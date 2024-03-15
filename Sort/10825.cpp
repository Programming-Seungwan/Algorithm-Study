#include <bits/stdc++.h>
using namespace std;

vector<tuple<string, int, int, int>> v;

bool cmp(tuple<string,int,int,int> &t1, tuple<string,int,int,int> &t2) {
    if (get<1>(t1) == get<1>(t2)) {
        if (get<2>(t1) == get<2>(t2)) {
            if(get<3>(t1) == get<3>(t2)) return get<0>(t1) < get<0>(t2);
            else return get<3>(t1) > get<3>(t2);
        }
        else return get<2>(t1) < get<2>(t2);
    }
    else return get<1>(t1) > get<1>(t2);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;

        v.push_back(make_tuple(name,kor,eng,math ));
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        cout << get<0>(i) << "\n";
    }
    
   
    return 0;
}

