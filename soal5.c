#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[100];
int status;
int nomor;
char word[50];

/*void* baca(void *arg)
{
	char cmd[100];
	strcat(cmd, "grep -o ");
	strcat(cmd, word);
	strcat(cmd, " Novel.txt | uniq -c");
//	printf();
//	sleep(5);
	system(cmd);
//	printf("\n");
}*/

void *baca(void *arg)
{
	while(!status)
	{
	}
	status = 0;
	FILE *fp;
	int count = 0;
	int ch, len;
	char *kata = malloc(sizeof((char *)arg));
	kata = (char *) arg;
	if(NULL==(fp=fopen("Novel.txt", "r")))
    		return NULL;
	len = strlen(kata);
	for(;;)
	{
        	int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *kata) continue;
        for(i=1;i<len;++i){
            if(EOF==(ch = fgetc(fp))) goto end;
            if((char)ch != kata[i]){
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }
        ++count;
        next: ;
    }
end:
    fclose(fp);
    printf("%s	:%d\n", kata, count);
	status = 1;
	sleep(1);
}

int main(int argc, void *argv[])
{
	status = 1;
	int i;

	for(i = 1; argv[i] != NULL; i++)
	{
		strcpy(word, argv[i]);
		strcat(word, "\0");
		printf("%d: %s\n" , i, word);
		pthread_create(&(tid[i]), NULL, &baca, word);
	}

	for(i = 1; argv[i] != NULL; i++)
	{
		pthread_join(tid[i], NULL);
	}
	return 0;
}
