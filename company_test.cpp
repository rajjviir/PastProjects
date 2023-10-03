#include <iostream>
#include "company.hpp"
using namespace std;
int main(){
    //allocating array of 10 companies
    CompanyTracker testing(10);

    //testing merge function between 0 and 1
    testing.merge(0,1);
    bool mergeWorkOne = testing.inSameCompany(0, 1);
    cout << mergeWorkOne << endl;

    //testing merge function between 2 and 3
    testing.merge(2,3);
    bool mergeWorkTwo = testing.inSameCompany(2, 3);
    cout << mergeWorkTwo << endl;

    //merging 2 and 3 larger company with singular 4 company
    testing.merge(2,4);
    mergeWorkTwo = testing.inSameCompany(2, 3);
    cout << mergeWorkTwo << endl;

    //merging larger 2,3,4 company with company 5
    testing.merge(2,5);

    //merging 0 and 1 company with 2,3,4,5 company
    testing.merge(0,3);
    bool mergeWorkThree = testing.inSameCompany(0, 3);
    cout << mergeWorkThree << endl;

    //reversing previous operation and checking if split function works
    testing.split(0);
    bool splitWorkOne = testing.inSameCompany(0, 3);
    cout << splitWorkOne << endl;

    //series of splits to check for memory leaks in "lost" new companies
    testing.split(1);

    testing.split(2);

    testing.split(3);

    testing.split(4);

    testing.split(5);

    // merging invalid companies to see no effect
    testing.merge(-1, 3);

    // splitting a company with no parents or children to no effect
    testing.split(4);

    // checking in same company function for invalid companies
    bool inSameInvalid = testing.inSameCompany(-1, 11); // Should return false
    cout << "inSameCompany(-1, 11): " << inSameInvalid << endl;

    return 0;
}


