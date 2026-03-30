class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        
        for(int num : nums) {
            // 利用二分搜找到 tails 中第一個 >= num 的位置
            auto it = lower_bound(tails.begin(), tails.end(), num);
            
            // 如果沒找到 (num 比 tails 裡所有的數字都大)，就把 num 塞到最後面擴充長度
            if(it == tails.end()) {
                tails.push_back(num);
            } 
            // 如果找到了，就替換掉它 (讓該長度的結尾數字變小，增加潛力)
            else {
                *it = num;
            }
        }
        
        return tails.size(); // tails 的長度就是 LIS 的長度！
    }
};