#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

//#include "SeqList.h"
//#include "List.h"
//#include "SCList.h"
//#include "DCList.h"
//#include "Stack.h"
//#include "Queue.h"
//#include "Tree.h"
#include "Heap.h"

int main()
{
	Heap hp;
	HeapElemType ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);

	HeapInitByArray(&hp, ar, n);
	while (!HeapEmpty(&hp))
	{
		HeapElemType top_val = HeapTop(&hp);
		printf("%d ", top_val);
		HeapRemove(&hp);
	}
	printf("\n");

	system("pause");
	return 0;
}

#if 0
int main()
{
	Heap hp;
	HeapElemType ar[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(ar) / sizeof(ar[0]);
	HeapInit(&hp, 20);

	for (int i = 0; i < n; i++)
		HeapInsert(&hp, ar[i]);
	//HeapShow(&hp);
	while (!HeapEmpty(&hp))
	{
		HeapElemType top_val = HeapTop(&hp);
		printf("%d ", top_val);
		HeapRemove(&hp);
	}
	printf("\n");

	system("pause");
	return 0;
}

int main()
{
	char* vlr = "ABCDEFGH";
	char* lvr = "CBEDFAGH";
	char* lrv = "CEFDBHGA";
	BinTree bt;
	BinTreeInit(&bt);

	int n = strlen(lvr);
	//bt = BinTreeCreat_VLR_LVR(vlr, lvr, n);
	bt = BinTreeCreat_LVR_LRV(lvr, lrv, n);

	printf("VLR: ");
	PreOrder(bt);
	printf("\n");
	printf("VLR_Nor: ");
	PreOrder_Nor(bt);
	printf("\n");
	printf("LVR: ");
	IndOrder(bt);
	printf("\n");
	printf("LVR_NOR: ");
	IndOrder_Nor(bt);
	printf("\n");
	printf("LRV: ");
	PostOrder(bt);
	printf("\n");
	printf("LRV_NOR: ");
	PostOrder_Nor(bt);
	printf("\n");
	printf("Level: ");
	LevelOrder(bt);
	printf("\n");

	system("pause");
	return 0;
}

int main()
{
	char* str = "ABC##DE##F##G#H##";
	BinTree bt;
	BinTreeInit(&bt);
	//BinTreeCreat_1(&bt);
	//bt = BinTreeCreat_2();

	int index = 0;
	bt = BinTreeCreat_3(str, &index);

	printf("VLR: ");
	PreOrder(bt);
	printf("\n");
	printf("VLR_Nor: ");
	PreOrder_Nor(bt);
	printf("\n");
	printf("LVR: ");
	IndOrder(bt);
	printf("\n");
	printf("LVR_NOR: ");
	IndOrder_Nor(bt);
	printf("\n");
	printf("LRV: ");
	PostOrder(bt);
	printf("\n");
	printf("LRV_NOR: ");
	PostOrder_Nor(bt);
	printf("\n");
	printf("Level: ");
	LevelOrder(bt);
	printf("\n");

	printf("size: %d\n", Size(bt));
	printf("Height: %d\n", Height(bt));

	char key = 'D';
	BinTreeNode* p = Find(bt, key);

	BinTreeNode* pr = Parent(bt, p);

	BinTree bt1 = Clone(bt);

	system("pause");
	return 0;
}

int main()
{
	SeqQueue sq;
	SeqQueueInit(&sq, 0);
	SeqQueuePush(&sq, 1);
	SeqQueuePush(&sq, 2);
	SeqQueuePush(&sq, 3);
	SeqQueuePush(&sq, 4);
	SeqQueuePush(&sq, 5);
	SeqQueueShow(&sq);
	printf("----------------\n");
	SeqQueuePop(&sq);
	SeqQueueShow(&sq);
	QueueElemType back = SeqQueueBack(&sq);
	QueueElemType front = SeqQueueFront(&sq);
	printf("?????? %d,  ?????? %d\n", back, front);


	system("pause");
	return 0;
}

int main()
{
	LinkQueue qu;
	LinkQueueInit(&qu);
	LinkQueuePush(&qu, 1);
	LinkQueuePush(&qu, 2);
	LinkQueuePush(&qu, 3);
	LinkQueuePush(&qu, 4);
	LinkQueuePush(&qu, 5);
	LinkQueueShow(&qu);
	printf("-----------------\n");
	LinkQueuePop(&qu);
	LinkQueueShow(&qu);


	system("pause");
	return 0;
}



int main()
{

	LinkStack st;
	LinkStackInit(&st);
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);
	LinkStackShow(&st);
	printf("-----------------\n");
	LinkStackPop(&st);
	LinkStackShow(&st);

	LinkStackDestroy(&st);

	system("pause");

	return 0;
}


int main()
{
	SeqStack st;
	SeqStackInit(&st, 0);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);
	printf("=============\n");
	while (!IsEmpty(&st))
	{
		StackElemType val = SeqStackTop(&st);
		SeqStackPop(&st);
		printf("%d????\n", val);
	}
	printf("????????\n");
	system("pause");
	return 0;
}



int main()
{
	//SeqList myList;
	//SeqListInit(&mylist, 8);

	//SCList mylist;
	//SCListInit(&mylist);

	//List myList;
	//ListInit(&mylist);


	DCList mylist;
	DCListInit(&mylist);

	Elemtype item, key;
	int pos;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [0] quit_system         [1] push_back    *\n");
		printf("* [2] push_front          [3] show_list    *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [*6] insert_pos         [7] insert_val   *\n");
		printf("* [*8] erase_pos          [9] erase_val    *\n");
		printf("* [*10] find_pos          [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [*15] capacity   *\n");
		printf("* [16] clear              [*17] destroy    *\n");
		printf("********************************************\n");
		printf("??????:>");
		scanf("%d", &select);
		if (select == 0)
			break;

		switch (select)
		{
		case 1:
			printf("??????????????????<??-1????>:");
			while (scanf("%d", &item))
			{
				if (item == -1)
					break;
				//DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("??????????????????<??-1????>:");
			while (scanf("%d", &item))
			{
				if (item == -1)
					break;
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("??????????????????:>");
			scanf("%d", &pos);
			printf("????????????????:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&myList, pos, item);
			break;
		case 7:
			printf("????????????????:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("??????????????????:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&myList, pos);
			break;
		case 9:
			printf("????????????????:>");
			scanf("%d", &item);
			//DCListEraseByVal(&mylist, item);
			break;
		case 10:
			printf("??????????????????:>");
			scanf("%d", &pos);
			//int val = SeqListFindByPos(&myList, pos);
			//printf("?????????? %d ???????????? %d \n", pos, val);
			break;
		case 11:
			printf("????????????????:>");
			scanf("%d", &key);
			//pos = ListFind(mylist, key);
			if (pos == -1)
				printf("???????? %d ????????????\n", key);
			else
				printf("???????? %d ?????????? %d\n", key, pos);
			break;
		case 12:
			DCListSort(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			printf("??????????????:> %d\n", DCListLength(&mylist));
			break;
		case 15:
			//printf("??????????????:> %d\n", SeqListCapacity(&myList));
			break;
		case 16:
			DCListClear(&mylist);
			break;
		case 17:
			DCListDestroy(&mylist);
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
#endif