
//detect zero followed by 1
#include <iostream>
#include <cassert>
using namespace std;
//detect zero followed by 1
long long period(long long n, long long m=10) {

	long long first = 0, second = 1;
	long long save = (first + second) % m;
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


// Sum of nth Fibonacci series = F(n+2) -1
// Then pisano period of module 10 = let n + 2 mod(60) = m then find F(m) mod(10) - 1
long long fibonacci_sum(long long n, long long m = 10) {

	long long first = 0, second = 1, pr = -1;
	long long save = -1;
	if (n == 0) {
		return first;
	}

	save = (first + second) % m;
	long long sum = save;
	if (n < m) {
		pr = 60;

	}
	else {
		pr = period(n);

	}
	n = (n + 2) % pr;
	long long * fib = new long long[n + 1];
	fib[0] = 0;
	fib[1] = 1;
	long long res = 1;
	for (int i = 2; i <= n; i++) {
		fib[i] = (fib[i - 1] % 10 + fib[i - 2] % 10) % 10;
		// res = res + fib[i];
	}
	// cout<<fib[n]<<"\n";
	if (fib[n] == 0) {
		return 9;
	}
	return (fib[n] % 10 - 1);


}


int main() {
	long long n = 0;
	

	//1 ≤ n ≤ 1014, 2 ≤ m ≤ 103. 

	std::cin >> n;

	// 1st
	if ((n >= 0 && n <= 100000000000000)) {
		std::cout << fibonacci_sum(n);

	}





	//	std::cout << fibonacci_naive(n) << '\n';
	system("pause");
	//test_solution();
	//std::cout << fibonacci_fast(n) << '\n';
	return 0;
}


/*
long long fibonacci_sum(long long n, long long m=3) {

long long first = 0, second = 1, pr=-1;
long long save=-1;
if (n == 0) {

return first;
}

save = (first + second) % m;
long long sum = save;
if (n < m) {
pr = n;

}
else {
pr = period(n);
}

for (long long i = 2; i <= pr; i++) {
save = (first + second) % m;
first = second;
second = save;
sum += save;

}
// result after division
cout << "\n sum 1st == " << sum;
int d = n / pr;
cout << "\n value of d " << d<<endl;
if (d == 0) {
cout << "\n True";
return sum;
}
else {
if (d >= 1) {
sum = (d*(sum));
}
cout << "\n sum 2nd " << sum;

}
//calculating remainders in period
int r = n % pr;

cout << "\n remainder ==  " << r<<endl;

if (r == 0) {
return sum  ;

}
else {

if (r == 1) {
return (sum + 1);

}
else {
first = 0;
second = 1;
save = (first + second) % m;
sum += save;
for (long long i = 2; i <= (r+1); i++) {
save = (first + second) % m;
first = second;
second = save;
sum += save;

cout << "\n sum" << sum;
}

cout << "\n sum 3rd " << sum;
return sum;
}

}




}
*/

/*

long long fibonacci_sum(long long n) {
	if (n == 0) {
		return 0;
	}
	else {
		long long first = 0, second = 1;
		long long save = (first + second) % 10;
		long long sum = 1;
		for (long long i = 2; i <= n; i++) {
			save = (first + second) % 10;
			first = second;
			second = save;
			sum += save;
		}
		return sum % 10;
	}
}



int main() {
	long long n = 0;


	
	std::cin >> n;

	// 1st
	if (n >= 0 && n <= 10^14) {
		
		std::cout << fibonacci_sum(n);

	}





	system("pause");
	
	return 0;
}

*/