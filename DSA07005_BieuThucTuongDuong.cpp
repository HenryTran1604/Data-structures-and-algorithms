#include <bits/stdc++.h>
#define ft first
#define sd second
#define pii pair<int, int>
#define toint(a) a-'0'
#define all(a) a.begin(), a.end()
#define endl '\n'
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
string s;
void solve(){
	stack <char> st;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			if(s[i-1] == '+' || s[i-1] == '-') st.push(s[i-1]);
		}
		else if(s[i] == '+' || s[i] == '-'){
			if(!st.empty() && st.top() == '-'){
				if(s[i] == '+'){
					s[i] = '-';
				}
				else{
					s[i] = '+';
				}
			}
		}
		else if(s[i] == ')'){
			st.pop();
		}
	}
	for(int i = 0; i < n; i++){
		if(s[i] != '(' && s[i] != ')')	cout << s[i];
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test; cin >> test;
	while(test--)
	{
		cin >> s;
		solve();
	}
	return 0;
}

/*Code by: Tran Quang Huy*/