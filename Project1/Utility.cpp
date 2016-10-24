/**
@file Utility
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#include "Utility.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cmath>


namespace GEX {

	void centerOrigin(sf::Sprite& sprite) { //centers the origin of sprites
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
	}



	void centerOrigin(sf::Text& text) { //centers the origin of text nodes
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
	}



}