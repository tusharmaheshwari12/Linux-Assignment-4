#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


pthread_once_t once=PTHREAD_ONCE_INIT;

void *myinit(){
printf("\n I am in init fun\n");
}

void *mythread(void *i)
{
printf("\n I am in my thread :%d\n",(int *)i);
pthread_once(&once,(void *)myinit);
printf("\n Exit from mythread :%d\n",(int *)i);
}

int main()
{
pthread_t thread,thread1,thread2;
pthread_create(&thread,NULL,mythread,(void *)1);
pthread_create(&thread1,NULL,mythread,(void *)2);
pthread_create(&thread2,NULL,mythread,(void *)3);
printf("\n Exit for main\n");
pthread_exit(NULL);
}
