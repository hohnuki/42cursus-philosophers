#include <stdio.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;

	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("%ld %06d\n", tv.tv_sec, tv.tv_usec);//tv_secが秒単位,tv_usecはマイクロ秒単位
	gettimeofday(&tv, NULL);
	printf("%ld %06d\n", tv.tv_sec, tv.tv_usec);
	return 0;
}