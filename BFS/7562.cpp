#include <iostream>
#include <queue>
using namespace std;

int visited[301][301];

int l; //체스판 한 변의 길이 

//이동 배열 
int dx[8] = { -2,-1,1,2,-2,-1,2,1};
int dy[8] = { -1,-2,-2,-1,1,2,1,2 };

void Reset() { //초기화 
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visited[i][j] = 0;
		}
	}
}

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= l || next_y >= l) continue;
			if (visited[next_x][next_y] == 0) { //방문하지 않은 경우에 
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

	int T; //테스트 케이스 
	cin >> T;

	while (T--) {
		cin >> l;

		int start_x, start_y;
		cin >> start_x >> start_y;
		BFS(start_x, start_y);

		int end_x, end_y;
		cin >> end_x >> end_y;
		cout << visited[end_x][end_y]-1 << "\n";

		Reset();
	}
	
	return 0;
	
}
