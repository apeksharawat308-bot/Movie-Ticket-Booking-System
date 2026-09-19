
#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP

class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n========================================\n";
        cout << "              MOVIE TICKET\n";
        cout << "========================================\n";
        cout << "Booking ID : " << booking.getBookingId() << "\n";
        cout << "Customer   : " << booking.getCustomer()->getName() << "\n";
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen     : " << booking.getShow()->getScreen()->getNumber() << "\n";
        cout << "Time       : " << booking.getShow()->getStartTime() << "\n";
        cout << "Seats      : ";

        for (ShowSeat* seat : booking.getSeats()) {
            cout << seat->getSeat()->getNumber() << " ";
        }

        cout << "\nTotal      : Rs." << booking.getTotalAmount() << "\n";
        cout << "Status     : " << booking.getStatusName() << "\n";
        cout << "========================================\n";
    }
};
#endif
