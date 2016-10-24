/**
@file World
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/
#include "World.h"
#include "Plane.h"
#include "TextureHolder.h"
#include "SpriteNode.h"
namespace GEX {
	World::World(sf::RenderWindow& window) :
		_window(window),
		_worldView(window.getDefaultView()),
		_sceneGraph(),
		_sceneLayers(),
		_worldBounds(0.f, 0.f, _worldView.getSize().x, 2000.f),
		_spawnPosition(_worldView.getSize().x / 2.f, _worldBounds.height - (_worldView.getSize().y / 2)),
		_scrollSpeed(-50.0f),
		_queue(),
		_playerAircraft(nullptr)
	{
		
		buildScene();


		//sets the view to the bottom since we will scroll upwards
		_worldView.setCenter(_spawnPosition);

	}


	World::~World()
	{
	}
	void World::update(sf::Time deltaTime)
	{
		//_worldView.zoom(1.00001); //goes OUT slowly
		//_worldView.rotate(0.001); //spins!

		//backgorund
		_worldView.move(0.f, _scrollSpeed * deltaTime.asSeconds()); // moves the view which moves the background moves and not the planes
		_playerAircraft->setVelocity(0.f, 0.f);
		while (!_queue.isEmpty())
		{
			_sceneGraph.onCommand(_queue.pop(), sf::Time::Zero);
		}
		// adjusting player pos
		sf::Vector2f position = _playerAircraft->getPosition();
		sf::Vector2f velocity = _playerAircraft->getVelocity();

		//checking OOB
		//								left side									right side
		if (position.x < _worldBounds.left + 150.f || position.x > _worldBounds.left + _worldBounds.width - 150)
		{
			velocity.x *= -1;
			_playerAircraft->setVelocity(velocity);
		}

		if (position.y < 0 || position.y > _worldBounds.height)
		{
			velocity.y *= -1;
			_playerAircraft->setVelocity(velocity);
		}
		spawnEnemies();
		//movement
		_sceneGraph.update(deltaTime, getCommandQueue());

		
	}
	void World::draw() //creates the view 
	{
		_window.setView(_worldView);
		_window.draw(_sceneGraph);
	}
	CommandQueue & World::getCommandQueue()
	{
		return _queue;
	}
	
	void World::buildScene()
	{
		//LAYER NODES FOR SCENE GRAPH

		for (std::size_t i = 0; i < LayerCount; i++)
		{
			Category::type category = (i == Air) ? Category::SceneAirLayer : Category::none;
			SceneNode::ptr layer(new SceneNode(category));
			_sceneLayers[i] = layer.get();
			_sceneGraph.attatchChild(std::move(layer));
		}

		//background

		
		sf::Texture& texture = TextureHolder::getInstance().get(TextureID::DESERT);
		sf::IntRect textureRect(_worldBounds);
		texture.setRepeated(true);
		//background sprite
		std::unique_ptr<SpriteNode> _background(new SpriteNode(texture, textureRect));
		_background->setPosition(_worldBounds.left, _worldBounds.top);
		_sceneLayers[Background]->attatchChild(std::move(_background));

		std::unique_ptr<Plane> plane(new Plane(Plane::Type::EAGLE));
		plane->setPosition(_spawnPosition);
		plane->setVelocity(40.f, _scrollSpeed);
		_playerAircraft = plane.get();
		_sceneLayers[Air]->attatchChild(std::move(plane));

		

		addEnemies();
	}
	sf::FloatRect World::getViewBounds() const //gets the windows size
	{
		return sf::FloatRect(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
	}
	sf::FloatRect World::getBalleFieldBounds() const //gets the windows size plus some extra so we can spawn objects offscreen
	{
		sf::FloatRect bounds = getViewBounds();
		bounds.height += 100;
		bounds.top -= 100;
		return bounds;
	}
	void World::spawnEnemies() //creates the enemy planes 
	{
		while (!_enemySpawnPoints.empty() && _enemySpawnPoints.back().y > getBalleFieldBounds().top) 
		{
			auto spawn = _enemySpawnPoints.back();
			std::unique_ptr<Plane> enemy(new Plane(spawn.type));
			enemy->setPosition(spawn.x, spawn.y);
			enemy->setRotation(180.f);
			_sceneLayers[Air]->attatchChild(std::move(enemy));

			_enemySpawnPoints.pop_back();
		

		}
	}	
	void World::addEnemies() //adds all the planes onto a vector and then sorts them from biggest to smallest so we just need to take it off the back instead of going through the vector to find the smallest
	{
		addEnemy(Plane::Type::RAPTOR, -250, 200);
		addEnemy(Plane::Type::RAPTOR, +250, 200);
		addEnemy(Plane::Type::RAPTOR, -150, 450);
		addEnemy(Plane::Type::RAPTOR, 0, 450);
		addEnemy(Plane::Type::RAPTOR, -250, 550);
		addEnemy(Plane::Type::RAPTOR, -50, 700);
		addEnemy(Plane::Type::RAPTOR, -150, 700);

		std::sort(_enemySpawnPoints.begin(), _enemySpawnPoints.end(), [](SpawnPoint lhs, SpawnPoint rhs) {return lhs.y < rhs.y; });
	
	}
	
	void World::addEnemy(Plane::Type type, float relx, float rely)
	{
		addEnemy(SpawnPoint(type, relx, rely));
	}
	void World::addEnemy(SpawnPoint point) //puts the planes onto the vetor
	{
		point.x = _spawnPosition.x + point.x;
		point.y = _spawnPosition.y - point.y;
		_enemySpawnPoints.push_back(point);
	}
}