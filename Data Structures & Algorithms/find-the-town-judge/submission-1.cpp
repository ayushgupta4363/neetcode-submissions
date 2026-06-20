class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);

        for(vector<int>& pair:trust){
            int u=pair[0];
            int v=pair[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=1;i<=n;i++){
            if(adj[i].size() == 0 && indegree[i]==n-1){
                return i;
            }
        } 
        return -1;
    }
};