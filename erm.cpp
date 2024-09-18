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

    // Default constructor
    Event() {
        eventCount++;
    }

    // Parameterized constructor
    Event(const string& id, const string& n, const string& d, const string& loc) 
        : eventID(id), name(n), date(d), location(loc) {
        eventCount++;
    }

    ~Event() {
        eventCount--;
    }

    // Mutators (Setters)
    void setEventID(const string& id) { this->eventID = id; }
    void setName(const string& n) { this->name = n; }
    void setDate(const string& d) { this->date = d; }
    void setLocation(const string& loc) { this->location = loc; }

    // Accessors (Getters)
    string getEventID() const { return eventID; }
    string getName() const { return name; }
    string getDate() const { return date; }
    string getLocation() const { return location; }

    static int getEventCount() {
        return eventCount;
    }
};

int Event::eventCount = 0;

class Participant {
private:
    string participantID;
    string name;
    bool isRegistered;

public:
    static int participantCount;  

    // Default constructor
    Participant() : isRegistered(false) {
        participantCount++;
    }

    // Parameterized constructor
    Participant(const string& id, const string& n, bool reg = false) 
        : participantID(id), name(n), isRegistered(reg) {
        participantCount++;
    }

    ~Participant() {
        participantCount--;
    }

    // Mutators (Setters)
    void setParticipantID(const string& id) { this->participantID = id; }
    void setName(const string& n) { this->name = n; }
    void registerForEvent() { this->isRegistered = true; }

    // Accessors (Getters)
    string getParticipantID() const { return participantID; }
    string getName() const { return name; }
    bool getRegistrationStatus() const { return isRegistered; }

    static int getParticipantCount() {
        return participantCount;
    }
};

int Participant::participantCount = 0;

int main() {
    Event events[2] = {
        Event("EV01", "Karishma's Event", "27-4-2024", "Conference Hall"),
        Event("EV02", "Tech Conference", "28-4-2024", "Main Auditorium")
    };

    for (int i = 0; i < 2; ++i) {
        cout << "Event " << (i + 1) << " Details:" << endl;
        cout << "ID: " << events[i].getEventID() << endl;
        cout << "Name: " << events[i].getName() << endl;
        cout << "Date: " << events[i].getDate() << endl;
        cout << "Location: " << events[i].getLocation() << endl;
        cout << endl;
    }

    cout << "Total Events: " << Event::getEventCount() << endl;

    Participant* par1 = new Participant("P01", "Karishma");

    par1->registerForEvent();

    cout << "Participant ID: " << par1->getParticipantID() << endl;
    cout << "Name: " << par1->getName() << endl;
    cout << "Registered: " << (par1->getRegistrationStatus() ? "Yes" : "No") << endl;

    cout << "Total Participants: " << Participant::getParticipantCount() << endl;

    delete par1;

    return 0;
}
