#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_MINE_COUNT 10
int menu(){
	printf("==========================\n");
	printf("=========1.游戏开始=======\n");
	printf("=========0.游戏结束=======\n");
	printf("==========================\n");
	int choice = 0;
	scanf_s("%d", &choice);
	return choice;
}
//*表示未翻开，数字表示翻开
//约定：'1'表示是地雷，'0'表示不是地雷
void Init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]){
	//初始化showMap，把每个位置都设为*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showMap[row][col] = '*';
		}
	}
	//2.初始化mineMap，先把所有位置都设为'0'
	//再随机产生若干个'1'
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mineMap[row][col] = '0';
		}
	}
	int count = MAX_MINE_COUNT;
	while (count > 0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//判断随机生成的雷是否合法
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
		printf("请输入要翻开的位置：");
		scanf_s("%d %d", row, col);
		if (*row<0 || *row>MAX_ROW || *col<0 || *col>MAX_COL){
			printf("您的输入有误\n");
			continue;
		}
		if (showMap[*row][*col] != '*'){
			printf("此位置已经翻开了\n");
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
	//如果需要实现连续翻开的话，就在这里判定是否是0
	//递归调用当前的Update函数，递归的时候传入的row，col
	//当前位置的相邻位置
}
void game(){
	//1.创建地图并初始化	
	char showMap[MAX_ROW][MAX_COL];
	char mineMap[MAX_ROW][MAX_COL];
	Init(showMap, mineMap);
	int notMineCount = 0;
	while (1){
		Print(mineMap);
		printf("\n");
		//2.打印地图
		Print(showMap);
        //3.玩家翻开指定位置（输入坐标）
		//4.对玩家的输入进行校验
		int row = 0;
		int col = 0;
		Input(showMap,&row, &col);
		//5.是否踩雷了，如果踩雷，直接游戏失败
		if (mineMap[row][col] =='1'){
			Print(mineMap);
			printf("游戏失败\n");
			break;
		}
		notMineCount++;
		//6.如果翻开的是最后一个位置，游戏胜利
		if (notMineCount == MAX_ROW*MAX_COL - MAX_MINE_COUNT){
			Print(mineMap);
			printf("游戏胜利\n");
			break;
		}
		//7.游戏需要继续，翻开的格子会变成一个数字
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
			printf("您的输入有误!\n");
		}
	}
	system("pause");
	return 0;
}