class Solution {

public:

    int uniquePaths(int m, int n) {

// 宣告一個 m 列 n 行的二維 vector，並且把「所有」元素直接初始化為 1

    vector<int> dp(n, 1);



// 這樣你就可以直接從 i=1, j=1 開始跑雙層迴圈了，程式碼瞬間變超短！

    for(int i = 0; i < m-1; i++) {

        for(int j = 1; j < n; j++) {

            dp[j] = dp[j]+dp[j-1];

        }

    }

    return dp[n-1];

    }

};