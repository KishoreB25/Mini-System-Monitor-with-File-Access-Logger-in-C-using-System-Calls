#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "file_logger.h"
#include "system_info.h"

// int main() {
//     int choice;
//     while (1) {
//         printf("\n--- Mini System Monitor ---\n");
//         printf("1. List Processes\n");
//         printf("2. Show My PID & Parent PID\n");
//         printf("3. Kill a Process\n");
//         printf("4. Log File Access Info\n");
//         printf("5. Show Disk Usage\n");
//         printf("0. Exit\n");
//         printf("Enter choice: ");
//         scanf("%d", &choice);

//         switch(choice) {
//             case 1: list_processes(); break;
//             case 2: show_pids(); break;
//             case 3: kill_process(); break;
//             case 4: log_file_access("test.txt"); break; // example file
//             case 5: show_disk_usage("/"); break;
//             case 0: exit(0);
//             default: printf("Invalid choice!\n");
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "file_logger.h"
#include "system_info.h"

#include "process.h"
#include "file_logger.h"
#include "system_info.h"

int main() {
    int choice;

    while (1) {
        printf("\n========== Mini System Monitor ==========\n");
        printf("1. Test Open Directory (opendir)\n");
        printf("2. Test File Open (fopen)\n");
        printf("3. Test Kill Process (kill)\n");
        printf("4. Test File Info (stat + ctime)\n");
        printf("5. Test Disk Usage (statvfs)\n");
        printf("6. Test Executable Path (readlink)\n");
        printf("7. Test Process IDs (getpid, getppid)\n");
        printf("8. Extra Functionality\n");
        printf("0. Exit\n");
        printf("=========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: test_opendir(); break;
            case 2: test_fopen(); break;
            case 3: test_kill(); break;
            case 4: test_stat_ctime(); break;
            case 5: test_statvfs(); break;
            case 6: test_readlink(); break;
            case 7: test_getpid(); break;
            case 8: test_extra(); break;
            case 0: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}

