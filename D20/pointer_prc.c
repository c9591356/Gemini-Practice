/*任務：
請寫一個函數 delete_node，傳入串列的頭指標位址與一個目標數字 key。如果串列中有這個數字，請把它刪除，並釋放記憶體。
*/
struct Node {
    int data;
    struct Node *next;
};

// 傳入雙重指標 head_ref，因為我們可能需要修改 Head 本尊！
void delete_node(struct Node **head_ref, int key) {
    // temp 用來代替我們在串列裡面跑腿
    struct Node *temp = *head_ref;
    // prev 用來記住 temp 的前一個節點，因為刪除時需要重新接線！
    struct Node *prev = NULL;

    // 🌟 情境 1：如果頭節點 (Head) 剛好就是要刪除的目標！
    if (temp != NULL && temp->data == key) {
        // 1. 把真正的 Head 本尊 (*head_ref) 改指向 temp 的下一個節點
        *head_ref = temp->next;
        // 2. 釋放 temp 佔用的記憶體 (注意：C 語言不是用 delete 喔！)
        free(temp);
        return;
    }

    // 🌟 情境 2：目標不在頭部，我們必須往後找。
    while (temp != NULL && temp->data != key) {
        // 3. 讓 prev 記住目前的 temp
        prev = temp;
        // 4. 讓 temp 往下走一步 (temp = ?)
        temp =temp->next;
    }

    // 如果走到盡頭都沒找到 key，就直接結束
    if (temp == NULL) return;

    // 🌟 情境 3：找到了！temp 現在指著要被刪掉的節點，prev 指著它的前一個。
    // 5. 把 prev 的 next 重新接線，繞過 temp，直接指向 temp 的下一個！
    prev->next = temp->next;
    // 6. 釋放 temp 佔用的記憶體
    free(temp);
}
struct Node* merge_sorted_lists(struct Node* l1, struct Node* l2) {
    // 你的純淨白板發揮時間
    if (l1 == NULL) return l2; if (l2 == NULL) return l1;
    struct Node* cur;
    if(l1->data<l2->data){
        cur = l1;
        l1 = l1->next;
    }else{
        cur = l2;
        l2 = l2->next;
    }
    struct Node* head=cur;
    
    while (l1!=NULL && l2!=NULL)
    {
        /* code */
        if(l1->data<l2->data){
            cur->next = l1;
            l1=l1->next;
        }
        else{
            cur->next = l2;
            l2=l2->next;
        }
        cur = cur->next;
    }
    if (l1!=NULL)
        cur->next = l1;
    else
        cur->next = l2;
    return head;    
    

}