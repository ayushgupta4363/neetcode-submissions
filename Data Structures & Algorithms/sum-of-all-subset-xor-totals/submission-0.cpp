class Solution {
public:
    int dfs(vector<int>& nums,int index,int curr_xor){
     
     if(index == nums.size()){return curr_xor;}

     int incl = dfs(nums,index+1,curr_xor ^ nums[index] );
     int excl= dfs(nums,index+1,curr_xor);
      
      return incl + excl ;  }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums,0,0);
    }
};