#include <iostream>
#include <queue>
using namespace std;

int maze[101][101];
bool visited[101][101]; //방문했는지 체크용
int dist[101][101]; //이동칸 기록용 

int dx[4] = { 1,-1,0,0 }; //상하좌우 x축 방향
int dy[4] = { 0,0,-1,1 }; //상하좌우 y축 방향
int N, M;

void BFS(int x, int y) {
	queue<pair<int, int>> q; //탐색 좌표 저장용 큐 
	visited[x][y] = true; //입력받은 시작 좌표를 방문 체크
	q.push({ x,y });
	dist[x][y] = 1; // 시작 좌표까지 이동한 칸을 1로 지정

	while (!q.empty()) { //q에 데이터가 있을 때까지 실행
		// queue 의 front 좌표를, 현재 좌표로 지정
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		// 현재 좌표와 상하좌우로 인접한 좌표 확인
		for (int i = 0; i < 4; i++) {
			int next_x = nx + dx[i];
			int next_y = ny + dy[i];

			// 인접한 좌표가, 미로 내에 존재하는지 검사
			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;

			//방문하지 않은 노드와 1인 곳을 대상으로 ...
			if ((visited[next_x][next_y] == false) && (maze[next_x][next_y] == 1)) {  
				q.push({ next_x,next_y });
				visited[next_x][next_y] = true; // 인접 좌표는 방문한 것으로 저장
				dist[next_x][next_y] = dist[nx][ny] + 1; // 인접 좌표까지 이동한 거리 저장
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력 받기 
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;

		for (int j = 0; j < M; j++) {
			maze[i][j] = (x[j]-'0');
		}
	}

	BFS(0, 0);

	
	cout << dist[N-1][M-1] << "\n";

	return 0;
	
}
