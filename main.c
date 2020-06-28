#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char* name = strrchr(argv[0], '\\');
	if(0 == name)
	{
		name = strrchr(argv[0], '/');
	}
	if(0 == name)
	{
		name = argv[0];
	}
	if(0 != strstr(name, "makedir"))
	{
		if(2 > argc)
		{
			puts("error: e.g mkdir myfolder");
			return -1;
		}
		char* bslash = strchr(argv[1], '/');
		while(bslash)
		{
			*bslash = '\\';
			bslash = strchr(bslash, '/');
		}

		char cmd[512] = "mkdir";
		strcat(cmd, " ");
		strcat(cmd, argv[1]);
		strcat(cmd, " 2> nul");
		system(cmd);
	}
	if(0 != strstr(name, "rm"))
	{
		if(2 > argc)
		{
			puts("error: e.g rm myfolder");
			return -1;
		}
		char cmd[512] = "rmdir";

		for(int i = 1; i < argc; ++i)
		{
			if(0 == strcmp(argv[i], "-f"))
			{
				strcat(cmd, " /Q");
			}
			else
			if(0 == strcmp(argv[i], "-r"))
			{
				strcat(cmd, " /S");
			}
			else
			{
				char* slash = strrchr(argv[i], '\\');
				if(slash) 	*slash = '\0';
				char* bslash = strrchr(argv[i], '/');
				if(bslash) *bslash = '\0';

				strcat(cmd, " ");
				strcat(cmd, argv[i]);
			}
		}
		system(cmd);
	}

    return 0;
}
