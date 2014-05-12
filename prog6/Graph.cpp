/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/15/14
 */

#include "Graph.h"
#include "PriorityQueue.h"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

Graph::Graph()
{
  numEdges = 0;
  inf = numeric_limits<float>::infinity();   //infinity 

}

Graph::~Graph()
{
}

//adds a vetex to the graph
void Graph::addVertex(int id,const GPSLocation& loc)
{
  vertexMap[id] = loc;
}

//adds an edge to the graph
void Graph::addEdge(int v1,int v2,float weight)
{
  edgeMap[v1][v2] = weight;
  numEdges++;
}

//this method returns the shortest path between to GPSLocations in a graph
vector<GPSLocation> Graph::shortest(const GPSLocation& start,const GPSLocation& end)
{  
  
  vector<GPSLocation> shortest_path;
  int startID, endID;
  float startWeight, endWeight, tempStart, tempEnd;
  startWeight = endWeight = numeric_limits<float>::max();   //sets max value

  vertexNode *v;

  map<int, GPSLocation>::iterator it; 

  //this for loop iterates across the whole map
  for(it = vertexMap.begin(); it != vertexMap.end(); it++)
  {

    //finds the vertex closest to the start and end vertex
    tempStart = start.getDistance(it->second);
    tempEnd = end.getDistance(it->second);

    if(tempStart < startWeight)
    {
      startWeight = tempStart;
      startID = it->first;
    }

    if(tempEnd < endWeight)
    {
      endWeight = tempEnd;
      endID = it->first;
    }

    //inserts into priority queue
    q.insert(it->first, inf);
    
    //inserts into our vinfo vector
    v = new vertexNode();
    vinfo.push_back(*v);

    delete [] v;
   
  }

  //calls the algorithm to find the shortest path
  dijkstra(startID, endID);

  int curr = endID;

  //inserts the end GPSLocation
  shortest_path.push_back(end);  

  //this backtracks across the list of last_vertex to find the
  //shortest path
  while(curr != startID)
  {
    shortest_path.push_back(vertexMap[curr]);
    curr = vinfo[curr].last_vertex;
  }

  //adds the start index
  shortest_path.push_back(vertexMap[startID]);

  //adds the actual start location
  shortest_path.push_back(start);

  //reverses the list
  reverse(shortest_path.begin(),shortest_path.end());

  return shortest_path;  
}

//this method finds the shortest path in a graph between two points
void Graph::dijkstra(int start,int end)
{
  bool done = false;
  int id;
  vertexNode v;
  map<int, float>::iterator it;

  q.changePriority(start, 0);   //change priority
  vinfo[start].lShort = 0;   //set the weight of path to 0
  
  while(!done)
  {
    
    if(q.isEmpty())
      done = true;
    else
    {

      id = q.pop();
      
      v = vinfo[id];
      
      if(v.lShort == inf)
      {
	done = true;
      }
      else
      {
	v.traversed = true;

	if(id == end)
	{
	  done = true;
	}
	else
	{
	  
	  for(it = edgeMap[id].begin(); it != edgeMap[id].end(); it++)
	  {
	    
	    if(vinfo[it->first].traversed != true)
	    {

	      if((vinfo[id].lShort + edgeMap[id][it->first]) < vinfo[it->first].lShort)
	      {
		q.changePriority(it->first, (vinfo[id].lShort + edgeMap[id][it->first]));
		vinfo[it->first].lShort = vinfo[id].lShort + edgeMap[id][it->first];
		vinfo[it->first].last_vertex = id;
	      }

	    }

	  }

	}
	
      }

    }

  }

}
