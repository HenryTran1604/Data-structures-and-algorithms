#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[6], id[6], sign[5], mark[6];
bool ok = 0, en;
int calc(int x, int y, int z)
{
	if(z == 1) return x+y;
	if(z == 2) return x-y;
	return x*y;
}
void check()
{
	ll res = a[id[1]];
	for(int i = 2; i <= 5; i++)
		res = calc(res, a[id[i]], sign[i-1]);
	if(res == 23)
		ok = 1;
}
void TrySign(int i) // + - *
{
	for(int j = 1; j <= 3; j++)
	{
		sign[i] = j;
		if(i == 4) check();
		else TrySign(i+1); 
	}
}
void TryNum(int i)
{
	for(int j = 1; j <= 5; j++)
	{
		if(!mark[j]){
			mark[j] = 1;
			id[i] = j;
			if(i == 5) TrySign(1);
			else TryNum(i+1);
			mark[j] = 0;
		}
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		ok = 0; en = 0;
		for(int i = 1; i <= 5; i++)
			cin >> a[i];
		TryNum(1);
		if(ok == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
/*Code by: Tran Quang Huy*/
