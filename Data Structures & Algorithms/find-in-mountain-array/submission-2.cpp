/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarysearch(int target, MountainArray &mountainArr,int l,int r,bool isAscending){
           
           while(l<=r){
            int mid=l+(r-l)/2;
            int midval=mountainArr.get(mid);
            if(midval==target){
                return mid;
            }
            if(isAscending){
             if(midval<target){
                l=mid+1;
             }
             else r=mid-1;
            }
            else{
                if(midval>target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
          
        }
return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
         int n=mountainArr.length();
         int l=0;
         int r=n-1;
         
         while(l<r){
            int mid=l+(r-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
             }
             else{
                r=mid;
             }
         }
         int peak = l;

         int leftres = binarysearch(target,mountainArr,0,peak,true);
         if(leftres != -1){
            return leftres;
         }
        return binarysearch(target,mountainArr,peak+1,n-1,false);
        
    }
};