#include "HotelReservationSystem.h"
#include <iostream>
using namespace std;
void displayMenu() {
    cout << "\nHotel Reservation System Menu:"<<endl;
    cout << "1. Add Room"<<endl;
    cout << "2. Check In Guest"<<endl;
    cout << "3. Check Out Guest"<<endl;
    cout << "4. Generate Occupancy Report"<<endl;
    cout << "5. Generate Revenue Report"<<endl;
    cout << "6. Exit"<<endl;
    cout << "Enter your choice: ";
}

int main() {
    Hotel hotel;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            // Add Room
            int roomNumber;
            string roomType;
            double pricePerNight;

            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter room type (Single/Double/Suite): ";
            cin >> roomType;
            cout << "Enter price per night: ";
            cin >> pricePerNight;

            hotel.addRoom(Room(roomNumber, roomType, pricePerNight));
            cout << "Room added successfully!"<<endl;

        } else if (choice == 2) {
            // Check In Guest
            string guestName, contactInfo, checkInDate, checkOutDate;
            int roomNumber;

            cout << "Enter guest name: ";
            cin.ignore();  // Ignore any leftover newline character from previous input
            getline(cin, guestName);
            cout << "Enter guest contact info: ";
            getline(cin, contactInfo);
            cout << "Enter room number for check-in: ";
            cin >> roomNumber;
            cout << "Enter check-in date (YYYY-MM-DD): ";
            cin >> checkInDate;
            cout << "Enter check-out date (YYYY-MM-DD): ";
            cin >> checkOutDate;

            Guest guest(guestName, contactInfo);

            Room* room = nullptr;
            for (Room& r : hotel.getRooms()) {  // Use the getter method here
                if (r.getRoomNumber() == roomNumber) {
                    room = &r;
                    break;
                }
            }

            if (room && room->getAvailability()) {
                hotel.checkIn(&guest, room, checkInDate, checkOutDate);
            } else {
                cout << "Room is not available or doesn't exist."<<endl;
            }

        } else if (choice == 3) {
            // Check Out Guest
            int roomNumber;
            cout << "Enter room number for check-out: ";
            cin >> roomNumber;

            Room* room = nullptr;
            for (Room& r : hotel.getRooms()) {  // Use the getter method here
                if (r.getRoomNumber() == roomNumber) {
                    room = &r;
                    break;
                }
            }

            if (room) {
                hotel.checkOut(room);
            } else {
                cout << "Room does not exist."<<endl;
            }

        } else if (choice == 4) {
            // Generate Occupancy Report
            hotel.generateOccupancyReport();

        } else if (choice == 5) {
            // Generate Revenue Report
            hotel.generateRevenueReport();

        } else if (choice == 6) {
            // Exit the system
            cout << "Exiting the system."<<endl;
            break;

        } else {
            cout << "Invalid choice, please try again."<<endl;
        }
    }

    return 0;
}
