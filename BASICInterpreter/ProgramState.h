#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include <stack>
#include <map>

class ProgramState
{
public:
	ProgramState(int numLines);
	~ProgramState(){};

	std::map<std::string, int> * getMapAddress();
	// You'll need to add a variety of methods here.  Rather than trying to
	// think of what you'll need to add ahead of time, add them as you find
	// that you need them.
	//map<string, int> ProgramStateMap;
	int* programCounter();
	void setEnd(bool end);
	bool isEnd() const;
	std::stack<int>* getStack();
	//int m_numLines;
	int getNumLines();


	
private:
	int m_numLines;
	std::map<std::string, int> ProgramStateMap;
	int lineCounter = 1;
	bool endExecution = false;
	std::stack<int> returnStack;

};



#endif
