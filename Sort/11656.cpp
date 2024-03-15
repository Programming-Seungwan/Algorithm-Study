#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    v.push_back(s);

    for (int i = 0; i < s.length(); i++) {
        string str = "";
        for (int j = i + 1; j < s.length(); j++) {
            str += s[j];
        }
        if(str!="")v.push_back(str);
    }
    
    sort(v.begin(), v.end());

    for (auto i : v) {
        cout << i << "\n";
    }
   
    return 0;
}

