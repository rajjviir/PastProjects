#include "company.hpp"
#include <iostream>

// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n)
{
  numCompanies = n;
  companies = new Company* [numCompanies];
  for (int i = 0; i < numCompanies; ++i){
      companies[i] = new Company ();
  }
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{
  //create for loop to iterate through each base company and split from top down
  //start at parent and split all children
  for (int i = 0; i < numCompanies; i++){
    while (companies[i]->parent  != nullptr){
      split(i);
    }
  }

  //deallocate memory using for loop to get individual values and then entire array
  for (int i = 0; i < numCompanies; i++){
     delete companies[i];
  }
  delete[] companies;
}

void CompanyTracker::merge(int i, int j)
{
  //bounds checking
  if ((i < 0) || (i >= numCompanies)){
    return;
  }
  if ((j < 0) || (j >= numCompanies)){
    return;
  }

  //use largest company function to find largest companies for two children
  Company* firstChild = findLargestCompany(i);
  Company* secondChild = findLargestCompany(j);

  //if they aren't already in the same large company, combine them into new large company
  if (firstChild != secondChild){
    Company* newParent = new Company(firstChild, secondChild);
    
    //set each large company parent to new largest company
    firstChild -> parent = newParent;
    secondChild -> parent = newParent;
  }
  else{
    return;
  }
}

void CompanyTracker::split(int i)
{

  //bounds check
  if ((i < 0) || (i >= numCompanies)){
    return;
  }
  if ((companies[i]->merge1 == nullptr) && (companies[i]->merge2 == nullptr) && (companies[i]->parent == nullptr)){
     return;
  }

  //find biggest parent company
  Company* biggestParent = findLargestCompany(i);

  //find biggest parent company's children
  Company* childOne = biggestParent->merge1;
  Company* childTwo = biggestParent->merge2;

  //set the childrens' parent to null pointer to get rid of biggest company
  //also, set the pointers of biggest parent to nullptr so now it has no connections
  //and no lost pointers/memory
  childOne->parent = nullptr;
  childTwo->parent = nullptr;
  biggestParent -> merge1 = nullptr;
  biggestParent -> merge2 = nullptr;

  //deallocate with delete
  delete biggestParent;
}

bool CompanyTracker::inSameCompany(int i, int j)
{
  //bounds check
  if ((i < 0) || (i >= numCompanies)){
    return false;
  }
  if ((j < 0) || (j >= numCompanies)){
    return false;
  }

  //find biggest company of both companies
  Company* child1 = findLargestCompany(i);
  Company* child2 = findLargestCompany(j);
  
  //check if their biggest companies are the same and return values
  if (child1 == child2){
    return true;
  }
  else{
    return false;
  }
}

Company* CompanyTracker::findLargestCompany (int i)
{
  //bounds check
  if ((i < 0) || (i >= numCompanies)){
    return nullptr;
  }

  //create temp company pointer
  Company *temp;
  temp = companies[i];
  //use while loop to iterate up company branches until you find company with parent null pointer
  while (temp->parent != nullptr){
    temp = temp->parent;
  }
  return temp;
}

