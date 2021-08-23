#include <iostream>
#include <math.h>
using namespace std;

// Converts Centigrade to Fahrenheit
float CtoF(float temp) {
  return (temp - 32) * 5 / 9; // conversion
}

// Convert Fahrenheit to Centigrade
float FtoC(float temp) {
  return (temp * 9 / 5) + 32; // conversion
}

void fahrenheitCentigradeConversion(void) {
  float temperature = 0.0; // set temp to 0
  char choice; // userInput

  std::cout << "Please enter the starting temperature: ";
  std::cin >> temperature; // updates float on line 16

  std::cout << "Enter 'C' to convert from Fahrenheit to Centigrade...";
  std::cout << "\nEnter 'F' to convert from Centigrade to Fahrenheit...\n";
  std::cout << "Enter 'K' to convert from Fahrenheit to Kelvin...\n";

  std::cin >> choice; // choice gets updated to whatever this is
  std::cout << "Your choice: " << choice << endl;

  if (choice == 'F' || choice == 'f') {
    std::cout << temperature << " in Centigrade is " << FtoC(temperature) << endl; // calls appropriate function
  } else if (choice == 'K' || choice == 'k') {
    std::cout << temperature << " in Kelvin is " << CtoF(temperature) + 273.15 << endl; // calls appropriate function
  } else if (choice == 'C' || choice == 'c') {
    std::cout << temperature << " in Fahrenheit is " << CtoF(temperature) << endl; // calls appropriate function
  } else {
    std::cout << "You need to enter either 'C', 'F' or 'K"; // If user doesn't enter either - error catcher 
  }
}


float addCost(float t, int q, float c) {
  float value = t + (q * c);
  return roundf(value * 100) / 100;
} // takes in subtotal, quantity and cost and rounds to two decimal places

float calculateTax(float total, float tax) {
  float percentageTax = tax / 100;
  float value = total * percentageTax;
  return roundf(value * 100) / 100;
}

void selfServiceCheckout(void) {
  const float tax = 5.5;
  float subtotal = 0.0;
  int quantity = 1; // set to one so while statement executes on line 59
  float cost = 0.0;
  int items = 0;

  while(quantity > 0) {
    items++;
    std::cout << "Please enter a quantity for item " << items << " (or 0 to finish): "; // asks for user input
    std::cin >> quantity; // quantity gets reassigned

    if (quantity > 0) {
      std::cout << "Please enter item " << items << "'s cost: ";
      std::cin >> cost;

      subtotal = addCost(subtotal, quantity, cost); // calls addCost
    }
  }

  std::cout << "Thank you.\n";

  std::cout << "\nSubtotal: £" << subtotal;
  std::cout << "\nShopping tax: £" << calculateTax(subtotal, tax);

  std::cout << "\n\nTotal: £" << subtotal + calculateTax(subtotal, tax);
}

