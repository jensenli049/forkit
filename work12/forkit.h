#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int sleepnum();
void child();
void parent();
void doWork(int pid, int tmp);
