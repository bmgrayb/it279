/*
 *ULID: bmgrayb
 *Programmer: Brandon Graybeal
 *Date: 2/18/14
 */

#include <vector>
#include <string>
#include "PrefixNode.h"
using namespace std;


class WordCompleter
{
 friend class PrefixNode;
 private:
  PrefixNode* root;

 public:
  WordCompleter();
  ~WordCompleter();
  void add(string s);
  vector<string> search(string prefix);
  bool find(string word);

};
