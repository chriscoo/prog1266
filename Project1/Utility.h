/**
@file utility
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#pragma once
#include <cmath>
namespace sf {
	class Sprite;
	class Text;
}
namespace GEX {

		void centerOrigin(sf::Sprite& sprite);
		void centerOrigin(sf::Text& text);

		const float M_PI = 3.14159265f;
		inline float degreesToRadians(float degress) { return degress*M_PI / 180.f; }
		inline float radiansToDegress(float radians) { return radians * 180.f / M_PI; }
		inline float sin(float degress) { return std::sin(degreesToRadians(degress)); }
		inline float cos(float degress) { return std::cos(degreesToRadians(degress)); }

}
