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

int main(int argc, char *argv[])
{

    	pthread_create(&(tid1), NULL, &tulis, NULL);
	pthread_create(&(tid2), NULL, &baca, NULL);

	int i;
	for(i = 0; argv[i] != NULL; i++)
	{
		nomor = argv[i][0] - '0';
		pthread_create(&(tid[i]), NULL, &faktorial, NULL);
	}
	
	for(i = 0; argv[i] != NULL; i++)
	{
		nomor = argv[i][0] - '0';
		pthread_create(&(tid[i]), NULL, &faktorial, NULL);
	}
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

    return 0;
}
