class Solution {
public:
    bool dfs(int node,int parent,vector<int>&visited,vector<vector<int>>&adj){
        visited[node]=1;

        for(auto i:adj[node]){
          if(!visited[i]){
           if(dfs(i,node,visited,adj)){
            return true;
           }
          }
          else if(visited[i] && i!=parent){
            return true;
          }
        }  
        return false;   
        
    }
    bool validTree(int n, vector<vector<int>>& edges) {

       vector<vector<int>>adj(n);
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<int>visited(n,0);
       
    if(dfs(0,-1,visited,adj)){
               return false;
           }
        for(int i=0;i<n;i++){
            if(!visited[i])return false;
        }   
         return true; 
    }
};
