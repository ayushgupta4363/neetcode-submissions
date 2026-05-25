class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxi=0;
        while(left<right){
            int length=min(heights[left],heights[right]);
            int breadth=right-left ;

            if(heights[left]<heights[right]){left++;}
            else{right--;}
            maxi=max(maxi,length*breadth);
        }
        return maxi;
    }
};
