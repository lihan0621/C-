#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDataType;
typedef struct seqList {
	SLDataType* _data;//需要动态开辟的数组
	size_t _size;      //有效元素的个数
	size_t _capaticy;  //当前可以存放的最大元素个数
}seqList;

//初始化
void InitSeqList(seqList* sl) {
	sl->_data = NULL;
	sl->_size = 0;
	sl->_capaticy = 0;
}

//检查容量
void CheckCapacity(seqList* sl) {
	//assert(sl);
	if (sl == NULL)
		return;
	//如果元素个数和容量相同, 说明空间满了, 需要调整空间(扩容)
	if (sl->_size == sl->_capaticy) {
		int newCapacity = sl->_capaticy == 0 ? 1 : 2 * sl->_capaticy;
		//开一个更大的空间, 拷贝已有的数据, 释放原有的空间
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType) * newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType) * sl->_size);
		free(sl->_data);
		//另一种写法
		//sl->_data = (SLDataType*)realloc(sl->_data, sizeof(SLDataType) * newCapacity);
		//更新
		sl->_data = tmp;
		sl->_capaticy = newCapacity;
	}
}

//尾插
void pushBack(seqList* sl, SLDataType val) {
	//检查容量
	CheckCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

//尾删
void popBack(seqList* sl) {
	if (sl == NULL)
		return;
	if (sl->_size > 0)
		sl->_size--;
}

//头插
// 一般不进行头插: 效率太低
//1.移动元素: [0, size)全部向后移动一个位置
//      方向: 不能从前向后移动, 会导致数据被覆盖
void pushFront(seqList* sl, SLDataType val) {
	if (sl == NULL)
		return;
	//0.检查容量
	CheckCapacity(sl);
	//1.移动元素: 从前向后移动
	size_t end = sl->_size;
	while (end > 0) {
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//头插
	sl->_data[0] = val;
	//更新
	sl->_size++;
}

//头删
//1.移动元素: [0, size)全部向前移动一个位置
//方向: 不能从后先前移动, 会导致数据被覆盖
void popFront(seqList* sl) {
	if (sl == NULL || sl->_size == 0)
		return;
	CheckCapacity(sl);
	int start = 1;
	while (start < sl->_size) {
		sl->_data[start - 1] = sl->_data[start];
		++start;
	}
	sl->_size--;
}

void insert(seqList* sl, int pos, SLDataType val) {
	if (sl == NULL)
		return;
	//0.检查容量
	CheckCapacity(sl);
	//有效的插入位置: [0, size]
	if (pos >= 0 && pos <= sl->_size) {
		size_t end = sl->_size;
		//移动元素: [pos, size)
		while (end > pos) {
			sl->_data[end] = sl->_data[end - 1];
			--end;
		}
		//插入
		sl->_data[pos] = val;
		//更新
		sl->_size++;
	}
}

void erase(seqList* sl, int pos) {
	if (sl == NULL || sl->_size == 0)
		return;
	//0.检查容量
	CheckCapacity(sl);
	if (pos >= 0 && pos < sl->_size) {
		//移动元素: (pos, size)
		//从pos + 1开始从前向后以此移动元素
		int start = pos + 1;
		while (start < sl->_size) {
			sl->_data[start - 1] = sl->_data[start];
			--start;
		}
		--sl->_size;
	}
}

int empty(seqList* sl) {
	if (sl == NULL || sl->_size == 0)
		return 1;
	else
		return 0;
}

int size(seqList* sl) {
	if (sl == NULL)
		return 0;
	else
		return sl->_size;
}

int find(seqList* sl, SLDataType val) {
	for (size_t i = 0; i < sl->_size; ++i) {
		if (sl->_data[i] == val)
			return i;
	}
	return -1;
}

//打印
void printSeqList(seqList* sl) {
	for (size_t i = 0; i < sl->_size; i++) {
		printf("%d ", sl->_data[i]);
	}
	printf("\n");
}

void test() {
	seqList sl;
	InitSeqList(&sl);
	pushBack(&sl, 1);
	pushBack(&sl, 2);
	pushBack(&sl, 3);
	pushBack(&sl, 4);
	pushBack(&sl, 5);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
	popBack(&sl);
	printSeqList(&sl);
}

int main() {
	test();
	return 0;
}
