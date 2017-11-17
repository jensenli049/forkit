#include "forkit.h"

int main(){
  int pid;
    int tmp;

  printf("Hi, I'm the parent! My pid is: %d, and I'm about to fork!\n", getpid());
  pid = fork();
  
  if( pid ){ //if parent
      tmp = fork();
  }

    doWork(pid, tmp);
  
}

int sleepnum(){
  srand( time(NULL) );
  int ans = rand()%16 + 5;
  return ans;
}

void doWork(int pid, int tmp){
    if(pid && tmp){  //if parent
        parent();
    }
    else
        child();
    
}

void child(){
  int tmp = sleepnum();
  printf("Hi, I'm a child! My pid is: %d\n", getpid());
  sleep(tmp);
  //printf("Sir, I'm done sleeping!\n");
  printf("I'm %d! I just woke up from a %d second nap!\n", getpid(), tmp);
}

void parent(){
  int status;
  //int f = fork(); //make second child

    wait(&status);
    printf("My life is complete, time to die...\n");

}
