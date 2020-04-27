#include <iostream>
using namespace std;
int coins[] = { 1,5,10 };

int get_change(int m,int count=0) {
  //write your code here
	if (m == 0) {
		return count;

	}else{
	for (int i = 0; i < 3; i++) {
	if(m<coins[i]){
		m = m - coins[i-1];

		count = count + 1;
		//std::cout << "coins =" << coins[i] <<" count = " << count <<" m= "<< m<< endl;
		return get_change(m,count++);
	}
	else {
		if (m == coins[i]) {
			m = m - coins[i];
			
			count = count + 1;

			//std::cout<<"coins ="<<coins[i] << " count = " << count << " m= " << m << endl;
		return get_change(m, count++);
		}
		else {
			if (m > coins[2]) {
				m = m - coins[2];
				count = count + 1;
				//std::cout << "coins =" << coins[2] << " count = " << count << " m= " << m << endl;
				return get_change(m, count++);

			}
		
		}
		
	}
	
	}
	}
}

int main() {
  int m;

  std::cin >> m;
  
  if (m <= 10 ^ 3 && m >= 1)
  {
	  std::cout << get_change(m) << '\n';
  }
  system("pause");
  return 0;
  }
