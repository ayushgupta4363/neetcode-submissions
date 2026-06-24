class Solution {
public:

    // void dfs(int node ,vector<vector<int>>& adj,vector<int>& indegree,stack<int>&s){
        
    //     for(auto i:adj[node]){
    //         indegree[i]--;
    //         if(indegree[i]==0){
    //             dfs(i,adj,indegree,s);
    //         }
    //     }
    //     s.push(node);
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
      vector<int>indegree(n,0);
      vector<vector<int>>adj(n);
      for(auto pre : prerequisites){
        indegree[pre[0]]++;
        adj[pre[1]].push_back(pre[0]);
      }
      queue<int>q;
      for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      
      vector<int>ans;
      while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        } 
      }
    
    if(ans.size()==n)return ans;
    else{
        return {};
    }


      
      


    }
};
