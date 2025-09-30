#include <iostream>
#include <string>
#include "payment_modes.h"

int main() {
    double amount;
    std::string modeStr;

    std::cout << "Enter payment amount: ";
    std::cin >> amount;
    std::cin.ignore();

    std::cout << "Enter payment mode (PayPal, GooglePay, CreditCard): ";
    std::getline(std::cin, modeStr);

    auto processor = ProcessorFactory::create(modeStr);
    if (processor) {
        std::cout << processor->process(amount) << '\n';
    } else {
        std::cout << "Invalid payment mode selected!\n";
    }

    return 0;
}
