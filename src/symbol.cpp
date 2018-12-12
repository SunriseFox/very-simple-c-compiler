#include "symbol.h"

string Symbol::getSymbolName(Symbol *s)
{
    switch (s->type) {
    case Symbol::VALUE_CHAR:
        return "char";
    case Symbol::VALUE_DOUBLE:
        return "double";
    case Symbol::VALUE_INT:
        return "int";
    case Symbol::VALUE_NONE:
        return "none";
    case Symbol::VALUE_ERROR:
        return "error";
    case Symbol::VALUE_STRING:
        return "string";
    case Symbol::VALUE_VOID:
        return "void";
    }
    return "--";
}

Symbol::Symbol(Symbol::ValueType type, std::string value, SymbolType symbolType)
    : type(type), value(value), symbolType(symbolType)
{

}


Constant::Constant(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_CONSTANT)
{

}

Variable::Variable(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_VARIABLE)
{

}

Callable::Callable(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_CALLABLE)
{

}

OpNode::OpNode(Symbol::ValueType type, string value)
    : Symbol (type, value, SYMBOL_OPNODE)
{

}
