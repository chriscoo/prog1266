/**
@file DataTables
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/

#include "DataTables.h"

namespace GEX {
	std::map<Plane::Type, AircraftData> GEX::InitializeAircraftData()
	{
		std::map<Plane::Type, AircraftData> data;


		data[Plane::Type::RAPTOR].hitpoints = 20;
		data[Plane::Type::RAPTOR].speed = 80;
		data[Plane::Type::RAPTOR].texture = TextureID::RAPTOR;
		data[Plane::Type::RAPTOR].fireInterval = sf::seconds(2);

		data[Plane::Type::RAPTOR].directions.push_back(Direction(80.f, 80.f));
		data[Plane::Type::RAPTOR].directions.push_back(Direction(-80.f, 100.f));
		data[Plane::Type::RAPTOR].directions.push_back(Direction(80.f, 80.f));

		data[Plane::Type::AVENGER].hitpoints = 40;
		data[Plane::Type::AVENGER].speed = 50;
		data[Plane::Type::AVENGER].texture = TextureID::AVENGER;
		data[Plane::Type::AVENGER].fireInterval = sf::seconds(2);

		data[Plane::Type::AVENGER].directions.push_back(Direction(-70.f, 150.f));
		data[Plane::Type::AVENGER].directions.push_back(Direction(0.f, 25.f));
		data[Plane::Type::AVENGER].directions.push_back(Direction(150.f, 80.f));

		data[Plane::Type::EAGLE].hitpoints = 100;
		data[Plane::Type::EAGLE].speed = 200;
		data[Plane::Type::EAGLE].texture = TextureID::AIRPLANE;
		data[Plane::Type::EAGLE].fireInterval = sf::seconds(1);


		return data;
	}
	Direction::Direction(float a, float d) : angle(a), distance(d)
	{
	}

	std::map<Projectile::Type, ProjectileData> GEX::InitializeProjectileData()
	{
		std::map<Projectile::Type, ProjectileData> data;

		data[Projectile::Type::EnemyBullet].damage = 100;
		data[Projectile::Type::EnemyBullet].speed = 200;
		data[Projectile::Type::EnemyBullet].texture = TextureID::BULLET;

		data[Projectile::Type::AlliedBullet].damage = 100;
		data[Projectile::Type::AlliedBullet].speed = 200;
		data[Projectile::Type::AlliedBullet].texture = TextureID::BULLET;

		data[Projectile::Type::Missle].damage = 100;
		data[Projectile::Type::Missle].speed = 200;
		data[Projectile::Type::Missle].texture = TextureID::MISSLE;
	
		return data;
	}
}