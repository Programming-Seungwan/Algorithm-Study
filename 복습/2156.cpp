#include <iostream>
#include <algorithm>

using namespace std;
#define MX 10001

int n;
int dp[MX];
int arr[MX];


int main() {


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[2], max(arr[2] + arr[3], arr[1]+arr[3]));

    
    for (int i = 4; i <= n; i++) {
        //아래의 상황 중 최대값을 찾아야 한다. 
        //1. 이번에 포도주 마시지 않은 경우
        //2. i-1번째에 포도주를 마시지 않은 경우 
        //3. 이번에 마시면 연속으로 두번 마시는 경우 
        dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
    }

    int answer = *max_element(dp, dp + n + 1);
    cout << answer;
    
    return 0;
}
