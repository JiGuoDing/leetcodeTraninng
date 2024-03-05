#include<iostream>
#include<vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
	int row[9][10] = {0}, column[9][10] = {0}, box[9][10] = {0};
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j] == '.')
				continue;
			int currentNumber = board[i][j] - '0';
			if(row[i][currentNumber] || column[j][currentNumber] || box[i/3 + (j/3)*3][currentNumber])
				return false;
			row[i][currentNumber] = 1;
			column[j][currentNumber] = 1;
			box[i/3 + (j/3)*3][currentNumber] = 1;
		}
	}
	return true;
}
/*
 *遍历到每个数的时候，例如boar[i][j]，我们判断其是否满足三个条件：
在第 i 个行中是否出现过
在第 j 个列中是否出现过
在第 j/3 + (i/3)*3个box中是否出现过.为什么是j/3 + (i/3)*3呢？
二维数组当作哈希表
 * */
int main(){
	return 0;
}
