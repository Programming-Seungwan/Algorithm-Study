#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

char arr[5][5];
int princess[7];
bool visited[25];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int answer = 0;


bool CheckS() { // 뽑은 7명 중에서, 이다솜파 학생이 적어도 4명 이상 있는지 확인
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		int index = princess[i];
		int row = index / 5;
		int col = index % 5;

		if (arr[row][col] == 'S') cnt++;
	}

	return cnt >= 4;
}

bool NextTo() { //그 7명이 서로 인접해 있는지
	
	int check[5][5];
	memset(check, 0, sizeof(check));

	int r = princess[0] / 5;
	int c = princess[0] % 5;

	queue<pair<int, int>> q;
	q.push({ r,c });
	check[r][c] = 1;

	int cnt = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = r + dx[i];
			int next_y = c + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= 5 || next_y >= 5) continue;
			//아직 체크한 적이 없고, 내가 뽑은 좌표라면 
			if (!check[next_x][next_y] && visited[next_x*5 + next_y] == 1) {
				check[next_x][next_y] = 1; //체크 
				q.push({ next_x,next_y });
				cnt++;
			}
		}
	}

	return cnt == 7;
}

//총 25명의 학생 중에서, 7명을 뽑기 
void Select(int index, int cnt) {

	if (cnt == 7) {
		if (CheckS() && NextTo()) {
			answer++;
		}
		return;
	}

	for (int i = index; i < 25; i++) {
		if (visited[i]) continue;
		if (cnt != 0 && princess[cnt - 1] > i) continue;

		visited[i] = 1;
		princess[cnt] = i;
		Select(i + 1, cnt + 1);
		visited[i] = 0;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	
	Select(0, 0);
	cout << answer;
    
    return 0;
	
}

