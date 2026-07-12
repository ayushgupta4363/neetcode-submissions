class Solution {
public:
    int maxArea(vector<int>& heights) {
    
        int l=0;
        int r=heights.size()-1;
        long long area;
        int mini;
        long long maxi=INT_MIN;

        while(l<r){

            mini =min(heights[l],heights[r]);
            area = mini*(r-l);
            maxi = max(area,maxi);
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi ;
    }
};
