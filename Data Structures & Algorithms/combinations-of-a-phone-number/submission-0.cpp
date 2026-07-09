class Solution {
public:
    vector<string>pad ={
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"  
};

void backtrack(string digits,int index, string& ans, vector<string>&res){
    
    if(index==digits.length()){
        res.push_back(ans);
        return ;
    }
    int digitnumber = digits[index]-'0';
    string letter =pad[digitnumber];

    for(char c:letter){
        ans.push_back(c);
        backtrack(digits,index+1,ans,res);
        ans.pop_back();
    }

}

 vector<string> letterCombinations(string digits) {

    vector<string>res;
    if(digits.empty()){return res;}
    string ans ="";
    backtrack(digits,0,ans,res);
    return res;

    }

};
