// #include <stdio.h>
// #include <sys/stat.h>
// #include <time.h>
// #include "file_logger.h"

// void log_file_access(const char *filename) {
//     struct stat st;
//     if (stat(filename, &st) == -1) {
//         perror("stat failed");
//         return;
//     }
//     FILE *log = fopen("file_log.txt", "a");
//     if (!log) { perror("fopen failed"); return; }

//     fprintf(log, "File: %s\n", filename);
//     fprintf(log, "Size: %ld bytes\n", st.st_size);
//     fprintf(log, "Last Access: %s", ctime(&st.st_atime));
//     fprintf(log, "Permissions: %o\n\n", st.st_mode & 0777);
//     fclose(log);

//     printf("File info logged.\n");
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "file_logger.h"

// void test_fopen() {
//     FILE *fp;
//     char buffer[256];
//     fp = fopen("/proc/cpuinfo", "r");
//     if (!fp) {
//         perror("fopen failed");
//         return;
//     }
//     printf("CPU Info (first line):\n");
//     if (fgets(buffer, sizeof(buffer), fp) != NULL) {
//         printf("%s", buffer);
//     }
//     fclose(fp);
// }


void test_fopen() {
    FILE *fp;
    char buffer[256];
    fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        perror("fopen failed");
        return;
    }
    printf("CPU Info:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}


void test_stat_ctime() {
    struct stat st;
    if (stat("/home/hp/mini_sys_monitor/tests/test.txt", &st) == 0) {
        printf("File Size: %ld bytes\n", st.st_size);
        printf("Last Access: %s", ctime(&st.st_atime));
        printf("Last Modification: %s", ctime(&st.st_mtime));
        printf("Permissions: %o\n", st.st_mode & 0777);
    } else {
        perror("stat failed");
    }
}

