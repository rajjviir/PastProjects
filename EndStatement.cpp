// EndStatement.cpp:
#include "EndStatement.h"


EndStatement::EndStatement()
{}

void EndStatement::execute(ProgramState * state, std::ostream &outf)
{   
	//if end, terminate program
	state->setEnd(true);
}

