/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 02/26/14
 */

#include "PriorityQueue.h"
#include <vector>
using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue()
{
  this->size = 0;
  vector< Node<T> > heap;
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
}

//this adds a new node
template<class T>
void PriorityQueue<T>::insert(T obj, float priority)
{
  Node<T>* n = new Node<T>(obj, priority);   //creates a new node
  heap.push_back(n);    //adds it to the end
  percolateUp(heap.size());    //places it where it should be
  
} 

//places the new node in the correct spot
template<class T>
void PriorityQueue<T>::percolateUp(int index)
{
  int hole = index;
  Node<T>* n = heap[hole];

  while(hole > 1 && heap[hole/2]->priority > n->priority)
  {
    heap[hole] = heap[hole/2];
    hole = hole/2;
  }

  heap[hole] = n;

}

//returns the object with the lowest priority
template<class T>
T PriorityQueue<T>::front()
{
  if(heap.size() > 0)
    return heap[1];
  else
    return;
}

//removes and returns the object with the lowest priority
template<class T>
T PriorityQueue<T>::pop()
{
  T data = heap[1]->data; //gets the object 
  percolateDown(1);   //moves every node up

}

//moves every node up from the given index
template<class T>
void PriorityQueue<T>::percolateDown(int index)
{
  int hole = index;
  Node<T>* n = heap[hole];
  int child = 2*hole;

  if((child + 1 <= heap.size()) && heap[child+1]->priority < heap[child]->priority)
    child++;

  while((child <= heap.size()) && (heap[child]->priority < n->priority))
  {
    heap[hole] = heap[child];
    hole = child;
    child = 2*hole;
    if((child+1 <= heap.size()) && heap[child+1]->priority < heap[child]->priority)
      child++;
    
  }
  
  heap[hole] = n;

}

template<class T>
bool PriorityQueue<T>::isEmpty()
{
  if(heap.size() == 0)
    return true;
  else
    return false;
}

template<class T>
void PriorityQueue<T>::changePriority(T obj, float new_prioirity)
{
}

template<class T>
void PriorityQueue<T>::remove(T obj)
{
}
