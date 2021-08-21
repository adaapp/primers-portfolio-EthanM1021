#include <iostream>
#include<thread>

const int t1Duration = 5;
const int t2Duration = 10;

// function which blocks any execution when called for specified amount of time
void sleep(int seconds = 10) {
  // conversion for seconds to milliseconds
  int milliseconds = seconds * 1000; 

  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); 
}

int sleepTimer(int seconds = 10) {
  sleep(seconds);
  return 0;
}

// function which produces a thread and states the id which is given to it and then calls sleep to block anything else until that sleep function is then executed
void timer1() {
  std::cout << "Thread 1 - " << std::this_thread::get_id() << " started\n";
  sleep(t1Duration);
  std::cout << "Thread 1 - " << std::this_thread::get_id() << " ended\n";
}

// same as timer1 but sleeps for duration specified on line 5
void timer2() {
  std::cout << "Thread 2 - " << std::this_thread::get_id() << " started\n";
  sleep(t2Duration);
  std::cout << "Thread 2 - " << std::this_thread::get_id() << " ended\n";
}

// function to join two threads together
int joinThreads(void) {
  std::cout << "\nJoin Threads\n\n";
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";

  std::thread thread1(timer1); // allows multiple function to execute concurrently
  std::thread thread2(timer2); 

  thread1.join(); // waits for the thread to finish its execution
  thread2.join(); 

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";

  return 0;
}


int detachThreads(void) {
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";

  std::thread thread1(timer1);
  thread1.detach(); // stops the thread exeucting independently from the thread 'handle'

  std::thread thread2(timer2); 
  thread2.detach();

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";

  return 0;
}

void joinDetachThreads(void) {
	detachThreads();
}