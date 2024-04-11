#include <iostream>
#include <windows.h>
#include <thread>
#include <limits>
#pragma comment(lib, "Winmm.lib")

using namespace std;

void countdown(float maxTime) {
	char dismiss = 'N';
	for (float i = maxTime * 60 ; i > 0; i = i--) {
		this_thread::sleep_for(1000ms);
	}

	mciSendString(L"open \"time_up_sound.mp3\" type mpegvideo alias timeUpSound", NULL, 0, NULL);
	mciSendString(L"play timeUpSound from 0 to 1500 repeat", NULL, 0, NULL);
	
	cout << "\nYour session time has expires. Take a break. Type d to dismiss and close.\n";
	cin >> ws;
	cin.get(dismiss);

	mciSendString(L"stop timeUpSound", NULL, 0, NULL);
	mciSendString(L"close timeUpSound", NULL, 0, NULL);
}


void launcher() {
	for (int i = 0; i < 100; i++) {
		cout << "Hi";
	}
}


int main(){
	float sessionDuration;
	cout << "Enter SESSION TIME in MINUTES: \n";
	cin >> ws;
	cin >> sessionDuration;

	thread timerThread(countdown, sessionDuration);
	thread launcherThread(launcher);

	timerThread.join();
	launcherThread.join();

}