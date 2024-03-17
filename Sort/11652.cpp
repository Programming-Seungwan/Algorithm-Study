#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> um; //값, 횟수

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        auto it = um.find(num);
        if (it == um.end()) um[num] = 1;
        else um[num]++;
    }

    vector<pair<long long, long long>> v(um.begin(), um.end());

    sort(v.begin(), v.end(), [](pair<long long, long long>& a, pair<long long, long long>& b)
        {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    );

    cout << v[0].first;
    
   
    return 0;
}

