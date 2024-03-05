#include <iostream>
#include <vector>
using namespace std;
bool isValidPosition(const vector<vector<char>> grid, const int x, const int y) // 判断位置是否合法
{
    if (x >= grid.size() || y >= grid[0].size() || x < 0 || y < 0)
        return false;
    else
        return true;
}
void dfs(vector<vector<char>> &grid, int x, int y)
{
    if (!isValidPosition(grid, x, y))
    {
        cerr << "坐标不合法" << endl;
        return;
    }

    if (grid[x][y] != '1') // 该点为海域或已访问过，直接返回
        return;
    else
        grid[x][y] = '2'; // 将该点标记为已访问

    // 访问该点相邻点
    dfs(grid, x - 1, y);
    dfs(grid, x + 1, y);
    dfs(grid, x, y - 1);
    dfs(grid, x, y + 1);
}
int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0;
    for (int x = 0; x < grid.size(); x++)
    {
        for (int y = 0; y < grid[x].size(); y++)
        {
            if (grid[x][y] == '1')
            {
                dfs(grid, x, y);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    return 0;
}