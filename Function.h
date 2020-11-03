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
  char ch = '\0',match[20];
  for(int i = 0;i >= 0;){
    ch = getch();
    if(ch != 8 && ch != 13){
      cout << "*";
      match[i] = ch;
      i++;
    }else if(ch == 8){ // if backspace is presssed
      if(i > 0){
        cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
        i--;
      }
    }else if(ch == 13){
      match[i] = '\0'; // if enter is pressed, last character in match[] becomes null
      break;          // for end of string
    }else{
      break;
    }
  }
  return match;
}