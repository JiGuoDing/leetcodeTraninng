#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1)
        return intervals;
    sort(intervals.begin(), intervals.end());
    int left, right;
    vector<int> vec0, vec1;
    vector<vector<int>> res;
    for(int index = 0;index < intervals.size(); index++){
        left = intervals[index][0];
        right = intervals[index][1];
        if(!res.size() || left > res.back()[1]) // back()获取vector最后一个元素
            res.push_back(intervals[index]);
        else // 当前区间的左端小于res最后元素的右端，说明要合并
            res.back()[1] = max(res.back()[1], right);
    }
    return res;
}
int main(){

    return 0;
}