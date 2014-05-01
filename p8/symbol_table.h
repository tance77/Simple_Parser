#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <map>
#include <iostream>
#include "symbol.h"
#include "game_object.h"
#include "animation_block.h"

using namespace std;

class Symbol_table
{
public:
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);
    static Symbol_table *instance();
    Symbol* lookup(string target);
    void print(ostream &os);
    bool insert(string a, Symbol* symbol);
    bool get(string name, int &value);
	bool get(string name, double &value);
	bool get(string name, string &value);
	bool get_type(string name, Gpl_type &type);
	bool set(string name, int value); // used for mouse_x, mouse_y
private:
    static Symbol_table *m_instance;
    map<string,Symbol*> mTable;
    map<string,Symbol*>::iterator it;
    Symbol_table() {};
};

#endif
