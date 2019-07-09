#pragma once
#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>

using namespace std;

class robot
{

protected:
	string robot_name;	//name of robot
	int countSteps; //number of steps which the robot has already done

	//the positions of the Robot in the grid (x,y)
	int positionX;
	int positionY;


public:
	// set up a robot with name n, placed at the origin-position 0,0
	explicit robot(const string &n);

	//returns the name of the robot (as supplied to the constructor).
	const std::string &name() const {
		return robot_name;
	}

	//moves the robot one step to the north
	void move_north();

	//moves the robot one step to the east
	void move_east();

	//moves the robot one step to the south
	void move_south();

	//moves the robot one step to the west
	void move_west();

	//returns the current distance north of the robot.
	int north() const {
		return positionY;
	}

	//returns the current distance east of the robot.
	int east() const {
		return positionX;
	}

	//returns the total distance travelled by this robot since it was created.
	int travelled() const {
		return countSteps;
	}

	//sets the name of the robot
	void set_name(const string &n);

	//gets the name of the robot
	const string get_name()const;
};


/*
 * External fucntions
 */

int distance(const robot &r);	//returns the distance of robot from the origin


#endif