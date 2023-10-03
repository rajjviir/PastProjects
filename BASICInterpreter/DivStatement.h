#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class DivStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;
	bool variable = false;
    std::string m_variableAdd;
	std::map<std::string, int>* tempLetAddress;
public:
	DivStatement(std::string variableName, int value);
	DivStatement(std::string variableName, std::string variableAdd);
	~DivStatement(){};

	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
