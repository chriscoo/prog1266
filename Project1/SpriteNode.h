/**
@file SpriteNode
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#pragma once
#include "SceneNode.h"

namespace GEX {
	class SpriteNode : public SceneNode
	{
	public:
		SpriteNode( sf::Texture&, sf::IntRect);
		SpriteNode(sf::Texture&);
		~SpriteNode();
	private:

		void drawCurrent(sf::RenderTarget & target, sf::RenderStates state) const;

	private:
		sf::Sprite _sprite;
	};
}

