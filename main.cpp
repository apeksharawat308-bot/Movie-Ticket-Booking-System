
#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// One class per .cpp file.
// The .cpp files are included here because the assignment specifically says
// "one class per file" and "no header files". For a normal industry project,
// these would be separated into .h/.cpp pairs.

#include "Movie.cpp"
#include "Seat.cpp"
#include "ShowSeat.cpp"
#include "Screen.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "PriceCalculator.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "Booking.cpp"
#include "TicketPrinter.cpp"
#include "Cinema.cpp"
#include "BookingService.cpp"

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printShows(const vector<Show*>& shows, int movieIndex) {
    cout << "\n--- Shows ---\n";

    bool found = false;

    for (size_t i = 0; i < shows.size(); ++i) {
        if (shows[i]->getMovie() != nullptr &&
            shows[i]->getMovie()->getTitle() != "") {

            // Shows are listed with their movie title so the menu remains clear.
            if (shows[i]->getMovie()->getTitle() ==
                shows[movieIndex]->getMovie()->getTitle()) {
                cout << i + 1 << ". Screen "
                     << shows[i]->getScreen()->getNumber()
                     << " - " << shows[i]->getStartTime() << "\n";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No shows available.\n";
    }
}

int main() {
    cout << "========================================\n";
    cout << "       MOVIE TICKET BOOKING SYSTEM\n";
    cout << "========================================\n";

    // ---------------- CINEMA + SCREENS ----------------
    Cinema cinema("PVR Cinemas");

    Screen screen1(1);
    Screen screen2(2);

    // COMPOSITION: Screen owns Seat objects.
    for (int i = 1; i <= 6; ++i) {
        if (i <= 2)
            screen1.addSeat(Seat(i, SeatType::SILVER));
        else if (i <= 4)
            screen1.addSeat(Seat(i, SeatType::GOLD));
        else
            screen1.addSeat(Seat(i, SeatType::PLATINUM));
    }

    for (int i = 1; i <= 6; ++i) {
        if (i <= 2)
            screen2.addSeat(Seat(i, SeatType::SILVER));
        else if (i <= 4)
            screen2.addSeat(Seat(i, SeatType::GOLD));
        else
            screen2.addSeat(Seat(i, SeatType::PLATINUM));
    }

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    // ---------------- MOVIES ----------------
    vector<Movie*> movies;

    Movie movie1("Interstellar", "English", 169);
    Movie movie2("Inception", "English", 148);

    movies.push_back(&movie1);
    movies.push_back(&movie2);

    // ---------------- SHOWS ----------------
    vector<Show*> shows;

    // Shows use the existing screen objects.
    vector<Screen>& cinemaScreens = cinema.getScreens();

    Show show1(&movie1, &cinemaScreens[0], "06:30 PM");
    Show show2(&movie1, &cinemaScreens[1], "09:30 PM");
    Show show3(&movie2, &cinemaScreens[0], "05:00 PM");

    shows.push_back(&show1);
    shows.push_back(&show2);
    shows.push_back(&show3);

    Customer customer("Apeksha Rawat", "9876543210");
    BookingService bookingService;

    while (true) {
        cout << "\n\n========== MAIN MENU ==========\n";
        cout << "1. List Movies\n";
        cout << "2. List Shows for a Movie\n";
        cout << "3. Show Seat Layout\n";
        cout << "4. Book Ticket\n";
        cout << "5. Cancel Booking\n";
        cout << "6. List Bookings\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            clearInput();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            cinema.listMovies(movies);
        }

        else if (choice == 2) {
            cinema.listMovies(movies);

            cout << "Select movie number: ";
            int movieChoice;
            cin >> movieChoice;

            if (cin.fail() ||
                movieChoice < 1 ||
                movieChoice > static_cast<int>(movies.size())) {
                clearInput();
                cout << "Invalid movie choice.\n";
                continue;
            }

            cout << "\nShows for "
                 << movies[movieChoice - 1]->getTitle() << ":\n";

            bool found = false;

            for (size_t i = 0; i < shows.size(); ++i) {
                if (shows[i]->getMovie() ==
                    movies[movieChoice - 1]) {
                    cout << i + 1 << ". Screen "
                         << shows[i]->getScreen()->getNumber()
                         << " - " << shows[i]->getStartTime() << "\n";
                    found = true;
                }
            }

            if (!found)
                cout << "No shows available.\n";
        }

        else if (choice == 3) {
            cinema.listMovies(movies);

            cout << "Select movie number: ";
            int movieChoice;
            cin >> movieChoice;

            if (cin.fail() ||
                movieChoice < 1 ||
                movieChoice > static_cast<int>(movies.size())) {
                clearInput();
                cout << "Invalid movie choice.\n";
                continue;
            }

            vector<int> matchingShows;

            cout << "\nShows:\n";

            for (size_t i = 0; i < shows.size(); ++i) {
                if (shows[i]->getMovie() ==
                    movies[movieChoice - 1]) {
                    cout << matchingShows.size() + 1
                         << ". Screen "
                         << shows[i]->getScreen()->getNumber()
                         << " - " << shows[i]->getStartTime() << "\n";
                    matchingShows.push_back(static_cast<int>(i));
                }
            }

            if (matchingShows.empty()) {
                cout << "No shows available.\n";
                continue;
            }

            cout << "Select show: ";
            int showChoice;
            cin >> showChoice;

            if (cin.fail() ||
                showChoice < 1 ||
                showChoice > static_cast<int>(matchingShows.size())) {
                clearInput();
                cout << "Invalid show choice.\n";
                continue;
            }

            shows[matchingShows[showChoice - 1]]->displaySeats();
        }

        else if (choice == 4) {
            cinema.listMovies(movies);

            cout << "Select movie number: ";
            int movieChoice;
            cin >> movieChoice;

            if (cin.fail() ||
                movieChoice < 1 ||
                movieChoice > static_cast<int>(movies.size())) {
                clearInput();
                cout << "Invalid movie choice.\n";
                continue;
            }

            vector<int> matchingShows;

            cout << "\nShows:\n";

            for (size_t i = 0; i < shows.size(); ++i) {
                if (shows[i]->getMovie() ==
                    movies[movieChoice - 1]) {
                    cout << matchingShows.size() + 1
                         << ". Screen "
                         << shows[i]->getScreen()->getNumber()
                         << " - " << shows[i]->getStartTime() << "\n";
                    matchingShows.push_back(static_cast<int>(i));
                }
            }

            if (matchingShows.empty()) {
                cout << "No shows available.\n";
                continue;
            }

            cout << "Select show: ";
            int showChoice;
            cin >> showChoice;

            if (cin.fail() ||
                showChoice < 1 ||
                showChoice > static_cast<int>(matchingShows.size())) {
                clearInput();
                cout << "Invalid show choice.\n";
                continue;
            }

            Show& selectedShow =
                *shows[matchingShows[showChoice - 1]];

            selectedShow.displaySeats();

            cout << "\nEnter number of seats: ";
            int seatCount;
            cin >> seatCount;

            if (cin.fail() || seatCount <= 0) {
                clearInput();
                cout << "Invalid number of seats.\n";
                continue;
            }

            vector<int> seatNumbers;

            for (int i = 0; i < seatCount; ++i) {
                cout << "Enter seat number " << i + 1 << ": ";
                int seatNumber;
                cin >> seatNumber;

                if (cin.fail()) {
                    clearInput();
                    cout << "Invalid seat number.\n";
                    seatNumbers.clear();
                    break;
                }

                seatNumbers.push_back(seatNumber);
            }

            if (seatNumbers.empty())
                continue;

            cout << "\nPayment Method:\n";
            cout << "1. UPI\n";
            cout << "2. Card\n";
            cout << "3. Cash\n";
            cout << "Enter choice: ";

            int paymentChoice;
            cin >> paymentChoice;

            if (cin.fail() ||
                paymentChoice < 1 ||
                paymentChoice > 3) {
                clearInput();
                cout << "Invalid payment choice.\n";
                continue;
            }

            cout << "Simulate payment failure? (1 = Yes, 0 = No): ";
            int failureChoice;
            cin >> failureChoice;

            if (cin.fail() ||
                (failureChoice != 0 && failureChoice != 1)) {
                clearInput();
                cout << "Invalid choice.\n";
                continue;
            }

            bookingService.bookTicket(
                customer,
                selectedShow,
                seatNumbers,
                paymentChoice,
                failureChoice == 1
            );
        }

        else if (choice == 5) {
            cout << "Enter Booking ID: ";
            int bookingId;
            cin >> bookingId;

            if (cin.fail()) {
                clearInput();
                cout << "Invalid Booking ID.\n";
                continue;
            }

            bookingService.cancelBooking(bookingId);
        }

        else if (choice == 6) {
            bookingService.listBookings();
        }

        else if (choice == 7) {
            cout << "\nThank you for using Movie Ticket Booking System!\n";
            break;
        }

        else {
            cout << "Invalid menu choice. Please try again.\n";
        }
    }

    return 0;
}
