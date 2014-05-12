/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 02/26/14
 */

#include <map>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue
{

  class Node
  {
  private:
    T data;
    float priority;

  public:
    Node(T data, float priority);
    ~Node();
    T getData();
    float getPriority();
    void setPriority(float new_priority);
  };



private:
  vector< Node > heap;
  map<T, int> nodeMap;
  int size;
  void percolateUp(int index);
  void percolateDown(int index);

public:
  PriorityQueue();
  ~PriorityQueue();
  void insert(T obj, float priority);
  T front();
  T pop();
  bool isEmpty();
  void changePriority(T obj, float new_priority);
  void remove(T obj);

};

template<class T>
PriorityQueue<T>::Node::Node(T d, float p)
{
  data = d;
  priority = p;
}

template<class T>
PriorityQueue<T>::Node::~Node()
{
}

template<class T>
T PriorityQueue<T>::Node::getData()
{
  return data;
}

template<class T>
float PriorityQueue<T>::Node::getPriority()
{
  return priority;
}

template<class T>
void PriorityQueue<T>::Node::setPriority(float new_priority)
{
  priority = new_priority;
}

template<class T>
PriorityQueue<T>::PriorityQueue()
{
  size = -1;
  vector< Node > heap;
  map<T, int> nodeMap;
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
}

//this adds a new node
template<class T>
void PriorityQueue<T>::insert(T obj, float priority)
{
  Node n(obj, priority);   //creats a new node
  
  size++;   //increments the size

  heap.push_back(n);    //adds it to the end
  
  percolateUp(size);
  
} 

//places the new node in the correct spot
template<class T>
void PriorityQueue<T>::percolateUp(int index)
{
  int hole = index;
  Node n = heap[hole];

  while(hole > 1 && heap[hole/2].getPriority() < n.getPriority())
  {
    heap[hole] = heap[hole/2];

    nodeMap[heap[hole].getData()] = hole;

    hole = hole/2;
  }


  heap[hole] = n;
}

//returns the object with the lowest priority
template<class T>
T PriorityQueue<T>::front()
{
 
  Node n = heap[0];

  return n.getData();
 
}

//removes and returns the object with the lowest priority
template<class T>
T PriorityQueue<T>::pop()
{
  Node n = heap[0];

  heap[0] = heap[size--];

  percolateDown(0);

  return n.getData();

}

//moves every node up from the given index
template<class T>
void PriorityQueue<T>::percolateDown(int index)
{
  int hole = index;
  Node n = heap[hole];
  int  child = 2*hole;


  if((child+1 <= size) && heap[child+1].getPriority() > heap[child].getPriority())
    child++;

  while((child <= size) && heap[child].getPriority() > n.getPriority())
  {
    heap[hole] = heap[child];
    
    nodeMap[heap[hole].getData()] = hole;
    
    hole = child;

    child = 2*hole;

    if((child+1 <= size) && heap[child+1].getPriority() > heap[child].getPriority())
    {
      child++;
    }
    
   }  
  
  heap[hole] = n;

}


//This method will return if the queue is empty or not
template<class T>
bool PriorityQueue<T>::isEmpty()
{
  if(heap.size() > 0)
    return false;
  else
    return true;
}

//This method allows you to change the priority of a given object
template<class T>
void PriorityQueue<T>::changePriority(T obj, float new_priority)
{
  if(&nodeMap[obj] != NULL)
  {
    int index = nodeMap[obj];   //get the index in the array

    Node n = heap[index];     //get the correct node

    float old_priority = n.getPriority();   //store the old priority to compare later

    n.setPriority(new_priority);   //set new priority

    heap[index] = n;   //place the node back in the queue


    //change the location based on new priority
    if(old_priority > new_priority)
      percolateUp(index);
    else
      percolateDown(index);
  }

}

//This method will remove the given object from the queue
template<class T>
void PriorityQueue<T>::remove(T obj)
{
  changePriority(obj, 0.0);   //sends it to the front of queue
  pop();  //pops off the lowest priority object

}
