#include<iostream>
#include<string>
using namespace std;
int main()
{
    char check;//to either he is a consumer or mess owner
    char oc='O';//open or close
    string name[100];
    int reg_no[100];
    unsigned int password[100];
    int bill[100];
    bool check_io[100];
    int n,check_p,check_r;
    string menu[21];
    int m=0;
    string day[7];
    int v=0;
    int price[21];
    bool b;
    n=0;
    cout<<"Enter the manager password to start : ";
    cin>>check_p;
    if(check_p==68422486)
    {
        do
    {
    cout<<"Enter S if your are a student and M if your are a manager : ";
    cin>>check;
    if(check=='M')
    {
        cout<<"Enter the password : ";
        cin>>check_p;
        if(check_p==68422486)
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
            cin>>checker;
            cout<<"------------------------------------------------------"<<endl;
            switch(checker)
            {
                case 'M':
                {
                    do
                	{
                		cout<<"Enter the day: ";
                		cin>>day[v];
                		for(int y=1;y<=3;y++)
                		{
                			cout<<"Enter the name of the dish: "<<endl;
                			cin>>menu[m];
                			cout<<"Enter the price of the respective menu: "<<endl;
                			cin>>price[m];
                			m++;
						}
                		v++;
					}while((m<=20)&&(v<=6));
                }
                break;
                case 'I':
                {
                    cout<<"Enter the registration number of student : ";
                    cin>>check_r;
                    bool q=0;
                    int j=0;
                    while((j<n)&&(q!=1))
                    {
                        if(reg_no[j]==check_r)
                        q=1;
                        else
                        q=0; 
                        j++;                      
                    }
                    if(q==1)
                    {
                        cout<<"Press I to mess in a student or O to mess out a student.";
                        char b;
                        cin>>b;
                        if(b=='I')
                        check_io[j]=1;
                        else if(b=='O')
                        check_io[j]=0;
                        else
                        cout<<"Invalid input."<<endl;
                        cout<<"------------------------------------------------------"<<endl;
                    }
                    else
                    cout<<"Invalid registration number."<<endl;
                    cout<<"------------------------------------------------------"<<endl;
                }
                break;
                case 'A':
                {
                    cout<<"Enter the student name : ";
                    cin>>name[n];
                    cout<<"Enter the student registration number : ";
                    cin>>reg_no[n];
                    cout<<"Enter the student pasword.";
                    cin>>password[n];
                    cout<<"New student name : "<<name[n]<<endl;
                    cout<<"New student rgistration number : "<<reg_no[n]<<endl;
                    cout<<"New student password : "<<password[n]<<endl;
                    bill[n]=0;
                    cout<<"------------------------------------------------------"<<endl;
                    n++;
                }
                break;
                case 'C':
                {
                    oc='C';
                }
                break;
                case 'P':
                {
                    for(int i=0;i<n;i++)
                {
                    cout<<"Name : "<<name[i]<<endl;
                    cout<<"Reg no. : "<<reg_no[i]<<endl;
                    cout<<"Total Bill : "<<bill[i]<<endl<<endl;
                }
                }
                break;
                case 'S':
                {
                    cout<<"Enter the registration number of student : ";
                    cin>>check_r;
                    bool q=0;
                    int j=0;
                    while((j<n)&&(q!=1))
                    {
                        if(reg_no[j]==check_r)
                        q=1;
                        else
                        q=0; 
                        j++;                      
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
                break;
                case 'O':
                	{
                	cout<<"Enter the registration number of student : ";
                    cin>>check_r;
                    bool q=0;
                    int j=0;
                    while((j<n)&&(q!=1))
                    {
                        if(reg_no[j]==check_r)
                        q=1;
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
                    	cout<<"Password : "<<password[j]<<endl;
                    	cout<<"Bill due : "<<bill[j]<<endl;
                    	cout<<"------------------------------------------------------"<<endl;
					}
                    else
                    cout<<"Invalid registration number.";
					}
                    break;
                    case 'U':
                    {
                        cout<<"Enter the student registration number : ";
                        cin>>check_r;
                        bool q=0;
                        int j=0;
                        while((j<n)&&(q!=1))
                        {
                        if(reg_no[j]==check_r)
                        q=1;
                        else
                        {
                        q=0; 
                        j++;
						}
                        }
                        if(q==1)
                        {
                            cout<<bill[j]<<endl;
                            cout<<"Enter P if bill has paid or N if not paid . ";
                            char r;
                            cin>>r;
                            if(r=='P')
                            bill[j]=0;
                            else if(r=='N')
                            bill[j]=bill[j];
                            else
                            cout<<"Invalid input.";
                            cout<<"------------------------------------------------------"<<endl;
                        }

                    }
                    b=0;


            }
        }
        else
        cout<<"Invalid password."<<endl;
        b=0;
        cout<<"------------------------------------------------------"<<endl;

    }
    else if(check=='S')
    {
        cout<<"Enter your registration number : ";
        cin>>check_r;
        int i=0;
        while((i<n)&&(b!=1))
        {
            if(reg_no[i]==check_r)
            b=1;
            else
			{ 
            b=0;
            i++;
            }
        }
        if(b==1)
        {
        	cout<<"Enter your password.";
        	cin>>check_r;
        	if(check_r==password[i]||check_r==68422486)
            {
            cout<<"Today menu : "<<menu<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<"Date : "<<day[i]<<endl<<endl;
            cout<<"Name : "<<name[i]<<endl;
            cout<<"Registration number : "<<reg_no[i]<<endl;
            bill[i]=bill[i]+price[0];
            cout<<"Your dues are : "<<bill[i]<<endl;

       		}
       		else 
       		cout<<"Invalid password.";
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
