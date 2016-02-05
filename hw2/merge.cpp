#include <iostream>
#include <fstream>
#include <sstream>
#include <stddef.h>

using namespace std;

struct Node{
	int value;
	Node *next;
};
	




Node* merge(Node*& first, Node*& second){
	Node* temp = NULL;
	if(first->value > second->value){
		temp=second;
		if(second->next){
			temp->next=merge(first,second->next);
			second=NULL;
			return temp;
		}
		else{
			temp->next=first;
			second=NULL;
			first=NULL;
			return temp;
		}
    }
	else{
		temp=first;
		if(first->next){
			temp->next=merge(first->next,second);
			first=NULL;
			return temp;
		}
		else{
			temp->next=second;
			first=NULL;
			second=NULL;
			return temp;
		}
	}


};
/*
int main(){
	Node* head1=NULL;
	Node* head2=NULL;
	Node a,b,c,d,e,f,g;
	head1=&a;
	head2=&e;
	a.value=1;
	b.value=2;
	c.value=3;
	d.value=4;
	e.value=5;
	f.value=6;
	g.value=7;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	d.next=NULL;
	e.next=&f;
	f.next=&g;
	g.next=NULL;
	Node *final=merge(head1,head2);
	while(final->next){
		cout<<final->value<<endl;
		final=final->next;
	}
}
*/