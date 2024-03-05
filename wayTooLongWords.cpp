#include <iostream>
using namespace std;
int main() {
  int count;
  cin >> count;
  string strs[100], str;
  for (int i = 0; i < count; i++) {
    cin >> str;
    strs[i] = "";
    if (str.length() <= 10)
      strs[i] = str;
    else
      strs[i] = str[0] + to_string(str.length() - 2) + str[str.length() - 1];
  }
  for (int j = 0; j < count; j++)
    cout << strs[j] << endl;
  return 0;
}