class Solution {
public:
    
    bool ispalindrome(string s,int l,int r){
            while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
           l++;
           r--;
            }
            return true;
    }


    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;

         while(l<r){
            if(s[l]!=s[r]){
              return ispalindrome(s,l,r-1) || ispalindrome(s,l+1,r);
            }

            l++;
            r--;
         }
    return true;
    }
};