#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);

  int floors;
  int *floorsizes;
  string ***trojans;
  string curr;
  int **possessions;
  input >> floors;
  trojans = new string**[floors];
  possessions = new int*[floors];

  //you will need to keep track of how many people are on each floor.
  floorsizes = new int[floors];

  for (int i = 0; i < floors; i++) {
	  floorsizes[i] = 0;
	  trojans[i] = NULL;
	  possessions[i]=NULL;
  }
  while(getline(input, curr)) {
  	  cout << curr<<endl;
	  stringstream ss;
	  ss << curr;
	  ss >> curr;
	  if (curr == "MOVEIN") {
		  int i,k;
		  ss >> i;
		  ss >> k;
		  if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		  }
		  else {
		  	if(i > (floors-1)||i<0){ //the floor does not exist
		  		output<<"Error - floor "<<i<<" does not exist"<<endl;
		  	}
		  	else{
		  		if(floorsizes[i]!=0){  //if the floor is not empty
		  			output<<"Error - floor "<<i<<" is not empty"<<endl;
		  		}
		  		else{
		  			possessions[i] = new int[k];
		  			floorsizes[i] = k; //make the floorsize to be k
		  			trojans[i] = new string*[k];	//set trojans[i] to be a pointer of size k
		  		 	
		  			for(int m=0;m<k;m++){
		  				possessions[i][m]=0;
		  				trojans[i][m]=NULL;
		  			}
		  		}
		  	}
		  }
	  }
	  else if (curr == "MOVEOUT") {
	  	int i;
	  	ss >> i;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		}
		else{
			if(i > (floors-1)||i<0){ //if the size of floor is not in the range
		  		output<<"Error - floor "<<i<<" does not exist"<<endl;
		  	}
		  	else{
		  		if(floorsizes[i]==0){ //if the floor is emtpy, there is no one that needs to move out
		  			output<<"Error - floor "<<i<<" is empty"<<endl;
		  		}
		  		else{
		  			for(int j=0;j<floorsizes[i];j++){
		  				delete[] trojans[i][j]; //set the individual pointer point to nothing
		  			}
		  			delete[] trojans[i];
	  				delete[] possessions[i];
		  			floorsizes[i]=0;//and the size of floor would be 0
		  		}
		  	}

		}

	  }
	  else if (curr == "OBTAIN") {
	  	int i,j,k;
	  	ss >> i;
	  	ss >> j;
	  	ss >> k;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		}
		else{
	  		if(i > (floors-1)||i<0){
		  			output<<"Error - floor "<<i<<" does not exist"<<endl;
			}
			else{
				if(j>(floorsizes[i]-1)||j<0){
					output<<"Error - floor "<<i<<" does not have "<<j<<endl;
				}
				else{
					if(possessions[i][j]!=0){
						output<<"Error - "<<j<<" has possessions already"<<endl;
					}
					else{
						possessions[i][j]=k;
						trojans[i][j]=new string[k];
	  					string poss;
	  					stringstream str;
	  					while(ss>>poss)	{
	  						str << poss+" ";
	  					}
	  					for(int m=0;m<k;m++){
	  						str >> poss;
	  						trojans[i][j][m]=poss;
	  					}

					}
				}

			}

	  	}
	  }
	  else if (curr == "OUTPUT") {
	  	int i,j;
	  	ss>>i;
	  	ss>>j;
	  	if (ss.fail()) {
			  output << "Error - incorrect command" << endl;
		}
		else{
			if(i > (floors-1)||i<0){
		  			output<<"Error - floor "<<i<<" does not exist"<<endl;
			}
			else{
				if(j>(floorsizes[i]-1)||j<0){
					output<<"Error - floor "<<i<<" does not have "<<j<<endl;
				}
				else{
					if(possessions[i][j]==0){
						output<<"Error - "<<j<<" has no possessions"<<endl;
					}
					else{
						for(int m=0;m<possessions[i][j];m++){
							output << trojans[i][j][m];
						}
						output<<endl;
					}
			    }
			}
		}

	  }
	  else {
	  	output << "Error - Wrong command"<<endl;
	  }
  }
  for(int m = 0;m<floors;m++){
  	if(floorsizes[m]!=0){
  		for(int n=0;n<floorsizes[m];n++){
  			delete[] trojans[m][n];
  		}
  		delete[] trojans[m];
  		delete[] possessions[m];
  	}

  }
  delete[] possessions;
  delete[] trojans;
  delete[] floorsizes;
  input.close();
  output.close();
  return 0;
}




