struct Node* remove_nth_from_end(struct Node* head, int n) {
    // 1. 建立哨兵節點，並把 next 指向 head (解決邊界問題)
    struct Node dummy;
    dummy.next = head;
    
    // 起跑線：快慢指標都站在 dummy 上
    struct Node *fast = &dummy;
    struct Node *slow = &dummy;

    // 🌟 步驟一：讓 fast 先偷跑 n 步
    // (你的迴圈邏輯)
    for (int i = 0; i < n; i++) 
        fast=fast->next;
    
    // 🌟 步驟二：fast 和 slow 同時往前跑，直到 fast 走到最後一個節點
    // (你的迴圈邏輯)
    while (fast->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    // 🌟 步驟三：此時 slow 剛好停在「要刪除節點的前一個」。請進行接線與釋放記憶體！
    // (提示：記得用一個 temp 記住要被殺掉的節點，接好線之後 free 掉它)
    struct Node *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return dummy.next; // 回傳真正的頭
}