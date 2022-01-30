#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _matrix { //node
	unsigned rows;
	unsigned cols;
	char name;  // A-Z
	double* arr;
	struct matrix *next;
} matrix;

typedef struct _matrixList {
	matrix* head;
	struct _matrixList* next;
} matrixList;

void mainMenu(void);
void printMenu(void);
void matrixMenu(void);
matrix createMatrix(void);
int readOptions(void);
//void addMatrix2List(void);

int main(void) {
	mainMenu();
	return 0;
}

void mainMenu() {
	system("cls");
	printMenu();
	switch (readOptions()) {
	case 1:
		printf("This chapter is too complex! Come back later!");
		break;
	case 9:
		matrixMenu();
		break;
	default:
		printf("No such option exists!");
		break;
	}
	return;
}

void printMenu(void) {
	printf("Welcome to the Linear Algebra App!\n");
	printf("Please choose an option (1-9) to proceed:\n");
	printf("1) Complex Numbers\n");
	printf("9) Matrix\n");
	return;
}

int readOptions() {
	unsigned option = 0;
	char buff[21];
	do {
		printf("Option: ");
		fgets(buff, 20, stdin);
	} while (sscanf(buff, "%u ", &option) != 1);
	return option;
}

void matrixMenu() {
	system("cls");
	printf("| Matrix Menu |\n");
	printf("1) Add Matrix\n");
	printf("2) Delete Matrix\n");
	printf("3) Return to Main Menu\n");
	switch (readOptions()) {
		case 1:
			createMatrix();
			break;
		case 2:
			printf("ERROR!");
			break;
		case 3:
			mainMenu();
			break;
		default: // help
			break;
	}
}

// add matrix - size, values, allocate memory
// delete matrix - free memory
// print matrix - for loop
// print marix list (A-Z, 26 total) 
// matrix operations
// return to main menu
// help

matrix createMatrix(void) {
	matrix* tmp = (matrix*)malloc(sizeof(matrix));
	unsigned r, c;
	char buff[21];
	r = c = 0;
	if (tmp) {
		do {
			printf("Rows: ");
			fgets(buff, 20, stdin);
		} while (sscanf(buff, "%u ", &r) != 1);
		do {
			printf("Columns: ");
			fgets(buff, 20, stdin);
		} while (sscanf(buff, "%u ", &c) != 1);
		if (!tmp) {
			return;
		}
		tmp->rows = r;
		tmp->cols = c;
		tmp->arr = calloc(r * c, sizeof(double));
		printf("Enter the matrix values (by rows):\n");
		for (int i = 0; i < r * c; i++) {
			scanf("%lf", &tmp->arr[i]);
		}
		for (int i = 0; i < r * c; i++) {
			printf("%5.2lf ", tmp->arr[i]);
			if ((i+1) % c == 0)
				printf("\n");
		}
	}
	return *tmp;
}

void printMatrix(matrix* m) {

}

//void addMatrix2List(matrixList) {
//	if (matrixList == NULL) {
//		matrixList->head = martix;
//		matrix->name = 'A';
//		matrix->next = NULL;
//		return;
//	}
//	matrix* tmp = matrixList->head;
//	if (temp != NULL) {
//		t
//	}
//}
