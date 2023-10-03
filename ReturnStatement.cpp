// LetStatement.cpp:
#include "ReturnStatement.h"

ReturnStatement::ReturnStatement()
{}

void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{	
	//return statement will find stack and line counter
	int* tempCounter = state->programCounter();
	std::stack<int>* tempStackAddress = state->getStack();
	//if stack is empty, terminate program
	if(tempStackAddress->empty()){
		state->setEnd(true);
	}
	//if stack not empty, pop top number and iterate program
	else{
		*tempCounter=tempStackAddress->top();
		tempStackAddress->pop();
		(*tempCounter)++;
	}
}

