#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    //creatign process to save PID
    pid_t pid;
    pid = fork();

    if(pid <0){
        //error handling
        perror("fork");

        return 1;
    }else if (pid ==0){
        //this is the child process
        printf("hello world from the child process! (PID %d)\n", getpid());
    }else{
        //this is parent process
        //parent waits for child
        printf("Hello worlds from parent process! (PID %d)\n", getpid());
        //waiting for child to terminate
        wait(NULL);
        printf("Child process has finished. \n");
    }
    return 0;
}