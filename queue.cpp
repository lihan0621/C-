#include <stdio.h>
#include <stdlib.h>

/*
typedef struct {
    //第一种实现:
    int* _data;
    //第一个元素的位置: 队头位置
    int _front;
    //最后一个元素的下一个位置
    int _rear;
    int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //多开一个元素的空间
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (mq)
    {
		mq->_data = (int*)malloc(sizeof(int) * (k + 1));
		mq->_front = mq->_rear = 0;
		mq->_k = k;
		return mq;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->_front == obj->_rear)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->_rear + 1) % (obj->_k + 1) == obj->_front)
        return true;
    else
        return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //判断队列是否已满
    if (myCircularQueueIsFull(obj))
        return false;
    obj->_data[obj->_rear++] = value;
    //判断队尾是否越界
    if (obj->_rear > obj->_k)
        obj->_rear = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //判断队列是否为空
    if (myCircularQueueIsEmpty(obj))
        return false;
    //出队
    obj->_front++;
    //判断队头是否越界
    if (obj->_front > obj->_k)
        obj->_front = 0;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    //返回队尾rear的前一个位置的元素
    //判断rear是否为0;
    if (obj->_rear != 0)
        return obj->_data[obj->_rear - 1];
    else
        return obj->_data[obj->_k];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}
*/

typedef struct {
    //第一种实现:
    int* _data;
    //第一个元素的位置: 队头位置
    int _front;
    //最后一个元素的下一个位置
    int _rear;
    int _k;
    int _size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //多开一个元素的空间
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (mq) {
        mq->_data = (int*)malloc(sizeof(int) * k);
        mq->_front = mq->_rear = 0;
        mq->_k = k;
        mq->_size = 0;
        return mq;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->_size == 0)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->_size == obj->_k)
        return true;
    else
        return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //判断队列是否已满
    if (myCircularQueueIsFull(obj))
        return false;
    obj->_data[obj->_rear++] = value;
    //判断队尾是否越界
    if (obj->_rear >= obj->_k)
        obj->_rear = 0;
    ++obj->_size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //判断队列是否为空
    if (myCircularQueueIsEmpty(obj))
        return false;
    //出队
    obj->_front++;
    //判断队头是否越界
    if (obj->_front >= obj->_k)
        obj->_front = 0;
    --obj->_size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->_data[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    //返回队尾rear的前一个位置的元素
    //判断rear是否为0;
    if (obj->_rear != 0)
        return obj->_data[obj->_rear - 1];
    else
        return obj->_data[obj->_k - 1];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}

