#ifndef UTILS_H
#define UTILS_H

#include "tree.h"
#include "scope.h"

extern int lineno;
extern TreeNode *root;
extern Scope *scope;

extern Callable *currFunc;
extern int currFuncCount;
extern map<Callable*, list<Symbol*>> funcTable;

#endif // UTILS_H
