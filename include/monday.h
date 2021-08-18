#include <iostream>
#include <math.h>
using namespace std;

float CtoF(float temp) {
  return (temp - 32) * 5 / 9;
}

float FtoC(float temp) {
  return(temp * 9 / 5) + 32;
}

void fahrenheitCentigradeConversion(void) {
  float temperature = 0.0;
  char choice;

  std::cout << "Please enter the starting temperature: ";
  std::cin >> temperature;

  std::cout << "Enter 'C' to convert from Fahrenheit to Centigrade...";
  std::cout << "\nEnter 'F' to convert from Centigrade to Fahrenheit...\n";
  std::cout << "Enter 'K' to convert from Fahrenheit to Kelvin...\n";

  std::cin >> choice;
  std::cout << "Your choice: " << choice << endl;

  if (choice == 'F' || choice == 'f') {
    std::cout << temperature << " in Centigrade is " << CtoF(temperature) << endl;
  } else if (choice == 'K' || choice == 'k') {
    std::cout << temperature << " in Kelvin is " << CtoF(temperature) + 273.15 << endl;
  } else if (choice == 'C' || choice == 'c') {
    std::cout << temperature << " in Fahrenheit is " << FtoC(temperature) << endl;
  } else {
    std::cout << "You need to enter either 'C', 'F' or 'K"; 
  }
}


float addCost(float t, int q, float c) {
  float value = t + (q * c);
  return roundf(value * 100) / 100;
}

float calculateTax(float total, float tax) {
  float value = total * tax;
  return roundf(value * 100) / 100;
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

