#include "statement_block.h"
#include "gpl_assert.h"
using namespace std;


Statement_block::Statement_block(int block_line)
{
  m_line = block_line;
}

bool Statement_block::empty()
{
  return m_vector_Statements->empty(); //returns true if it is empty false if its not
}

void Statement_block::execute()
{
  if(!empty()) //if the vector is not empty we need to execute
    for(Statement* cur_statement: *m_vector_Statements)
        //for each statement cur_statement in the vector of statements m_vector_Statements, call execute on the statement
      cur_statement->execute();
}

ostream & Statement_block::print(ostream &os) const
{
  os << indent << "Statement_block[" << m_line;
  
  os << "]" << endl
  << indent << "{" << endl;
  indent++;
  os << indent << "statement block not implemented yet" << endl;
  indent--;
  os << indent << "}";
  return os;
}


ostream & operator<<(ostream &os, const Statement_block &statement_block)
{
  return statement_block.print(os);
}

ostream & operator<<(ostream &os, const Statement_block *statement_block)
{
  if (!statement_block)
    {
    os << indent << "NULL";
    return os;
    }
  
  return statement_block->print(os);
}
