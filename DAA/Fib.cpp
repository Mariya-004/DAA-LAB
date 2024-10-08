#include<iostream>
using namespace std;
int Fib(int n){
	if (n<=1){
		return 0;
	}
	if (n==2){
		return 1;
	}
	if (n>2){
		return Fib(n-1)+Fib(n-2);
	}
	return 0;
}
int main(){
	cout<<"Enter the the number of the fibannocci term you need to find out:";
	int t;
	cin>>t;
	cout<<"The "<<t<<"th fibanocci term is:"<<Fib(t)<<endl;
}
		