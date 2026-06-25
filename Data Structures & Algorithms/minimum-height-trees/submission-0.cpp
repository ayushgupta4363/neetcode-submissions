class Solution {
public:

    int dfs(int node,int parent,vector<vector<int>>&adj){
            int hgt=0;
            for(auto i:adj[node]){
                if(i==parent){
                    continue;
                }
                hgt = max(hgt,1+dfs(i,node,adj));
            }
        return hgt;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int mini=INT_MAX;
        vector<int>measure;
        for(int i=0;i<n;i++){
           int height = dfs(i,-1,adj);
           measure.push_back(height);
           
            mini=min(mini,height);

        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(measure[i]==mini){
                ans.push_back(i);
            }
        }
       return ans;
    }
};