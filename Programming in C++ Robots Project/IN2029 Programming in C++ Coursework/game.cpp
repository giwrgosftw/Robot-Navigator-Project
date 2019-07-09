#include "game.h"
#include <algorithm>


game::game() {	//declare the game object

	//game_map.emplace("George", robot("George"));
	//robotsName10_list.push_back("George");

	//game_map.emplace("Nick", robot("Nick"));
	//robotsName10_list.push_back("Nick");

	//game_map.emplace("Theo", robot("Theo"));
	//robotsName10_list.push_back("Theo");


	maxDist = 0;
	furthestRobot = "no one";
}


//returns TRUE/FALSE if the name of the robot is/isn't in the list
bool game::findRobotName10(const string &name) {
	bool found = (find(robotsName10_list.begin(), robotsName10_list.end(), name) != robotsName10_list.end());
	return found;
}


void game::move(const string &name, int dir) {

	//if there is no robot of that name, create it at the origin and then moved.
	if (game_map.count(name) == 0) {
		game_map.emplace(name, robot(name));
	}

	//moving the robot to the map in a specified direction(0 = north, 1 = east, 2 = south, 3 = west).
	if (dir == 0) {
		game_map.at(name).move_north();
	}
	else if (dir == 1) {
		game_map.at(name).move_east();
	}
	else if (dir == 2) {
		game_map.at(name).move_south();
	}
	else if (dir == 3) {
		game_map.at(name).move_west();
	}
	else {
		cout << "One of the directions which you gave for the robot <" << game_map.at(name).get_name() << "> is invalid (valid for 2D environement directions: 0,1,2,3)" << endl <<endl;
	}


	//if the total distance of the robot is <=10, add the robot's name in the list
	if (game_map.at(name).travelled() <= 10) {
		if (findRobotName10(name) == false) {
			robotsName10_list.push_back(name);
		}
	}
	else {	//deletes the robot's name from the list
		if (findRobotName10(name) == true) {
			robotsName10_list.remove(name);
		}
	 }

	//finds the furthest robot, as its distance is the longest
	if (distance(game_map.at(name)) > maxDist) {
		maxDist = distance(game_map.at(name));
		furthestRobot = name;
	}
}



//if the robot made/did't make less steps than the other one,return TRUE/FALSE
bool compare_travelled(const robot& x, const robot& y) { return x.travelled() < y.travelled(); }

//compares two robots, if the robot's name is bigger than the other's one,return TRUE/FALSE
bool compare_name(const robot& x, const robot& y) { return x.get_name() > y.get_name(); }



//returns a collection of all the robots in the system
vector<robot>  game::robots_by_travelled() const {

	vector<robot> tmpRobots_vector;	//create an temporary vector

	for (auto elem : game_map) {	//copy all the robots from the map and paste them to the vector
		tmpRobots_vector.push_back(elem.second);
	}

	//iterating through the map and sorts by repeatedly swapping the adjacent elements if they are in wrong order.
	for (std::vector<robot>::iterator it1 = tmpRobots_vector.begin(); it1 != tmpRobots_vector.end(); ++it1) {
		for (std::vector<robot>::iterator it2 = tmpRobots_vector.begin(); it2 != tmpRobots_vector.end(); ++it2){
			sort(tmpRobots_vector.begin(), tmpRobots_vector.end(), compare_name);	//sort in alphabetically-escending order.
			sort(tmpRobots_vector.begin(), tmpRobots_vector.end(), compare_travelled);	//sort in increasing order.
		}
	}

    return tmpRobots_vector;
}


//void game::print_vector(vector<robot> robots_vector) {
//	cout << endl;
//	for (std::vector<robot>::iterator it = robots_vector.begin(); it != robots_vector.end(); ++it) {
//		cout << "Total distance travelled by " << (*it).name() << " is " << (*it).travelled() << '\n';
//	}
//	cout << endl;
//}