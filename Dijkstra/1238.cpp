#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 98765432
using namespace std;

int n, m, x;
vector<pair<int,int>> v[1001];
int map[1001];
int result;

void func(int start,int end) {
	memset(map, INF, sizeof(map));
	priority_queue<pair<int, int >, vector<pair<int, int >>, greater<pair<int, int >> > q;
	q.push({0,start});
	map[start] = 0;

	while (!q.empty()) {
		int node = q.top().second;
		int cost = q.top().first;
		q.pop();
		
		if (node == end) {
			result = map[node];
			break;
		}
	
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i].first;
	
			if (map[next] > cost + v[node][i].second) {
				map[next] = cost + v[node][i].second;
				q.push({ map[next], next });
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back({ b, t});
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		func(x, i);
		int ans1 = result;

		func(i, x);
		int ans2 = result;

		if (ans < ans1 + ans2) ans = ans1 + ans2;

	}
	cout << ans;

	return 0;

}

