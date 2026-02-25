/*
 * Автор: Синьков
 * Группа: gr12
 * Описание: Программа генерирует массив случайных чисел и подсчитывает
 *           количество чисел-палиндромов в массиве.
 *           Размер массива передается через аргумент командной строки.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Функция для проверки, является ли число палиндромом
bool is_palindrome(int number) {
		int original = number;
		int reversed = 0;
		int remainder;

		// Запоминаем знак числа и работаем с положительным числом
		if (number < 0) {
				return false; // Отрицательные числа не считаем палиндромами
		}

		// Переворачиваем число
		while (number > 0) {
				remainder = number % 10;
				reversed = reversed * 10 + remainder;
				number /= 10;
		}

		// Сравниваем с оригиналом
		return original == reversed;
}

// Функция для заполнения массива случайными числами
void fill_array_random(int arr[], int size) {
		for (int i = 0; i < size; i++) {
				arr[i] = rand() % 100000; // случайные числа от 0 до 99999
		}
}

// Функция для вывода массива
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

// Функция для подсчета палиндромов
int count_palindromes(int arr[], int size) {
		int count = 0;
		for (int i = 0; i < size; i++) {
				if (is_palindrome(arr[i])) {
						count++;
				}
		}
		return count;
}

// Функция для вывода всех палиндромов
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
		// Проверка аргументов командной строки
		if (argc < 2) {
				printf("Ошибка: не указан размер массива!\n");
				printf("Использование: %s <размер массива>\n", argv[0]);
				printf("Пример: %s 10\n", argv[0]);
				return 1;
		}

		// Получаем размер массива из аргументов
		int size = atoi(argv[1]);

		// Проверка корректности размера
		if (size <= 0) {
				printf("Ошибка: размер массива должен быть положительным числом!\n");
				return 1;
		}

		if (size > 1000) {
				printf("Предупреждение: слишком большой размер массива. Используйте <= 1000\n");
				return 1;
		}

		// Инициализация генератора случайных чисел
		srand(time(NULL));

		// Создание массива
		int array[size];

		// Заполнение массива случайными числами
		fill_array_random(array, size);

		// Вывод исходных данных
		printf("Исходные данные:\n");
		printf("Размер массива: %d\n", size);
		printf("Сгенерированный массив:\n");
		print_array(array, size);

		// Подсчет палиндромов
		int palindrome_count = count_palindromes(array, size);

		// Вывод результатов
		printf("\nРезультаты:\n");
		printf("Количество чисел-палиндромов: %d\n", palindrome_count);

		if (palindrome_count > 0) {
				print_palindromes(array, size);
		}

		return 0;
}