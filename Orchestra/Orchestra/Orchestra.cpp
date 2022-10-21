#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instrument {
public:
    virtual void play() = 0;
};

class Guitar : public Instrument {
public:
    void play() {
        cout << "Guitar play ..." << endl;
    }
};

class Flute : public Instrument {
public:
    void play() {
        cout << "Flute play ..." << endl;
    }
};

class Trombone : public Instrument {
public:
    void play() {
        cout << "Trombone play ..." << endl;
    }
};
class Orchestra : public Instrument {
public:
    Orchestra(){}
    Orchestra(string name) {
        setName(name);
    }
    ~Orchestra() {
        for (size_t i = 0; i < instruments.size(); i++)
        {
            delete instruments[i];
            
        }
        instruments.clear();
    }
    void play() {
        for(Instrument* var : instruments)
        {
            var->play();
        }
    }
    void setName(string name) {
        this->name = name;
    }
    void addInstrument(Instrument* instrument) {
        instruments.push_back(instrument);
    }
private:
    vector<Instrument*> instruments;
    string name;
};


int main()
{

    Instrument* guitar = new Guitar;
    Instrument* flute = new Flute;
    Instrument* trombone = new Trombone;

    
    Orchestra orchestra;
    orchestra.setName("gerdzio");
    orchestra.addInstrument(guitar);
    orchestra.addInstrument(flute);
    orchestra.addInstrument(trombone);
    orchestra.play();
}