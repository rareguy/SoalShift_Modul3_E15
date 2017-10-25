#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];
int status;
int nomor;

void* baca(void *arg)
{
	char *word = (char *) arg;
	char cmd[] = "grep ";
	strcat(cmd, word);
	strcat(cmd, " Novel.txt | wc -l");
	printf("%s	: ", word);
	system(cmd);
	printf("\n");
}

int main(int argc, void *argv[])
{
	int i;
	for(i = 1; argv[i] != NULL; i++)
	{
		pthread_create(&(tid[i]), NULL, &baca, argv[i]);
	}

	for(i = 1; argv[i] != NULL; i++)
	{
		pthread_join(tid[i], NULL);
	}
	return 0;
}
