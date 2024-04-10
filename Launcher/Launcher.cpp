#include <iostream>
#include <windows.h>
#include <string.h>
#pragma comment(lib, "Winmm.lib")

using namespace std;

void countdown() {
	int max_time = 0;
	string status;

	cout << "Enter session limit in minutes: ";
	cin >> max_time;

	max_time = (max_time * 60) * 1000;
	Sleep(max_time);
	main();

	mciSendString(L"open \"D:/Programming/C++/Launcher/assets/time_up_sound.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString(L"play mp3 from 0 to 1500 wait repeat", NULL, 0, NULL);

	cout << "Session time has expired. Please take a break!\n Type dismiss to exit.";
	cin >> status;
	mciSendString(L"close mp3", NULL, 0, NULL);
}

int main(){
	string username = "NotOfficialAash";
	cout << "Welcome " << username << endl;
	countdown();


}