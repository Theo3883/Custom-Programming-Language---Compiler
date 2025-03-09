#include "SymTable.h"
using namespace std;

bool ClassInfo::existsField(const std::string &fieldName) const
{
    return fields.find(fieldName) != fields.end();
}

IdInfo ClassInfo::getField(const std::string &fieldName) const
{
    auto it = fields.find(fieldName);
    if (it != fields.end())
    {
        return it->second;
    }
    return IdInfo();
}

void ClassInfo::addField(const std::string &fieldName, const IdInfo &fieldInfo)
{
    fields[fieldName] = fieldInfo;
}

void SymTable::addVar(const char *type, const char *name)
{
    IdInfo var(type, name, "var");
    variables[name] = var;
}

bool SymTable::existsId(const char *var)
{
    return variables.find(var) != variables.end();
}

IdInfo SymTable::getVar(const char *name)
{
    return variables[name];
}

void SymTable::printVars()
{
    for (const pair<string, IdInfo> &v : variables)
    {
        cout << "name: " << v.first << " type:" << v.second.type << endl;
    }
}

SymTable::~SymTable()
{
   for(auto child : children) {
        delete child;
    }
    children.clear();
    variables.clear();
}

void SymTable::addClass(const std::string &className, const ClassInfo &classBody)
{
    classes[className] = classBody;
}

bool SymTable::existsClass(const std::string &className) const
{
    return classes.find(className) != classes.end();
}

ClassInfo SymTable::getClass(const std::string &className) const
{
    auto it = classes.find(className);
    if (it != classes.end())
    {
        return it->second;
    }
    return ClassInfo();
}

void SymTable::addVar(const std::string &type, const std::string &name)
{
    IdInfo info(type, name);
    variables[name] = info; // Store in variables map
}

bool SymTable::existsId(const std::string &name) const
{
    return variables.find(name) != variables.end();
}
/*&IdInfo SymTable::getVar(const std::string& name) const {
    auto it = variables.find(name);
    if (it != variables.end()) {
        return it->second;
    }
    // Handle error: variable not found
    return IdInfo();
}*/
IdInfo &SymTable::getVar(const std::string &name)
{
    // Use variables map consistently
    auto it = variables.find(name);
    if (it == variables.end())
    {
        throw std::runtime_error("Variable not found: " + name);
    }
    return it->second; // Return reference to stored variable
}

const IdInfo &SymTable::getVar(const std::string &name) const
{
    auto it = variables.find(name);
    if (it == variables.end())
    {
        throw std::runtime_error("Variable not found: " + name);
    }
    return it->second;
}

bool SymTable::checkCondition(const string &left, const string &op, const string &right)
{
    IdInfo leftInfo = getVar(left);
    IdInfo rightInfo = getVar(right);

    // Check that both operands have same type
    if (leftInfo.type != rightInfo.type)
    {
        return false;
    }
    return true;
}

bool SymTable::validateExpression(const string &expr)
{
    // Add expression validation logic
    return true;
}

string SymTable::evaluateExpr(const IdInfo &expr)
{
    
    if (existsId(expr.name))
    {
        return getVar(expr.name).type;
    }
    return expr.type;
}

bool SymTable::validateCondition(const IdInfo &left, const string &op, const IdInfo &right)
{
    return left.type == right.type;
}

void SymTable::addFunction(string name, FunctionInfo func)
{
    functions[name] = func;
}

bool SymTable::existsFunction(string name)
{
    return functions.find(name) != functions.end();
}

FunctionInfo SymTable::getFunction(string name)
{
    auto it = functions.find(name);
    if (it != functions.end())
    {
        return it->second;
    }
    return FunctionInfo("void"); 
}

void SymTable::printTypeOf(const string &name) const
{
    if (existsId(name))
    {
        const IdInfo &info = getVar(name);
        cout << "TypeOf " << name << " de tipul " << info.type << endl;
    }
    else
    {
        for (const auto &v : variables)
        {
            if (v.first == name)
            {
                cout << "TypeOf " << name << "de tipul " << v.second.type << endl;
                return;
            }
        }
        cout << "TypeOf " << name << ": undefined" << endl;
    }
}
