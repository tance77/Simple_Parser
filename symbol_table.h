#ifndef SYMBOL_TABLE_H
#define SYMBOL_TBALE_H

#include <string>
#include <map>
#include <iostream>
#include "symbol.h"

using namespace std;

class Symbol_table
{
public:
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);
    static Symbol_table *instance();
    Symbol* lookup(string target);
    void print(ostream &os);
    void insert(string a, Symbol* symbol);
private:
    static Symbol_table *m_instance;
    map<string,Symbol*> mTable;
    map<string,Symbol*>::iterator it;
    Symbol_table() {};
};

#endif
