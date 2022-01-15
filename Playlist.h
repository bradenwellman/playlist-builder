#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

#include "Song.h"

class Playlist {

    // Public Members
public:

    // Default Constructor No Arguments
    Playlist();

    // Default Constructor with 2 arguments
    Playlist(string nameOfPlaylist,
             vector<Song*> ptrForPlaylist);

    // Setters
    void SetName(string nameOfPlaylist);
    void AddSongToList(Song* thisSong);
    void RemoveSongFromPlaylist(int songIndex);
    void RemovingFromAll(string songToRemove);
    void AddSongPlay();

    // Getters
    string GetName();
    void GetFirstLines();
    void GetSongNames();

    // Private Members
private:
    string playlistName;
    vector<Song*> songPointers;

};

#endif
