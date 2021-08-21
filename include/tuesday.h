#include <list>

// function to see if characters are a number
int isNumber(string password) { 
  int number = 0; // initialise number to 0 to coutn how many numbers are in the password

  for (int i = 0; i < password.length(); i++) {
    if (isdigit(password[i])) {
      number += 1; // if char is number, add 1 to number 
    }
  }

  return number; // returns amount of numbers in password
}

// function to see if characters are a letter
int isLetter(string password) {
  int letter = 0;

  for (int i = 0; i < password.length(); i++) {
    if (isalpha(password[i])) {
      letter += 1;
    }
  }

  return letter;
}

// function to see if characters are neither letter/number
int isSpecial(string password) {
  int special = 0;

  for (int i = 0; i < password.length(); i++) {
    if (!isalpha(password[i]) && !isdigit(password[i])) {
      special += 1;
    }
  }

  return special;
}


// function to calculate the strength
int calculatePasswordStrength(string password) {

  bool onlyNumbers = isNumber(password) && !isLetter(password) && !isSpecial(password);
  bool onlyLetters = isLetter(password) && !isNumber(password) && !isSpecial(password);
  bool onlySpecial = isSpecial(password) && !isNumber(password) && !isLetter(password);

  if (onlyNumbers || onlyLetters || onlySpecial) {
    return 1;
  }
  if (password.length() >= 2 && isNumber(password) <= 3 && isLetter(password) < 5) {
    return 2;
  }
  if (password.length() >= 8 && isLetter(password) > 4 && isNumber(password) > 2 && !isSpecial(password)) {
    return 3;
  }
  if (password.length() >= 8 && isLetter(password) > 4 && isNumber(password) > 2 && isSpecial(password) >= 1) {
    return 4;
  }
  return 0;
}

void passwordComplexityChecker(void) {
  string password;
  string complexity;
	
  std::cout << "Enter password: ";
  std::cin >> password; // user input of the password

  //calls password strength function to return an integer
  if (calculatePasswordStrength(password) == 1) {
    complexity = "weak";
  } else if (calculatePasswordStrength(password) == 2) {
    complexity = "moderate";
  } else if (calculatePasswordStrength(password) == 3) {
    complexity = "strong";
  } else if (calculatePasswordStrength(password) == 4) {
    complexity = "very strong";
  }

  std::cout << "The password " << password << " is " << complexity;
  // tells the user the complexity of their password
}

void employeeListRemoval(void) {
	string employeeToDelete;
  bool goAhead = true;

  std::list<string> employees { "John Smith", "Jaelynn Stuart", "Kaley Barajas", "Walter Collier", "Cale Myers" };

  std::cout << "\nThere are 5 employees:" << endl;
  
  for (string i : employees) std::cout << i << endl;

  std::cout << "\nEnter an employee name to remove: ";
  getline(cin, employeeToDelete);

  for (string i : employees) {
    employees.remove(employeeToDelete);
  }

  if (employees.size() == 5) {
    std::cout << "No employee found!";
    goAhead = false;
  }

  if (goAhead == true) {
    std::cout << "\nThere are 4 employees:" << endl;

  for (string i : employees) std::cout << i << endl;
  }
}