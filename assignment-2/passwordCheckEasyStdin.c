

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int size;

int checkPassword() {
   int result = 0;
   char buffer[32];
   char *p = buffer;
   while (read(0,p++,1));
   *p = '\0';
   printf("wrote until %p\n",p);
   if (!strcmp(buffer,"hardestOne"))
      result = 1;
   else if (!strcmp(buffer,"hardestTwo"))
      result = 1;
   return result;
}

int main(int argc, char **argv) {

   if (checkPassword()) {
      printf("Login successful!\n");
      return 0; 
   }
   printf("Login unsuccessful!\n");
   return 1;
}
