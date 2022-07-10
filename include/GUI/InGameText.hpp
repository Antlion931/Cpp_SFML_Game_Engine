#pragma once
#include "GUI/text.hpp"

class InGameText : public engine::Text
{
public:
    InGameText(std::string _l, float* _p, std::string _r, bool _isBiggerGood)
    {
        isBiggerGood = _isBiggerGood;
        leftString = _l;
        rightString = _r;
        value = _p;
        lastValue = *value;
        currentTime = 0.0f;
        isNewValueBigger = isBiggerGood;
        set_text(leftString + std::to_string((int)lastValue) + rightString);
    }
        virtual void onDraw() const {
            render_layer->draw(text, global_transform.getTransform());
        }

    virtual void onUpdate(const sf::Time& delta) 
    {
        text.setCharacterSize(25);
        currentTime += delta.asSeconds();

        if(currentTime < 1.0f)
        {
            bool buffer = isBiggerGood ? isNewValueBigger : !isNewValueBigger;

            if(buffer)
            {
                text.setColor(sf::Color(255*currentTime, 255, 255*currentTime));
            }
            else
            {
                text.setColor(sf::Color(255, 255*currentTime, 255*currentTime));
            }
        }
        else
        {
            text.setColor(sf::Color(255,255,255));
        }

        if(lastValue != *value)
        {
            currentTime = 0.0f;
            isNewValueBigger = lastValue < *value;
            lastValue = *value;
            set_text(leftString + std::to_string((int)lastValue) + rightString);
        }
    }
private:
    float currentTime;
    std::string leftString;
    std::string rightString;

    bool isBiggerGood;
    bool isNewValueBigger;
    float lastValue;
    float * value;

};
