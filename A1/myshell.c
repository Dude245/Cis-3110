#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>

extern char **getln();

int main() {
	//Declare variables, not war
	int i = 0;
	char * line;
	long addNum;
	char **args;
	int isString;
	int addCount;
	int argCount;
	pid_t pid;
	unsigned char c;
	int num = 0;
	//Start the main loop
	while (1) {
		//Give it personal flair
		printf("> ");
		args = getln();
		//Make sure the program doesnt die
		if (args[i] == NULL) {
			printf("Invalid Command\n");
			continue;
			i--;
		//Exit Command
		} else if (strcmp(args[i], "exit") == 0) {
			exit(0);
			//Add command. Strcat to a line, tokenize and add
		} else if (strcmp(args[i], "add") == 0) {
			num = 0;
			addCount = 0;
			isString = 0;
			line = calloc(1000, sizeof (char));
			while (args[i + 1] != NULL) {

				if (args[i + 1] != NULL) {
					line = args[i + 1];
					addNum = strtol(line, NULL, 0);
					num = addNum + num;
					c = args[i + 1][0];
					if (isdigit(c) == 0) {
						isString = 1;
					}
					addCount++;
				}
				i++;
			}
			//Check if its a string
			if (addCount < 1 || isString == 1 || num == 0) {
				printf("Invalid Input\n");
			} else {
				printf("%d\n", num);
			}
			free(line);
			//Concatinate arguments
		} else if (strcmp(args[i], "arg") == 0 && args[i + 1] != NULL) {
			argCount = 0;
			line = calloc(1000, sizeof (char));
			while (1) {
				if (args[i + 1] != NULL) {
					line = strcat(line, args[i + 1]);
					if (args[i + 2] != NULL) {
						line = strcat(line, ",");
					}
					argCount++;
				} else {
					break;
				}
				i++;

			}
			printf("argc = %d \n args = %s\n", argCount, line);
			//Execute hangman, from CIS*1500
		} else if (strcmp(args[i], "hangman") == 0) {
			system("./hangman");
		} else if (args[i + 1] != NULL) {
			//Declare loop variables
			int p = 0;
			int isWrite = 0;
			int isRead = 0;
			int isPiped=0;
			int pip[2];
			//Create a line for arguments
			char ** argV = calloc(100, sizeof (char *));
			while (args[i + 1] != NULL) {
				isWrite = 0;
				isRead = 0;
				isPiped=0;
				argV[p] = args[i];
				//If else block for input/output/piping
				if (strcmp(">", args[i + 1]) == 0) {
					freopen(args[i + 2], "w", stdout);
					i += 2;
					isWrite = 1;
				} else if (strcmp("<", args[i + 1]) == 0) {
					freopen(args[i + 2], "r", stdin);
					i+=2;
					isRead = 1;
				} else if (strcmp("|", args[i + 1]) == 0) {
					i += 2;
					isPiped=1;
					pipe(pip);
				}
				argV[p + 1] = args[i + 1];
				i++;
				p++;


			}
			if (isWrite == 1) {
				i--;
			}
			if (isRead == 1) {
				i--;
			}
			if (isPiped==1)
			{
				i--;
			}
			//Set last element to NULL
			argV[p + 1] = NULL;

			//Fork a child process
			pid = fork();
            if (pid < 0) // fork was not successful
            {
            	printf("Failed\n");
            	exit(0);
            } else if (pid == 0) // child process
            {
            	execvp(argV[0], argV);
            	printf("Execute failed\n");
            	exit(0);
            } else //Parent process
            {
            	wait(NULL);
            	if (isWrite == 1) {
            		freopen("/dev/tty", "a", stdout);
            	} else if (isRead == 1) {
            		exit(0);
            	}
            }
            //Case for no arugments
        } else if (args[i + 1] == NULL) {
        	//For a child
        	pid = fork();
        	//Set command to first positon, then NULL
        	char ** empty = calloc(10, sizeof (char *));
        	empty[0] = args[i];
        	empty[1] = NULL;

            if (pid < 0) // fork was not successful
            {
            	printf("Failed\n");
            	exit(0);
            } else if (pid == 0) // child process
            {
            	execvp(empty[0], empty);
            	printf("Execute failed\n");
            	exit(0);
            } else //Parent process
            {
            	wait(NULL);
            }

        }
        //Increase the arugent counter
        i++;

    }

    return 0;
}