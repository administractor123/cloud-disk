#include "../include/head.hpp"

using std::cout;
using std::endl;

int exitPipe[2];

void sigHandle(int num)
{
    cout<< num << "sig is comming" <<endl;    
    int one = 1;
    write(exitPipe[1], &one, sizeof(int));
}

int main(int argc, char* argv[])
{
    pipe(exitPipe);

    pid_t pid = fork();
    if(pid > 0)
    {
        close(exitPipe[0]);
        signal(SIGUSR1, sigHandle);
        wait(NULL);
        close(exitPipe[1]);
        cout<< "Parent process has exit" <<endl;
        exit(0);
    }


     
    return 0;
}