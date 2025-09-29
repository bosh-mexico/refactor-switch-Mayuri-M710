#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include "payment_processor.h"

// Factory with self-registration
class ProcessorFactory {
 public:
    using Creator = std::function<std::unique_ptr<PaymentProcessor>()>;

    static void registerProcessor(const std::string& name, Creator creator) {
        // At least two spaces is best between code and comments
        getRegistry()[name] = std::move(creator);
    }

    static std::unique_ptr<PaymentProcessor> create(const std::string& name) {
        auto& reg = getRegistry();
        auto it = reg.find(name);
        if (it != reg.end()) {
            return it->second();
        }
        return nullptr;  // invalid mode
    }

 private:
    static std::unordered_map<std::string, Creator>& getRegistry() {
        static std::unordered_map<std::string, Creator> registry;
        return registry;
    }
};
