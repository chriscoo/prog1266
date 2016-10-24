/**
@file GameState
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/
#pragma once

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics\Text.hpp"

#include "World.h"
#include "PlayerControl.h"
#include "State.h"
#include "CommandQueue.h"

namespace GEX {

	class GameState : public State
	{
	public:
		GameState(StateStack& stack, Context context);

		virtual void draw();
		virtual bool update(sf::Time dt);
		virtual bool handleEvent(const sf::Event& event);

	private:

		World _world;
		PlayerControl& _player;
	};

}