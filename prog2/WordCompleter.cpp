/* ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/18/2014
 *
 */


#include <vector>
#include <string>
#include "WordCompleter.h"
using namespace std;


WordCompleter::WordCompleter()
{
  this->root = new PrefixNode();

}

WordCompleter::~WordCompleter()
{
  //delete[] root;
}

//This method will add a given word to the word completer
void WordCompleter:: add(string s)
{
  PrefixNode* curr = root;

  if(s.length() == 0)
    return;

  for(int i = 0; i < s.length(); i++)
  {
    //this gets the integer value of the letter
    int child = tolower(s[i]) - 'a';   

    //if the child is not foud, create a new node at that index
    if(curr->nodeList[child] == NULL)
    {
      PrefixNode* n = new PrefixNode();
      n->words.push_back(s);
      curr->nodeList[child] = n;
      curr = n;
    }
    //else make curr the child node
    else
    {
      curr->words.push_back(s);
      curr = curr->nodeList[child];
    }

  }

}

//This method will search for all words starting with the given prefix
vector<string> WordCompleter::search(string prefix)
{
  PrefixNode* curr = root;
  PrefixNode* next = root;
  int i = 0;
  
  while(next != NULL)
  {
    int child = tolower(prefix[i]) - 'a';
    curr = next;
    next = next->nodeList[child];
    i++;
  }
  
  return curr->words;

}


//This method will return whether or not a given word is found
bool WordCompleter::find(string word)
{
  PrefixNode* curr = root;
  //boolean to see if word was found
  bool found = true;
  
  //this loop steps through to check if the provided word was found
  for(int i = 0; i < word.length(); i++)
  {
    //the index of the current letter in the string
    int child = tolower(word[i]) - 'a';

    //if its null then the word does not exist
    if(curr->nodeList[child] == NULL)
      found = false;
    else
      curr = curr->nodeList[child];
  }

  return found;

}
