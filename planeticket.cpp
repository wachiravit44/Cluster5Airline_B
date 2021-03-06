/************************************************************************/
/* Program Assignment: Planeticket										*/
/* Team : B																*/
/* Date : 16/10/2653     												*/
/************************************************************************/
#include "All_include_in_main.h"
#include<iostream>

using namespace std;
class node{
	public:
		string Departure;
		string Terminal;
		string Time_out;
		string Time_to;
		int cost;
		node *link;
		node *plink;
		node(string D,string Ter,string T_out,string T_to,int Cost){
			Departure = D;
			Terminal = Ter;
			Time_out = T_out;
			Time_to = T_to;
			cost = Cost;
			link = NULL;
			plink = NULL; 
		}
};
class round{
	public:
		node *head;
		node *tail;
		node *F;
		round(){
			head = NULL;
			tail = NULL;

		}
		bool check(string terminal){
			node *temp = head;
			while(temp != NULL){
				if(terminal == temp->Terminal){
					return true;
				}
				temp = temp->link;
			}
			delete temp;
			return false;
		}
		bool check(string out, string terminal){
			node *temp = head;
			while(temp != NULL){
				if(out == temp->Time_out && terminal == temp->Terminal){
					return true;
				}
				temp = temp->link;
			}
			delete temp;
			return false;

		}
		void add(string D,string Ter,string T_out,string T_to,int cost){
			node *Round = new node(D,Ter,T_out,T_to,cost);
			if(head == NULL){
				head = Round;
				tail = Round;
				F = head;
			}else{
				tail->link = Round;
				Round->plink = tail;
				tail = Round; 
			}
		}
		void read(){
			fstream R;
			string filein,de,ter,out,to,cost;
			int Cost;
			R.open("round.txt",ios::in);
			while(getline(R,filein)){
				de = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				ter = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				out = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				to = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				cost = filein;
				stringstream ss;
				ss << cost;
				ss >> Cost;
				add(de,ter,out,to,Cost);
                }
			R.close();
		}
		void all_show(){
			node *a = head;
			node *temp = head->link;
			while(a!=NULL){
				if(a->Terminal != temp->Terminal || a->link == NULL){
					cout <<"Departure: " <<a->Departure << " - Terminal: " <<a->Terminal <<endl;
				}
				if(temp->link != NULL){
					temp = temp->link;
				}
				a = a->link;
			}
		}
		void all_show(string de){
			node *a = head;
			int hour,h;
			string H;
			while(a!=NULL){
			time_t now = time(0);
			tm *ltm = localtime(&now);
			stringstream ss1,ss2,ss3,SS,SS1,SS2;
			h = ltm->tm_hour;
			H = a->Time_out.substr(0,2);
			ss1 << H;
			ss1 >> hour;
				if(a->Terminal == de && hour > h){
					cout <<"Round: " << a->Time_out <<" - " <<a->Time_to<<endl;
				}
				a = a->link;
			}
		}
};


class NodeTicket{
	public:
		string PassengerName;
		string Seat;
		string Form,To;
		string Class;
		string Date;
		string Time;
		string out;
		NodeTicket*link;
		NodeTicket *plink;
		NodeTicket(string PName,string Cl,string Se,string F,string T,string d,string o,string t){
			PassengerName = PName;
			Seat = Se;
			Class = Cl;
			Form = F;
			To = T;
			Time = o;
			out = t;
			Date = d;
			link = NULL;
			plink = NULL;
		}
};
class TicketList{
	public:		
		NodeTicket *head;
		NodeTicket *tail;
		int count;
		
	
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
	void remove(){
		NodeTicket *d = head;
		while(head != NULL){
			d = head;
			head = head->link;
			delete d;
		}
	}
	void Add_ticket(string PassengerName,string Class,string Seat,string Form,string To,string date,string out,string de){
			NodeTicket *n = new NodeTicket(PassengerName,Class,Seat,Form,To,date,out,de);
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
		void Add_ticketMember(string user,string Class,string Seat,string Form,string To,string date,string out,string de){
			NodeTicket *n = new NodeTicket(user,Class,Seat,Form,To,date,out,de);
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

			}
				temp = temp->link;
		}
	}
	void saveticket(){
		NodeTicket *temp = head;
		TicketList *h = new TicketList;
		string filein,name,Class,s,de,ter,date,out,to;
		fstream myfile("ticket.txt",ios::in);
			while(getline(myfile,filein)){
				name = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				Class = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				s = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				de = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				ter = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				out = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				to = filein;
				h->Add_ticket(name,Class,s,de,ter,date,out,to);
                }
			myfile.close();
			NodeTicket *ptemp = h->head;
			ofstream myFile3("ticket.txt",ios::app);
        	if(myFile3.is_open()){ 
				while(temp!=NULL){
					ptemp = h->head;
					while(ptemp !=NULL){
						if(ptemp->Class == temp->Class&&ptemp->Date == temp->Date&&ptemp->To == temp->To&&ptemp->Seat == temp->Seat&&ptemp->out == temp->out){
							break;
						}else{
							myFile3  << temp->PassengerName <<","<< temp->Class << "," << temp->Seat << ","  << temp->Form <<"," << temp->To <<"," 
							<< temp->Date << "," <<temp->Time << "," <<temp->out<<endl;
							break;
						}
						ptemp = ptemp->link;
					}
					temp = temp->link;
				}  
			}	
	}
	void sort(){
			NodeTicket *temp = head;
			NodeTicket *i,*j;
			string name,seat,to,day,go,TO;
			i = head; 
			j = i;
			for(i= head;i!=NULL;i=i->link){
				for(j=i;j!=NULL;j=j->link){
					if(i->Seat > j->Seat){
					name = i->PassengerName;
					seat = i->Seat;
					to = i->To;
					day = i->Date;
					go = i->Time;
					TO = i->out;

					i->PassengerName = j->PassengerName;
					i->Seat = j->Seat;
					i->To = j->To;
					i->Date = j->Date;
					i->Time = j->Time;
					i->out = j->out;
					
					j->PassengerName = name;
					j->Seat = seat;
					j->To = to;
					j->Date = day;
					j->Time = go;
					j->out = TO;
					}	
				}
			}
	}
	void showTicket(){
		NodeTicket *temp = head;
		while(temp != NULL){	
				cout <<"========================================================"<<endl;
				cout <<"PassengerName : "<< temp->PassengerName <<" Class : "<< temp->Class <<endl;
				cout << "Seat : " << temp->Seat <<" "<< "Travel form : "  << temp->Form <<" Travel to :"<< temp->To <<" " <<endl;
				cout <<"Date of ticket purchase : " << temp->Date << " Round: "<<temp->Time<< " - " << temp->out << endl;
				cout <<"========================================================"<<endl;
				temp = temp->link;
		} 
	}
	void showTicketMember(){
		NodeTicket *temp = head;
		while(temp != NULL){
				cout <<"========================================================"<<endl;
				cout <<"username : "<< temp->PassengerName <<" Class : "<< temp->Class <<endl;
				cout << "Seat : " << temp->Seat <<" " << "Travel form : "  << temp->Form <<" Travel to :"<< temp->To <<" " <<endl;
				cout <<"Date of ticket purchase : " << temp->Date << " Round: "<<temp->Time<< " - " << temp->out<< endl;
				cout <<"========================================================"<<endl;
				temp = temp->link;
		}
	}
	void calculate(int cost_class,int Rou){
		NodeTicket *temp = head;
		double sum = 0;
		while(temp != NULL){
			sum = sum + cost_class + Rou;
			temp = temp->link;
		}
		cout <<"-----------------------------------------"<<endl;
		cout <<"Total Cost: " << sum <<endl;
		cout <<"-----------------------------------------"<<endl;
		//return sum;
	}
	void calculate_member(int cost_class,int Rou){
		NodeTicket *temp = head;
		double sum = 0;
		while(temp != NULL){
			sum = sum + cost_class + Rou;
			temp = temp->link;
		}
		sum = sum-(sum*5/100);
		cout <<"-----------------------------------------"<<endl;
		cout <<"Total Cost: " << sum <<endl;
		cout <<"-----------------------------------------"<<endl;
		//return sum;
	}
};
class Seat{
	private:
		int count;
		string p;
		string seat;
		round *ro;
	public:
		TicketList *ticket;
		Seat(){
			count = 0;;
			p = "";
			ticket = new TicketList();
			ro = new round;
			ro->read();
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
		string as;
		cout<<"enter valid seat no to check(like 1B) or N to end: ";
		cin>>as;
		if(as != "N"){
			seat = as;
		}
		return as;
	}
	string getSeat(){ 
		return seat;
	}
	void update(char arr[7][5],string Out,string terminal,string C,string Date){
		string name,Class,seat,de,ter,date,filein,out,to;
		int row,col;
		fstream R;
		R.open("ticket.txt",ios::in);
		while(getline(R,filein)){
			stringstream ss;
			name = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			Class = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			seat = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			de = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			ter = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			date = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			out = filein.substr(0,filein.find(','));
				filein.erase(0,filein.find(',')+1);
			to = filein;
			if(out == Out && ter == terminal && Class == C && date == Date){
				ss << seat[0];
				ss >> row;
				if(seat.substr(1,1) == "A"){
					col = 1;
				}else if(seat.substr(1,1) == "B"){
					col = 2;
				}else if(seat.substr(1,1) == "C"){
					col = 3;
				}else if(seat.substr(1,1) == "D"){
					col = 4;
				}
				arr[row-1][col] = 'x';
			}
		}
		R.close();
	}
	//update sit status
	void update(char arr[7][5],int row,int col){ 
		cout<<"congrats, your seat is valid. Reserved for you\n";
		cout<<"updated seat status..........\n";
		arr[row][col] ='X';
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
	void airline(char arr[7][5],string username,string Class,string form,string to,string Date,string out){
		// user can stop process by pressing 'N'
		cout<<"enter N if you are done!\n"; 
		string s ,de;
		round *as = ro;
		// continue if not interrepted by user or 
		//there is valid sit in unoccupied state
		while(as->head->Time_out != out){
			as->head=as->head->link;
		}
		de = as->head->Time_to;
		while(true){ 
			
			s=getData(); //get user input
						//if user input is to stop the process
			if(s[0]=='N') 
				break;  // break
						//process the request & check according to
			if(check(arr,s)!=0){ 
				system("cls");
				readfile("First_page");
				cout<<"===== SEAT ====="<<endl;
					display(arr);
				cout<<"================"<<endl;
				if(allOccupied(arr)){ //if all sits are occupied
					cout<<"sorry, no more seats left!!!!!!!!!!..."<<endl;
					break;
				}

				ticket->Add_ticket(username,Class,s,form, to, Date,out,de);
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
                cout << "ID [8]: ";
                cin >> id;
                cout << "Password [10]: ";
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
        string booking_datego;
        string Id_seat;
        string from;
        string to;
        string Class;
    public:
        Booking(){
            name_customer = " ";
            booking_datego  = " ";
            //booking_dateback = " ";
            Id_seat = " ";
            from = " ";
            to = " ";
            Class = " ";
        }
        void booking_ticket_RoundTrip(string From,string To,string DateGo,string Floor){
            
        }
};
void Enter(){
  char enter = ' ';
  cout << "Please Enter to Continue . . . ";
  while((enter = getch()) != '\r'){  
    cin >> enter;
  }
  system("cls");
}

void clear(){
		TicketList *temp = new TicketList;
		string filein,name,Class,s,de,ter,date,out,to;
		fstream DE;
		fstream myfile("ticket.txt",ios::in);
			while(getline(myfile,filein)){
				//cout << "AS" << endl;
				name = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				Class = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				s = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				de = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				ter = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				date = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				out = filein.substr(0,filein.find(','));
					filein.erase(0,filein.find(',')+1);
				to = filein;
				temp->Add_ticket(name,Class,s,de,ter,date,out,to);
            }
			myfile.close();
		//cout << "asd" <<endl;
	
	string days,mon,years;
	    time_t now = time(0);
    	tm *ltm = localtime(&now);
		int year,m,day,H,min,sec;
		year = 1900 + ltm->tm_year;
		m = 1 + ltm->tm_mon;
		day = ltm->tm_mday;
	
	DE.open("ticket.txt",ios::out);
	while(temp->head != NULL){
			days = temp->head->Date.substr(0,2);
			mon = temp->head->Date.substr(3,2);
			years = temp->head->Date.substr(6,4);
			stringstream D,M,Y;
			D << days;
			M << mon;
			Y << years;
			D >> H;
			M >> min;
			Y >> sec;
		if(H >= day && min >= m && sec >= year){
			DE << temp->head->PassengerName <<","<< temp->head->Class << "," << temp->head->Seat << ","  << temp->head->Form <<"," << temp->head->To <<"," 
					<< temp->head->Date << "," <<temp->head->Time << "," <<temp->head->out<<endl;
		}
		temp->head = temp->head->link;
	}
	DE.close();
}

int main(){
	clear();
	memberList *obj = new memberList;
	TicketList *ticket = new TicketList;
	round *Round = new round;
	Round->read();
	Seat *s  = new Seat; 
	string Rou;
	//Queue *q = new Queue;
	string PassengerName,username,password,Date2;
	string Form,to;
	string Seat,N,n;
	int cost;
	int ad;
	string Class;
	string d,MO,YYY;
	int advance;int MMM;
	int DD;	
	int menu,YN,yn,choice,choice1,choice2;
	Airplane:system("cls");
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Year:" << 1900 + ltm->tm_year <<" ";
    cout << "Month: "<< 1 + ltm->tm_mon <<" ";
    cout << "Day: "<<  ltm->tm_mday <<" ";
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
	int year,m,day,h,min,sec;
		year = 1900 + ltm->tm_year;
		m = 1 + ltm->tm_mon;
		day = ltm->tm_mday;
		h = ltm->tm_hour;
		min = 1 + ltm->tm_min;
		sec = 1 + ltm->tm_sec;
		stringstream ssyear,ssm,ssd;
		ssyear << year;
		ssm << m;
	    ssd << day;
		string Year = ssyear.str();
		string M = ssm.str();
		string Day = ssd.str();
		if(Day.length() ==1){
			Day = "0"+Day;
		}
		if(M.length() == 1){
			M = "0"+M;
		}
		string Date = Day+"/"+M+"/"+Year;										
	
	readfile("First_page");
	cout <<"======Airplane ticket booking======"<<endl;
	cout <<"1.Book ticket"<<endl;
	cout <<"2.Book ticket in advance"<<endl;
	cout <<"3.register"<<endl;
	cout <<"4.Exit"<<endl;
	cout <<"==================================="<<endl;
	cout <<"Enter=> ";
	cin >> menu;
		if (menu == 1){
			cout << "Do you want to login?"<<endl;
			cout << "1.Yes"<<endl;
			cout << "2.No"<<endl;
			cout <<"Enter=> ";
			cin >> yn;
				if (yn == 1){
					login:
					system("cls");
					readfile("First_page");
					cout << "==== Airplane ticket booking ====" << endl;
					cout << "Enter Username: ";
					cin>> username;
					cout << "Enter Password: "; 
					password = Hide_password();
					//cin>>password;
					cout <<endl <<"==================" << endl;
					if(obj->Checkpass(username,password)==true){
			    booking:system("cls");
						readfile("First_page");
						cout<<"====== Airplane Ticket ======="<<endl;
						cout<<"1.Booking"<<endl;
						cout<<"2.Back"<<endl;
						cout<<"==============================" << endl;
						cout<<"Please Enter : ";
						cin >> choice;
						if(choice == 1){
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
								tra:
								Round->head = Round->F;
								Round->all_show();						
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin.ignore();
								getline(cin,to);
								if(Round->check(to)!=true){
									goto tra;
								}
								ro:
								Round->all_show(to);
								cout<<"Please Choose Round : ";
								cin >> Rou;
								if(Round->check(Rou,to)!=true){
									goto ro;
								}
								system("cls");
								readfile("First_page");
								cout<<"===== SEAT ====="<<endl;
								s->update(Arr,Rou,to,Class,Date);
								s->display(Arr);
								cout<<"================"<<endl;
								s->airline(Arr,username,Class,Form,to,Date,Rou); //airline function
								s->ticket->saveticket();
								s->ticket->sort();
								s->ticket->showTicketMember();
								Round->head = Round->F;
								while(Round->head != NULL){
									if(Round->head->Time_out == Rou && Round->head->Terminal == to){
										break;
									}
									Round->head = Round->head->link;
								}
							
								s->ticket->calculate_member(cost,Round->head->cost);
								s->ticket->remove();
								Enter();
							goto booking;
						}else if(choice == 2){
							goto Airplane;
						}
								
				}else if(obj->Checkpass(username,password) != true){	
						cout<<"!!!!!Invalid Username or Password!!!! "<<endl;
						goto Airplane;
					}
				}else if (yn == 2){
								system("cls");
								readfile("First_page");
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
								tra_se:
								Round->head = Round->F;
								Round->all_show();
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin.ignore();
								getline(cin,to);
								if(Round->check(to)!=true){
									goto tra_se;
								}
								roses:
								Round->all_show(to);
								cout<<"Please Choose Round : ";
								cin >> Rou;
								if(Round->check(Rou,to)!=true){
									goto roses;
								}
								system("cls");
								readfile("First_page");
								cout<<"===== SEAT ====="<<endl;
								s->update(arr,Rou,to,Class,Date);
								s->display(arr);
								cout<<"================"<<endl;
								s->airline(arr,PassengerName,Class,Form,to,Date,Rou);
								s->ticket->saveticket();
								s->ticket->sort();
								s->ticket->showTicket();
								Round->head = Round->F;
								while(Round->head != NULL){
									if(Round->head->Time_out == Rou && Round->head->Terminal == to){
										break;
									}
									Round->head = Round->head->link;
								}
								
								s->ticket->calculate(cost,Round->head->cost);
								s->ticket->remove();
								Enter();
							goto Airplane;
								
				}
		}else if (menu == 2){
			cout << "Do you want to login?"<<endl;
			cout << "1.Yes"<<endl;
			cout << "2.No"<<endl;
			cout <<"Enter=> ";
			cin >> YN;
			if (YN == 1){
		 login2:system("cls");
				readfile("First_page");
		 		cout << "==== Airplane ticket booking ====" << endl;
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
						
				booking2:cout<<"====== Airplane Ticket ======="<<endl;
						cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
						cout<<"1.booking"<<endl;
						cout<<"2.back"<<endl;
						cout <<"==============================" << endl;
						cout <<"Please Enter: ";
						cin >> choice2;
						if(choice2 == 1){
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
								tras:
								Round->head = Round->F;
								Round->all_show();
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin.ignore();
								getline(cin,to);
								if(Round->check(to)!=true){
									goto tras;
								}
								ros:
								Round->all_show(to);
								cout<<"Please Choose Round : ";
								cin >> Rou;
								if(Round->check(Rou,to)!=true){
									goto ros;
								}
								AD:cout <<"Date of ticket purchase advance:";
								cin >> ad;
								if(ad > 14){
									cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
									goto AD;
								}
								
								d = Date.substr(0,2);
								MO = Date.substr(3,2);
								YYY = Date.substr(6,4);
								stringstream day(d); 
								stringstream month(MO); 
    
    							day >> DD;
								month >> MMM;
								advance = DD+ad;
								if(advance > 32 ){
									if(MMM == 01 || MMM == 3 || MMM == 5 || MMM == 7 || MMM == 8 || MMM == 10 || MMM == 12){
										if(MMM == 02){
											DD = 0;
											DD = DD+advance-29;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}else if(MMM != 2){
											DD = 0;
											DD = DD+advance-31;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}	
									}
								}else if(advance > 31){
									if(MMM == 01 || MMM == 4 || MMM == 6 || MMM == 9 || MMM == 11){
										if(MMM == 02){
											DD = 0;
											DD = DD+advance-29;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}else if(MMM != 2){
											DD = 0;
											DD = DD+advance-30;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}	
									}
								}
								else{
									DD = DD+ad;
									cout <<"Date you have to go is :" << DD <<"/" << MO <<"/" << YYY << endl;
								}	
								stringstream days; 
								stringstream months; 
								days << DD;
								days >> d;
								months << MMM;
								months >> MO;

								if(d.length() ==1){
									d = "0"+d;
								}
								if(MO.length() == 1){
									MO = "0"+MO;
								}
								Date =  d +"/" + MO +"/" + YYY ;
								system("cls");
								readfile("First_page");
								cout<<"===== SEAT ====="<<endl;
								s->update(Arr2,Rou,to,Class,Date);
								s->display(Arr2);
								cout<<"================"<<endl;
								s->airline(Arr2,username,Class,Form,to,Date,Rou);
								s->ticket->saveticket();
								s->ticket->sort();
								s->ticket->showTicketMember();	
								Round->head = Round->F;
								while(Round->head != NULL){
									if(Round->head->Time_out == Rou && Round->head->Terminal == to){
										break;
									}
									Round->head = Round->head->link;
								}
								
								s->ticket->calculate_member(cost,Round->head->cost);
								s->ticket->remove();
								Enter();					
								goto booking;
						}else if(choice2 == 2){
							goto Airplane;
						}
								
					}else if(obj->Checkpass(username,password) != true){
						cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
						goto login2;
					}
			}else if (YN == 2) {
								bookingAdnologin:
								system("cls");
								readfile("First_page");
								cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
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

								char Arr3[7][5]; 
								for(int i=0;i<7;i++){
									//forst column is row number
									Arr3[i][0]=i+1+'0';
									for(int j=1;j<5;j++){
										//to represent sit number A,B,C,D respectively
										Arr3[i][j]='A'+j-1; 
									}
								}
								tra_s:
								Round->head = Round->F;
								Round->all_show();
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin.ignore();
								getline(cin,to);
								if(Round->check(to)!=true){
									goto tra_s;
								}
								rose:
								Round->all_show(to);
								cout<<"Please Choose Round : ";
								cin >> Rou;
								if(Round->check(Rou,to)!=true){
									goto rose;
								}
								AD2:cout <<"Date of ticket purchase advance:";
								cin >> ad;
								if(ad > 14){
									cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
									goto AD2;
								}
								d = Date.substr(0,2);
								MO = Date.substr(3,2);
								YYY = Date.substr(6,4);
								stringstream day(d); 
								stringstream month(MO); 
    							
    							day >> DD;
								month >> MMM;
								advance = DD+ad;
								
								if(advance > 32 ){
									if(MMM == 01 || MMM == 3 || MMM == 5 || MMM == 7 || MMM == 8 || MMM == 10 || MMM == 12){
										if(MMM == 02){
											DD = 0;
											DD = DD+advance-29;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}else if(MMM != 2){
											DD = 0;
											DD = DD+advance-31;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}	
									}
								}else if(advance > 31){
									if(MMM == 01 || MMM == 4 || MMM == 6 || MMM == 9 || MMM == 11){
										if(MMM == 02){
											DD = 0;
											DD = DD+advance-29;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}else if(MMM != 2){
											DD = 0;
											DD = DD+advance-30;
											MMM = MMM+1;
											cout <<"Date you have to go is :" << DD <<"/" << MMM  <<"/" << YYY << endl;
										}	
									}
								}
								else{
									DD = DD+ad;
									cout <<"Date you have to go is :" << DD <<"/" << MO <<"/" << YYY << endl;
								}	
								stringstream days; 
								stringstream months; 
								days << DD;
								days >> d;
								months << MMM;
								months >> MO;

								if(d.length() ==1){
									d = "0"+d;
								}
								if(MO.length() == 1){
									MO = "0"+MO;
								}
								Date =  d +"/" + MO +"/" + YYY ;
								system("cls");
								readfile("First_page");	
								cout<<"===== SEAT ====="<<endl;	
								s->update(Arr3,Rou,to,Class,Date);
								s->display(Arr3);
								cout<<"================"<<endl;
								s->airline(Arr3,PassengerName,Class,Form,to,Date,Rou);
								s->ticket->saveticket();
								s->ticket->sort();
								s->ticket->showTicket();
								Round->head = Round->F;
								while(Round->head != NULL){
									if(Round->head->Time_out == Rou && Round->head->Terminal == to){
										break;
									}
									Round->head = Round->head->link;
								}
							
								s->ticket->calculate(cost,Round->head->cost);
								s->ticket->remove();
								Enter();
								//goto bookingAdnologin;
						}
								goto Airplane;
			
			EXIT:cout <<"Exit"<<endl;		
		}else if (menu == 3){
				obj->Register();
				goto Airplane;
			}else if (menu == 4){
				goto EXIT;
			}
		clear();
		return 0;
}
