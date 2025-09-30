#pragma once

#include <memory>
#include <sstream>
#include <string>

#include "processor_factory.h"

// Shared formatter (DRY)
inline std::string formatMessage(const std::string& mode, double amount) {
    std::ostringstream oss;
    oss << "Processing " << mode << " payment of $" << amount;
    return oss.str();
}

// Macro for self-registration (reduces boilerplate)
#define REGISTER_PROCESSOR(ClassName, ModeName) \
    static bool ClassName##_registered = [] { \
        ProcessorFactory::registerProcessor( \
            ModeName, []() { return std::make_unique<ClassName>(); }) ; \
        return true; \
    }();

// ---------------- PAYMENT PROCESSORS ----------------

// PayPal
class PayPalProcessor : public PaymentProcessor {
 public:
    std::string process(double amount) const override {
        // TODO(fef2kor): Integrate with PayPal API
        return formatMessage("PayPal", amount);
    }
};
REGISTER_PROCESSOR(PayPalProcessor, "PayPal")

// GooglePay
class GooglePayProcessor : public PaymentProcessor {
 public:
    std::string process(double amount) const override {
        // TODO(fef2kor): Integrate with GooglePay API
        return formatMessage("GooglePay", amount);
    }
};
REGISTER_PROCESSOR(GooglePayProcessor, "GooglePay")

// CreditCard
class CreditCardProcessor : public PaymentProcessor {
 public:
    std::string process(double amount) const override {
        // TODO(fef2kor): Integrate with Credit Card API
        return formatMessage("CreditCard", amount);
    }
};
REGISTER_PROCESSOR(CreditCardProcessor, "CreditCard")
