/**
@file DataTable.h
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/
#pragma once
#include "TextureHolder.h"
#include "Plane.h"
#include "Projectile.h"
#include "Utility.h"
#include <map>
#include <vector>
namespace GEX {

	struct Direction
	{
		Direction(float a, float d);
		float angle;
		float distance;


	};
	struct AircraftData
	{
		int					   hitpoints;
		float				   speed;
		TextureID			   texture;
		sf::Time			   fireInterval;
		std::vector<Direction> directions;
	};

	struct ProjectileData
	{
		int			damage;
		float		speed;
		TextureID	texture;
	};
	std::map<Plane::Type, AircraftData> InitializeAircraftData();
	std::map<Projectile::Type, ProjectileData> InitializeProjectileData();
}