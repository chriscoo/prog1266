/**
@file Plane
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "CommandQueue.h"
#include <memory>
namespace GEX {

	class TextNode;
	class Plane : public Entity
	{
	public:
		enum class  Type{ EAGLE, RAPTOR, AVENGER};
		
	public:
						Plane(Type type = Type::EAGLE);
		virtual			~Plane() {};
		unsigned int	getCategory() const override; //sets the correct category for the different types of airplanes
		void			drawCurrent(sf::RenderTarget & target, sf::RenderStates state) const; //draws the current instance of plane
		void			updateCurrent(sf::Time dt, CommandQueue& commands);
		void			updateTexts();
		void			movementUpdate(sf::Time dt); //moves the plane
		void			fireMissle(); 
		void			fireBullet();
		void			checkProjectileLaunch(sf::Time dt, CommandQueue& commands);
		float			getMaxSpeed() const; //gets the planes speed from he datatable
		sf::FloatRect	getBoundingRect() const override; //gets the hitbox
		void			createBullets(SceneNode& node)const;
			void		createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset)const;
			bool isAllied() const;
	private:
		Type _type;
		sf::Sprite		_player; //the controllable plane the user uses
		TextNode*		_healthDisplay;
		int				_directionIndex;
		float			_travelDistance;

		
		bool			_isFiringBullets;
		bool			_isFiringMissle;
		sf::Time		__fireCountdown;

		Command			_fireCommand;
		Command			_launchMissileCommand;
		std::size_t				_missleAmmo;
		std::size_t				_fireRateInterval;
		std::size_t				_spreadLevel;
	};

}