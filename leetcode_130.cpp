#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<vector<char>> &board, int x, int y)
{
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != '0')
        return;
    board[x][y] = 'A';
    DFS(board, x - 1, y);
    DFS(board, x + 1, y);
    DFS(board, x, y - 1);
    DFS(board, x, y + 1);
}
/*
注意到题目解释中提到：任何边界上的 O 都不会被填充为 X。
我们可以想到，所有的不被包围的 O 都直接或间接与边界上的 O 相连。
我们可以利用这个性质判断O是否在边界上
*/
void solve(vector<vector<char>> &board)
{
    if (board.size() == 0)
        return;
    for (int i = 0; i < board.size(); i++) // 第一列和最后一列
    {
        DFS(board, i, 0);
        DFS(board, i, board[0].size() - 1);
    }
    for (int i = 1; i < board[0].size() - 1; i++) // 第一行和最后一行
    {
        DFS(board, 0, i);
        DFS(board, board.size() - 1, i);
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'A')
                board[i][j] = '0';
            else if (board[i][j] == '0')
                board[i][j] = 'X';
        }
    }
}
int main()
{
    return 0;
}