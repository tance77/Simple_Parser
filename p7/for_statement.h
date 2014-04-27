#ifndef FOR_STATEMENT_H
#define FOR_STATEMENT_H

#include "statement.h"
#include "statement_block.h"

class For_Statement : public Statement
{
public:
    For_Statement(Statement_block*, Expression*, Statement_block*, Statement_block*);
    virtual void execute();
private:
    Expression* m_second_condition;
    Statement_block* m_third_condition;
    Statement_block* m_first_condition;
    Statement_block* m_stuff_in_for_loop;
};

#endif