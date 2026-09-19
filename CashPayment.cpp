
#ifndef CASHPAYMENT_CPP
#define CASHPAYMENT_CPP

class CashPayment : public Payment {
private:
    bool shouldFail;

public:
    explicit CashPayment(bool shouldFail = false)
        : shouldFail(shouldFail) {}

    bool pay(double amount) override {
        cout << "\nReceiving Cash of Rs." << amount << "...\n";

        if (shouldFail) {
            cout << "Cash payment failed.\n";
            return false;
        }

        cout << "Cash payment successful.\n";
        return true;
    }

    string getMethodName() const override {
        return "CASH";
    }
};
#endif
