
#ifndef BOOKING_CPP
#define BOOKING_CPP
#include <vector>
#include <string>
using namespace std;

enum class BookingStatus { PENDING, CONFIRMED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer* customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer* customer, Show* show,
            const vector<ShowSeat*>& seats, double totalAmount)
        : customer(customer),
          show(show),
          seats(seats),
          totalAmount(totalAmount),
          status(BookingStatus::PENDING) {
        bookingId = nextBookingId++;
    }

    void confirm() {
        status = BookingStatus::CONFIRMED;
    }

    void cancel() {
        for (ShowSeat* seat : seats) {
            seat->release();
        }
        status = BookingStatus::CANCELLED;
    }

    int getBookingId() const { return bookingId; }
    Customer* getCustomer() const { return customer; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }

    string getStatusName() const {
        if (status == BookingStatus::PENDING) return "PENDING";
        if (status == BookingStatus::CONFIRMED) return "CONFIRMED";
        return "CANCELLED";
    }
};

int Booking::nextBookingId = 1001;
#endif
