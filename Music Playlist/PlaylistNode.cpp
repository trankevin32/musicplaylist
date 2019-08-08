//
//  PlaylistNode.cpp
//  Lab 26.5 Link List 02
//
//  Created by Kevin Tran on 6/11/19.
//  Copyright © 2019 Kevin Tran. All rights reserved.
//


// Header files section
#include "PlaylistNode.h"

/****** PlaylistNode class implementation ******/

// Default constructor implementation
PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

// Parameterized constructor implementation
PlaylistNode::PlaylistNode(string id, string songname, string artist, int length)
{
    uniqueID = id;
    songName = songname;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}

// InsertAfter function implementation
void PlaylistNode::InsertAfter(PlaylistNode* ptr)
{
//    this->SetNext(ptr->GetNext());
//    ptr->SetNext(this);

}

// SetNext function implementation
void PlaylistNode::SetNext(PlaylistNode* ptr)
{
    nextNodePtr = ptr;
}

// GetID function implementation
string PlaylistNode::GetID()
{
    return uniqueID;
}

// GetSongName function implementation
string PlaylistNode::GetSongName()
{
    return songName;
}

// GetArtistName function implementation
string PlaylistNode::GetArtistName()
{
    return artistName;
}

// GetSongLength function implementation
int PlaylistNode::GetSongLength()
{
    return songLength;
}

// GetNext function implementation
PlaylistNode* PlaylistNode::GetNext()
{
    return nextNodePtr;
}

// PrintPlaylistNode function implementation
void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

/****** Playlist class implementation ******/

// Default constructor implementation
Playlist::Playlist()
{
    head = tail = 0;
}

// AddSong function implementation
void Playlist::AddSong(string id, string songname, string artistname, int length)
{
    //PlaylsitNode* n;
    //n = new PlaylistNode(id,songname,artist);
    PlaylistNode* n = new PlaylistNode(id, songname, artistname, length); //create new node
    if (head == 0)
        head = tail = n;
    else
    {
        n->InsertAfter(tail);
        tail = n;
    }
}

// RemoveSong function implementation
bool Playlist::RemoveSong(string id)
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return false;
    }
    
    PlaylistNode* curr = head;
    PlaylistNode* prev = NULL;
    while (curr != NULL)
    {
        if (curr->GetID() == id)
        {
            break;
        }
        prev = curr;
        curr = curr->GetNext();
    }
    
    if (curr == NULL) //not found
    {
        cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
        return false;
    }
    else
    {
        if (prev != NULL)
            prev->SetNext(curr->GetNext());
        else
            head = curr->GetNext();
        
        if (tail == curr)
            tail = prev;
        cout << "\"" << curr->GetSongName() << "\" removed" << endl;
        delete curr;
        return true;
    }
}

// ChangePosition function implementation
bool Playlist::ChangePosition(int oldPos, int newPos)
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return false;
    }
    
    
    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;
    
    int pos;
    if (head == NULL || head == tail)
        return false;
    
    //first locate the node that is to be move
    for (pos = 1; curr != NULL && pos < oldPos; pos++)
    {
        prev = curr;
        curr = curr->GetNext();
    }
    if (curr != NULL) //found a node at given position
    {
        string currentSong = curr->GetSongName();
        
        // delete it from the current list and later insert it
        // into the list at specified new poistion
        // after removing it from the curretn list, we don't
        // deallocate it but simply insert it in new position
        if (prev == NULL)
            head = curr->GetNext();
        else
        {
            prev->SetNext(curr->GetNext());
        }
        
        if (curr == tail) //if we removed the tail node
            tail = prev;
        
        PlaylistNode* curr1 = curr;
        prev = NULL;
        curr = head;
        //now locate the new position
        for (pos = 1; curr != NULL && pos < newPos; pos++)
        {
            prev = curr;
            curr = curr->GetNext();
        }
        
        //insert in located position
        
        if (prev == NULL)
        {
            curr1->SetNext(head);
            head = curr1;
        }
        else
            curr1->InsertAfter(prev);
        
        if (curr == NULL)
            tail = curr1;
        
        
        cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
        return true;
        
    }
    else
    {
        cout << "Song's current position is invalid" << endl;
        return false;
    }
}

// SongsByArtist function implementation
void Playlist::SongsByArtist(string artist)
{
    if (head == NULL)
        cout << "Playlist is empty." << endl;
    else
    {
        PlaylistNode* curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (curr->GetArtistName() == artist)
            {
                cout << endl << i << "." << endl;
                curr->PrintPlaylistNode();
            }
            curr = curr->GetNext();
            i++;
        }
    }
}

// TotalTime function implementation
int Playlist::TotalTime()
{
    int total = 0;
    PlaylistNode* curr = head;
    
    while (curr != NULL)
    {
        total += curr->GetSongLength();
        curr = curr->GetNext();
    }
    
    return total;
}


// PrintList function implementation
void Playlist::PrintList()
{
    if (head == NULL)
        cout << "Playlist is empty." << endl;
    else
    {
        PlaylistNode* curr = head;
        int i = 1;
        while (curr != NULL)
        {
            cout << endl << i++ << "." << endl;
            curr->PrintPlaylistNode(); //call to print function from PlaylistNode class
            curr = curr->GetNext();
        }
    }
}
