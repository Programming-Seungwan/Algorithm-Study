#include <bits/stdc++.h>
using namespace std;

int t;

bool cmp(int x, int y) {
    return x > y;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> avec;
        vector<int> bvec;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            avec.push_back(a);
        }

        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            bvec.push_back(b);
        }

        sort(avec.begin(), avec.end(), cmp);
        sort(bvec.begin(), bvec.end(), cmp);

        int ans = 0;
        for (auto i : avec) {
            for (int j = 0; j < bvec.size(); j++) {
                if (i > bvec[j]) {
                    ans += (bvec.size() - j);
                    break;
                }
            }
        }
        cout << ans << "\n";

    }
    
    
   
    return 0;
}

