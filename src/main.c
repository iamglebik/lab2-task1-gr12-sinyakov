#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
		if (argc < 2) {
				printf("Использование: %s <размер массива>\n", argv[0]);
				return 1;
		}
		int size = atoi(argv[1]);
		printf("Размер массива: %d\n", size);
		return 0;
}