#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <functional>

// Abstract base class
class PaymentProcessor {
 public:
    virtual ~PaymentProcessor() = default;
    virtual std::string process(double amount) const = 0;
};
