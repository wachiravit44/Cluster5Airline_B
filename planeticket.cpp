/************************************************************************/
/* Program Assignment: Planeticket										*/
/* Team : B																*/
/* Date : 16/10/2653     												*/
/************************************************************************/
#include "All_include_in_main.h"
class Seat{
	private:
		int count;
		string p;
		string seat;
	public:
		Seat(){
			count = 0;;
			p = "";

		}
		int allOccupied(char arr[7][5]){ 
			int count=0;
			for(int i=0;i<7;i++){
				for(int j=1;j<5;j++)
				if(arr[i][j]=='X')
					count++;
			}if(count==28)
				return 1;
			return 0;
		}

//to display the sits
	void display(char arr[7][5]){ 
		for(int i=0;i<7;i++){
			for(int j=0;j<5;j++){
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
		seat = p;
		return p;
	}
	string getSeat(){ 
		return seat;
	}
	//update sit status
	void update(char arr[7][5],int row,int col){ 
		cout<<"congrats, your seat is valid. Reserved for you\n";
		cout<<"updated seat status..........\n";
		arr[row][col]='X';
	}

//checking whether user request for 
//his sit no can be processed or not
	int check(char arr[7][5],string s){ 
	//if user input is not in the range 1A to 7D
	if(s[0]>'7' || s[0]<'1' || s[1]>'D' || s[1]<'A'){ 
		cout<<"invalid seat no\n"; //invalid sit no
		return 0;
	}
		int row=-1,col=-1;
		//find the row no of the user sit
		for(int i=0;i<7;i++){
			if(arr[i][0]==s[0])
				row=i;
		}
	//find the column no of user sit
		for(int j=0;j<5;j++){
			if(arr[row][j]==s[1])
				col=j;
		}
		//check whether sit is already occupied or not.
		if(col==-1){
			cout<<"Seat is already occupied\n";
			return 0;
		}else{
		//if it's a valid sit & not occupied, 
		//process the requested & update the sit as occupied 
			update(arr,row,col);   
		}
			return 1;
	} 
	void airline(char arr[7][5]){
		// user can stop process by pressing 'N'
		cout<<"enter N if you are done!\n"; 
		string s;
		// continue if not interrepted by user or 
		//there is valid sit in unoccupied state
		while(true){ 
			s = getData(); //get user input
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
};

 class member{
            public:
				//test
                string Name,Tel,Id,Pass,Number_th;
                member *link;
                member *plink;
                member(string n,string tel,string id,string pass,string n_th){
                    Name = n;
                    Tel = tel;
                    Id = id;
                    Pass = pass;
                    Number_th = n_th;
                    link = NULL;
                    plink = NULL;
                } 
        };
class memberList{
    private:
        member *head;
        member *tail;
        int count;
    public:
        memberList(){
            head = NULL;
            tail = NULL;
            count = 0;
            read_data();
        }
        void login(){

        }
        void add_member(string n,string tel,string id,string pass,string n_th){
            member *Newmember = new member(n,tel,id,pass,n_th);
                if(head == NULL){
                    head = Newmember;
                    tail = Newmember;
                }else{
                    tail->link = Newmember;	
                    Newmember->plink = tail;
                    tail = Newmember;
                }
            count++;
        }
        void read_data(){
            ifstream myfile;
            string filein,name,tel,id,pass,number_th;
            myfile.open("Member.txt",std::ios::out);//read file
            while (getline(myfile,filein)){
                name = filein.substr(0,filein.find(','));
					 filein.erase(0,filein.find(',')+1);
				number_th = filein.substr(0,filein.find(','));
					 filein.erase(0,filein.find(',')+1);
				tel = filein.substr(0,filein.find(','));
				     filein.erase(0,filein.find(',')+1);
                id = filein.substr(0,filein.find(','));
                    filein.erase(0,filein.find(',')+1);
                pass = filein;
    	        add_member(name,tel,id,pass,number_th);
        	}
            myfile.close();
        }
        bool check(string id,string pass){
            for(member *temp = head;temp != NULL;temp=temp->link){
                if(id == temp->Id && pass == temp->Pass){
                    return true;
                }
            }
            return false;
        }
        bool check_NumberTH(string num){
            for(member *temp = head;temp != NULL;temp=temp->link){
                if(num == temp->Number_th){
                    //cout << "find!!!!!\n";
                    return true;
                }
            }
            return false;
        }
        bool Checkpass(string username,string pass){
			member *temp = head;
			while(temp !=NULL){
				if(temp->Pass==pass &&  temp->Id == username){
					return true;
					//break;
				}
					temp = temp->link;
			}//while
			return false;
		}	
        void Register(){
            string name,thai_number,Tel,id,pass;
            cout << "=========== Register ==========" << endl;
            cout << "Name & Lastname: ";
            cin.ignore();
            getline(cin,name);
            //cin.ignore();
            //cin >> name;
            cout << "Identification: ";
            cin >> thai_number;
            cout << "Telephone number: ";
            cin >> Tel;
            cout << "==============================" << endl;
                while(check_NumberTH(thai_number) == true || Tel.length() != 10){
                    cout << "!!! Warring !!!\n";
                    if(check_NumberTH(thai_number) == true || thai_number.length() != 13){
                        cout << "Identification: ";
                        cin >> thai_number;                        
                    }
                    if(Tel.length() != 10){
                        cout << "Telephone number: ";
                        cin >> Tel;
                    }
                }
            do{
                cout << "========== Sign up ===========" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "Password: ";
                cin >> pass;
                cout << "==============================" << endl;
                //check
            }while(check(id,pass) != false || id.length() != 8 || pass.length() != 10 );
            //write file
            ofstream myfile;
			myfile.open("Member.txt",std::ios::app);//writeFirstname to file
			myfile << name<<","<< thai_number << "," << Tel << "," << id << "," << pass << endl;
			myfile.close(); 
        }
};
class Booking{
    private:
        string name_customer;
        string booking_datego,booking_dateback;
        string Id_seat;
        string from;
        string to;
        string Class;
    public:
        Booking(){
            name_customer = " ";
            booking_datego  = " ";
            booking_dateback = " ";
            Id_seat = " ";
            from = " ";
            to = " ";
            Class = " ";
        }
        void booking_ticket_RoundTrip(string From,string To,string DateGo,string DateBack,string Floor){
            
        }
};
class NodeTicket{
	public:
		string PassengerName;
		string Seat;
		string Form,To;
		string Class;
		string Date;
		NodeTicket*link;
		NodeTicket *plink;
		NodeTicket(string PName,string Cl,string Se,string F,string T,string d){
			PassengerName = PName;
			Seat = Se;
			Class = Cl;
			Form = F;
			To = T;
			Date = d;
			link = NULL;
			plink = NULL;
		}
};
class TicketList{
	private:		
		NodeTicket *head;
		NodeTicket *tail;
		int count;
		
	public:
		TicketList(){
			head = NULL;
			tail = NULL;
			count = 0;
		}	
	~TicketList(){
			for(int i=1;i<count;i++){
				NodeTicket *temp = head;
				head = head->link;
				delete temp;
				temp = NULL;
			}
			head = NULL;
			tail = NULL;
		}
	void Add_ticket(string PassengerName,string Class,string Seat,string Form,string To,string date){
			NodeTicket *n = new NodeTicket(PassengerName,Class,Seat,Form,To,date);
			if(head == NULL){
				head = n;
				tail = head;
				count++;
			}else{
				tail->link = n;
				n->plink = tail;	
				tail = n;
				count++;
			}		
		}
		void Add_ticketMember(string user,string Class,string Seat,string Form,string To,string date){
			NodeTicket *n = new NodeTicket(user,Class,Seat,Form,To,date);
			if(head == NULL){
				head = n;
				tail = head;
				count++;
			}else{
				tail->link = n;
				n->plink = tail;	
				tail = n;
				count++;
			}		
		}
	string checkname(string id){
		//loadfile();
		NodeTicket *temp = head;
		while(temp != NULL){
			if(temp->PassengerName == id){
				return temp->PassengerName;
			//	break;
			}
				temp = temp->link;
		}
	}
	void saveticket(){
		NodeTicket *temp = head;
			ofstream myFile3("ticket.txt",ios::out);
        	if(myFile3.is_open()){ 
				while(temp!=NULL){
					myFile3  << temp->PassengerName <<","<< temp->Class << "," << temp->Seat << ","  << temp->Form <<"," << temp->To <<"," 
					<< temp->Date << "," << endl;
					temp = temp->link;
				}  
			}	
	}
	void showTicket(){
		NodeTicket *temp = head;
		while(temp != NULL){	
				cout <<"Name : "<< temp->PassengerName <<" Class : "<< temp->Class << " Seat : " << temp->Seat << " Travel form : "  << temp->Form <<" Travel to :" << temp->To <<" Date of ticket purchase : " << temp->Date << endl;
				temp = temp->link;
		}
	}
	void showTicketMember(){
		NodeTicket *temp = head;
		while(temp != NULL){	
				cout <<"username : "<< temp->PassengerName <<" Class : "<< temp->Class << " Seat : " << temp->Seat << " Travel form : "  << temp->Form <<" Travel to :" << temp->To <<" Date of ticket purchase : " << temp->Date << endl;
				temp = temp->link;
		}
	}
};

int main(){
	memberList *obj = new memberList;
	TicketList *ticket = new TicketList;
	Seat *s  = new Seat; 
	string PassengerName,username,password;
	string Form,to,Date;
	string Seat,N,n;
	int cost;
	string Class;
	int menu,YN,yn,choice,choice1,choice2;
	readfile("First_page");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Year:" << 1900 + ltm->tm_year <<" ";
    cout << "Month: "<< 1 + ltm->tm_mon <<" ";
    cout << "Day: "<<  ltm->tm_mday <<" ";
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
	Airplane:cout <<"======Airplane ticket booking======"<<endl;
	cout <<"1.Book ticket"<<endl;
	cout <<"2.Book ticket in advance"<<endl;
	cout <<"3.register"<<endl;
	cout <<"4.Exit"<<endl;
	cout <<"Enter=> ";
	cin >> menu;
		if (menu == 1){
			cout << "Do you want to login?"<<endl;
			cout << "1.Yes"<<endl;
			cout << "2.No"<<endl;
			cout <<"Enter=> ";
			cin >> yn;
				if (yn == 1){
					login:cout << "==== Airplane ticket booking ====" << endl;
					cout << "Enter Username: ";
					cin>> username;
					cout << "Enter Password: "; 
					password = Hide_password();
					//cin>>password;
					cout <<endl <<"==================" << endl;
					if(obj->Checkpass(username,password)==true){
			    booking:cout<<"====== Airplane Ticket ======="<<endl;
						cout<<"1.booking"<<endl;
						cout<<"2.Exit"<<endl;
						cin >> choice;
								cout <<"1.booking" <<endl;
								cout <<"your ID : " ;
								cout << username <<endl;
					ChooseClass:cout <<"Choose Seat Class F,B,E:";
								cin >> Class;
								if(Class != "F" && Class != "B" && Class != "E"){
									cout <<"we only have F,B,E class"<<endl;
									goto ChooseClass;
								}else if(Class == "F"){
									cost = 4000;
								}else if(Class == "B"){
									cost = 3000;
								}else if(Class == "E"){
									cost = 2000;
								}
								char Arr[7][5]; 
								for(int i=0;i<7;i++){
									//forst column is row number
									Arr[i][0]=i+1+'0';
									for(int j=1;j<5;j++){
										//to represent sit number A,B,C,D respectively
										Arr[i][j]='A'+j-1; 
									}
								}
								//getData();
								//string S = s->getSeat();
								//cout << "Choose Seat position ";
								//cout<<"enter valid seat no to check(like 1B) or N to end: ";
								//cin >> Seat;
								s->display(Arr);
								s->airline(Arr); //airline function
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticketMember(username,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
							goto booking;
				}else if(obj->Checkpass(username,password) != true){	
						cout<<"!!!!!Invalid Username or Password!!!! "<<endl;
						goto Airplane;
					}
				}else if (yn == 2){
								cout <<"2.booking no login"<<endl;
								cout <<"input your name :";
								cin >> PassengerName;
				    ChooseClass2:cout <<"Choose Seat Class F,B,E:";
								cin >> Class;
								if(Class != "F" && Class != "B" && Class != "E"){
									cout <<"we only have F,B,E class"<<endl;
									goto ChooseClass2;
								}else if(Class == "F"){
									cost = 4000;
								}else if(Class == "B"){
									cost = 3000;
								}else if(Class == "E"){
									cost = 2000;
								}
								char arr[7][5]; 
								for(int i=0;i<7;i++){
									//forst column is row number
									arr[i][0]=i+1+'0';
									for(int j=1;j<5;j++){
										//to represent sit number A,B,C,D respectively
										arr[i][j]='A'+j-1; 
									}
								}
								s->display(arr);
								s->airline(arr);
								//string S2 = s->getData();
								//cout << "Choose Seat position :";
								//cin >> Seat;
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticket(PassengerName,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
							goto Airplane;
				}
		}else if (menu == 2){
			cout << "Do you want to login?"<<endl;
			cout << "1.Yes"<<endl;
			cout << "2.No"<<endl;
			cout <<"Enter=> ";
			cin >> YN;
			if (YN == 1){
		 login2:cout << "==== Airplane ticket booking ====" << endl;
				cout << "Enter Username: ";
				cin>>username;
				cout << "Enter Password: "; 	
				password = Hide_password();	
				cout << endl <<"==================" << endl;
				if(username.length()!=8 && password.length()!= 10){
						cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
						goto login2;
					}
					if(obj->Checkpass(username,password) == true){
						booking2:
						cout<<"====== Airplane Ticket ======="<<endl;
						cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
						cout<<"1.booking"<<endl;
						cout<<"2.Exit"<<endl;
						cin >> choice2;
							cout <<"1.booking" <<endl;
								cout <<"your ID : " ;
								cout << username <<endl;
					ChooseClass3:cout <<"Choose Seat Class F,B,E:";
								cin >> Class;
								if(Class != "F" && Class != "B" && Class != "E"){
									cout <<"we only have F,B,E class"<<endl;
									goto ChooseClass3;
								}else if(Class == "F"){
									cost = 4000;
								}else if(Class == "B"){
									cost = 3000;
								}else if(Class == "E"){
									cost = 2000;
								}
								char Arr2[7][5]; 
								for(int i=0;i<7;i++){
									//forst column is row number
									Arr2[i][0]=i+1+'0';
									for(int j=1;j<5;j++){
										//to represent sit number A,B,C,D respectively
										Arr2[i][j]='A'+j-1; 
									}
								}
								s->display(Arr2);
								s->airline(Arr2);
								//string S3 = s->getData();
								//cout << "Choose Seat position ";
								//cin >> Seat;
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to?";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticketMember(username,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
								goto booking;
					}else if(obj->Checkpass(username,password) != true){
						cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
						goto login2;
					}
			}else if (YN == 2) {
								cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
								cout <<"2.booking no login"<<endl;
								cout <<"input your name :";
								cin >> PassengerName;
				    ChooseClass4:cout <<"Choose Seat Class F,B,E:";
								cin >> Class;
								if(Class != "F" && Class != "B" && Class != "E"){
									cout <<"we only have F,B,E class"<<endl;
									goto ChooseClass4;
								}else if(Class == "F"){
									cost = 4000;
								}else if(Class == "B"){
									cost = 3000;
								}else if(Class == "E"){
									cost = 2000;
								}
								//cout << "Choose Seat position ";
								//cin >> Seat;
								char Arr3[7][5]; 
								for(int i=0;i<7;i++){
									//forst column is row number
									Arr3[i][0]=i+1+'0';
									for(int j=1;j<5;j++){
										//to represent sit number A,B,C,D respectively
										Arr3[i][j]='A'+j-1; 
									}
								}
								s->display(Arr3);
								s->airline(Arr3);
								//string S4 = s->getData();
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to?";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticket(PassengerName,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
								goto Airplane;
			}
			EXIT:cout <<"Exit"<<endl;		
		}else if (menu == 3){
				obj->Register();
			}else if (menu == 4){
				goto EXIT;
			}
		return 0;
}
