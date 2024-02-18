#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MX 1500002

int n;
pair<int,int> arr[MX];
int dp[MX];


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    //기존 코드 
    /*for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }


    for (int i = 1; i <= n; i++) {

        //일을 새롭게 시작하지 않고
        //어제 한 일을 이어서 할 수도 있기 때문에 같이 고려 
        dp[i] = max(dp[i], dp[i - 1]);

        int next = i + arr[i].first;
        if (next > n+1) continue;

        dp[next] = max(dp[next], dp[i] + arr[i].second);
    }

    int ans = *max_element(dp + 1, dp + n + 2);
    cout << ans;

    */

    //블로그 코드 
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        dp[a + b] = max(dp[a] + b, dp[a + b]);
        //오늘까지 완료한 일을 내일이 돼도 그대로 
        dp[a + 1] = max(dp[a + 1], dp[a]);
    }

    cout << dp[n+1];

    
    return 0;
}
