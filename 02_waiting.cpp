#include <thread>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std; 

void new_thread_do_something (int& i);

void old_thread_do_something();

struct new_thread_func {

  // A state variable 
  int& i;
 
  // Structure constructor 
  new_thread_func(int& i_):i(i_) {} 

  // The action to be taken when the thread is spawned
  // This is a functor 
  void operator ()() {
    for (unsigned j = 0; j < 10; ++j) {
      new_thread_do_something (i);
    }
  }
};


int main() {

  int some_local_state = 0;

  // Create thread structure
  new_thread_func my_func (some_local_state);

  // Start new thread 
  std::thread t (my_func);

  // Do stuff in old thread 
  try {
    old_thread_do_something ();
  }
  catch(...) {
    t.join();
    throw;
  }

  // Wait until the new thread is done
  t.join();
  cout << "Threads rejoined!!!" << endl;
}

void new_thread_do_something (int& i) {
  ++i;
  cout << "Sleep " << i << endl;
  sleep(1);
}

void old_thread_do_something() {
  cout << "Ho hum..." << endl;
} 



