class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        if(s.size()==0){return 0;}
        int max_length=1;
        int l=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
         if(map.contains(c)){
         l=max(l,map[c]+1);
         }
         max_length=max(max_length,r-l+1);
            map[c]=r;
        }
       return max_length;
    }
};
