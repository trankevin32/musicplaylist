//
//  PlaylistNode.h
//  Lab 26.5 Link List 02
//
//  Created by Kevin Tran on 6/11/19.
//  Copyright © 2019 Kevin Tran. All rights reserved.
//

// Header files section
#ifndef POLYLIST_H
#define POLYLIST_H
#include <iostream>
#include <string>
using namespace std;

/****** PlaylistNode class specifications ******/

class PlaylistNode
{
public:
    PlaylistNode();
    PlaylistNode(string id, string songname, string artist, int length);
    void InsertAfter(PlaylistNode* ptr);
    void SetNext(PlaylistNode* ptr);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
    
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

/****** Playlist class specifications ******/
class Playlist
{
private:
    PlaylistNode *head;
    PlaylistNode *tail;

public:
    Playlist();
    void AddSong(string id, string songname, string artistname, int length);
    bool RemoveSong(string id);
    void PrintList();
    bool ChangePosition(int oldPos, int newPos);
    void SongsByArtist(string artist);
    int TotalTime();
};
#endif
