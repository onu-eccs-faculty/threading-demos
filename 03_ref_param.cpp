#include <iostream>
#include <thread>
#include <vector>

using namespace std; 

void printer (int i) {
  cout << i << " is a nifty number!!" << endl;
}

void doubler (vector<int>& v) {
  cout << "v used to be: ";
  for (int i = 0; i < v.size(); i++){
    cout << v[i] << " "; 
    v[i] *= 2; 
  }
  cout << endl;
}

int main () {

  // Passing a primitive variable
  int n = 3;
  thread primitive_pass (printer, n);
  primitive_pass.join();
 
  // Passing a reference variable 
  vector<int> v = {1,2,3};
  thread t2 (doubler, ref(v)); 
  t2.join();
    
  cout << "v is now: ";
  for (int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;


}

