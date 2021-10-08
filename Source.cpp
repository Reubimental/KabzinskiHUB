#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include <vector>
#include <string>

using std::sort;
using std::cout;
using std::cin;
using std::vector;
using std::string;

// Function declarations
int statDice(int faces);
vector<int> bestXofN(int x, int n, int faces);
int sumOfDice(vector<int> dice);

int main() {
	// Adding a very important comment

	srand(time(NULL));

	vector<int> stats = {};
	
	for (int i = 0; i < 6; i++) {
		int value = sumOfDice(bestXofN(3, 4, 6));
		stats.push_back(value);
		cout << "Got value: " << value << '\n';
	}
	
	string statIn = "";

	cout << "Enter a stat: \n";

	cin >> statIn;

	if (statIn == "str") {
		cout << "You chose strength!\n";
	}
	else {
		cout << "You chose something else\n";
	}
	
}

/* 
	Returns an intiger between 1 and the number of faces (inclusive)
*/
int cunt() {
	return 69;
}
int statDice(int faces) {
	int value = rand() % faces + 1;

	return value;
}

/*  
	Rolls 'n' dice and returns the top 'x' values on 'faces' sided die.
	Input:
		int x: how many dice to return. Takes the top 'x'
		int n: how many dice to roll.
		int faces: number of faces on all dice.
	Output:
		vector of integers containing the dice values.
*/
vector<int> bestXofN(int x, int n, int faces) {
	
	vector<int> dice = {};

	for (int die = 0; die < n; die++) {
		dice.push_back(statDice(faces));
	}

	sort(dice.begin(), dice.end());

	vector<int> bestXdice(dice.cend()-x, dice.cend());

	return bestXdice;
	 
}

/*
	Adds together all the values of all given dice.
*/
int sumOfDice(vector<int> dice) {
	int sum = 0;

	for (int i = 0; i < dice.size(); i++) {
		sum += dice[i];
	}

	return sum;
}