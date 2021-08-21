#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <array>
#include <string>

std::vector<std::vector<std::string>> readFromCSV(std::string fileName) {
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

  std::vector<std::vector<std::string>> data = readFromCSV("./include/phoneDirectory.csv");
  int amountOfContacts = data.size();

  std::cout << "Searching " << amountOfContacts << " records...";

  formatContact(amountOfContacts, userInput, data);
}

int makes13(int number) {
  int counter = 0;

  while (counter + number != 14) {
    counter++;
  }
  return counter;
}

void formatPeople(std::vector<std::vector<std::string>> data, int i) {
  auto initial = data[i][0][0];
  auto surname = data[i][1];
  auto salary = data[i][2];
  std::string spacing;
  int longestSurname = 0;

  int numberOfSpaces = makes13(surname.length());
  spacing = std::string(numberOfSpaces, ' ');

  std::cout << initial << ".          ";
  std::cout << surname << spacing << "£";
  std::cout << salary << endl;
}

void dataFileParser() {
  std::string initialLines;
  std::string spaces;
  std::string surname;

  std::vector<std::vector<std::string>> data = readFromCSV("./include/employees.csv");
  int employeeSize = data.size();

  printf("Initial     Last          Salary\n");
  printf("--------    ----------    -------\n");

  for (int i = 0; i < employeeSize; i++) {
    formatPeople(data, i);
  }
}