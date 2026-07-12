class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(m==0){ nums1 =nums2 ;}
        int l=0;
        while(l<m){
            l++;
        }
        int s=0;
        while(n>0){
        nums1[l++]=nums2[s++];
        n--;
        }
        sort(nums1.begin(),nums1.end());
    }
};