#include <iostream>
#include <cassert>

int fibonacci_last_digit(int n) {
	// write your code here
	int * fib = new int[n + 1];
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
	}
	int a = fib[n];
	delete[] fib;
	return a;
}
int main() {
	int n = 0;

	std::cin >> n;

	// 2nd
	if (n >= 0 && n <= 10^7) {
	std::cout << fibonacci_last_digit(n);

	}
	



	//	std::cout << fibonacci_naive(n) << '\n';
	system("pause");

	return 0;
}
