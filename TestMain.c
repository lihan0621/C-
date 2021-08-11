#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include "SeqList.h"

int main()
{
	SeqList myList;
	SeqListInit(&myList, 8);

	Elemtype item, key;
	int pos;
	int select = 1;
	while (select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [6] insert_pos          [7] insert_val   *\n");
		printf("* [8] erase_pos           [9] erase_val    *\n");
		printf("* [10] find_pos           [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [15] capacity    *\n");
		printf("* [16] clear              [*17] destroy    *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;

		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushBack(&myList, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushFront(&myList, item);
			}
			break;
		case 3:
			SeqListShow(&myList);
			break;
		case 4:
			SeqListPopBack(&myList);
			break;
		case 5:
			SeqListPopFront(&myList);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsertByPos(&myList, pos, item);
			break;
		case 8:
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			int val = SeqListFindByPos(&myList, pos);
			printf("需要查找的 %d 位置的值是： %d \n", pos, val);
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFindByVal(&myList, key);
			if (pos == -1)
				printf("要查找的 %d 的数据不存在\n", key);
			else
				printf("要查找的 %d 的位置为： %d\n", key, pos);
			break;
		case 14:
			printf("顺序表的长度为:> %d\n", SeqListLength(&myList));
			break;
		case 15:
			printf("顺序表的容量为:> %d\n", SeqListCapacity(&myList));
			break;
		case 16:
			SeqListClear(&myList);
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}