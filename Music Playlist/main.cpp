//
//  main.cpp
//  Lab 26.5 Link List 02
//
//  Created by Kevin Tran on 6/11/19.
//  Copyright © 2019 Kevin Tran. All rights reserved.
//

#include <iostream>
#include "PlaylistNode.h"
    
    // function prototype
void PrintMenu(string title);
    
    // start main function
int main()
{
    string plTitle;
        
    cout << "Enter playlist's title: ";
    getline(cin, plTitle);
        
    PrintMenu(plTitle);
}
    
    // PrintMenu function implementation
    // PrintMenu() takes the playlist title as a parameter and outputs a menu
    // of options to manipulate the playlist. Each option is represented by a
    // single character. Build and output the menu within the function.
void PrintMenu(string title){
    Playlist list;
    string id;
    string sname;
    string aname;
    int length;
    int oldPos;
    int newPos;
    char choice;
        
    while (true)
    {
        cout << endl << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
            
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); //flush newline
            
        if (choice == 'q' || choice == 'Q')
        {
            exit(1);
        }
        else if (choice == 'a' || choice == 'A')
        {
            cout << "\nADD SONG" << endl;
            cout << "Enter song's unique ID: ";
            cin >> id;
            cin.ignore();//ignore newline
            cout << "Enter song's name: ";
            getline(cin, sname);
            cout << "Enter artist's name: ";
            getline(cin, aname);
            cout << "Enter song's length (in seconds): ";
            cin >> length;
            list.AddSong(id, sname, aname, length);
        }
        else if (choice == 'd' || choice == 'D')
        {
            cout << "\nREMOVE SONG" << endl;
            cout << "Enter song's unique ID: ";
            cin >> id;
            list.RemoveSong(id);
        }
        else if (choice == 'c' || choice == 'C')
        {
            cout << "\nCHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position: ";
            cin >> oldPos;
            cout << "Enter new position for song: ";
            cin >> newPos;
            list.ChangePosition(oldPos, newPos);
        }
        else if (choice == 's' || choice == 'S')
        {
            cout << "\nOUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name: ";
            getline(cin, aname);
            list.SongsByArtist(aname);
        }
        else if (choice == 't' || choice == 'T')
        {
            cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << list.TotalTime() << " seconds" << endl;
        }
        else if (choice == 'o' || choice == 'O')
        {
            
            cout << endl << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.PrintList();
        }
        else
            {
            cout << "Invalid menu choice! Please try again." << endl;
        }
    }
} // end of PrintMenu function
   

