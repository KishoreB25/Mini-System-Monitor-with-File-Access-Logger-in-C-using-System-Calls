// #include <stdio.h>
// #include <dirent.h>
// #include <unistd.h>
// #include <signal.h>
// #include "process.h"

// void list_processes() {
//     DIR *dir;
//     struct dirent *entry;
//     dir = opendir("/proc");
//     if (!dir) { perror("opendir"); return; }
//     printf("Processes:\n");
//     while ((entry = readdir(dir)) != NULL) {
//         if (entry->d_name[0] >= '0' && entry->d_name[0] <= '9') {
//             printf("PID: %s\n", entry->d_name);
//         }
//     }
//     closedir(dir);
// }

// void show_pids() {
//     printf("My PID: %d\n", getpid());
//     printf("Parent PID: %d\n", getppid());
// }

// void kill_process() {
//     int pid;
//     printf("Enter PID to kill: ");
//     scanf("%d", &pid);
//     if (kill(pid, SIGKILL) == 0)
//         printf("Killed process %d\n", pid);
//     else
//         perror("kill failed");
// }

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include "process.h"

void test_opendir() {
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");
    if (d) {
        printf("Processes in /proc:\n");
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("opendir failed");
    }
}

void test_kill() {
    int pid;
    printf("Enter PID to kill: ");
    scanf("%d", &pid);
    if (kill(pid, SIGKILL) == 0) {
        printf("Process %d killed successfully.\n", pid);
    } else {
        perror("kill failed");
    }
}

void test_getpid() {
    printf("Current PID: %d\n", getpid());
    printf("Parent PID : %d\n", getppid());
}
