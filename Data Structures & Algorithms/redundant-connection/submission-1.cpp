class Solution {
public:


    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&visited){

             visited[node]=true;
             for(auto i:adj[node]){
                if(!visited[i]){
                    if(dfs(i,node,adj,visited)){
                        return true;
                    }
                    }
                    else if( visited[i] && parent!=i){
                        return true;
                }

             }
             return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
       
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool>visited(n+1,0);
            if(dfs(u,-1,adj,visited)){
                 return {u,v};
            }
        }
        return {};
        
        
    }
};
