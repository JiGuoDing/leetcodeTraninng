#include <iostream>
using namespace std;
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    int p = 0, q = 0, r = 1;
    for (int i = 1; i <= n; i++)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}
int main()
{

    return 0;
}