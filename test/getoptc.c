// Program to illustrate the getopt()
// function in C

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char opt;
	while((opt = getopt(argc, argv, "t: c:")) != -1)
	{
		switch(opt)
		{
			case 't':
				printf("token: %s\n", optarg);
				break;
                        case 'c':
				printf("total runned thread: %s\n", optarg);
				break;
			case '?':
				printf("unknown option: %c\n", optopt);
				break;
		}
	}
	return 0;
}
