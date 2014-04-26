/***
 This file is a placeholder for the Statement_block class you will write in
 the next assignment p7.
 
 You may use it w/o modification in p6.
 
 You may use it as a starting point for your Statement_block class for p7.
 
 I have put in just enough for it to work in p6.
 
 ***/


#ifndef STATEMENT_BLOCK_H
#define STATEMENT_BLOCK_H

#include <iostream>
#include <vector>
#include "statement.h"

#include "indent.h"

class Game_object;
class Statement;

class Statement_block
{
public:
    
    Statement_block(int block_line);
    bool empty();
    void execute();
    
    std::ostream &print(std::ostream &os) const;
    bool insert(Statement *stmt);
        // line number statement block starts on (only used for debugging)
    int m_line;
    
private:
    std::vector<Statement*> m_vector_Statements; //vector of statement pointers
    
};


std::ostream & operator<<(std::ostream &os, const Statement_block &statement_block);

std::ostream & operator<<(std::ostream &os, const Statement_block *statement_block);

#endif // #ifndef STATEMENT_BLOCK_H
