class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int l=0;
        int boat=0;
        int r=n-1;
        while(l<=r){
        
         if(people[r]+people[l]<=limit){
            boat++;
            l++;
            r--;
         } 
         else if(people[r]+people[l]>limit){
              r--;
              boat++;
         }
         else{
                r--;
                boat++;
                }  

        }
       return boat;
    }
};