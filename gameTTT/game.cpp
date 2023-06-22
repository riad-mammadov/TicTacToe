#include <iostream>
#include <string>


using namespace std;

char space[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char token = 'x';
bool tie = false;
int row;
int column;
string p1 = "";
string p2 = "";

void gridFunction() {


	cout << "    |    |    \n";
	cout << " " << space[0][0] << "  | " << space[0][1] << "  | " << space[0][2] << " \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << " " << space[1][0] << "  | " << space[1][1] << "  | " << space[1][2] << " \n";
	cout << "____|____|____\n";
	cout << "    |    |    \n";
	cout << " " << space[2][0] << "  | " << space[2][1] << "  | " << space[2][2] << " \n";
	cout << "    |    |    \n";


}

void check_value() {

	int digit;

	if (token == 'x')
	{
		cout << p1 << " enter X \n";
		cin >> digit;

	}

	if (token == '0')
	{
		cout << p2 << " Enter 0 \n";
		cin >> digit;
	}

	if (digit == 1) {
		row = 0;
		column = 0;

	}
	if (digit == 2) {
		row = 0;
		column = 1;

	}
	if (digit == 3) {
		row = 0;
		column = 2;

	}
	if (digit == 4) {
		row = 1;
		column = 0;

	}
	if (digit == 5) {
		row = 1;
		column = 1;

	}
	if (digit == 6) {
		row = 1;
		column = 2;

	}
	if (digit == 7) {
		row = 2;
		column = 0;

	}
	if (digit == 8) {
		row = 2;
		column = 1;

	}
	if (digit == 9) {
		row = 2;
		column = 2;

	}
	else if (digit < 1 || digit > 9) {
		cout << "Invalid value within the grid";
	}

	if (token == 'x' && space[row][column] != 'x' && space[row][column] != '0') {
		space[row][column] = 'x';
		token = '0';
	}

	else if (token == '0' && space[row][column] != 'x' && space[row][column] != '0') {
		space[row][column] = '0';
		token = 'x';
	}
	else {
		cout << "No empty space!" << '\n';
		check_value();
	}
	
}

bool gameCondition() {

	for (int i = 0; i < 3; i++) {

		if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
			return true;
		}

		if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
			return true;
		}

		for (int j = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)

				if (space[i][j] != 'x' && space[i][j] != '0') {
					return false;
				}
		}
	}
	
	
}



int main() {

	cout << "Enter name of first player : " << '\n';
	getline(cin, p1);
	cout << "Enter name of second player : " << '\n';
	getline(cin, p2);
	cout << p1 << " is player one (X) \n";
	cout << p2 << " is player two (O) \n";

	while (!gameCondition())
	{
		gridFunction();
		check_value();
		gameCondition();

	}
	if (token == 'x' && tie == false)
	{

		cout << p2 << " Wins the match!" << '\n';
	}

	if (token == '0' && tie == false)
	{
		cout << p1 << " Wins the match!" << '\n';
	}

	else {
		cout << "Game is a draw" << '\n';
	}

}