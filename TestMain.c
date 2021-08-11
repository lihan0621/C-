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
		printf("��ѡ��:>");
		scanf("%d", &select);
		if(select == 0)
			break;

		switch(select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushBack(&myList, item);
			}
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:>");
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
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����ֵ:>");
			scanf("%d", &item);
			SeqListInsertByPos(&myList, pos, item);
			break;
		case 8:
			break;
		case 10:
			printf("������Ҫ���ҵ�λ��:>");
			scanf("%d", &pos);
			int val = SeqListFindByPos(&myList, pos);
			printf("��Ҫ���ҵ� %d λ�õ�ֵ�ǣ� %d \n", pos, val);
			break;
		case 11:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFindByVal(&myList, key);
			if (pos == -1)
				printf("Ҫ���ҵ� %d �����ݲ�����\n", key);
			else
				printf("Ҫ���ҵ� %d ��λ��Ϊ�� %d\n", key, pos);
			break;
		case 14:
			printf("˳���ĳ���Ϊ:> %d\n", SeqListLength(&myList));
			break;
		case 15:
			printf("˳��������Ϊ:> %d\n", SeqListCapacity(&myList));
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