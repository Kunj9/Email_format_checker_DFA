/*
Written by : Kunj Bhatt
*/
#include <iostream>;
#include <string>;

using namespace std;
void getinput(string& email){
	//string email;
	bool isfinal = false;
	int state = 1;
	bool statest = false;
	int len = email.size();
	//cout << "enter string";
	//cin >> state/*;*/
		
	for (int i = 0; i < email.size(); i++) {
		if (state == 1) {
			if (isalpha(email[i]) && islower(email[i])){
				state = 2;
				cout << "state is q:" << state << " " << email[i] << "\n";		
				continue;
				++i;
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state:q" << state << " " << email[i] << "\n";
			}

		}
		if (state == 2) {
			if ((isalpha((email[i])) && islower((email[i]))) || isdigit((email[i]))) {
				state = 2;
				cout << "state is:q" << state << " " << email[i] << "\n";
				continue;
				i++;
			}
			if ((email[i]) == '.') {
				state = 1;
				cout << "state is:q" << state << " " << email[i] << "\n";
				continue;
				++i;
			}
			if ((email[i]) == '@') {
				state = 3;
				cout << "state is:q" << state << " " << email[i] << "\n";
				i++;
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state: q" << state << " " << (email[i]) << "\n";
			}
		} 
		if (state == 3) {
			if (isalpha((email[i])) && islower((email[i]))) {
				state = 4;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
				i++;
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state:" << state << " " << (email[i]) << "\n";
			}
		}//checks for alpha and numbers
		if (state == 4) {
			if ((isalpha((email[i])) && islower((email[i]))) || isdigit((email[i]))) {
				state = 4;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
				continue;
				i++;  //added continue and put i++
			}
			else if ((email[i]) == '.') {
				state = 5;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
				i++; //chnages i++ & continue
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state:" << state << (email[i]);
			}
		}//dot state Q5
		if (state == 5) {			
			if ((email[i]) == 'c') {
				state = 6;
				cout << "state is: q" << state << " " << (email[i]) << "\n";
				i++;
			}
			else if (isalpha((email[i])) && islower((email[i]))) {
				state = 4;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state:" << state << " " << (email[i]) << "\n";
			}
		}//C state q6
		if (state == 6) {
			if ((email[i]) == 'o') {
				state = 7;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
				i++;
			}
			else if ((email[i]) == '.') {
				state = 5;
				cout << "state is:" << state << " " << (email[i]) << "\n";
			}
			else if (isalpha((email[i])) && islower((email[i])) || isdigit((email[i]))) {
				state = 4;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
			}
			else {
				state = 9;
				statest = true;
				cout << "state is trap state: q" << state << " " << (email[i]) << "\n";
			}
		}// o state q7
		if (state == 7) {
			if ((email[i]) == 'm') {
				state = 8;
				cout << "state is: q" << state << " " << (email[i]) << "\n";
				if (i == len - 1) {
					cout << "Final state: q"<< state <<" \n"<< "String is accepted: "<< " " << email <<"\n ";
				}
			}
			else if ((email[i]) == '.') {
				state = 5;
				cout << " state is: q" << state << " " << (email[i]) << "\n";
			}
			else if (isalpha((email[i])) && islower((email[i])) || isdigit((email[i]))){
				state = 4;
				cout << " state is: q" << state << " " << (email[i]) << "\n";
				continue;
			}
			else {
				state = 9;
				statest = true;
				cout << " state is trap state: q" << state << " " << (email[i]) << "\n";
			}
		}//final state m
		if (state == 8) {
			if ((email[i]) == 'm') {
				if (i == len - 1) {
					if (statest == true) {
						printf("String is rejected \n");
						break;
					}
					cout << "String is accepted:" << " " << email << "\n";
					break;
				}
				if (email[i + 1] == '.' && email[i + 2] == '.') {
					printf("String is rejected \n");
					break;
				}
				if (email[i + 1] == '.' && email[i + 2] == 'c'&& email[i + 3] == 'o'&& email[i + 4] == 'm') {
					cout << "String is accepted:" << " " << email << "\n";
					break;
				}
				if ((isalpha((email[i])) && islower((email[i]))) || isdigit((email[i]))) {
					state = 4;
					i++;
					cout << "state is:q" << state << " " << (email[i]) << "\n";
				}				
			}
			if (isfinal) {
				printf("String is rejected \n");
			}
			if ((isalpha((email[i])) && islower((email[i]))) || isdigit((email[i]))) {
				state = 4;
				i++;
				cout << "state is:q" << state << " " << (email[i]) << "\n";
				continue;
			}
		}
		//trap state
		if (state == 9) {
			statest = true;
			cout << "state is:q" << state << " " << (email[i]) << "\n";
			printf("String is rejected \n");
			i++;
			continue;
		}
	}
	if (state != 8) {
		printf("String is rejected \n");
	}	
}

int main(){
	
	char scanenr;
	string input;

	cout<<"Project 1 for CS 341 \n"<< "Section number : 005 \n"<< "Semester : Fall 2022\n"<<
"Written by : Kunj Bhatt, kb556\n"<<"Instructor : Marvin Nakayama, marvin@njit.edu\n";


	cout << "Do you want to enter a string? (y/n) (only lowercase please): " << endl;
	cin >> scanenr;

	if (scanenr == 'n' ) {
		exit(1);
	}

	else if (scanenr == 'y') {

		cout << "Enter a string" << endl;
		cin >> input;
		getinput(input);

		while (scanenr == 'y') {
			if (scanenr == 'n' ) {
				exit(1);
			}

			cout << "Do you want to enter a string? (y/n) (only lowercase please): " << endl;
			cin >> scanenr;
			if (scanenr == 'n') {
				exit(1);
			}

			cout << "Enter a string" << endl;
			cin >> input;
			
			getinput(input);

			
		}
	}
}
