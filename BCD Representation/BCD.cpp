#include <iostream>
#include <ctype.h>

using namespace std;

int displayExitMenu();

enum Options {
	START = 1, CLOSE = 2
};

int main() {

	cout << "Please enter the BCD representation:" << endl;

	char representation[6];
	cin >> representation;

	if (!cin.good()) {
		cerr << "\aAn error occured whilst running the program:" << endl;
		cerr << "Please type in a correct BCD representation!" << endl;
		cerr << "Re-running the program..." << endl;

		main();


		return 0;
	}

	if (!isdigit(representation[0]) || !isdigit(representation[1]) || !isdigit(representation[2]) || !isdigit(representation[3])) {
		cerr << "\aAn error occured whilst running the program:" << endl;
		cerr << "Please type in a correct BCD representation!" << endl;
		cerr << "Re-running the program..." << endl;

		main();


		return 0;
	}

	int firstDigit = (int)representation[0] - 48;
	int secondDigit = (int)representation[1] - 48;
	int thirdDigit = (int)representation[2] - 48;
	int fourthDigit = (int)representation[3] - 48;

	int correspondingDig{ firstDigit * 8 + secondDigit * 4 + thirdDigit * 2 + fourthDigit };

	cout << "The corresponding digit is " << correspondingDig << endl;

	return displayExitMenu();
}

int displayExitMenu() {
	cout << "Would you like to exit the program or rerun the program?" << endl;
	cout << "\tRERUN - 1" << endl;
	cout << "\tEXIT - 2" << endl;

	int option{};
	cin >> option;

	switch (option) {

	case START:
		main();

		return 0;
		break;
	case CLOSE:
		return 0;
		break;
	default:
		cerr << "Invalid choice!" << endl;

		displayExitMenu();

		break;
	}
}