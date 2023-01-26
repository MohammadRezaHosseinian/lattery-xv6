#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


#define N  10
struct process_info{
    int num_process;
    int pids[64];
    int ticks[64];
    int tickets[64];
};
struct process_info *info;

void
print(const char *s)
{
  write(1, s, strlen(s));
}

void
forktest(void)
{
  int n, pid;

  print("fork test\n");

  for(n=0; n<N; n++){
    processinfo(info);
    printf("num process: %d - num tickets %d\n", (*info).ticks, info->tickets[0]);
    pid = fork();


    sptickets(n+10);
    if(pid < 0)
      break;
    if(pid == 0)
      exit(0);
  }

  if(n == N){
    print("fork claimed to work N times!\n");
    exit(1);
  }

  for(; n > 0; n--){
    if(wait(0) < 0){
      print("wait stopped early\n");
      exit(1);
    }
  }

  if(wait(0) != -1){
    print("wait got too many\n");
    exit(1);
  }

  print("fork test OK\n");
}



int
main(int argc, char *argv[]){

 processinfo(info);
  printf("num process: %d - num tickets\n", info->num_process);
  sptickets(150);
  forktest();
  exit(0);
}