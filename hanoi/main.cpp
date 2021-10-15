#include<stdio.h>
#include<stdlib.h>

//#define level 5
int level = 5;

typedef struct{
	int q[8];
	int cur;
} tower_t;

int inq(tower_t* atower, int plate);
int inq_valid(tower_t* atower, int plate);
int deq(tower_t* atower, int *plate);
int deq_valid(tower_t* atower, int *plate);
int tower_print(int move_cnt, tower_t* tower_a, tower_t* tower_b, tower_t* tower_c);

int main() {	
	//printf("Game Clear\nPress x exit:");
	//while (getchar() != 'x');
	printf("Hanoi Tower\r\n");
	do {
		printf("Select Level:");
		scanf_s("%d", &level);
	} while (level < 3 || level > 8);
	system("cls");
	
	tower_t one;
	tower_t two;
	tower_t three;

	for (int i = 0; i < level; i++) {
		one.q[i] = level - i;
	}
	one.cur = level;
	two.cur = 0;
	three.cur = 0;

	int from, to, buf,result_deq,result_inq,move_cnt=0;

	tower_print(move_cnt, &one, &two, &three);

	do{
		printf("Select Tower:");
		scanf_s("%d%d", &from, &to);
		//check balid
		if(from == 1)	        result_deq = deq_valid(&one, &buf);
		else if (from == 2)		result_deq = deq_valid(&two, &buf);
		else if (from == 3)		result_deq = deq_valid(&three, &buf);
		else
		{
			result_deq = -1;
			buf = 0;
		}

		if (to == 1)	        result_inq = inq_valid(&one, buf);
		else if (to == 2)		result_inq = inq_valid(&two, buf);
		else if (to == 3)		result_inq = inq_valid(&three, buf);
		else
		{
			result_inq = -1;
		}

		if (result_deq == 0 && result_inq == 0) {
			if (from == 1)			deq(&one, &buf);
			else if (from == 2)		deq(&two, &buf);
			else if (from == 3)		deq(&three, &buf);

			if (to == 1)			inq(&one, buf);
			else if (to == 2)		inq(&two, buf);
			else if (to == 3)		inq(&three, buf);
		}
		move_cnt++;
		tower_print(move_cnt, &one, &two, &three);
	} while (two.cur != level && three.cur != level);

	printf("Game Clear\nPress x exit:");
	while (getchar() != 'x');

	return 0;
}
int inq(tower_t* atower,int plate) {
	atower->cur++;
	atower->q[atower->cur - 1] = plate;
	return 0;
}

int inq_valid(tower_t* atower, int plate) {
	if (atower->cur == 0) {
		return 0;
	}
	else if (atower->cur < level && atower->q[atower->cur - 1] > plate) {
		return 0;
	}
	else {
		return -1;
	}
}

int deq(tower_t* atower, int *plate) {
	*plate = atower->q[atower->cur-1];
	atower->cur--;
	return 0;
}

int deq_valid(tower_t* atower, int *plate) {
	if (atower->cur > 0) {
		*plate = atower->q[atower->cur - 1];
		return 0;
	}
	else {
		return -1;
	}
}

int tower_print(int move_cnt, tower_t* tower_a, tower_t* tower_b, tower_t* tower_c) {
	system("cls");
	printf("move_cnt:%d\r\n\n\n",move_cnt);

	for (int i = level; i >= 1; i--) {
	//for(int i = 3; i >= 1; i--) {
		if (tower_a->cur >= i)	printf("%d    ", tower_a->q[i-1]);
		else                    printf("|    ");

		if (tower_b->cur >= i)	printf("%d    ", tower_b->q[i-1]);
		else                    printf("|    ");

		if (tower_c->cur >= i)	printf("%d    \r\n", tower_c->q[i-1]);
		else                    printf("|    \r\n");
	}
	printf("===============\r\n1    2    3    \r\n");
	
	return 0;
}
