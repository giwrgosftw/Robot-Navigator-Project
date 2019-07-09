//  Created by Georgios Karanasios on 25/11/2018.
//  Copyright © 2018 Georgios Karanasios. All rights reserved.

#pragma once
#ifndef GAME_H
#define GAME_H

#include "robot.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

class game
{

private:
	map<string, robot> game_map;	//a map where class holds the robot(s) there
	typedef map<string, robot>::const_iterator iter;	//iterator of the map

	list<string> robotsName10_list;	//a list which keeps the robots names with no more than 10 steps from the origin.
	int maxDist;	//the furthest distance of any robot from the origin.
	string furthestRobot;	//the name of the robot that is the furthest distance from the origin.


public:
	// Default Constructor
	game();

	//returns the total number of robots in the game (initially none)
	int num_robots() const {
		return game_map.size();
	}

	//move the named robot one step
	void move(const string &name, int dir);

	//check if the name of the robot exist in the list
	//which includes the names of the robots with no more than 10 steps from the origin.
	bool findRobotName10(const string &name);

	//returns the number of robots no more than 10 steps from the origin
	int num_close() const {
		return robotsName10_list.size();
	}

	//returns the furthest distance of any robot from the origin.
	int max_distance() const {
		return maxDist;
	}

	//returns the name of the robot that is the furthest distance from the origin.
	string furthest() const {
		return furthestRobot;
	}

	//returns a collection of all the robots in the system, arranged in increasing order of total distance travelled.
	vector<robot> robots_by_travelled() const;


//	//prints the vector
//	void print_vector(vector<robot> robots_vector);
};


/*
 * External fucntions
 */


//Compares the robots based on their total distance travelled since they were created.
bool compare_travelled(const robot& x, const robot& y);

//Compares the robots based on their name.
bool compare_name(const robot& x, const robot& y);


#endif