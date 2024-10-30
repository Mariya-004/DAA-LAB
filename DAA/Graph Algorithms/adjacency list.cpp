#include <iostream>
using namespace std;
class Node{
	private:
		int data;
		Node* link;
	public:
		Node(int data){
			this->data=data;
			link=NULL;
		}
		int get_vertices(){
			return data;
		}
		void set_link(Node* link){
			this->link=link;
		}
		Node* get_link(){
			return link;
		}
};
class List{
	private:
		Node* head;
	public:
		List(){
			head=NULL;
		}
		void insert(int ver){
			Node* node=new Node(ver);
			if (head==NULL){
				head=node;
			}
			else{
				Node* p=head;
				while(p->get_link()!=NULL){
					p=p->get_link();
				}
				p->set_link(node);
			}
		}
		void print(){
			Node* p=head;
			while(p!=NULL){
				cout<<p->get_vertices()<<" ";
							p=p->get_link();
			}
			cout<<endl;
		}
};
int main(){
	List l;
	cout<<"Enter the vertex:";
	int v;
	cin>>v;
	l.insert(v);
	cout<<"Enter the number of vertices connected to it:";
	int con;
	cin>>con;
	for (int i=0;i<con;i++){
		cout<<"Enter the vertex connected to"<<v<<":";
		int ver;
		cin>>ver;
		l.insert(ver);
	}
	l.print();

}
