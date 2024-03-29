// /* Filename: msgq_recv.c */
// #include <stdio.h>
// #include <stdlib.h>
// #include <errno.h>
// #include <sys/types.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>
// #include <string.h>

// #define PERMS 0644
// struct my_msgbuf {
//    long mtype;
//    char mtext[200];
// };

// int main(void) {
//    struct my_msgbuf buf;
//    int msqid;
//    int toend;
//    key_t key;
   
//    if ((key = ftok("msgq.txt", 'B')) == -1) {
//       perror("ftok");
//       exit(1);
//    }
   
//    if ((msqid = msgget(key, PERMS)) == -1) { /* connect to the queue */
//       perror("msgget");
//       exit(1);
//    }
//    printf("message queue: ready to receive messages.\n");
   
//    for(;;) { /* normally receiving never ends but just to make conclusion 
//              /* this program ends wuth string of end */
//       if (msgrcv(msqid, &buf, sizeof(buf.mtext), 0, 0) == -1) {
//          perror("msgrcv");
//          exit(1);
//       }
//       printf("recvd: \"%s\"\n", buf.mtext);
//       toend = strcmp(buf.mtext,"end");
//       if (toend == 0)
//       break;
//    }
//    printf("message queue: done receiving messages.\n");
//    system("rm msgq.txt");
//    return 0;
// }




#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer {
   long mesg_type;
   char mesg_text[100];
} message;

int main()
{
   key_t key;
   int msgid;

   key = ftok("progfile", 65);
   msgid = msgget(key, 0666 | IPC_CREAT);
   msgrcv(msgid, &message, sizeof(message), 1, 0);
   printf("Data Received is : %s \n", message.mesg_text);
   msgctl(msgid, IPC_RMID, NULL);

   return 0;
}
