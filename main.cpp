#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Player {
private:
    string name;
    int position;
    int money;
    vector<Place> board = {
        Place("START", 0),
        Place("A1", 50),
        Place("A2", 80),
        Place("A3", 100),
        Place("WORKHOUSE", 0),
        Place("UTILITY 1", 50),
        Place("TRAIN 1", 50),
        Place("JAIL", 0),
        Place("SHELTER", 0),
        Place("CHANCE", 0),
        Place("TAXES", 0)
    };


public:
    Player(string playerName, int initialMoney, ) : name(playerName), position(0), money(initialMoney) {}

    void move(int newPosition) {
        position += newPosition;
    }

    void addProperty(const Property& property) {
        properties.push_back(property);
        cout << name << " acquired property: " << property.name << " worth $" << property.value << endl;
    }

    void changeMoney(int amount) {
        money += amount;
    }

    void showProperties() const {
        cout << name << "'s properties:" << endl;
        for (const auto& property : properties) {
            cout << "- " << property.name << " ($" << property.value << ")" << endl;
        }
    }


    string getName() const {
        return name;
    }

    int getMoney() const {
        return money;
    }

    int getPosition() const {
        return position;
    }
};


class Place {
private:
    string name;
    int value;
    int position;  // Dodano pole pozycji
    Player* owner;

public:
    Place(string placeName, int placeValue, int placePosition)
        : name(placeName), value(placeValue), position(placePosition), owner(nullptr) {}

    void setOwner(Player* newOwner) {
        owner = newOwner;
        if (owner != nullptr) {
            cout << owner->getName() << " now owns " << name << " at position " << position << endl;
        }
    }



    string getOwnerName() const {
        return owner ? owner->getName() : "No owner";
    }

    string getName() const {
        return name;
    }

    int getValue() const {
        return value;
    }

    int getPosition() const {
        return position;
    }
};



int main() {
    vector<Place> board = {
        Place("START", 0, 0),
        Place("A1", 50, 1),
        Place("A2", 80, 2),
        Place("A3", 100, 3),
        Place("WORKHOUSE", 0, 4),
        Place("UTILITY 1", 50, 5),
        Place("TRAIN 1", 50, 6),
        Place("JAIL", 0, 7),
        Place("SHELTER", 0, 8),
        Place("CHANCE", 0, 9),
        Place("TAXES", 0, 10)
    };



    int n;
    cout << "Enter the number of players: ";
    cin >> n;
    const int BoardSize = 10;
    vector<Player> players;

    for (int i = 0; i < n; ++i) {
        string playerName = "player" + to_string(i + 1);
        int initialMoney = 200;
        players.emplace_back(playerName, initialMoney);
    }



    int turn=0;
    string s;
    while(cin>>s) {
        turn+=1;
        if(s=="Move") {
            int arugment, player_id;
            cin>>arugment;
            player_id = turn%n;

            user = players[player_id--];
            user.move(arugment);

            Place& currentPlace = board[user.getPosition()];

            if (currentPlace.isOwned()) {
                if (user.getName() == currentPlace.getName()) {
                    user.changeMoney()
                }
            }
        }









    for (const auto& player : players) {
        player.showStatus();
        cout << "------------------------" << endl;
    }

}
