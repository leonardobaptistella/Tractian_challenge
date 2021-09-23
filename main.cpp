#include <iostream>
#include <string>
#include <iomanip> 
#include <sstream> 
#include <vector>
#include <fstream> 
using namespace std; 


int main() {
	
	// define variables
	string X, Y, Z  ;
	vector<float>X_V;
	vector<float>Y_V;
	vector<float>Z_V;
	
	//input filename
	string file;
	file = "01-03-S23.txt";
	
	//parse file name
	std::istringstream split(file);
	string inicio, duracao, id_sensor; 
	getline(split, inicio, '-');
	getline(split, duracao, '-');
    getline(split, id_sensor, '.');

	//number of lines
	int i = 0;

	// File to Array
	ifstream coeff(file); //opening the file.
	if (coeff.is_open()) //if the file is open
	{
		//ignore first line
		string line;
		getline(coeff, line);

		while (!coeff.eof()) 
		{
			getline(coeff, X, ',');
			X_V.push_back(stof(X));
			getline(coeff, Y, ',');
			Y_V.push_back(stof(Y));
			getline(coeff, Z, '\n'); 
			Z_V.push_back(stof(Z));
			
			i += 1; 
		}
		coeff.close(); //closing the file
		//cout << "Number of entries: " << i-1 << endl;
	}
	else cout << "Unable to open file"; 
	
	/*for(int j=0; j<=i-1;j++){
		cout << X_V[j];
		cout << "\t";
		cout << Y_V[j];
		cout << "\t";
		cout << Z_V[j];
		cout << "\n";
	}*/
	
	cout << inicio; 
	cout << "\n";
	cout << duracao;
	cout << "\n";
	cout << id_sensor;
	cout << "\n";	

	return 0;

}