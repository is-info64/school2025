#include <algorithm>
#include <iostream>

int main() {
	const int N = 10;
	int arr[] = {1, 2, 3, 4, -5, 3, -7, -8, 9, 0};

	// 1 Output all elements on the screen
	std::for_each<int*>(arr, arr + N, [](const int& a) {
		std::cout << a;
	});
	std::cout << std::endl;

	// 2 Count elements of array that equals to 3
	std::cout << std::count(arr, arr + N, 3) << std::endl; // 2
	// Count char 'l' int string
	std::string s = "Hello, world!";
	std::cout << std::count(s.begin(), s.end(), 'l') << std::endl; // 3
	// 3 count_if positive elements (predicate)
	std::cout << std::count_if(arr, arr + N, [](const int& a) { return a > 0; }) << std::endl; // 6
	
	// 4 min element
	int* min = std::min_element(arr, arr + N);  // -8
	std::cout << "min_el = arr[" << min - arr << "]: " << *min << std::endl;
	
	// 5
	int b = std::max(10, 15); // 15
	
	// 6
	int c = 5, d = 6;
	std::swap(c, d);
	std::cout << c << d << std::endl; // 6 5
	
	// 7 accumulate (operation_func) sum all elements of array
	std::accumulate(arr, arr + N, 0, [](const int& acc, const int& el) {
		return acc + el;
	});
	
	// 8 Sort (comparator) Ascending
	std::sort(arr, arr + N, [](const int& curr, const int& next) {return curr < next; });
	std::for_each<int *>(arr, arr + N, [](const int& a) {
		std::cout << a << " ";
	});
	
	// 8 Sort Descending
	std::sort(arr, arr + N, [](const int& curr, const int& next) {return curr > next; });
	std::for_each<int *>(arr, arr + N, [](const int& a) {
		std::cout << a << " ";
	});
	
	// 9
	std::reverse(a, a + N);

	// 10 other
	/*
		find, find_if,
		replace, replace_if,
		remove, remove_if,
		search, search_if

		MORE FUNCTIONS: 
		https://en.cppreference.com/w/
		https://en.cppreference.com/w/cpp/algorithm
		Algorithm library
	*/
	
	//int arr[] = {1, 2, 3, 4, -5, 3, -7, -8, 9, 0};
}












