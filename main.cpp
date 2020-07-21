#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "Room.h"
#include "Room.cpp"
#include "Customer.h"
#include "Customer.cpp"
#include <ctime>
#include <cmath>
#include "Room_feature.h"
#include "Room_feature.cpp"

using namespace std;

string r_NY(bool cond);

void home_display();

typedef std::chrono::system_clock Clock;

int rdn(int y, int m, int d);

int main() {
    // Populate rooms;
    Room r1(1, "-", "Bedroom\t\t", 1300, true, 0);
    Room r2(2, "-", "Lounge\t\t\t", 4500, true, 0);
    Room r3(3, "-", "Conference room", 3000, true, 0);
    Room r4(4, "-", "Bedroom\t\t", 1300, true, 0);
    Room r5(5, "-", "Apartment\t\t", 7650, true, 0);
    Room r6(6, "-", "Bedroom\t\t", 1300, true, 0);
    Room_feature r1_feature(r1, 3.5, 4.5, 3, 1, 1);
    Room_feature r2_feature(r2, 12.3, 7.5, 13, 4, 6);
    Room_feature r3_feature(r3, 7.5, 7.5, 35, 0, 17);
    Room_feature r4_feature(r4, 3.5, 4.5, 3, 1, 1);
    Room_feature r5_feature(r5, 12.5, 9.6, 4, 3, 3);
    Room_feature r6_feature(r6, 4.5, 4.5, 3, 2, 2);
    vector<Room> rooms;
    vector<Customer> customers;
    vector<Room_feature> room_features;
    rooms.push_back(r1);
    rooms.push_back(r2);
    rooms.push_back(r3);
    rooms.push_back(r4);
    rooms.push_back(r5);
    rooms.push_back(r6);
    room_features.push_back(r1_feature);
    room_features.push_back(r2_feature);
    room_features.push_back(r3_feature);
    room_features.push_back(r4_feature);
    room_features.push_back(r5_feature);
    room_features.push_back(r6_feature);
    /* ***************************** */
    int choice;
    int room_number;
    do {
        home_display();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Room no.\t\t Occupant\t\t\t Type\t\t\t\t Charge(SEK)\t\t Availability\t\t Period(day(s))\t\t"
                     << endl;
                for (auto &room : rooms) {
                    // 0,1,2,3,4,5
                    cout << room.getRoomNo() << "\t\t\t\t " << room.getOccupant() << "\t\t\t\t "
                         << room.getType() <<
                         "\t\t " << room.getCharge() << "\t\t\t\t " << r_NY(room.isAvailability())
                         << "\t\t\t\t\t " << room.getPeriod() << "\t\t\t\t\n";
                }
                break;
            case 2:
                cout << "Enter room number : ";
                int input_features;
                cin >> input_features;
                for (int j = 0; j < room_features.size() - 1; ++j) {
                    if (room_features.at(j).getRoom().getRoomNo() == input_features) {
                        cout << "Size         : " << room_features.at(j).getLength() * room_features.at(j).getWidth()
                             << " m^2\n";
                        cout << "Chairs       : " << room_features.at(j).getNumberOfChairs() << endl;
                        cout << "Beds         : " << room_features.at(j).getNumberOfBeds() << endl;
                        cout << "Tables       : " << room_features.at(j).getNumberOfTables() << endl;
                        cout << "Occupant     : "
                             << (room_features.at(j).getRoom().getOccupant() == "-" ? "Unoccupied" :
                                 room_features.at(j).getRoom().getOccupant()) << endl;
                        break;
                    }
                }
                break;
            case 3:
                cout << "Enter room number : ";
                cin >> room_number;
                if (room_number <= 6) {
                    // room info
                    for (int i = 0; i <= rooms.size() - 1; ++i) {
                        if (rooms.at(i).getRoomNo() == room_number) {
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Occupant name : ";
                            string occupant_name;
                            getline(cin, occupant_name);
                            rooms.at(i).setOccupant(occupant_name);
                            room_features.at(i).room.setOccupant(occupant_name);
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
                            cout << "CUSTOMER'S DETAILS\n";
                            int age, ID, phone_number;
                            string address, email;
                            cout << "==============================\n";
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Email address : ";
                            getline(cin, email);
                            cout << "Address       : ";
                            getline(cin, address);
                            cout << "Age           : ";
                            cin >> age;
                            srand(time(nullptr));
                            ID = rand() % 100 + 1;
                            cout << "ID : " << ID << endl;
                            cout << "Phone number  : ";
                            cin >> phone_number;
                            cout << "==============================\n";
                            Customer customer(ID, room_number, occupant_name, age, address, email, phone_number);
                            customers.push_back(customer);
                            cout << "SAVED!\n";
                            break;
                        }
                    }
                } else {
                    cout << "Invalid room ID!" << endl << endl;
                }
                break;
            case 4:
                cout << "CUSTOMER SEARCH\n";
                int input;
                cout << "Enter customer's ID OR ROOM NUMBER : ";
                cin >> input;
                // ID
                for (auto &customer : customers) {
                    if (customer.getId() == input) {
                        cout << "Name        : " << customer.getName() << endl;
                        cout << "Room number : " << customer.getRoomNumber() << endl;
                        cout << "Address     : " << customer.getAddress() << endl;
                        cout << "Phone       : " << customer.getPhoneNumber() << endl;
                        break;

                    }
                }
                // room number
                for (auto &customer : customers) {
                    if (customer.getRoomNumber() == input) {
                        cout << "Name    : " << customer.getName() << endl;
                        cout << "ID      : " << customer.getId() << endl;
                        cout << "Address : " << customer.getAddress() << endl;
                        cout << "Phone   : " << customer.getPhoneNumber() << endl;
                        break;
                    }
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

int rdn(int y, int m, int d) {
    if (m < 3)
        y--, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}


