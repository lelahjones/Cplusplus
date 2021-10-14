// Lelah Jones-Olender

// Programming Project # 17 Using vectors to store lists from external files and checking input against them



# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <iterator>

using namespace std;

int main()
{
	ifstream inputFile;
	ifstream inputFile2;
	string inputName;
	vector<string> boyNames;
	vector<string> girlNames;

	//opening files
	inputFile.open("C:\\Users\\lelah\\OneDrive\\CIS 115 logic\\GirlNames.txt");
	inputFile2.open("C:\\Users\\lelah\\OneDrive\\CIS 115 logic\\BoyNames.txt");

	//entering names
	cout << "Please enter a name to check and see if it is one of the most popular: ";
	cin >> inputName;
	cout << endl;

	//putting files into vectors (string type)
	copy(istream_iterator<string>(inputFile),
		istream_iterator<string>(),
		back_inserter(girlNames));
	copy(istream_iterator<string>(inputFile2),
		istream_iterator<string>(),
		back_inserter(boyNames));

	//checking to see if names are in list
	if (find(boyNames.begin(), boyNames.end(), inputName) != boyNames.end())
		cout << inputName << " is among the most popular boy names.\n";
	else
		if (find(girlNames.begin(), girlNames.end(), inputName) != girlNames.end())
			cout << inputName << " is among the most popular girls names.\n";
		else
			cout << inputName << " is not in either the girl list or boy list of popular names.\n";

	//closing files
	inputFile.close();
	inputFile2.close();

	return 0;
}
