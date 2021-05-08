#include <windows.h>
#include <stdio.h>

#define MAX_CHECKS 60

int main(void)
{
	//start the FH4 executable form current directory, exit if the executable not in directory

	puts("Starting ForzaHorizon4_Or.exe");
	if(system("start ForzaHorizon4_Or.exe"))
	{
		return 1;
	}

	puts("Waiting for alert to show.\n");

	HWND db = 0;

	for (int i = 0; !db && i < MAX_CHECKS; ++i)
	{
		db = FindWindowA(0, "Your system falls below minimum settings.");
		// printf("got %llx\n", db);
		Sleep(2000);
	}

	//printf("%llx\n", db);

	//close the alert box allowing game to load
	if(db)
		SendMessage(db, WM_CLOSE, 0, 0);
	else
		puts("Timed out");

	return 0;
}