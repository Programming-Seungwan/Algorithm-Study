#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = arr[i];

        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
    }
    
    int ans = *max_element(dp + 1, dp + n + 1);
    cout << ans;
    
    return 0;
}
