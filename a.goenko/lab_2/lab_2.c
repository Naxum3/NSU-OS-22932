#include <sys/types.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
extern char* tzname[];

int main()
{
	setenv("TZ","America/Los_Angeles", 100);
	time_t now;
	struct tm* sp;

	(void)time(&now);

	printf("%s", ctime(&now));

	sp = localtime(&now);
	sp->tm_mon += 1;
	sp->tm_year -= 100;
	printf("%d/%d/%02d %d:%02d %s\n",
		sp->tm_mon, sp->tm_mday,
		sp->tm_year, sp->tm_hour,
		sp->tm_min, tzname[sp->tm_isdst]);
	exit(0);
}