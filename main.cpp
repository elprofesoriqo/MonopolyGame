#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Player {
private:
    string name;
    int position;
    int money;
    int blocked;

public:
    Player(string playerName, int initialMoney, int isBlocked) : name(playerName), position(0), money(initialMoney), blocked(isBlocked) {}

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

    int isBlocked() const{
        return blocked;
    }


    int getMoney() const {
        return money;
    }

    int getPosition() const {
        return position;
    }

    void makeBlockd(int turn) {
        blocked += turn;
    };
};


class Place {
private:
    string name;
    int value;
    int rent;
    int position;
    int blocked;// Dodano pole pozycji
    Player* owner;

public:
    Place(string placeName, int placeValue, int placeRent, int placePosition)
        : name(placeName), value(placeValue), rent(placeRent), position(placePosition), owner(nullptr) {}

    void setOwner(Player* newOwner) {
        owner = newOwner;
        if (owner != nullptr) {
            cout << owner->getName() << " now owns " << name << " at position " << position << endl;
        }
    }

    bool isOwned() const {
        return owner != nullptr;
    }


    string getOwnerName() const {
        return owner ? owner->getName() : "No owner";
    }

    string getName() const {
        return name;
    }

    int getRent() const {
        return rent;
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
        Place("START", 0, 0, 0),
        Place("A1", 50, 10, 1),
        Place("A2", 80, 10, 2),
        Place("A3", 100,10,  3),
        Place("WORKHOUSE", 0,0, 4),
        Place("UTILITY 1", 50, 10, 5),
        Place("TRAIN 1", 50, 10, 6),
        Place("JAIL", 0, 0,  7),
        Place("SHELTER", 0, 0, 8),
        Place("CHANCE", 0, 0,  9),
        Place("TAXES", 0, 0, 10)
    };



    int n;
    cin >> n;
    const int BoardSize = 10;
    vector<Player> players;

    for (int i = 0; i < n; ++i) {
        string playerName = "player" + to_string(i + 1);
        int initialMoney = 200;
        players.emplace_back(playerName, initialMoney, 0);
    }



    int turn=0;
    string s;
    while(cin>>s) {
        turn++;
        int player_id=turn%n;
        Player user = players[player_id--];

        if(user.isBlocked()==0) {
            if(s=="Move") {
                int arugment;
                cin>>arugment;

                user.move(arugment);

                Place& currentPlace = board[user.getPosition()];

                if (currentPlace.isOwned()) {
                    if (user.getName() != currentPlace.getName()) {
                        user.changeMoney(-currentPlace.getRent());
                    }
                }else {
                    if(currentPlace.getName()=="JAIL") {
                        user.makeBlockd(2);
                    }
                }



            }
        }else {
            user.makeBlockd(-1);
        }
    }

}
