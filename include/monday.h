#include <iostream>
using namespace std;

float FtoC(float temp) {
  return ((temp - 32) * 5 / 9);
}

float CtoF(float temp) {
  return ((temp * 9 / 5) + 32);
}

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
    std::cout << temperature << " in Centigrade is " << CtoF(temperature) << endl;
  } else if (choice == 'C' || choice == 'c') {
    std::cout << temperature << " in Fahrenheit is " << FtoC(temperature) << endl;
  } else {
    std::cout << "You need to enter either 'C' or 'F'"; 
  }
}




void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

