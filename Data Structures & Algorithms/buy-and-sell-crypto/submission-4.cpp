class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int mini=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            mini=min(prices[i],mini);
            profit=prices[i]-mini;
            maxi=max(maxi,profit);
        }
        return maxi;
    }
};
