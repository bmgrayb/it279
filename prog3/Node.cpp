/*
 *ulid: bmgrayb
 *programmer: Brandon Graybeal
 *Date: 2/25/14
 * This represents one node in the priority queue
 */

#include "Node.h"
using namespace std;

template<class T>
Node<T>::Node(T data, float priority)
{
  this->data = data;
  this-> priority = priority;
}

template<class T>
T Node<T>::getData()
{
  return data;
}

template<class T>
float Node<T>::getPriority()
{
  return priority;
}

template<class T>
void Node<T>::setPriority(float newPriority)
{
  priority = newPriority;
}
