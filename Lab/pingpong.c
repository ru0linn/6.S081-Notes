#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int p1[2];//pipe from parent to child
    int p2[2];//pipe from child to parent
    pipe(p1);
    pipe(p2);
    char c;
    if(fork() == 0){
        read(p1[0], &c, 1);
        printf("%d: received ping\n", getpid());
        write(p2[1], &c, 1);
        exit(0);
    }else{
        c = 'c';
        write(p1[1], &c, 1);;
        read(p2[0], &c, 1);
        printf("%d: received pong\n", getpid());
    }
    exit(0);
}