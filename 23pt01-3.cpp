#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m = 0;
    int n = 0;
    cin >> m;
    cin >> n;
    vector<pair<int, pair<int, int>>> iVect;
    unordered_set<int> nset;
    for(int i = 0; i < n; i++) {
        int u = 0;
        int v = 0;
        int w = 0;
        cin >> u;
        cin >> v;
        cin >> w;
        nset.insert(u);
        nset.insert(v);
        iVect.push_back({w, {u, v}});
    }
    if(m != nset.size()) {
        cout << 0;
        return 0;
    }
    
    nset.clear();
    sort(iVect.begin(), iVect.end());
    int minx = 0;
    for(int i = 0; i < n; i++) {
        int w = iVect[i].first;
        int u = iVect[i].second.first;
        int v = iVect[i].second.second;
        // cout << w << " " << u << " " << " " << v << endl;
        if(nset.count(u) && nset.count(v)) continue;
        nset.insert(u);
        nset.insert(v);
        minx += w;
    }
    cout << minx;
}
