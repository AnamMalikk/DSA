class Solution {
public:
    double bfs(string src, string dest, unordered_map<string, vector<pair<string, double>>> &adj) {

        unordered_map<string, bool> visited;
        queue<pair<string, double>> q;
        q.push({src, 1.0});
        visited[src] = true;

        while(!q.empty()) {

            pair<string, double> node_info = q.front();
            q.pop();

            string node = node_info.first;
            double cost = node_info.second;

            if(node == dest) {
                return cost;
            }

            if(!adj.count(node))
                continue;

            for(pair<string, double> nbr_info: adj[node]) {
                string nbr = nbr_info.first;
                double nbr_cost = nbr_info.second;

                if(!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, (nbr_cost*cost)});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i=0; i<n; i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            adj[A].push_back({B, values[i]});
            adj[B].push_back({A, 1.0/values[i]});
        }

        vector<double> ans;
        for(vector<string> &query: queries) {
            if(!adj.count(query[0]) || !adj.count(query[1])){
                ans.push_back(-1.0);
            } else {
                double temp = bfs(query[0], query[1], adj);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};