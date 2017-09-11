#ifndef PROG2_H
#define PROG2_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


int numLevels = 0;
int numChildren = 1;
int sleepTime = 1;
bool pFlag = false;
bool sFlag = false;
bool defaultSFlag = false;
int opt;
int levelCounter = 0;

void checkCommandLine(int argcount, char **argvariables)
{                  
	
	
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	while((opt = getopt(argcount, argvariables, "uN:M:ps:")) != -1)
	{

		switch(opt)
		{
				//Print the usage string, then exit
				case 'u':
					printf("prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time>]\n");
					exit(1);
				break;
				//Create a process tree with <num-levels> levels
				case 'N':
					numLevels = atoi(optarg);
					if(numLevels > 4)
					{
						printf("There are too many levels to support\n");
						exit(1);
					}
					else if(numLevels < 0)
					{
						printf("Less than 0 levels are not possible\n");
						exit(1);
					}
				break;
				//Create a process wherein every process (other than leaf processes) creates <num-children>
				// child processes
				case 'M':
					numChildren = atoi(optarg);
					if(numChildren > 3)
					{
						printf("There are too many children to support\n");
						exit(1);
					}
					else if(numChildren < 0)
					{
						printf("Less than 0 children are not possible\n");
						exit(1);
					}
				break;
				//Leaf processes should pause()
				case 'p':
					pFlag = true;
				break;
				//Leaf processes should sleep for <sleep-time> seconds, 
				case 's':
					sleepTime = atoi(optarg);
					sFlag = true;
				break;
				default:
						printf("prog2tree [-u] [-N <num-levels>] [-M <num-children>] [-p] [-s <sleep-time>]\n");
						printf("\nThat option is not supported by the program.\n");
						exit(1);
				break;
			}
	}
	
		
	if(sFlag && pFlag)
	{
		printf("Both Sleep and Pause can not be set together\n");
		exit(1);
	}

	if(!sFlag && !pFlag)
	{
		defaultSFlag = true;
		sFlag = true;
	}
	
}


#endif
