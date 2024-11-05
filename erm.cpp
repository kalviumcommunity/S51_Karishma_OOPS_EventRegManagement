#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Event interface
class EventInterface {
public:
    virtual void displayDetails() const = 0;
    virtual ~EventInterface() = default;
};

// SportsEvent class implementing EventInterface
class SportsEvent : public EventInterface {
private:
    string eventID;
    string name;
    string date;
    string location;
    string sportType;

public:
    SportsEvent(const string& id, const string& n, const string& d, const string& loc, const string& type)
        : eventID(id), name(n), date(d), location(loc), sportType(type) {}

    void displayDetails() const override {
        cout << "Sports Event Details:" << endl;
        cout << "ID: " << eventID << endl;
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Sport Type: " << sportType << endl;
    }
};

// CulturalEvent class implementing EventInterface
class CulturalEvent : public EventInterface {
private:
    string eventID;
    string name;
    string date;
    string location;
    string theme;

public:
    CulturalEvent(const string& id, const string& n, const string& d, const string& loc, const string& t)
        : eventID(id), name(n), date(d), location(loc), theme(t) {}

    void displayDetails() const override {
        cout << "Cultural Event Details:" << endl;
        cout << "ID: " << eventID << endl;
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Theme: " << theme << endl;
    }
};

// EventManager class depends on the EventInterface, not specific event types
class EventManager {
private:
    vector<unique_ptr<EventInterface>> events;

public:
    void addEvent(unique_ptr<EventInterface> event) {
        events.push_back(move(event));
    }

    void displayAllEvents() const {
        for (const auto& event : events) {
            event->displayDetails();
            cout << endl;
        }
    }
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
    EventManager eventManager;

    // Adding different types of events to EventManager
    eventManager.addEvent(make_unique<SportsEvent>("SE03", "Tennis Match", "1-5-2024", "Court A", "Tennis"));
    eventManager.addEvent(make_unique<CulturalEvent>("CE01", "Art Exhibition", "2-5-2024", "Art Hall", "Modern Art"));

    // Display all events through EventManager
    eventManager.displayAllEvents();

    // Participant and ParticipantManager example
    ParticipantManager participantManager;
    Participant* par1 = new Participant("P01", "Karishma");
    participantManager.addParticipant(par1);
    participantManager.registerParticipant(par1);
    cout << "Participant ID: " << par1->getParticipantID() << endl;
    cout << "Name: " << par1->getName() << endl;
    cout << "Total Participants: " << ParticipantManager::getParticipantCount() << endl;

    return 0;
}
