#include <iostream>
#include <vector>
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
    Event() { eventCount++; }

    // Parameterized constructor
    Event(const string& id, const string& n, const string& d, const string& loc) 
        : eventID(id), name(n), date(d), location(loc) {
        eventCount++;
    }

    // Destructor
    virtual ~Event() { eventCount--; }

    // Pure virtual function making Event an abstract class
    virtual void displayDetails() const = 0;

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

    // Static function to get the total count of events
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

class CulturalEvent : public Event {
private:
    string theme;

public:
    CulturalEvent(const string& id, const string& n, const string& d, const string& loc, const string& t) 
        : Event(id, n, d, loc), theme(t) {}

    void displayDetails() const override {
        cout << "Cultural Event Details:" << endl;
        cout << "ID: " << getEventID() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Date: " << getDate() << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Theme: " << theme << endl;
    }

    void setTheme(const string& t) { theme = t; }
    string getTheme() const { return theme; }
};

class Participant {
private:
    string participantID;
    string name;

public:
    Participant(const string& id, const string& n) 
        : participantID(id), name(n) {}

    // Accessors (Getters)
    string getParticipantID() const { return participantID; }
    string getName() const { return name; }
};

class ParticipantManager {
private:
    vector<Participant*> participants;
    static int participantCount;

public:
    void addParticipant(Participant* participant) {
        participants.push_back(participant);
        participantCount++;
    }

    void registerParticipant(Participant* participant) {
        cout << "Participant " << participant->getName() << " registered successfully." << endl;
    }

    static int getParticipantCount() { return participantCount; }

    ~ParticipantManager() {
        for (Participant* p : participants) {
            delete p;
        }
    }
};

int ParticipantManager::participantCount = 0;

int main() {
    // Creating an array of Event pointers to demonstrate polymorphism
    Event* events[2];
    events[0] = new SportsEvent("SE03", "Tennis Match", "1-5-2024", "Court A", "Tennis");
    events[1] = new CulturalEvent("CE01", "Art Exhibition", "2-5-2024", "Art Hall", "Modern Art");

    // Display details for each event
    for (int i = 0; i < 2; ++i) {
        events[i]->displayDetails();
        cout << endl;
    }

    // Display total number of events
    cout << "Total Events: " << Event::getEventCount() << endl;

    // Clean up dynamically allocated memory
    for (int i = 0; i < 2; ++i) {
        delete events[i];
    }

    // Participant and ParticipantManager example
    ParticipantManager manager;
    Participant* par1 = new Participant("P01", "Karishma");
    manager.addParticipant(par1);
    manager.registerParticipant(par1);
    cout << "Participant ID: " << par1->getParticipantID() << endl;
    cout << "Name: " << par1->getName() << endl;
    cout << "Total Participants: " << ParticipantManager::getParticipantCount() << endl;

    return 0;
}
