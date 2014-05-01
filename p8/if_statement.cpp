#include "if_statement.h"
#include "gpl_assert.h"

If_Statement::If_Statement(Expression* expr, Statement_block* stmt_block, Statement_block* stmt_block_else) : Statement()
{
    if(expr != NULL || stmt_block != NULL || stmt_block_else != NULL)
      {
        assert(expr->get_gType() == INT); //assert it is of type int or its an error
        if(expr->get_gType() == INT)
          {
                // cout << "If statement on line: "<< stmt_block->m_line << endl;
                //cout << "Else Statment on line:" << stmt_block_else->m_line << endl;
            m_expression = expr;
            m_stmtblock = stmt_block;
            m_stmtblock_else = stmt_block_else;
          }
        else{
                //error if not type int
        }
      }
    else{
            //else the expression is null or the stmt_block is null
    }
}
void If_Statement::execute()
{
    if(m_stmtblock_else != NULL) //if with else
      {
        if(m_expression->evalint()){
            m_stmtblock->execute();
        }
        else{
            m_stmtblock_else->execute();
        }
      }
    else{ //if with no else
        if(m_expression->evalint()){
            m_stmtblock->execute();
        }
    }
    
}