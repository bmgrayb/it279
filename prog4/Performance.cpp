#include "Performance.h"
#include <iostream>
using namespace std;

Performance::Performance()
{
  this->numCompare = 0;
  this->numAssign = 0; 
}

void Performance::addCompare()
{
  numCompare++;
}

void Performance::addAssign()
{
  numAssign++;
}

void Performance::reset()
{
  numCompare = 0;
  numAssign = 0;
}

void Performance::printResults()
{
  cout << "Number of comparisons: " << numCompare << endl;
  cout << "Number of assignments: " << numAssign << endl;
  cout << "\n";

}
