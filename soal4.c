#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100]; ///maksimum 100 argumen
unsigned long long nomor;

void* faktorial(void *arg)
{
	unsigned long long result = 1;
	unsigned long long i;
	for(i = 1; i <= nomor; i++)
	{
		result *= i;
	}
	printf("Hasil %llu!	:%llu\n", result);
}

void check(char tmp[])
{
	if(strcmp(tmp, "1") == 0)
		nomor = 1;
	else if(strcmp(tmp, "2") == 0)
		nomor = 2;
	else if(strcmp(tmp, "3") == 0)
		nomor = 3;
	else if(strcmp(tmp, "4") == 0)
		nomor = 4;
	else if(strcmp(tmp, "5") == 0)
		nomor = 5;
	else if(strcmp(tmp, "6") == 0)
		nomor = 6;
	else if(strcmp(tmp, "7") == 0)
		nomor = 7;
	else if(strcmp(tmp, "8") == 0)
		nomor = 8;
	else if(strcmp(tmp, "9") == 0)
		nomor = 9;
	else if(strcmp(tmp, "10") == 0)
		nomor = 10;
	else if(strcmp(tmp, "11") == 0)
		nomor = 11;
	else if(strcmp(tmp, "12") == 0)
		nomor = 12;
	else if(strcmp(tmp, "13") == 0)
		nomor = 13;
	else if(strcmp(tmp, "14") == 0)
		nomor = 14;
	else if(strcmp(tmp, "15") == 0)
		nomor = 15;
	else if(strcmp(tmp, "16") == 0)
		nomor = 16;
	else if(strcmp(tmp, "17") == 0)
		nomor = 17;
	else if(strcmp(tmp, "18") == 0)
		nomor = 18;
	else if(strcmp(tmp, "19") == 0)
		nomor = 19;
	else if(strcmp(tmp, "20") == 0)
		nomor = 20;
	else nomor = 1;
}

int main(int argc, char *argv[])
{
	int i;
	for(i = 0; argv[i] != NULL; i++)
	{
		//printf("%d\n", argv[i]);
		//nomor = argv[i];
		check(argv[i]);
		pthread_create(&(tid[i]), NULL, &faktorial, NULL);
	}

	for(i = 0; argv[i] != NULL; i++)
	{
		pthread_join(tid[i], NULL);
	}

    return 0;
}
