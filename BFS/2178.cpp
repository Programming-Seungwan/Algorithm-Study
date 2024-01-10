#include <iostream>
#include <queue>
using namespace std;

int map[101][101]; //지도 
int visited[501][501]; //방문했는지 체크 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, m;

bool cmp(int a, int b) {
	return a > b;
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	visited[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			//지도를 벗어난 경우 
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
			//길이 있고 방문하지 않은 경우 
			if ((visited[next_x][next_y] == 0) && (map[next_x][next_y] == 1)) {
				q.push({ next_x,next_y });
				visited[next_x][next_y] = visited[x][y]+1;

			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		for (int j = 0; j < m; j++) {
			map[i][j] = str[j]-'0'; //char를 int로 변환 
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
      //길이 있고 방문하지 않은 경우 
			if ((visited[i][j] == 0) && (map[i][j] == 1)) {
				BFS(i, j);
			}
		}
	}

	cout << visited[n - 1][m - 1];

	return 0;
	
}
