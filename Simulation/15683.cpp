#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int,int> mapArr[9][9];
vector<pair<int, int>> cctvPos;

//right, down, left, up
int cctv[6][4] = { {0,0,0,0}, {0,0,1,0}, {1,0,1,0}, {1,0,0,1}, {1,0,1,1},{1,1,1,1} };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int answer = 1e9;

// 사각 지대(0)의 개수를 세는 함수
int cntZero() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapArr[i][j].first == 0) cnt++;
        }
    }
    return cnt;
}

// CCTV 방향 설정 및 사각 지대 계산 함수
void checkDir(int index) {
    if (cctvPos.size() <= index) {
        int cnt = cntZero();
        if (answer > cnt) {
            answer = cnt;
        }
        return;
    }
    int x = cctvPos[index].first;
    int y = cctvPos[index].second;

    int cctvNum = mapArr[x][y].first;
    
    int arr[4] = { cctv[cctvNum][0], cctv[cctvNum][1], cctv[cctvNum][2], cctv[cctvNum][3] };

    // 각 방향에 대해 CCTV 감시 영역 계산
    for (int i = 0; i < 4; i++) {
        if (i == 1 && cctvNum == 5) break; // 5번 CCTV는 회전 없이 모든 방향 감시 가능
        int n0 = arr[0];
        int n1 = arr[1];
        int n2 = arr[2];
        int n3 = arr[3];

        // CCTV 방향 90도로 회전
        arr[0] = n3;
        arr[1] = n0;
        arr[2] = n1;
        arr[3] = n2;

        for (int j = 0; j < 4; j++) {
            if (arr[j] == 1) {
                int next_x = x;
                int next_y = y;
                while (true) {
                    next_x += dx[j];
                    next_y += dy[j];

                    // 범위를 벗어나거나 벽을 만나면 중단
                    if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) break;
                    if (mapArr[next_x][next_y].first == 6 ) {
                        break;
                    }

                    if (mapArr[next_x][next_y].first == -1) {
                        mapArr[next_x][next_y].second++;
                    }
                    else if (mapArr[next_x][next_y].first == 0) {
                        mapArr[next_x][next_y].first = -1;
                        mapArr[next_x][next_y].second++;
                    }
                }
            }
        }

        // 다음 CCTV로 이동
        checkDir(index + 1);

        // 이전 상태로 복구 (백트래킹)
        for (int j = 0; j < 4; j++) {
            if (arr[j] == 1) {
                int next_x = x;
                int next_y = y;
                while (true) {
                    next_x += dx[j];
                    next_y += dy[j];

                    if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) break;
                    if (mapArr[next_x][next_y].first == 6) {
                        break;
                    }

                    if (mapArr[next_x][next_y].first == -1) {
                        if(--mapArr[next_x][next_y].second == 0) mapArr[next_x][next_y].first = 0;
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

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapArr[i][j].first;
            // CCTV 위치 저장 (벽이 아닌 CCTV일 경우)
            if (mapArr[i][j].first != 0 && mapArr[i][j].first != 6) cctvPos.push_back({ i,j });
        }
    }
    
    checkDir(0);

    cout << answer;


    return 0;
}

