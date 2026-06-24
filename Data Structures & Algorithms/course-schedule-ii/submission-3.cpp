class Solution {
public:

    void dfs(int node ,vector<vector<int>>& adj,vector<int>&indegree,vector<int>&ans){
        ans.push_back(node);
        indegree[node]--;
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0){
                dfs(i,adj,indegree,ans);
            }
        }
         
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);

      for(auto pre : prerequisites){
        indegree[pre[0]]++;
        adj[pre[1]].push_back(pre[0]);
      }
      
      vector<int>ans;
      for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
           dfs(i,adj,indegree,ans);
        }
      }
      
    if(ans.size()==n){return ans;}
      else{return {};}
      
      


    }
};
