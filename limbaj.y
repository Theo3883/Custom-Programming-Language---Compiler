// Forward declarations
%code requires {
    #include <iostream>
    #include <vector>
    #include <string>
    #include <cstring>  
    class ClassInfo;
    class IdInfo;

}

%{
#include "SymTable.h"
#include "AST.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;

// Enhanced error reporting function
void reportTypeError(const string& msg, const string& var) {
    errorCount++;
    cerr << "Type Error at line " << yylineno << ": " << msg << " '" << var << "'" << endl;
}

// Enhanced type checking for expressions
string getResultType(const string& left, const string& op, const string& right) {
    if (left != right) {
        reportTypeError("Type mismatch in operation: cannot mix types", left + " " + op + " " + right);
        return "error";
    }
    
    if (left == "int" && right == "int") {
        if (op == "+" || op == "-" || op == "*" || op == "/") return "int";
    }
    else if (left == "string" && right == "string" && op == "+") return "string"; 
    else if (left == "bool" && right == "bool" && (op == "&&" || op == "||")) return "bool";
    
    reportTypeError("Invalid operation between types", left + " " + op + " " + right);
    return "error";
}

string makeArrayType(const string& baseType, int dimensions) {
    string type = baseType;
    for(int i = 0; i < dimensions; i++) type += "[]";
    return type;
}

void enterScope(const string& name, ScopeType type);
void exitScope();
%}

%union {
    char* string;
    int number;
    class ASTNode* ast;
    class ClassInfo* classInfo;
    class IdInfo* idInfo;
    class NameAndType* exprValue;
    std::vector<std::string>* vector;
    std::vector<NameAndType*>* exprList;
}

// Tokens
%token BGIN END ASSIGN
%token<string> ID TYPE STRING_LITERAL BOOL_LITERAL
%token CLASS NEW
%token<number> NR
%token FUNCTION RETURN
%token IF ELSE WHILE FOR
%token EQ NEQ LT GT LE GE
%token Print TypeOf
%token THEN  // Add if not already present

// Non-terminals
%type<exprValue> lvalue
%type<ast> expr term factor
%type<classInfo> class_body 
%type<idInfo> member_decl
%type<exprValue> field_access array_access  // Add array_access here
%type<string> statement assignment print_stmt type_stmt
%type<string> if_stmt if_then if_then_else while_stmt for_stmt control_stmt
%type<string> rel_op function_call 
%type<number> array_dims
%type<vector> function_params
%type<exprList> expr_list
%type<ast> condition


// Precedence and associativity
%precedence THEN
%precedence ELSE
%left ASSIGN
%left EQ NEQ
%left LT GT LE GE
%left '+' '-'
%left '*' '/'
%left '.'
%left '[' ']'
%nonassoc UMINUS

%%

program: declarations main { if (errorCount == 0) cout << "The program is correct!" << endl; }
    ;

declarations: decl
    | declarations decl
    ;

decl: TYPE ID ';' {
    if(current->existsId($2)) {
        reportTypeError("Variable already defined in current scope", $2);
    } else {
        current->addVar($1, $2);
    }
}
    | TYPE ID array_dims ';' {
        if(!current->existsId($2)) {
            string arrayType = makeArrayType($1, $3);
            current->addVar(arrayType.c_str(), $2);
        }
        else { errorCount++; yyerror("Array already defined"); }
    }
    | ID ID ';' {  
        if(!current->existsClass($1)) {
            errorCount++; 
            yyerror("Class type not defined");
        }
        else if(!current->existsId($2)) {
            current->addVar($1, $2);
        }
        else {
            errorCount++;
            yyerror("Variable already defined");
        }
    }
    | class_decl
    | function_decl
    ;

class_decl: CLASS ID '{' class_body '}' {
        if(!current->existsClass($2)) {
            // First add the class definition
            current->addClass($2, *$4);
            // Then enter scope, process members, and exit
            enterScope($2, ScopeType::CLASS);
            exitScope();
        } else {
            errorCount++;
            yyerror("Class already defined");
        }
    }
    ;

function_decl: FUNCTION ID '(' function_params ')' ':' TYPE function_block {
        FunctionInfo func;
        func.name = $2;
        func.returnType = $7;
        

        for(int i = $4->size()-2; i >= 0; i-=2) {
            func.params.push_back($4->at(i)); 
        }
        
        if(!current->existsFunction($2)) {
            current->addFunction($2, func); // Add function first
            enterScope($2, ScopeType::FUNCTION);
            // Add parameters to function scope
            for(int i = $4->size()-2; i >= 0; i-=2) {
                current->addVar($4->at(i), $4->at(i+1)); // type, name
            }
            exitScope();
        } else {
            errorCount++;
            yyerror("Function already defined");
        }
    }
    | FUNCTION ID '(' ')' ':' TYPE function_block {
        FunctionInfo func;
        func.name = $2;
        func.returnType = $6;
        if(!current->existsFunction($2)) {
            enterScope($2, ScopeType::FUNCTION);
            current->addFunction($2, func);
            exitScope();
        } else {
            errorCount++;
            yyerror("Function already defined");
        }
    }
    ;

function_params: TYPE ID {
        $$ = new vector<string>();
        $$->push_back($1); // type
        $$->push_back($2); // name
    }
    | function_params ',' TYPE ID {
        $$ = $1;
        $$->push_back($3); // type
        $$->push_back($4); // name
    }

function_block: '{' {
        enterScope("block", ScopeType::BLOCK);
        // Copy parent scope variables 
        SymTable* parent = current->getParent();
        while(parent) {
            auto vars = parent->getVariables();
            for(const auto& var : vars) {
                if(!current->existsId(var.first)) {
                    current->addVar(var.second.type, var.first);
                }
            }
            parent = parent->getParent();
        }
    } statements RETURN expr ';' '}' {
        exitScope();
    }
simple_block: '{' {
        enterScope("block", ScopeType::BLOCK);
        // Copy all variables from parent scopes up to global
        SymTable* parent = current->getParent();
        while(parent) {
            auto vars = parent->getVariables();
            for(const auto& var : vars) {
                if(!current->existsId(var.first)) {
                    current->addVar(var.second.type, var.first);
                }
            }
            parent = parent->getParent();
        }
    } statements '}' {
        exitScope();
    }


class_body: member_decl { 
        $$ = new ClassInfo(); 
        $$->addField($1->name, *$1); 
    }
    | class_body member_decl { 
        $$ = $1; 
        $$->addField($2->name, *$2); 
    }
    ;

member_decl: TYPE ID ';' {
        $$ = new IdInfo($1);
        $$->name = $2;
    }
    | TYPE ID array_dims ';' {
        string arrayType = makeArrayType($1, $3);
        $$ = new IdInfo(arrayType);
        $$->name = $2;
    }
    ;

array_dims: '[' NR ']' { 
        $$ = 1; 
    }
    | array_dims '[' NR ']' { 
        $$ = $1 + 1;  // array dimensions
    }
    ;


main: BGIN statements END
    ;

statements: statement ';'
    | statements statement ';'
    ;

statement: assignment { $$ = "assignment"; }
    | control_stmt { $$ = $1; }
    | print_stmt { $$ = "print"; }
    | type_stmt { $$ = "type"; }
    | function_call { $$ = "function"; }
    ;

assignment: lvalue ASSIGN expr {
    std::string lhsType;
    if ($1->isArray) {
        lhsType = $1->type;
    } else {
        lhsType = $1->type;
    }
    
    // Store the evaluated value in the symbol table
    if (current->existsId($1->name)) {
        IdInfo& info = current->getVar($1->name);
        info.value = $3->evaluate(current);  // Store the actual value
    }
    
    if ($3->getValueType() != "error" && lhsType != "error" && lhsType != $3->getValueType()) {
        reportTypeError("Type mismatch in assignment", $1->name + " = " + $3->getName());
    }
}
lvalue: ID { 
    if (current->existsId($1)) {
        IdInfo info = current->getVar($1);
        $$ = new NameAndType($1, info.type); 
    } else {
        $$ = new NameAndType("error", "error");
    }
}
    | array_access { $$ = $1; }
    | field_access { $$ = $1; }
    ;

array_access: ID '[' expr ']' {
    if (current->existsId($1)) {
        IdInfo info = current->getVar($1);
        string baseType = info.type;
        // Strip array brackets to get base type
        if (baseType.find("[]") != string::npos) {
            baseType = baseType.substr(0, baseType.find("[]"));
        }
        $$ = new NameAndType($1, baseType, true);  // true indicates array type
    }
} 
| field_access '[' expr ']' {
    string fieldType = $1->type;
    if (fieldType.find("[]") != string::npos) {
        fieldType = fieldType.substr(0, fieldType.find("[]"));
    }
    $$ = new NameAndType($1->name, fieldType, true);
}
field_access: ID '.' ID {
    $$ = new NameAndType();
    if (current->existsId($1)) {
        IdInfo info = current->getVar($1);
        if (current->existsClass(info.type)) {
            ClassInfo classInfo = current->getClass(info.type);
            if (!classInfo.existsField($3)) {
                errorCount++;
                yyerror("Field not found in class");
            } else {
                IdInfo fieldInfo = classInfo.getField($3);
                $$ = new NameAndType($3, fieldInfo.type);
            }
        } else {
            errorCount++;
            yyerror("Not a class type");
        }
    } else {
        errorCount++;
        yyerror("Variable not declared");
    }
};
control_stmt: if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    ;

if_stmt: if_then { $$ = $1; }
    | if_then_else { $$ = $1; }
    ;

if_then: IF '(' condition ')' simple_block {
        $$ = "if";
    }
    ;

if_then_else: IF '(' condition ')' simple_block ELSE simple_block {
        $$ = "if-else"; 
    }
    ;

while_stmt: WHILE '(' condition ')'
    {
        enterScope("while", ScopeType::BLOCK);
    }
    simple_block
    {
        exitScope();
        //$$ = $7;  // Use simple_block's value
    }
    ;

for_stmt: FOR '(' assignment ';' condition ';' assignment ')'
    {
        enterScope("for", ScopeType::BLOCK);
    }
    simple_block
    {
        exitScope();
        //$$ = $11;  // Use simple_block's value
    }
    ;
condition: expr rel_op expr {
    // Check if expressions are valid
    if (!$1 || !$3) {
        errorCount++;
        yyerror("Invalid operands in condition");
        $$ = new NameAndType("error", "error");
        YYERROR;
    }

    // Get the actual value types
    string leftType = $1->getValueType();
    string rightType = $3->getValueType();
    string leftValue = $1->evaluate(current);
    string rightValue = $3->evaluate(current);

    // Check type compatibility
    if (leftType != rightType) {
        string errorMsg = "Type mismatch in condition: cannot compare " + 
                         leftType + " with " + rightType;
        yyerror(errorMsg.c_str());
        $$ = new NameAndType("error", "error");
        YYERROR;
    }

    // Create comparison operator node
    auto op = new OperatorNode($2);
    op->left = std::shared_ptr<ASTNode>($1);
    op->right = std::shared_ptr<ASTNode>($3);
    $$ = op;

    // Store condition result
    current->addVar("bool", "_condition_result");
}
    ;

print_stmt: Print '(' expr ')' {
    try {
        std::string value = $3->evaluate(current);
        std::string type = $3->getValueType();
        std::cout << "Print: " << value << " (type: " << type << ")\n";
        delete $3;
    } catch(std::exception& e) {
        yyerror(e.what());
    }
}

type_stmt: TypeOf '(' expr ')' {
if ($3->getValueType() != "error") {
    std::cout << "Type of " << $3->getName() << " is " << $3->getValueType() << '\n';
}
        $$ = "type";
    }
    ;


rel_op: EQ { $$ = "=="; }
    | NEQ { $$ = "!="; }
    | LT { $$ = "<"; }
    | GT { $$ = ">"; }
    | LE { $$ = "<="; }
    | GE { $$ = ">="; }
    ;

expr_list: expr { 
    $$ = new vector<NameAndType*>();
    $$->push_back(dynamic_cast<NameAndType*>($1));  
}
| expr_list ',' expr {
    $$ = $1;
    $$->push_back(dynamic_cast<NameAndType*>($3));  
}
    ;

expr: expr '+' term { 
    auto op = new OperatorNode("+");
    op->left = std::shared_ptr<ASTNode>($1);
    op->right = std::shared_ptr<ASTNode>($3);
    $$ = op;
}
    | expr '-' term {
        auto op = new OperatorNode("-");
        op->left = std::shared_ptr<ASTNode>($1);
        op->right = std::shared_ptr<ASTNode>($3);
        $$ = op;
    }
    | term { $$ = $1; }
    ;

term: term '*' factor {
        auto op = new OperatorNode("*");
        op->left = std::shared_ptr<ASTNode>($1);
        op->right = std::shared_ptr<ASTNode>($3);
        $$ = op;
    }
    | term '/' factor {
        auto op = new OperatorNode("/");
        op->left = std::shared_ptr<ASTNode>($1);
        op->right = std::shared_ptr<ASTNode>($3);
        $$ = op;
    }
    | factor { $$ = $1; }
    ;

factor: ID { 
    if (current->existsId($1)) {
        IdInfo info = current->getVar($1);
        $$ = new NameAndType($1, info.type);
    } else {
        errorCount++;
        yyerror("Variable not declared");
        $$ = new NameAndType("error", "error");
    }
}
    | NR { $$ = new NameAndType(std::to_string($1), "int"); }
    | STRING_LITERAL { $$ = new NameAndType($1, "string"); }
    | BOOL_LITERAL { $$ = new NameAndType($1, "bool"); }
    | array_access { $$ = $1; }
    | field_access { $$ = $1; }
    | '(' expr ')' { $$ = $2; }
    | function_call { $$ = new NameAndType("", "function"); }
    | NEW ID {  
        if(!current->existsClass($2)) {
            errorCount++;
            yyerror("Class not defined");
            $$ = new NameAndType("error", "error");
        } else {
            $$ = new NameAndType("new_" + std::string($2), $2);
        }
    }
;

function_call: ID '(' expr_list ')' {
    if (!current->existsFunction($1)) {
        reportTypeError("Function not declared", $1);
    } else {
        FunctionInfo func = current->getFunction($1);
        if (func.params.size() != $3->size()) {
            reportTypeError("Wrong number of parameters in call to", $1);
        } else {
            for(size_t i = 0; i < $3->size(); i++) {
                if((*$3)[i]->type != func.params[i]) {
                    reportTypeError("Parameter type mismatch in function", 
                        string($1) + ": expected " + func.params[i] + 
                        ", got " + (*$3)[i]->type);
                    break;
                }
            }
        }
    }
    $$ = "function"; 
    }
    ;

%%

void yyerror(const char * s){
    cout << "error:" << s << " at line: " << yylineno << endl;
}

void enterScope(const string& name, ScopeType type) {
    current = current->createChildScope(name, type);
}

void exitScope() {
    if(current->getParent()) {
        current = current->getParent();
    }
}

int main(int argc, char** argv) {
    yyin = fopen(argv[1],"r");
    current = new SymTable("global", ScopeType::GLOBAL);
    yyparse();
    
    ofstream symFile("symbol_tables.txt");
    current->dumpToFile(symFile);
    symFile.close();
    
    delete current;
    return 0;
}