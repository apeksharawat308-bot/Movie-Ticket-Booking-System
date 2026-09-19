
#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP
#include <vector>
using namespace std;

class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<Booking*> bookings;

    Payment* createPayment(int paymentChoice, bool failPayment) {
        if (paymentChoice == 1) {
            return new UpiPayment(failPayment);
        }

        if (paymentChoice == 2) {
            return new CardPayment(failPayment);
        }

        return new CashPayment(failPayment);
    }

public:
    ~BookingService() {
        for (Booking* booking : bookings) {
            delete booking;
        }
    }

    // Runtime polymorphism:
    // Payment* points to UpiPayment/CardPayment/CashPayment.
    Booking* bookTicket(Customer& customer,
                         Show& show,
                         const vector<int>& seatNumbers,
                         int paymentChoice,
                         bool failPayment = false) {
        vector<ShowSeat*> selectedSeats;

        // Validate all seats BEFORE changing anything.
        for (int seatNumber : seatNumbers) {
            ShowSeat* showSeat = show.findShowSeat(seatNumber);

            if (showSeat == nullptr) {
                cout << "Seat " << seatNumber << " does not exist.\n";
                return nullptr;
            }

            if (!showSeat->isAvailable()) {
                cout << "Seat " << seatNumber
                     << " is already BOOKED.\n";
                return nullptr;
            }

            for (ShowSeat* selected : selectedSeats) {
                if (selected->getSeat()->getNumber() == seatNumber) {
                    cout << "Seat " << seatNumber
                         << " was selected twice.\n";
                    return nullptr;
                }
            }

            selectedSeats.push_back(showSeat);
        }

        // Temporarily reserve selected seats.
        for (ShowSeat* seat : selectedSeats) {
            seat->book();
        }

        double total = priceCalculator.calculateTotal(selectedSeats);

        Booking* booking =
            new Booking(&customer, &show, selectedSeats, total);

        Payment* payment = createPayment(paymentChoice, failPayment);

        bool paymentSuccessful = payment->pay(total);

        if (!paymentSuccessful) {
            cout << "Payment failed. Booking NOT confirmed.\n";

            // Release seats because payment failed.
            for (ShowSeat* seat : selectedSeats) {
                seat->release();
            }

            delete payment;
            delete booking;
            return nullptr;
        }

        booking->confirm();
        bookings.push_back(booking);

        delete payment;

        ticketPrinter.printTicket(*booking);
        return booking;
    }

    bool cancelBooking(int bookingId) {
        for (Booking* booking : bookings) {
            if (booking->getBookingId() == bookingId) {
                if (booking->getStatus() == BookingStatus::CANCELLED) {
                    cout << "Booking is already cancelled.\n";
                    return false;
                }

                booking->cancel();
                cout << "Booking " << bookingId
                     << " cancelled successfully.\n";
                return true;
            }
        }

        cout << "Booking ID not found.\n";
        return false;
    }

    void listBookings() const {
        cout << "\n--- Bookings ---\n";

        if (bookings.empty()) {
            cout << "No bookings found.\n";
            return;
        }

        for (const Booking* booking : bookings) {
            cout << "ID: " << booking->getBookingId()
                 << " | Movie: "
                 << booking->getShow()->getMovie()->getTitle()
                 << " | Amount: Rs."
                 << booking->getTotalAmount()
                 << " | Status: "
                 << booking->getStatusName() << "\n";
        }
    }
};
#endif
