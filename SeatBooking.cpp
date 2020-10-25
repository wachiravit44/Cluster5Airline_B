#include <bits/stdc++.h>
using namespace std;

// to check whether all sits are occupied or not
int allOccupied(char arr[10][11]){ 
	int count=0;
	for(int i=0;i<10;i++){
		for(int j=1;j<11;j++)
		if(arr[i][j]=='X')
			count++;
	}

	if(count==110)
		return 1;
	return 0;
}

//to display the sits
void display(char arr[10][11]){ 
	for(int i=0;i<10;i++){
		for(int j=0;j<11;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	return;
}

//take user data
string getData(){ 
	string p;
	cout<<"enter valid seat no to check(like 1B) or N to end: ";
	cin>>p;
	return p;
}

//update sit status
void update(char arr[10][11],int row,int col){ 
	cout<<"congrats, your seat is valid. Reserved for you\n";
	cout<<"updated seat status..........\n";
	arr[row][col]='X';
}

//checking whether user request for 
//his sit no can be processed or not
int check(char arr[10][11],string s){ 
//if user input is not in the range 1A to 7D
if(s[0]>'9' || s[0]<'1' || s[1]>'J' || s[1]<'A'){ 
cout<<"invalid seat no\n"; //invalid sit no
return 0;
}

int row=-1,col=-1;
//find the row no of the user sit
for(int i=0;i<10;i++){
if(arr[i][0]==s[0])
row=i;
}
 //find the column no of user sit
for(int j=0;j<11;j++){
if(arr[row][j]==s[1])
col=j;
}

//check whether sit is already occupied or not.
if(col==-1){
cout<<"Seat is already occupied\n";
return 0;
}
else{
//if it's a valid sit & not occupied, 
//process the requested & update the sit as occupied 
update(arr,row,col);   
}
return 1;
} 


void airline(char arr[10][11]){
	// user can stop process by pressing 'N'
	cout<<"enter N if you are done!\n"; 
	string s;
	// continue if not interrepted by user or 
	//there is valid sit in unoccupied state
	while(true){ 
		s=getData(); //get user input
		//if user input is to stop the process
		if(s[0]=='N') 
			break; // break

		//process the request & check according to
		if(check(arr,s)) 
			display(arr);

		if(allOccupied(arr)){ //if all sits are occupied
			cout<<"sorry, no more seats left!!!!!!!!!!1..."<<endl;
			break; //break
		}
	}
	cout<<"Thanks, that's all"<<endl; //end of program
}

int main()
{
	//2-D array for storing sit number
	char arr[10][11]; 
	for(int i=0;i<10;i++){
		//forst column is row number
		arr[i][0]=i+1+'0';
		for(int j=1;j<11;j++){
			//to represent sit number A,B,C,D respectively
			arr[i][j]='A'+j-1; 
		}
	}
	
	cout<<"initial seat arrangements........\n";
	display(arr);

	airline(arr); //airline function

	return 0;
}
