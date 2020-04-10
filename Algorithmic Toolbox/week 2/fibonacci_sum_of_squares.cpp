#include <iostream>
#include <cassert>

//detect zero followed by 1

long long fibonacci_sum_of_squares(long long n) {
	/*if (n <= 1) {
		return n;
	}
	else {
		long long first = 0, second = 1;
		long long save = 1;
		long long f = 1;
		for (long long i = 2; i <= n%60; i++) {
			save = (first + second);
			first = second;
			second = save;
		}
		first = 0, second = 1;
		f=save;

		for (long long i = 2; i <= (n + 1)%60; i++) {
			save = (first + second);
			first = second;
			second = save;
		}
		return (f*save) % 10;
	}*/
	
	if (n <= 1)
		return n;

	long long *fibo = new long long[60 + 2];
	fibo[0] = 0, fibo[1] = 1;


	// Add remaining terms 
	int i;
	for (i = 2; i <= (n+1) % 60; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2])%10;
	}

	long long c = (fibo[i - 1] * fibo[i-2])%10;
	delete[] fibo;
	return c;
}



int main() {
	long long n = 0;
	

	std::cin >> n;

	// 1st
	if (n >= 0 && n <= 10 ^ 14) {
	
			std::cout << fibonacci_sum_of_squares(n);
	}





	system("pause");

	return 0;
}