class MyQueue {
public:
    stack<int> s1,s2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty()&&s2.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */