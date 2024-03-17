#include <bits/stdc++.h>
using namespace std;

vector<string> v;

bool cmp(string s1,string s2) {
    if (s1.length() == s2.length()) {
        int sum1 = 0; int sum2 = 0;
        for (auto i : s1) {
            if (i < 65) sum1 += (i - '0');
        }
        for (auto i : s2) {
            if (i < 65) sum2 += (i - '0');
        }
        if (sum1 == sum2) {
            return s1 < s2;
        }
        else return sum1 < sum2;
    }
    else return s1.length() < s2.length();
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        cout << i << "\n";
    }
   
    return 0;
}

