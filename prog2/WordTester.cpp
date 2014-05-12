/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/18/2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WordCompleter.h"
using namespace std;

int main()
{

  WordCompleter myWord;
  vector<string> foundStr;
  string curr;

  //the dictionary file to read from 
  ifstream dictionary("english.0");

  
  if(dictionary.is_open())
  {

    //reads through the file until the eof
    getline(dictionary, curr);
    while(!dictionary.eof())
    {
      
      //this section removes punction from the string
      string newStr;
      for(int i = 0; i < curr.length(); i++)
      {
	if(!(curr[i] == '\'' | curr[i] == '.' | curr[i] == ',' | curr[i] == '\"' | curr[i] == ';'))
	{
	  newStr+= curr[i];
	}
      }
      
      curr = newStr;
      
      //the word is then added to the string
      myWord.add(curr);
      
      getline(dictionary, curr);
    }
    
    dictionary.close();
  }
  else
  {
    cout << "Could not open file!" << endl;
  }

  

  //this gets the input from the user
  cout << "Please enter the word you would like to find: ";
  string word;
  getline(cin, word);

  //as long as the line isn't blank it will run
  while(word != "\0")
  {
    //if the word is found the information is printed to the console
    if(myWord.find(word))
    {
      cout << "Found the word: " << word << endl;

      foundStr = myWord.search(word);

      cout << "Number of words with prefix: " << foundStr.size() << endl;

      for(int i = 0; i < foundStr.size(); i++)
	cout << foundStr[i] << endl;
    }
    else
    {
      cout << "Could not find word " << word << endl;
    }

    //a new word is then entered
    cout << "Please enter the next word: ";
    getline(cin, word);

  }

  
}
