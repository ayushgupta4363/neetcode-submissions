class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        int currnum =0;
        for(auto trip:trips){
            int num= trip[0];
            int from= trip[1];
            int to= trip[2];

            while(!minheap.empty() && minheap.top().first<=from){
                currnum -= minheap.top().second ;
                 minheap.pop();
            }

            currnum += num;

            if(currnum>capacity){
                return false ;}

            minheap.emplace(to,num);
        }
        return true ;
    }
};