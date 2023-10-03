// LetStatement.cpp:
#include "GoSubStatement.h"

GoSubStatement::GoSubStatement(int lineNum)
: m_lineNum(lineNum)
{}

void GoSubStatement::execute(ProgramState * state, std::ostream &outf)
{	
	//create temp counter and create a stack address pointer
	//push temp counter 
	//then return temp counter to line number to go to
	int* tempCounter = state->programCounter();
	std::stack<int>* tempStackAddress = state->getStack();
	tempStackAddress->push((*tempCounter)++);
	*tempCounter = m_lineNum;
}

