//  main.cpp


#include <iostream>
#include "game.h"
#include <vector>

using namespace std;

void runGameWithDefaultSettings() {

	game g;
	g.move("Bob", 0);
	g.move("Bob", 0);
	g.move("Bob", 0);

	g.move("Tom", 0);
	g.move("Tom", 0);

	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	cout << "Your Results : " << '\n';
	cout << "Number of robots close to the origin : " << g.num_close() << '\n';
	cout << "Name of Robot with max distance : " << g.furthest() << '\n';
	cout << "Max distance : " << g.max_distance() << '\n';
	cout << '\n';
	cout << "Expected Results : " << '\n';
	cout << "Number of robots close to the origin : 2 " << '\n';
	cout << "Name of Robot with max distance : Rob " << '\n';
	cout << "Max distance : 23 " << '\n';

}

void createRobot() {
	string robot_name;
	int move_direction;
	int steps_direction;
	game g;

	cout << "Enter a name for robot " << '\n';
	cin >> robot_name;

	cout << "Enter a number between 0 and 3 to move robot" << '\n';
	cout << "0(North) 1(East) 2(South) 3(East)" << '\n';
	cin >> move_direction;

	cout << "How many steps do you want to move in that direction ?" << '\n';
	cin >> steps_direction;

	for (int i = 0; i == steps_direction; ++i) {
		g.move(robot_name, move_direction);
	}
}

void editRobot(game g, string robot_name) {
	int move_direction;
	int steps_direction;



	cout << "Enter a number between 0 and 3 to move robot" << '\n';
	cout << "0(North) 1(East) 2(South) 3(East)" << '\n';
	cin >> move_direction;

	cout << "How many steps do you want to move in that direction ?" << '\n';
	cin >> steps_direction;

	for (int i = 0; i == steps_direction; ++i) {
		g.move(robot_name, move_direction);
	}
}

void runGameWithCustomSettings() {
	string robot_name;
	int move_direction;
	int steps_direction;
	game g;
	int user_pref = 0;

	cout << "Enter a name for robot " << '\n';
	cin >> robot_name;

	cout << "Enter a number between 0 and 3 to move robot" << '\n';
	cout << "0(North) 1(East) 2(South) 3(East)" << '\n';
	cin >> move_direction;

	cout << "How many steps do you want to move in that direction ?" << '\n';
	cin >> steps_direction;

	for (int i = 0; i < steps_direction; ++i) {
		g.move(robot_name, move_direction);
	}

	while (user_pref != 3) {
		cout << "Select an option below " << '\n';
		cout << '\n';
		cout << "1. Move robot again " << '\n';
		cout << "2. Create a new robot " << '\n';
		cout << "3. Output Results" << '\n';
		cin >> user_pref;

		switch (user_pref) {
		case 1:
			editRobot(g, robot_name);
			break;
		case 2:
			createRobot();
			break;
		default:
			break;
		}
	}


	cout << "Number of robots close to the origin : " << g.num_close() << '\n';
	cout << "Name of Robot with max distance : " << g.furthest() << '\n';
	cout << "Max distance : " << g.max_distance() << '\n';

}

void runGameWithExtraSettings() {
	game g;
	g.move("Bob", 0);
	g.move("Bob", 0);
	g.move("Bob", 0);

	g.move("Tom", 0);
	g.move("Tom", 0);

	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 0);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);
	g.move("Rob", 1);

	cout << "Your Results : " << '\n';
	cout << "Number of robots close to the origin : " << g.num_close() << '\n';
	cout << "Name of Robot with max distance : " << g.furthest() << '\n';
	cout << "Max distance  : " << g.max_distance() << '\n';


	vector<robot>::iterator iter;
	vector<robot> r1 = g.robots_by_travelled();
	cout << '\n';
	cout << "Info about robots on the map  : " << '\n';
	for (iter = r1.begin(); iter != r1.end(); ++iter) {
		cout << "-> " << "Total distance travelled by " << (*iter).name() << " is " << (*iter).travelled() << '\n';
	}
	cout << '\n';
	cout << "Expected Results : " << '\n';
	cout << "Number of robots close to the origin : 2 " << '\n';
	cout << "Name of Robot with max distance : Rob " << '\n';
	cout << "Max distance : 23 " << '\n';
	cout << "Info about robots on the map : " << '\n';
	cout << "-> Total distance travelled by Tom is 2 " << '\n';
	cout << "-> Total distance travelled by Bob is 3 " << '\n';
	cout << "-> Total distance travelled by Rob is 23 " << '\n';

}



int main(int argc, const char * argv[]) {


	int user_pref = 0;

	cout << "Select an option and press enter to continue" << '\n';
	cout << '\n';
	cout << "1. Press 1 to test game with default settings" << '\n';
	cout << "2. Press 2 to test game with custom settings" << '\n';
	cout << "3. Press 3 to test game with default settings + extra info" << '\n' << endl;
	cin >> user_pref;
	cout << '\n';

	switch (user_pref) {
	case 1:
		runGameWithDefaultSettings();
		break;
	case 2:
		runGameWithCustomSettings();
		break;
	case 3:
		runGameWithExtraSettings();
		break;
	default:
		break;
	}

	system("pause");

	return 0;

}