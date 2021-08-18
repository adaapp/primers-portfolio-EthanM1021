#include <fstream>

void phoneDirectory(void) {
  ifstream file;
  string name;
  string number;
  
  file.open("./include/phoneDirectory.csv");

  while(file >> name >> number) {
    getline(file, name);
    getline(file, number);

    std::cout << name;
    std::cout << number;
  }
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}