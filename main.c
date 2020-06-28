/*
<https://github.com/alantsd/mingw32>
  Licensed under the MIT License <http://opensource.org/licenses/MIT>.
  SPDX-License-Identifier: MIT
  Copyright (c) 2016-2018 Rafa Garcia <rafagarcia77@gmail.com>.
  Copyright (c) 2018-2020 Alan Tong <alantsd@hotmail.com>.
  Permission is hereby  granted, free of charge, to any  person obtaining a copy
  of this software and associated  documentation files (the "Software"), to deal
  in the Software  without restriction, including without  limitation the rights
  to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
  copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
  IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
  FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
  AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
  LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/


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
