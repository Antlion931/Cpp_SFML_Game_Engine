#pragma once
#include <unordered_set>
#include <algorithm>
#include <functional>
#include "event_listener.hpp"

template<typename... Ts>
class EventEmitter{
    private:
        std::list<std::weak_ptr<std::function<void(Ts...)>>> subscriber_list;
    
    public:
        void subscribe(EventListener<Ts...> &listener) {
            subscriber_list.push_back(listener.get_func());
        }

        void emit(Ts... values) {
            auto it = subscriber_list.begin();
            while(it != subscriber_list.end()) {
                if(auto listener = it->lock()) {
                   (*listener)(values...);
                   it++;
                }
                else{
                    it = subscriber_list.erase(it);
                }

            }
        }
};




