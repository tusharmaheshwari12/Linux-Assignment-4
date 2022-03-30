#define _XOPEN_SOURCE 600
#include<stdlib.h>
#include<stdio.h>
//#include<bits/type.h>
#include<errno.h>
//#include<sys/types.h>
#include<unistd.h>
#include<pthread.h>

static pthread_spinlock_t spinlock;
volatile int_slock;


void *spinlockthread(void *i)
{
int rc;
int count =0;

printf("entered thread %d,getting spin lock\n",(int *)i);
rc=pthread_spin_lock(&spinlock);

printf("%d thread unlock the spin lock\n",(int *)i);
rc=pthread_spin_lock(&spinlock);
printf("%d thread unlock the spin lock\n",(int *)i);
return NULL;
}

int main()
{
int rc=0;
pthread_t thread,thread1;
if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
perror("init");
printf("Main, get the spinlock \n");
rc=pthread_spin_lock(&spinlock);

printf("Main,create the spin lock thread \n");
rc= pthread_create(&thread,NULL,spinlockthread,(int *)1);

printf("Main,wait a bit holding the spin lock\n");
sleep(10);

printf("Main,now unlock the spin lock\n");
rc=pthread_spin_unlock(&spinlock);

if(rc==0)
printf("\n Main thread successfully unlocked\n");
else
printf("\n main thread successfully unlocked\n");

printf("Main, wait for the thread to end\n");
rc=pthread_join(thread,NULL);

printf("Main completed\n");
return 0;
}






