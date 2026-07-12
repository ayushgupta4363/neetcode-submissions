class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
           if(j>i+1 && nums[j]==nums[j-1])continue;
             int l=j+1;
             int r=n-1;
             while(l<r){
            long long sum=(long long)nums[j]+nums[l]+nums[r];
            if(sum==target-nums[i]){
                res.push_back({nums[j],nums[i],nums[l],nums[r]});
                while(l<r && nums[l]==nums[l+1])l++;
                while(l<r && nums[r]==nums[r-1])r--;
                l++;
                r--;
            }
            else if(nums[j]+nums[l]+nums[r] < target-nums[i]){
                l++;
            }
            else{
               r--;
            }

             }

            }
        }
         return res ;
    }
};