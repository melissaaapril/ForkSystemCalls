#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    //creatign process to save multiple PIDs
    pid_t pid1, pid2;
    //this return process ID to show which is parent or child
    pid1 = fork();

    if(pid1 <0){
        //error handling
        perror("fork");
        return 1;
    //no error
    }else if (pid1 ==0){
        //this is the child process when pid ==0
        //et pid gets process
        printf("My Major is Computer Science (PID %d)\n" , getpid());
    }else{
        //this is the parent process
        //parent waits for child (boht so we did 2 waits)
        printf("Hello I'm Melissa Castro (PID %d)\n" , getpid());
        //redefine fork again for pid2
        pid2 = fork();
        if(pid2 <0){
            //error handling
        perror("fork");
        return 1;
        //no error
        }else if (pid2 ==0){
            //this is the child process when pid ==0
            //get pid gets process
            printf("I'm graduating sometime December 2025 (PID %d)\n" , getpid());
        }else{
            //waiting for both child process to terminate
            wait(NULL);
            wait(NULL);
            printf("Child process has finished. \n");
        }    
    }
    return 0;
}