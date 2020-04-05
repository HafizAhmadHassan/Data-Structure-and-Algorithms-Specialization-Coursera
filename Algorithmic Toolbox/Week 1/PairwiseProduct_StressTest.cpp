#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long MaxPairwiseProduct_fast(const std::vector<int>& numbers) {
	int n = numbers.size();
	int max_index1 = -1;

	for (int i = 0; i < n; ++i) {
		if ((max_index1 == -1) || (numbers[i] > numbers[max_index1])) {
			max_index1 = i;
		}
	}

	int max_index2 = -1;
	for (int j = 0; j < n; j++) {
		// problem Identified is corrected
		if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) {
			max_index2 = j;
		}

	}

	//cout << max_index1 << " " << max_index2 << "\n";
	return (long long)numbers[max_index1] * numbers[max_index2];
}


long long MaxPairwiseProduct(const std::vector<int>& numbers) {
	int max_product = 0;
	int n = numbers.size();

	for (int first = 0; first < n; ++first) {
		for (int second = first + 1; second < n; ++second) {
			if (((long long)numbers[first] * numbers[second]) > max_product)

				max_product = (long long)(numbers[first] * numbers[second]);
		}
	}

	return max_product;
}
int main() {
	// some other test:
	// checking time of two functions
	// n=1 
	//integer overflow
	// greek letter 



	while (true) {

	//	v1 = rand() % 100;         // v1 in the range 0 to 99
	//	v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
	//	v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014 


		// int n = rand() % 10 + 2; changing
		//int n = rand() % 4 + 2; again changing
		//int n = rand() % 100 + 2; changing
		int n = rand() % 1000 + 2;

			cout << n << "\n";
			vector <int> a;
			for (int i = 0; i < n; i++) {
				//a.push_back(rand() % 100000); change
				//a.push_back(rand() % 10); again changing 
				a.push_back(rand() % 100000);
			
			}
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			
			}
			cout << "\n";

			long long res1 = MaxPairwiseProduct(a);
			long long res2 = MaxPairwiseProduct_fast(a);

			if (res1 != res2) {
				cout << "Wrong Answer : " << res1 << " " << res2 << endl;
				break;
			}
			else {
			
				cout << "OK";
			}

	}



	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	std::cout << MaxPairwiseProduct_fast(numbers) << "\n";
	system("pause");
	return 0;
}
