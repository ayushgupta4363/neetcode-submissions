class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int>count(26,0);
        int l=0;
        int maxi =0;
        int max_frq=0;
        for(int r=0;r<s.size();r++){
            count[s[r]-'A']++;

            max_frq =max(max_frq,count[s[r]-'A']);

            while((r-l+1)-max_frq >k){
                count[s[l]-'A']--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }  return maxi ;
    }
};
