#pragma once
#include "SFML/Graphics.hpp"
#include <cmath>

namespace engine
{
    template<typename T>
    class Vec2
    {
        public:
            T x;
            T y;
            
            Vec2() : x(0), y(0) {}
            Vec2(T x, T y) : x(x), y(y) {}

            T dot(const Vec2<T> &rhs) {
                return x*rhs.x + y*rhs.y;
            }

            T length_sq() {
                return x*x + y*y;
            }

            double length() {
                return std::sqrt(length_sq());
            }

            Vec2<double> norm() {
                double len = length();
                return Vec2<double>(x/len,y/len);
            }

            //konwersje
            operator sf::Vector2<T>() const {
                return {x, y};
            }
    };

    typedef Vec2<int> Vec2i;
    typedef Vec2<double> Vec2d;
    typedef Vec2<float> Vec2f;

    //unarny minus
    template<typename T> 
    Vec2<T> operator-(const Vec2<T> &rhs) {
        return Vec2(-rhs.x,-rhs.y);
    }

    //dodawanie
    template<typename T> 
    Vec2<T> operator+(const Vec2<T> &lhs, const Vec2<T> &rhs) {
        return Vec2(lhs.x + rhs.x,lhs.y + rhs.y);
    }

    template<typename T> 
    Vec2<T>& operator+=(Vec2<T> &lhs, const Vec2<T> &rhs) {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }

    //odejmowanie
    template<typename T> 
    Vec2<T> operator-(const Vec2<T> &lhs, const Vec2<T> &rhs) {
        return Vec2(lhs.x - rhs.x,lhs.y - rhs.y);
    }

    template<typename T> 
    Vec2<T>& operator-=(Vec2<T> &lhs, const Vec2<T> &rhs) {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
    }

    //mnożenie przez skalar
    template<typename T> 
    Vec2<T> operator*(T &lhs, const Vec2<T> &rhs) {
        return Vec2(lhs * rhs.x,lhs * rhs.y);
    }

    template<typename T> 
    Vec2<T> operator*(const Vec2<T> &lhs, T &rhs) {
        return Vec2(lhs.x * rhs,lhs.y * rhs);
    }
    
    template<typename T> 
    Vec2<T>& operator*=(Vec2<T> &lhs, const T &rhs) {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }

    //dzielenie przez skalar
    template<typename T> 
    Vec2<T> operator/(const Vec2<T> &lhs, T &rhs) {
        return Vec2(lhs.x / rhs,lhs.y / rhs);
    }
    
    template<typename T> 
    Vec2<T>& operator/=(Vec2<T> &lhs, const T &rhs) {
        lhs.x /= rhs;
        lhs.y /= rhs;
        return lhs;
    }   

    //porównywanie
    template<typename T> 
    Vec2<T> operator==(const Vec2<T> &lhs, const Vec2<T> &rhs) {
        return rhs.x == lhs.x && rhs.y == lhs.y;
    }

    //wypisanie 
    template<typename T> 
    std::ostream& operator<< (std::ostream& out, const Vec2<T> &vec)
    {
        return out << vec.x << " " << vec.y;
    }
}