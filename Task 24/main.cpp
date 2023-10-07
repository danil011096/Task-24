#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T>
void fill_arr(T arr[], const int length, int left, int rigth ) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (rigth - left) + left;
}
template <typename T>
void print_arr(T arr, const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

//Задание 2.
void resize_arr(int*& arr, int size, int new_size) {
	int* new_arr = new int[new_size]; 
	int min_size = (size < new_size) ? size : new_size; 

	for (int i = 0; i < min_size; i++) {
		new_arr[i] = arr[i];
	}

	delete[] arr;
	arr = new_arr; 
}

int main() {
	setlocale(LC_ALL, "Russian");

	//Задание 1.

	int n, m;
	std::cout << "Введите длины массивов -> ";
	std::cin >> n >> m;
	int* arr1 = new int[n];
	int* arr2 = new int[m];
	fill_arr(arr1, n, 18, 98);
	print_arr(arr1, n);
	fill_arr(arr2, m, 45, 86);
	print_arr(arr2, m);

	int* arr3 = new int[n + m];
	for (int i = 0; i < n; i++)
		arr3[i] = arr1[i];
	for (int i = n; i < n + m; i++)
		arr3[i] = arr2[i - n];
	
	print_arr(arr3, n + m);
	delete[] arr1;
	delete[] arr2;

	//Задание 2.

	int* arr4 = new int[10];
	resize_arr(arr4, 10, 15);

	return 0;
}