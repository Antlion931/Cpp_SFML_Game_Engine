#pragma once
#include "GUI.hpp"
#include "Standard/Events/event_emitter.hpp"
#include "AnimationManager.hpp"


class button : public GUI
{
public:
    void onClick() { eventEmitter.emit(); }
protected:
    EventEmitter<> eventEmitter;
protected:
    virtual void onCreate() {}
    virtual void onDraw() const {

    }
    virtual void onUpdate(const sf::Time& delta) {

    }
private:
    AnimationManager animationManager = AnimationManager("test", {{"run",1}},"run");
};


