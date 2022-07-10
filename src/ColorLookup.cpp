#include "ColorLookup.hpp"

ColorLookup* ColorLookup::m_instance = nullptr;

ColorLookup* ColorLookup::get_instance()
{
    if(m_instance == nullptr)
    {
        m_instance = new ColorLookup();
    }
    return m_instance;
}