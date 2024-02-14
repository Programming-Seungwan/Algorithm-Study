#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<pair<int, int>> vec;
    vec.push_back({ 0,0 });

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        vec.push_back({ a,b });
    }

    
    for (int i = 1; i <= n; i ++) {
        int next = vec[i].first + i;
        dp[i] = max(dp[i - 1], dp[i]);
        if (next <= n+1) {
            dp[next] = max(dp[next], dp[i] + vec[i].second);
        }

    }

    int answer = 0;
    for (int i = 1; i <= n+1; i++) {
        if (answer < dp[i]) answer = dp[i];
    }
    cout << answer;


    return 0;
}
