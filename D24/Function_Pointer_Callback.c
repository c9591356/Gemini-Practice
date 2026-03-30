// 1. 定義型別 (typedef)
typedef void (*handler)(int);
// 2. 實作註冊並執行的函數
void execute_handler(handler func, int data) {
    // 呼叫傳入的函數指標
    func(data);
}