#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, a[100], id[100]= {0}, cnt = 0;
void inp()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}
void Try(int i)
{
	for(int j = id[i-1]+1; j <= n-k+i; j++)
	{
		id[i] = j;
		if(a[id[i-1]] < a[j])
		{
			if(i == k) cnt++;
			else Try(i+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; t = 1;
	while(t--)
	{
		inp();
		Try(1);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

