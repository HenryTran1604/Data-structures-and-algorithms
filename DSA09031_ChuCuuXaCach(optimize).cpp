#include <bits/stdc++.h>
#define pii pair<int, int>
#define endl '\n'
using namespace std;
using ll = long long;
short n, k, m; // n: kich thuoc canh dong, k: so cuu, m: vi tri rao chan
short sheep[110][3];
short dx[] = {-1, 0, 1, 0};
short dy[] = {0, 1, 0, -1};
bool used[110][110];
map <pii, set<pii>> f;

void inp()
{
	cin >> n >> k >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z, t; cin >> x >> y >> z >> t;
		f[{x, y}].insert({z, t});
		f[{z, t}].insert({x, y});
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> sheep[i][1] >> sheep[i][2];
	}
}
bool check(int prev_x, int prev_y, int new_x, int new_y)
{
	if(new_x > 0 && new_x <= n && new_y > 0 && new_y <= n)
	{
		if(f[{new_x, new_y}].find({prev_x, prev_y}) == f[{new_x, new_y}].end() && !used[new_x][new_y])
			return 1;
	}
	return 0;
}
void dfs(int x, int y)
{
	used[x][y] = 1;
//	cout << x << ' ' << y << endl;
	for(int i = 0; i < 4; i++)
	{
		int x1 = x + dx[i], y1 = y + dy[i];
		if(check(x, y, x1, y1))
			dfs(x1, y1);
	}
}
void solve()
{
	int cnt = 0;
	for(int i = 1; i <= k; i++)
	{
//		cout << sheep[i][1] <<  sheep[i][2] << endl;
		memset(used, 0, sizeof(used));
		dfs(sheep[i][1], sheep[i][2]);
		for(int j = 1; j <= k; j++)
		{
			if(!used[sheep[j][1]][sheep[j][2]]) // vi tri con cuu chua duoc tham
			{
				cnt++;
//				cout << "unvisited sheep: ";
//				cout << sheep[j][1] <<  sheep[j][2] << endl;
			}
		}
//		cout << endl;
	}
	cout << cnt/2;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; test = 1;
	while(test--)
	{
		inp();
		solve();
	}
	return 0;
}
//test:
// 4 6 5
// 4 1 4 2
// 3 2 4 2
// 3 3 4 3
// 4 3 4 4
// 3 4 4 4
// 1 1
// 2 2
// 3 4
// 4 4
// 4 2
// 4 3
/*Code by: Tran Quang Huy*/