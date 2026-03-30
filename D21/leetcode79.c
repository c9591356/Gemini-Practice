class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int i,int j,int str_i){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[str_i] )
            return false;
        if(str_i==word.length()-1)
            return true;
        board[i][j]='#';
        int dict[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int dir=0;dir<4;dir++){
            if(dfs(board,word,i+dict[dir][0],j+dict[dir][1],str_i+1))
                return true;
        }
        board[i][j]=word[str_i];
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0])
                    if(dfs(board,word,i,j,0))
                        return true;
            }
        }
        return false;
    }
};