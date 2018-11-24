#include "symbol.h"

Symbol::Symbol(Symbol::ValueType type, std::string value, bool isConstant) : type(type), value(value), isConstant(isConstant)
{

}


Constant::Constant(Symbol::ValueType type, string value) : Symbol (type, value, true)
{

}

Variable::Variable(Symbol::ValueType type, string value) : Symbol (type, value, false)
{

}
