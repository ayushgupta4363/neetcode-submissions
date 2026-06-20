class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c, int row,int col){

        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==2){return 0;}
        if(grid[r][c]==0){return 0;}
         grid[r][c]=2;

        return 1+dfs(grid,r,c+1,row,col)+
                dfs(grid,r,c-1,row,col)+
                dfs(grid,r+1,c,row,col)+
                dfs(grid,r-1,c,row,col);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int maxi=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    maxi=max(maxi,dfs(grid,r,c,row,col));
                }
            }
        } return maxi;
    }
};
