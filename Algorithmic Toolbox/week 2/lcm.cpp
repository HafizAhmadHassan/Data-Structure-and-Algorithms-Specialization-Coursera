
#include <iostream>
long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;

	}
	else {
		long long r = a % b;
		return gcd(b, r);

	}
}
long long lcm(long long a, long long b) {
		return a*b/gcd(a, b);
}


int main() {
	long long a=0, b=0;

	std::cin >> a >> b;
	if ((a <= 2 * 10 ^ 9 && a >= 1) && (b <= 2 * 10 ^ 9 && b >= 1)) {

		std::cout << lcm(a, b) << std::endl;
		
	}

	system("pause");
	return 0;
}