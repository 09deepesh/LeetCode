class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph,
               string start, string end, 
               unordered_set<string>& visited) {
        if (graph.find(start) == graph.end()) return -1.0;
        if (start == end) return 1.0;

        visited.insert(start);

        for (auto& [neighbor, weight] : graph[start]) {
            if (visited.count(neighbor)) continue;
            double result = dfs(graph, neighbor, end, visited);
            if (result != -1.0) {
                return result * weight;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        // Build graph
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        // Answer queries
        vector<double> results;
        for (auto& q : queries) {
            string src = q[0], dest = q[1];
            unordered_set<string> visited;
            double res = dfs(graph, src, dest, visited);
            results.push_back(res);
        }

        return results;
    }
};
