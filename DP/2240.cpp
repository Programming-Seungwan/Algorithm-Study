#include <bits/stdc++.h>
using namespace std;

int t, w;
int arr[1001][3]; //시간, 자두 떨어지는 위치
int dp[1001][31][3]; //현재 시간, 움직임 횟수, 현재 위치 



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		int pos;
		cin >> pos;
		arr[i][pos] = 1;
	}

	dp[1][0][1] = arr[1][1];
	dp[1][1][2] = arr[1][2];

	int result = max(dp[1][0][1], dp[1][1][2]);

	for (int i = 2; i <= t; i++) {
		for (int j = 0; j <= w; j++) {
			if (j == 0) { 
				dp[i][j][1] = dp[i - 1][j][1] + arr[i][1];
			}
			else {
				//자리를 바꾸지 않았을 경우 vs 자리를 바꾼 경우 
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + arr[i][1];
				dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + arr[i][2];
			}

			result = max(result,max(dp[i][j][1], dp[i][j][2]));
		}
	}
	cout << result;

	return 0;
}
