

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 32

char *trim(char *str1, char *str2) {
   char *buf = NULL;
   int len1 = strlen(str1); 
   int len2 = strlen(str2); 
   if (len1 == len2 || len1 < len2)
      return str1;
   int size = len2;
   buf = malloc(len2 + 1);
   strncpy(buf, str1, len2);
   return buf;
}

int swap(char *str1, char *str2) {
   int result = 0;
   char buffer[LENGTH+1];
   strcpy(buffer, str1);
   strcpy(str1, str2);
   strcpy(str2, buffer);
   return (strlen(str1) == strlen(str2));
}

int main(int argc, char **argv) {

   if (argc < 3) {
      printf("Usage: %s arg1 arg2\n", argv[0]);
      return 1;
   }
   if (swap(argv[1], argv[2])) 
      printf("Try this also: %s %s %s\n", argv[0], argv[1], argv[2]);
   else {
      char *p1 = trim(argv[1], argv[2]);
      char *p2 = trim(argv[2], argv[1]);
      printf("Try this also: %s %s %s\n", argv[0], p1, p2);
   }
   return 1;
}
