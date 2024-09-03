#include <iostream>
using namespace std;
int sharik(int N) {
	int j = 1;
	if (N == 1){
		return 1;
	}
	else if (N == 2) {
		return 1;
	}
	else if (N > 2) {
		return (sharik(N - 1) + sharik(N - 2)) * (N - 1);
	}
}
int factorial(int N) {
	int j = 1;
	for (int i = 1; i <= N;i++) {
		j *= i;
	}
	return j;
}
int main() { 
	int N, t,k;
	cin>> N;
	cout << sharik(N);
}