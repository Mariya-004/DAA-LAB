#include<iostream>
using namespace std;
void insertion(int A[],int len){
	int i=1;
	while(i<len){
		int j=i-1;
		int key=A[i];
		while (j>=0 and A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		i++;
	}
}
int main(){
	int A[4]={5,2,1,9};
	insertion(A,4);
	for (int i=0;i<4;i++){
		cout<<A[i]<<" ";
	
	}
	cout<<endl;
}
		

			
	
		
