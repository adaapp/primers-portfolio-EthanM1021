#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <array>
#include <string>

// function to read a csv file line by line
std::vector<std::vector<std::string>> readFromCSV(std::string fileName) {
  std::ifstream file(fileName);

  std::string line;
  std::vector<std::vector<std::string>> records;

  // while there is things to read, carry on
  while(getline(file, line)) {
    std::stringstream stream(line);
    std::string field;
    std::vector<std::string> rowList;

  // while there is still a comma, push that field into the vector above
  // third parameter is a delimiter
    while(getline(stream, field, ',')) {
      rowList.push_back(field);
    }

    records.push_back(rowList);
  }
  // line 16 will eventually return false so it closes the file
  file.close();
  // returns the vector of strings with the records we need...
  return records;
}

// function to format the output to the console
void formatContact(int n, string userInput, std::vector<std::vector<std::string>> data) {
  // flag to deal with if contacts were found
  bool record = false;

  // nested for loop to loop through through each field of each column
  for (int col = 0; col < n; col++) { 
    for (int row = 0; row < n; row++) {
      // if the name that user entered is in the csv file carry on
      if (userInput == data[col][row]) {
        std::cout << "\n\nContact details:\n" << data[col][0] << ", T: " << data[col][1] << std::endl;
        record = true;
      }
    }
  }
  // if no records were found
  if (record == false) {
    std::cout << "Sorry, no contact details found\n"; 
  }
}

void phoneDirectory(void) {
  string userInput;

  std::cout << "\nEnter a name or number to search: ";
	getline(std::cin, userInput); // stores userInput

  // calls readFromCSV and stores is a nested vector of strings
  std::vector<std::vector<std::string>> data = readFromCSV("./include/phoneDirectory.csv");
  int amountOfContacts = data.size();

  // data.size() will get the amount of contacts in this case
  std::cout << "Searching " << amountOfContacts << " records...";

  // calls function to then output what is needed to the user
  formatContact(amountOfContacts, userInput, data);
}

// function that returns the amount of spacing after the last name to make console look correct
int makes13(int number) {
  int counter = 0;

  while (counter + number != 14) {
    counter++;
  }
  return counter;
}

void formatPeople(std::vector<std::vector<std::string>> data, int i) {
  char initial = data[i][0][0]; // gets first initial of each employee
  std::string surname = data[i][1]; // gets surname of employee
  std::string salary = data[i][2]; // gets salary of employee
  std::string spacing;

  int numberOfSpaces = makes13(surname.length()); // calls makes13 with the int of the length of the surname
  spacing = std::string(numberOfSpaces, ' ');
  // i.e produces a string of spaces with the integer of whatever numberOfSpaces is

  // formats the data in the console
  std::cout << initial << ".          ";
  std::cout << surname << spacing << "£";
  std::cout << salary << endl;
}

void dataFileParser() {
  std::vector<std::vector<std::string>> data = readFromCSV("./include/employees.csv");
  int employeeSize = data.size();

  printf("Initial     Last          Salary\n");
  printf("--------    ----------    -------\n");

  // loops through each employee and passes their index in the vector to the formatPeople function
  for (int i = 0; i < employeeSize; i++) {
    formatPeople(data, i);
  }
}