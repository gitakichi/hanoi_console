#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int q[8];
	int cur;
} tower_t;

int inq(tower_t* atower, int plate);
int inq_valid(tower_t* atower, int plate);
int deq(tower_t* atower, int *plate);
int deq_valid(tower_t* atower, int *plate);
int tower_print(tower_t* tower_a, tower_t* tower_b, tower_t* tower_c);

int main() {
	tower_t one = { {3,2,1},3 };
	tower_t two = { {},0 };
	tower_t three = { {},0 };

	int from, to, buf=0;
	int result_deq=-1,result_inq = -1;

	tower_print(&one, &two, &three);

	while (1) {
		scanf_s("%d%d", &from, &to);
		//check balid
		if(from == 1)	        result_deq = deq_valid(&one, &buf);
		else if (from == 2)		result_deq = deq_valid(&two, &buf);
		else if (from == 3)		result_deq = deq_valid(&three, &buf);

		if (to == 1)	        result_inq = inq_valid(&one, buf);
		else if (to == 2)		result_inq = inq_valid(&two, buf);
		else if (to == 3)		result_inq = inq_valid(&three, buf);

		if (result_deq == 0 && result_inq == 0) {
			if (from == 1)			deq(&one, &buf);
			else if (from == 2)		deq(&two, &buf);
			else if (from == 3)		deq(&three, &buf);

			if (to == 1)			inq(&one, buf);
			else if (to == 2)		inq(&two, buf);
			else if (to == 3)		inq(&three, buf);
		}
		tower_print(&one, &two, &three);
	}
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
	else if (atower->cur < 3 && atower->q[atower->cur - 1] > plate) {
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

int tower_print(tower_t* tower_a, tower_t* tower_b, tower_t* tower_c) {
	system("cls");

	for(int i = 3; i >= 1; i--) {
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
