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

#include "GameState.h"
#include "Utility.h"

namespace GEX {




	GameState::GameState(StateStack & stack, Context context) : State(stack, context), _world(*context.window), _player(*context.player) {}

	void GameState::draw()
	{
		_world.draw();
	}

	bool GameState::update(sf::Time dt)
	{
		_world.update(dt);

		CommandQueue& commands = _world.getCommandQueue();
		_player.handleRealTimeInput(commands);

		return true;
	}

	bool GameState::handleEvent(const sf::Event & event)
	{
		CommandQueue& command = _world.getCommandQueue();

		_player.handleEvent(event, command);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			requestStackPush(StateID::Pause);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
		{
			requestStackPop();
			requestStackPush(StateID::Menu);
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G)
			requestStackPush(StateID::Gex);

		return true;
	}


}
