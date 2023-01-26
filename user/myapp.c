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
struct process_info info;

//void
//print(const char *s)
//{
//  write(1, s, strlen(s));
//}
//
//void
//forktest(void)
//{
//  int n, pid;
//
//  print("fork test\n");
//
//  for(n=0; n<N; n++){
//    //processinfo(info);
//    printf("num process: %d - num tickets %d\n", (*info).ticks, info->tickets[0]);
//    pid = fork();
//
//
//    sptickets(n+10);
//    if(pid < 0)
//      break;
//    if(pid == 0)
//      exit(0);
//  }
//
//  if(n == N){
//    print("fork claimed to work N times!\n");
//    exit(1);
//  }
//
//  for(; n > 0; n--){
//    if(wait(0) < 0){
//      print("wait stopped early\n");
//      exit(1);
//    }
//  }
//
//  if(wait(0) != -1){
//    print("wait got too many\n");
//    exit(1);
//  }
//
//  print("fork test OK\n");
//}



int
main(int argc, char *argv[]){
    printf("starting testing lottery...\n");
    sptickets(150);
    printf("after set ticket\n");
    processinfo(&info);
    printf("ticket: %d" ,info.tickets);
    printf("hello\n");
    int pid = fork();
    printf("after fork\n");
    if (pid > 0){
        printf("in parent process\n");
        processinfo(&info);
        printf("after calling process_info\n");
        int num_process = info.num_process;
        printf("num process: %d\n",num_process);
        for(int n=0; n<num_process; n++){
            //processinfo(info);
            printf("tick process %d: %d \t num tickets %d\n",info.pids[n], info.ticks[n], info.tickets[n]);

            //sptickets(n+10);
//          if(pid < 0)
//              break;
//          if(pid == 0)
//              exit(0);
        }
    }
    //forktest();
    else{
        printf("in child process\n");
//        for (int i =0; i < 2;i++)
//        {
//           int pid = fork();
//           if (pid == 0)
//           {
//               sptickets(5 * (i + 3));
//           }
//        }
    }
    exit(0);
}