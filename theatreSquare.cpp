#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n, m, a, n_cnt, m_cnt, cnt;
	cin >> n >> m >> a;
	n_cnt = n / a + (n % a == 0 ? 0 : 1);
	m_cnt = m / a + (m % a == 0 ? 0 : 1);
	cnt = n_cnt * m_cnt;
	cout << cnt << endl;
	return 0;
}
