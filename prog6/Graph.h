#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <map>
#include <set>
#include <limits>
using namespace std;
#include "GPSLocation.h"
#include "PriorityQueue.h"

class Graph
{
  class vertexNode
  {
  friend class Graph;
  public:
    vertexNode()
    {
      traversed = false;
      last_vertex = -1;
      lShort = numeric_limits<float>::infinity();
    }

  private:
    bool traversed;
    int last_vertex;
    float lShort;
  };

 public:
  Graph();
  ~Graph();
  inline int getNumVertices()
  {
    return vertexMap.size();
  }

  inline int getNumEdges()
  {
      return numEdges;
  }

  void addVertex(int id,const GPSLocation& loc);
  void addEdge(int v1,int v2,float weight);
  vector<GPSLocation> shortest(const GPSLocation& start,const GPSLocation& end);


 private:
  map<int, GPSLocation>vertexMap;
  map<int, map<int, float> >edgeMap;
  int numEdges; 
  PriorityQueue<int> q;
  vector<vertexNode> vinfo;
  void dijkstra(int start, int end);
  float inf;


};

#endif
