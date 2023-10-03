 #ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GoSubStatement: public Statement
{
private:
	int m_lineNum;
	int* tempCounter;
	std::map<std::string, int>* tempLetAddress;
	std::stack<int>* tempStackAddress;
public:
	GoSubStatement(int lineNum);
	~GoSubStatement(){};
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};


#endif
