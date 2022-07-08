#include <iostream>
#include <SFML/Graphics.hpp>


namespace std {
  template <>
  struct hash<sf::Color>
  {
    std::size_t operator()(const sf::Color& k) const
    {
      using std::size_t;
      using std::hash;
      using std::string;

      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      int p1 = 73856093,p2 = 19349663,p3 = 83492791;

      return (k.r * p1) ^ (k.g * p2) ^ (k.b * p3);
    }
  };

}