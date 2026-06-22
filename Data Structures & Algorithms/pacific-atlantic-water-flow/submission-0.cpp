class Solution {
public:
    void dfs(vector<vector<int>>& heights,int r,int c,int height,vector<vector<bool>>& visited,int m,int n){
        
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || heights[r][c] < height) {
            return;
        }
        
        visited[r][c] = true;
        
        
        dfs(heights, r + 1, c, heights[r][c], visited, m, n);
        dfs(heights, r - 1, c, heights[r][c], visited, m, n);
        dfs(heights, r, c + 1, heights[r][c], visited, m, n);
        dfs(heights, r, c - 1, heights[r][c], visited, m, n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>>result;
        if(heights.empty() || heights[0].empty()){return result;}
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            dfs(heights,0,i,heights[0][i],pacific,m,n);
            dfs(heights,m-1,i,heights[m-1][i],atlantic,m,n);
        }
        for(int j=0;j<m;j++){
            dfs(heights,j,0,heights[j][0],pacific,m,n);
            dfs(heights,j,n-1,heights[j][n-1],atlantic,m,n);
        }
      for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
