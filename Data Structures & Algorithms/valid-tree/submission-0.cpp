class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // THE MATH TRICK: Check edge count first
        if (edges.size() != n - 1) {
            return false; 
        }

        // Step 1: Adjacency List banao
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Simple DFS (No parent tracking needed)
        vector<bool> visited(n, false);
        dfs(0, adj, visited);

        // Step 3: Agar koi unvisited reh gaya, toh disconnected hai
        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }

        return true; // Exactly n-1 edges aur fully connected = Valid Tree
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) { // Sirf unvisited par jao
                dfs(neighbor, adj, visited);
            }
        }
    }
};