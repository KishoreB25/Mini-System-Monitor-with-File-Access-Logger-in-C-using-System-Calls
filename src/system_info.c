// #include <stdio.h>
// #include <sys/statvfs.h>
// #include "system_info.h"

// void show_disk_usage(const char *path) {
//     struct statvfs fs;
//     if (statvfs(path, &fs) != 0) {
//         perror("statvfs failed");
//         return;
//     }
//     unsigned long total = fs.f_blocks * fs.f_frsize;
//     unsigned long free  = fs.f_bfree * fs.f_frsize;
//     printf("Disk Total: %lu bytes\n", total);
//     printf("Disk Free : %lu bytes\n", free);
// }

#include <stdio.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <limits.h>
#include "system_info.h"

void test_statvfs() {
    struct statvfs fs;
    if (statvfs("/", &fs) != 0) {
        perror("statvfs failed");
        return;
    }
    unsigned long total = fs.f_blocks * fs.f_frsize;
    unsigned long free = fs.f_bfree * fs.f_frsize;
    printf("Disk Total: %lu bytes\n", total);
    printf("Disk Free : %lu bytes\n", free);
}

void test_readlink() {
    char exe[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", exe, sizeof(exe) - 1);
    if (len == -1) {
        perror("readlink failed");
        return;
    }
    exe[len] = '\0';
    printf("Executable Path: %s\n", exe);
}

void test_extra() {
    printf("Custom Functionality Placeholder.\n");
    printf("You can implement memory usage, CPU stats, or file logger here.\n");
}
