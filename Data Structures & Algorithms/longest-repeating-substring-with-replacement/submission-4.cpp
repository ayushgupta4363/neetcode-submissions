class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int>map;
        int l=0;
        int max_frq=0;
        int maxi=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            map[c]++;
           max_frq=max(max_frq,map[c]);
           while((r-l+1)-max_frq >k){
                map[s[l]]--;
                l++;
           }
           maxi=max(maxi,r-l+1);
        }
       return maxi;
    }
};
