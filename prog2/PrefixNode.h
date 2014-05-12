/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/18/14
 */

#include <vector>
using namespace std;

class PrefixNode
{

 private:
  vector<string> words;
  PrefixNode* nodeList[26];

 public:
  PrefixNode();
  ~PrefixNode();

 friend class WordCompleter;

};
