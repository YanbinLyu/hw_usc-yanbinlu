#include "llistint.h"
#include <iostream>

using namespace std;
int main() {
	LListInt * list = new LListInt();
 	list->insert(0, 3);
  	//insert an item to the empty list. 

  	if (list->size() == 1) {
    	cout << "SUCCESS: List has size 1 after one insertion." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}

	if (list->get(0) == 3) {
    	cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    	cout << " is instead." << endl;
  	}

  	list->insert(1,4);
  	//insert an item at the valid location SIZE
  	//the tail will be changed and the size would be changed to 2
  	if (list->size() == 2) {
    	cout << "SUCCESS: List has size 2 after one insertion." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	//the second item will have the value 2;
  	if (list->get(1) == 4) {
    	cout << "SUCCESS: 4 is at the 1st index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 4 is not at the 1st index of the list, " << list->get(1);
    	cout << " is instead." << endl;
  	}

  	list->insert(1,5);
  	//add one item at the location between 0 to Size-1
  	if(list->size() == 3){
  		cout << "SUCCESS: List has size 3 after one insertion." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}

  	if (list->get(1) == 5) {
    	cout << "SUCCESS: 5 is at the 1st index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 5 is not at the 1st index of the list, " << list->get(1);
    	cout << " is instead." << endl;
  	}
  	//5 should be the new value of the 1st index
  	if (list->get(2) == 4) {
    	cout << "SUCCESS: 4 is at the 2nd index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 4 is not at the 2nd index of the list, " << list->get(2);
    	cout << " is instead." << endl;
  	}
  	//4 would be pushed to the next position at the 2nd.
	//the substitution is successful.

	list->insert(5,4);
	list->insert(-2,4);
	//insert an item to the array at the location out of valid range
	if(list->size() == 3){
  		cout << "SUCCESS: List has size 3 after two insertion." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}

	list->remove(1);
	//delete the item in location 1 in the valid range
	if(list->size() == 2){
  		cout << "SUCCESS: List has size 2 after one remove." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	//the size should be 2 now.

	if (list->get(1) == 4) {
    	cout << "SUCCESS: 4 is at the 1st index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 4 is not at the 1st index of the list, " << list->get(1);
    	cout << " is instead." << endl;
  	}
  	//the item with value 4 will substitute the value at location 1 before

  	list->remove(4);
  	list->remove(-2);
  	//delete the item at the location out of the valid range
  	if(list->size() == 2){
  		cout << "SUCCESS: List has size 2 after one remove." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	//the size should keep 2 now.

  	list->insert(2,5);
  	//insert item with value 5 to the list.
  	list->remove(2);
  	//remove the last item(boundary)
  	if(list->size() == 2){
  		cout << "SUCCESS: List has size 2 after one remove." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	//the last item is removed and the size will become 2
  	if (list->get(1) == 4) {
    	cout << "SUCCESS: 4 is at the 1st index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 4 is not at the 1st index of the list, " << list->get(1);
    	cout << " is instead." << endl;
  	}

  	list->insert(2,5);
  	list->remove(0);
  	//remove the first boundary item
  	//the rest items should move left by one spot
  	if(list->size() == 2){
  		cout << "SUCCESS: List has size 2 after one remove." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	//the first item is removed and the size will become 2
  	if (list->get(1) == 5) {
    	cout << "SUCCESS: 5 is at the 1st index of the list." << endl;
  	} 
  	else {
    	cout << "FAIL: 5 is not at the 1st index of the list, " << list->get(1);
    	cout << " is instead." << endl;
  	}
  	list->clear();
  	if(list->size() == 0){
  		cout << "SUCCESS: List has size 0 after one clear." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	list->remove(0);
  	if(list->size() == 0){
  		cout << "SUCCESS: List has size 0 after one clear." << endl;
  	} 
  	else {
    	cout << "FAIL: List has size " << list->size() << " after one insertion.";
    	cout << endl;
  	}
  	delete list;
  	return 0;
}