class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int row,int col){
         
        if(r<0 || c<0 || r>=row || c>=col||
         grid[r][c]=='0'||grid[r][c]=='2'){
            return;
            }
    
        grid[r][c]='2';

        dfs(grid,r,c+1,row,col);
        dfs(grid,r-1,c,row,col);
        dfs(grid,r+1,c,row,col);
        dfs(grid,r,c-1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){return 0;}
        int row= grid.size();
        int col= grid[0].size();
        int ans=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    ans++;
                    dfs(grid,r,c,row,col);
                }
            }
        }
        return ans ;
    }
};
