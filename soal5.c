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
    while(status != 1)
    {

    }
	char cmd[] = "cat /home/rifqi/modul3/SoalShift_Modul3_E15 | grep ";
	strcat(,);
}

int main(int argc, void *argv[])
{
	int i;
	for(i = 1; argv[i] != NULL; i++)
	{
		pthread_create(&(tid[i]), NULL, &
	}
    pthread_create(&(tid1), NULL, &tulis, NULL);
    pthread_create(&(tid2), NULL, &baca, NULL);


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
