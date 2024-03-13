#include <bits/stdc++.h>
using namespace std;

int n;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    priority_queue < pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long, long long>>> pq;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        pq.push({ a,b });
    }

    long long start = pq.top().first;
    long long end = pq.top().second;
    long long answer = end - start;
    pq.pop();

    while (!pq.empty()) {
        if (pq.top().second > end) {
            if (pq.top().first <= end) { //연장되게 그릴 때
                answer += (pq.top().second - end); 
            }
            else { //새롭게 그릴 때 
                answer += (pq.top().second - pq.top().first);
                start = pq.top().first;
            }
            end = pq.top().second;
        }
        pq.pop();
    }
    cout << answer;

   
    return 0;
}

