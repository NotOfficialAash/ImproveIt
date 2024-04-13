#include <iostream>
#include <windows.h>
#include <thread>
#include <fstream>
#include <string>
#pragma comment(lib, "Winmm.lib")

using namespace std;

int exitProgram = 0;
void oProgram();
void aProgram();
void rProgram();

void countdown(float minTime)
{
	char dismiss = 'N';
	for (float i = minTime * 60; i > 0; i--)
	{
		if(exitProgram != 1)
		{
			this_thread::sleep_for(1000ms);
		}
		else
		{
			break;
		}
	}

	mciSendString(L"open \"resources/time_up_sound.mp3\" type mpegvideo alias timeUsnd", NULL, 0, NULL);
	mciSendString(L"play timeUsnd from 0 to 1500 repeat", NULL, 0, NULL);
	
	while (dismiss != 'd' && exitProgram != 1)
	{
		cout << "\nYour session time has expires. Take a break. Type 'd' to dismiss.\n";
		cin >> ws;
		cin.get(dismiss);
	}
		
	mciSendString(L"stop timeUsnd", NULL, 0, NULL);
	mciSendString(L"close timeUsnd", NULL, 0, NULL);
}


void launcher() 
{
	string lineInFile;
	fstream pListFile;
	pListFile.open("resources/program_list.txt");
	getline(pListFile, lineInFile);
	
	if (lineInFile.empty())
	{
		cout << "You have no programs set. You need to add them to the list." << endl;
		aProgram();
		cout << "Now please restart the program for it to initialize";
	}
	else
	{
		while (exitProgram != 1)
		{
			char status = 'z';
			cout << "Enter 'a' to add new programs to list." << endl << "Enter 'l' to open programs present in the list." << endl;
			cout << "Enter 'r' to remove programs form list." << endl << "Enter 'e' to exit." << endl;
			cin >> ws;
			cin >> status;

			switch (status)
			{
			case 'a':
				aProgram();
				break;
			case 'l':
				oProgram();
				break;
			case 'r':
				rProgram();
				break;
			case 'e':
				exitProgram = 1;
				break;
			default:
				cout << "No option called '" << status << "' Try again" << endl;
			}
		}
	}
	pListFile.close();
}


int main()
{
	float minTime = 0;

	cout << "Welcome" << endl << "Enter SESSION TIME in MINUTES:" << endl;
	cin >> ws;
	cin >> minTime;

	thread timerThread(countdown, minTime);
	thread launcherThread(launcher);

	timerThread.join();
	launcherThread.join();

	exit(0);
}