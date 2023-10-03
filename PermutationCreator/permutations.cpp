#include <iostream>
#include <string>
#include <vector>

using namespace std;

//create permutations vector of strings
vector<string> perms;

//helper function to swap characters in each permutation
void helperSwap(char& start, char& end){
    char temp = start;
    start = end;
    end = temp;
}
//helper function that takes in string and two ints to find size of string
void helper(string& recursion, int begin, int end){
    //recursion base case that pushes every new string
    if (begin >= end){
        perms.push_back(recursion);
        return;
    }
    
    //iterates through each string and swaps the character, calls recursion on new string
    //and then swaps back
    for (int i = begin; i < end; i++){
        helperSwap(recursion[begin], recursion[i]);
        helper(recursion, begin + 1, end);
        helperSwap(recursion[begin], recursion[i]);
    }
}

//takes in string argument and passes to helper recursion function with size of string
void permutations(std::string in){
    int first = 0;
    int last = in.size();
    helper(in, first, last);
}