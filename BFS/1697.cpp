#include <iostream>
#include <queue>
using namespace std;

int map[100001]; //지도 
int visited[100001]; //방문했는지 체크 

int dx[3] = { 1,-1,0 }; //이동방식 
int n, m;


void BFS(int x) {
	queue<int> q;
	visited[x] = 0;
	q.push(x);

	while (!q.empty()) {
		x = q.front();
		q.pop();

		if (x == m) { //도착지점에 온 경우 
			cout << visited[m];
			return;
		}

		for (int i = 0; i < 3; i++) {
			int next = 0;
			if (i == 2) { //2*X의 위치로 이동 
				next = 2*x;
			}
			else { //X-1 또는 X+1로 이동 
				next = x + dx[i];
			}

			//도착지점보다 더 멀리 이동했다가 다시 돌아오는 경우도 존재하기 때문에
			//최대 200000까지 고려한다 
			if (next < 0 || next > 200000) continue;
			//방문을 하지 않았거나 or 방문했는데 더 빠른 시간으로 방문했다면 
			if (visited[next] == 0 || visited[next] > visited[x] + 1) {
				q.push(next);
				visited[next] = visited[x]+1;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	BFS(n);
	
	return 0;
	
}
