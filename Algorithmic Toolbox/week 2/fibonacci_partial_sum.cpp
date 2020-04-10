
#include <iostream>
#include <cassert>
using namespace std;

//detect zero followed by 1
long long period(long long n, long long m = 10) {

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
//F(m+2) - F(n+2) - 2 
//F(m + 2) - F(n + 2) - 2

//Literally, the sum of your upper bound m, minus the sum of your lower bound n
//I think we've teased you long enough, in particular with the hint about Binet (instead you should use linear algebra as hinted in your question). Also beware that The F(m+2) - F(n+2) - 2 isn't quite correct but you can figure it out given that the sum of fibo # to n is effectively F(n+2) -1 (hint: you want the sum inclusive of F(n) 
//and hence you need to substract the sum of fibo # up to n-1 and substract this from F(m+2) -2). Anyway... it looking and smelling like HOMEWORK, the SO community shouldn't help too much
long long fibonacci_sum2(long long n,long long m = 10) {

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

//long long fibonacci_partial_sum(long long k,long long n, long long m = 10) {
	// return (fibonacci_sum(n) - fibonacci_sum(k) ) %10;
	


	//long sum = 0;

	////Reduces very large numbers to manageable form
	//from = from % 60;
	//to = to % 60;
	////While this reduction if "to" is less than "from" it introduces errors, hence add 60 to it to make to>from for 
	////proper calculation of partial sum
	//if (to < from)
	//	to += 60;

	//long current = 0;
	//long next = 1;

	//for (long i = 0; i <= to; ++i) {
	//	if (i >= from) {
	//		sum += current;
	//	}

	//	long new_current = next;
	//	next = next + current;
	//	current = new_current;
	//}

	//return sum % 10;


//}

long long fibonacci_partial_sum(long long from, long long to) {
	long long sum = 0;

	// Simplify the input arguments, as the last digit pattern repeats with a period of 60, 
	// and the sum of 60 such consecutive numbers is 0 mod 10
	long long m = (long long)(from % 60); // pisanoLength(10) = 60
	long long n = (long long)(to % 60);

	// make sure n is greater than m
	if (n < m)
		n += 60;

	long long current = 0;
	long long next = 1;

	for (int i = 0; i <= n; ++i) {
		if (i >= m) {
			sum += current;
		}

		long long newCurrent = next;
		next = next + current;
		current = newCurrent;
	}

	return (long long)(sum % 10);
}





int main() {
	long long m = 0;

	long long k = 0;


	std::cin >> m >> k;

	// 1st
	if ((m >= 0 && m <= 10^14) && (k >= 0 && k <= 10^14)) {
		if (k >= m) {
			std::cout << fibonacci_partial_sum(m, k);
		}
	}

	system("pause");

	return 0;
}


/*
#include <iostream>
#include <cassert>
using namespace std;
//detect zero followed by 1
long long period(long long n, long long m = 10) {

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

long long fibonacci_partial_sum(long long n,long long k, long long m = 10) {
long long pr = -1;
if (n > m) {
if (m > 2) {
pr = n % period(n, m);
}
else {
if (m == 2) {
pr = 3;
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
if (n == 0 || m == 0) {

return 0;

}
else {
long long first = 0, second = 1;
long long save = (first + second) % m;
long long sum = 0;
for (long long i = 2; i <= pr; i++) {
save = (first + second) % m;
first = second;
second = save;

sum += save;

}
return (first*sum) % m;

}

}



int main() {
long long m = 0;

long long k = 0;


std::cin >> m >> k;

// 1st
if ((m >= 0 && m <= 10 ^ 14) && (k >= 0 && k <= 10 ^ 14)) {
if (k >= m) {
std::cout << fibonacci_partial_sum((m+1),k);
}
}

system("pause");

return 0;
}

long long period(long long n, long long m = 10) {

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

long long fibonacci_partial_sum2(long long m, long long n) {
if (m == 0 || n == 0) {
return 0;
}
else {
long long first = 0, second = 1;
long long save = 1;
long long sum = 1;
for (long long i = 2; i <= m; i++) {
save = (first + second) % 10;
first = second;
second = save;
}
sum = save;

for (long long i = (m + 1); i <= n; i++) {
save = (first + second) % 10;
first = second;
second = save;

sum = sum + save;
}
return sum % 10;
}
}
long long fibonacci_partial_sum3(long long n, long long k, long long m = 10) {
long long pr = -1;
if (n > m) {
if (m > 2) {
pr =  period(n, m);
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
if (n == 0 || m == 0) {

return 0;

}
else {
long long first = 0, second = 1;
long long save = 1;
long long sum = 1;
for (long long i = 2; i <= m; i++) {
save = (first + second) % 10;
first = second;
second = save;
}
sum = save;

for (long long i = (m + 1); i <= pr; i++) {
save = (first + second) % 10;
first = second;
second = save;

sum = sum + save;
}
return sum % 10;

}

}

long long fibonacci_partial_sum(long long n, long long k, long long m = 10) {
long long pr = -1;
if (n > m) {
if (m > 2) {
pr = n % period(n, m);
}
else {
if (m == 2) {
pr = 3;
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
if (n == 0 || m == 0) {

return 0;

}
else {
long long first = 0, second = 1;
long long save = (first + second) % m;
long long sum = 0;
for (long long i = 2; i <= pr; i++) {
save = (first + second) % m;
first = second;
second = save;
if (i >= n && i<=pr) {
sum += save;
}
}
return sum % m;

}

}


*/



/* 
Naive


long long fibonacci_partial_sum(long long m,long long n) {
	if (m == 0 || n == 0) {
		return 0;
	}
	else {
		long long first = 0, second = 1;
		long long save = 1;
		long long sum = 1;
		for (long long i = 2; i <= m; i++) {
			save = (first + second) % 10;
			first = second;
			second = save;
		}
		sum = save;

		for (long long i = (m + 1); i <= n; i++) {
			save = (first + second) % 10;
			first = second;
			second = save;
			
			sum = sum + save;
		}
		return sum % 10;
	}
}



int main() {
	long long n = 0;
	long long m = 0;


	std::cin >> m>>n;

	// 1st
	if ( (m >= 0 && m <= 10 ^ 14) && (n >= 0 && n <= 10 ^ 14)) {
		if (n >= m){
		std::cout << fibonacci_partial_sum(m,n);
		}
	}





	system("pause");

	return 0;
}
*/