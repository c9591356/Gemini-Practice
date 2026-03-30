int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
// 🌟 步驟 1：請使用 typedef 定義一個函數指標型別 `MathOp`。
// 該函數必須接收兩個 int 參數，並回傳一個 int 值。
typedef int (*MathOp)(int,int);

// 🌟 步驟 2：請宣告一個名為 `op_table` 的陣列（大小為 3），
// 並把上面的 add, sub, mul 依序放進去初始化。
MathOp op_table[3] = {add,sub,mul};

// 🌟 步驟 3：請實作分發與計算函數。
// 規則：傳入操作 ID (0=加, 1=減, 2=乘)，以及兩個要運算的數字 x 與 y。
// 🚨 限制：一樣不准用 switch-case 或一堆 if-else 判斷功能！
// 防禦機制：如果 op_id 越界（不是 0, 1, 2），請直接回傳 0。
int compute(int op_id, int x, int y) {
    // 你的純淨白板發揮時間
    if(op_id<=2 && op_id>=0)
        return op_table[op_id](x,y);
    return-1;
}