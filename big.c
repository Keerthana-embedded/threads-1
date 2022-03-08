#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
static char ch=65;
void * capital(void *p)
{
	while((ch>=65)&&(ch<=90))
	{
		printf("%c..",ch);
		sleep(0.7);
  }
}
void * small(void *p)
{
	while(ch<=90)
	{
		printf("%c..",ch+32);
		ch++;
                sleep(0.7);		
	}
}
int main()
{
	pthread_t t[2];
	pthread_create(&t[0],0,capital,0);
	pthread_create(&t[1],0,small,0);
	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	return 0;

}
