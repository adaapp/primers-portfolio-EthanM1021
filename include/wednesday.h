#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

std::vector<std::vector<std::string>> readFromCSV() {
  std::string fileName = "./include/phoneDirectory.csv";
  std::ifstream file(fileName);

  std::string line;
  std::vector<std::vector<std::string>> records;

  while(getline(file, line)) {
    std::stringstream stream(line);
    std::string field;
    std::vector<std::string> rowList;

    while(getline(stream, field, ',')) {
      rowList.push_back(field);
    }

    records.push_back(rowList);
  }

  file.close();
  return records;
}

void formatContact(int n, string userInput, std::vector<std::vector<std::string>> data) {
  bool record = false;

  for (int col = 0; col < n; col++) { 
    for (int row = 0; row < n; row++) {
      if (userInput == data[col][row]) {
        std::cout << "\n\nContact details:\n" << data[col][0] << ", T: " << data[col][1] << std::endl;
        record = true;
      }
    }
  }
  if (record == false) {
    std::cout << "Sorry, no contact details found\n"; 
  }
}

void phoneDirectory(void) {
  string userInput;

  std::cout << "\nEnter a name or number to search: ";
	getline(std::cin, userInput);

  std::vector<std::vector<std::string>> data = readFromCSV();
  int amountOfContacts = data.size();

  std::cout << "Searching " << amountOfContacts << " records...";

  formatContact(amountOfContacts, userInput, data);
}


void dataFileParser() {
}
