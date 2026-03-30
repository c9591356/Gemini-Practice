void cmd_power_on(void) { /* 電源開啟邏輯 */ }
void cmd_power_off(void) { /* 電源關閉邏輯 */ }
void cmd_reset(void) { /* 重置邏輯 */ }

// 🌟 步驟 1：請使用 typedef 定義一個函數指標型別 `CmdFunc`，
// 該函數不接收參數 (void)，也不回傳值 (void)。
typedef void (*Cmdfunc)(void);

// 🌟 步驟 2：請宣告一個型別為 CmdFunc、大小為 3 的陣列，命名為 `cmd_table`。
// 並在宣告的同時，把上面的三個函數（power_on, power_off, reset）依序放進去初始化。
CmdFunc cmd_table[3] = {cmd_power_on,cmd_power_off,cmd_reset};

// 🌟 步驟 3：請實作分發函數。
// 規則：傳入指令 ID (0 代表 power_on, 1 代表 power_off, 2 代表 reset)。
// 🚨 終極限制：函數內「絕對不可以使用」 switch-case 或一堆 if-else 來判斷呼叫誰！
// 只能透過陣列索引直接呼叫。 (但你可以用一個簡單的 if 來防止越界)
void execute_cmd(int cmd_id) {
    // 1. 防禦性判斷：確保指令 ID 沒有越界
    if (cmd_id >= 0 && cmd_id < 3) {
        // 2. 查表並扣下板機 () 執行它！
        cmd_table[cmd_id](); 
    }
}