#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[10001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    dp[0] = 1; // 아무 동전도 선택하지 않은 경우
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i]; j <= k; j++) {
            dp[j] += dp[j - v[i]];
        }
    }


    cout << dp[k];
    
   
    return 0;
}

