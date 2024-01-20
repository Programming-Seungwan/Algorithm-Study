#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<char>> map; 
queue <pair<int,int>> q;
bool visited[100][100];

int cnt,Gcnt;

void bfs(int x, int y);

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N ;

	map.resize(N);

	char a;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			map[i].push_back(a);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				Gcnt++;
			}
		}
	}

	cout << cnt << " " << Gcnt;
	
	return 0;
}

void bfs(int x,int y) {

	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if ((!visited[nx][ny]) && (map[x][y] == map[nx][ny])) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}

		}
	}
}
