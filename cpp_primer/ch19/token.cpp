#include "token.h"
using std::string;

Token& Token::operator=(int i)
{
    if (tok == STR) svar.~string();
    tok = INT;
    ivar = i;
    return *this;
}

Token& Token::operator=(char c)
{
    if (tok == STR) svar.~string();
    tok = CHAR;
    cvar = c;
    return *this;
}

Token& Token::operator=(double d)
{
    if (tok == STR) svar.~string();
    tok = DBL;
    dvar = d;
    return *this;
}

Token& Token::operator=(const string& s)
{
    if (tok == STR)
        svar = s;
    else
        new(&svar) string(s);
    tok = STR;
    return *this;
}

void Token::copyUnion(const Token& t)
{
    switch(t.tok){
        case INT: ivar = t.ivar; break;
        case CHAR: cvar = t.cvar; break;
        case DBL: dvar = t.dvar; break;
        case STR: new(&svar) string(t.svar); break;
    }
}

Token& Token::operator=(const Token& t)
{
    if (tok == STR && t.tok != STR) svar.~string();
    if (tok == STR && t.tok == STR)
        svar = t.svar;
    else
        copyUnion(t);
    return *this;
}