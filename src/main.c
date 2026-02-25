/*
 * Автор: Синяков Глеб
 * Дата: 2026-02-25
 * Группа: gr12
 * Описание: Программа генерирует массив случайных чисел и подсчитывает
 *           количество чисел-палиндромов в массиве.
 *           Размер массива передается через аргумент командной строки.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool is_palindrome(int number) {
		int original = number;
		int reversed = 0;
		int remainder;

		if (number < 0) {
				return false;
		}

		while (number > 0) {
				remainder = number % 10;
				reversed = reversed * 10 + remainder;
				number /= 10;
		}

		return original == reversed;
}

void fill_array_random(int arr[], int size) {
		for (int i = 0; i < size; i++) {
				arr[i] = rand() % 100000;
		}
}

void print_array(int arr[], int size) {
		printf("[");
		for (int i = 0; i < size; i++) {
				printf("%d", arr[i]);
				if (i < size - 1) {
						printf(", ");
				}
		}
		printf("]\n");
}

int count_palindromes(int arr[], int size) {
		int count = 0;
		for (int i = 0; i < size; i++) {
				if (is_palindrome(arr[i])) {
						count++;
				}
		}
		return count;
}

void print_palindromes(int arr[], int size) {
		printf("Числа-палиндромы: ");
		int found = 0;
		for (int i = 0; i < size; i++) {
				if (is_palindrome(arr[i])) {
						printf("%d ", arr[i]);
						found++;
				}
		}
		if (found == 0) {
				printf("не найдены");
		}
		printf("\n");
}

int main(int argc, char *argv[]) {
		if (argc < 2) {
				printf("Ошибка: не указан размер массива!\n");
				printf("Использование: %s <размер массива>\n", argv[0]);
				printf("Пример: %s 10\n", argv[0]);
				return 1;
		}

		int size = atoi(argv[1]);

		if (size <= 0) {
				printf("Ошибка: размер массива должен быть положительным числом!\n");
				return 1;
		}

		if (size > 1000) {
				printf("Предупреждение: слишком большой размер массива. Используйте <= 1000\n");
				return 1;
		}

		srand(time(NULL));

		int array[size];

		fill_array_random(array, size);

		printf("Исходные данные:\n");
		printf("Размер массива: %d\n", size);
		printf("Сгенерированный массив:\n");
		print_array(array, size);

		int palindrome_count = count_palindromes(array, size);

		printf("\nРезультаты:\n");
		printf("Количество чисел-палиндромов: %d\n", palindrome_count);

		if (palindrome_count > 0) {
				print_palindromes(array, size);
		}

		return 0;
}