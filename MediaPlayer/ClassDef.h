#pragma once

template <class Type>
struct nodeType {
    Type info;
    nodeType<Type>* next;
    nodeType<Type>* back;
};

template <class Type>
class MediaPlayer {
public:
    bool isEmpty();
    //function to determine if the list is empty 
    //post condition: return true if first is nullptr and return false otherwise 
    void displayMusicList();
    //function to print the content of each node
    int ListLength() const;
    //function to return the number of songs in the list
    //postCondition: the value of count is returned
    void playMusic(const Type& musicName);
    //function to play musicName if it's found in the list, use function searchForMusic to see whether musicName is in the list
    void playNext(nodeType<Type>* ptr);
    //function to play the next music in the list 
    //postCondition: the iterator now points to the next node
    void playPrev(nodeType<Type>* ptr);
    //function to play the previous music in the list
    //postCondition: the iterator points to the previous node
    void deleteMusic(const Type& deletedMusic);
    //function to delete deletedMusic from the list
    //if deletedMusic is found, the node containing deletedMusic is deleted from the list and count is decremented by 1
    void deleteMusicList();
    //function to delete the whole music list
    //postCondition: first=NULL, last=NULL, count=0
    bool searchForMusic(const Type& searchedMusic);
    //function to determine whether searchedMusic is in the music list
    //postCondition: the value true is returned if searchedMusic is in the list
    void addMusic(const Type& addedMusic);
    //function to add a new song to the music list
    //postCondition: addedMusic is inserted at the propper place in the list and count is incremented by 1
    MediaPlayer();
    //default constructor initializes the list to an empty state 
    //postCondition: first=NULL, last=NULL, count=0
    ~MediaPlayer();
    //destructor deletes all the nodes/songs from the music list by calling the function deleteMusicList
    //postCondition: the list object is destroyed
private:
    int count;
    nodeType<Type>* first;
    nodeType<Type>* last;
};