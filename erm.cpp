//class for events
# include <iostream>
using namespace std;

class Event {
private:
    std::string eventID;
    std::string name;
    std::string date;
    std::string location;

public:
    void setEventID(const std::string& id) { eventID = id; }
    void setName(const std::string& n) { name = n; }
    void setDate(const std::string& d) { date = d; }
    void setLocation(const std::string& loc) { location = loc; }

    std::string getEventID() const { return eventID; }
    std::string getName() const { return name; }
    std::string getDate() const { return date; }
    std::string getLocation() const { return location; }
};

//class for participants
class Participant {
private:
    std::string participantID;
    std::string name;
    bool isRegistered;

public:
    Participant() : isRegistered(false) {}

    void setParticipantID(const std::string& id) { participantID = id; }
    void setName(const std::string& n) { name = n; }
    void registerForEvent() { isRegistered = true; }

    std::string getParticipantID() const { return participantID; }
    std::string getName() const { return name; }
    bool getRegistrationStatus() const { return isRegistered; }
};


int main(){
    Event evnt1;
    evnt1.setDate("27-4-2024");
    evnt1.setName("karishma");
    evnt1.setLocation("conference hall");
    evnt1.setEventID("EV01");

    cout << evnt1.getDate();
    cout << evnt1.getName();
    cout << evnt1.getLocation();
    cout << evnt1.getEventID();

    
    Participant par1;
    par1.setParticipantID("27-4-2024");
    par1.setName("karishma");
    par1.registerForEvent();

    cout << par1.getParticipantID();
    cout << par1.getName();
    cout << par1.getRegistrationStatus();


 
    return 0;
}