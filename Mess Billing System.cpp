#include<iostream>
#include<string>

using namespace std;

void menuFunction(string day[],int &v,string menu[],int price[],int &m)
{
    do
    {
        cout<<"Enter the day: "<<endl;
    	cin>>day[v];                                //stores the input in the array of the datatype string
        for(int y=1;y<=3;y++)
        {
            cout<<"Enter the name of the dish: "<<endl;
            cin>>menu[m];                                                   //used to store the name of the menu in the array menu of the string datatype as there are 21 meal the size of the arrat is 21
            cout<<"Enter the price of the respective menu: "<<endl;
            cin>>price[m];                                                  //used to store the price of the respective menu entered by the manager prior to this as their are 27 meals so there are 21 menus as well
            m++;                                                            //as there are three meals each day therefore the menu and price are entered three times for each day using the nested loop
		}
        v++;                                                                //increments the day number
	}while((m<21)&&(v<7));                                                  //checks whether the day number or the food number has exceeded the limit if it does the loop stops iterating and the manager has successfully filledd the mess menu along with repective prices
}





void messInOutFunction(int check_r,int total,int reg_no[],bool check_io[])
{
    cout<<"Enter the registration number of student : ";
    cin>>check_r;
    bool q=0;
    int j=0;
    while((j<total)&&(q!=1))                        //the while loop iterates till the registration number is found inside the record
    {
        if(reg_no[j]==check_r)                      //checks whether the entered registration number of the student matches with the one in the record
        {
            q=1;                                    //if the condition is satisfied the value of the variable q becomes one and as the loop iterates once again the condition is unsatisfied and the iterations stop
        }
        else
        {
            q=0;                                    //retains the value of q to be zero so that the loop keeps on iterating until the registration number is found in the record
            j++;                                    
        }                      
    }
    if(q==1)
    {
        cout<<"Press I to mess in a student or O to mess out a student.";
        char b;                 
        cin>>b;
        if(b=='I')
        check_io[j]=1;                              //stores 1 in the boolean array element of the respective student indicating that the student is in
        else if(b=='O')
        check_io[j]=0;                              //stores 0 in the boolean array element of the respective student indicating that the student is out
        else
        cout<<"Invalid input."<<endl;
        cout<<"------------------------------------------------------"<<endl;
    }
    else
    cout<<"Invalid registration number."<<endl;     //if the boolean variable q is not equal to one this indicates that the registration number of the student was never found in the record of the students in the mess
    cout<<"------------------------------------------------------"<<endl;
}



void addStudentFunction(int &total,int &n,string name[],int reg_no[],int password[],int bill[],bool check_io[])
{
    total=total+1;                                      //increases the total number of students as a new one is added
    cout<<"Enter the student name : ";
    cin>>name[n];                                   //stores the name of the new student in the array, names, of string datatype
    cout<<"Enter the student registration number : ";
    cin>>reg_no[n];                                 //stores the registration nuumber of the new student in the array, reg_no, element of the respective student
    cout<<"Enter the student pasword : "; 
    cin>>password[n];                               //sets the password of the new student to be used later by that student to check the menu of the week and to check his dues
    cout<<"New student name : "<<name[n]<<endl;
    cout<<"New student registration number : "<<reg_no[n]<<endl;
    cout<<"New student password : "<<password[n]<<endl;
    bill[n]=0;  //as the student is new therefore his bill is initialized to zero
    check_io[n]=1;
    cout<<"------------------------------------------------------"<<endl;
    n++;
}






void printAllstudentsMessBills(int total,string name[],int reg_no[],int bill[])
{
    for(int i=0;i<total;i++)
    {
        cout<<"Name : "<<name[i]<<endl;
        cout<<"Reg no. : "<<reg_no[i]<<endl;
        cout<<"Total Bill : "<<bill[i]<<endl<<endl;
    }
}




void printSingleStudentMessBill(int check_r,int total,int reg_no[],string name[],int bill[])
{
    cout<<"Enter the registration number of student : ";
    cin>>check_r;
    bool q=0;
    int j=0;
    while((j<total)&&(q!=1))
    {
        if(reg_no[j]==check_r)
        {
            q=1;
        }
        else
        {
            q=0; 
            j++;
        }                      
    }
    if(q==1)
    {
        cout<<"Name : "<<name[j]<<endl;
        cout<<"Registration number : "<<reg_no[j]<<endl;
        cout<<"Total bill : "<<bill[j]<<endl;
        cout<<"------------------------------------------------------"<<endl;
    }
    else
    {
        cout<<"Invalid registration number."<<endl;
        cout<<"------------------------------------------------------"<<endl;
    }
}





void checkStudentProfileFunction(int check_r,int total,int reg_no[],string name[],int password[],int bill[])
{
    cout<<"Enter the registration number of student : ";
    cin>>check_r;                               //stores the registration number of the particular student whose profile is to be determined
    bool q=0;
    int j=0;
    while((j<total)&&(q!=1))                    //the loop iterates to find the entered registration number in the record of the registration number
    {
        if(reg_no[j]==check_r)
        {
            q=1;                                //if the registration number matches an element in the array of registration numbers, then the boolean variable q is assigned the value of 1 so that it can stop the iterations of the loop 
        }
        else
        {
            q=0;                                //if the registration number doesn't match the element of the array reg_no then the value of the boolean variable q is retained and j increments by 1
            j++;
		}
    }
    if(q==1)                                    //if the value of the boolean variable is one then this means that the registration number has been found among the registration numbers stored in the array reg_no
    {
        cout<<"Name : "<<name[j]<<endl;
        cout<<"Registration number : "<<reg_no[j]<<endl;
        cout<<"Password : "<<password[j]<<endl;
        cout<<"Bill due : "<<bill[j]<<endl;
        cout<<"------------------------------------------------------"<<endl;
	}
    else
    {
        cout<<"Invalid registration number.";   //if the value of the boolean variable is not 1 but 0, then this means that the registration number has not been found among the registration numbers stored in the array
    }
}







void billPaymentFunction(int check_r,int total,int reg_no[],int bill[],string name[])
{
    cout<<"Enter the student registration number : ";
    cin>>check_r;
    bool q=0;
    int j=0;
    while((j<total)&&(q!=1))
    {
        if(reg_no[j]==check_r)
        {
            q=1;
        }
        else
        {
            q=0; 
            j++;
		}
    }
    if(q==1)                                    //if the value of the boolean variable is 1, that means that the registration number of that particular student has been found
    {
        cout<<bill[j]<<endl;
        cout<<"Enter P if the bill is payed and N if not: ";
        char r;
        cin>>r;
        if(r=='P')
        {
            bill[j]=0;
            cout<<"The due bill of the student "<<name[j]<<", registration number "<<reg_no[j]<< "is: "<<bill[j]<<endl;
        }
        else if(r=='N')
        {
            cout<<"The due bill is not payed"<<endl;
            cout<<"The due bill of the student "<<name[j]<<", registration number "<<reg_no[j]<< "is: "<<bill[j]<<endl;
        }
        else
        {
            cout<<"Invalid input."<<endl;
        }
        cout<<"------------------------------------------------------"<<endl;
    }
    else
    {
        cout<<"Invalid registration number"<<endl;
    }
}








int main()
{
    char check;                                                     //to either he is a consumer or mess owner
    char oc='O';                                                    //open or close
    string name[100];                                               //use to store the names of all the students in th mess            
    int reg_no[100];                                                //used to store the registration numbers of all the students in the mess
    int password[100];                                               
    int bill[100];
    bool check_io[100];                                             //check_io is a boolean variable which keeps the record of all the students whether they are in or out
    int n=0;  
    int total=0;                                                      //used to store the total number of students registered in the mess
    int check_p,check_r;                                            //the variable check_p is used to check the validity of the user whether he is the manager or a student where as the check_r variable is used to store the regitration number of the student
    string menu[21]= {"CHICKEN_SOUP","RICE_PILAF","CHOCOLATE_CAKE","COFFEE","FRUIT_SALAD","ROASTED_VEGETABLES","TOMATO_BASIL_SOUP","GREEK_SALAD","BEEF_STROGANOFF","STUFFED_PEPPERS","APPLE_PIE","PASTA_PRIMAVERA","BAKED_SALMON","CHILLI_CON_CARNE","COLESLAW","MINESTRONE_SOUP","CAESAR_SALAD","VEGETABLE_STIR_FRY","STEAMED_BROCCOLI","ICED_TEA","LEMMONADE"};                           //used to store the names of the meal per day                                               //used to store the names of the meal per day
    int m=0;
    string day[7]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};                                                  //array used to make a record of seven days
    int v=0;                                                  //array used to make a record of seven days
    int price[21]={200,150,130,160,150,400,160,130,150,200,130,160,150,200,150,350,160,190,180,160,130};                                                  //array to store the price of the respective meal in the menu
    bool b;
    n=0;
    cout<<"Enter the manager password to start : ";
    cin>>check_p;
    if(check_p==68422486)                                           //This password checks the validity of whether the user is valid for this computer system
    {
        do                                                          //a do while loop used to store
    {
    cout<<"Enter S if your are a student and M if your are a manager : "; 
    cin>>check;
    if(check=='M')                                                  //else if statement used to check whether the user is the manager or  student
    {
        cout<<"Enter the password : ";                              //used for checking the validity
        cin>>check_p;
        if(check_p==68422486)                                       //this password is used to check the validity of the user as a manager specifically               
        {
            char checker;
            cout<<"Press M to change menu. "<<endl;
            cout<<"Press I to mess in or mess out a student. "<<endl;
            cout<<"Press A to add a student."<<endl;
            cout<<"Press P to print all students mess bills. "<<endl;
            cout<<"Press S to print single student bill. "<<endl;
            cout<<"Press C to close mess. "<<endl;
            cout<<"Press O to check student profile. "<<endl;
            cout<<"Press U for bill payment. "<<endl;
            cin>>checker;                                           //the checker variable is used to acknowledge whichh operation the manager wants to perform
            cout<<"------------------------------------------------------"<<endl;
            switch(checker)                                         //switch statement used to select the operation which the manager wants to perform
            {
                case 'M':
                {
                    menuFunction(day,v,menu,price,m);                                            
                }
                break;
                case 'I':                                           //in this block of code the registration number of thr particular student is stored who enters the mess
                {
                    messInOutFunction(check_r,total,reg_no,check_io);
                }
                break;
                case 'A':                                           //chunk of code used for adding a new student to the mess
                {
                    addStudentFunction(total,n,name,reg_no,password,bill,check_io);
                }
                break;
                case 'C':                                           //this case closes the mess billing system as the compiler reaches the condition of the do while loop which states that the loop will keep on iterating till the value of the string variable oc is 'c'
                {
                    oc='C';
                }
                break;
                case 'P':
                {
                    printAllstudentsMessBills(total,name,reg_no,bill);
                }
                break;
                case 'S':
                {
                    printSingleStudentMessBill(check_r,total,reg_no,name,bill);
                }
                break;
                case 'O':                                           //used to check the profile of a particular student
                {
                    checkStudentProfileFunction(check_r,total,reg_no,name,password,bill);
				}
                break;
                case 'U':
                {
                    billPaymentFunction(check_r,total,reg_no,bill,name);
                }
                b=0;
            }
        }
        else
        {
            cout<<"Invalid password."<<endl;                        //if the password entered into the manager system is incorrect then the message of incorrect password will be displayed
        }
        b=0;
        cout<<"------------------------------------------------------"<<endl;
    }

    else if(check=='S')                                             //if the user is a student then the chunk of code should be executed
    {
        cout<<"Enter your registration number : ";
        cin>>check_r;                                               //the registation number of the student who is trying to enter the system is stored in the variable check_r
        int i=0;
		b=0;
        while((i<total)&&(b!=1))                                    //loop is used to find out the student with the entered registration number
        {
            if(reg_no[i]==check_r)                                  //if the student is found in the record then the boolean variable b initializes to 1
            {
                b=1;
            }
            else
			{ 
                b=0;
                i++;
            }
        }
        if(b==1)                                                    //if the value of the boolean variable b is 1 this means that the student with the entered reigistration number has been found
        {
        	cout<<"Enter your password.";
        	cin>>check_r;                                           //password of the student entering the system is entered over here to authenticate whether he is the real student or not
        	if(check_r==password[i]||check_r==68422486)             //either the particular student or the manager can enter into the account of the particular student
            {
		    if(check_io[i]==1)
		    {
		int t=0;
                int k=0;
                int o=0;
                cout<<"Enter the day: "<<endl;
          	    string d;                                           //creation of a new string variable used to store the entered password of the student to be matched with all the passwords of the students in the record
		        cin>>d;
                while(d!=day[o])
                {
            	    o++;
            	    t=t+3;
			    }
                for(k=t;k<t+3;k++)
                {
            	    cout<<k-t+1<<". "<<menu[k]<<" price : "<<price[k]<<endl;
		}
		     cout<<"Do you want to take this meal or not(Y/N) : ";
                char c;
                cin>>c;
                if(c=='Y')
                {
                    cout<<"Which meal you want to take : ";
                    cin>>o;
                    if(o==1)
                    bill[i]=bill[i]+price[t];
                    else if(o==2)
                    bill[i]=bill[i]+price[t+1];
                    else if(o==3)
                    bill[i]=bill[i]+price[t+2];
                    else
                    cout<<"Invalid input"<<endl;
                }
                cout<<"Name : "<<name[i]<<endl;
                cout<<"Registration number : "<<reg_no[i]<<endl;
                cout<<"Your dues are : "<<bill[i]<<endl;
		}
		    else
			    cout<<"Your mess is out"<<endl;
       		}
       		else
            {
       		    cout<<"Invalid password."<<endl;
            }
            cout<<"------------------------------------------------------"<<endl; 

        }
        else
        {
          cout<<"Invalid registration  number"<<endl;  
        }
        
        cout<<"------------------------------------------------------"<<endl;  
        b=0;

    }
    else
    {
        cout<<"Invalid input."<<endl;
        b=0;
        cout<<"------------------------------------------------------"<<endl;
    }
    }
    while(oc!='C');
    }
    else
    {
        cout<<"Invalid password."<<endl;
        cout<<"------------------------------------------------------"<<endl;
        b=0;
    }
    return 0;
}
