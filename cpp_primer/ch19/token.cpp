#include "token.h"
using std::string;

void Token::freeUnion()
{
    switch(tok){
        case STR: svar.std::string::~string(); break;
        case SD: sdvar.~Sales_data(); break;
    }
}

Token& Token::operator=(int i)
{
    freeUnion();
    tok = INT;
    ivar = i;
    return *this;
}

Token& Token::operator=(char c)
{
    freeUnion();
    cvar = c;
    return *this;
}

Token& Token::operator=(double d)
{
    freeUnion();
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

Token& Token::operator=(const Sales_data& sd)
{
    if (tok == SD)
        sdvar = sd;
    else
        new(&sdvar) Sales_data(sd);
    tok = SD;
    return *this;
}

void Token::copyUnion(const Token& t)
{
    switch(t.tok){
        case INT: ivar = t.ivar; break;
        case CHAR: cvar = t.cvar; break;
        case DBL: dvar = t.dvar; break;
        case STR: new(&svar) string(t.svar); break;
        case SD: new(&sdvar) Sales_data(t.sdvar); break;
    }
}

Token& Token::operator=(const Token& t)
{
    if (tok == STR && t.tok != STR) svar.~string();
    if (tok == SD && t.tok != SD) sdvar.~Sales_data();
    if (tok == STR && t.tok == STR)
        svar = t.svar;
    else if (tok == SD && t.tok == SD)
        sdvar = t.sdvar;
    else
        copyUnion(t);
    return *this;
}