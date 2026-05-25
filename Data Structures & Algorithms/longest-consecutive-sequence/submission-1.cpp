class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set(nums.begin(),nums.end());
       int longstreak =0;
        for(int num :set){

            if(!set.contains(num-1)){
                int curr = num;
                int streak=1;
                 
                 while(set.contains(curr+1)){
                     curr +=1;
                     streak +=1;
                 }

                 longstreak=max(longstreak,streak);
            }
            

        }
        return longstreak;
    }
};
