#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#include<graphics.h>
#include<conio.h>
#include<Windows.h>

#define MAX 200
HWND hwnd = NULL;

enum DIR {//枚举移动方向
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct COOR {//位置，x，y坐标
	int x;
	int y;
};

struct SNAKE {//蛇的基础信息
	int size;//节数
	int speed;//运动速度
	char dir;//运动方向
	struct COOR xy[MAX];//位置
}snakes;

struct FOOD {//食物信息
	struct COOR fooddir;//食物位置
	int flag;//判断食物是否被吃掉，1未被吃掉，0被吃掉
}food;

void snakeInit() {//初始化蛇的信息
	snakes.size = 3;//开始节数
	snakes.dir = RIGHT;//开始运动方向
	snakes.speed = 10;
	int i = 0;
	for (; i < snakes.size; i++) {//每一节书的位置，注意将第一节作为头
		snakes.xy[i].x = 40 - 10 * i;
		snakes.xy[i].y = 10;
	}

}

void drawSnake() {//画蛇
	int i = 0;
	for (; i < snakes.size; i++) {
		//setlinecolor(BLACK);//画线的颜色
		//setfillcolor(RED);//填充色
		//fillrectangle(snakes.xy[i].x, snakes.xy[i].y, snakes.xy[i].x + 10, snakes.xy[i].y+10);//矩形
		fillcircle(snakes.xy[i].x, snakes.xy[i].y, 5);//圆形
	}


}

void moveSnake() {//蛇的移动
	//snakes.xy[0].x++;

	int i = 0;
	for (i = snakes.size - 1; i > 0; i--) {//蛇身跟着舌头运动
		snakes.xy[i].x = snakes.xy[i - 1].x;
		snakes.xy[i].y = snakes.xy[i - 1].y;
	}
	switch (snakes.dir) {
	case UP:
		snakes.xy[0].y -= snakes.speed;
		break;
	case DOWN:
		snakes.xy[0].y += snakes.speed;
		break;
	case LEFT:
		snakes.xy[0].x -= snakes.speed;
		break;
	case RIGHT:
		snakes.xy[0].x += snakes.speed;
		break;
	default:
		break;
	}


}

void coorSnake() {//按键控制蛇的运动方向
	if (_kbhit()) { //等待获取按键
		char c = _getch();//获得按键
		switch (c) {
		case 72:
		case'w':
			if (snakes.dir != DOWN) {
				snakes.dir = UP;
			}
			break;
		case 80:
		case's':
			if (snakes.dir != UP) {
				snakes.dir = DOWN;
			}
			break;
		case 75:
		case'a':
			if (snakes.dir != RIGHT) {
				snakes.dir = LEFT;
			}
			break;
		case 77:
		case'd':
			if (snakes.dir != LEFT) {
				snakes.dir = RIGHT;
			}
			break;
		default:
			break;
		}
	}
}
void initFood() {//初始化食物的信息
	food.flag = 1;
	while (1) {
	START:
		food.fooddir.x = rand() % 63 * 10;//食物位置随机
		food.fooddir.y = rand() % 47 * 10;
		for (int i = 0; i < snakes.size; i++) {//防止食物生成在蛇身上。
			if (food.fooddir.x == snakes.xy[i].x && food.fooddir.y == snakes.xy[i].y) {
				goto START;
			}
			else {
				break;
			}
		}
		break;
	}
}

void drawFood() {//画食物
	//food.fooddir.x = 100;
	//food.fooddir.y = 200;
	//setlinecolor(BLACK);
	//setfillcolor(RED);
	fillcircle(food.fooddir.x, food.fooddir.y, 5);

}
void eatFood() {//蛇吃食物
	if (snakes.xy[0].x - food.fooddir.x <= 5 && snakes.xy[0].y - food.fooddir.y <= 5 \
		&& food.fooddir.x - snakes.xy[0].x <= 5 && food.fooddir.y - snakes.xy[0].y <= 5 && food.flag == 1) {
		food.flag = 0;
		snakes.size++;
	}

}

int gameOver() {//游戏结束情况
	if (snakes.xy[0].x < 5 || snakes.xy[0].y <= 0 || snakes.xy[0].x > 635 || snakes.xy[0].y > 478) {
		MessageBox(hwnd, "GAME OVER!", "你撞墙了！", MB_OK);
		return 1;
	}
	for (int i = 1; i < snakes.size; i++) {
		if (snakes.xy[0].x == snakes.xy[i].x && snakes.xy[0].y == snakes.xy[i].y) {
			MessageBox(hwnd, "GAME OVER!", "你撞了自己", MB_OK);
			return 1;
		}
	}
	return 0;
}



void gameInit() {
	hwnd = initgraph(640, 480);//设置窗口大小
	//setbkcolor(GREEN);//设置窗口颜色
}


int main() {
	srand((unsigned long)time(NULL));//生成随机数
	gameInit();
	cleardevice();//刷新窗口
	snakeInit();
	initFood();
	while (1) {
		cleardevice();
		if (food.flag == 0) {
			initFood();
		}
		drawFood();
		drawSnake();
		coorSnake();
		eatFood();
		moveSnake();
		//eatFood();
		if (gameOver()) {
			break;
		}
		//stopGame();
		Sleep(100);
	}
	getchar();//防止闪屏
	closegraph();
	system("pause");
	return 0;
}
