#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int map[1001][1001];
int visited[1001][1001];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int t, w, h;

vector<tuple<int, int, bool>> v; //x좌표, y좌표, 불 여부 

//초기화 
void reset() {
	v.clear();

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			visited[i][j] = 0;
		}
	}
}

//불이 상근이 보다 먼저 오도록 정렬 
bool cmp(tuple<int, int, bool> t1, tuple<int, int, bool> t2) {
	return get<2>(t2) < get<2>(t1);
}


int bfs() {

	queue<tuple<int, int,bool>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push({ get<0>(v[i]), get<1>(v[i]) ,get<2>(v[i]) });

		if(get<2>(v[i]) == 1) visited[get<0>(v[i])][get<1>(v[i])] = -1; //fire 
		else visited[get<0>(v[i])][get<1>(v[i])] = 1; //상근이 
	}
	
	
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();

		if ((x == 0 || y == 0 || x >= h-1 || y >= w-1) && z == 0) { //탈출 
			return visited[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w) continue;

			//fire 
			if (!visited[next_x][next_y] && map[next_x][next_y] != -2 && z == 1) {
				q.push({ next_x,next_y,z });
				map[next_x][next_y] = -1;
				visited[next_x][next_y] = -1;
			}
			
			//상근이 
			if (!map[next_x][next_y] && !visited[next_x][next_y] && z== 0) {
				q.push({ next_x,next_y,z });
				visited[next_x][next_y] = visited[x][y] + 1;
			}
		}
	}

	return -1;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;

				if (c == '#') map[i][j] = -2; //벽 
				else if (c == '.') map[i][j] = 0;
				else if (c == '@') { //상근이 
					map[i][j] = 1; 
					v.push_back({ i,j,0 });
				}
				else { //불 
					map[i][j] = -1; 
					v.push_back({ i,j,1 });
				}
			}
		}


		sort(v.begin(), v.end(), cmp);

		int ans = bfs();

		if (ans == -1) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << ans << endl;
		}

		reset();

	}
	

	return 0;

}
