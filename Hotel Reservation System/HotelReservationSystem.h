#ifndef HOTELRESERVATIONSYSTEM_H_INCLUDED
#define HOTELRESERVATIONSYSTEM_H_INCLUDED

#include <string>
#include <vector>

using namespace std;
// Class Room
class Room {
private:
    int roomNumber;
    string roomType;
    bool isAvailable;
    double pricePerNight;

public:
    Room(int number, const string& type, double price);

    int getRoomNumber() const;
    string getRoomType() const;
    bool getAvailability() const;
    double getPrice() const;
    void setAvailability(bool availability);
};

// Class Guest
class Guest {
private:
    string name;
    string contactInfo;

public:
    Guest(const string& guestName, const string& contact);

    string getName() const;
    string getContactInfo() const;
};

// Class Booking
class Booking {
private:
    Room* room;
    Guest* guest;
    string checkInDate;
    string checkOutDate;

public:
    Booking(Room* r, Guest* g, const string& inDate, const string& outDate);

    Room* getRoom() const;
    Guest* getGuest() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
};

// Class Hotel
class Hotel {
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    void addRoom(const Room& room);
    void checkIn(Guest* guest, Room* room, const string& checkInDate, const string& checkOutDate);
    void checkOut(Room* room);
    void manageRoomAvailability(int roomNumber, bool availability);
    void generateOccupancyReport() const;
    void generateRevenueReport() const;

    // Getter method to access rooms
    vector<Room>& getRooms() {
        return rooms;
    }
};
#endif // HOTELRESERVATIONSYSTEM_H_INCLUDED
