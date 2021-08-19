#include <fstream>

void phoneDirectory(void) {
  ifstream fin;
    string line;
    // Open an existing file
    fin.open("./include.phoneDirectory.csv");
     while(!fin.eof()){
                fin>>line;
            cout<<line<<" ";
            }
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}