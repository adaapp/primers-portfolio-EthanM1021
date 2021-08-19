#include <iostream>
#include<thread>

const int t1Duration = 5;
const int t2Duration = 10;

void sleep(int seconds = 10) {
  int milliseconds = seconds * 1000; 
  
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); 
}

int sleepTimer(int seconds = 10) {
  sleep(seconds);
  return 0;
}

void timer1() {
  std::cout << "Thread 1 - " << std::this_thread::get_id() << " started\n";
  sleep(t1Duration);
  std::cout << "Thread 1 - " << std::this_thread::get_id() << " ended\n";
}

void timer2() {
  std::cout << "Thread 2 - " << std::this_thread::get_id() << " started\n";
  sleep(t2Duration);
  std::cout << "Thread 2 - " << std::this_thread::get_id() << " ended\n";
}

int joinThreads(void) {
  std::cout << "\nJoin Threads\n\n";
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";

  std::thread thread1(timer1); 
  std::thread thread2(timer2); 

  thread1.join(); 
  thread2.join(); 

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";

  return 0;
}


int detachThreads(void) {
  std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";

  std::thread thread1(timer1);
  thread1.detach();

  std::thread thread2(timer2); 
  thread2.detach();

  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";

  return 0;
}

void joinDetachThreads(void) {
	detachThreads();
}