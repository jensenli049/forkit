#include "forkit.h"

int main(){
  int pid, status;

  printf("Hi, I'm the parent!\n My pid is: %d\n", getpid());
  pid = fork();
  
  if( pid ){ //if parent
    parent(getpid());
  }
  else {
    pid = fork();
    pid = wait(&status);
    printf("Hi\n");
  }
  
}

int sleepnum(){
  srand( time(NULL) );
  int ans = rand()%16 + 5;
  return ans;
}

int child( int pid ){
  printf("Hi, I'm a child!\n My pid is: %d\n", pid);
  sleep(sleepnum());
}

int parent( int pid ){
  fork(); //make second child
  f = wait(&status);
  
  return f;
}
