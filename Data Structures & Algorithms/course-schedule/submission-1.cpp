class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v =numCourses;
        vector<int> indegree(numCourses, 0);
        unordered_map<int,list<int>>adj;
        for(auto pre : prerequisites){
            indegree[pre[0]]++;
          adj[pre[1]].push_back(pre[0]);
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return finish == numCourses ;

    }
};
