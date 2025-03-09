#pragma once
#include <string>
#include <memory>
#include "SymTable.h"

class SymTable;

enum class NodeType {
    NUMBER,
    IDENTIFIER,
    OPERATOR,
    NAME_AND_TYPE
};

class ASTNode {
protected:
    NodeType nodeType;
public:
    ASTNode(NodeType type) : nodeType(type) {}
    virtual ~ASTNode() = default;
    virtual std::string evaluate(SymTable* symTable) = 0;
    virtual std::string getValueType() const = 0;
    virtual std::string getName() const = 0;
};

class NameAndType : public ASTNode {
public:
    std::string name;
    std::string type;
    bool isArray;
    
            NameAndType(string name = "", string type = "", bool isArray = false) 
        : ASTNode(NodeType::NAME_AND_TYPE), name(name), type(type), isArray(isArray) {}
    
        std::string evaluate(SymTable* symTable) override {
        if (symTable->existsId(name)) {
            IdInfo info = symTable->getVar(name);
            return info.value;  
        }
        return name;  
    }
    std::string getValueType() const override { return type; }
    std::string getName() const override { return name; }
};

class OperatorNode : public ASTNode {
public:
    std::string op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
    
    OperatorNode(const std::string& op) 
        : ASTNode(NodeType::OPERATOR), op(op) {}
    
    std::string evaluate(SymTable* symTable) override;
    std::string getValueType() const override { return "int"; }
    std::string getName() const override { return op; }
};

class NumberNode : public ASTNode {
public:
    int value;
    
    NumberNode(int val) 
        : ASTNode(NodeType::NUMBER), value(val) {}
    
    std::string evaluate(SymTable* symTable) override { return std::to_string(value); }
    std::string getValueType() const override { return "int"; }
    std::string getName() const override { return std::to_string(value); }
};

class IdentifierNode : public ASTNode {
public:
    std::string name;
    
    IdentifierNode(const std::string& id) 
        : ASTNode(NodeType::IDENTIFIER), name(id) {}
    
    std::string evaluate(SymTable* symTable) override;
    std::string getValueType() const override;
    std::string getName() const override { return name; }
};