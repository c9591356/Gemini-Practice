#define BUFFER_SIZE 8

typedef struct {
    int data[BUFFER_SIZE];
    volatile int head; // 生產者更新
    volatile int tail; // 消費者更新
} RingBuffer;

// 要求：
// 1. 若 Buffer 已滿，回傳 -1。
// 2. 若成功存入，回傳 0。
// 3. 必須包含 Memory Barrier 確保資料寫入先於 head 更新。
int ring_buffer_push(RingBuffer *rb, int val) {
    // 請實作你的代碼
    if ((rb->head+1)%BUFFER_SIZE==rb->tail)
        return -1;
    rb->data[head] = val;
    __sync_synchronize();
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    return 0;
}