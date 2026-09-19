
#ifndef SHOW_CPP
#define SHOW_CPP
#include <vector>
#include <string>
using namespace std;

class Show {
private:
    Movie* movie;                 // AGGREGATION
    Screen* screen;               // ASSOCIATION
    string startTime;
    vector<ShowSeat> showSeats;   // COMPOSITION

public:
    Show(Movie* movie, Screen* screen, string startTime)
        : movie(movie), screen(screen), startTime(startTime) {
        for (Seat& seat : screen->getSeats()) {
            showSeats.emplace_back(&seat);
        }
    }

    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }

    vector<ShowSeat>& getShowSeats() {
        return showSeats;
    }

    ShowSeat* findShowSeat(int seatNumber) {
        for (ShowSeat& showSeat : showSeats) {
            if (showSeat.getSeat()->getNumber() == seatNumber) {
                return &showSeat;
            }
        }
        return nullptr;
    }

    void displaySeats() const {
        cout << "\n--- Seat Layout ---\n";
        for (const ShowSeat& showSeat : showSeats) {
            cout << "Seat " << showSeat.getSeat()->getNumber()
                 << " [" << showSeat.getSeat()->getTypeName() << "] : "
                 << (showSeat.isAvailable() ? "AVAILABLE" : "BOOKED")
                 << "\n";
        }
    }
};
#endif
