class Solution {
public:
    void backtrack(vector<int>& nums,vector<bool>& visited,vector<int>& ans ,vector<vector<int>>&res){
      
       if(ans.size()==nums.size()){
        res.push_back(ans);
        return ;
       }
    for(int i=0;i<nums.size();i++){
        
        if(visited[i]||(i>0 && !visited[i-1] && nums[i]==nums[i-1])){
            continue;
        }
        
        visited[i]=true;

        ans.push_back(nums[i]);
        backtrack(nums,visited,ans,res);
        visited[i]=false;
        ans.pop_back();
       }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        vector<bool>visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtrack(nums,visited,ans,res);
        return res;
    }
};