#include <iostream>
#include <vector>
using namespace std;

int map[51][51];
bool visited[51][51];

int m, n, k;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void Reset() { //초기화 
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void DFS(int x, int y) {
	visited[x][y] = 1; //방문 배열 체크 

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
		if (!visited[next_x][next_y] && map[next_x][next_y]) {
			DFS(next_x, next_y); //재귀로 dfs 구현 
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; //테스트 케이스 
	cin >> T;

	while (T--) {
		//입력 
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x; //행과 열 주의..!
			map[x][y] = 1;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j]) {
					DFS(i, j); 
					ans++; //서로 떨어져있는 배추밭 개수 체크 
				}
			}
		}
		cout << ans << "\n";
		Reset();
	}
	
	return 0;
	
}
