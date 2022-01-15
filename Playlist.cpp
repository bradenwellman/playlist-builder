#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;

// Default Constructor with no arguments
Playlist::Playlist() {
    playlistName = "No Playlist Name";
}

// Default constructor with 2 arguments
Playlist::Playlist(string nameOfPlaylist, vector<Song*> vectorOfPointers) {
    playlistName = nameOfPlaylist;
    songPointers = vectorOfPointers;
}

// Returning the name of the playlist
string Playlist::GetName() {
    return playlistName;
}

// Setting the name of the playlist
void Playlist::SetName(string nameOfPlaylist) {
    playlistName = nameOfPlaylist;
}

// Adding a song to the playlist
void Playlist::AddSongToList(Song *thisSong) {
    songPointers.push_back(thisSong);
}

// Getting the first lines of the songs in the playlists
void Playlist::GetFirstLines() {
    for (int i = 0; i < songPointers.size(); ++i) {
        cout << songPointers.at(i)->GetFirstLine() << endl;
    }
}

// Getting the name of the songs in the playlist
void Playlist::GetSongNames() {
    for (int i = 0; i < songPointers.size(); ++i) {
        cout << i << ": " << songPointers.at(i)->GetName() << endl << endl;
    }
}

// Removing a song from the playlist
void Playlist::RemoveSongFromPlaylist(int songIndex) {
    songPointers.erase(songPointers.begin() + songIndex);
}

// Removing a song from every playlist that it is in
void Playlist::RemovingFromAll(string songToRemove){

    // Loop to go through every song until we find it
    for (int i = 0; i < songPointers.size(); ++i) {

        // If the name of the song matches the provided name...
        if (songPointers.at(i)->GetName() == songToRemove){

            // Remove it from the playlist
            songPointers.erase(songPointers.begin() + i);
        }
    }
}

// Adding to the play count of the song
void Playlist::AddSongPlay() {
    for (int i = 0; i < songPointers.size(); ++i) {
        songPointers.at(i)->AddPlay();
    }
}