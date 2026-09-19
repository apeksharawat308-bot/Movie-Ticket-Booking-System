
#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP

enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    Seat* seat;
    SeatStatus status;

public:
    ShowSeat(Seat* seat)
        : seat(seat), status(SeatStatus::AVAILABLE) {}

    bool isAvailable() const {
        return status == SeatStatus::AVAILABLE;
    }

    void book() {
        status = SeatStatus::BOOKED;
    }

    void release() {
        status = SeatStatus::AVAILABLE;
    }

    Seat* getSeat() const {
        return seat;
    }

    SeatStatus getStatus() const {
        return status;
    }
};
#endif
