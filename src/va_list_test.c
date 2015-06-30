#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void testfunc(int id, ...);

int main(int argc, char *argv[])
{
 
  testfunc(5, "Hello", "World", "What");

  return 0;
}


void testfunc(int id, ...)
{
 va_list ap;
 char *params;

 va_start(ap, id);
 while (1) {
   params = va_arg(ap, char*);
   if (strcmp(params, "") == 0) {
     break;
   }
   printf("params: #%s\n", params);
 }
 
 va_end(ap);

}
