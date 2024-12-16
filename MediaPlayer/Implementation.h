#include "ClassDef.h"
#include <iostream>
using namespace std;

template <class Type>
MediaPlayer <Type>::MediaPlayer() {
	count = 0;
	first = last = nullptr;
}

template <class Type>
MediaPlayer<Type>::~MediaPlayer() {
	nodeType<Type>* temp;
	nodeType<Type>* trail;

	if (isEmpty()) {}
	else {
		temp = first->next;
		while (temp != first) {
			trail = temp->next;
			delete temp;
			temp = trail;
		}
		delete first;
		first = nullptr;
	}
}

template <class Type>
bool MediaPlayer <Type>::isEmpty() {
	return (first == nullptr);
}

template <class Type>
int MediaPlayer <Type>::ListLength() const{
	return count;
}

template <class Type>
void MediaPlayer <Type>::displayMusicList() {
	if (isEmpty()) {
		std::cout << std::endl;
		std::cout << "=============================================================" << std::endl;
		std::cout << "                    The list is empty!" << std::endl;
		std::cout << "=============================================================" << std::endl;
	}
	else {
		std::cout << std::endl;
		nodeType<Type>* temp = new nodeType<Type>;
		temp = first;
		do {
			std::cout << temp->info << std::endl;
			temp = temp->next;
		} while (temp != last->next); 
	}
}

template <class Type>
bool MediaPlayer <Type>::searchForMusic(const Type& searchedMusic) {
	bool found = false;
	nodeType<Type>* current;
	current = first;
	while (current->next != first && !found) {
		if (current->info == searchedMusic)
			found = true;
		else
			current = current->next;
	}
	if (current->info == searchedMusic)
		found = true;
	return found;
}

template <class Type>
void MediaPlayer <Type>::addMusic(const Type& addedMusic) {
	nodeType <Type>* trail;
	nodeType <Type>* current;
	nodeType <Type>* newMusic = new nodeType<Type>;
	newMusic->info = addedMusic;
	newMusic->back = nullptr;
	newMusic->next = nullptr;
	if (isEmpty()) {
		first = last = newMusic;
		first->next = last;
		first->back = last;
		last->next = first;
		last->back = first;
		count++;
		std::cout << std::endl;
		cout << "\n======================================================\n"
			<< "              Song added successfully."
			<< "\n=======================================================\n";
	}
	
	else {
		if (searchForMusic(addedMusic)) {
			std::cout << std::endl;
			std::cout << "====================================================" << std::endl;
			std::cout << "            The music is already in the list!" << std::endl;
			std::cout << "====================================================" << std::endl;
			delete newMusic;
		}
		else {
			if(newMusic->info < first->info) {
				newMusic->next = first;
				newMusic->back = last;
				first->back = newMusic;
				first = newMusic;
				last->next = first;
				count++;
				std::cout << std::endl;
				cout << "\n======================================================\n"
				  	 << "               Song added successfully."
					 << "\n=======================================================\n";
			}
			else if (newMusic->info > last->info) {
				newMusic->next = first;
				newMusic->back = last;
				first->back = newMusic;
				last->next = newMusic;
				last = last->next;
				count++;
				std::cout << std::endl;
				cout << "\n======================================================\n"
					 << "                Song added successfully."
					 << "\n=======================================================\n";
			}
			else {
				current = first;
				while (current->next != first) {
					trail = current;
					current = current->next;
					if (newMusic->info > trail->info && newMusic->info < current->info) {
						newMusic->back = trail;
						trail->next = newMusic;
						newMusic->next = current;
						current->back = newMusic;
						count++;
						std::cout << std::endl;
						cout << "\n======================================================\n"
							 << "           Song added successfully."
							 << "\n=======================================================\n";
					}
				}
			}
		}
	}
}

template <class Type>
void MediaPlayer <Type>::deleteMusicList() {
	nodeType<Type>* temp;
	nodeType<Type>* trail;

	if (isEmpty()) {
		std::cout << std::endl;
		std::cout << "======================================================" << std::endl;
		std::cout << "          The list is already empty!" << std::endl;
		std::cout << "======================================================" << std::endl;
	}
	else {
		temp = first->next;
		while (temp != first) {
			trail = temp->next;
			delete temp;
			temp = trail;
		}
		delete first;
		first = nullptr;
		std::cout << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << "          All songs have been deleted." << std::endl;
		std::cout << "====================================================" << std::endl;
	}
}

template <class Type>
void MediaPlayer <Type>::deleteMusic(const Type& deletedMusic) {
	if (isEmpty()) {
		std::cout << std::endl;
		std::cout << "===================================================" << std::endl;
		std::cout << "         The list is already empty!" << std::endl;
		std::cout << "===================================================" << std::endl;
	}
	else if (searchForMusic(deletedMusic)) {
		nodeType<Type>* temp;
		nodeType<Type>* trail;
		if (first == last) {
			temp = first;
			delete temp;
			first = last = nullptr;
			std::cout << std::endl;
			cout << "==================================================\n"
				 << "           Song deleted successfully.\n"
				 << "===================================================\n";
			count = 0;
		}
		else {
			if (first->info == deletedMusic) {
				temp = first;
				first = first->next;
				last->next = first;
				first->back = last;
				delete temp;
				count--;
				std::cout << std::endl;
				cout << "==================================================\n"
					 << "           Song deleted successfully.\n"
					 << "==================================================\n";
			}
			else if (last->info == deletedMusic) {
				temp = last;
				last = last->back;
				first->back = last;
				last->next = first;
				delete temp;
				count--;
				std::cout << std::endl;
				cout << "==================================================\n"
					<< "           Song deleted successfully.\n"
					<< "==================================================\n";
			}
			else {
				bool found = false;
				temp = first;
				while (temp-> next != first && !found) {
					trail = temp;
					temp = temp->next;
					if (deletedMusic == temp->info) {
						trail->next = temp->next;
						temp->next->back = trail;
						delete temp;
						found = true;
						count--;
						std::cout << std::endl;
						cout << "==================================================\n"
							<< "           Song deleted successfully.\n"
							<< "==================================================\n";
					}
				}
			}
			
		}
	}
	else {
		std::cout << std::endl;
		std::cout << "====================================================" << std::endl;
		std::cout << "              The song does not exist!" << std::endl;
		std::cout << "====================================================" << std::endl;
	}
}

template <class Type>
 void MediaPlayer<Type>::playMusic(const Type& musicName){
	if (searchForMusic(musicName)) {
		std::cout << std::endl;
		std::cout << "======================================================" << std::endl;
		std::cout << "            The song " << musicName << " is playing right now." << std::endl;
		std::cout << "======================================================" << std::endl;
		bool found = false;
		nodeType<Type>* current;
		current = first;
		while (current->next != first && !found) {
			if (current->info == musicName)
				found = true;
			else
				current = current->next;
		}
		int choice = 0;
		while (choice != 3) {
			std::cout << std::endl;
			cout << "-------------------------------\n"
				<< "1. Play next song.\n"
				<< "2. Play previous song.\n"
				<< "3. Stop and back to main menu.\n"
				<< "-------------------------------\n";
			std::cin >> choice;
			if (choice == 1) {
				playNext(current);
				current = current->next;
			}
			else if (choice == 2) {
				playPrev(current);
				current = current->back;
			}
			else if (choice == 3) {
				break;
			}
		}
	}
	else {
		cout << endl;
		cout << "==================================================\n"
			<< "        The song doesn't exist, try again.\n"
			<< "===================================================\n";
	}
}

template <class Type>
void MediaPlayer<Type>::playNext(nodeType<Type>* ptr) {
	std::cout << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "         The song " << ptr->next->info << " is playing right now." << std::endl;
	std::cout << "===================================================" << std::endl;
}

template <class Type>
void MediaPlayer<Type>::playPrev(nodeType<Type>* ptr) {
	std::cout << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "         The song " << ptr->back->info << " is playing right now." << std::endl;
	std::cout << "===================================================" << std::endl;
}