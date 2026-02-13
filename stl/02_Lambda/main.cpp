#include <iostream>
// ========== 1
/*
int sum_el(int* arr, int N, bool (*separate)(int)) {
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if(separate(arr[i])){
			sum += arr[i];
		}
	}
	
	return sum;
}

bool separate_even(int a) {
	return a % 2 == 0;
}

bool separate_odd(int a) {
	return a % 2 != 0;
}

int main() {
	int a[5] = {1,2,3,4,5};
	std::cout << sum_el(a, 5, separate_even) << "\n";
}
*/

// ============= 2
/*
template <typename T, typename Func>
T sum_el(T* arr, size_t N, Func separate) { // Func =  bool (*separate)(T) <- указатель на функцию
	T sum = 0;
	for (size_t i = 0; i < N; ++i) {
		if(separate(arr[i])){
			sum += arr[i];
		}
	}
	
	return sum;
}

bool separate_even(int a) {
	return a % 2 == 0;
}

bool separate_odd(int a) {
	return a % 2 != 0;
}

int main() {
	int a[5] = {1,2,3,4,5};
	std::cout << sum_el(a, 5, separate_even) << "\n";
}*/

// ============= 3
/*
template <typename T, typename Func>
T sum_el(T* arr, size_t N, Func separate) { // Func =  bool (*separate)(T) <- указатель на функцию
	T sum = 0;
	for (size_t i = 0; i < N; ++i) {
		if(separate(arr[i])){
			sum += arr[i];
		}
	}
	
	return sum;
}

int main() {
	int a[5] = {1,-2,3,4,-5};
	std::cout << sum_el(a, 5, [](int a) {
			if (a > 0) {
				return true;
			} 
			
			return false;
		}) << "\n";
}
*/

// ============= 3
/*
 определить  сумму четных либо нечетных элементов в зависимости от флага isEven 
 и их количество
 */
template <typename T, typename Func>
T sum_el(T* arr, size_t N, Func separate) { // Func =  bool (*separate)(T) <- указатель на функцию
	T sum = 0;
	for (size_t i = 0; i < N; ++i) {
		sum += separate(arr[i]);
	}
	
	return sum;
}

int main() {
	int a[5] = {1,2,3,4,5};
	bool isEven = false;
	/*if(isEven) {
		std::cout << sum_el(a, 5, [](int a) { return a % 2 == 0 ? a : 0; }) << "\n";
	}
	else {
		std::cout << sum_el(a, 5, [](int a) { return a % 2 != 0 ? a : 0; }) << "\n";
	}*/
	
	int cnt = 0;
	std::cout << sum_el(a, 5, [isEven, &cnt](int a) { // захват по значению и по ссылке
			if(isEven) {
				if (a % 2 == 0) {
					++cnt;
					return a;
				}
				
				return 0;
			} 
			else {
				if (a % 2 != 0) {
					++cnt;
					return a;
				}
				
				return 0;
			}
		}) << "\n";
		
		std::cout << "count: " << cnt << "\n";
}
