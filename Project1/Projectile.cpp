/**
@file Projectile
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#include "Projectile.h"
#include "TextureHolder.h"
#include "TextNode.h"
#include "DataTables.h"
#include "Utility.h"
#include <iostream>
#include <cassert>


namespace GEX {
	const 	std::map<Projectile::Type, ProjectileData> table = InitializeProjectileData();;


	Projectile::Projectile(Type type) : Entity(), _type(type), _sprite(TextureHolder::getInstance().get(table.at(type).texture))
	{
		centerOrigin(_sprite);
	}

	unsigned int Projectile::getCategory() const //to find out who the bullets should damage
	{

		if (_type == Type::AlliedBullet)
			return Category::AlliedBullet;
		else
			return Category::EnemyBullet;
	}


float Projectile::getMaxSpeed() const //gets the bullets/missiles speed
{
	return table.at(_type).speed;
}

void Projectile::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	Entity::updateCurrent(dt, commands);
}

void Projectile::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

}
