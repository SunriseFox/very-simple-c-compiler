
  #include "common.h"
  int lineno = 1;

  string strip_string(const char* text, int start = 0, int end = 0) {
    string str = string(text + start);
    if (end > 0 && end - start >= 0)
      return str.substr(0, end - start);
    size_t len = str.length() + end;
    return len > 0 ? str.substr(0, len) : string();
  }

EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

CHAR \'.+\'
STRING \".+\"
INT [0-9]+
DOUBLE ([0-9]+)?(\.[0-9]+)([eE](\+|-)?[0-9]+)?

IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*

RESERVED "enum"|"signed"|"sizeof"|"static"|"struct"|"typedef"|"union"|"unsigned"|"volatile"

%%

{RESERVED} cout << endl << "reserved token: " << yytext << endl;

"auto" return T_AUTO;
"int"|"bool"|"long" return T_INT;
"char" return T_CHAR;
"string" return T_STRING;
"double"|"float" return T_DOUBLE;
"void" return T_VOID;

"break"	return K_BREAK;
"case" return K_CASE;
"const" /* return K_CONST; */
"continue"	return K_CONTINUE;
"default" return K_DEFAULT;
"do"  return K_DO;
"else"  return K_ELSE;
"extern" /* return K_EXTERN; */
"for"	return K_FOR;
"goto" return K_GOTO;
"if" return K_IF;
"register" /* return K_REGISTER; */
"return" return K_RET;
"switch" return K_SWITCH;
"while"	return K_WHILE;

"(" return LP;
")" return RP;

"++" return INC;
"--" return DEC;

"!" return NOT;
"~" return BREV;

"<<" return LMOVE;
">>" return RMOVE;

"*" return MUL;
"/" return DIV;
 % return MOD;

"+" return ADD;
"-" return SUB;
"&" return BAND;
"^" return BXOR;
"|" return BOR;

"<"	return LESS;
"<=" return LESSEQ;
">"	return MORE;
">=" return MOREEQ;
"==" return EQ;
"!="	return NE;

"&&" return LAND;

"||" return LOR;

"?" return QM;
":" return COLON;

"*=" return MULAS;
"/=" return DIVAS;
"%=" return MODAS;

"+=" return ADDAS;
"-=" return SUBAS;
"&=" return BANDAS;
"^=" return BXORAS;
"|=" return BORAS;
"=" return ASSIGN;

"," return COMMA;
";" return SEMICOLON;

"{"	return LB;
"}"	return RB;


"/*" {
  int c;
  while((c = yyinput()) != 0)
  {
    if(c == '\n')
      ++lineno;
    else if(c == '*')
    {
      if((c = yyinput()) == '/')
        break;
      else
        unput(c);
    }
  }
}

{IDENTIFIER}: return LABEL;

"true" yylval.symbol = new Constant(Constant::VALUE_INT, "1"); return SYMBOL;
"false" yylval.symbol = new Constant(Constant::VALUE_INT, "0"); return SYMBOL;

{CHAR} {
  yylval.symbol = new Constant(Constant::VALUE_CHAR, strip_string(yytext, 1, -1));
  return SYMBOL;
}
{STRING} {
  yylval.symbol = new Constant(Constant::VALUE_STRING, strip_string(yytext, 1, -1));
  return SYMBOL;
}
{INT} {
  yylval.symbol = new Constant(Constant::VALUE_INT, yytext);
  return SYMBOL;
}
{DOUBLE} {
  yylval.symbol = new Constant(Constant::VALUE_DOUBLE, yytext);
  return SYMBOL;
}
{IDENTIFIER} yylval.value = new string(yytext); return IDENTIFIER;

{WHILTESPACE} /* do nothing */
{EOL} lineno++;
. {
  cout << "unknown character " << yytext << endl;
  exit(EXIT_FAILURE);
}

%%
