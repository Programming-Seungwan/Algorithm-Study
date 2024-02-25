#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int sum_arr[10001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i < N+1; i++) {
        cin >> arr[i];
    }
    
    sum_arr[1] = arr[1];
    sum_arr[2] = arr[1] + arr[2];
    
    for (int i = 3; i < N + 1; i++) {
        sum_arr[i] = max(sum_arr[i - 3] + arr[i-1], sum_arr[i-2]) + arr[i];
        sum_arr[i] = max(sum_arr[i], sum_arr[i - 1]);
    }

    int m = *max_element(sum_arr, sum_arr + 10001);
    cout << m << "\n";

    return 0;
}

