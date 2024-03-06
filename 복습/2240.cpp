#include <bits/stdc++.h>
using namespace std;

int t, w; // 자두의 수 t와 나무의 최대 움직임 횟수 w를 저장하는 변수 선언
int arr[1001]; // 자두가 떨어진 나무의 번호를 저장하는 배열
int dp[1001][31][3]; // 동적 계획법을 위한 배열, dp[i][j][k]는 i번째 시간에 j번 움직이고 k번째 나무 아래에서의 최대 자두 수

int main() {

    ios_base::sync_with_stdio(false); // C++의 입출력 버퍼를 비활성화하여 실행 속도를 높임
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> w; // 자두의 수와 나무의 최대 움직임 횟수를 입력 받음

    for (int i = 1; i <= t; i++) cin >> arr[i]; // 각 시간에 자두가 떨어지는 나무의 번호를 입력 받음

    // 초기값 설정
    dp[1][0][1] = (arr[1] == 1 ? 1 : 0); // 첫 번째 시간에 첫 번째 나무 아래에서 자두를 받을 수 있는 경우
    dp[1][1][2] = (arr[1] == 2 ? 1 : 0); // 첫 번째 시간에 두 번째 나무 아래에서 자두를 받을 수 있는 경우

    // 동적 계획법을 이용하여 최대 자두 수 계산
    for (int i = 2; i <= t; i++) {
        for (int j = 0; j <= w; j++) {
            if(j==0) dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == 1 ? 1 : 0); // 움직임이 0인 경우, 첫 번째 나무에서 받을 수 있는 자두 수
            else {
                // 움직임이 1 이상인 경우, 이전 시간의 결과를 이용하여 현재 시간에 최대 자두 수 계산
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (arr[i] == 1? 1 : 0); // 첫 번째 나무에서 자두를 받는 경우
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + (arr[i] == 2? 1 : 0); // 두 번째 나무에서 자두를 받는 경우
            }
        }
    }

    int mx = 0;
    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= 2; j++) {
            if (mx < dp[t][i][j]) mx = dp[t][i][j]; // 최종 결과 중 최대값을 찾음
        }
    }
    cout << mx; // 최대 자두 수 출력

    return 0;
}
