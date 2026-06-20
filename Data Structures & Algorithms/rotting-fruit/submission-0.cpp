class Solution {
public: 
   
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){return 0;}
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>rotten;
        int total=0;
        int cnt=0;
        int days =0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==2){
                    rotten.push({r,c});
                }
                if(grid[r][c]!=0){
                    total++;
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

       while(!rotten.empty()){

        int k =rotten.size();
        cnt =cnt+k;
        while(k--){
        int x= rotten.front().first;
        int y=rotten.front().second;
        rotten.pop();
        
        for(int i=0;i<4;i++){
         int nx= x+dx[i];
         int ny= y+dy[i];
         if(nx<0 || ny<0 ||nx>=row || ny>=col || grid[nx][ny]!=1){
            continue;
         }
         grid[nx][ny]=2;
         rotten.push({nx,ny});
        }
    } if(!rotten.empty()){days++;
    }
        
       }
       return (total==cnt) ? days:-1;

    }
};
