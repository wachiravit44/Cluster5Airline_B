/************************************************************************/
/* Program Assignment: Planeticket										*/
/* Team : B																*/
/* Date : 16/10/2653     												*/
/************************************************************************/
#include "All_include_in_main.h"
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
		int Date;
		NodeTicket*link;
		NodeTicket *plink;
		NodeTicket(string PName,string Cl,string Se,string F,string T,int d){
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
	void Add_ticket(string PassengerName,string Class,string Seat,string Form,string To,int date){
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
				cout << temp->PassengerName <<" "<< temp->Class << " " << temp->Seat << " "  << temp->Form <<" " << temp->To <<" " << temp->Date << endl;
				temp = temp->link;
		}
	}
	
};

int main(){
	memberList *obj = new memberList;
	TicketList *ticket = new TicketList;
	string PassengerName,username,password;
	string Form,to;
	string Seat,N,n;
	int Date;
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
				if (yn){
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
								cout <<"1.booking";
								cout <<"your ID and Name";
								N = ticket->checkname(username);
								cout << username <<endl;
								cout << N <<endl;
								cout <<"Choose Seat Class :";
								cin >> Class;
								cout << "Choose Seat position ";
								cin >> Seat;
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to? :";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticket(PassengerName,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
							goto booking;
				}else if(obj->Checkpass(username,password) != true){
						
						cout<<"!!!!!Invalid Username or Password!!!! "<<endl;
						goto Airplane;
					}
				}else if (yn){
								cout <<"2.booking no login";
								cout <<"input your name :";
								cin >> PassengerName;
								cout <<"Choose Seat Class :";
								cin >> Class;
								cout << "Choose Seat position :";
								cin >> Seat;
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
							cout <<"1.booking";
								cout <<"your ID and Name";
								n = ticket->checkname(username);
								cout << username <<endl;
								cout << n <<endl;
								cout <<"Choose Seat Class :";
								cin >> Class;
								cout << "Choose Seat position ";
								cin >> Seat;
								cout <<"Travel form :";
								cin >> Form;																
								cout <<"Travel to?";
								cin >> to;
								cout <<"Date of ticket purchase :";
								cin >> Date;
								ticket->Add_ticket(PassengerName,Class,Seat,Form,to,Date);
								ticket->saveticket();
								ticket->showTicket();
								goto booking;
					}else if(obj->Checkpass(username,password) != true){
						cout<<"!!!!!Invalid Username or Password!!!!"<<endl;
						goto login2;
					}
			}else if (YN == 2) {
								cout <<"You can only reserve ticket 2 weeks in advance."<<endl;
								cout <<"2.booking no login";
								cout <<"input your name :";
								cin >> PassengerName;
								cout <<"Choose Seat Class :";
								cin >> Class;
								cout << "Choose Seat position ";
								cin >> Seat;
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
