#include<iostream>
using namespace std;
class Array{
	int LB,UB;
	int A[100];
	public:
	Array(int u){
		LB=0;
		UB=u;
		for (int i=LB;i<UB;i++){
			cout<<"Enter the element:";
			int a;
			cin>>a;
			A[i]=a;
		}
	}
	void display(){
		cout<<"The array is:";
		for (int i=LB;i<UB;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
		
	void LinearSearch(int x){
		int i=LB; 
			for (i=LB;i<UB;i++){
				if (A[i]==x){
					cout<<"Element found at index:"<<i<<endl;
					
				}
			}
			if (i>=UB){
				cout<<"Element not found"<<endl;
			}

	}
};
int main(){
Array a(3);
a.display();
cout<<"Enter the element to search for:";
int el;
cin>>el;
a.LinearSearch(el);
return 0;
}

			
	
