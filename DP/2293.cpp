#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long ll;

int n, m;
int arr[101];
int dp[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			if (dp[j - arr[i]]) {
				dp[j] += dp[j-arr[i]];
			}
		}
	}
	cout << dp[m];
}
