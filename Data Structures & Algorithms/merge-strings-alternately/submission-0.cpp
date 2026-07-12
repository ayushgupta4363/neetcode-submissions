class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int l1=word1.size();
        int l2=word2.size();
        string neww ="";
        int s1=0;
        int s2=0;
        
        while(s1<l1 || s2<l2){
            if(s1<l1 && s2<l2){
            neww += word1[s1++];
            neww += word2[s2++];
            }
            else if(s1<l1){
             neww += word1[s1++];
            }
            else{
             neww += word2[s2++];
            }
        }
       return neww;
    }
};