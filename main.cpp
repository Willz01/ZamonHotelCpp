#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>

using namespace std;

string r_NY(bool cond);


void home_display();

typedef std::chrono::system_clock Clock;

int rdn(int y, int m, int d);

class Room {
private:
    int room_no;
public:
    string occupant;
    string type;
    double charge;
    bool availability;
    int period;

    Room(int roomNo, string occupant, string type, double charge, bool availability, int period)
            : room_no(roomNo), occupant(std::move(occupant)), type(std::move(type)), charge(charge),
              availability(availability),
              period(period) {}

    int getRoomNo() const {
        return room_no;
    }

    void setRoomNo(int roomNo) {
        room_no = roomNo;
    }

    string getOccupant() const {
        return occupant;
    }

    void setOccupant(string occupant) {
        Room::occupant = occupant;
    }

    const string &getType() const {
        return type;
    }

    void setType(const string &type) {
        Room::type = type;
    }

    double getCharge() const {
        return charge;
    }

    void setCharge(double charge) {
        Room::charge = charge;
    }

    bool isAvailability() const {
        return availability;
    }

    void setAvailability(bool availability) {
        Room::availability = availability;
    }

    int getPeriod() const {
        return period;
    }

    void setPeriod(int period) {
        Room::period = period;
    }

};

int main() {
    // Populate rooms;
    Room r1(1, "-", "Bedroom\t\t", 1300, true, 0);
    Room r2(2, "-", "Lounge\t\t\t", 4500, true, 0);
    Room r3(3, "-", "Conference room", 3000, true, 0);
    Room r4(4, "-", "Bedroom\t\t", 1300, true, 0);
    Room r5(5, "-", "Apartment\t\t", 7650, true, 0);
    Room r6(6, "-", "Bedroom\t\t", 1300, true, 0);
    vector<Room> rooms;
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    rooms.push_back(r4);
    rooms.push_back(r5);
    rooms.push_back(r6);
    /* ***************************** */
    int choice;
    int room_number;
    do {
        home_display();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Room no.\t\t Occupant\t\t\t Type\t\t\tFi\t Charge(SEK)\t\t Availability\t\t Period(day(s))\t\t"
                     << endl;
                for (auto &room : rooms) {
                    // 0,1,2,3,4,5
                    cout << room.getRoomNo() << "\t\t\t\t " << room.getOccupant() << "\t\t\t\t "
                         << room.getType() <<
                         "\t\t " << room.getCharge() << "\t\t\t\t " << r_NY(room.isAvailability())
                         << "\t\t\t\t\t " << room.getPeriod() << "\t\t\t\t\n";
                }
                break;
            case 3:
                cout << "Enter room number : ";
                cin >> room_number;
                if (room_number <= 6) {
                    cout << "Here\n";
                    // room info
                    for (int i = 0; i <= rooms.size() - 1; ++i) {
                        if (rooms.at(i).getRoomNo() == room_number) {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Occupant name : ";
                            string occupant_name;
                            getline(cin, occupant_name);
                            rooms.at(i).setOccupant(occupant_name);   //TODO(bug) -- sets name to blank
                            int dayFrom, monthFrom, dayTo, monthTo;
                            int period;
                            cout << "From--> " << endl;
                            cout << "Day : ";
                            cin >> dayFrom;
                            cout << "Month : ";
                            cin >> monthFrom;
                            cout << "To --->" << endl;
                            cout << "Day : ";
                            cin >> dayTo;
                            cout << "Month : ";
                            cin >> monthTo;

                            auto now = Clock::now();
                            time_t now_c = Clock::to_time_t(now);
                            struct tm *parts = localtime(&now_c);
                            period = rdn(1900 + parts->tm_year, monthFrom, dayFrom) -
                                     rdn(1900 + parts->tm_year, monthTo, dayTo);
                            rooms.at(i).setPeriod(abs(period));
                            rooms.at(i).setAvailability(false);

                            break;
                        } else {
                            //TODO
                        }
                    }
                } else {
                    //TODO
                }
                break;
            case 6 :
                cout << "Thanks for trusting Zamon!";
                exit(0);
            default:
                cout << "Invalid input!\n";
        }
    } while (choice != 6);


    return 0;
}

string r_NY(bool cond) {
    return cond == 1 ? "A" : "N";
}

void home_display() {
    cout << "******************************************\n";
    cout << "******************************************\n";
    cout << "**     Zamon Hotel Booking system       **\n";
    cout << "******************************************\n";
    cout << "******************************************\n";
    cout << "1 : Availability\n";
    cout << "2 : Room features\n";
    cout << "3 : Book room\n";
    cout << "4 : Customer details\n";
    cout << "5 : Restaurant\n";
    cout << "6 : Exit\n";
    cout << "Enter choice id : ";
}

int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}


