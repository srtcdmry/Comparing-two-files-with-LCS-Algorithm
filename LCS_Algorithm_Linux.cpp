#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
#include <clocale>
#include <unistd.h>
#define Turkuaz "\x1B[36m"
//#include <bits/stdc++.h>

#define MAX 9999999
using namespace std;

// g++ name.cpp -std=c++11
//multiple files
// >> ./a.out *.txt
// or two files
// >> ./a.out file.txt file2.txt

char* arrTranslation = new char[MAX];
vector<int>indis,indis2;
vector<string>arr_LCS;
string arr_text[MAX];
string arr_text1[MAX];

char controller(char c_text) {
	//cout << c_text;
	auto c_sets = "/*-.,<>)({}[]+-:;%^&~!_\"?#\\=";  
	int i = 0;

	for (i = 0; i <= 27; i++) {
		if (c_text == c_sets[i]) {
			c_text = ' ';
		}
	}
	c_text = tolower(c_text);
	return c_text;
}

void fileConversion(string file,string newfile) {
	ifstream file1(file);
	ofstream n_file1(newfile);
	int hh = 0;
	if (file1.is_open()) {
		while (file1.get(arrTranslation[hh])) {

			arrTranslation[hh] = controller(arrTranslation[hh]);
				
				n_file1 << arrTranslation[hh];
				hh++;
		}
		cout << "\n\n\n";
		file1.close();
		n_file1.close();
	}
	
}

int readConversionFile(string r_newFile) {
	string array1, t, q;
	int ll = 1;
	ifstream file2;
	file2.open(r_newFile.c_str());
	while (file2 >> array1) {
		arr_text[ll] = array1;
		arr_text[ll] = arr_text[ll];
		ll++;
	}
	file2.close();
	
	return ll-1;
}

int readConversionFile2(string r_newFile2) {
	string array2, t, q;
	int kk = 1;
	ifstream file3;
	file3.open(r_newFile2.c_str());
	while (file3 >> array2) {
		arr_text1[kk] = array2;
		kk++;
	}
	file3.close();
	return kk-1;
}

void LCS_Algorithm(int length1, int length2) {
	int ii = length1 ;
	int  dd = length2;
	int i = length1, d = length2;

	vector<vector<char>> b(i + 1, vector<char>(d + 1, 0));
	vector<vector<char>> c(i + 1, vector<char>(d + 1, 0));
	
	for (int j = 0; j <= i; j++) {
		for (int k = 0; k <= d; k++) {
			if (j == 0 || k == 0) {
				c[j][k] = 0;
				b[j][k] = '/';
			}
			else if (arr_text[j] == arr_text1[k]) {
				c[j][k] = c[j - 1][k - 1] + 1;
				b[j][k] = '@';
			}
			else if (c[j - 1][k] >= c[j][k - 1]) {
				c[j][k] = c[j - 1][k];
				b[j][k] = '#';
			}
			else {
				c[j][k] = c[j][k - 1];
				b[j][k] = '!';
			}
		}
		//cout << endl;
	}
	int y = 0, u = 0;
	int l = 0;
	//cout << "LCS Printed :   ";
	while (i != 0 || d != 0) {
		if (i == 0 || d == 0) {
		//	//for (int u = arr_LCS.size()-1 ; u > 0; u--) {

		//		//cout << arr_LCS[u] << "---";
		////	}
		//	//cout << endl;
		//	//cout << "LCS Length :  " << arr_LCS.size()-1 ;
		//	//cout << "\n\n";
		//	
			return;
		}
		if (b[i][d] == '@')
		{	//diagonal arrow, MATCH
			indis.push_back(i);
			indis2.push_back(d);
			arr_LCS.push_back(arr_text[i]);
			//cout << arr_text[i]<<" " ;
			l++;
			i--;
			d--;
		}
		else if (b[i][d] == '#')
		{	//up arrow
			i--;
		}
		else {
			d--;
		}

	}
	//for (int u = l - 1; u >= 0; u--) {
	//	cout << red << arr_LCS[u] << "---";
	//}

	//cout  <<"\n\nLCS Length :  " << arr_LCS.size()<<white ;

	//cout << white << endl ;
	//cout << green << "Indices of file 1: " << white;
	//for (int yy = indis.size() -1 ; yy > 0 ; yy--) {
	//	cout << indis[yy] << ",";
	//}
	//cout << endl;

	//cout << green << "Indices of file 2 : " <<white;
	//for (int xx = indis2.size() -1 ; xx > 0; xx--) {
	//	cout << indis2[xx] << ",";
	//}
	//	cout << "\n\n";

	//double similarity = 0.0;
	//similarity = arr_LCS.size() / (double(dd + ii) / 2) * 100;
	//cout << yellow<< "Similarity rate of files : " << similarity<<white;

}

void LCS_info(int i, int d) {
	int ii = i;
	int dd = d;



	cout << "LCS Printed :   ";

	for (int u = arr_LCS.size() - 1; u >= 0; u--) {
		cout << arr_LCS[u] <<  "--";
	}
	cout <<  "\n\nLCS Length :  " << arr_LCS.size() << "\n\n";
	double similarity = 0.0;
	similarity = arr_LCS.size() / (double(dd + ii) / 2) * 100;
	cout << "Similarity rate of files : % " << similarity <<  endl;
	cout << "\n*****************************************************\n\n" ;
	cout << "Total words of File 1 : " << i << endl;
	cout <<  "Total words of File 2 : " << d <<  endl;

	cout <<  endl;
	cout <<  "Indices of file 1: ";
	for (int yy = indis.size() - 1; yy >= 0; yy--) {
		cout << indis[yy] << ",";
	}
	cout << endl;

	cout <<  "Indices of file 2 : " ;
	for (int xx = indis2.size() - 1; xx >= 0; xx--) {
		cout << indis2[xx] << ",";
	}
	cout << "\n\n";

	cout <<  "*****************************************************\n\n" ;

	cout << "\n\n"; 
	arr_LCS.clear() ;
	indis.clear() ;
	indis2.clear() ;

}
int main(int argc, char **argv) {

	setlocale(LC_ALL, "tr_TR.utf8");

	if (argc < 2) {
	std::cerr << "Usage : process <filename> [filename...]\n";
	return EXIT_FAILURE ;
	}
	for (int z = 1 ; z< argc ; z++ ){
	std::ifstream infile(argv[z]) ;
	cout << argv[z] ;
	}
	for (int m=1 ; m<argc ; m++ ){
		for(int n = m; n<argc; n++){
			if (argv[m] == argv[n]){
				cout<<" ";
			}
			else{
			cout << "\n\n******************** Comparison of File : " << argv[m] << " and File : " << argv[n] << "********************" ;
			

			string newFile = "n_file.txt";
			string newFile2 = "n_file2.txt";
	//cout << Turkuaz << "********************** FILE 1 **********************\n\n";
			fileConversion(argv[m], newFile);
	//cout << "********************** FILE 2 **********************\n\n";

			fileConversion(argv[n], newFile2);
			int i;
			i = readConversionFile(newFile);
			int d;
			d = readConversionFile2(newFile2);
			LCS_Algorithm(i, d);
			LCS_info(i, d);
			sleep(4);
			}
		}
	}	

	return 0; 

}
