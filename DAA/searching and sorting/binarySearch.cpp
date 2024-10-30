#include<iostream>
using namespace std;
int binarySearch(int A[],int key,int lb,int ub){
	
	int ind=-1;
	if (lb<ub){
	int mid=(lb+ub)/2;
	if (A[mid]== key){
		return mid;
	}
	if (A[mid]>key){
		ub=mid-1;
		return binarySearch(A,key,lb,ub);
	}
	else if (A[mid]<key){
		lb=mid+1;
		return binarySearch(A,key,lb,ub);
	}

	}
	return ind;
		if(lb>ub){
		cout<<"NOT FOUND"<<endl;
	}

}
int main(){
	int A[5]={1,2,3,4,5};
	cout<<binarySearch(A,0,0,5)<<endl;
	}
