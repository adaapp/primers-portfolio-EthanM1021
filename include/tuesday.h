int isNumber(string password) {
  int number = 0;

  for (int i = 0; i < password.length(); i++) {
    if (isdigit(password[i])) {
      number += 1;
    }
  }

  return number;
}

int isLetter(string password) {
  int letter = 0;

  for (int i = 0; i < password.length(); i++) {
    if (isalpha(password[i])) {
      letter += 1;
    }
  }

  return letter;
}

int isSpecial(string password) {
  int special = 0;

  for (int i = 0; i < password.length(); i++) {
    if (!isalpha(password[i]) && !isdigit(password[i])) {
      special += 1;
    }
  }

  return special;
}

void passwordComplexityChecker(void) {
  string password;
	
  std::cout << "Enter password: ";
  std::cin >> password;

  if (isNumber(password) > 2 && !isLetter(password) && !isSpecial(password)) {
    std::cout << 1;
  }
  if (password.length() >= 4 && isNumber(password) <= 3 && isLetter(password) < 5) {
    std::cout << 2;
  }
  if (password.length() >= 8 && isLetter(password) > 4 && isNumber(password) > 2 && !isSpecial(password)) {
    std::cout << 3;
  }
  if (password.length() >= 8 && isLetter(password) > 4 && isNumber(password) > 2 && isSpecial(password) >= 1) {
    std::cout << 4;
  }
}

void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}