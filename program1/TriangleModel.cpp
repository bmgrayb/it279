/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/2/2014
 *This program will take an OBJ file and caculate the volume
 *of the given object.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "TriangleModel.h"
using namespace std;

TriangleModel::TriangleModel()
{
  ifstream objFile;
  vector<float>  xVec, yVec, zVec;
  vector<int>  point1, point2, point3;
}

TriangleModel::~TriangleModel()
{
  xVec.clear();
  yVec.clear();
  zVec.clear();
  point1.clear();
  point2.clear();
  point3.clear();
}

//This method reads in a file and then stores the values into several different
//vectors. A set of three for the vertices, and one for the points used in the
//triangle.
bool TriangleModel::readInputFile(char *filename)
{

  float xLoc, yLoc, zLoc = 0;
  int vert1, vert2, vert3 = 0;

  objFile.open(filename);   //opens the file
  string line;

  //if the file will not open show error message
  if(objFile.fail())
  {
    cout << "File did not open." << endl;
    return false;
  }
  else
  {

      while(getline(objFile, line))
      {
	//a tokenizer is used to break up a whole line of input
	istringstream tokenizer(line);
	string token;

	//a space is used as a delimiter to read in each piece of 
	//of info on each line
	getline(tokenizer, token, ' ');

	if(token.compare("f"))
	{
	  //get the x location and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream float_issX(token);
	  float_issX >> xLoc;
	  xVec.push_back(xLoc);

	  //get y location and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream float_issY(token);
	  float_issY >> yLoc;
	  yVec.push_back(yLoc);

	  //get z location and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream float_issZ(token);
	  float_issZ >> zLoc;
	  zVec.push_back(zLoc);

	}
	else
	{
	  
	  //get first vertex and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream int_iss1(token);
	  int_iss1 >> vert1;
	  point1.push_back(vert1);

	  //get second vertex and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream int_iss2(token);
	  int_iss2 >> vert2;
	  point2.push_back(vert2);

	  //get third vertex and push it to the vector
	  getline(tokenizer, token, ' ');
	  istringstream int_iss3(token);
	  int_iss3 >> vert3;
	  point3.push_back(vert3);

	}
      

      }

      objFile.close();
      return true;

    }

 }

//This method calculates the volume of the object
float TriangleModel::getVolume()
{
  int i;
  int vert1, vert2, vert3;
  float first, second, third;
  float volume = 0.0;
  float newVol = 0.0;

  for(i = 0; i < point1.size(); i++)
  {
    //gets the location of each vertex being used
    vert1 = point1[i]-1;
    vert2 = point2[i]-1;
    vert3 = point3[i]-1;

    //breaks up the equation into individual parts
    first = xVec[vert1]*(yVec[vert2]*zVec[vert3]-yVec[vert3]*zVec[vert2]);
    second = yVec[vert1]*(xVec[vert2]*zVec[vert3]-xVec[vert3]*zVec[vert2]);
    third = zVec[vert1]*(xVec[vert2]*yVec[vert3]-xVec[vert3]*yVec[vert2]);

    volume += first - second + third;

  }
  
  return volume/6.0;

}

