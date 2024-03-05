#include <iostream>
#include <vector>
using namespace std;
vector<string> summaryRanges(vector<int> &nums) {
  vector<string> vec;
  int i = 0, low, high;
  string str;
  while (i < nums.size()) {
    low = i;
    i++;
    while (i < nums.size() && nums[i] == nums[i - 1] + 1)
      i++;
    high = i - 1;
    str = to_string(nums[low]);
    if (low < high) {
      str.append("->");
      str.append(to_string(nums[high]));
    }
    vec.push_back(str);
  }
  return vec;
}
int main() { 
  vector<int> vec0 = {0, 1, 2, 4, 5, 7};
  vector<string> vec1 = summaryRanges(vec0);
  for(auto str : vec1)
    cout << str << endl;
  return 0; 
}