#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_N = 400000;
const int MOD = 998244353;

ll t, n, m, u, v;
ll fact[MAX_N + 50], dist[MAX_N + 50];
vector<int> adj[MAX_N + 50];

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

void dfs1(int node, int parent) {
    dist[node] = 1e9;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs1(neighbor, node);
            dist[node] = min(dist[node], dist[neighbor] + 1);
        }
    }
    if (dist[node] > 1e8) dist[node] = 0;
}

void dfs2(int node, int parent) {
    if (node > 1) {
        fact[node] = (fact[parent] * dist[node] % MOD * mod_pow(dist[node] + 1, MOD - 2)) % MOD;
    }
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs2(neighbor, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        fill(fact, fact + n + 1, 0);
        fact[1] = 1;
        
        dfs1(1, 0);
        dfs2(1, 0);
        
        for (int i = 1; i <= n; ++i) {
            cout << fact[i] << ' ';
            adj[i].clear();
        }
        cout << '\n';
    }
    return 0;
}
