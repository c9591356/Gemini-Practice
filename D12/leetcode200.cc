class Solution {
private:
    // 獨立的領土擴張函式 (把這座島全部炸沉)
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // 1. 終止條件：越界，或是遇到水 ('0')，直接 return
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        
        // 2. 踏上陸地了！原地沉島 (標記為已拜訪)，省下 visited 陣列的空間
        grid[r][c] = '0';
        
        // 3. 往四面八方派出探子繼續炸沉
        dfs(grid, r - 1, c); // 上
        dfs(grid, r + 1, c); // 下
        dfs(grid, r, c - 1); // 左
        dfs(grid, r, c + 1); // 右
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        // 乾淨的雙層迴圈掃描
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // 只要發現新大陸
                if (grid[i][j] == '1') {
                    ans++;             // 島嶼數 +1
                    dfs(grid, i, j);   // 呼叫轟炸機，把這整座相連的島都炸沉
                }
            }
        }
        return ans;
    }
};