#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define MAX_KEY_SIZE 64

#define MAX_FEED_SIZE 32

#define MAX_COMMAND_SIZE 16

char *keystore;
char *feedDB;
char *ringBuffer;

void printUsage(char **argv);

void recordKey(char *key) {
   if (strlen(key) >= MAX_KEY_SIZE) {
      printf("Nice try, invalid key size!\n");
      return;
   }
   keystore = malloc(64);
   printf("keystore %p\n", keystore);
   strcpy(keystore, key); 
   printf("storing super secret key %s\n", keystore);
     
}

void establishSecureConnection() {
   if (keystore != NULL) 
      printf("Establishing secure connection using key %s\n", keystore); 
   else 
      printf("Invalid key, could not estanblish connection\n");
 
}

void disconnect() {
  printf("freeing keystore %p\n", keystore);
  free(keystore);
}

void recordFeed(char *feed) {
   if (strlen(feed) >= MAX_FEED_SIZE) {
      printf("Nice try, invalid feed size!\n");
      return;
   }
   feedDB = malloc(64);
   printf("feedDB %p\n", feedDB);
   strcpy(feedDB, feed);
   printf("recording feed %s\n", feedDB);
}

void displayFeed() {
   if (feedDB != NULL)
      printf("What's going on social media recently: %s", feedDB);
  else 
      printf("Check back later\n"); 
}

void closeSocialMediaApp() {
   printf("freeing feedDB %p\n", feedDB);
   free(feedDB);
}

void sendCommandToRobot(char *command) {
   if (strlen(command) >= MAX_COMMAND_SIZE) {
      printf("Nice try, invalid command size!\n");
      return;
   }
   ringBuffer = malloc(64);
   printf("ringBuffer %p\n", ringBuffer);
   strcpy(ringBuffer, command);
   printf("recording command %s\n", command);

}

void flushCommands() {
   if (ringBuffer != NULL) {
      printf("Sending %s to robot\n", ringBuffer);
      *ringBuffer = '\0';
   }
}

void closeSmartRobotApp() {
   printf("freeing ringBuffer %p\n", ringBuffer);
   free(ringBuffer);
}


void processCommands(int args, char **argv) {
  int i=1;
  while (i < args) {
    if (!strcmp(argv[i],"k1")) {
       i++;
       if (i < args) {
          recordKey(argv[i]); 
       }
       else printUsage(argv);
    }
    else if (!strcmp(argv[i],"k2")) {
       establishSecureConnection();
    }
    else if (!strcmp(argv[i],"k3")) {
       disconnect();
    }
    else if (!strcmp(argv[i],"f1")) {
       i++;
       if (i < args) {
          recordFeed(argv[i]);
       }
       else printUsage(argv); 
    }
    else if (!strcmp(argv[i],"f2")) {
       displayFeed();
    }
    else if (!strcmp(argv[i],"f3")) {
       closeSocialMediaApp();
    }
    else if (!strcmp(argv[i],"r1")) {
       i++;
       if (i < args) {
          sendCommandToRobot(argv[i]);
       }
       else printUsage(argv); 
    }
    else if (!strcmp(argv[i],"r2")) {
       flushCommands();
    }
    else if (!strcmp(argv[i],"r3")) {
       closeSmartRobotApp();
    }
    else printUsage(argv);
    i++;
  }
}

void printUsage(char **argv) {
   printf("Usage: %s commands:\n", argv[0]);
   printf("\tk1 SKArg: record the secret key SKArg\n");
   printf("\tk2 : establish a secure connection\n");
   printf("\tk3 : disconnect\n");
   printf("\tf1 FArg: record the feed FArg\n");
   printf("\tf2 : display the social media feed\n");
   printf("\tf3 : close social media app\n");
   printf("\tr1 CArg : send command CArg to the robot\n"); 
   printf("\tr2 : flush the robot commands\n"); 
   printf("\tr3 : close the smart robot app\n"); 
   exit(1);
}

int main(int argc, char **argv) {
   if (argc < 2) {
      printUsage(argv);
   }
   printf("Turning the phone on...\n");
   processCommands(argc, argv);
   printf("Turning the (possibly hacked) phone off...\n");
   return 0;
}
