#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;
struct weightValuePair
{
	int weight, value;
	double vw;
};
double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<weightValuePair> wvp,double val=0.0,int index=0) {
  
  if (capacity <= 0 || index>= weights.size()) {
	  return val;
  
  }
  else {
	  if (index < weights.size()) {
		  // for (int i; i < weights.size(); i++) {
		  //	  perunit[i]
		  //  }
		  if (wvp[index].weight <= capacity) {
			  //take whole
			  val = val + wvp[index].value;
			  capacity = capacity - wvp[index].weight;

		  }
		  else {
			  //fraction
			  if (wvp[index].weight > capacity) {
				  val = val + wvp[index].vw*capacity;
				  capacity = capacity - capacity;
			  }

		  }

		  index = index + 1;
		  return val = get_optimal_value(capacity, weights, values, wvp, val, index);
	  }
  }
  // write your code here

  
}

int main() {
  int n;
  int capacity;
  //Constraints. 1 ≤ n ≤ 103, 0 ≤ W ≤ 2·106; 0 ≤ vi ≤ 2·106, 0 < wi ≤ 2·106 for all 1 ≤ i ≤ n.All the numbers are integers.
  
  std::cin >> n >> capacity;
  if (!(n <= 10 ^ 3 && n >= 1) && (capacity <= 2 * 10^6 && capacity>=0)) {
	  system("pause");
	  return 0;
  }

  vector<int> values(n);
  vector<int> weights(n);

  vector<int> perunit(n);

  vector<weightValuePair> triplets;

  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
	if (!(values[i] <= 2 * 10^6 && values[i] >= 0) && !(weights[i] <= 2 * 10^6 && weights[i] >= 0)) {
		system("pause");
		return 0;
	}
	weightValuePair * k= new weightValuePair();

	k->weight = weights[i];
	k->value = values[i];
	k->vw = values.at(i) * 1.0 / weights.at(i);
	triplets.push_back(*k);
	delete k;


  }
  // Sort the vector in descending order 
  std::sort(triplets.begin(), triplets.end(), [](const weightValuePair &a, const weightValuePair &b) -> bool {
	  return a.vw > b.vw;
  });


 

  
  double optimal_value = get_optimal_value(capacity, weights, values,triplets);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  system("pause");
  return 0;
}
