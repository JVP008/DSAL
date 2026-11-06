#include <bits/stdc++.h>
using namespace std;

class Song_info
{
public:
    string music_name;
    string author;
    int id;

    Song_info(string music_name = "", string author = "", int id = 0)
    {
        this->music_name = music_name;
        this->author = author;
        this->id = id;
    }

    string getName() const { return music_name; }
    string getAuthor() const { return author; }
    int getId() const { return id; }
};

class Node
{
public:
    Song_info data;
    Node *next;
    Node *prev;

    Node(Song_info song) : data(song), next(nullptr), prev(nullptr) {}
    friend class SongManager;
};

class SongManager
{
private:
    Node *head;
    Node *current;

public:
    SongManager() : head(nullptr), current(nullptr) {}

    ~SongManager()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void Add_song()
    {
        string name, author;
        int id;

        cout << "Enter song name: ";
        cin >> name;
        cin.clear();
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter ID: ";
        cin >> id;

        Node *check = head;
        while (check != nullptr)
        {
            if (check->data.music_name == name)
            {
                cout << "A song with this name already exists.\n";
                return;
            }
            check = check->next;
        }

        Song_info newSong(name, author, id);
        Node *newnode = new Node(newSong);

        if (head == nullptr)
        {
            head = newnode;
            current = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
        }

        cout << "Song added successfully.\n";
    }

    void Delete_song()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        int id;
        cout << "Enter ID of the song you want to delete: ";
        cin >> id;

        Node *temp = head;
        Node *pre = nullptr;

        while (temp != nullptr && temp->data.id != id)
        {
            pre = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Song not found.\n";
            return;
        }

        bool deletingCurrent = (temp == current);

        if (pre == nullptr)
        {
            head = temp->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
        }
        else
        {
            pre->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = pre;
            }
        }

        delete temp;

        if (deletingCurrent)
        {
            current = (pre != nullptr) ? pre : head;
        }

        if (head == nullptr)
        {
            current = nullptr;
        }
        else if (current == nullptr)
        {
            current = head;
        }

        cout << "Song deleted successfully.\n";
    }

    void Search_song()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        int id;
        cout << "Enter song ID to search: ";
        cin >> id;

        Node *temp = head;

        while (temp != nullptr && temp->data.id != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Song not found.\n";
        }
        else
        {
            cout << "Song found:\n";
            cout << "ID: " << temp->data.id << "\n";
            cout << "Name: " << temp->data.music_name << "\n";
            cout << "Author: " << temp->data.author << "\n";
        }
    }

    void Display_playlist()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        Node *temp = head;
        cout << "\nPlaylist:\n";

        while (temp != nullptr)
        {
            cout << (temp == current ? "* " : "  ");
            cout << "ID: " << temp->data.id
                 << " | Name: " << temp->data.music_name
                 << " | Author: " << temp->data.author << "\n";
            temp = temp->next;
        }
    }

    void Next_song()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current == nullptr)
        {
            current = head;
        }

        if (current->next == nullptr)
        {
            cout << "Already at the last song.\n";
        }
        else
        {
            current = current->next;
        }

        Show_current_song();
    }

    void Previous_song()
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        if (current == nullptr)
        {
            current = head;
        }

        if (current->prev == nullptr)
        {
            cout << "Already at the first song.\n";
        }
        else
        {
            current = current->prev;
        }

        Show_current_song();
    }

    void Show_current_song()
    {
        if (current == nullptr)
        {
            cout << "No current song.\n";
            return;
        }

        cout << "Current song -> ID: " << current->data.id
             << " | Name: " << current->data.music_name
             << " | Author: " << current->data.author << "\n";
    }
};

int main()
{
    SongManager sm;
    int ch = 1;

    while (ch)
    {
        int choice;
        cout << "\n===== Song Playlist Manager =====\n";
        cout << "1. Add song\n";
        cout << "2. Delete song\n";
        cout << "3. Search song\n";
        cout << "4. Display playlist\n";
        cout << "5. Next song\n";
        cout << "6. Previous song\n";
        cout << "7. Show current song\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            sm.Add_song();
            break;
        case 2:
            sm.Delete_song();
            break;
        case 3:
            sm.Search_song();
            break;
        case 4:
            sm.Display_playlist();
            break;
        case 5:
            sm.Next_song();
            break;
        case 6:
            sm.Previous_song();
            break;
        case 7:
            sm.Show_current_song();
            break;
        default:
            cout << "Invalid choice!\n";
        }

        cout << "Continue (1) or (0): ";
        cin >> ch;
    }

    return 0;
}
