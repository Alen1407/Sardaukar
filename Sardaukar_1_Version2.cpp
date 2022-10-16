#include <iostream>
#include <fstream>
#include <cstring>
#include <elf.h>
using namespace std;

int platform_type(fstream &file){
	char ch;
	file.seekg(4, ios::beg);
	file >> ch;

	return (int)ch;
}

void endianness(fstream &file){
	char ch;
	file.seekg(5, ios::beg);
	file >> ch;
	if((int)ch == 1)
		cout << "Little endian\n";
	else
		cout << "Big endian\n";

	return;
}

void entry_point(fstream &file){
	char ch;
	int n;
	int seek_point = 18;
	if(platform_type(file) == 1)
		n = 4;	
	else
		n = 8;
	
	for(int i = 0; i < n; i++){
		file.seekg(seek_point+i, ios::beg);
		file >> ch;
		cout << hex << (int)ch;
	}

	cout << endl;
}

int number_of_symbols(fstream &file){
	int res = 0;
	char ch;
	file >> ch;
	while(file){
		res++;
		file >> ch;
	}

	return res;
}

int main(){
	fstream file;
	file.open("1_1.o", ios::in);
	char ch;
	if(!file){
		cout << "No such file";
	}

	if(platform_type(file) == 1)
		cout << "Platform: 32 bit\n";
	else
		cout << "Platform: 64 bit\n";
	endianness(file);
	entry_point(file);
	cout << number_of_symbols(file);

	file.close();

		
	return 0;
}
