#include <iostream>
#include <string>
#include <ctime>
#include <list>

using namespace std;

struct Player {
    string id;
    string name;
    tm date;
};

bool check(Player a, Player b) {
    return (a.date.tm_year < b.date.tm_year) ||
           (a.date.tm_year == b.date.tm_year && a.date.tm_mon < b.date.tm_mon) ||
           (a.date.tm_year == b.date.tm_year && a.date.tm_mon == b.date.tm_year && a.date.tm_mday < b.date.tm_mday);
}

int main(){
    int n;
    cout << "Enter the number of players: ";
    cin >> n;
    //----Input & sort----
    list<Player> a;
    for (int i=0;i<n;i++){
        string id, name;
        tm date;
        cout << "player " << i + 1 << ":\n";
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin.ignore(); getline(cin, name);
        cout << "date (dd mm yyyy): ";
        cin >> date.tm_mday >> date.tm_mon >> date.tm_year;
        a.push_back(Player{id, name, date});
    }
    cout << "List:\n";
    for (Player player : a)
        cout << "ID: " << player.id << "\t Name: " << player.name << "\t" <<player.date.tm_mday << "/" << player.date.tm_mon << "/" << player.date.tm_year << "\n";
    // Sort
    a.sort(check);
    cout << "Sort:\n";
    for (Player player : a)
        cout << "ID: " << player.id << "\t Name: " << player.name << "\t" <<player.date.tm_mday << "/" << player.date.tm_mon << "/" << player.date.tm_year << "\n";

    // youngestPlayer
    Player youngestPlayer = a.back();
    cout << "Youngest player:\n";
    for (Player player : a)
        if (player.date.tm_year == youngestPlayer.date.tm_year &&
        player.date.tm_mon == youngestPlayer.date.tm_mon &&
        player.date.tm_mday == youngestPlayer.date.tm_mday) 
            cout << player.name << "\n";
    return 0;
}
