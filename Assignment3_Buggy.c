#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int target = 0;
struct data{char name[64];};
struct fp{int (*fp)();};
const int a = 2,b = 3;
void falsePositive()
{
	int *buffer = (int *)calloc(10,sizeof(int));
	buffer[15] = 12;
	if(a + b == 4)
		buffer[20] = a + b;
}
void Winner(){printf("\n\tPassed\n");}
void notWinner(){printf("\n\tNot Passed\n");}
void bufferOverflow(char *user,char *passw) {
	char userRights = 'n';
	printf("\n\tLogin as: %s",user);
	printf("\n\tPassword: %s",passw);
	if (userRights == 'n')
		printf("\nWelcome, normal user '%s'\n", user);
	else
		printf("\nWelcome, admin user '%s'!\n", user);
        *user++;
}
void formatVulnerability(char *string)
{
  printf(string);
  if(target != 0)
      printf("\n\t target modified\n");
  else
      printf("\n\ttarget is %08x :(\n", target);
}
int stackOverflow(int x)
{
   return x == 0 ? 1 : x * stackOverflow(x-1);
}
int main(int argc,char *argv[])
{
	bufferOverflow(argv[1],argv[2]);
	formatVulnerability(argv[3]);
	struct data *d;
	struct fp *f;
	d = malloc(sizeof(struct data));
	f = malloc(sizeof(struct fp));
	f->fp = notWinner;
	strcpy(d->name,argv[4]);
	f->fp();
        falsePositive();
	stackOverflow(-2);
	return 0;
}
