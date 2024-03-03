#include <bits/stdc++.h>
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
        dp[i] = 1;

        for (int j = 1; j < i; j++) {
             if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
             else if (arr[j] == arr[i]) dp[i] = dp[j];
         }
        
    }

    cout << *max_element(dp, dp + n + 1);
    
    
    return 0;
}
