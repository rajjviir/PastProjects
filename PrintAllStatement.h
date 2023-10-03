#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class PrintAllStatement: public Statement
{
private:
	std::map<std::string, int>* tempPrintAddress;
	int* tempCounter;

public:
	PrintAllStatement();
	~PrintAllStatement() {};
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
