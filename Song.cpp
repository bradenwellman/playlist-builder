#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#include "Song.h"

// Default Constructor
Song::Song(string nameOfSong, string firstLine, int numPlays) {
    songName = nameOfSong;
    songLine = firstLine;
    numPlays = 0;
}

// Set the name of the song
void Song::SetName(string nameOfSong) {
    songName = nameOfSong;
}

// Set the first line of the song
void Song::SetFirstLine(string firstLine){
    songLine = firstLine;
}

// Get the name of the song
string Song::GetName() {
    return songName;
}

// Get the first line of the song
string Song::GetFirstLine() {
    return songLine;
}

// Get the number of plays the song has
int Song::GetNumPlays() {
    return numPlays;
}

// Add to the play count of the song
void Song::AddPlay() {
    numPlays = numPlays + 1;
}