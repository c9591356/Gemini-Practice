class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 邊界檢查
        if (head == NULL || head->next == NULL) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 標準寫法：只檢查 fast 能不能跑兩步
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;       // 走一步
            fast = fast->next->next; // 走兩步
            
            // 如果相遇，代表有環
            if (slow == fast) {
                return true;
            }
        }
        
        // 兔子跑到終點 (NULL) 了，代表沒有環
        return false;
    }
};