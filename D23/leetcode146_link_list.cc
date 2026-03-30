struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> mp;
    Node *head,*tail;
    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node){
        Node *tmp = head->next;
        head->next = node;
        node->prev = head;
        node->next = tmp;
        tmp->prev = node;    
    }
public:
    
    LRUCache(int capacity) {
        cap = capacity;
        // 4. 初始化 Dummy Head 和 Dummy Tail，並且讓它們互相牽手
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            Node* node = mp[key]; // 把找到的節點抓出來
            removeNode(node);     // 拔出來
            addNode(node);        // 放到最前面 (變新鮮)
            return node->value;
        }
    }
    
    void put(int key, int value) {
        
        if(get(key)!=-1){
            mp[key]->value = value;
        }
        else{
            Node *tmp = new Node(key,value);
            addNode(tmp);
            mp[key] = tmp;
        }
        
        if(mp.size()>cap){
            Node *oldNode = tail->prev; // 抓出最老的節點
            mp.erase(oldNode->key);     // 1. 從 Map 刪除
            removeNode(oldNode);        // 2. 從 List 拔除
            delete oldNode;             // 3. 把記憶體還給系統 (超級重要！)
            
        }
        

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */