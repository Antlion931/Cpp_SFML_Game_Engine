#include <filesystem>
#include <assert.h>

#include "TextureLoaderPrototypeFactory.hpp"

TextureLoaderPrototypeFactory* TextureLoaderPrototypeFactory::instance = nullptr;

std::shared_ptr<TextureLoader> TextureLoaderPrototypeFactory::make(std::string name)
{
    if(!prototypes.count(name))
    {
        std::cerr << "There's no directory " << name << " in your textures directory  " << std::endl;
    }
    return prototypes[name];
}

TextureLoaderPrototypeFactory* TextureLoaderPrototypeFactory::getInstance(std::string directoryPath)
{
    if(instance == nullptr)
    {
        assert(directoryPath != "");
        instance = new TextureLoaderPrototypeFactory(directoryPath);
    }

    return instance;
}

TextureLoaderPrototypeFactory::TextureLoaderPrototypeFactory(std::string directoryPath)
{
    for(const auto &entry: std::filesystem::directory_iterator(directoryPath))
    {
        TextureLoader loader(entry.path().string());

        std::string name = entry.path().string();
        name.erase(0,directoryPath.length());

        prototypes[name] = std::make_shared<TextureLoader>(loader);
    }
}
