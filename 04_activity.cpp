#include <thread> 
#include <iostream> 
#include <vector> 
using namespace std;

void initVec(vector<int>& v) {
  for (unsigned int i = 0; i < v.size(); i++) 
    v[i] = i;
}

void totVec(vector<int>& v, int& total) {
  for (unsigned int i = 0; i < v.size(); i++) 
    total += v[i];
}

int main () {
  vector<int> v1(10);
  initVec(v1);
  int total_main = 0; 

  // make this subroutine run as a separate thread
  totVec(v1,total_main);

  // Print out total
  cout << "total_main: " << total_main << endl;
  
  return 0;
}

