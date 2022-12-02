// /* Filename: fifoclient.c */
// #include <stdio.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>

// #define FIFO_FILE "MYFIFO"
// int main() {
//    int fd;
//    int end_process;
//    int stringlen;
//    char readbuf[80];
//    char end_str[5];
//    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
//    fd = open(FIFO_FILE, O_CREAT|O_WRONLY);
//    strcpy(end_str, "end");
   
//    while (1) {
//       printf("Enter string: ");
//       fgets(readbuf, sizeof(readbuf), stdin);
//       stringlen = strlen(readbuf);
//       readbuf[stringlen - 1] = '\0';
//       end_process = strcmp(readbuf, end_str);
      
//       //printf("end_process is %d\n", end_process);
//       if (end_process != 0) {
//          write(fd, readbuf, strlen(readbuf));
//          printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
//       } else {
//          write(fd, readbuf, strlen(readbuf));
//          printf("Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
//          close(fd);
//          break;
//       }
//    }
//    return 0;
// }



#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
// #include <bits/stdc++.h>

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
    while (1)
    {
        fd = open(myfifo, O_WRONLY);
        fgets(arr2, 80, stdin);
        write(fd, arr2, strlen(arr2)+1);
        close(fd);
        fd = open(myfifo, O_RDONLY);
        read(fd, arr1, sizeof(arr1));
        printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}
