class Solution {
public:
    void backtrack(int n,int k,int start,vector<int>&ans,vector<vector<int>>&res){
        
         for(int i=start;i<=n;i++){
            ans.push_back(i);
            if(ans.size()==k){
                res.push_back(ans);
            }
            backtrack(n,k,i+1,ans,res);
            ans.pop_back();
         }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>ans;
        backtrack(n,k,1,ans,res);
        return res;
    }
};