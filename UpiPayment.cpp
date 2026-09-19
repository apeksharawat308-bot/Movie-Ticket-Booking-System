
#ifndef UPIPAYMENT_CPP
#define UPIPAYMENT_CPP

class UpiPayment : public Payment {
private:
    bool shouldFail;

public:
    explicit UpiPayment(bool shouldFail = false)
        : shouldFail(shouldFail) {}

    bool pay(double amount) override {
        cout << "\nProcessing UPI payment of Rs." << amount << "...\n";

        if (shouldFail) {
            cout << "UPI payment failed.\n";
            return false;
        }

        cout << "UPI payment successful.\n";
        return true;
    }

    string getMethodName() const override {
        return "UPI";
    }
};
#endif
