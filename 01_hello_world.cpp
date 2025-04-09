// Compile command: g++ -pthread –std=c++17 –o 01_hello_world 01_hello_world.cpp

#include <iostream>
#include <thread>
using namespace std;

void hello() {
  cout << "Hello Concurrent World\n";
}

int main() {

  // Launch a sperate thread to execute the function hello()
  thread t(hello);

  // Wait for the new thread to finish
  t.join();

  return 0;
}

