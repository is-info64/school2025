#include <iostream>

namespace stl {
template <typename T, typename Func>
void for_each(T* begin, T* end, Func f) {
	for(T* it = begin; it != end; ++it) {
		f(it);
	}
}
}

int main() {
	const int N = 5;
	int a[N] = {1,2,3,4,5};
	stl::for_each<int, void (int*)>(a, a + N, [](int* a) {
		std::cout << *a << ", ";
	});
	std::cout << "\n";
	stl::for_each<int>(a, a + N, [](int* a) {
		*a *= *a;
	});
	stl::for_each(a, a + N, [](int* a) {
		std::cout << *a << ", ";
	});
	std::cout << "\n";
	stl::for_each(a, a + N, [](int* a) {
		*a = 0;
	});
	stl::for_each(a, a + N, [](int* a) {
		std::cout << *a << ", ";
	});
	std::cout << "\n";
	
}
