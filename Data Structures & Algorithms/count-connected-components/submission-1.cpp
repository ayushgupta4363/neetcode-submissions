class Solution {
public:
     
    int countComponents(int n, vector<vector<int>>& edges) {
      vector<vector<int>>adj(n);
      for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      vector<int>visited(n);
      queue<int>q;
      int cnt =0;
      for(int i=0;i<n;i++){
        if(!visited[i]){
          cnt++;
          q.push(i);
        }
       while(!q.empty()){
          int front=q.front();
          q.pop();
          visited[front]=1;
          for(auto i:adj[front]){
            if(!visited[i]){
                q.push(i);
            }
          }

       }

      }
    return cnt;
    }
};
