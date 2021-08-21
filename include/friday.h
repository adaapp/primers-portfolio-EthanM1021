class Car { // The class
    private: // Access specifier
    // default private variables 
      const std::string DEFAULT_COLOUR = "Matte Black"; 
      const std::string DEFAULT_MAKE = "Batmobile";

    // initialise variables needed
      string carColour;
      string carMake;
      bool isEngineRunning;
      bool isCarLocked;

    // function to initialise car
      void init_car(std::string colour, std::string make, bool running,bool isLocked) {
        carColour = colour;
        carMake = make;
        isEngineRunning = running;
        isCarLocked = isLocked;
      }

    public:

      int option;

      // constructor - when the objects lifetime begins
     Car() {
        init_car(DEFAULT_COLOUR, DEFAULT_MAKE, false, true);
      }

      // destructor - when the objects lifetime ends
      ~Car() {
      };

      // getter and setter functions
      void setColour(string colour) { carColour = colour; };
      string getColour(void) { return carColour; };

      void setMake(string make) { carMake = make; };
      string getMake(void) { return carMake; };

      void engineOn(void);
      void engineOff(void);
      void lockCar(void);
      void unlockCar(void);

      void status(void) { 
        // change status of engine and locked as they are bools. IT would return 1 or 0 instead of running or off/locked or unlocked
        std::string engine_status;
        std::string locked_status;
        
        isEngineRunning ? engine_status = "Running" : engine_status = "Off";

        isCarLocked ? locked_status = "Locked" : locked_status = "Unlocked";

        // Outputs to the user the status of the car
        std::cout << "\nCar status: Colour: " << carColour << ", Make: " << carMake << ", engine: " << engine_status << ", " << locked_status << endl;
      };
  };

// if a user was to try and lock the car whilst it was locked already, it would give the user a helpful message
  void Car::lockCar(void) {
    if (!isCarLocked) {
      std::cout << "\nLocking the car\n";
      isCarLocked = true;
    } else {
      std::cout << "\nSorry, the car is already locked\n";
    }
  }

  // Same as line 61
  void Car::unlockCar(void) {
    if (isCarLocked) {
      std::cout << "\nUnlocking the car\n";
      isCarLocked = false;
    } else {
      std::cout << "\nSorry, the car is already unlocked\n";
    }
  }

  // Same as line 61
  void Car::engineOn(void) {
    if (!isEngineRunning) {
      std::cout << "\nTurning the engine on\n";
      isEngineRunning = true;
    } else {
      std::cout << "\nSorry, the engine is already on\n";
    }
  }

  // Same as line 61
  void Car::engineOff(void) {
  if(isEngineRunning) {
    std::cout << "\nTurning the engine off\n";
    isEngineRunning = false;
  } else {
    std::cout << "\nSorry, the engine is already off\n"; 
  }
  }

// menu to allow user to see and enter the option they want
int carMenu(void) {
  int option;

  std::cout << "1. Turn Engine On" << endl;
  std::cout << "2. Turn Engine Off" << endl;
  std::cout << "3. Lock Car" << endl;
  std::cout << "4. Unlock Car" << endl;
  std::cout << "Please select an option (or 0 to finish) ";
  std::cin >> option;

  // returns the number in which the user picked
  return option;
  }

void carClass(void) {
  Car myCar; // Instansiates class

  myCar.status();

  // switch case to detect which option the user has chosen
  switch(carMenu()) {
    case 1:
      myCar.engineOn();
      break;
    case 2:
      myCar.engineOff();
      break;
    case 3:
      myCar.lockCar();
      break;
    case 4:
      myCar.unlockCar();
      break;
  }
}

class AreaOf {
    private:
      const float PI = 3.14159;
    
    public: 
      float size(float r) {
        return PI * (r * r);
      }
      float size(float l, float w) {
        return l * w;
      }
      float size(float a, float b, float h) {
        return (a + b) * 2 * h;
      }

      ~AreaOf() {};
};

void areaOf(void) {
    AreaOf square;
    AreaOf rectangle;
    AreaOf trapezium;

		std::cout << "Area of Cirle (radius = 10): " << square.size(10) << endl;
		std::cout << "Area of Rectangle (length = 10, width = 20): " << rectangle.size(10, 20) << endl;
		std::cout << "Area of Trapezium (base = 5, base = 10, height = 20): " << trapezium.size(5, 10, 20) << endl;
}