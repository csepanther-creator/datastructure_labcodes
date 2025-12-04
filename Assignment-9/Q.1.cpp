#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rnk;
    DSU(int n) {
        parent.resize(n);
        rnk.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findSet(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }
    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

void bfs(int n, const vector<vector<pair<int,int>>> &adj, int start) {
    vector<bool> vis(n, false);
    queue<int> q;
    vis[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto &p : adj[u]) {
            int v = p.first;
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfsUtil(int u, const vector<vector<pair<int,int>>> &adj, vector<bool> &vis) {
    vis[u] = true;
    cout << u << " ";
    for (auto &p : adj[u]) {
        int v = p.first;
        if (!vis[v]) dfsUtil(v, adj, vis);
    }
}

void dfs(int n, const vector<vector<pair<int,int>>> &adj, int start) {
    vector<bool> vis(n, false);
    dfsUtil(start, adj, vis);
    cout << endl;
}

void kruskalMST(int n, const vector<Edge> &edges) {
    vector<Edge> e = edges;
    sort(e.begin(), e.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });
    DSU dsu(n);
    int mstWeight = 0;
    vector<Edge> result;
    for (auto &ed : e) {
        if (dsu.unionSet(ed.u, ed.v)) {
            mstWeight += ed.w;
            result.push_back(ed);
        }
    }
    cout << "Kruskal MST weight: " << mstWeight << endl;
    cout << "Kruskal MST edges:" << endl;
    for (auto &ed : result) {
        cout << ed.u << " - " << ed.v << " (" << ed.w << ")" << endl;
    }
}

void primMST(int n, const vector<vector<pair<int,int>>> &adj, int start) {
    vector<int> key(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    int mstWeight = 0;
    for (int i = 0; i < n; i++) {
        if (key[i] != numeric_limits<int>::max()) mstWeight += key[i];
    }
    cout << "Prim MST weight: " << mstWeight << endl;
    cout << "Prim MST edges:" << endl;
    for (int v = 0; v < n; v++) {
        if (parent[v] != -1) {
            cout << parent[v] << " - " << v << " (" << key[v] << ")" << endl;
        }
    }
}

void dijkstra(int n, const vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != dist[u]) continue;
        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Dijkstra distances from " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == numeric_limits<int>::max()) cout << i << ": INF" << endl;
        else cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    int startBFS, startDFS, startPrim, srcDij;
    cin >> startBFS;
    cin >> startDFS;
    cin >> startPrim;
    cin >> srcDij;

    cout << "BFS: ";
    bfs(n, adj, startBFS);
    cout << "DFS: ";
    dfs(n, adj, startDFS);

    kruskalMST(n, edges);
    primMST(n, adj, startPrim);
    dijkstra(n, adj, srcDij);

    return 0;
}
