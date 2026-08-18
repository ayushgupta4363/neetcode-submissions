class Solution {
public:
     bool dfs(int node,int parent,vector<bool>&visited,vector<vector<int>>& adj){
            
            visited[node]=true;

            for(auto nbr:adj[node]){

              if(visited[nbr] && parent!=nbr){
                return true;
              }
              if(!visited[nbr]){
             dfs(nbr,node,visited,adj);}
            }

            return false;
     }
    bool validTree(int n, vector<vector<int>>& edges) {
  
      vector<vector<int>>adj(n+1);
      for(auto query:edges){
        adj[query[0]].push_back(query[1]);
         adj[query[1]].push_back(query[0]);
      }
      vector<bool>visited(n,false);
     if(dfs(0,-1,visited,adj)){
      return false;
     }
     for(int i=0;i<n;i++){
     if(!visited[i])return false;
     }
     return true;
    }
};
