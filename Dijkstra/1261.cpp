#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

int n, m;
int map[101][101];
int visited[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 0;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
	

		for (int i = 0; i < 4; i++) {
			int next_x = dx[i] + x;
			int next_y = dy[i] + y;

			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
			//벽이 없고, 벽을 더 적게 부시면서 도착 가능한 경우 
			if (!map[next_x][next_y] && visited[next_x][next_y] > visited[x][y] ) {
				visited[next_x][next_y] = visited[x][y];
				q.push({ next_x,next_y });
			}

			//벽이 있고, 벽을 더 적게 부시면서 도착 가능한 경우 
			if (map[next_x][next_y] && visited[next_x][next_y] > visited[x][y] + 1) {
				visited[next_x][next_y] = visited[x][y] + 1;
				q.push({ next_x,next_y });
			}
			
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;

		for (int j = 0; j < m; j++) {
			map[i][j] = x[j] - '0';
			visited[i][j] = INF;
		}
	}

	bfs(0, 0);

	cout << visited[n - 1][m - 1];

	return 0;

}

