
#ifndef SCREEN_CPP
#define SCREEN_CPP
#include <vector>
using namespace std;

class Screen {
private:
    int screenNumber;
    vector<Seat> seats; // COMPOSITION: Screen owns its physical seats.

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {}

    void addSeat(const Seat& seat) {
        seats.push_back(seat);
    }

    int getNumber() const {
        return screenNumber;
    }

    vector<Seat>& getSeats() {
        return seats;
    }

    void displaySeats() const {
        for (const Seat& seat : seats) {
            cout << "Seat " << seat.getNumber()
                 << " [" << seat.getTypeName() << "]\n";
        }
    }
};
#endif
