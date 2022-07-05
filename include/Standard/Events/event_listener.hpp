#pragma once
#include <functional>
#include <memory>

template<typename... Ts>
class EventListener {
    private:
        std::shared_ptr<std::function<void(Ts...)>> f;

    public:
        EventListener(std::function<void(Ts...)> f) {
            this->f = std::make_shared<std::function<void(Ts...)>>(f);
        }

        std::weak_ptr<std::function<void(Ts...)>> get_func() {
            return f;
        }
};

