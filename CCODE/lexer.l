%option nounput

L   [a-zA-Z_]
A   [a-zA-Z_0-9]
WS  [ \t\v\f]

%{

#include <parsererror.h>
#include <iostream>
#include "parser.h"

int lineNum=1;

extern void yyerror(const char *);  /* prints grammar violation message */
extern int sym_type(const char*);

#define sym_type(identifier) IDENTIFIER

static int check_type(void);

%}

%%


"include"               { return(INCLUDE); }

"auto"					{ return(AUTO); }
"break"					{ return(BREAK); }
"case"					{ return(CASE); }
"char"					{ return(CHAR); }
"const"					{ return(CONST); }
"continue"				{ return(CONTINUE); }
"default"				{ return(DEFAULT); }
"do"					{ return(DO); }
"double"				{ return(DOUBLE); }
"else"					{ return(ELSE); }
"enum"					{ return(ENUM); }
"extern"				{ return(EXTERN); }
"float"					{ return(FLOAT); }
"for"					{ return(FOR); }
"goto"					{ return(GOTO); }
"if"					{ return(IF); }
"int"					{ return(INT); }
"long"					{ return(LONG); }
"register"				{ return(REGISTER); }
"restrict"				{ return(RESTRICT); }
"return"				{ return(RETURN); }
"short"					{ return(SHORT); }
"signed"				{ return(SIGNED); }
"sizeof"				{ return(SIZEOF); }
"static"				{ return(STATIC); }
"struct"				{ return(STRUCT); }
"switch"				{ return(SWITCH); }
"typedef"				{ return(TYPEDEF); }
"union"					{ return(UNION); }
"unsigned"				{ return(UNSIGNED); }
"void"					{ return(VOID); }
"volatile"				{ return(VOLATILE); }
"while"					{ return(WHILE); }


"..."					{ return ELLIPSIS; }
">>="					{ return RIGHT_ASSIGN; }
"<<="					{ return LEFT_ASSIGN; }
"+="					{ return ADD_ASSIGN; }
"-="					{ return SUB_ASSIGN; }
"*="					{ return MUL_ASSIGN; }
"/="					{ return DIV_ASSIGN; }
"%="					{ return MOD_ASSIGN; }
"&="					{ return AND_ASSIGN; }
"^="					{ return XOR_ASSIGN; }
"|="					{ return OR_ASSIGN; }
">>"					{ return RIGHT_OP; }
"<<"					{ return LEFT_OP; }
"++"					{ return INC_OP; }
"--"					{ return DEC_OP; }
"->"					{ return PTR_OP; }
"&&"					{ return AND_OP; }
"||"					{ return OR_OP; }
"<="					{ return LE_OP; }
">="					{ return GE_OP; }
"=="					{ return EQ_OP; }
"!="					{ return NE_OP; }
";"					{ return ';'; }
("{"|"<%")				{ return '{'; }
("}"|"%>")				{ return '}'; }
","					{ return ','; }
":"					{ return ':'; }
"="					{ return '='; }
"("					{ return '('; }
")"					{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."					{ return '.'; }
"&"					{ return '&'; }
"!"					{ return '!'; }
"~"					{ return '~'; }
"-"					{ return '-'; }
"+"					{ return '+'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"<"					{ return '<'; }
">"					{ return '>'; }
"^"					{ return '^'; }
"|"					{ return '|'; }
"?"					{ return '?'; }
"//".*              { /* DO NOTHING */ }

[<][^>]*[>]                              { 
                                            std::string tmp(yytext);
                                            yylval.s = new std::string(tmp.substr(1, tmp.size() - 2));
                                            return LIBRARY; 
                                        }

{L}{A}+                                 {return check_type();}


([1-9][0-9]*)|0                             {   yylval.i = atoi(yytext);
                                            return I_CONSTANT; }
(([1-9][0-9]*)|0)\.([0-9]+)             {   yylval.f = atof(yytext);
                                            return F_CONSTANT; }
["][^"]*["]        {
                      std::string tmp(yytext);
                      yylval.s = new std::string(tmp.substr(1, tmp.size() - 2));
                      return STRING_LITERAL;  /* " */
	           }


[#]                                    {
                                        return *yytext;}

{WS}+					{ /* whitespace separates tokens */ }
[\n]                                    {lineNum++;}
.					{ /* discard bad characters */ std::cout << "nepoznat karakter " << *yytext  << "\n\n\n";}

%%

int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static int check_type(void)
{
    switch (sym_type(yytext))
    {
        case TYPEDEF_NAME:
            return TYPEDEF_NAME;
        case ENUMERATION_CONSTANT:
            return ENUMERATION_CONSTANT;
    default:{
        yylval.s=new std::string(yytext);
        return IDENTIFIER;
        }
    }
}


