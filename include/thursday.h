#include <iostream>
#include<thread>

void sleep(int seconds = 10) {
  int milliseconds = seconds * 1000; 
  
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); 
}

int sleepTimer(int seconds = 10) {
  sleep(seconds);
  return 0;
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}