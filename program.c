#include <windows.h>
#include <stdio.h>

int main(void)
{
	//start the FH4 executable form current directory, exit if the executable not in directory
	puts("Starting ForzaHorizon4_Or.exe");
	if(system("start ForzaHorizon4_Or.exe"))
	{
		return 1;
	}

	puts("Waiting for alert to show.\n");
	HWND db;
	do{
		//if the gme opens w/o alert, exit yay
		if(FindWindowA(0, "Forza Horizon 4"))
		{
			printf("alert didn't come! \\o/\n");
			return 0;
		}

		db = FindWindowA(0, "Your system falls below minimum settings.");
		// printf("got %llx\n", db);
		Sleep(2000);
	}while(!db);

	//printf("%llx\n", db);

	//close the alert box allowing game to load
	SendMessage(db, WM_CLOSE, 0, 0);

	return 0;
}