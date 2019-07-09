#include "robot.h"
#include  <cstdlib>

/*
 * Robot class implementation
 */

robot::robot(const string &n) {	//declares the robot object
	robot_name = n;
	positionX = 0;
	positionY = 0;
	countSteps = 0;
}

// declares the name of the robot
void robot::set_name(const string &n) {
	robot_name = n;
}

// returns name of the robot (needed to get private members of robot class)
const string robot::get_name()const {
	return robot_name;
}



/* 2D Dimension

           N
		   ▲
		   | ▲
		   | | +
		   | |
		   |
   - ◄---- | ----► +
W ◄-----------------► E
		   |
		   | |
		   | | -
           | ▼
		   ▼
           S
*/


//moves the robot one step to the north
void robot::move_north() {
	positionY++;
	countSteps++;
}

//moves the robot one step to the south
void robot::move_south() {
	positionY--;
	countSteps++;
}

//moves the robot one step to the east
void robot::move_east() {
	positionX++;
	countSteps++;
}

//moves the robot one step to the west
void robot::move_west() {
	positionX--;
	countSteps++;
}

//returns the distance of robot r from the origin
int distance(const robot &r) {
	return abs(r.north()) + abs(r.east());	//always returns positive number
}