class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
          int n=arr.size();
          int diff ;
        vector<pair<int,int>>newarr;
         for(int i=0;i<n;i++){
            diff = abs(arr[i]-x);
            newarr.push_back({diff,arr[i]});
         }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        
        for(auto num : newarr){
            minheap.push(num);
        }
        vector<int>ans;
        while(k--){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};