#include<bits/stdc++.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<vector>
using namespace std;

void admin_menu();

class student
{
    public:
    char admno[50],name[50];
    string adm,nme;
    vector<string>admn,names;

    void sread()
    {
        ifstream obj1("student.txt");
        while(obj1>>admno && obj1>>name)
        {
            admn.push_back(admno);
            names.push_back(name);
        }
        obj1.close();
    }

    void creates()
    {
        int a=0;
        cout<<"\nEnter the Details:-\n";
        cout<<"Enter Admission number: ";
        cin>>adm;
        sread();
        for(int i=0;i<admn.size();i++)
        {
            if(adm==admn[i])
            {
                cout<<"\n***Record already exists with this admission number***\n";
                cout<<"Enter a different Admission number...\n";
                a++;
                break;
            }
        }
        if(a==0)
        {
            cout<<"Enter Student's name: ";
            cin>>nme;
            ofstream obj2("student.txt",ios::app); //adding data without clearing prev data
            obj2<<endl;
            obj2<<adm<<" "<<nme<<endl;
            cout<<"\nRecord Entered successfully";
            obj2.close();
        }
    }
    void shows()
    {
        ifstream obj1("student.txt");
        obj1.seekg(0,ios::end); // points to the end of file
        int length = obj1.tellg();
        if(length==0)
        {
            cout<<"\nThere is no data to display!!"<<endl;
        }
        else
        {
            obj1.seekg(0,ios::beg);
            cout<<"\n----------------------------------\n";
            cout<<"\nStudents Details:-\n";
            while(obj1>>admno && obj1>>name)
            {
                cout<<"\nStudent ID  : "<<admno<<endl;
                cout<<"Student Name: "<<name<<endl;
            }
            cout<<"\n----------------------------------\n";
        }
        obj1.close();
    }
    void search_s(string d)
    {
        int a=0;
        string id=d;
        sread();
        for(int i=0;i<=admn.size()-1;i++)
        {
            if(id==admn[i])
            {
                a++;
                cout<<"\nStudent ID  : "<<admn[i]<<endl;
                cout<<"Student Name: "<<names[i]<<endl;
                break;
            }
        }
        if(a!=1)
        {
            cout<<"\n---Record not Found!!---"<<endl;
            cout<<"Check the Admission number again!!"<<endl;
            admin_menu();
        }
    }
    void modify_s()
    {
        int a=0;
        cout<<"\nEnter Student ID(Admission number): ";
        cin>>adm;
        sread();
        for(int i=0;i<=admn.size()-1;i++)
        {
            if(adm==admn[i])
            {
                cout<<"Now Enter the Name: ";
                cin>>nme;
                names[i]=nme;
                a++;
            }
        }
        if(a==1)
        {
            cout<<"\n---Record Modified!!---"<<endl;
            ofstream obj2("student.txt");
            for(int i=0;i<=admn.size()-1;i++)
            {
                obj2<<admn[i]<<" "<<names[i]<<endl;
            }
            obj2.close();
        }
        else
        {
            cout<<"\n---Record not Found!!---"<<endl;
            cout<<"Enter the correct details...."<<endl;
        }
    }
    void delete_s()
    {
        int a=0,b=0;
        cout<<"\nEnter Student ID(Admission number): ";
        cin>>adm;
        sread();
        for(int i=0;i<=admn.size()-1;i++)
        {
            if(adm==admn[i])
            {
                if(admn.size()==1)
                {
                    ofstream obj2("student.txt",ios::out);
                    b++;
                    cout<<"\n---The Record is deleted!!---"<<endl;
                    obj2.close();
                    break;
                }
                else
                {
                    admn.erase(admn.begin()+i);
                    names.erase(names.begin()+i);
                    a++;
                }
                cout<<"\n---The Record is deleted!!---"<<endl;
                break;
            }
        }
        if(a==1 && b==0)
        {
            ofstream obj2("student.txt");
            for(int i=0;i<=admn.size()-1;i++)
            {
                obj2<<admn[i]<<" "<<names[i]<<endl;
            }
            obj2.close();
        }
        else
        {
            if(b!=1)
            {
                cout<<"\n---Record not Found!!---"<<endl;
                cout<<"Enter the correct details..."<<endl;
            }
        }
    }
};

class book
{
public:
    char bkname[50];
    int bno,quant,id;

    vector<int>ser,quan;
    vector<string>names;

    void bread()
    {
        ifstream obj1("books.txt");
        while(obj1>>bno && obj1>>bkname && obj1>>quant)
        {
            ser.push_back(bno);
            names.push_back(bkname);
            quan.push_back(quant);
        }
        obj1.close();
    }
    void createb()
    {
        int a=0,s,q;
        string n;
        cout<<"\nEnter the details:-\n";
        cout<<"Enter the Serial number of Book: ";
        cin>>s;
        bread();
        for(int i=0;i<ser.size();i++)
        {
            if(s==ser[i])
            {
                cout<<"\n---Book Record already exists with this serial number!!---\n";
                cout<<"Enter a different serial number...\n";
                a++;
            }
        }
        if(a==0)
        {
            cout<<"Enter Book's name: ";
            cin>>n;
            cout<<"Enter Quantity of the book: ";
            cin>>q;
            ofstream obj2("books.txt",ios::app);
            obj2<<endl;
            obj2<<s<<" "<<n<<" "<<q<<endl;
            cout<<"\nRecord Entered Successfully!!";
            obj2.close();
        }
    }
    void showb()
    {
        ifstream obj1("books.txt");
        obj1.seekg(0,ios::end); // points to the end of file
        int length = obj1.tellg();
        if(length==0)
        {
            cout<<"\nThere is no data to display!!"<<endl;
        }
        else
        {
            obj1.seekg(0,ios::beg);
            cout<<"\n----------------------------------\n";
            cout<<"\nBooks Details:-\n";
            while(obj1>>bno && obj1>>bkname && obj1>>quant)
            {
                cout<<"\nSerial No: "<<bno<<endl;
                cout<<"Book Name: "<<bkname<<endl;
                cout<<"Quantity : "<<quant<<endl;
            }
            cout<<"\n----------------------------------\n";
        }
    }
    void search_b()
    {
        int a=0;
        cout<<"Enter serial number: ";
        cin>>id;
        bread();
        for(int i=0;i<=ser.size()-1;i++)
        {
            if(id==ser[i])
            {
                a++;
                cout<<"\nSerial No: "<<ser[i]<<endl;
                cout<<"Book Name: "<<names[i]<<endl;
                cout<<"Quantity : "<<quan[i]<<endl;
                break;
            }
        }
        if(a!=1)
        {
            cout<<"\n---Record not Found!!---"<<endl;
            cout<<"Enter a valid serial number of book...."<<endl;
        }
    }
    void modify_b()
    {
        int a=0,b,c,d=0;
        char n[50];
        cout<<"\nEnter Serial number: ";
        cin>>id;
        bread();
        for(int i=0;i<=ser.size()-1;i++)
        {
            if(id==ser[i])
            {
                cout<<"\nIf you want to Modify Book name enter 1,";
                cout<<" or to Modify Quantity of book enter 2: ";
                cin>>c;
                if(c==1)
                {
                    cout<<"Now Enter the Name of Book: ";
                    cin>>n;
                    names[i]=n;
                    a++;
                }
                else if(c==2)
                {
                    cout<<"Enter Quantity of the book: ";
                    cin>>b;
                    quan[i]=b;
                    a++;
                }
                else
                {
                    cout<<"\nEnter the Correct details..."<<endl;
                    d++;
                }
            }
        }
        if(a==1)
        {
            cout<<"\n---The Data is modified!!---"<<endl;
            ofstream obj2("books.txt");
            for(int i=0;i<=ser.size()-1;i++)
            {
                obj2<<ser[i]<<" "<<names[i]<<" "<<quan[i]<<endl;
            }
            obj2.close();
        }
        else if(a!=1 && d==0)
        {
            cout<<"\n--Record not Found!!--"<<endl;
            cout<<"Enter Correct details...."<<endl;
        }
    }
    void delete_b()
    {
        int a=0,b=0;
        char n[50];
        cout<<"\nEnter Serial number: ";
        cin>>id;
        bread();
        for(int i=0;i<=ser.size()-1;i++)
        {
            if(id==ser[i])
            {
                if(ser.size()==1)
                {
                    ofstream obj2("books.txt",ios::out);
                    cout<<"\n---The Record is deleted!!---"<<endl;
                    b++;
                    obj2.close();
                    break;
                }
                else
                {
                    ser.erase(ser.begin()+i);
                    names.erase(names.begin()+i);
                    quan.erase(quan.begin()+i);
                    cout<<"\n---The Record is deleted!!---"<<endl;
                    a++;
                    break;
                }
            }
        }
        if(a==1 && b==0)
        {
            ofstream obj2("books.txt");
            for(int i=0;i<=ser.size()-1;i++)
            {
                obj2<<ser[i]<<" "<<names[i]<<" "<<quan[i]<<endl;
            }
            obj2.close();
        }
        else
        {
            if(b!=1)
            {
                cout<<"\n---Record not Found!!---"<<endl;
                cout<<"Enter correct details...."<<endl;
            }
        }
    }
};

class data: public book,public student
{
    public:
    int a1,b1,c1,id;
    string adm;
    void book_issue(string aaa)
    {
        string adm=aaa;
        string y;
        cout<<"\n\t\t*-*-*-*-*-* BOOK ISSUE *-*-*-*-*-*\n";
        cout<<"\nNote: You can only Issue 3 books at a time.. ";
        cout<<"\nThe books which are in library will be displayed in prior... \n";
        cout<<"If you want to issue more books make sure you deposit the books you have issued..!!\n";
        int a=0,an,q,b,cc=0,dd=0,ee,o2,o3,o4,o5=0;
        char sn[50],n[50],is[50],o1[50];
        cout<<"\nDo you want to check the books in library? Press (y/Y) to access: ";
        cin>>y;
        if(y=="y" || y=="Y")
        {
            showb(); //display of books
        }
        search_s(adm); //checking id student record is existing
        cout<<"\nEnter Serial number: ";
        cin>>id;

        ifstream obj3("book_issue.txt");
        vector<int>v2,v3,v4;
        vector<string>v1;
        obj3.seekg(0,ios::end); // points to the end of file
        int length = obj3.tellg();
        if(length==0) //checking if file is empty
        {
            cout<<"\nNew user\n";
            ofstream obj2("book_issue.txt",ios::app);
            a1=-1;
            b1=-1;
            c1=-1;
            obj2<<adm<<" "<<a1<<" "<<b1<<" "<<c1<<endl; //at first, keeping the serial numbers as -1, later updating them
            v1.push_back(adm);
            v2.push_back(a1);
            v3.push_back(b1);
            v4.push_back(c1);
            obj2.close();
        }
        else
        {
            obj3.seekg(0,ios::beg); //again pointing the pointer to the beginning
            while(obj3>>o1 && obj3>>o2 && obj3>>o3 && obj3>>o4) //reading file into the vectors
            {
                v1.push_back(o1);
                v2.push_back(o2);
                v3.push_back(o3);
                v4.push_back(o4);
            }
            for(int i=0;i<=v1.size()-1;i++)
            {
                if(v1[i]==adm) //checking if the student already issued books or this is the first time
                {
                    cc++;
                }
            }
            if(cc==0)//if it's the first time
            {
                ofstream obj2("book_issue.txt",ios::app);
                a1=-1;
                b1=-1;
                c1=-1;
                obj2<<adm<<" "<<a1<<" "<<b1<<" "<<c1<<endl; //at first,keeping the serial numbers as -1, later updating them
                v1.push_back(adm);
                v2.push_back(a1);
                v3.push_back(b1);
                v4.push_back(c1);
                obj2.close();
            }
        }
        ifstream obj1("books.txt");
        vector<int>ser,quan;
        vector<string>names;
        while(obj1>>an && obj1>>sn && obj1>>q)
        {
            ser.push_back(an);
            names.push_back(sn);
            quan.push_back(q);
        }
        for(int i=0;i<=ser.size()-1;i++)
        {
            if(id==ser[i])
            {
                if(quan[i]>0) //checking if the book is in stock
                {
                    a++;
                }
                else
                {
                    cout<<"\nThe Book is out of stock!!"<<endl;
                }
            }
        }
        for(int i=0;i<=v1.size()-1;i++)
        {   //to change -1 to serial number of book
            if(adm==v1[i] && a==1) // a==1 means the book is in stock
            {
                if(v2[i]==-1) //if the firat slot is empty
                {
                    v2[i]=id;
                    o5++;
                }
                else if(v3[i]==-1) //if 1st slot is full and 2nd slot is empty
                {
                    v3[i]=id;
                    o5++;
                }
                else if(v4[i]==-1) //if 2nd slot is empty and 3rd slot is empty
                {
                    v4[i]=id;
                    o5++;
                }
                else //if no slot is empty
                {
                    cout<<"\nYour Book Issue limit has Exceeded...."<<endl;
                    cout<<"Deposit a Book before you issuing this one..."<<endl;
                    dd=1;
                }
            }
        }
        if(o5==1) //the serial replaced the -1 in file
        {
            //To change the quantity of the issued book
            for(int i=0;i<=ser.size()-1;i++)
            {
                if(id==ser[i])
                {
                    if(quan[i]>0 && dd==0)
                    {
                        quan[i]--;
                        cout<<"The Book issued Successfully!!!"<<endl;
                        cout<<"\nNote: Write the current date in backside of the book";
                        cout<<"\nShould be submitted within 15 days to avoid fine";
                        cout<<"\nThe fine is Rs. 1 for each day after 15 days period\n";
                    }
                    else
                    {

                        cout<<"\nThe Book is out of stock!!"<<endl;
                    }
                }
            }
            if(a==1)
            {
                ofstream obj2("books.txt");
                for(int i=0;i<=ser.size()-1;i++) //pushing the details into the file, rewriting the whole file everytime
                {
                    obj2<<ser[i]<<" "<<names[i]<<" "<<quan[i]<<endl;
                }
                obj2.close();
            }
        }
        ofstream obj4("book_issue.txt",ios::out);
        for(int i=0;i<=v1.size()-1;i++)
        {
            obj4<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<" "<<v4[i]<<endl; //writing the details into the file
        }
        obj4.close();
    }

    void book_deposit()
    {
        book bb;
        ifstream obj1("book_issue.txt");
        cout<<"\nEnter your admission number: ";
        cin>>adm;
        search_s(adm); //checking id student record is existing
        int o2,o3,o4,i,o5,a=0,z=0,b=0;
        char o1[50];
        vector<string>v1;
        vector<int>v2,v3,v4;
        while(obj1>>o1 && obj1>>o2 && obj1>>o3 && obj1>>o4) //reading file into the vectors
        {
            v1.push_back(o1);
            v2.push_back(o2);
            v3.push_back(o3);
            v4.push_back(o4);
        }
        for(i=0;i<=v1.size()-1;i++)
        {
            if(adm==v1[i])
            {
                if(v2[i]==-1 && v3[i]==-1 && v4[i]==-1)
                {
                    cout<<"\nYou didn't issued any books\n";
                    z++;
                }
                else
                {
                    cout<<"\nThe details of book(s) you issued: ";
                    cout<<"Admission number: "<<v1[i]<<endl;
                    cout<<"Books Issued(Serial Numbers): ";
                    if(v2[i]!=-1)
                    {
                        cout<<v2[i]<<" ";
                        a++;
                    }
                    if(v3[i]!=-1)
                    {
                        cout<<v3[i]<<" ";
                        a++;
                    }
                    if(v4[i]!=-1)
                    {
                        cout<<v4[i]<<" ";
                        a++;
                    }
                    cout<<endl;
                    if(a>0)
                    {
                        cout<<"\nEnter the Serial number of the book you want to deposit: ";
                        cin>>o5;
                        if(o5==v2[i])
                        {
                            v2[i]=-1;
                        }
                        else if(o5==v3[i])
                        {
                            v3[i]=-1;
                        }
                        else if(o5==v4[i])
                        {
                            v4[i]=-1;
                        }
                        else
                        {
                            cout<<"\nEnter the Serial numbers of Book you issued"<<endl;
                            b++;
                        }
                    }
                }
            }
        }
        ifstream obj2("books.txt");
        vector<int>ser,quan;
        vector<string>names;
        int an,q,d;
        string sn;
        while(obj2>>an && obj2>>sn && obj2>>q)
        {
            ser.push_back(an);
            names.push_back(sn);
            quan.push_back(q);
        }
        for(int i=0;i<=ser.size()-1;i++)
        {
            if(o5==ser[i] && a>0 && b==0)
            {
                z++;
                quan[i]++;
                cout<<"Enter after how many days the book is deposited: ";
                cin>>d;
                if(d>0 && d<=15)
                {
                    cout<<"\nYou deposited the book in time successfully!!\n";
                }
                else if(d>15)
                {
                    cout<<"\nYou deposited the book late by "<<d-15<<" day(s)!!";
                    cout<<"\nPay a fine of "<<d-15<<" Rs";
                    cout<<"\nThe book is deposited Successfully!!";
                }
            }
        }
        if(z==0)
        {
            cout<<"\nPlease Enter valid Serial Number of the book!!"<<endl;
        }
        ofstream obj3("books.txt");
        for(int i=0;i<=ser.size()-1;i++) //pushing the details into the file, rewriting the whole file everytime
        {
            obj3<<ser[i]<<" "<<names[i]<<" "<<quan[i]<<endl;
        }
        ofstream obj4("book_issue.txt");
        for(int i=0;i<=v1.size()-1;i++)
        {
            obj4<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<" "<<v4[i]<<endl; //writing the details into the file
        }
        obj4.close();
    }
};

void write_student()
{
    student st;
    st.creates();
    cout<<"\n";
    admin_menu();
}
void write_book()
{
    book bo;
    bo.createb();
    admin_menu();
}
void list_student()
{
    student st;
    st.shows();
    cout<<"\n";
    admin_menu();
}
void list_book()
{
    book bo;
    bo.showb();
    cout<<"\n";
    admin_menu();
}
void search_student()
{
    string zz;
    student st;
    cout<<"\nEnter the Details: \n";
    cout<<"Enter student ID: ";
    cin>>zz;
    st.search_s(zz);
    admin_menu();
}
void search_book()
{
    book bo;
    cout<<"\nEnter the Details: \n";
    bo.search_b();
    admin_menu();
}
void modify_student()
{
    student st;
    st.modify_s();
    admin_menu();
}
void modify_book()
{
    book bo;
    bo.modify_b();
    admin_menu();
}
void delete_student()
{
    student st;
    st.delete_s();
    admin_menu();
}
void delete_book()
{
    book bo;
    bo.delete_b();
    admin_menu();
}

void login_page()
{
    void login(int a);
    void registration(int a);
    int a,c;
    cout<<"\n\t\t*-*-*-*-*-*-* MENU *-*-*-*-*-*-*\n";
    cout<<"\nIf you are Librarian Press 1, or a Student Press 2..."<<endl;
    cout<<"Enter your Choice: ";
    cin>>a;
    if(a==1 || a==2)
    {
        cout<<"\n\nEnter 1 to Login [Old User]\n";
        cout<<"Enter 2 to Register [New User]\n";
        cout<<"Enter 3 to Exit\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
            case 1:
            login(a);
            break;

            case 2:
            registration(a);
            break;

            case 3:
            cout<<"\n_-*-_ THANK YOU _-*-_\n";
            exit(0);
            break;

            default:
            cout<<"\nEnter from the options...\n";
            login_page();
            break;
        }
    }
    else
    {
        cout<<"\nEnter from the options...\n";
        login_page();
    }

}

void registration(int a)
{

    if(a==1)//librarian registration
    {
        string ruser,rpassword;
        cout<<"\nEnter your Username: ";
        cin>>ruser;
        cout<<"Enter the Password: ";
        cin>>rpassword;
        ofstream obj1("librecords.txt",ios::out); //out will rewrite the file everytime
        obj1<<ruser<<"  "<<rpassword<<endl;
        cout<<"\n\nRegistration is Successful\n\n";
        cout<<"\nPress Enter key to continue....";
        getch();
        system("cls");
        obj1.close();
        login_page();
    }
    else if(a==2) //student registration
    {
        string ruser,rpassword;
        cout<<"\nEnter your Username(Roll Number): ";
        cin>>ruser;
        cout<<"Enter the Password: ";
        cin>>rpassword;
        ofstream obj1("sdntrecords.txt",ios::app); //append will add data to the file without clearing prev ones
        obj1<<endl;
        obj1<<ruser<<"  "<<rpassword<<endl;
        cout<<"\n\nRegistration is Successful\n\n";
        cout<<"\nPress Enter key to continue....";
        getch();
        system("cls");
        obj1.close();
        login_page();
    }

}

void login(int a)
{
    string luser,lpassword,id,pass;
    int count1=0;

    if(a==1) //librarian login
    {
        cout<<"\nEnter your Username: ";
        cin>>luser;
        cout<<"Enter the Password : ";
        cin>>lpassword;
        ifstream obj2("librecords.txt");
        while(obj2>>id && obj2>>pass)
        {
            if(luser==id && lpassword==pass)
            {
                count1=1;
            }
        }
        if(count1==1)
        {
            cout<<"\n\nLogin is Successful!!\n\n";
            cout<<"Logging in as Librarian.....\n";
            cout<<"\nNote: The Librarian can have the whole access to book menu and Admin Menu..!!\n";
            count1=0;
        }
        else
        {
            cout<<"\nLogin error...!!!\n";
            login_page();
        }
    }
    else if(a==2) //student login
    {
        cout<<"\nEnter your Username(Roll Number): ";
        cin>>luser;
        cout<<"Enter the Password: ";
        cin>>lpassword;
        ifstream obj2("sdntrecords.txt");
        while(obj2>>id && obj2>>pass)
        {
            if(luser==id && lpassword==pass)
            {
                count1=1;
            }
        }
        if(count1==1)
        {
            cout<<"\n\nLogin is Successful!!\n\n";
            cout<<"Logging in as Student.....\n";
            cout<<"\nThe Student can only have access to book issuing...\n";
            cout<<"\nPress Enter key to continue...";
            getch();
            system("cls");
            data da;
            da.book_issue(luser); //calling book issue function
            count1=0;
            cout<<"\n\t\t_-*-_ THANK YOU _-*-_\n";
            exit(0);
        }
        else
        {
            cout<<"\nLogin error...!!!\n";
            login_page();
        }
    }
}

void main_menu()
{
    int opt1,opt2;
    string adm;
    cout<<"\nPress Enter key to continue...";
    getch();
    system("cls");
    cout<<"--------------------------------------------------"<<endl;
    cout<<"-------------- LIBRARY MANAGEMENT ----------------"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    returning:
    cout<<"\n  *-*-*-*-*-*-*-* MAIN MENU *-*-*-*-*-*-*-*\n";
    cout<<"\n1. Book Menu\n";
    cout<<"2. Administrator menu\n";
    cout<<"3. Exit\n";
    cout<<"Enter option: ";
    cin>>opt1;
    switch(opt1)
    {
        case 1:
        start:
            cout<<"\nPress Enter key to continue...";
            getch();
            system("cls");
            cout<<"  *-*-*-*-* Book Menu *-*-*-*-*\n";
            cout<<"\n1. Book Issue\n";
            cout<<"2. Book Deposit\n";
            cout<<"3. Main Menu\n";
            cout<<"Enter option: ";
            cin>>opt2;
            if(opt2==1)
            {
                data da;
                cout<<"\nEnter the Admission number: ";
                cin>>adm;
                da.book_issue(adm);
                cout<<"\nPress Enter key to continue...";
                getch();
                system("cls");
                goto returning;
            }
            else if(opt2==2)
            {
                data da;
                da.book_deposit();
                cout<<"\nPress Enter key to continue...";
                getch();
                system("cls");
                goto returning;
            }
            else if(opt2==3)
            {
                main_menu();
            }
            else
            {
                cout<<"\nIt's not the right option...\n";
                goto start;
            }
            break;

            case 2:
            admin_menu();
            break;

            case 3:
            cout<<"\n\t\t_-*-_ THANK YOU _-*-_\n";
            exit(0);
            break;

            default:
            main_menu();
            break;
    }
}

int main()
{
    login_page();
    cout<<"\nNote: Admission number and Roll number are the same..!!\n";
    main_menu();
    return 0;
}

void admin_menu()
{
fine:
    int opt1;
    cout<<"\nPress Enter key to continue...";
    getch();
    system("cls");

    cout<<"\n\t*-*-*-*-*-* ADMINISTRATOR MENU *-*-*-*-*-*"<<endl;
    cout<<"\n1. Create Student Record"<<endl;
    cout<<"2. Display All Students Record"<<endl;
    cout<<"3. Display Specific Student Record"<<endl;
    cout<<"4. Modify Student Record"<<endl;
    cout<<"5. Delete Student Record"<<endl;
    cout<<"6. Create Book"<<endl;
    cout<<"7. Display All Books"<<endl;
    cout<<"8. Display Specific Book"<<endl;
    cout<<"9. Modify Book"<<endl;
    cout<<"10. Delete Book"<<endl;
    cout<<"11. Back to Main Menu"<<endl;
    cout<<"Enter your option: ";
    cin>>opt1;
    switch(opt1)
    {
        case 1:
        write_student();
        goto fine;
        break;

        case 2:
        list_student();
        goto fine;
        break;

        case 3:
        search_student();
        goto fine;
        break;

        case 4:
        modify_student();
        goto fine;
        break;

        case 5:
        delete_student();
        goto fine;
        break;

        case 6:
        write_book();
        goto fine;
        break;

        case 7:
        list_book();
        goto fine;
        break;

        case 8:
        search_book();
        goto fine;
        break;

        case 9:
        modify_book();
        goto fine;
        break;

        case 10:
        delete_book();
        goto fine;
        break;

        case 11:
        main_menu();
        break;

        default:
        cout<<"Enter the Correct option..."<<endl;
        goto fine;
        break;
    }
}
