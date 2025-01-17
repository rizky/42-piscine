#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <utmp.h>
#include <time.h>

void utmpprint(struct utmp *log)
{
  printf("%s\t%s\t%s\t%d\n", log->ut_name, log->ut_line, log->ut_host, log->ut_tv.tv_usec);
}

int main() {

	int logsize = 10;
	int file;
	struct utmp log[logsize];
	int i = 0;

	file = open("/var/run/utmp", O_RDONLY);
	if( file < 0 ) 
	{ 
	   printf("Failed to open");
	   return(0);
	}
	if (file) {
			read(file, &log, sizeof(log));
			for(i = 0; i < logsize; i++) {

					utmpprint(&log[i]);
			}
			close(file);

	} else {
			return(0);
	}
	return(0);
}
