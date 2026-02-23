class Solution {
public:
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
        if (node == destination) {
            return true;
        }
        visited.insert(node);
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for (const auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> visited;
        return dfs(source, destination, adj, visited);
    }
};