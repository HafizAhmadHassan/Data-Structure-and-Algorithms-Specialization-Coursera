

#include <iostream>
#include <cassert>
using namespace std;
//detect zero followed by 1
long long period(long long n, long long m) {
	
		long long first = 0, second = 1;
		long long save = (first+second) % m;
		for (int i = 2; i <= n; i++) {
			save = (first + second) % m;
			first = second;
			second = save;
			if (first == 0 && second == 1) {
				return i - 1;

			}
		}
		return n;

}

long long huge_fibonacci(long long n, long long m) {
	long long pr = -1;
	if (n > m) {
		if (m > 2) {
			pr = n % period(n, m);
		}
		else {
			if (m == 2) {
				pr = n % 3;
		
			}
			else {
				if (m == 1) {
					pr = n;
				}

			}

		}
	}
	else {
		pr = n;
	}


	if (n == 0 || m == 0 || pr == 0) {
	
		return 0;
	
	}
	else {
		long long first = 0, second = 1;
		long long save = (first + second) % m;;
		for (long long i = 2; i <= pr; i++) {
			save = (first + second) % m;
			first = second;
			second = save;
		}
		return save%m;

	}
	
}



int main() {
	long long n = 0;
	long long m = 0;

	//1 ≤ n ≤ 1014, 2 ≤ m ≤ 103. 
	
	std::cin >> n >> m;

	// 1st
	if ( (n >= 0 && n<= 100000000000000) && (m <= 1000 && m > 0)) {
		std::cout << huge_fibonacci(n,m);

	}





	//	std::cout << fibonacci_naive(n) << '\n';
	system("pause");
	//test_solution();
	//std::cout << fibonacci_fast(n) << '\n';
	return 0;
}


/*


long long huge_fibonacci(long long n,long long m) {
// write your code here
long long len = 0;
if (m == 1) {
len = 1;
}
else {
if (m == 2) {
len = 3;
}

}
len = 1;
long  long * fib = new long long[n + 1];
fib[0] = 0;
fib[1] = 1;
int br = 1;
int zerocount = 0;
for (long long i = 2; i <= n && br == 1; i++) {
fib[i] = (fib[i - 1] + fib[i - 2])% m;
if (fib[i] != 0) {
len++;
}
else {
if (fib[i] == 0) {
len++;
zerocount++;
if(zerocount==2){
br = 0;
}


}
}
}

std::cout << "\n length = " << len;

std::cout << "\n remainder = " << n % len;
long long a = -1;

if ((n % len) != 0) {
a = fib[n % len] % m;

}
else {
a = fib[n] % m;
}
delete[] fib;
return a;
}
*/