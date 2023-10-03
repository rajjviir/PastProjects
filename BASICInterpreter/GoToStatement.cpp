// LetStatement.cpp:
#include "GoToStatement.h"

GoToStatement::GoToStatement(int lineNum) : m_lineNum(lineNum)
{}

void GoToStatement::execute(ProgramState * state, std::ostream &outf)
{
	//error check for illegal jump and then 
	//set temp counter to program counter
	//and set programstate counter to goto line
	if (m_lineNum >= state->getNumLines()){
		outf << "Illegal jump instruction" << std::endl;
		state->setEnd(true);
	}
	int* tempCounter = state->programCounter();
	(*tempCounter) = m_lineNum;

}

