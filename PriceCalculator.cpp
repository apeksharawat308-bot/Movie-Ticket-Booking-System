
#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP

class PriceCalculator {
private:
    static constexpr double SILVER_PRICE = 150.0;
    static constexpr double GOLD_PRICE = 250.0;
    static constexpr double PLATINUM_PRICE = 400.0;

public:
    double getPrice(SeatType type) const {
        if (type == SeatType::SILVER) return SILVER_PRICE;
        if (type == SeatType::GOLD) return GOLD_PRICE;
        return PLATINUM_PRICE;
    }

    double calculateTotal(const vector<ShowSeat*>& seats) const {
        double total = 0;

        for (ShowSeat* showSeat : seats) {
            total += getPrice(showSeat->getSeat()->getType());
        }

        return total;
    }
};
#endif
