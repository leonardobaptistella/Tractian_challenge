#include <iostream>
#include <string>
#include <iomanip> 
#include <sstream> //Parse the file
#include <vector>
#include <fstream> //Read and Write Files
using namespace std; 


vector<float> import_data(string file){
    // define variables
	string X, Y, Z  ; //variables from file are here
	vector<float>X_V;
	vector<float>Y_V;
	vector<float>Z_V;
	    
	//number of lines
	int i = 0;

	ifstream coeff(file); //opening the file.
	if (coeff.is_open()) //if the file is open
	{
		//ignore first line
		string line;
		getline(coeff, line);

		while (!coeff.eof()) //while the end of file is NOT reached
		{
			getline(coeff, X, ',');
			X_V.push_back(stof(X));
			getline(coeff, Y, ',');
			Y_V.push_back(stof(Y));
			getline(coeff, Z, '\n'); //new line after Z
			Z_V.push_back(stof(Z));
			
			i += 1; //increment number of lines
		}
		coeff.close(); //closing the file
		cout << "Number of entries: " << i-1 << endl;
	}
	else cout << "Unable to open file"; //if the file is not open output
	
	/*for(int j=0; j<=i-1;j++){
		cout << X_V[j];
		cout << "\t";
		cout << Y_V[j];
		cout << "\t";
		cout << Z_V[j];
		cout << "\n";
	} */
   
    return X_V , Y_V, Z_V;
}

int main() {
    string file_name = "sensor_data.txt";
	import_data(file_name);
	return 0;

}