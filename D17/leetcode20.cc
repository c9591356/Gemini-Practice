class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        // 善用 C++ 的 range-based for loop，程式碼更易讀
        for (char c : s) {
            // 看到左邊，就預先推入對應的右邊
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                // 如果遇到右括號，且 Stack 是空的 (沒有對應的左邊)
                // 或者這個右括號跟我們「期待」的 st.top() 不一樣 -> 報錯！
                if (st.empty() || st.top() != c) {
                    return false;
                }
                // 成功配對，把期待值彈出
                st.pop();
            }
        }
        // 如果最後 Stack 清空了，代表所有期待都被滿足了
        return st.empty();
    }
};