#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
  cerr << "SOMETHING" << endl;
  ifstream life("life.txt");
  if(!life){
    cerr << "Failed to open the file. \n";
    exit(1);
  }
  string line;
  vector<string> lines;
  while( life >> line){
    cout << "wrk" << endl;
    lines.push_back("|" + line + "|");
  }
  for(size_t i = 0; i < lines.size(); ++i){
    cout << lines[i] << endl;
  }

}

/*
int main() {
  ifstream life("life.txt");
  if(!life){
    cerr << "Failed to open the file. \n";
    exit(1);
  }
  string line;
  vector<string> lines;
  life >> line;
  int linelength =  line.size();
  lines.push_back( string(linelength + 2, '|'));
  lines.push_back("|" + line + "|");
  while( life >> line){
    lines.push_back("|" + line + "|");
  }
  lines.push_back( string(linelength + 2, '|')); 
  life.close();
  for(size_t i = 0; i < lines.size(); ++i){
    cout << lines[i] << endl;
  }
  for(size_t generation = 0; generation < 10; ++generation){
    
    for(size_t i = 1; i < lines.size()-1; ++i){
      for(size_t j = 1; j < lines[0].size(); ++j){
	
	int neighbor_count;
	neighbor_count = 0;

	//a cell can have neighbors
	//to the left
	if(lines[i][j-1] == '*'){	  neighbor_count++;	}
	
	//to the right
	if(lines[i][j+1] == '*'){	  neighbor_count++;	}

	//above
	if(lines[i-1][j] == '*'){	  neighbor_count++;	}

	//below
	if(lines[i+1][j] == '*'){	  neighbor_count++;	}

	//top left diagonal
	if(lines[i-1][j-1] == '*'){	  neighbor_count++;	}

	//top right diagonal
	if(lines[i-1][j+1] == '*'){	  neighbor_count++;	}

	//bottom left diagonal
	if(lines[i+1][j-1] == '*'){	  neighbor_count++;	}

	//bottom right diagonal
	if(lines[i+1][j+1] == '*'){	  neighbor_count++;	}

	//dead cell with 3 neighbors comes alive
	if( lines[i][j] == '-' && neighbor_count == 3){
	  lines[i][j] = '*';
	}

	//living cell 
	if( lines[i][j] == '*'){
	  //with less than 2 neighbors or with more than 3 neighbors, dies
	  if(neighbor_count < 2 || neighbor_count > 3){
	    lines[i][j] = '-';
	  }
	}
	
      }//line j
    }//lines i

    //print updated board
    cout << "Generation " << generation+1 << endl;
    for(size_t i = 0; i < lines.size(); ++i){
      cout << lines[i] << endl;
    }    
  }//10 generations

}

*/
