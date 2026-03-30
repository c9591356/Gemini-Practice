class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache_list;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // 1. 如果找不到，回傳 -1
        if (mp.find(key) == mp.end()) {
            return -1; 
        }
        
        // 2. 找到了！我們要把它更新為「最近使用」
        int value = mp[key]->second; // 先把值備份起來
        
        cache_list.erase(mp[key]);   // 從 List 中把這個舊節點直接刪除
        cache_list.push_front({key, value}); // 重新在 List 的最前面塞入一個新節點
        
        // 3. ⭐️ 關鍵：因為節點被砍掉重練了，它在記憶體裡的位址變了
        // 所以必須去 Map 裡面更新這個 key 查到的新指標！
        mp[key] = cache_list.begin(); 
        
        return value; 
    }
    
    void put(int key, int value) {
        // 情況 A：如果 key 已經存在
        if (mp.find(key) != mp.end()) {
            // 直接砍掉舊的，在最前面塞新的
            cache_list.erase(mp[key]);
            cache_list.push_front({key, value});
            mp[key] = cache_list.begin(); // 更新 Map 裡的指標
            return;
        }
        
        // 情況 B：這個 key 不存在，是全新的資料。
        // 先檢查快取是不是已經滿了？
        if (cache_list.size() == cap) {
            // 滿了！踢掉最後面（最久沒用）的那個
            int old_key = cache_list.back().first; 
            mp.erase(old_key);       // 從 Map 刪除
            cache_list.pop_back();   // 從 List 刪除
        }
        
        // 現在確定有空間了，直接在最前面塞入新資料
        cache_list.push_front({key, value});
        mp[key] = cache_list.begin(); // 記得把新家位址登記到 Map
    }
};