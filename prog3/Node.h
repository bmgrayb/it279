/*
 *ulid: bmgrayb
 *programmer: Brandon Graybeal
 *Date: 2/25/14
 *This represents one node in the priority queue
 */

template<class T> 
class Node
{
 private: 
  T data;
  float priority;

 public:
  Node(T data, float priority);
  T getData();
  float getPriority();
  void setPriority(float newPriority);
  friend class PriorityQueue;

};
