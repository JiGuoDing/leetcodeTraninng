#include <iostream>
#include <map>
using namespace std;
bool isIsomorphic(string s, string t) {
  if (s.length() != t.length())
    return false;
  map<char, char> chMap;
  map<char, char> chMap_reverse;
  for (int i = 0; i < s.length(); i++) {
    if (chMap.find(s[i]) == chMap.end()) {
      if (chMap_reverse.find(t[i]) == chMap_reverse.end()) {
        chMap.insert({s[i], t[i]});
        chMap_reverse.insert({t[i], s[i]});
      } else
        return false;
    } else {
      if (chMap[s[i]] != t[i])
        return false;
    }
  }
  return true;
}
int main() {
  cout << isIsomorphic("badc", "baba") << endl;
  return 0;
}
