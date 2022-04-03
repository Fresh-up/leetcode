#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
void err_thread(int ret, char *str){
	if (ret != 0){
		fprintf(stderr, "%s:%s\n", str, strerror(ret));
		pthread_exit(NULL);
	}
}
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//定义/初始化一个互斥量
pthread_cond_t has_data = PTHREAD_COND_INITIALIZER;//定义/初始化一个条件变量

struct msg {
	int num;
	struct msg *next;
};
struct msg *head;

void* producer(void* arg){
	while (1){
		struct msg *mp = malloc(sizeof(struct msg));
		mp->num = rand() % 1000 + 1;//模拟生产一个数据
		printf("--produce %d\n", mp->num);

		pthread_mutex_lock(&mutex);//加锁
		mp->next = head;//链表头插，写公共区域
		head = mp;
		pthread_mutex_unlock(&mutex);//解锁

		pthread_cond_signal(&has_data);//唤醒阻塞在条件变量上的线程
		sleep(rand() % 3);//睡一会，让消费者拿到cpu
	}
	return NULL;
}
void* consumer(void* arg){
	while (1){
		struct msg *mp;
		pthread_mutex_lock(&mutex);//加锁
		if (head == NULL){
			pthread_cond_wait(&has_data, &mutex);//阻塞等待条件变量，解锁
		}//wait返回时，重新加锁mutex

		mp = head;
		head = mp->next;//模拟读操作
		pthread_mutex_unlock(&mutex);
		printf("----------consumer:%d\n", mp->num);
		free(mp);

		sleep(rand() % 3);//把cpu还给生产者
	}

	return NULL;
}
int main(){
	int ret;
	pthread_t pid, cid;
	srand(time(NULL));//种一颗种子，产生随机数

	ret = pthread_create(&pid, NULL, producer, NULL);//创建生产者
	if (ret != 0) err_thread(ret, "pthread_create producer error");
	ret = pthread_create(&cid, NULL, consumer, NULL);//创建消费者
	if (ret != 0) err_thread(ret, "pthread_create consumer error");
	
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	return 0;
}
