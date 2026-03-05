class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        // 只要 n 還有 1，就繼續做
        while (n != 0) {
            // 每執行一次，就「消除」掉最右邊的一個 1
            n = n & (n - 1);
            
            // 計數器 + 1
            count++;
        }
        
        return count;
    }
};