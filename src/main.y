
%{
  #include "common.h"
  extern int lineno;
  extern TreeNode * root;
  Symbol::ValueType currentType = Symbol::VALUE_NONE;

  int yylex();
  int yyerror( char const* );
  Scope scope;
%}

%union {
  string *value;
  Symbol *symbol;
  TreeNode *node;
}

// ---

%token T_AUTO T_CHAR T_INT T_DOUBLE T_VOID T_STRING

%token K_BREAK K_CASE K_CONTINUE K_DEFAULT K_DO K_ELSE K_FOR K_GOTO K_IF K_RET K_SWITCH K_WHILE

%token LP RP

%token INC DEC SIZEOF

%token NOT BREV

%token LMOVE RMOVE

%token MUL DIV MOD

%token ADD SUB BAND BXOR BOR

%token LESS LESSEQ MORE MOREEQ EQ NE

%token LAND

%token LOR

%token QM COLON

%token MULAS DIVAS MODAS
%token ADDAS SUBAS BANDAS BXORAS BORAS ASSIGN

%token COMMA SEMICOLON

%token LABEL

%token <symbol> SYMBOL
%token <value> IDENTIFIER

%token LB RB

// ---

%right COMMA
%right NOT BREV
%left LMOVE RMOVE
%left MUL DIV MOD
%left ADD SUB BAND BXOR BOR
%left LESS LESSEQ MORE MOREEQ EQ NE
%left LAND LOR
%right MULAS DIVAS MODAS ADDAS SUBAS BANDAS BXORAS BORAS ASSIGN
%nonassoc IFX
%right UMINUS UADD

// ---

%type <node> node
%type <node> declaration id_list id_pair
%type <node> expression assignment logical comparative additive multiplicative bitshift bitbinary postfix cast
%type <node> if_condition if_else_condition for_statement while_statement do_while_statement  function_declaration_statement
%type <node> statement program
%type <symbol> id_prefix

// ---

%right K_ELSE

%%

start : program {root = $1;}
     ;

program : program statement {
          ($1) -> addSibling($2);
          $$ = $1;
        }
        | statement {
          $$ = $1;
        }
        | LB RB {
          $$ = new StatementNode(lineno, StatementNode::ST_SCOPE);
        }
        ;

lb_scope  : LB { scope.pushScope(); }
          ;

statement : expression SEMICOLON {
            $$ = $1;
          }
          | declaration SEMICOLON {
            $$ = $1;
          }
          | SEMICOLON {
            $$ = new StatementNode(lineno, StatementNode::ST_EMPTY);
          }
          | lb_scope program RB {
            $$ = new StatementNode(lineno, StatementNode::ST_SCOPE);
            $$ -> addChild($2);
            scope.popScope();
          }
          | if_else_condition {
              $$ = $1;
          }
          | if_condition {
            $$ = $1;
          }
          | for_statement {
            $$ = $1;
          }
          | while_statement {
            $$ = $1;
          }
          | do_while_statement {
            $$ = $1;
          }
          | function_declaration_statement {
            $$ = $1;
          }
          ;

function_declaration_statement  : type IDENTIFIER LP RP LB program RB {
                                  Callable* symbol = new Callable(currentType, *$2);
                                  $$ = new FuncStatementNode(lineno, symbol, {$6});
                                }
                                | type IDENTIFIER LP RP LB RB {
                                  Callable* symbol = new Callable(currentType, *$2);
                                  $$ = new FuncStatementNode(lineno, symbol);
                                }
                                ;

if_condition  : K_IF LP expression RP statement %prec IFX {
                $$ = new StatementNode(lineno, StatementNode::ST_IF, {$3, $5});
              }
              ;

if_else_condition : K_IF LP expression RP statement K_ELSE statement {
                $$ = new StatementNode(lineno, StatementNode::ST_IF_ELSE, {$3, $5, $7});
              }
              ;

for_statement : K_FOR LP expression SEMICOLON expression SEMICOLON expression RP statement {
                $$ = new StatementNode(lineno, StatementNode::ST_FOR, {$3, $5, $7, $9});
              }
              ;

while_statement : K_WHILE LP expression RP statement {
                  $$ = new StatementNode(lineno, StatementNode::ST_WHILE, {$3, $5});
                }
                ;

do_while_statement  : K_DO lb_scope statement RB K_WHILE LP expression RP SEMICOLON {
                  $$ = new StatementNode(lineno, StatementNode::ST_DO_WHILE, {$3, $7});
                  scope.popScope();
                }
                ;

declaration : type id_list {
              $$ = $2;
            }
            ;

type      : T_INT { currentType = Symbol::VALUE_INT; }
          | T_CHAR { currentType = Symbol::VALUE_CHAR; }
          | T_STRING { currentType = Symbol::VALUE_STRING; }
          | T_DOUBLE { currentType = Symbol::VALUE_DOUBLE; }
          | T_VOID { currentType = Symbol::VALUE_VOID; }
          | T_AUTO { currentType = Symbol::VALUE_NONE; }

id_list   : id_pair {
            $$ = $1;
          }
          | id_list COMMA id_pair {
            $1 -> addSibling($3);
            $$ = $1;
          }
          ;

id_pair   : id_prefix ASSIGN expression {
            $$ = new DeclarationNode(lineno, $1);
            $$ -> addChild($3);
          }
          | id_prefix {
            $$ = new DeclarationNode(lineno, $1);
          }
          ;

id_prefix : IDENTIFIER {
            Symbol* symbol = new Variable(currentType, *$1);
            bool ok = scope.insertSymbol(*$1, lineno, symbol);
            if (!ok)  {
              cerr << "Line " << lineno << ": symbol " << *$1 << " has already been declared." << endl;
              return -1;
            }
            $$ = symbol;
          }

expression  : assignment {
              $$ = $1;
            }
            | expression COMMA assignment {
              $1 -> addSibling($3);
              $$ = $3;
            }
            ;

assignment  : logical {
              $$ = $1;
            }
            | node MULAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_MULAS, {$1, $3});
            }
            | node DIVAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_DIVAS, {$1, $3});
            }
            | node MODAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_MODAS, {$1, $3});
            }
            | node ADDAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_ADDAS, {$1, $3});
            }
            | node SUBAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_ADDAS, {$1, $3});
            }
            | node BANDAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_BANDAS, {$1, $3});
            }
            | node BXORAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_BXORAS, {$1, $3});
            }
            | node BORAS logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_BORAS, {$1, $3});
            }
            | node ASSIGN logical {
              $$ = new OperatorNode(lineno, OperatorNode::OP_ASSIGN, {$1, $3});
            }
            ;

logical     : comparative {
              $$ = $1;
            }
            | logical LAND comparative {
              $$ = new OperatorNode(lineno, OperatorNode::OP_LAND, {$1, $3});
            }
            | logical LOR comparative {
              $$ = new OperatorNode(lineno, OperatorNode::OP_LOR, {$1, $3});
            }
            ;

comparative : additive {
              $$ = $1;
            }
            | comparative LESS additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_LESS, {$1, $3});
            }
            | comparative LESSEQ additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_LESSEQ, {$1, $3});
            }
            | comparative MORE additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_MORE, {$1, $3});
            }
            | comparative MOREEQ additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_MOREEQ, {$1, $3});
            }
            | comparative EQ additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_EQ, {$1, $3});
            }
            | comparative NE additive {
              $$ = new OperatorNode(lineno, OperatorNode::OP_NE, {$1, $3});
            }
            ;

additive  : multiplicative {
            $$ = $1;
          }
          | additive ADD multiplicative {
            $$ = new OperatorNode(lineno, OperatorNode::OP_ADD, {$1, $3});
          }
          | additive SUB multiplicative {
            $$ = new OperatorNode(lineno, OperatorNode::OP_SUB, {$1, $3});
          }
          | additive BAND multiplicative {
            $$ = new OperatorNode(lineno, OperatorNode::OP_BAND, {$1, $3});
          }
          | additive BXOR multiplicative {
            $$ = new OperatorNode(lineno, OperatorNode::OP_BXOR, {$1, $3});
          }
          | additive BOR multiplicative {
            $$ = new OperatorNode(lineno, OperatorNode::OP_BOR, {$1, $3});
          }
          | ADD multiplicative %prec UADD {
            $$ = new OperatorNode(lineno, OperatorNode::OP_ADD, {$2});
          }
          | SUB multiplicative %prec UMINUS {
            $$ = new OperatorNode(lineno, OperatorNode::OP_SUB, {$2});
          }
          ;

multiplicative  : bitshift  {
                  $$ = $1;
                }
                | multiplicative MUL bitshift {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_MUL, {$1, $3});
                }
                | multiplicative DIV bitshift {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_DIV, {$1, $3});
                }
                | multiplicative MOD bitshift {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_MOD, {$1, $3});
                }
                ;

bitshift        : bitbinary {
                  $$ = $1;
                }
                | bitshift LMOVE bitbinary {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_LMOVE, {$1, $3});
                }
                | bitshift RMOVE bitbinary {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_RMOVE, {$1, $3});
                }
                ;

bitbinary       : postfix {
                  $$ = $1;
                }
                | NOT bitbinary  {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_NOT, {$2});
                }
                | BREV bitbinary {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_BREV, {$2});
                }
                ;

postfix         : cast {
                  $$ = $1;
                }
                | INC postfix {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_INC, {$2});
                }
                | DEC postfix {
                  $$ = new OperatorNode(lineno, OperatorNode::OP_DEC, {$2});
                }
                ;

cast  : LP expression RP {
        $$ = $2;
      }
      | node {
        $$ = $1;
      }
      ;

node  : IDENTIFIER  {
        auto symbol = scope.findSymbol(*$1);
        if (symbol == nullptr) {
          std::cerr << "Line " << lineno << ": symbol " << *$1 << " is not defined." << endl;
          return -1;
        }
        $$ = new ExprNode(lineno, symbol);
      }
      | SYMBOL  {
        $$ = new ExprNode(lineno, $1);
      }
      ;

%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}
