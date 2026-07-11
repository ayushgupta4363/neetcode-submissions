class Solution {
public:
    bool backtrack(vector<int>& nums,int index,vector<int>& ans,int target){

        if(index==nums.size()){return true;}  
         
    for(int i=0;i<ans.size();i++){
          
        if(ans[i]+nums[index] <= target){
            ans[i] += nums[index];
          
        if(backtrack(nums,index+1,ans,target)){
            return true;
          }
           ans[i] -= nums[index];
          }
          if (ans[i] == 0) {
                break;
            }

         }

       return false ;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
      int n=nums.size();
      int sum=0;
      for(int num:nums){sum+=num;}
      if(sum%k != 0){return false ;}
      int target=sum/k;
      sort(nums.rbegin(),nums.rend());
      if(nums[0]>target){return false;}
      vector<int>ans(k,0);

      return backtrack(nums,0,ans,target);
    }

};