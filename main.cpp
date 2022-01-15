#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
#include "Playlist.h"

using namespace std;

std::string GetUserString(const std::string& prompt);

// Definitions of all my functions
void AddSongsMenuOption(vector<Song*> &songList);
void ListSongsMenuOption(vector<Song*> songList);
void AddPlaylistMenuOption(vector<Playlist>& playlistList);
void AddSongToPlaylistMenuOption(const vector<Song*>& songList, vector<Playlist>& playlistList);
void ListPlaylistsMenuOption(vector<Playlist>& playlistList);
void PlayPlaylistMenuOption(vector<Playlist>& playlistList);
void RemovePlaylistMenuOption(vector<Playlist>& playlistList);
void RemoveSongFromPlaylistMenuOption(vector<Playlist>& playlistList);
void RemoveSongFromLibraryMenuOption(vector<Song*>& songList, vector<Playlist>& playlistList);
void OptionsMenuOption();
void QuitMenuOption();
void ListSongName(vector<Song*> songList);
int GetSongIndex();
int GetPlaylistIndex();
int GetSongIndexRemove();
int GetPlaylistIndexRemove();

// --------------------------------------- START OF MAIN --------------------------------------------------------------
int main() {

    // Introduction to the program
    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;


    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    vector<Song*> songList;
    vector<Playlist> playlistList;

    // Options menu that runs until user says quit
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            AddSongsMenuOption(songList);
        }
        else if (userMenuChoice == "list") {
            ListSongsMenuOption(songList);
        }
        else if (userMenuChoice == "addp") {
            AddPlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "addsp") {
            AddSongToPlaylistMenuOption(songList, playlistList);
        }
        else if (userMenuChoice == "listp") {
            ListPlaylistsMenuOption(playlistList);
        }
        else if (userMenuChoice == "play") {
            PlayPlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "remp") {
            RemovePlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "remsp") {
            RemoveSongFromPlaylistMenuOption(playlistList);
        }
        else if (userMenuChoice == "remsl") {
            RemoveSongFromLibraryMenuOption(songList, playlistList);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    // Deleting every song pointer before the project terminates
    for (int i = 0; i < songList.size(); ++i) {
        delete songList.at(i);
        songList.erase(songList.begin() + i);
    }

    return 0;
}

// ------------------------------------------- END OF MAIN -------------------------------------------------------------

// Prompt the user for a string and then store it
string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}

// Prompt user for an integer and store it
int GetUserInt(const string& prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}

// Adding a song pointer to the song library
void AddSongsMenuOption(vector<Song*> &songList) {

    // Variables we will need for this function
    string songName = "none";
    string firstLine = "none";
    const string DONE_KEYWORD = "DONE";

    // Keep entering songs until keyword "DONE" is entered
    cout << "Enter songs' names and first lines"
         << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

    // Get initial name of song
    songName = GetUserString("Song Name: ");

    // Loop
    while (songName != DONE_KEYWORD) {

        // Prompt user for the first line of the song, the song name
        firstLine = GetUserString("Song's first line: ");

        // Create a new Song
        Song* thisSong = new Song(songName, firstLine);
        songList.push_back(thisSong);

        // Prompt them for another song name
        songName = GetUserString("Song Name: ");

    }
}

// Lists every song, the first line, and the number of plays
void ListSongsMenuOption(vector<Song*> songList) {

    for (int i = 0; i < songList.size(); ++i) {

        // First return the name of the song
        cout << songList.at(i)->GetName() << ": \"";

        // Then return the first line of the song
        cout << songList.at(i)->GetFirstLine() << "\", ";

        // Then return the number of plays
        cout << songList.at(i)->GetNumPlays() << " play(s)." << endl << endl;

    }
}

// Adding a playlist to the vector of playlists
void AddPlaylistMenuOption(vector<Playlist>& playlistList) {

    string playlistName = "none";

    // Prompt user for the name of the playlist
    playlistName = GetUserString("Playlist Name: ");

    // Create the playlist with the user input name
    Playlist thisPlaylist = Playlist();
    thisPlaylist.SetName(playlistName);

    // Add playlist to the list of playlists
    playlistList.push_back(thisPlaylist);

}

// Adding a song pointer to a playlist
void AddSongToPlaylistMenuOption(const vector<Song*>& songList, vector<Playlist>& playlistList) {

    int playlistIndex;
    int songIndex;

    // List out all of the playlists
    ListPlaylistsMenuOption(playlistList);

    // Get index of the playlist
    playlistIndex = GetPlaylistIndex();

    // List the songs
    ListSongName(songList);

    // Get index of the song
    songIndex = GetSongIndex();

    // Add the song pointer to the list
    playlistList.at(playlistIndex).AddSongToList(songList.at(songIndex));

}

// Listing the names of all of the playlist
void ListPlaylistsMenuOption(vector<Playlist>& playlistList) {

    // List all of our playlists in the vector
    for (int i = 0; i < playlistList.size(); ++i) {
        cout << i << ": " << playlistList.at(i).GetName() << endl;
    }
    cout << endl;
}

// Prints out the first line of each song in the playlist, then adding to the song counter
void PlayPlaylistMenuOption(vector<Playlist>& playlistList) {

    int playlistIndex;

    // Print out all of the playlists
    ListPlaylistsMenuOption(playlistList);

    // Get index of the playlist we want
    playlistIndex = GetPlaylistIndex();

    // Print name of the playlist
    cout << "Playing songs from playlist: " << playlistList.at(playlistIndex).GetName() << endl;

    // Play all of the first lines
    playlistList.at(playlistIndex).GetFirstLines();
    cout << endl;

    // Add Play count to each of the songs
    playlistList.at(playlistIndex).AddSongPlay();


}

// Removing a playlist (not the songs in them) from the vector of playlists
void RemovePlaylistMenuOption(vector<Playlist>& playlistList) {

    int playlistIndex;

    // Print out all of the playlists
    ListPlaylistsMenuOption(playlistList);
    cout << endl;

    // Get index of the playlist we want to remove
    playlistIndex = GetPlaylistIndexRemove();

    // Erase the playlist
    playlistList.erase(playlistList.begin() + playlistIndex);
    cout << endl;

}

// Removing a song pointer from the playlist (not the library)
void RemoveSongFromPlaylistMenuOption(vector<Playlist>& playlistList) {

    int playlistIndex;
    int songIndex;

    // Print out all of the playlists
    ListPlaylistsMenuOption(playlistList);
    cout << endl;

    // Get index of the playlist we want
    playlistIndex = GetPlaylistIndex();

    // Print out the songs in the playlist
    playlistList.at(playlistIndex).GetSongNames();

    // Get index of the song they want
    songIndex = GetSongIndexRemove();

    // Remove the song from the playlist
    playlistList.at(playlistIndex).RemoveSongFromPlaylist(songIndex);

}

// Removes a song from every playlist, as well as the library of song pointers
void RemoveSongFromLibraryMenuOption(vector<Song*>& songList, vector<Playlist>& playlistList) {

    int songIndex;
    string songToRemove;

    // List all of the songs
    ListSongName(songList);

    // Get index of the song we want
    songIndex = GetSongIndexRemove();

    // Name of the song we want to remove
    songToRemove = songList.at(songIndex)->GetName();

    // Looping through and removing for every playlist
    for (int i = 0; i < playlistList.size(); ++i) {
        playlistList.at(i).RemovingFromAll(songToRemove);
    }

    // Deleting the song as well as freeing memory
    delete songList.at(songIndex);
    songList.erase(songList.begin() + songIndex);

}

// Index of the song and it's name
void ListSongName(vector<Song*> songList){

    for (int i = 0; i < songList.size(); ++i) {

        // Label the index of the song
        cout << i <<": ";

        // Return the name of the song
        cout << songList.at(i)->GetName() << endl;

    }
    cout << endl;
}

// The options menu (printed by default if the one of the options isn't entered)
void OptionsMenuOption() {
    cout << "add      Adds a list of songs to the library" << endl
         << "list     Lists all the songs in the library" << endl
         << "addp     Adds a new playlist" << endl
         << "addsp    Adds a song to a playlist" << endl
         << "listp    Lists all the playlists" << endl
         << "play     Plays a playlist" << endl
         << "remp     Removes a playlist" << endl
         << "remsp    Removes a song from a playlist" << endl
         << "remsl    Removes a song from the library (and all playlists)" << endl
         << "options  Prints this options menu" << endl
         << "quit     Quits the program" << endl << endl;
}

// If the user enters quit
void QuitMenuOption() {
    cout << "Goodbye!" << endl;
}

// Getting the index of the song pointer they want
int GetSongIndex(){

    int songIndex;

    // Prompt user for the index of the song they want
    cout << "Pick a song index number: ";
    cin >> songIndex;
    cin.ignore();
    cout << endl;

    return songIndex;

}

// Getting the index of the playlist that they want
int GetPlaylistIndex(){

    int playlistIndex;

    // Prompt user for the index of the playlist they want
    cout << "Pick a playlist index number: ";
    cin >> playlistIndex;
    cin.ignore();
    cout << endl;

    return playlistIndex;

}

// Getting the index of the song pointer they want to remove
int GetSongIndexRemove(){

    int songIndex;

    // Prompt user for the index of the song they want
    cout << "Pick a song index number to remove: ";
    cin >> songIndex;
    cin.ignore();
    cout << endl;

    return songIndex;

}

// Index of the playlist to remove
int GetPlaylistIndexRemove() {

    int playlistIndex;

    // Prompt user for the index of the playlist they want
    cout << "Pick a playlist index number to remove: ";
    cin >> playlistIndex;
    cin.ignore();
    cout << endl;

    return playlistIndex;

}