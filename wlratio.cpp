#include <iostream>
#include <cstdlib> 
using namespace std;

double winratio (double wins, double draws, double losses) {
	return  ( (wins + (draws/2) ) / ( (wins + draws/2) + (losses + draws/2) ) ) * 100.0;
}

double lossratio (double wins, double draws, double losses) {
	return  ( (losses + (draws/2) ) / ( (losses + draws/2) + (wins + draws/2) ) ) * 100.0;
}

int main(int argc, char* argv[]) {
	if( argc == 3 ) {
		cout << "Win Ratio: " << winratio(atof(argv[1]), 0.0, atof(argv[2])) << "%" << endl
				<< "Loss Ratio: " << lossratio(atof(argv[1]), 0.0, atof(argv[2])) << "%";
		return 0;
	}
	else if( argc == 4 ) {
		cout << "Win Ratio: " << winratio(atof(argv[1]), atof(argv[2]), atof(argv[3])) << "%" << endl
				<< "Loss Ratio: " << lossratio(atof(argv[1]), atof(argv[2]), atof(argv[3])) << "%";
		return 0;
	} else {
		cout << "Usage: " << argv[0] << " <wins> <draws> <losses>" << endl
				<< "\tdraws are optional\n";
	}
	return 0;
}


