class Solution {
public:
    
    bool bfs(int n,int src, int target,vector<vector<int>>adj){
          queue<int>q;
          q.push(src);
          vector<bool>visited(n);
          visited[src]=1;

          while(!q.empty()){
            int front=q.front();
            q.pop();

            if(front == target){
                    return true;
                  }

            for(auto nbr:adj[front]){
                  if(!visited[nbr]){
                    visited[nbr]=1;
                    q.push(nbr);
                  }
            }
          } 
        return false;
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
       vector<int>visited(n);
       vector<bool>ans;
       for(auto q:queries){
        ans.push_back(bfs(n,q[1],q[0],adj));
       }  
       return ans;

    }
};