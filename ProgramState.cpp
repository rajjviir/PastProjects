#include "ProgramState.h"


//create many different functions within this file 
//that can be called universally and used to determine
//programstate object values
ProgramState::ProgramState(int numLines){
    m_numLines = numLines;
}
int ProgramState::getNumLines(){
    return m_numLines;
}
std::map<std::string, int>* ProgramState::getMapAddress(){
    return &ProgramStateMap;
}

std::stack<int>* ProgramState::getStack(){
    return &returnStack;
}
int* ProgramState::programCounter(){
    return &lineCounter;
}
void ProgramState::setEnd(bool end) {
    endExecution = end;
}

bool ProgramState::isEnd() const {
    return endExecution;
}