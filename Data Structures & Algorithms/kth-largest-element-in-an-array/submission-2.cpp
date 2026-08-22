class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxheap;
        for(int num:nums){
            maxheap.push(num);
        }
        int top;
        while(k--){
            top=maxheap.top();
            maxheap.pop();
        }
        return top;
    }
};
