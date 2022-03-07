# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

void	*thr_fn1(void *arg)
{
	(void)arg;

	printf("thread 1 returning \n");
	return ((void *)1);
}

void	*thr_fn2(void *arg)
{
	(void)arg;

	printf("thread 2 exiting \n");
	pthread_exit((void *)2);
}

int main(void)
{
	int	err;
	pthread_t tid1;
	pthread_t tid2;
	void	*tret;

	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	err = pthread_create(&tid2, NULL, thr_fn2, NULL);

	err = pthread_join(tid1, &tret);
	printf("thread 1 exit code %ld \n", (long)tret);
	err = pthread_join(tid2, &tret);
	printf("thread 2 exit code %ld \n", (long)tret);
}