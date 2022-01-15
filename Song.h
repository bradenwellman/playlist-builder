#ifndef SONG_H
#define SONG_H
#include <vector>
#include <string>

using namespace std;

class Song {
public:
    // Default Constructor
    Song(string nameOfSong = "No Name",
         string firstLine = "No First Line",
         int numPlays = 0);

    // Setters
    void SetName(string nameOfSong);
    void SetFirstLine(string firstLine);
    void AddPlay();

    // Getters
    string GetName();
    string GetFirstLine();
    int GetNumPlays();

private:
    string songName;
    string songLine;
    int numPlays;

};
#endif