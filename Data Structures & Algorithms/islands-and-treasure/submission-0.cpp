class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)return ;
        int n=grid[0].size();
        queue<pair<int,int>>q;
        const int INF = 2147483647;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0){
                q.push({r,c});
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        while(!q.empty()){
            int k=q.size();
            while(k--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<0 || ny<0 || nx>=m ||ny>=n||grid[nx][ny]!=INF){
                    continue;
                }
                 grid[nx][ny]=1+grid[x][y];
                    q.push({nx,ny});
            }


            }
        }


    }
};
