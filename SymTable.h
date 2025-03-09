#ifndef SYMTABLE_H
#define SYMTABLE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Forward declarations
class ParamList;
class IdInfo;
class ClassInfo;
class FunctionInfo;
class ASTNode;
class NameAndType;

class ParamList {
public:
    std::vector<std::string> types;
    std::vector<std::string> names;
    
    void addParam(const std::string& type, const std::string& name) {
        types.push_back(type);
        names.push_back(name);
    }
};

enum class ScopeType
{
    GLOBAL,
    BLOCK,
    FUNCTION,
    CLASS
};

class IdInfo {
public:
    string idType;
    string type;
    string name;
    ParamList params; // for functions
    string value;     // For storing actual value
    union {
        int intValue;
        bool boolValue;
    };
    std::string stringValue; 

    // Single unified constructor 
    IdInfo(const std::string& t = "", const std::string& n = "", const std::string& v = "", 
           int iVal = 0, const std::string& sVal = "")
        : type(t), name(n), value(v), intValue(iVal), stringValue(sVal) {}
    
    // Constructor for C-strings
    IdInfo(const char* type, const char* name, const char* idType = "")
        : type(type), name(name), idType(idType), intValue(0), stringValue("") {}
};

class ClassInfo
{
public:
    std::map<std::string, IdInfo> fields;
    bool existsField(const std::string &fieldName) const;
    IdInfo getField(const std::string &fieldName) const;
    void addField(const std::string &fieldName, const IdInfo &fieldInfo);
};

class FunctionInfo
{
public:
    string name;
    string returnType;
    vector<string> params;

    FunctionInfo() : returnType("void") {} 
    FunctionInfo(string type) : returnType(type) {}
};

class SymTable
{
public:
    SymTable(const char *name) : name(name) {}
    SymTable(const std::string &name, ScopeType type, SymTable *parent = nullptr)
        : name(name), scopeType(type), parent(parent) {}

    ~SymTable();
    bool existsId(const char *s);
    void addVar(const char *type, const char *name);
    IdInfo getVar(const char *name);
    void printVars();
    void addClass(const std::string &className, const ClassInfo &classBody);
    bool existsClass(const std::string &className) const;
    ClassInfo getClass(const std::string &className) const;
    void addVar(const std::string &type, const std::string &name);
    bool existsId(const std::string &name) const;

    IdInfo &getVar(const std::string &name);             
    const IdInfo &getVar(const std::string &name) const; 
    bool checkCondition(const string &left, const string &op, const string &right);
    bool validateExpression(const string &expr);
    string evaluateExpr(const IdInfo &expr);
    bool validateCondition(const IdInfo &left, const string &op, const IdInfo &right);
    void addFunction(string name, FunctionInfo func);
    bool existsFunction(string name);
    FunctionInfo getFunction(string name);
    void printTypeOf(const string &name) const;

    bool validateCondition(const string &left, const string &op, const string &right)
    {
        return left == right; 
    }

    SymTable *getParent() const { return parent; }
    const std::map<std::string, IdInfo> &getVariables() const { return variables; }
    // Scope management
    SymTable *createChildScope(const std::string &name, ScopeType type)
    {
        auto child = new SymTable(name, type, this);
        children.push_back(child);
        return child;
    }

    // SymTable *getParent() const { return parent; }

    // Symbol lookup with scope chain traversal
    IdInfo *lookupVariable(const std::string &name)
    {
        auto it = variables.find(name);
        if (it != variables.end())
        {
            return &it->second;
        }
        if (parent)
        {
            return parent->lookupVariable(name);
        }
        return nullptr;
    }

    // Symbol definition
    void addVariable(const std::string &name, const IdInfo &info)
    {
        variables[name] = info;
    }

    // Print symbol table contents to file
    void dumpToFile(std::ofstream &out, int indent = 0)
    {
        std::string ind(indent * 2, ' ');
        out << ind << "Scope: " << name << " (";
        switch (scopeType)
        {
        case ScopeType::GLOBAL:
            out << "GLOBAL";
            break;
        case ScopeType::BLOCK:
            out << "BLOCK";
            break;
        case ScopeType::FUNCTION:
            out << "FUNCTION";
            break;
        case ScopeType::CLASS:
            out << "CLASS";
            break;
        }
        out << ")\n";

        // Print variables
        for (const auto &var : variables)
        {
            out << ind << "  VAR " << var.second.type << " " << var.first << "\n";
        }

        // Print functions
        for (const auto &func : functions)
        {
            out << ind << "  FUNC " << func.second.returnType << " "
                << func.first << "(";
            for (const auto &param : func.second.params)
            {
                out << param << " ";
            }
            out << ")\n";
        }

        // Recursively print child scopes
        for (auto child : children)
        {
            child->dumpToFile(out, indent + 1);
        }
    }

private:
    std::string name;
    ScopeType scopeType;
    SymTable *parent;
    std::map<std::string, IdInfo> variables;
    std::map<std::string, FunctionInfo> functions;
    std::map<std::string, ClassInfo> classes;
    std::vector<SymTable *> children;
};

#endif