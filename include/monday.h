#include <iostream>
using namespace std;

void fahrenheitCentigradeConversion(void) {
  float temperature;
  char choice;

	std::cout << "Please enter the starting temperature: ";
  
  std::cin >> temperature;

  std::cout << "\nPress 'C' to convert from Fahrenheit to Centigrade...";
  std::cout << "\nPress 'F' to convert from Centigrade to Fahrenheit...\n";

  std::cin >> choice;
  std::cout << "You picked: " << choice << endl;

  if (choice == 'F' || choice == 'f') {
    std::cout << temperature << " in Centigrade is " << (temperature * 9 / 5) + 32 << endl;
  } else if (choice == 'C' || choice == 'c') {
    std::cout << temperature << " in Fahrenheit is " << (temperature - 32) * 5 / 9 << endl;
  } else {
    std::cout << "You need to enter either 'C' or 'F'"; 
  }
}


void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

