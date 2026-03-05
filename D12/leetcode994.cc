class Solution {
public:
    int ans=0;
    bool check(vector<vector<int>>& grid,int r,int c){
        if( r<0 || r>=grid.size() || c<0 || c>=grid[0].size())
            return false;
        if(grid[r][c]==1){
            grid[r][c]=2;
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int round = 0;
        queue<pair<int,int>> qu;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2){
                    qu.push(make_pair(i,j));
                    round++;
                }
            }
        }
        if(qu.empty()&&fresh==0)
            return 0;
        int minutes=-1;
        
        while(!qu.empty()){
            int tmpround=0;
            minutes++;
            for(int i=0;i<round;i++){
                pair<int,int> tmppair = qu.front();
                qu.pop();
                int r=tmppair.first,c=tmppair.second;
                if(check(grid,r-1,c)){
                    qu.push(make_pair(r-1,c));
                    fresh--;
                    tmpround++;
                }
                if(check(grid,r+1,c)){
                    qu.push(make_pair(r+1,c));
                    fresh--;
                    tmpround++;
                }
                if(check(grid,r,c-1)){
                    qu.push(make_pair(r,c-1));
                    fresh--;
                    tmpround++;
                }
                if(check(grid,r,c+1)){
                    qu.push(make_pair(r,c+1));
                    fresh--;
                    tmpround++;
                }
            }
            round = tmpround;
        }

        if(fresh>0)
            return -1;
        return minutes;

    }
};