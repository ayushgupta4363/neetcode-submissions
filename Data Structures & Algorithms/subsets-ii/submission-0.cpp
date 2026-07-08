class Solution {
public:
    void backtrack(vector<int>& nums,int start,vector<int>&ans,vector<vector<int>>&res){
      
    
       res.push_back(ans);
       
       for(int i=start;i<nums.size();i++){

        if(i>start && nums[i]==nums[i-1]){continue ;}

        ans.push_back(nums[i]);
        backtrack(nums,i+1,ans,res);
        ans.pop_back();
       }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,ans,res);
        return res;
    }
};
