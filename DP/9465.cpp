#include <bits/stdc++.h>
using namespace std;

int t,n;
int arr[2][100001];
int dp[2][100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		memset(dp, 0, sizeof(dp));

		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				int a = 0;
				if (i == 0) a = 1;

				dp[i][j] = max(dp[i][j], arr[i][j]);
				dp[i][j] = max(dp[i][j], max(dp[a][j-1],dp[a][j-2])+ arr[i][j]);
				
			}
		}

		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
		cout << ans << "\n";
	}
	

	return 0;
}
