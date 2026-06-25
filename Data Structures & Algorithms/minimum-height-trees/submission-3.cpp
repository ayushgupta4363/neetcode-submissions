class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){return {0};}
        vector<vector<int>>adj(n+1);
        vector<int>degree(n);
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int>q;
       for(int i=0;i<n;i++){
        if(degree[i]==1){
            q.push(i);
        }
       }

       int remnodes=n;
       while(remnodes>2){
        int leafcnt=q.size();
        remnodes -= leafcnt;

        for(int i=0;i<leafcnt;i++){
            int leaf=q.front();
            q.pop();
            for(auto i:adj[leaf]){
                degree[i]--;
                if(degree[i]==1){
                    q.push(i);
                }
            }
        }
       }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
       return res;
    }
};