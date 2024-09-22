#include "HotelReservationSystem.h"
#include <iostream>

using namespace std;
// Room Class Definitions
Room::Room(int number, const string& type, double price)
    : roomNumber(number), roomType(type), isAvailable(true), pricePerNight(price) {}

int Room::getRoomNumber() const { return roomNumber; }string Room::getRoomType() const { return roomType; }
bool Room::getAvailability() const { return isAvailable; }
double Room::getPrice() const { return pricePerNight; }
void Room::setAvailability(bool availability) { isAvailable = availability; }

// Guest Class Definitions
Guest::Guest(const string& guestName, const string& contact)
    : name(guestName), contactInfo(contact) {}

string Guest::getName() const { return name; }
string Guest::getContactInfo() const { return contactInfo; }

// Booking Class Definitions
Booking::Booking(Room* r, Guest* g, const string& inDate, const string& outDate)
    : room(r), guest(g), checkInDate(inDate), checkOutDate(outDate) {}

Room* Booking::getRoom() const { return room; }
Guest* Booking::getGuest() const { return guest; }
string Booking::getCheckInDate() const { return checkInDate; }
string Booking::getCheckOutDate() const { return checkOutDate; }

// Hotel Class Definitions
void Hotel::addRoom(const Room& room) {
    rooms.push_back(room);
}

void Hotel::checkIn(Guest* guest, Room* room, const string& checkInDate, const string& checkOutDate) {
    if (room->getAvailability()) {
        room->setAvailability(false);
        bookings.emplace_back(room, guest, checkInDate, checkOutDate);
        cout << "Guest " << guest->getName() << " checked in to room " << room->getRoomNumber() << endl;
    } else {
        cout << "Room not available." << endl;
    }
}

void Hotel::checkOut(Room* room) {
    room->setAvailability(true);
    cout << "Room " << room->getRoomNumber() << " is now available." << endl;
}

void Hotel::manageRoomAvailability(int roomNumber, bool availability) {
    for (Room& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            room.setAvailability(availability);
            break;
        }
    }
}

void Hotel::generateOccupancyReport() const {
    cout << "Occupancy Report:" <<endl;
    for (const Room& room : rooms) {
        cout << "Room " << room.getRoomNumber() << ": "
                  << (room.getAvailability() ? "Available" : "Occupied") << endl;
    }
}

void Hotel::generateRevenueReport() const {
    double totalRevenue = 0;
    for (const Booking& booking : bookings) {
        totalRevenue += booking.getRoom()->getPrice();
    }
    cout << "Total Revenue: $" << totalRevenue << endl;
}
