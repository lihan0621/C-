#include <stdio.h>
#include <stdlib.h>

/*
typedef struct {
    //��һ��ʵ��:
    int* _data;
    //��һ��Ԫ�ص�λ��: ��ͷλ��
    int _front;
    //���һ��Ԫ�ص���һ��λ��
    int _rear;
    int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //�࿪һ��Ԫ�صĿռ�
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
    //�ж϶����Ƿ�����
    if (myCircularQueueIsFull(obj))
        return false;
    obj->_data[obj->_rear++] = value;
    //�ж϶�β�Ƿ�Խ��
    if (obj->_rear > obj->_k)
        obj->_rear = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //�ж϶����Ƿ�Ϊ��
    if (myCircularQueueIsEmpty(obj))
        return false;
    //����
    obj->_front++;
    //�ж϶�ͷ�Ƿ�Խ��
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
    //���ض�βrear��ǰһ��λ�õ�Ԫ��
    //�ж�rear�Ƿ�Ϊ0;
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
    //��һ��ʵ��:
    int* _data;
    //��һ��Ԫ�ص�λ��: ��ͷλ��
    int _front;
    //���һ��Ԫ�ص���һ��λ��
    int _rear;
    int _k;
    int _size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    //�࿪һ��Ԫ�صĿռ�
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
    //�ж϶����Ƿ�����
    if (myCircularQueueIsFull(obj))
        return false;
    obj->_data[obj->_rear++] = value;
    //�ж϶�β�Ƿ�Խ��
    if (obj->_rear >= obj->_k)
        obj->_rear = 0;
    ++obj->_size;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    //�ж϶����Ƿ�Ϊ��
    if (myCircularQueueIsEmpty(obj))
        return false;
    //����
    obj->_front++;
    //�ж϶�ͷ�Ƿ�Խ��
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
    //���ض�βrear��ǰһ��λ�õ�Ԫ��
    //�ж�rear�Ƿ�Ϊ0;
    if (obj->_rear != 0)
        return obj->_data[obj->_rear - 1];
    else
        return obj->_data[obj->_k - 1];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->_data);
    free(obj);
}

