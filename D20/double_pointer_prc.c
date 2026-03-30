struct Node {
    int data;
    struct Node *next;
};
/*面試官要你寫一個函數 push_front，把一個新的數字插入到整個串列的最前面（成為新的 Head）。*/
// head_ref 是指向 head 指標的指標
void push_front(struct Node **head_ref, int new_data) {
    // 1. 動態配置一個新節點 (struct Node)
    str Node *new_node = malloc(sizeof(Node));
    // 2. 把 new_data 放進新節點的 data 裡
    new_node->data = new_data; 
    // 3. 把新節點的 next 指向目前的頭節點 (解鎖 head_ref 取得目前的頭)
    new_node->next = *head_ref;
    // 4. 更新外部的頭節點，讓它指向這個新節點 (解鎖 head_ref 並賦值)
    *head_ref = new_node;
}