class Solution {
public:
   void swap(int &a,int &b){
            int temp=a;
            a=b;
            b=temp;
         }
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

       for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
       }
       for(int i=0;i<m;i++){
        reverse(matrix[i].begin(),matrix[i].end());
       }

    }
};
