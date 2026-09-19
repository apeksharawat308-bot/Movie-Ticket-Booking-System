
#ifndef CARDPAYMENT_CPP
#define CARDPAYMENT_CPP

class CardPayment : public Payment {
private:
    bool shouldFail;

public:
    explicit CardPayment(bool shouldFail = false)
        : shouldFail(shouldFail) {}

    bool pay(double amount) override {
        cout << "\nProcessing Card payment of Rs." << amount << "...\n";

        if (shouldFail) {
            cout << "Card payment failed.\n";
            return false;
        }

        cout << "Card payment successful.\n";
        return true;
    }

    string getMethodName() const override {
        return "CARD";
    }
};
#endif
