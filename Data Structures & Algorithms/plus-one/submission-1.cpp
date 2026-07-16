class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long newn = 0;
        for(int num:digits){
           newn = newn*10+num;
        }  
        long long updated=newn+1;
        vector<int>ans;
        int digit;
        while(updated>0){
           digit=updated%10;
           ans.insert(ans.begin(),digit);
           updated /=10;
        }
        return ans;
   }
};
