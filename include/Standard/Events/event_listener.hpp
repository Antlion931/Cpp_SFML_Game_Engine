#pragma once
#include <functional>
#include <memory>

template<typename... Ts>
class EventListener {
    private:
        std::shared_ptr<std::function<void(Ts...)>> f;

    public:
        //Tworzy Listenera z daną funkcją do odpalenia w razie otrzymania wiadomości, spoko są lambdy:
        //class Test {
        //  EventListener<int> el = EventListener<int>([this](int n) {
        //    std::cout << n << std::endl;
        //  })    
        //}
        //EventListenery najlepiej tworzyć jak wyżej
        //Zmienne, które zbieramy do funkcji (np. this) muszą żyć conajmniej tyle, co ten listener
        EventListener(std::function<void(Ts...)> f) {
            this->f = std::make_shared<std::function<void(Ts...)>>(f);
        }
 
        std::weak_ptr<std::function<void(Ts...)>> get_func() {
            return f;
        }
};

