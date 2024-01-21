#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

//상하좌우로 이동하는 경우의 수 
int mx[4] = { 0,0,-1,1 };
int my[4] = { 1,-1,0,0 };

//말처럼 뛰는 범위 총 8가지 경우의 수
int hx[8] = {  -1,-2, -1,-2, 1,2, 1,2 };
int hy[8] = { -2, -1, 2, 1, 2, 1, -2, -1, };

int map[201][201];
int visited[31][201][201];

int w, h, k;

void bfs(int x,int y) {
	queue<tuple<int, int, int>> q;
	q.push({ x,y,0 });
	visited[0][x][y] = 1;

	while (!q.empty()) {
		x = get<0>(q.front()); 
		y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();


		for (int i = 0; i < 12; i++) {
			bool act = false;
			int next_x = x;
			int next_y = y ;

			if (i < 4) { //상하좌우로 이동하는 경우 
				next_x += mx[i];
				next_y += my[i];
			}
			else if(i>=4 && cnt < k) { //말처럼 뛰는 경우 
				next_x += hx[i-4];
				next_y += hy[i-4];
				act = true;
			}

			if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w ) continue;
			if (map[next_x][next_y]) continue; //지도에 장애물이 있으면 pass
			//말처럼 뛰는 경우 
			if (act == true && !visited[cnt+1][next_x][next_y]) {
				visited[cnt+1][next_x][next_y] = visited[cnt][x][y] + 1;
				q.push({next_x, next_y, cnt+1});
			}
			//상하좌우로 이동하는 경우 
			if (act == false && !visited[cnt][next_x][next_y]) {
				visited[cnt][next_x][next_y] = visited[cnt][x][y] + 1;
				q.push({ next_x, next_y, cnt });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input code 
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	bfs(0, 0);

	bool act = false;
	int ans = 99999;
	for (int i = 0; i <= k; i++) {
		if (visited[i][h - 1][w - 1] != 0) { //여러 레이어 중에서 0이 아닌 값이 하나라도 있으면 도착지점에 도착함
			act = true;
			ans = min(ans, visited[i][h - 1][w - 1]); //최솟값 
		}
	}

	if (!act) cout << "-1";
	else cout << ans-1;
	
	
	return 0;
}


