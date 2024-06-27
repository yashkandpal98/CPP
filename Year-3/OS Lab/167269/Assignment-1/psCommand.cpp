#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int main()
{
	char *cmd = "ps";
	char *args[3];
	args[0] = "ps";
	args[1] = "ax";
	args[2] = NULL;

	execvp(cmd, args);

	return 0;
}
