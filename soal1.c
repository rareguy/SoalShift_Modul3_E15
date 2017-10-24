#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

char *gun[] = {"MP4A1", "PM2-V1", "SPR-3", "SS2-V5", "SP1-V3", "MINE"};

void mainmenu()
{
	printf("Penjual UI\n");
	printf("1. Lihat stock senjata\n");
	printf("2. Tambah stok senjata\n");
	printf("3. Exit\n");
	printf("Command	:");
}

void lihat()
{
	key_t db;
	int *value;
	int guntype;
	for(guntype = 1; guntype <=6; guntype++)
	{
		switch(guntype)
		{
			case 1:
				db = 1041;
				break;
			case 2:
				db = 2021;
				break;
			case 3:
				db = 3003;
				break;
			case 4:
				db = 4025;
				break;
			case 5:
				db = 5013;
				break;
			case 6:
				db = 6000;
				break;
			default:
				printf("No gun in this menu\n");
		}
		int shmid = shmget(db, sizeof(int), IPC_CREAT | 0666);
		value = shmat(shmid, NULL, 0);
		if(*value > 0)
			printf("%s	:%d\n", gun[guntype-1], *value);
		shmdt(value);
		shmctl(shmid, IPC_RMID, NULL);
	}
}

void tambahchoosing(char type[], int amount)
{
	if(strcmp(type, "MP4A1") == 0)
		tambah(1, amount);
	else if(strcmp(type, "PM2-V1") == 0)
		tambah(2, amount);
	else if(strcmp(type, "SPR-3") == 0)
		tambah(3, amount);
	else if(strcmp(type, "SS2-V5") == 0)
		tambah(4, amount);
	else if(strcmp(type, "SP1-V3") == 0)
		tambah(5, amount);
	else if(strcmp(type, "MINE") == 0)
		tambah(6, amount);
	else tambah(7, amount);
}

void tambah(int guntype, int amount)
{
	key_t db;
	int *value;

	switch(guntype)
	{
		case 1:
			db = 1041;
			break;
		case 2:
			db = 2021;
			break;
		case 3:
			db = 3003;
			break;
		case 4:
			db = 4025;
			break;
		case 5:
			db = 5013;
			break;
		case 6:
			db = 6000;
			break;
		default:
			printf("No gun in this menu\n");
	}
	int shmid = shmget(db, sizeof(int), IPC_CREAT | 0666);
	value = shmat(shmid, NULL, 0);
	*value += amount;
	shmdt(value);
	shmctl(shmid, IPC_RMID, NULL);
	printf("Successgully added!\n");
	return;
}

void main()
{
	/*
	List of guns:
	MP4A1, PM2-V1, SPR-3, SS2-V5, SPG1-V3, MINE
	Shared Memory keys:
	MP4A1	 = 1041
	PM2-V1	 = 2021
	SPR-3	 = 3003
	SS2-V5	 = 4025
	SPG1-V3	 = 5013
	MINE	 = 6000
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
