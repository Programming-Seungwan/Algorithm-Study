#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N;
long long pq[1000001];
long long result;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        result = 0;
        for (int j = 0; j < N; j++) {
            cin >> pq[j];
        }

        int mx = pq[N-1];
        for (int j = N-2; j >= 0; j--) {
            if (mx < pq[j]) {
                mx = pq[j];
            }
            else {
                result += (mx - pq[j]);
            }
        }
        cout << result << "\n";
    }

    return 0;
}
