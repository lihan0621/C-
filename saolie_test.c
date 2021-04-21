#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_MINE_COUNT 10
int menu(){
	printf("==========================\n");
	printf("=========1.��Ϸ��ʼ=======\n");
	printf("=========0.��Ϸ����=======\n");
	printf("==========================\n");
	int choice = 0;
	scanf_s("%d", &choice);
	return choice;
}
//*��ʾδ���������ֱ�ʾ����
//Լ����'1'��ʾ�ǵ��ף�'0'��ʾ���ǵ���
void Init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]){
	//��ʼ��showMap����ÿ��λ�ö���Ϊ*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showMap[row][col] = '*';
		}
	}
	//2.��ʼ��mineMap���Ȱ�����λ�ö���Ϊ'0'
	//������������ɸ�'1'
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mineMap[row][col] = '0';
		}
	}
	int count = MAX_MINE_COUNT;
	while (count > 0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//�ж�������ɵ����Ƿ�Ϸ�
		if (mineMap[row][col] == '1'){
			continue;
		}
		mineMap[row][col] = '1';
		count--;
	}
}
void Print(char showMap[MAX_ROW][MAX_COL]){
	printf("  | ");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d",col);
	}
	printf("\n");
	printf("--+---------------\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf(" %d| ",row);
		for (int col = 0; col < MAX_COL; col++){
			printf("%c", showMap[row][col]);
		}
		printf("\n");
	}
}
void Input(char showMap[MAX_ROW][MAX_COL],int* row, int* col){
	while (1){
		printf("������Ҫ������λ�ã�");
		scanf_s("%d %d", row, col);
		if (*row<0 || *row>MAX_ROW || *col<0 || *col>MAX_COL){
			printf("������������\n");
			continue;
		}
		if (showMap[*row][*col] != '*'){
			printf("��λ���Ѿ�������\n");
			continue;
		}
		break;
	}
}
void Update(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL],int row, int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
				continue;
			}
			if (mineMap[r][c] == '1'){
				count++;
			}
		}
	}
	showMap[row][col] = count+'0';
	//�����Ҫʵ�����������Ļ������������ж��Ƿ���0
	//�ݹ���õ�ǰ��Update�������ݹ��ʱ�����row��col
	//��ǰλ�õ�����λ��
}
void game(){
	//1.������ͼ����ʼ��	
	char showMap[MAX_ROW][MAX_COL];
	char mineMap[MAX_ROW][MAX_COL];
	Init(showMap, mineMap);
	int notMineCount = 0;
	while (1){
		Print(mineMap);
		printf("\n");
		//2.��ӡ��ͼ
		Print(showMap);
        //3.��ҷ���ָ��λ�ã��������꣩
		//4.����ҵ��������У��
		int row = 0;
		int col = 0;
		Input(showMap,&row, &col);
		//5.�Ƿ�����ˣ�������ף�ֱ����Ϸʧ��
		if (mineMap[row][col] =='1'){
			Print(mineMap);
			printf("��Ϸʧ��\n");
			break;
		}
		notMineCount++;
		//6.��������������һ��λ�ã���Ϸʤ��
		if (notMineCount == MAX_ROW*MAX_COL - MAX_MINE_COUNT){
			Print(mineMap);
			printf("��Ϸʤ��\n");
			break;
		}
		//7.��Ϸ��Ҫ�����������ĸ��ӻ���һ������
		Update(showMap, mineMap, row, col);
	}

}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("goodbye\n");
			break;
		}
		else{
			printf("������������!\n");
		}
	}
	system("pause");
	return 0;
}