#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
private:
	std::string m_variableName;
    std::string m_variableAdd;
	int m_value;
	std::map<std::string, int>* tempLetAddress;
    bool variable = false;
public:
	MultStatement(std::string variableName, int value);
	MultStatement(std::string variableName, std::string variableAdd);
	~MultStatement(){};

	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
