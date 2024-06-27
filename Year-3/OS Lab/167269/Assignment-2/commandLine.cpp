#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<fcntl.h>


char *input = NULL;
size_t capline = 0;

int i;
char *token;
char *tok;
char *filename;
char *filename2;
char *array[512];


void makeTokens(char *input)
{
	i = 0;

	token = strtok(input, "\n ");

	while(token != NULL)
	{
		array[i++] = token;
		token = strtok(NULL, "\n ");
	}

	array[i] = NULL;
}

void execute()
{
	int pid = fork();

	if(pid != 0)
	{
		int s;
		waitpid(-1, &s, 0);
	}

	else
	{
		int fd2 = open(filename2, O_RDONLY);
		dup2(fd2, 0);
		close(fd2);

		int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		dup2(fd, 1);
		close(fd);

		if(execvp(array[0], array) == -1)
		{
			perror("Wrong command");
			exit(errno);
		}
	}
}

void displayPrompt()
{
	printf("Enter q for exit\n");
	printf("my_shell: ");
}


int main()
{
	while(1)
	{
		displayPrompt();
		getline(&input, &capline, stdin);

		if(strcmp(input, "\n") == 0)
		{
			perror("please type in command");
			continue;
		}

		input = strtok(input, "<");
		filename2 = strtok(NULL, "\n");

		if(filename2 == NULL)input = strtok(input, ">");
		else filename2 = strtok(filename2, ">");

		filename = strtok(NULL, "\n ");

		makeTokens(input);

		if(strcmp(array[0], "q") == 0)
		{
			printf("SYSTEM : Shell is exiting\n\n");
			return 0;
		}

		execute();
	}
}
