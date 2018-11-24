#ifndef SCOPE_H
#define SCOPE_H

#include "pch.h"
#include "symbol.h"

using std::list;
using std::string;

class ScopeNode {
public:
    int lineno;
    string name;
    Symbol* symbol;
    ScopeNode(int lineno, const string& name, Symbol* symbol);
};


class Scope
{
    typedef list<ScopeNode> ScopeList;

    list<ScopeList> scopeStack;

public:
    Scope();
    Symbol* findSymbol(const string& name);
    bool insertSymbol(const string& name, int lineno, Symbol* symbol);

    void pushScope();
    void popScope();

};

#endif // + SCOPE_H
