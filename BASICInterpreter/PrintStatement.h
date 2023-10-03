#ifndef PRINT_STATEMENT_INCLUDED
#define PRINT_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class PrintStatement: public Statement
{
private:
	std::string m_variableName;
	std::map<std::string, int>* tempPrintAddress;
	int tempPrintValue;
	int* tempCounter;
public:
	PrintStatement(std::string variableName);
	~PrintStatement(){};
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
