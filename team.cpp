#include<bits/stdc++.h>
using namespace std;
int main(){
	int count, num = 0;
	cin >> count;
	for(int i = 0; i < count; i++){
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if(a+b+c >= 2)
			num++;
	}
	cout << num;
	return 0;
}
