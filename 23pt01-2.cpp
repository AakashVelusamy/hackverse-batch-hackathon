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
        cout << "[]";
        return 0;
    }
    
    vector<pair<int, int>> path;
    queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    // cout << "Start: " << si << " " << sj << endl;
    q.push({{si, sj}, {{si, sj}}});
    visited[si][sj] = 1;
    int flag = 0;
    int ix = 0;
    while(!q.empty()) {
        auto f = q.front();
        int fi = f.first.first;
        int fj = f.first.second;
        // cout << "Iteration " << ix++ << ": [" << fi << "][" << fj << "]: " << maayavivana[fi][fj] << endl;
        q.pop();
        if(fi != 0 && visited[fi - 1][fj] == 0) {
            vector<pair<int, int>> pathv = f.second;
            pathv.push_back({fi - 1, fj});
            visited[fi - 1][fj] = 1;
            if(maayavivana[fi - 1][fj] == 'P') q.push({{fi - 1, fj}, pathv});
            if(maayavivana[fi - 1][fj] == 'E') {
                path = pathv;
                flag = 1;
                break;
            }
        }
        if(fi != m - 1 && visited[fi + 1][fj] == 0) {
            vector<pair<int, int>> pathv = f.second;
            pathv.push_back({fi + 1, fj});
            visited[fi + 1][fj] = 1;
            if(maayavivana[fi + 1][fj] == 'P') q.push({{fi + 1, fj}, pathv});
            if(maayavivana[fi + 1][fj] == 'E') {
                path = pathv;
                flag = 1;
                break;
            }
        }
        if(fj != 0 && visited[fi][fj - 1] == 0) {
            vector<pair<int, int>> pathv = f.second;
            pathv.push_back({fi, fj - 1});
            visited[fi][fj - 1] = 1;
            if(maayavivana[fi][fj - 1] == 'P') q.push({{fi, fj - 1}, pathv});
            if(maayavivana[fi][fj - 1] == 'E') {
                path = pathv;
                flag = 1;
                break;
            }
        }
        if(fj != n - 1 && visited[fi][fj + 1] == 0) {
            vector<pair<int, int>> pathv = f.second;
            pathv.push_back({fi, fj + 1});
            visited[fi][fj + 1] = 1;
            if(maayavivana[fi][fj + 1] == 'P') q.push({{fi, fj + 1}, pathv});
            if(maayavivana[fi][fj + 1] == 'E') {
                path = pathv;
                flag = 1;
                break;
            }
        }
    }
    
    string result = "";
    if(flag == 1) {
        result += '[';
        for(auto node : path) result += "[" + to_string(node.first) + ", " + to_string(node.second) + "], ";
        if(result.size() >= 2) {
            result.pop_back();
            result.pop_back();
        }
        result += ']';
    }
    else result = "[]";
    cout << result;
}
