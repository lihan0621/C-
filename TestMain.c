#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

//#include "SeqList.h"
//#include "List.h"
//#include "SCList.h"
//#include "DCList.h"
#include "Stack.h"



#if 0
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
		printf("%d��ջ\n", val);
	}
	printf("��ջ���\n");
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
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;

		switch (select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item))
			{
				if (item == -1)
					break;
				//DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
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
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&myList, pos, item);
			break;
		case 7:
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&myList, pos);
			break;
		case 9:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &item);
			//DCListEraseByVal(&mylist, item);
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��:>");
			scanf("%d", &pos);
			//int val = SeqListFindByPos(&myList, pos);
			//printf("��Ҫ���ҵ� %d λ�õ�ֵ�ǣ� %d \n", pos, val);
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			//pos = ListFind(mylist, key);
			if (pos == -1)
				printf("Ҫ���ҵ� %d �����ݲ�����\n", key);
			else
				printf("Ҫ���ҵ� %d ��λ��Ϊ�� %d\n", key, pos);
			break;
		case 12:
			DCListSort(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			printf("˳���ĳ���Ϊ:> %d\n", DCListLength(&mylist));
			break;
		case 15:
			//printf("˳��������Ϊ:> %d\n", SeqListCapacity(&myList));
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