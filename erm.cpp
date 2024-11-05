#include <iostream>
#include <memory>
using namespace std;

class EventDetails {
public:
    virtual void displaySpecificDetails() const = 0;
    virtual ~EventDetails() = default;
};

class SportsDetails : public EventDetails {
private:
    string sportType;

public:
    SportsDetails(const string& type) : sportType(type) {}

    void displaySpecificDetails() const override {
        cout << "Sport Type: " << sportType << endl;
    }
};

class CulturalDetails : public EventDetails {
private:
    string theme;

public:
    CulturalDetails(const string& t) : theme(t) {}

    void displaySpecificDetails() const override {
        cout << "Theme: " << theme << endl;
    }
};

class Event {
private:
    string eventID;
    string name;
    string date;
    string location;
    unique_ptr<EventDetails> details;

public:
    static int eventCount;

    // Parameterized constructor
    Event(const string& id, const string& n, const string& d, const string& loc, unique_ptr<EventDetails> det) 
        : eventID(id), name(n), date(d), location(loc), details(move(det)) {
        eventCount++;
    }

    // Destructor
    virtual ~Event() { eventCount--; }

    // Display event details
    void displayDetails() const {
        cout << "Event ID: " << eventID << endl;
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        details->displaySpecificDetails();  // Display specific event type details
    }

    // Static function to get the total count of events
    static int getEventCount() { return eventCount; }
};

int Event::eventCount = 0;

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
    // Creating different types of events using the open/closed principle
    Event event1("SE03", "Tennis Match", "1-5-2024", "Court A", make_unique<SportsDetails>("Tennis"));
    Event event2("CE01", "Art Exhibition", "2-5-2024", "Art Hall", make_unique<CulturalDetails>("Modern Art"));

    // Display details for each event
    event1.displayDetails();
    cout << endl;
    event2.displayDetails();
    cout << endl;

    // Display total number of events
    cout << "Total Events: " << Event::getEventCount() << endl;

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
