#include <iostream>
#include <vector>
using namespace std;
int main() {
  string str, str_to_insert = "";
  vector<string> vec;
  while (cin >> str) {
    str_to_insert = "";
    for (int i = str.size() - 1; i >= 0; i--) str_to_insert += str[i];
    vec.push_back(str_to_insert);
  }
  for (auto elem : vec) cout << elem << endl;
  return 0;
}