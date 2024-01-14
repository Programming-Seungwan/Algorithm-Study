#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char map[31][31][31];
int visited[31][31][31];


//이동 배열 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int dz[2] = { 1,-1 };

int l, r, c;

//visited 배열 초기화 
void reset() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int z = 0; z < 31; z++) {
				visited[i][j][z] = 0;
			}
		}
	}
}

bool bfs(int z, int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push({ z,x,y });
	visited[z][x][y] = 1;

	while (!q.empty()) {
		z = get<0>(q.front());
		x = get<1>(q.front());
		y = get<2>(q.front());
		q.pop();

		if (map[z][x][y] == 'E') { //출구인 경우 
			cout << "Escaped in " << visited[z][x][y]-1 << " minute(s)." << "\n";
			return 1;
		}

		for (int i = 0; i < 6; i++) {
			int next_z = z;
			int next_x = x;
			int next_y = y;

			if (i < 4) {
				next_x += dx[i];
				next_y += dy[i];
			}
			else {
				next_z += dz[i-4];
			}

			if (next_z < 0 || next_x < 0 || next_y < 0 || next_z >= l || next_x >= r || next_y >= c) continue;
			if (visited[next_z][next_x][next_y] == 0 && map[next_z][next_x][next_y] != '#') {
				q.push({ next_z,next_x,next_y });
				visited[next_z][next_x][next_y] = visited[z][x][y] + 1;
			}
		}
	}
	return 0;
}

//bfs 함수 실행 코드 
void doBfs() {

	for (int z = 0; z < l; z++) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (map[z][i][j] == 'S') {
					if (!bfs(z, i, j)) {
						cout << "Trapped!" << "\n";
						return;
					}
				}

			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> l >> r >> c;

		if (l == 0 && r == 0 && c == 0) {
			break;
		}

		for (int z = 0; z < l; z++) {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cin >> map[z][i][j];
				}
			}
		}

		doBfs();
		reset();

	}

	return 0;

}
