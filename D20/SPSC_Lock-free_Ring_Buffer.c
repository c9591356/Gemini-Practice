#define SIZE 10

typedef struct {
    int buffer[SIZE];
    volatile int head; // 生產者專用 (出餐鈴)
    volatile int tail; // 消費者專用 (取餐進度)
} RingBuffer;

void push_buffer(**RingBuffer push_buffer,int push_number){
    while((Buffer->head+1)%SIZE==Buffer->tail);//滿了
    push_buffer->buffer[head] = push_number;
    __sync_synchronize();
    head = head + 1;

}