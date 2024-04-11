#include <iostream>
#include <windows.h>
#include <thread>
#pragma comment(lib, "Winmm.lib")

using namespace std;

void countdown(int maxTime) {
	char dismiss;
	for (int i = maxTime * 60 ; i > 0; i--) {
		this_thread::sleep_for(1000ms);
	}

	mciSendString(L"open time_up_sound.mp3 type mpegvideo alias timeUpSound", NULL, 0, NULL);
	mciSendString(L"play timeUpSound from 0 to 1500 wait repeat", NULL, 0, NULL);

	while (dismiss != 'D') {
		cout << "\nYour session time has expires. Take a break. Type D to dismiss and close.\n";
		cin >> dismiss;
	}

	mciSendString(L"stop timeUpSound", NULL, 0, NULL);
	mciSendString(L"close timeUpSound", NULL, 0, NULL);
}


int main(){
	int sessionDuration;
	cout << "Enter SESSION TIME in MINUTES";
	cin >> sessionDuration;

}