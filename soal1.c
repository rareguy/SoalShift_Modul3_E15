#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void mainmenu()
{
	printf("Penjual UI\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Tambah stok senjata\n");
	printf("3. Exit\n");
	printf("Command	:");
}

void lihat()

void main()
{
	/*
	List of guns:
	MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE
	*/

        key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        *value = 10;

        printf("Program 1 : %d\n", *value);

        sleep(5);

        printf("Program 1: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
