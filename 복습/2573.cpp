#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[301][301];
bool visited[301][301];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int ans = 0;

void DFS(int x,int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (!visited[nx][ny] && map[nx][ny] > 0) {
            DFS(nx, ny);
        }
    }
}



int Melt() {
    int answer = 0;
    int n=1;
    while (n > 0) {
        n = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (map[i][j] == 0) continue;
                for (int z = 0; z < 4; z++) {
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
                    if (map[nx][ny] == 0 && map[i][j] > 0) {
                        if (map[i][j] - 1 == 0) map[i][j] = -1;
                        else map[i][j] -= 1;
                    }

                }
                visited[i][j] = false;


            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && map[i][j] > 0) {
                    ans++;
                    DFS(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == -1) map[i][j] = 0;
                if (map[i][j] > 0) n++;
            }
        }


        answer++;
       
        if (ans >= 2) {
            return  answer;
        }
        else ans = 0;

    }
    return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (mx < map[i][j]) mx = map[i][j];
        }
    }

    
    cout << Melt();


    return 0;
}

