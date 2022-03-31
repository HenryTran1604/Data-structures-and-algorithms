#include <bits/stdc++.h>
#define fi first
#define sec second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
#define endl '\n'
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

bool isprime(int);
int n; ll ans = 1e18;
ll pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
void Try(int i, int soUoc, ll kq){
	if(soUoc > n || kq > ans)
		return;
	if(soUoc == n){
		ans = min(ans, kq);
		return;
	}
		
	for(int j = 1; j < n; j++){
		kq *= pr[i];
		if(kq > ans) break;
		Try(i+1, soUoc*(j+1), kq);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test; test = 1;
	while(test--){
		cin >> n;
		Try(0, 1, 1);
		cout << ans;
	}
	return 0;
}
bool isprime(int n){
	if(n < 2) return 0;
	if(n < 4) return 1;
	if(n%2==0 || n%3==0) return 0;
	int tmp = sqrt(n);
	for(int i = 5; i <= tmp; i+=6){
		 if(n%i==0 || n%(i+2)==0) return 0;
	}
	return 1;
}

/*Code by: Tran Quang Huy*/