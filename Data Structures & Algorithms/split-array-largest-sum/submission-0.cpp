class Solution {
public:
    bool cansplit(vector<int>& nums, int k,int& maxsum){
            int currsum=0;
            int subarr=1;
            for(int num:nums){
                currsum +=num;
                if(currsum >maxsum){
                    subarr++;
                    currsum = num;
                    if(subarr>k){
                        return false;
                    }
                }
            } 
            return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;
        for(int num:nums){
            r+=num;
            l=max(l,num);
    }   
    int res = r;
    while(l<=r){
        int mid=l+(r-l)/2;
    if (cansplit(nums,k,mid)){
        res=mid;
        r=mid-1;
       }
       else{
       l=mid+1;
       }
    }
        return res ; 
    }
};