#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[1001][1001];
int visited[1001][1001];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, m;
vector<pair<int, int>> v1;

bool cmp(int a, int b) {
	return a > b;
}


void bfs() {

	queue<pair<int, int>> q;
	for (int i = 0; i < v1.size(); i++) {
		q.push({ v1[i].first,v1[i].second });
		visited[v1[i].first][v1[i].second] = 1;
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
			if (!visited[next_x][next_y] && map[next_x][next_y] == 0) {
				q.push({ next_x,next_y });
				visited[next_x][next_y] = visited[x][y] + 1;
			}
		}
	}

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	bool noZero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (!map[i][j]) noZero = 1;
		}
	}

	//익지 않은 토마토가 아예 없다면 
	if (!noZero) {
		cout << "0";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				v1.push_back({ i,j });
			}
		}
	}

	bfs();
	

	//방문하지 않은 곳이 있다면 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) continue;
			if (!visited[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}

	vector<int> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == -1) continue; //토마토 없는 곳 제외 
			v.push_back(visited[i][j]);
		}
	}

	sort(v.begin(), v.end(), cmp); //내림차순으로 정렬 

	cout << v[0] - 1;

	return 0;

}
