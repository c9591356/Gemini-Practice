#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
// 為什麼用 long long？因為 LeetCode 很愛考 INT_MAX 和 INT_MIN 當作節點的合法值。
// 如果區間用 int，會無法區分「初始邊界」和「真實節點的值」。
    bool validate(TreeNode* node, long long min_val, long long max_val) {
        // 1. 終止條件：走到 NULL 代表這條路徑沒問題
        if (node == NULL) return true;

        // 2. 犯規條件：如果我不在我的「合法區間」內，直接判死刑！
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // 3. 繼續往下查：
        // 左小孩：最大值被我(node)限制住了。
        // 右小孩：最小值被我(node)限制住了。
        // 兩邊都合法才是 true！
        return validate(node->right,node->val,max_val) && validate(node->left,min_val,node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        // 請在此完成實作
        // 提示：你可能需要呼叫一個自己寫的 private helper function
        return validate(root, LONG_MIN, LONG_MAX);
    }
};