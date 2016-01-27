/**
 * print the text line by line with reverse order
 Name: Yanbin Lu
 ID: 4042942514
 */

#include <iostream>
#include <sstream>
#include <cstring> 
#include <fstream> 
#

using namespace std;


int main(int argc, char* argv[]){
	char* file = argv[1]; //read the file name
	ifstream ifile (file); 
	if(ifile.fail()){
		cout << "Couldn't open file" << endl;
		return 1;
	}
	int n;
	ifile >> n; //read how many words totally	
	string line;
	string word;
	int* length=new int[n];
	int m=0;
	stringstream ss;
	char** list = new char*[n]; //create a double char pointer
	for(int i= 0;i<n;i++){
		list[i]=NULL;
	}
	while(getline(ifile, line)){
		ss<<line+" ";//save the string in the stringstream
	} 
	while(ss >> word){
		int len = word.length();
		list[m]=new char[len]; //set the pointer point to the known length char array
		for(int i=0;i<len;i++){
			list[m][i] = word[i];//save the word in the array(string)
		}
		length[m]=len;
		m++;
	}

	for(int i=0; i<n; i++){
		for(int j=0;j<length[n-i-1];j++){
			cout << list[n-i-1][j];//cout the words in reverse order 
		}
		cout << endl;
	}
	for(int i=0; i<n; i++){
		delete[] list[i]; //deallocate
	}
	delete[] list;
	delete[] length;
	ifile.close();

	return 0;
}


