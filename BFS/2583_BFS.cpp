#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
bool visited[101][101];

int m, n, k;

//이동 배열 
int dx[4] = { 0,0,-1,1};
int dy[4] = { -1,1,0,0 };

//사각형 그리기 
void Rect(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			map[i][j] = 1;
		}
	}
}

int BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	int size = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
			if (!visited[next_x][next_y] && !map[next_x][next_y]) { //방문하지 않은 경우에 
				q.push({ next_x,next_y });
				visited[next_x][next_y] = 1;
				size++;
			}
		}
	}

	return size;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;
	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		Rect(x1, y1, x2, y2);
	}

	vector<int> v;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && !map[i][j]) {
				v.push_back(BFS(i, j));
				ans++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << ans << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	
	return 0;
	
}
