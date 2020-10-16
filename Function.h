#include <iostream>
#include <conio.h>
using namespace std;

void readfile(string filename){
	ifstream myfile;
        string filein,name,tel,id,pass,number_th;
		filename = filename+".txt";
        myfile.open(filename,std::ios::out);//read file
        while (getline(myfile,filein)){
			cout << filein << endl;
		}
		myfile.close();
}

string Hide_password(){
    	char ch;
        string password;				
        ch = _getch();
		while(ch != 13){//character 13 is enter
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}	
        return password;
}