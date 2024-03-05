#include <iostream>
#include <queue>
using namespace std;
int steppintNumbers(int N, int M, int i)
{
    int cnt = 0, lastDigit, candidate, numToPushA, numToPushB;
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        candidate = q.front();
        q.pop();

        if (candidate >= max(N, 10) && candidate <= M)
            cnt++;
        else if (candidate == 0 || candidate > M)
            continue;

        lastDigit = candidate % 10;
        numToPushA = candidate * 10 + lastDigit - 1;
        numToPushB = candidate * 10 + lastDigit + 1;

        if (lastDigit == 0)
            q.push(numToPushB);
        else if (lastDigit == 9)
            q.push(numToPushA);
        else
        {
            q.push(numToPushB);
            q.push(numToPushA);
        }
    }
    return cnt;
}

int countSteppintNumbers(int N, int M)
{
    int cnt = 0;
    for (int i = 1; i < 9; i++)
        cnt += steppintNumbers(N, M, i);
    return cnt;
}
int main()
{
    cout << countSteppintNumbers(2, 21) << endl;
    return 0;
}
/*
The idea is to use a Breadth First Search/Depth First Search traversal.

How to build the graph?
Every node in the graph represents a stepping number; there will be a directed edge from a node U to V if V can be transformed from U. (U and V are Stepping Numbers) A Stepping Number V can be transformed from U in following manner.
lastDigit refers to the last digit of U (i.e. U % 10)
An adjacent number V can be:

U*10 + lastDigit + 1 (Neighbor A)
U*10 + lastDigit – 1 (Neighbor B)

By applying above operations a new digit is appended to U, it is either lastDigit-1 or lastDigit+1, so that the new number V formed from U is also a Stepping Number.
Therefore, every Node will have at most 2 neighboring Nodes.
Edge Cases: When the last digit of U is 0 or 9

Case 1: lastDigit is 0 : In this case only digit ‘1’ can be appended.
Case 2: lastDigit is 9 : In this case only digit ‘8’ can be appended.
What will be the source/starting Node?

Every single digit number is considered as a stepping Number, so bfs traversal for every digit will give all the stepping numbers starting from that digit.
Do a bfs/dfs traversal for all the numbers from [0,9].
Note: For node 0, no need to explore neighbors during BFS traversal since it will lead to 01, 012, 010 and these will be covered by the BFS traversal starting from node 1.
*/