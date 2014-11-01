#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int target = 0;
struct data{char name[64];};
struct fp{int (*fp)();};
const int a = 2,b = 3;

void falsePositive()
{
	int buffer[10],c,d;
	buffer[10] = 12; c = d = 0;
	if(a + b == 4)
		buffer[20] = a + b;
	if(c + d != 0)
		buffer[25] = c + d;
}

void Winner(){printf("\n\tPassed");}

void notWinner(){printf("\n\tNot Passed");}

void bufferOverflow() {
	char userRights = 'n';
	char userName[8],password[8];
	printf("\n\tLogin as: ");
	gets(userName);
	printf("\n\tPassword: ");
	gets(password);
	if (userRights == 'n')
		printf("\nWelcome, normal user '%s', your rights are limited.\n\n", userName);
	else
		printf("\nWelcome, all mighty admin user '%s'!\n", userName);
}

void formatVulnerability()
{
  char buffer[512];
  printf("\n\tEnter buffer value::");
  fgets(buffer, sizeof(buffer), stdin);
  printf(buffer);
  if(target != 0)
      printf("\n\t target modified");
  else
      printf("target is %08x :(\n", target);
}

int stackOverflow(int x)
{
   return x == 0 ? 1 : x *stackOverflow(x-1);
}

int main()
{
	bufferOverflow();
	formatVulnerability();
	falsePositive();
	struct data *d;
	struct fp *f;
	char value[72];
	d = malloc(sizeof(struct data));
	f = malloc(sizeof(struct fp));
	f->fp = notWinner;
	printf("data is at %p, fp is at %p\n", d, f);
	gets(value);
	strcpy(d->name,value);
	f->fp();
	stackOverflow(-2);
	return 0;
}



