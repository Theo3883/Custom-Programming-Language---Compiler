#include "AST.h"

std::string IdentifierNode::getValueType() const {
   
    return "unknown";
}

std::string IdentifierNode::evaluate(SymTable* symTable) {
    if (!symTable->existsId(name)) {
        throw std::runtime_error("Variable not found: " + name);
    }
    IdInfo info = symTable->getVar(name);
    return info.value;
}


std::string OperatorNode::evaluate(SymTable* symTable) {
    std::string leftVal = left->evaluate(symTable);
    std::string rightVal = right->evaluate(symTable);
    
    try {
        int lhs = std::stoi(leftVal);
        int rhs = std::stoi(rightVal);
        
        if (op == "+") return std::to_string(lhs + rhs);
        if (op == "-") return std::to_string(lhs - rhs);
        if (op == "*") return std::to_string(lhs * rhs);
        if (op == "/") {
            if (rhs == 0) throw std::runtime_error("Division by zero");
            return std::to_string(lhs / rhs);
        }
        
        if (op == "==") return std::to_string(lhs == rhs);
        if (op == "!=") return std::to_string(lhs != rhs);
        if (op == "<") return std::to_string(lhs < rhs);
        if (op == ">") return std::to_string(lhs > rhs);
        if (op == "<=") return std::to_string(lhs <= rhs);
        if (op == ">=") return std::to_string(lhs >= rhs);
    }
    catch(std::exception& e) {
        throw std::runtime_error("Invalid operation: " + op);
    }
    
    throw std::runtime_error("Unknown operator: " + op);
}