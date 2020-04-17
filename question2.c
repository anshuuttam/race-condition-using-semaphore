#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h> 
#include <semaphore.h>

              int counter = 5;
  sem_t mutex;
void *f1() {
int a;
sem_wait(&mutex);
a=counter;
a=a+1;
sleep(1);
counter=a;
sem_post(&mutex);
printf("the value of counter is %d\n",counter);
}
void *f2() {
int a;
sem_wait(&mutex);
a=counter;
a=a-1;
sleep(1);
counter=a;
sem_post(&mutex);
printf("the value of counter is %d \n",counter);
}
int main() {
pthread_t thread1, thread2;
sem_init(&mutex, 0, 1);
pthread_create( &thread1, NULL, f1, NULL);
pthread_create( &thread2, NULL, f2, NULL);
pthread_join( thread1, NULL);
pthread_join( thread2, NULL);
printf("the value of counter is %d\n", counter);
}
