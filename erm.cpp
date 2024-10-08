#include <iostream>
using namespace std;

class Event {
private:
    string eventID;
    string name;
    string date;
    string location;

public:
    static int eventCount;

    Event() { eventCount++; }

    Event(const string& id, const string& n, const string& d, const string& loc) 
        : eventID(id), name(n), date(d), location(loc) {
        eventCount++;
    }

    virtual ~Event() { eventCount--; }

    virtual void displayDetails() const = 0;  // Pure virtual function

    void setEventID(const string& id) { this->eventID = id; }
    void setName(const string& n) { this->name = n; }
    void setDate(const string& d) { this->date = d; }
    void setLocation(const string& loc) { this->location = loc; }

    string getEventID() const { return eventID; }
    string getName() const { return name; }
    string getDate() const { return date; }
    string getLocation() const { return location; }

    static int getEventCount() { return eventCount; }
};

int Event::eventCount = 0;

class SportsEvent : public Event {
private:
    string sportType;

public:
    SportsEvent(const string& id, const string& n, const string& d, const string& loc, const string& type) 
        : Event(id, n, d, loc), sportType(type) {}

    void displayDetails() const override {
        cout << "Sports Event Details:" << endl;
        cout << "ID: " << getEventID() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Date: " << getDate() << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Sport Type: " << sportType << endl;
    }

    void setSportType(const string& type) { sportType = type; }
    string getSportType() const { return sportType; }
};

int main() {
    Event* event = new SportsEvent("SE02", "Basketball Game", "30-4-2024", "Gymnasium", "Basketball");
    event->displayDetails();

    cout << "Total Events: " << Event::getEventCount() << endl;

    delete event;

    return 0;
}
