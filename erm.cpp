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

    void setSportType(const string& type) { sportType = type; }
    string getSportType() const { return sportType; }
};

int main() {
    SportsEvent sportsEvent("SE01", "Football Match", "29-4-2024", "Stadium", "Football");
    cout << "Event ID: " << sportsEvent.getEventID() << endl;
    cout << "Name: " << sportsEvent.getName() << endl;
    cout << "Date: " << sportsEvent.getDate() << endl;
    cout << "Location: " << sportsEvent.getLocation() << endl;
    cout << "Sport Type: " << sportsEvent.getSportType() << endl;

    cout << "Total Events: " << Event::getEventCount() << endl;

    return 0;
}
