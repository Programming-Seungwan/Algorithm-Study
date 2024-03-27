#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int sticker[101][11][11];
int mapArr[41][41];

//주어진 스티커를 노트북에 붙일 수 있는 위치를 찾고, 그 위치에 스티커를 붙인다.
//스티커가 붙여질 수 있는 위치가 없으면 `false`를 반환.
bool locate(int z, int r, int c) {
    for (int i = 0; i <= n-r; i++) {
        for (int j = 0; j <= m-c; j++) {
            bool fit = true;

            // 현재 위치에서 스티커가 노트북에 들어갈 수 있는지 확인
            for (int r1 = i; r1 < i + r; r1++) {
                for (int c1 = j; c1 < j + c; c1++) {
                    // 노트북과 스티커 둘 다 해당 위치에 채워져 있다면 스티커를 붙일 수 없다.
                    if (mapArr[r1][c1] == 1 && sticker[z][r1 - i][c1 - j] == 1) {
                        fit = false;
                        break;
                    }
                }
                if (!fit) break;
            }

            // 스티커를 붙일 수 있다면 노트북에 스티커를 붙인다.
            if (fit) {
                for (int r1 = i; r1 < i + r; r1++) {
                    for (int c1 = j; c1 < j + c; c1++) {
                        if(sticker[z][r1 - i][c1 - j] == 1) mapArr[r1][c1] = sticker[z][r1 - i][c1 - j];
                    }
                }

                return true;
            }
        }
    }

    // 모든 위치에 스티커를 붙일 수 없다면 false를 반환
    return false;
}


//스티커를 90도 회전
//회전된 스티커의 새로운 크기를 반환
pair<int,int> rotate(int z, int r, int c) {
    int rotsticker[11][11];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rotsticker[j][r-i-1] =  sticker[z][i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[z][i][j] = rotsticker[i][j];
        }
    }

    pair<int, int> p = { c,r };
    return p;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int z = 0; z < k; z++){
        int r, c;
        cin >> r >> c;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[z][i][j];
            }
        }

        int a = r; int b = c; // 현재 스티커의 크기
        for (int i = 0; i < 4; i++) {  // 최대 4번 회전시키며 시도
            bool fit = locate(z, a, b); // 스티커를 붙일 수 있는지 확인
            if (fit) break; // 붙일 수 있다면 반복 중단

            // 스티커를 회전시키고, 크기 정보 업데이트
            pair<int,int> s = rotate(z, a, b);
            a = s.first;
            b = s.second;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mapArr[i][j] == 1) ans++;
        }
    }
    
    cout << ans;

    return 0;
}

