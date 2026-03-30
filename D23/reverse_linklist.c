struct Node* reverse_list(struct Node* head) {
    struct Node *prev = NULL; // 尾巴要指向 NULL
    struct Node *cur = head;
    struct Node *tmp;
    
    while (cur != NULL) {
        tmp = cur->next;  // 1. 先記住下一個是誰
        cur->next = prev; // 2. 轉向！指向前一個
        prev = cur;       // 3. prev 往前踩一步
        cur = tmp;        // 4. cur 往前踩一步
    }
    return prev; // 迴圈結束時，prev 就是新的頭！
}