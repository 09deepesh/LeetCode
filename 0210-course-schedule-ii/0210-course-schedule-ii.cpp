class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> order;

        for (auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && hascycle(graph, visited, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
    bool hascycle(vector<vector<int>>& graph, vector<int>& visited, int node,
                  vector<int>& order) {
        if (visited[node] == 1)
            return true;
        if (visited[node] == 2)
            return false;

        visited[node] = 1; // mark as visiting

        for (auto& x : graph[node]) {
            if (hascycle(graph, visited, x,order))
                return true;
        }
        visited[node] = 2;
        order.push_back(node);
        return false;
    }
};