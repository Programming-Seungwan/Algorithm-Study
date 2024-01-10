#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int paper[501][501]; //도화지 
bool visited[501][501]; //방문했는지 체크 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, m;

bool cmp(int a, int b) {
	return a > b;
}

int BFS(int x, int y) {
	int cnt = 1;
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

			//도화지를 벗어난 경우 
			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;
			//다음 칸이 색칠되어 있고 방문하지 않은 경우 
			if ((!visited[next_x][next_y]) && (paper[next_x][next_y] == 1)) {
				q.push({ next_x,next_y });
				visited[next_x][next_y] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	vector<int> v; //그림 넓이 저장 벡터 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((!visited[i][j]) && (paper[i][j] == 1)) {
				int num = BFS(i, j);
				v.push_back(num);
			}
		}
	}

  //내림차순으로 정렬 
	sort(v.begin(), v.end(), cmp);

	if(v.empty()) cout << v.size() << "\n" << "0";
	else cout << v.size() << "\n" << v[0];

	return 0;
	
}
