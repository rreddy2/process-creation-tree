#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prog2.h"

int main(int argc, char **argv)
{
	checkCommandLine(argc, argv);


	
	pid_t pid; 					/* for a child process */
		
	int i,j = 0;

	printf("ALIVE: Level %d process with pid=%d, child of ppid=%d\n", numLevels-1,(int) getpid(), (int) getppid());
	

	
	if(numLevels <= 1)
	{


		if(sFlag)
			sleep(sleepTime);
		else if(pFlag)			
			pause();
	}
	
	else if(numLevels > 1)	
	{
		for(i = 0; i < numChildren; i++)
		{
			pid = fork();
			
			

			if(pid < 0) 
			{
				fprintf(stderr, "Fork failed.");
				continue;
			}else if(pid == 0)
			{	
				int arg1, arg2, arg3, arg4;
				
				char execStr1[10];			//-N numLevels		
				char execStr2[10];			//-M numChildren
				char execStr3[10];			//-p
				char execStr4[10];			//-s

				arg1 = numLevels-1;
				arg2 = numChildren;
				
				if(pFlag == true)
					arg3 = 1;
				else
					arg3 = 0;
				
			
				
				sprintf(execStr1, "%d", arg1);
				sprintf(execStr2, "%d", arg2);
				
					
				if(sFlag == true)
					sprintf(execStr4, "%d", arg4);
				 
				if(sFlag)
					sleep(sleepTime);
				else if(pFlag)				
					pause();
	
	
				if(pFlag == true)
					execlp("./prog2tree", "./prog2tree", "-N", execStr1, "-M", execStr2, "-p", execStr3, (char *)0);
				else if(defaultSFlag != true)
					execlp("./prog2tree", "./prog2tree", "-N", execStr1, "-M", execStr2, "-s", execStr4, (char *)0);
				else if(defaultSFlag == true)
					execlp("./prog2tree", "./prog2tree", "-N", execStr1, "-M", execStr2, (char *)0);

				break;
			}
		
		}

		int k = 0,p;
		while(k < numChildren)
		{
			int child;
			p = wait(&child);
			k++;
		}

	

		
	}


	printf("EXITING: Level %d process with pid=%d, child of ppid=%d\n", numLevels-1,(int) getpid(), (int) getppid());

	return 0;

}
