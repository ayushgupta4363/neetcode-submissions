class Solution {
public:
    
    int dfs(vector<int>& coins, int amount,vector<int>&dp){

        if(amount==0){return 0;}
        if(dp[amount]!=-1){return dp[amount];}

        int mini= INT_MAX;
        for(int coin:coins){
            if(amount-coin>=0){
               int res= dfs(coins,amount-coin,dp);
            if(res!=INT_MAX){
                mini=min(1+res,mini);
            }
        }
        }
        dp[amount]=mini;
        return dp[amount];
    }
 

    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,-1);
       int ans =dfs(coins,amount,dp);
       return (ans==INT_MAX)?-1:ans;
    }
};
