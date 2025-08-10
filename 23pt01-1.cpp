#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    vector<vector<char>> maayavivana(m, vector<char>(n));
    int si = -1;
    int sj = -1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            maayavivana[i][j] = c;
            if(c == 'S') {
                si = i;
                sj = j;
            }
        }
    }
    
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cout << "[" << i << "][" << j << "]: " << maayavivana[i][j] << endl;    
    //     }
    // }
    
    if(si == -1) {
        cout << "False";
        return 0;
    }
    
    queue<pair<int, int>> q;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    // cout << "Start: " << si << " " << sj << endl;
    q.push({si, sj});
    visited[si][sj] = 1;
    int flag = 0;
    int ix = 0;
    while(!q.empty()) {
        auto f = q.front();
        int fi = f.first;
        int fj = f.second;
        // cout << "Iteration " << ix++ << ": [" << fi << "][" << fj << "]: " << maayavivana[fi][fj] << endl;
        q.pop();
        if(fi != 0 && visited[fi - 1][fj] == 0) {
            visited[fi - 1][fj] = 1;
            if(maayavivana[fi - 1][fj] == 'P') q.push({fi - 1, fj});
            if(maayavivana[fi - 1][fj] == 'E') {
                flag = 1;
                break;
            }
        }
        if(fi != m - 1 && visited[fi + 1][fj] == 0) {
            visited[fi + 1][fj] = 1;
            if(maayavivana[fi + 1][fj] == 'P') q.push({fi + 1, fj});
            if(maayavivana[fi + 1][fj] == 'E') {
                flag = 1;
                break;
            }
        }
        if(fj != 0 && visited[fi][fj - 1] == 0) {
            visited[fi][fj - 1] = 1;
            if(maayavivana[fi][fj - 1] == 'P') q.push({fi, fj - 1});
            if(maayavivana[fi][fj - 1] == 'E') {
                flag = 1;
                break;
            }
        }
        if(fj != n - 1 && visited[fi][fj + 1] == 0) {
            visited[fi][fj + 1] = 1;
            if(maayavivana[fi][fj + 1] == 'P') q.push({fi, fj + 1});
            if(maayavivana[fi][fj + 1] == 'E') {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1) cout << "True";
    else cout << "False";
}
