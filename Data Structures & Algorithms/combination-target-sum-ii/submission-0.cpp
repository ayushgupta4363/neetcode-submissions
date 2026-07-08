class Solution {
public:
    void backtrack(vector<int>& c, int target,int start,vector<int>&ans,vector<vector<int>>&res){
      
      if(target==0){
        res.push_back(ans);
        return ;
      }
      for(int i=start;i<c.size();i++){
        if(c[i]>target){
            break;
        }
        if(i>start && c[i]==c[i-1]){continue;}
        ans.push_back(c[i]);
        backtrack(c,target-c[i],i+1,ans,res);
        ans.pop_back();
      }  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ans;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates,target,0,ans,res);
        return res;
    }
};
