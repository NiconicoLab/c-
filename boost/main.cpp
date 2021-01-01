#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h> 
#include <sys/stat.h> 
#include <boost/thread.hpp>

bool loop;

int kbhit(void);
void thread1(void);
void thread2(void);
		    
int main(int argc, char *argv[])
{
	struct stat st;
	
	if (stat("dir", &st) != 0)
	{
		printf("dir does not exit\n");
		if(mkdir("dir", 0775) == 0)
		{
			printf("create dir\n");
		}
	}
	else
	{
		printf("dir exits\n");
	}

	loop = true;
        boost::thread th1(&thread1);
        boost::thread th2(&thread2);

	while(loop)
	{
		if (kbhit())
		{
			switch(getchar()) {
			case 'Q':
			case 'q':
				printf("\nexit\n");
				loop = false;
				break;
			default:
				break;
			}
		}
	}
	th1.join ();
	th2.join ();
	
	return 0;
}

int kbhit(void)
{
	struct termios old_fd, new_fd;
	int ret = 0;
	
	tcgetattr(STDIN_FILENO, &old_fd);
	new_fd = old_fd;
	new_fd.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_fd);
	int old = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, old | O_NONBLOCK);	
	int c = getchar();	
	tcsetattr(STDIN_FILENO, TCSANOW, &old_fd);
	fcntl(STDIN_FILENO, F_SETFL, old);
	
	if (c != EOF)
	{
		ungetc(c, stdin);
		ret = 1;
	}
	
	return ret;
}

void thread1(void)
{
	while(loop)
	{
		// 1000ミリ秒スリープ
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		printf("thread1 output\n");
	}
}

void thread2(void)
{
	while(loop)
	{
		// 1000ミリ秒スリープ
		boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
		printf("thread2 output\n");
	}
}

