#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include "model/Room.h"
#include "model/Room.cpp"
#include "model/Customer.h"
#include "model/Customer.cpp"
#include <ctime>
#include <cmath>
#include "Room_feature.h"
#include "Room_feature.cpp"
#include "Food_customer.h"
#include "Food_customer.cpp"
#include <regex>

using namespace std;

string r_NY(bool cond);

void home_display();

typedef std::chrono::system_clock Clock;

int rdn(int y, int m, int d);

void restaurant_display();

double confirmPrice(int);

void save_customer(vector<Customer> &customers, int room_number, const string &occupant_name);

int get_date_diff(int dayFrom, int monthFrom, int dayTo, int monthTo);

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
        cin >> choice; // TODO exception (on all ints types)
        switch (choice) {
            case 1:
                cout
                        << "Room no.\t\t Occupant\t\t\t Type\t\t\t\t Charge(SEK)\t\t Availability\t\t Period(day(s))\t\t"
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
                        cout << "Size         : "
                             << room_features.at(j).getLength() * room_features.at(j).getWidth()
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
                            cout << "Day   : ";
                            cin >> dayFrom;
                            cout << "Month : ";
                            cin >> monthFrom;
                            cout << "To --->" << endl;
                            cout << "Day   : ";
                            cin >> dayTo;
                            cout << "Month : ";
                            cin >> monthTo;
                            period = get_date_diff(dayFrom, monthFrom, dayTo, monthTo);
                            rooms.at(i).setPeriod(abs(period));
                            rooms.at(i).setAvailability(false);
                            save_customer(customers, room_number, occupant_name);
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
                        cout << "Name        : " << customer.getName() << endl;
                        cout << "ID          : " << customer.getId() << endl;
                        cout << "Address     : " << customer.getAddress() << endl;
                        cout << "Phone       : " << customer.getPhoneNumber() << endl;
                        break;
                    }
                }
                break;
            case 5 :
                restaurant_display();
                int choice_food;
                cin >> choice_food;
                cout << "Enter room number : ";
                int room_number_food;
                cin >> room_number_food;
                for (int i = 0; i < rooms.size(); ++i) {
                    if (rooms.at(i).getRoomNo() == room_number && !rooms.at(i).isAvailability()) {
                        // TODO - fix ordering food to an unoccupied room
                        if (choice_food == 1) {
                            string food_to_string = "Rice and chicken";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else if (choice_food == 2) {
                            string food_to_string = "Fish and sauce";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else if (choice_food == 3) {
                            string food_to_string = "Potatoes";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else if (choice_food == 4) {
                            string food_to_string = "Soup";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else if (choice_food == 5) {
                            string food_to_string = "Bread and cheese";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else if (choice_food == 6) {
                            string food_to_string = "Coffee";
                            Food_customer foodCustomer(room_number_food, food_to_string, confirmPrice(choice_food));
                            cout << "DONE!\n";
                        } else {
                            cout << "Invalid choice\n";
                        }
                        break;
                    }
                }
                for (auto &room : rooms) {
                    if (room.getRoomNo() == room_number_food && room.isAvailability()) {
                        cout << "You can't send food to an unoccupied room!\n";
                        break;
                    }
                }
                if (room_number_food > 6 || room_number_food < 0) {
                    cout << "Invalid room number!\n";
                    break;
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

int get_date_diff(int dayFrom, int monthFrom, int dayTo, int monthTo) {
    int period;
    auto now = Clock::now();
    time_t now_c = Clock::to_time_t(now);
    struct tm *parts = localtime(&now_c);
    period = rdn(1900 + parts->tm_year, monthFrom, dayFrom) -
             rdn(1900 + parts->tm_year, monthTo, dayTo);
    return period;
}

void save_customer(vector<Customer> &customers, int room_number, const string &occupant_name) {
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
    cin >> phone_number;  // TODO
    cout << "==============================\n";
    Customer customer(ID, room_number, occupant_name, age, address, email, phone_number);
    customers.push_back(customer);
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

void restaurant_display() {
    cout << "================\n";
    cout << "  Zamon foods" << endl;
    cout << "================\n";
    cout << "==========================\n";
    cout << "||  1 : Rice and chicken ||" << endl;
    cout << "||  2 : Fish and sauce   ||\n";
    cout << "||  3 : Potato           ||" << endl;
    cout << "||  4 : Soup             ||\n";
    cout << "||  5 : Bread and cheese ||\n";
    cout << "||  6 : Coffee           ||\n";
    cout << "==========================\n";
    cout << "Enter choice id : ";
}

double confirmPrice(int choice_id) {
    double price = 0;
    if (choice_id == 1 || choice_id == 2) {
        price = 300;
    } else if (choice_id == 3) {
        price = 150;
    } else if (choice_id == 4) {
        price = 140;
    } else if (choice_id == 5) {
        price = 375;
    } else if (choice_id == 6) {
        price = 50;
    } else {
        cout << "You definitely entered nonsense!!\n";
    }
    return price;
}



