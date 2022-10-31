#include<iostream>
#include<string>
#include<fstream>
#include <cstring>



using namespace std;
const int koko = 25;
void basic();
void inkrement2(char* argv[], int arc);
void inkrement3(char* argv[], int arc);



int main(int arc, char* argv[]) {

	cout << endl;
	cout << endl;


	if (arc == 1) {

		basic();
	}


	if (arc == 3) {

		inkrement2(argv, arc);
	}

	if (arc == 4) {

		inkrement3(argv, arc);

	}


}



void basic() {


	char search_string[koko];

	char name[koko];
	char tulos[koko];
	

	cout << "Give a string from which to search for: ";
	cin.getline(name, koko);



	int terve = strlen(name);
	name[terve + 1] = '\0';



	cout << "Give a search string: ";
	cin.getline(search_string, koko);
	cout << endl;

	int terve2 = strlen(search_string);
	search_string[terve2 + 1] = '\0';


	tulos[0] = '\0';

	int x = 0;
	int laskuri = 0;
	int z = 0;
	int pos_counter = 0;

	for (int i = 0; i < koko; i++) {
		name[i];
		search_string[z];

		if (name[i] == search_string[z]) {

			tulos[x] = name[i];

			laskuri++;

			if (z == terve2 - 1) {
				break;
			}
			x++;
			z++;
		}
		else {
			tulos[0] = '\0';

			x = 0;
			laskuri = 0;
			z = 0;
			pos_counter++;
		}

	}

	tulos[terve2] = '\0';

	cout << endl << endl;

	if (laskuri > 0) {
		cout << '"' << search_string << '"' << " Found in " << '"' << name << '"' << " in position " << pos_counter;
	}

	else if (laskuri == 0) {
		cout << '"' << search_string << '"' << " NOT found in " << '"' << name << '"';
	}
	cout << endl << endl;


}


void inkrement2(char* argv[], int arc) {

	string line;
	string word;
	fstream file;

	word = argv[1];


	file.open(argv[2], ios::in);

	while (getline(file, line)) {

		size_t pos = line.find(word);

		if (pos != string::npos)
			cout << line << endl;
	}

	cout << endl << endl;

}


void inkrement3(char* argv[], int arc) {


	fstream file;
	string word;
	int line_counter = 1;
	int occur_counter = 0;
	string compare;
	string line;

	compare = argv[1];

	string olo = "-olo";
	string ol = "-ol";
	string oo = "-oo";

	

	word = argv[2];


	file.open(argv[3], ios::in);

	

	

	while (getline(file, line)) {
		line_counter++;
		size_t pos = line.find(word);
		
		if (compare == olo || compare == ol) {

			if (pos != string::npos) {
				cout << line_counter << ": \t" << line << endl;
				occur_counter++;
			}
		}

		if (compare == oo) {


			if (pos != string::npos) {
				cout << line << endl;
				occur_counter++;
			}


		}
	
	}

	if (compare == olo || compare == oo) {

		cout << endl << endl;
		cout << "Occurences of lines containing \"" << word << "\": " << occur_counter;
	
	}

	cout << endl << endl;

}

