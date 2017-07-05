#include <stdio.h>

int fun2() {  
  return 2; 
}

int fun1() { 
  fun2(); 
  return 0;
}

int fun() {
  fun1();
  return 1;
}

int main(int argc, char **argv) { 
  fun(); 
}
