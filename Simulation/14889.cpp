#include <bits/stdc++.h>
using namespace std;

int n;
int team[21][21];
int visited[21];

int diff = 1e9;

void makeTeam(int num,int depth) {
    vector<int> startTeam;
    vector<int> linkTeam;

    if (depth == (n / 2)) {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) linkTeam.push_back(i);
            else startTeam.push_back(i);
        }

        int start = 0;
        int link = 0;
        for (int i = 0; i < (n/2); i++) {
            for (int j = 0; j < (n / 2); j++) {
                start += team[startTeam[i]][startTeam[j]];
                link += team[linkTeam[i]][linkTeam[j]];
            }
        }

        if (diff > abs(start - link)) diff = abs(start - link);

        return;
    }

    for (int i = num; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        makeTeam(i, depth + 1);
        visited[i] = 0;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> team[i][j];
        }
    }

    makeTeam(0, 0);
    cout << diff;
    return 0;
}

