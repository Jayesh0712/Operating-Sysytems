// /* Filename: fifoserver.c */
// #include <stdio.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <fcntl.h>
// #include <unistd.h>
// #include <string.h>

// #define FIFO_FILE "MYFIFO"
// int main() {
//    int fd;
//    char readbuf[80];
//    char end[10];
//    int to_end;
//    int read_bytes;
   
   
//    mknod(FIFO_FILE, S_IFIFO|0640, 0);
//    strcpy(end, "end");
//    while(1) {
//       fd = open(FIFO_FILE, O_RDONLY);
//       read_bytes = read(fd, readbuf, sizeof(readbuf));
//       readbuf[read_bytes] = '\0';
//       printf("Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
//       to_end = strcmp(readbuf, end);
//       if (to_end == 0) {
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
    int fd1;
    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char str1[80], str2[80];
    while (1)
    {
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);
        printf("User1: %s\n", str1);
        close(fd1);
        fd1 = open(myfifo,O_WRONLY);
        fgets(str2, 80, stdin);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}
