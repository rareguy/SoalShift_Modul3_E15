#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
int lohanstatus;
int kepitingstatus;
int nomor;
int done;

void* lohan(void *arg)
{
	lohanstatus = 100;
	while(lohanstatus > 0 && lohanstatus <= 100)
	{
		sleep(10);
		lohanstatus -= 15;
		printf("Lohan status	:%d\n", lohanstatus);
		if(lohanstatus <= 0 || lohanstatus > 100)
		{
			done = 1;
			return NULL;
		}
	}
	return NULL;
}


void* kepiting(void *arg)
{
	kepitingstatus = 100;
	while(kepitingstatus > 0 && kepitingstatus <= 100)
	{
		sleep(20);
		kepitingstatus -= 10;
		printf("Kepiting status	:%d\n", kepitingstatus);
		if(kepitingstatus <= 0 || kepitingstatus > 100)
		{
			done = 1;
			return NULL;
		}
	}
	return NULL;
}

void tambahlohan()
{
	lohanstatus += 10;
	printf("Lohan status	:%d\n", lohanstatus);
}

void tambahkepiting()
{
	kepitingstatus += 10;
	printf("Kepiting status	:%d\n", kepitingstatus);
}

int main(void)
{

    	pthread_create(&(tid1), NULL, &lohan, NULL);
	pthread_create(&(tid2), NULL, &kepiting, NULL);
	done = 0;
	int input;
	while(!done)
	{
		printf("Menu:\n1. Pakan lohan\n2. Pakan kepiting\nCommand :\n");
		scanf("%d", &input);
		if(input == 1)
			tambahlohan();
		else if(input == 2)
			tambahkepiting();
	}

    	pthread_join(tid1, NULL);
    	pthread_join(tid2, NULL);

    	return 0;
}
