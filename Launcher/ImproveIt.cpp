#include <iostream>
#include <windows.h>
#include <thread>
#include "Launcher.cpp"
#pragma comment(lib, "Winmm.lib")

using namespace std;

int exitProgram;

void addProgram();
void removeProgram();
void openProgram();


void countdown(float maxTime) {
	char dismiss = 'N';
	for (float i = maxTime * 60 ; i > 0; i = i--) {
		this_thread::sleep_for(1000ms);
	}

	mciSendString(L"open \"time_up_sound.mp3\" type mpegvideo alias timeUsnd", NULL, 0, NULL);
	mciSendString(L"play timeUsnd from 0 to 1500 repeat", NULL, 0, NULL);
	exitProgram = 1;
	
	while (dismiss != 'd') {
		cout << "\nYour session time has expires. Take a break. Type d to dismiss and close.\n";
		cin >> ws;
		cin.get(dismiss);
	}
		

	mciSendString(L"stop timeUsnd", NULL, 0, NULL);
	mciSendString(L"close timeUsnd", NULL, 0, NULL);
}


void launcher() {
	
	
}


int main(){
	float sessionDuration;

	cout << "Welcome";
	cout << "Enter SESSION TIME in MINUTES: \n";
	cin >> ws;
	cin >> sessionDuration;

	thread timerThread(countdown, sessionDuration);
	thread launcherThread(launcher);

	timerThread.join();
	launcherThread.join();

}