

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

int checkPassword(char *str) {
   int result = 0;
   char buffer[32];
   strcpy(buffer, str);
   if (!strcmp(buffer,"hardestOne"))
      result = 1;
   else if (!strcmp(buffer,"hardestTwo"))
      result = 1;
   return result;
}

int main(int argc, char **argv) {

   if (argc < 2) {
      printf("Usage: %s list of passwords to try\n",argv[0]);
      return 1;
   }
   for(int i=1; i<argc; i++) {
      if (checkPassword(argv[i])) {
         printf("Login successful!\n");
         return 0; 
      }
   }
   printf("Login unsuccessful!\n");
   return 1;
}
