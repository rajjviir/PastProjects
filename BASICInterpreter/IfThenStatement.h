 #ifndef IFTHEN_STATEMENT_INCLUDED
#define IFTHEN_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class IfThenStatement: public Statement
{
private:
	int m_value;
	std::string m_variableName;
	std::string m_typeOperator;
	int m_lineNum;
	std::map<std::string, int>* tempLetAddress;
	int temp;
	int* tempCounter;
	bool equationPassed;
	bool goodJump;
public:
	IfThenStatement(int value, std::string variableName, std::string typeOperator, int lineNum);
	~IfThenStatement(){};
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
