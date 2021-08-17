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


float addCost(float t, int q, float c) {
  return t + (q * c);
}

float calculateTax(float total, float tax) {
  return total * tax;
}

void selfServiceCheckout(void) {
  float tax = 0.055;
  float subtotal = 0.0;
  int quantity = 1;
  float cost = 0.0;
  int items = 0;

  while(quantity > 0) {
    items++;
    std::cout << "Please enter a quantity for item " << items << " (or 0 to finish):";
    std::cin >> quantity;

    if (quantity > 0) {
      std::cout << "Please enter item " << items << "'s cost: ";
      std::cin >> cost;

      subtotal = addCost(subtotal, quantity, cost);
    }
  }

  std::cout << "Thank you.\n";

  std::cout << "\nSubtotal: £" << subtotal;
  std::cout << "\nShopping tax: £" << calculateTax(subtotal, tax);

  std::cout << "\n\nTotal: £" << subtotal + calculateTax(subtotal, tax);
}

