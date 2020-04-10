#include <iostream>

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	
	}
	else {
		int r = a % b;
		return gcd(b,r);

	}
}

int main() {
	int a, b;
	
	std::cin >> a >> b;
	if( (a <=2*10^9 && a>=1 ) && (b <=2*10^9 && b >=1 )){
	
	std::cout << gcd(a, b) << std::endl;
	system("pause");
	}

	
	return 0;
}
