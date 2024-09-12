#include <iostream>
#include <string>

using namespace std;

class Baggage {
private:
    string baggageTag; 
    double weight;      
    string baggageType; 

public:
    
    Baggage(const string& tag, double wt, const string& type)
        : baggageTag(tag), weight(wt), baggageType(type) {}

    void displayBaggageInfo() const {
        cout << "baggage room: " << baggageTag << endl;
        cout << "weight: " << weight << " kg" << endl;
        cout << "type: " << baggageType << endl;
    }

    string getBaggageTag() const {
        return baggageTag;
    }
};

class Passenger {
private:
    string name;       
    string passportNumber; 
    Baggage* baggage;  

public:
    Passenger(const string& n, const string& pNumber, Baggage* bag)
        : name(n), passportNumber(pNumber), baggage(bag) {}

    void displayPassengerInfo() const {
        cout << "Name passenger: " << name << endl;
        cout << "number of passport: " << passportNumber << endl;
        if (baggage) {
            cout << "Info About Baggage: " << endl;
            baggage->displayBaggageInfo();
        }
        else {
            cout << "Baggage missing" << endl;
        }
    }

    string getBaggageTag() const {
        if (baggage) {
            return baggage->getBaggageTag();
        }
        return "Baggage missing";
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");
    Baggage* baggage1 = new Baggage("BAG123", 23.5, "Âàë³çà");
    Baggage* baggage2 = new Baggage("BAG456", 12.0, "Ðó÷íà ïîêëàæà");
    Passenger passenger1("Îëåã ²âàíîâ", "AA123456", baggage1);
    Passenger passenger2("Íàòàë³ÿ Ïåòðåíêî", "BB654321", baggage2);
    cout << "²íôîðìàö³ÿ ïðî ïàñàæèðà 1:" << endl;
    passenger1.displayPassengerInfo();
    cout << endl;
    cout << "²íôîðìàö³ÿ ïðî ïàñàæèðà 2:" << endl;
    passenger2.displayPassengerInfo();
    cout << endl;
    return 0;
}
