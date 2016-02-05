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
	Node *tail=NULL;
	Node *mer=NULL;
	if(first.value>second.value){
		if(second->next){
			tail=merge(first,second->next);
			mer = first;
			mer->next = tail;
			first->next=NULL;
			return mer;
		}
		else{
			return first;
		}

	}
	else{
		if(first->next){
			tail=merge(first->next,second);
			mer = second;
			mer->next = tail;
			second->next=NULL;
			return mer;
		}
		else{
			return second;
		}
	}

}

int main(){
	Node a=0;
	Node b=0;
	Node c=0;
	Node d=0;
	a.value=1;
	a->next = b;
	b.value = 3;
	b->next = NULL;
	c.value=2;
	c->next = d;
	d.value = 4;
	d->next = NULL;
	Node *k= merge(a,d);
	cout << k->value;
}




