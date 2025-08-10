#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> visited;
vector<int> path;
vector<vector<int>> adjM;
int N = 0;

bool isSafe(int v, int idx) {
    if(adjM[idx - 1][v] == 0) return false;
    if(visited[v] == 1) return false;
    return true;
}

bool bt(int idx) {
    if(idx == N) {
        return true;
    }
    
    for (int v = 0; v < N; v++) {
        if(isSafe(v, idx)) {
            path[idx] = v;
            visited[v] = true;
            if(bt(idx + 1)) return true;
            visited[v] = false;
        }
    }
    return false;
}

int main() {
    int n = 0;
    cin >> n;
    if(n <= 1) {
        cout << 0;
        return 0;
    }
    
    N = n;
    adjM.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> adjM[i][j];
    unordered_map<int, vector<int>> adjL;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adjM[i][j] == 1) adjL[i].push_back(j);
        }
    }
    
    visited.resize(n, 0);
    path.resize(n, 0);
    
    visited[0] = 1;
    path[0] = 0;
    
    if(bt(1)) cout << path.size() - 1;
    else cout << 0;

}
