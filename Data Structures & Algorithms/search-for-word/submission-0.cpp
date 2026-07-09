class Solution {
public:
    bool dfs(int k,int i,int j,int row,int col,vector<vector<bool>>& visited,vector<vector<char>>& board, string word){
      
    if(k==word.size()){return true;}
     
     if(i<0 || j<0 ||i>=row ||j>=col || visited[i][j]||board[i][j]!=word[k]){
        return false;
        }
     
     visited[i][j]=true;
      
     bool found =dfs(k+1,i+1,j,row,col,visited,board,word)||
     dfs(k+1,i-1,j,row,col,visited,board,word)||
     dfs(k+1,i,j+1,row,col,visited,board,word)||
     dfs(k+1,i,j-1,row,col,visited,board,word);
    
     if(found){return true;}
     
     visited[i][j]=false;
     return false;
         }
bool exist(vector<vector<char>>& board, string word) {
    int m=board.size();
    int n=board[0].size();
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0]){
                if(dfs(0,i,j,m,n,visited,board,word)){
                    return true;
                }
            }
        }
    }
      return false ;
    }
};
