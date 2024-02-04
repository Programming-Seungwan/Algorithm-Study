#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int visited[101];
vector<vector<int>> v;

void reset() { //초기화 
	for (int i = 0; i < 101; i++) {
		visited[i] = 0;
	}
}

int HowMany(int node) { 
	int total = 0;
	for (int i = 1; i < n+1; i++) {
		if (node == i) continue;
		total += (visited[i]-1);
	}
	return total;
}

int bfs(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (!visited[v[x][i]]) {
				visited[v[x][i]] = visited[x] + 1; //단계 저장 
				q.push(v[x][i]);
			}
		}
	}

	return HowMany(start);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	v.resize(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}


	int ans = 1e9;
	int node = 0;
	for (int i = 1; i < n + 1; i++) {
		if (ans > bfs(i)) {
			ans = bfs(i);
			node = i;
		}
		reset();
	}

	cout << node << endl;
    
    return 0;
	
}

