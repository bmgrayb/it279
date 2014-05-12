/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/26/14
 */

#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

int main()
{
  
  PriorityQueue<string> q;

  //check to see if insert works
  cout << "Inserting: apple. " << endl;
  q.insert("apple", 20.1);

  if(q.isEmpty())
    cout << "Empty. \n" << endl;
  else
    cout << "Not empty. \n" << endl;

  //check to see if pop works. 
  cout << "Popping: " << q.pop() << endl;
  if(q.isEmpty())
    cout << "Heap is now empty.\n" << endl;
  else
    cout << "Still not empty. \n" << endl;


  cout << "Insert: Tests, 1.1" << endl;
  q.insert("Tests ", 1.1);
  cout <<"Insert: min, 2.2" << endl;
  q.insert("min ",2.2 );
  cout << "Insert: heap, 3.3 " << endl;
  q.insert("heap ", 3.3);
  cout << "Insert: sort., 4.4 " << endl;
  q.insert("sort. ", 4.4);
  cout << "Insert: Pretty, 5.5" << endl;
  q.insert("Pretty ", 5.5);
  cout << "Insert: cool." << endl;
  q.insert("cool. ", 6.6);

  cout << "\n";

  cout << "At the front: " << q.front() << endl;
  
  cout << q.pop() << q.pop() << q.pop() << q.pop() << q.pop() << q.pop() << endl;

  
}
