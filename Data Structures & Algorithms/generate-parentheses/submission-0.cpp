class Solution {
public:
    void backtrack(int n,string ans,int open,int close,vector<string>&res){
       if(ans.length() == 2*n){
        res.push_back(ans);
        return ;
       }
      if(open<n){
      backtrack(n,ans+"(",open+1,close,res);}
      if(close<open){
      backtrack(n,ans+")",open,close+1,res);}
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        backtrack(n,"",0,0,res);
        return res;
    }
};
