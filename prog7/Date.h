/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/25/14
 */

 #ifndef _DATE_H_
 #define _DATE_H_

 class Date
 {
 public:
 	friend class HashTable;

 	Date(int m, int d, int y)
 	{
 		this->day = d;
 		this->month = m;
 		this->year = y;
 	}

 	~Date()
 	{

 	}

 private:
 	int day;
 	int month;
 	int year;
 };

 #endif