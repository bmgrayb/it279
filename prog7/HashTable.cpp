/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/25/14
 */

 #include <string>
 #include <fstream>
 #include <iostream>
 #include <stdlib.h>
 #include "HashTable.h"
 #include "Date.h"
 using namespace std;

////////////////////////////////////////////////////
//				public metods


 //the constructor for a hash table
 HashTable::HashTable()
 {
 	readPrimes();	//initializes the prime number array
 	numVals = 0.0;	//sets the initial number of values to 0
 	sizeIndex = 0;	//sets initial index in the primes array to the first
 	table = new HashNode[primes[sizeIndex]];

 	LOAD_FACTOR = 0.45;
 }

 //destructor for a hash table
 HashTable::~HashTable()
 {
   delete [] table;
 }

 //this function inserts a value into the hash table
 void HashTable::insert(Date d, string value)
 {
   
 	//if the array gets more than 0.45 full, rehash
 	if((numVals/primes[sizeIndex]) >= 0.45)
 	{
 		rehash();
 	}

 	int i = 0;	//value for quadratic probing
 	int key = hash(d, i);	//creates a new key

	while((table[key].isNull == false) && !checkDate(d, table[key].nodeDate))
	{
	  i++;
	  key = hash(d,i);
	}

	if(table[key].isNull == true)
	{
	  //intializes the values of curr
	  table[key].isNull = false;
	  table[key].nodeDate = new Date(d.month, d.day, d.year);
	  table[key].names.push_back(value);
	  numVals++;
        }
	else
	{
	  //the date is the same so push back the value
	  table[key].names.push_back(value);
	}
	
 }

//This function will return a vector of all the names for a given date
vector<string> HashTable::get(Date d)
{
  int i = 0;
  int key = hash(d, i);
  vector<string> returnNames;

  while((table[key].isNull == false) && !checkDate(d, table[key].nodeDate))
  {
      i++;
      key = hash(d, i);
  }

  return table[key].names;


}

///////////////////////////////////////////////////////////
//					private functions

//This function initializes the vector that contains all the prime numbers
void HashTable::readPrimes()
{
	ifstream infile("primes-to-100k.txt");
	string line;

	if(infile.is_open())
	{
		while(getline(infile, line))
		{
			primes.push_back(atoi(line.c_str()));
		}

	}
	else
		cout << "Could not read in primes file." << endl;

}

//this is the hash function. It takes in a Date object and an integer
//It adds up all the values of the date, adds the square of the integer
//and returns a value that is modded by the table size
int HashTable::hash(Date key, int i)
{
	int newKey = key.day + key.month + key.year + i*i;
	return newKey % primes[sizeIndex];
}

//This function will compare two dates
bool HashTable::checkDate(Date a, Date *b)
{
	if(a.day == b->day && a.month == b->month && a.year == b->year)
		return true;
	else
		return false;
}

void HashTable::rehash()
{

  int oldSize = primes[sizeIndex];	//current size of the array
  int newSize = 2 * primes[sizeIndex];
  int curr = primes[sizeIndex];

  //finds the next highest prime after doubling the size
  while(curr <= newSize)
  {
      sizeIndex++;
      curr = primes[sizeIndex];
  }  

  HashNode *temp = table;
  table = new HashNode[curr];

  int i;
  for(i = 0; i < oldSize; i++)
  {
    if(temp[i].isNull == false)
    {

      	int a = 0;
	Date currDate(temp[i].nodeDate->month, temp[i].nodeDate->day, temp[i].nodeDate->year);
	int key = hash(currDate, a);

	HashNode n = table[key];

	while(n.isNull == false && !checkDate(currDate, n.nodeDate))
	{
	    a++;
	    key = hash(currDate, a);
	    n = table[key];
	}

	n.nodeDate = temp[i].nodeDate;
	n.names = temp[i].names;
      
    }

  }

  delete [] temp;

}

