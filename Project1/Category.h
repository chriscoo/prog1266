/**
@file Category.h
@author  Chris Arsenault Chris.arsenault06@gmail.com
@version 1.0

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt

Additions and modifications are my sole work for prog 1266

@section DESCRIPTION

<your description of the purpose of this file here>

*/
#pragma once
namespace GEX {

	namespace Category {
		enum type {
			none = 0,
			SceneAirLayer = 1 << 0,
			playerAircraft = 1 << 1,
			AlliedAircraft = 1 << 2,
			EnemyAircraft = 1 << 3,
			AlliedBullet = 1 << 4,
			EnemyBullet = 1 << 5,
			PickUp = 1 << 6,

			Plane = playerAircraft | AlliedAircraft | EnemyAircraft,
			Projectile = EnemyBullet | AlliedBullet
		};

	}


}