#include <bits/stdc++.h>
#define ll  long long
using namespace std;
int b[25], n, ok = 0;
void print()
{
	for(int i = 1; i <= n/2; i++)
		cout << b[i] << " ";
	for(int i = n/2; i > 0; i--)
		cout << b[i] << " ";
	cout << endl;
}
void create()
{
	print();
	int i = n/2;
	while(b[i] == 1)
	{
		b[i] = 0;
		i--;
	}
	if(i == 0) ok = 1;
	else
	{
		b[i] = 1;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while(!ok)
	{
		create();
	}
	return 0;
}



