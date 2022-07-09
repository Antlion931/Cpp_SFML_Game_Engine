#pragma once

// TO DO

class ConfigLoader
{
public:
    void load()
    {

    }
    void save()
    {

    }
    static ConfigLoader *get_instance()
    {
        if(m_instance == nullptr)
            m_instance = new ConfigLoader();
        return m_instance;
    }
private:
    static ConfigLoader* m_instance;
public:
    ConfigLoader(ConfigLoader &other) = delete;
    void operator=(const ConfigLoader &) = delete;
private:
    ConfigLoader(){}
    ~ConfigLoader(){}
};
