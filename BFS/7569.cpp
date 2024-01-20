#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

queue<tuple<int, int, int>> q;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int dz[2] = { 1,-1 };

int map[101][101][101];
int visited[101][101][101];

int n, m, h;

int bfs() {
	int x = 0;
	int y = 0;
	int z = 0;
	if (q.empty()) return 0;

	while (!q.empty()) {
		z = get<0>(q.front());
		x = get<1>(q.front());
		y = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_x = x;
			int next_y = y ;
			int next_z = z;

			if (i < 4) {
				next_x += dx[i];
				next_y += dy[i];
			}
			else {
				next_z += dz[i-4];
			}

			if (next_x < 0 || next_y < 0 || next_z < 0 || next_x >= n || next_y >= m || next_z >= h) continue;
			if (!visited[next_z][next_x][next_y] && !map[next_z][next_x][next_y]) {
				visited[next_z][next_x][next_y] = visited[z][x][y] + 1;
				q.push({next_z, next_x, next_y});
			}
		}
	}
	return visited[z][x][y];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input code 
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				cin >> map[i][j][z];
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				if (map[i][j][z] == 1 && !visited[i][j][z]) { //토마토가 있는 좌표값을 미리 queue에 저장 
					q.push(make_tuple(i, j, z));
				}
			}
		}
	}

	int ans = bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0; z < m; z++) {
				if (map[i][j][z] == 0 && !visited[i][j][z]) {
					cout << "-1 ";
					return 0;
				}
			}
		}
	}

	cout << ans;
	
	return 0;
}


