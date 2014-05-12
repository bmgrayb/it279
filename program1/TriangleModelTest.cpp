/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/2/2014
 */

#include <iostream>
#include "TriangleModel.h"
using namespace std;

int main(int argc, char *argv[])
{

  TriangleModel object1;

  if(argc != 2)
    cout << "Incorrect command line input!" << endl;

  if(object1.readInputFile(argv[1]))
  {
    cout << "Using file: " << argv[1] << endl;
    cout << "Volume: " << object1.getVolume() << endl;
  }
  else
  {
    cout << "File could not be opened!" << endl;
  }


}
