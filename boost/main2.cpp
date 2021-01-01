#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h> 
#include <sys/stat.h> 
#include <boost/thread.hpp>

bool loop;

static struct termios init_tio;
void init_keyboard()  { tcgetattr(0, &init_tio); }
void close_keyboard() { tcsetattr(0, TCSANOW,&init_tio); }
int kbhit();
int readkey();
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

	init_keyboard();
	loop = true;
        boost::thread th1(&thread1);
        boost::thread th2(&thread2);

	while(loop == true)
	{
		if(kbhit())
		{
			int ch = readkey();
			switch(ch) {
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
	close_keyboard();
	th1.join ();
	th2.join ();
	
	return 0;
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

int kbhit()
{
	struct termios tio;
	struct timeval tv;
	fd_set rfds;

	memcpy(&tio, &init_tio, sizeof(struct termios));
	tio.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &tio);
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);
	tv.tv_usec = 0;
	tv.tv_sec  = 0;
	select(1, &rfds, NULL, NULL, &tv);
	tcsetattr(0, TCSANOW, &init_tio);

	return (FD_ISSET(0, &rfds)?1:0);
}

int readkey()
{
	int ch;
	struct termios tio;

	memcpy(&tio, &init_tio, sizeof(struct termios));
	tio.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW,&tio);
	read(0, &ch, 1);
	tcsetattr(0, TCSANOW, &init_tio);

	return ch;
}

