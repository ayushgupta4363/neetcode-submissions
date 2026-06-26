class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minheap;
    int maxcapacity;

    KthLargest(int k, vector<int>& nums) {
         maxcapacity=k;
        for(auto num :nums){
            minheap.push(num);
            if(minheap.size()>maxcapacity){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>maxcapacity){
            minheap.pop();
        }
        return minheap.top();
    }
};
