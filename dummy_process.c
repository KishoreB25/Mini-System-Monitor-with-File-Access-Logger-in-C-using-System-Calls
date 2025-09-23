// dummy_process.c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Dummy process started. PID = %d\n", getpid());
    while (1) {
        sleep(1); // keep running
    }
    return 0;
}
