#include <iostream>
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
