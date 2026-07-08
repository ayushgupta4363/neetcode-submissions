class Solution {
public:
    void backtrack(vector<int>& nums,vector<bool>&visited,vector<int>&ans,vector<vector<int>>&res){
      
      if(ans.size()==nums.size()){
            res.push_back(ans);
            return ;
        }
      for(int i=0;i<nums.size();i++){

        if(visited[i]){continue;}
        visited[i]=true;
        ans.push_back(nums[i]);

        backtrack(nums,visited,ans,res);

        visited[i]=false;
        ans.pop_back();

      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int n=nums.size();
        vector<bool>visited(n);
        backtrack(nums,visited,ans,res);
        return res;
    }
};
