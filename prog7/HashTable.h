/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/25/14
 */

 #include "Date.h"

 #include <string>
 #include <vector>
 using namespace std;

 class HashTable
 {
 	class HashNode
 	{
 		friend class HashTable;
 	public:
 		HashNode()
 		{
 			nodeDate = NULL;
			isNull = true;
 		}
 		~HashNode()
 		{

 		}
 	private:
 		bool isNull;
 		Date *nodeDate;
 		vector<string> names;
 	};

 public:
 	HashTable();
 	~HashTable();
 	vector<string> get(Date d);
 	void insert(Date d, string value);


 private:
 	int hash(Date key, int i);
 	void rehash();
 	void readPrimes();
 	bool checkDate(Date a, Date *b);
 	vector<int> primes;
 	HashNode *table;
 	float numVals;
 	int sizeIndex;
 	float LOAD_FACTOR;

 };
