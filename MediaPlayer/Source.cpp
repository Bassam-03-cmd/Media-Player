#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Implementation.h"
using namespace std;

void mainMenu();
void Clr();

int main() {
	MediaPlayer <string> player;
	int choice = 0;
	while (true) {
		mainMenu();
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			cout << "Enter the song's name: ";
			string song;
			getline(cin, song);
			player.addMusic(song);
			this_thread::sleep_for(chrono::milliseconds(3000));
		}

		else if (choice == 2) {
			player.displayMusicList();
			this_thread::sleep_for(chrono::milliseconds(5000));
		}

		else if (choice == 3) {
			cout << "Type the song name to play: ";
			string song;
			getline(cin, song);
			player.playMusic(song);
			this_thread::sleep_for(chrono::milliseconds(1000));	
		}

		else if (choice == 4) {
			cout << "Type song name to delete (type \"all\" to delete all): ";
			string song;
			getline(cin, song);
			if (song == "all") {
				player.deleteMusicList();
				this_thread::sleep_for(chrono::milliseconds(1750));
			}
			else {
				player.deleteMusic(song);
				this_thread::sleep_for(chrono::milliseconds(1750));
			}
		}

		else if (choice == 5) {
			Clr();
			cout << "----------------------\n"
				<< "Media Player Closed.\n"
				<< "----------------------\n";
			break;
		}
	}
	return 0;
}

void mainMenu() {
	Clr();
	cout << "-------------------------------\n"
		<< "1. Add a song.\n"
		<< "2. View songs.\n"
		<< "3. Play a song.\n"
		<< "4. Delete a song.\n"
		<< "5. Exit.\n"
		<< "-------------------------------\n";
}

void Clr() {
	for (int n = 0; n < 5; n++)
		cout << "\n\n\n\n\n\n\n\n\n\n";
}