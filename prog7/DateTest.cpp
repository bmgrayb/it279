/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/25/14
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "HashTable.h"
#include "Date.h"

using namespace std;

int main(int argc, char *argv[])
{
  
  //checks to see correct number of arguments are passed in
  if(argc != 2)
    cerr << "Not correct number of arguments passed in." << endl;
  
  //creates a hash table
  HashTable htable;
  vector<string> nameVector;
  int i, dayNum, monthNum, yearNum;
  string day, month, year;

  ifstream infile(argv[1]);

  if(!infile.is_open())
    cout << "Could not open the file." << endl;
  else
  {
    string line;
    string name;
    int count = 0;

    while(getline(infile, line))
    {
      stringstream instream(line);
      
      getline(instream, name, ',');
      getline(instream, month, '/');
      getline(instream, day, '/');
      getline(instream, year);

      Date d(atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()));

      htable.insert(d, name);

    }


  }

  

  string wholeDate;

  //get the initial date from the user
  cout << "Please enter a date (mm/dd/yyyy) or 0 when finished: " ;
  cin >> wholeDate;

  //parse the initial date
  stringstream newinstream(wholeDate);
  getline(newinstream, month, '/');
  getline(newinstream, day, '/');
  getline(newinstream, year);

  dayNum = atoi(day.c_str());
  monthNum = atoi(month.c_str());
  yearNum = atoi(year.c_str());

  while(dayNum != 0 && monthNum != 0 && yearNum != 0)
  {
    Date getDate(monthNum, dayNum, yearNum);
    nameVector = htable.get(getDate);

    if(nameVector.size() == 0)
      cout << "No names found for that date" << endl;
    else
    {
      cout << "Number of names for date: " << month << "/" << day << "/" << year << ": " << nameVector.size()<< endl;

      for(i = 0; i < nameVector.size(); i++)
        cout << nameVector[i] <<  endl;
    }

    //get the next date from the user
    cout << "Enter another date or 0 when finished: " ;
    cin >> wholeDate;

    //parse the next date
    stringstream newinstream(wholeDate);
    getline(newinstream, day, '/');
    getline(newinstream, month, '/');
    getline(newinstream, year);

    dayNum = atoi(day.c_str());
    monthNum = atoi(month.c_str());
    yearNum = atoi(year.c_str());

  }
  
  
  return 0;
}
