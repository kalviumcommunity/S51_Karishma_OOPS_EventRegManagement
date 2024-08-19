#include <iostream>
using namespace std;

class Event {
private:
    string eventID;
    string name;
    string date;
    string location;
    static int totalEvents; // Static variable to count total events

public:
    Event() {
        totalEvents++; // Increment the totalEvents when an event is created
    }

    ~Event() {
        totalEvents--; // Decrement the totalEvents when an event is destroyed
    }

    void setEventID(const string& id) { this->eventID = id; }
    void setName(const string& n) { this->name = n; }
    void setDate(const string& d) { this->date = d; }
    void setLocation(const string& loc) { this->location = loc; }

    string getEventID() const { return eventID; }
    string getName() const { return name; }
    string getDate() const { return date; }
    string getLocation() const { return location; }

    static int getTotalEvents() { return totalEvents; } // Static method to get the total number of events
};

// Initialize the static variable
int Event::totalEvents = 0;

class Participant {
private:
    string participantID;
    string name;
    bool isRegistered;
    static int totalParticipants; // Static variable to count total registered participants

public:
    Participant() : isRegistered(false) {}

    void setParticipantID(const string& id) { this->participantID = id; }
    void setName(const string& n) { this->name = n; }
    
    void registerForEvent() {
        if (!isRegistered) {
            isRegistered = true;
            totalParticipants++; // Increment the totalParticipants when a participant registers
        }
    }

    string getParticipantID() const { return participantID; }
    string getName() const { return name; }
    bool getRegistrationStatus() const { return isRegistered; }

    static int getTotalParticipants() { return totalParticipants; } // Static method to get the total number of registered participants
};

// Initialize the static variable
int Participant::totalParticipants = 0;

int main() {
    Event* events = new Event[2];

    events[0].setDate("27-4-2024");
    events[0].setName("Karishma's Event");
    events[0].setLocation("Conference Hall");
    events[0].setEventID("EV01");

    events[1].setDate("28-4-2024");
    events[1].setName("Tech Conference");
    events[1].setLocation("Main Auditorium");
    events[1].setEventID("EV02");

    cout << "Total Events: " << Event::getTotalEvents() << endl << endl;

    for (int i = 0; i < 2; ++i) {
        cout << "Event " << (i + 1) << " Details:" << endl;
        cout << "ID: " << events[i].getEventID() << endl;
        cout << "Name: " << events[i].getName() << endl;
        cout << "Date: " << events[i].getDate() << endl;
        cout << "Location: " << events[i].getLocation() << endl;
        cout << endl;
    }

    delete[] events;

    cout << "Total Events after deletion: " << Event::getTotalEvents() << endl << endl;

    Participant* par1 = new Participant;

    par1->setParticipantID("P01");
    par1->setName("Karishma");
    par1->registerForEvent();

    cout << "Participant ID: " << par1->getParticipantID() << endl;
    cout << "Name: " << par1->getName() << endl;
    cout << "Registered: " << (par1->getRegistrationStatus() ? "Yes" : "No") << endl;

    cout << "Total Registered Participants: " << Participant::getTotalParticipants() << endl;

    delete par1;

    return 0;
}
