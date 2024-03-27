#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,w,l;
vector<int> v;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    //priority_queue<int> q;
    queue<int> q;
    for (int i = 0; i < w; i++) {
        q.push(0);
    }


    int ans = 0;
    int index = 0;
    while (!q.empty()) {
        q.pop();

        int sum = 0;
        for (int i = 0; i < q.size(); i++) {
            int num = q.front();
            sum += num;
            q.pop();

            q.push(num);
        }

        if (index < n) {
            if (sum + v[index] <= l) {
                q.push(v[index]);
                index++;
            }
            else {
                q.push(0);
            }
        }

        ans++;
    }

    cout << ans;

    return 0;
}
