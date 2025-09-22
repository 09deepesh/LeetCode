class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses, 0);

        for (auto& x : prerequisites) {
            graph[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && hascycle(graph, visited, i)) {
                return false;
            }
        }
        return true;
    }

    bool hascycle(vector<vector<int>>& graph, vector<int>& visited, int node) {
        if (visited[node] == 1)
            return true;
        if (visited[node] == 2)
            return false;

        visited[node] = 1; // mark as visiting

        for (auto& x : graph[node]) {
            if (hascycle(graph, visited, x))
                return true;
        }
        visited[node] = 2;
        return false;
    }
};