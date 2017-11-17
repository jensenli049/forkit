#include "forkit.h"

int main(){
  int pid;

  printf("Hi, I'm the parent!\n My pid is: %d\n", getpid());
  pid = fork();
  
  if( pid ){ //if parent
    parent(getpid());
  }
  else {
    printf("---------");
    child(getpid());
  }
  
}

int sleepnum(){
  srand( time(NULL) );
  int ans = rand()%16 + 5;
  return ans;
}

int child( int pid ){
  int tmp = sleepnum();
  printf("Hi, I'm a child! My pid is: %d\n", pid);
  sleep(tmp);
  printf("Sir, I'm done sleeping!\n");
  return tmp;
}

int parent( int pid ){
  int status;
  int f = fork(); //make second child
  if( f )
    printf("I'm %d! I just woke up from a %d second nap!\n", f, child(f));
  else{
    wait(&status);
    printf("My life is complete, time to die...\n");
  }
  return f;
}
