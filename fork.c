#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
// this code is just testing fork() calls in c and parent vs child processes

int main(){
    //creatign process to save PID
    pid_t pid;
    //this return process ID to show which is parent or child
    pid = fork();

    if(pid <0){
        //error handling
        perror("fork");

        return 1;
    //no error
    }else if (pid ==0){
        //this is the child process when pid ==0
        //et pid gets process
        printf("I'm in the process of watching arcane (PID %d)\n" , getpid());
    }else{
        //this is parent process
        //parent waits for child
        printf("My name is Melissa Castro (PID %d)\n" , getpid());
        //waiting for child to terminate
        wait(NULL);
        printf("Child process has finished. \n");
    }
    return 0;
}