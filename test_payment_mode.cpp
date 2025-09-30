#include <memory>
#include <string>
#include <gtest/gtest.h>

#include "payment_modes.h"
#include "processor_factory.h"

// Utility: get processor safely
std::string processPayment(const std::string& mode, double amount) {
    auto processor = ProcessorFactory::create(mode);
    if (!processor) {
        return "Invalid";
    }
    return processor->process(amount);
}

// -------- TESTS --------

// Requirement: PayPal support
TEST(CheckoutTest, PayPalPayment) {
    EXPECT_EQ(processPayment("PayPal", 100.0),
              "Processing PayPal payment of $100");
}

// Requirement: GooglePay support
TEST(CheckoutTest, GooglePayPayment) {
    EXPECT_EQ(processPayment("GooglePay", 50.5),
              "Processing GooglePay payment of $50.5");
}

// Requirement: CreditCard support
TEST(CheckoutTest, CreditCardPayment) {
    EXPECT_EQ(processPayment("CreditCard", 250.0),
              "Processing CreditCard payment of $250");
}

// Requirement: Unsupported payment mode handled gracefully
TEST(CheckoutTest, InvalidPaymentMode) {
    EXPECT_EQ(processPayment("Bitcoin", 1000.0), "Invalid");
}

// Requirement: Placeholder logic (test that stub message still prints correctly)
TEST(CheckoutTest, PlaceholderLogicStillWorks) {
    // For now just ensure PayPal prints expected placeholder confirmation
    std::string result = processPayment("PayPal", 42.42);
    EXPECT_NE(result.find("PayPal"), std::string::npos);  // contains "PayPal"
    EXPECT_NE(result.find("42.42"), std::string::npos);   // contains amount
}
