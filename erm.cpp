#include <iostream>
#include <vector>
using namespace std;

// Abstract class Event
class Event {
private:
    string eventID;
    string name;
    string date;
    string location;

    static int totalEvents; 


public:
    static int eventCount;  

    Event() {

        eventCount++;
    }

    virtual ~Event() {
        eventCount--;
        totalEvents++; 
    }

    ~Event() {
        totalEvents--; 
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

    // Virtual functions
    virtual void showDetails() const = 0; 
    virtual string getType() const = 0;   
};

int Event::eventCount = 0;

// Participant class

    static int getTotalEvents() { return totalEvents; } 
};


int Event::totalEvents = 0;

class Participant {
private:
    string participantID;
    string name;
    bool isRegistered;

    static int totalParticipants; 

public:
    static int participantCount;  

    Participant() : isRegistered(false) {
        participantCount++;
    }

    ~Participant() {
        participantCount--;
    }

    // Mutators (Setters)
    void setParticipantID(const string& id) { this->participantID = id; }
    void setName(const string& n) { this->name = n; }

    void registerForEvent() { this->isRegistered = true; }
    
    void registerForEvent() {
        if (!isRegistered) {
            isRegistered = true;
            totalParticipants++; 
        }
    }

    // Accessors (Getters)
    string getParticipantID() const { return participantID; }
    string getName() const { return name; }
    bool getRegistrationStatus() const { return isRegistered; }

    static int getParticipantCount() {
        return participantCount;
    }
};

int Participant::participantCount = 0;

// Hackathon class inheriting from Event
class Hackathon : public Event {
private:
    string sponsor;
    vector<Participant*> participants;
    static int getTotalParticipants() { return totalParticipants; } 
};

int Participant::totalParticipants = 0;

int main() {
    Event* events = new Event[2];

    // Using mutators to set event details
    events[0].setEventID("EV01");
    events[0].setName("Karishma's Event");
    events[0].setDate("27-4-2024");
    events[0].setLocation("Conference Hall");

    events[1].setEventID("EV02");
    events[1].setName("Tech Conference");
    events[1].setDate("28-4-2024");
    events[1].setLocation("Main Auditorium");

public:
    Hackathon() : sponsor("") {}

    // Override 
    void showDetails() const override {
        cout << "Hackathon Details:" << endl;
        cout << "ID: " << getEventID() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Date: " << getDate() << endl;
        cout << "Location: " << getLocation() << endl;
        cout << "Sponsor: " << sponsor << endl;
        cout << "Participants:" << endl;

        for (const auto& participant : participants) {
            cout << "  ID: " << participant->getParticipantID() << ", Name: " << participant->getName() << endl;
        }
        cout << endl;
    }

    // Override 
    string getType() const override {
        return "Hackathon";
    }

    // Mutators (Setters)
    void setSponsor(const string& sp) { this->sponsor = sp; }

    // Accessors (Getters)
    string getSponsor() const { return sponsor; }

    // Manage participants
    void addParticipant(Participant* p) {
        participants.push_back(p);
    }
};

int main() {
    Hackathon* hackathons = new Hackathon[2];

    // Using mutators to set hackathon details
    hackathons[0].setEventID("HK01");
    hackathons[0].setName("Code Masters");
    hackathons[0].setDate("15-5-2024");
    hackathons[0].setLocation("Tech Park");
    hackathons[0].setSponsor("Tech Corp");

    hackathons[1].setEventID("HK02");
    hackathons[1].setName("Innovate 2024");
    hackathons[1].setDate("16-5-2024");
    hackathons[1].setLocation("Innovation Center");
    hackathons[1].setSponsor("Innovate Inc.");

    // Creating participants
    Participant* par1 = new Participant;
    par1->setParticipantID("P01");
    par1->setName("Karishma");
    par1->registerForEvent();

    Participant* par2 = new Participant;
    par2->setParticipantID("P02");
    par2->setName("John");
    par2->registerForEvent();

    // Adding participants to hackathons
    hackathons[0].addParticipant(par1);
    hackathons[0].addParticipant(par2);

    hackathons[1].addParticipant(par2);

    // Using accessors and overridden methods to get hackathon details
    for (int i = 0; i < 2; ++i) {
        hackathons[i].showDetails();
        cout << "Type: " << hackathons[i].getType() << endl;
    }

    cout << "Total Events: " << Event::getEventCount() << endl;
    cout << "Total Participants: " << Participant::getParticipantCount() << endl;

    delete par1;
    delete par2;
    delete[] hackathons;

    return 0;
}
