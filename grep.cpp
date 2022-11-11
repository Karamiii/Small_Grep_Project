#include<iostream>
#include<string>
#include<fstream>
#include<cstring>


using namespace std;

// making a public size variable
const int koko = 25;

//functions to different levels
void basic();
void inkrement2(char* argv[], int arc);
void inkrement3(char* argv[], int arc);


 //Reading users command line arguments
int main(int arc, char* argv[]) {

	cout << endl;
	cout << endl;

// The amount of arguments determines the function that will be used

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


/*basic funtion asks from the user a string and a search string
It will then compare the search string to the original string and try to find
occurances from the strings. The position of the simalarities is allso listed*/

void basic() {

	// creating arrays to store user strings and the result
	char search_string[koko];
	char name[koko];
	char tulos[koko];
	

	cout << "Give a string from which to search for: ";
	cin.getline(name, koko);


	//measuring length of the array and adding a NULL at the end
	int terve = strlen(name);
	name[terve + 1] = '\0';



	cout << "Give a search string: ";
	cin.getline(search_string, koko);
	cout << endl;

	//measuring length of the array and adding a NULL at the end
	int terve2 = strlen(search_string);
	search_string[terve2 + 1] = '\0';

	// Setting up preparations for the searching  

	tulos[0] = '\0';

	int x = 0;
	int laskuri = 0;
	int z = 0;
	int pos_counter = 0;

	
	/* Finding the occurances in the strings. This i created my self and works pretty much the same way
	as the public "string::find function. I use the public funtion later on, but i wanted to create my own implementation first"	
	*/
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

	// Presenting the results
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

// inkrement2 function finds sentences containing a word given by the user from a given file

void inkrement2(char* argv[], int arc) {

	string line;
	string word;
	fstream file;

	word = argv[1];

	//Open the user given file
	file.open(argv[2], ios::in);
	// public string::find function
	while (getline(file, line)) {

		size_t pos = line.find(word);

		if (pos != string::npos)
			cout << line << endl;
	}

	cout << endl << endl;

}

/* inkrement3 function does the same as inkrement2 but has more options for parameters.
For example "-olo" adds line numbers of the sencentces containing the given word.*/
void inkrement3(char* argv[], int arc) {


	fstream file;
	string word;
	int line_counter = 1;
	int occur_counter = 0;
	string compare;
	string line;
	compare = argv[1];

	//adding the parameters
	
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

