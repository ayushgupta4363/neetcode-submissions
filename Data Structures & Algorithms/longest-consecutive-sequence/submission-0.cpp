class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
          int longstreak=0;

          for(int num :nums){
          
          if(set.find(num-1)==set.end()){
                int curr= num;
                int streak =1;
           
           while(set.find(curr+1)!=set.end()){
              curr += 1;
              streak += 1;
           }

           longstreak= max(longstreak,streak);

          }
        }
          return longstreak;

    }
};
