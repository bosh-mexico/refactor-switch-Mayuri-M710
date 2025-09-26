#pragma once
#include "payment_processor.h"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

// Factory with self-registration
class ProcessorFactory {
 public:
    using Creator = std::function<std::unique_ptr<PaymentProcessor>()>;

    static void registerProcessor(const std::string& name, Creator creator) {
        getRegistry()[name] = std::move(creator);  //  At least two spaces is best between code and comments
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