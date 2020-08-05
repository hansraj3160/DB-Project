#include <iostream>
#include<conio.h>
#include<cstdio>
#include<windows.h>
#include<mysql.h>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<string>
#include<stdio.h>
#include<iomanip>

using namespace std;
void student_enrroll();
void students();
void fee_status();
void Search();
struct admin
	{
	void admin_x()
	{

    system("cls");
	string name,pass,u_name,password;
   cout<<"Welcome to admin panel"<<endl;
    cout<<"Eneter User name "<<endl;
    cin>>u_name;
    cout<<"Enter Password "<<endl;
    cin>>password;
    MYSQL* conn;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
    MYSQL_ROW row;//get value from the table
    MYSQL_RES* res;
    if(conn)
    {
        int qstate=mysql_query(conn,"select user_name,password from admin");
            if(!qstate)
         {
          res=mysql_store_result(conn);
        while(row=mysql_fetch_row(res))
        {
           name=row[0];//user_name
           pass=row[1];//password
        }
       }
       else
        cout<<"Not qstate"<<endl;
    }
    else
        cout<<"Not connect"<<endl;
    if(u_name==name && password==pass)
    {
        system("cls");
        int option;
    	cout<<"Enter 1 for Student "<<endl;
    	cout<<"Enter 2 for course "<<endl;
    	cout<<"Enter 3 for department "<<endl;
    	cout<<"Enter 4 for fee "<<endl;
    	cin>>option;
    	switch(option)
    	{
        case 1:
            system("cls");
            cout<<"Enter 1 for add student "<<endl;
            cout<<"Enter 2 for search Student "<<endl;
            cout<<"Enter 3 for Show Student details "<<endl;
            cout<<"Enter 4 for Student Enrollment "<<endl;
            cout<<"Enter 5 for update student detail"<<endl;
            cout<<"Enter 6 for remove student "<<endl;
            int studt;
            cin>>studt;
            if(studt==1)
            add_student();
            else if(studt==2)
                Search();
            else if(studt==3)
                students();
            else if(studt==4)
                student_enrroll();
            else if(studt==5)
                update();
            else if(studt==6)
               removeStd();
            else
                cout<<"Enter invalid "<<endl;
            break;
        case 2:
             system("cls");
            cout<<"Enter 1 for add course "<<endl;
            cout<<"Enter 2 for update course detail"<<endl;
            cout<<"Enter 3 for remove course "<<endl;
            int cors;
            cin>>cors;
            if(cors==1)
            course();
            else if(cors==2)
                updatecourse();
            else if(cors==3)
                removecourse();
            else
                cout<<"Enter invalid "<<endl;
            break;
        case 3:
             system("cls");
             cout<<"Enter 1 for add Department "<<endl;
            cout<<"Enter 2 for remove department "<<endl;
            int dpt;
            cin>>dpt;
            if(dpt==1)
            Add_department();
            else if(dpt==2)
                removedpt();
            else
                cout<<"Enter invalid "<<endl;
            break;
        case 4:
         system("cls");
             cout<<"Enter 1 for add Fees "<<endl;
            cout<<"Enter 2 for check fees status "<<endl;
            int fe;
            cin>>fe;
            if(fe==1)
            addfees();
            else if(fe==2)
               fee_status();
            else
                cout<<"Enter invalid "<<endl;
            break;
        default:
            cout<<"Invalid Enter "<<endl;
            char xz;
            cout<<"Enter B for back menu"<<endl;
            cin>>xz;
            if(xz=='B'||xz=='b')
                admin_x();

    	}
	}
	else
        cout<<"connection fail"<<endl;
	}
	void add_student()
	{
	     system("cls");
	   MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0,ID,dep_ID,age;
         string phone, fname,lname,dep_name,email;
         string address;
         cout<<"Enter First name "<<endl;
         cin>>fname;
         cout<<"Enter Last Name "<<endl;
         cin>>lname;
         cout<<"Enter Department ID "<<endl;
         cin>>dep_ID;
         cout<<"Enter age "<<endl;
         cin>>age;
         cout<<"Enter phone number"<<endl;
         cin>>phone;
         cin.ignore(1, '\n');
         cout<<"Enter city Name "<<endl;
         getline(cin,address);
         cout<<"Enter Email address "<<endl;
         cin>>email;
         stringstream ss;
         ss<<"INSERT INTO student(fname,lname,dep_ID,age,phone,email,address) values('"<<fname<<"','"<<lname<<"','"<<dep_ID<<"','"<<age<<"','"<<phone<<"','"<<email<<"','"<<address<<"')";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
            {cout<<"Record inserted "<<endl;}
        else
            cout<<"Insert error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
	}
	void  update()

	{
        system("cls");
	   MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0;
         string phone, fname,lname,dep_name,email,ID,dep_ID,age;
         string address;
         cout<<"Enter Student ID "<<endl;
         cin>>ID;
          cout<<"Enter First name "<<endl;
         cin>>fname;
         cout<<"Enter Last Name "<<endl;
         cin>>lname;
         cout<<"Enter Department ID "<<endl;
         cin>>dep_ID;
         cout<<"Enter age "<<endl;
         cin>>age;
         cout<<"Enter phone number"<<endl;
         cin>>phone;
         cin.ignore(1, '\n');
         cout<<"Enter city Name "<<endl;
         getline(cin,address);
         cout<<"Enter Email address "<<endl;
         cin>>email;
         stringstream ss;
         ss<<"update student set fname = '"+fname+"', lname = '"+lname+"', dep_ID= '"+dep_ID+"', age= '"+age+"',phone= '"+phone+"',address = '"+address+"',email= '"+email+ "' where ID= '"+ID+"'";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
            {cout<<"Record inserted "<<endl;}
        else
            cout<<"Insert error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
	}
	void  removeStd()
	{
	     system("cls");
	   MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0;
         int ID;
         cout<<"Enter Student ID "<<endl;
         cin>>ID;
         stringstream ss;
         ss<<"Delete from student where ID = '"<<ID<<"'";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(!qstate)
            {cout<<"Record Delete"<<endl;}
        else
            cout<<"Delete error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
	}
	void course()
	{
	     system("cls");
          MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0,inst_ID,dep_ID;
        float credit;
         string title,instName;
         cin.ignore(1,'\n');
         cout<<"Enter course title "<<endl;
         getline(cin,title);
         cout<<"Enter credit hours"<<endl;
         cin>>credit;
         cout<<"Enter Instructor ID "<<endl;
         cin>>inst_ID;
         cout<<"Enter department ID"<<endl;
         cin>>dep_ID;
          stringstream ss;
         ss<<"INSERT INTO course(title,credit,inst_ID,dep_ID) values('"<<title<<"','"<<credit<<"','"<<inst_ID<<"','"<<dep_ID<<"')";
           string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
            {cout<<"Record inserted "<<endl;}
        else
            cout<<"Insert error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
            }
void updatecourse()
{
      system("cls");
     MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0,courseID;

         string title,credit,inst_ID,dep_ID;
         cout<<"Enter course ID "<<endl;
         cin>>courseID;
         cin.ignore(1,'\n');
         cout<<"Enter course title "<<endl;
         getline(cin,title);
        cout<<"Enter credit hours"<<endl;
         cin>>credit;
         cout<<"Enter Instructor ID "<<endl;
         cin>>inst_ID;
         cout<<"Enter department ID"<<endl;
         cin>>dep_ID;
          stringstream ss;
         ss<<"update course set title = '"+title+"', credit = '"+credit+"', inst_ID= '"+inst_ID+"', dep_ID= '"+dep_ID+"' where courseID= '"<<courseID<<"'";
           string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(!qstate)
            {cout<<"Record update "<<endl;}
        else
            cout<<"update error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
}
void  removecourse()
	{
	     system("cls");
	   MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0;
         int courseID;
         cout<<"Enter course ID "<<endl;
         cin>>courseID;
         stringstream ss;
         ss<<"Delete from course where courseID = '"<<courseID<<"'";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(!qstate)
            {cout<<"Record Delete"<<endl;}
        else
            cout<<"Delete error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
	}
	void Add_department()
	{      system("cls");
          MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0,departmentid;
         string dep_name;
         cout<<"Enter department name "<<endl;
         cin>>dep_name;
           stringstream ss;
         ss<<"INSERT INTO department(dep_name) values('"<<dep_name<<"')";
           string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
            {cout<<"Record inserted "<<endl;}
        else
            cout<<"Insert error"<<endl;
        }
        else
            cout<<"Not connect database "<<endl;
	}
		void  removedpt()
	{
	     system("cls");
	   MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0;
         int dep_ID;
         cout<<"Enter Department ID "<<endl;
         cin>>dep_ID;
         stringstream ss;
         ss<<"Delete from department where dep_ID = '"<<dep_ID<<"'";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(!qstate)
            {cout<<"Record Delete"<<endl;}
        else
            cout<<"Delete error"<<endl;
	 }
	else
        cout<<"Not connected"<<endl;
	}
	void addfees()
	{
	    system("cls");
	    MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		if(conn)
        {
         int qstate=0,tutionfee,LibraryFees,SECURITYFees,total,S_id;
         bool status=false;
         cout<<"Enter Rs.10000 tution fees"<<endl;
         cin>>tutionfee;
         cout<<"Enter Rs.500 Library Fees"<<endl;
         cin>>LibraryFees;
         cout<<"Enter Rs.200 Security Fees"<<endl;
         cin>>SECURITYFees;
         cout<<"Enter Student ID "<<endl;
         cin>>S_id;
         total=tutionfee+LibraryFees+SECURITYFees;
         if(total==10700)
            status=true;
         stringstream ss;
         ss<<"Insert Into fees(tutionfee,LibraryFees,SECURITYFees,total,S_ID,status) values('"<<tutionfee<<"','"<<LibraryFees<<"','"<<SECURITYFees<<"','"<<total<<"','"<<S_id<<"','"<<status<<"')";
         string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0)
            {cout<<"Record inserted "<<endl;}
        else
            cout<<"Insert error"<<endl;
        }
	    else
       cout<<"Not connected"<<endl;
		}



	};
	void Search()
	{
	 system("cls");
	    MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		 MYSQL_ROW row;//get value from the table
        MYSQL_RES* res;
		if(conn)
        {
            string ID;
            cout<<"Enter Student ID "<<endl;
            cin>>ID;
            string findquery="select s.ID,s.fname,s.lname, d.dep_name,s.phone,s.email,s.address from student s inner join department d using(dep_ID) where ID='"+ID+"'";
            const  char* q=findquery.c_str();
            int qstate=mysql_query(conn,q);
            if(!qstate)
         {
          res=mysql_store_result(conn);
          while(row=mysql_fetch_row(res))
          {
             cout<<setw(4)<<row[0]<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(30)<<row[3]<<setw(30)<<row[4]<<setw(28)<<row[5]<<setw(20)<<row[6]<<endl;

          }
         }
         else
        cout<<"Query Not work"<<endl;

        }
        else
            cout<<"Database Not connected"<<endl;


   }
   void fee_status()
   {
        system("cls");
	    MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
		 MYSQL_ROW row;//get value from the table
        MYSQL_RES* res;
		if(conn)
        {
            bool check=false;
            string S_ID;
            cout<<"Enter Student ID "<<endl;
            cin>>S_ID;
            string findquery="select status from fees where S_ID= '"+S_ID+"'";
            const  char* q=findquery.c_str();
            int qstate=mysql_query(conn,q);
            if(!qstate)
         {
          res=mysql_store_result(conn);
          cout<<"Status"<<endl;
          while(row=mysql_fetch_row(res))
          {
           check=row[0];
               cout<<row[0]<<endl;
           }

          }
         else
        cout<<"Query Not work"<<endl;

        }
        else
            cout<<"Database Not connected"<<endl;


   }

		void student_portal()
	{
	    system("cls");
	    cout<<"welcome to Student Portal "<<endl;
         string userName,name,Password,pass;
         bool flag=false;
	     MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
        MYSQL_ROW row;//get value from the table
        MYSQL_RES* res;
		if(conn)
        {
            cout<<"Enter User name "<<endl;
            cin>>userName;//fname+ID
            cout<<"Enter Password "<<endl;
            cin>>Password;//lastName
            int qstate=mysql_query(conn,"select user_name,PASSWORD from studentlogin");
            if(!qstate)
          {
          res=mysql_store_result(conn);
        while(row=mysql_fetch_row(res))
        {
           name=row[0];
           pass=row[1];
        if(userName==name && Password==pass)
        {
            flag=true;
            break;
        }
        }
       }
       else
        cout<<"Not qstate"<<endl;
    }
    else
        cout<<"Not connect"<<endl;
     if(flag)
    {
        system("cls");
        int option;
    	cout<<"Enter 1 for Student detail "<<endl;
    	cout<<"Enter 2 for Student Enrollment  "<<endl;
    	cout<<"Enter 3 for checkfee "<<endl;
        cin>>option;
    	switch(option)
    	{
        case 1:
            students();
            break;
        case 2:
           student_enrroll();
            break;
        case 3:
            fee_status();
            break;

        default:
            cout<<"Invalid Enter "<<endl;
            char xz;
            cout<<"Enter B for back menu"<<endl;
            cin>>xz;
            if(xz=='B'||xz=='b')
               student_portal();
    	}
    }

	}
	void students()
	{
	    system("cls");
        string S_Firstname,S_Lname,S_id,S_Email,S_Phone,S_Fname,S_FLname,S_program;
        MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
        MYSQL_ROW row;//get value from the table
        MYSQL_RES* res;
		if(conn)
        {
            int qstate=mysql_query(conn,"select s.ID,s.fname,s.lname, d.dep_name,s.phone,s.email,s.address from student s inner join department d using(dep_ID)");
            if(!qstate)
         {
          res=mysql_store_result(conn);
         cout<<setw(4)<<"ID"<<setw(15)<<"Fname"<<setw(10)<< "LName "<<setw(30)<<" Deparment "<<setw(30)<<" Phone "<<setw(28)<<" Email "<<setw(20)<<" Address "<<endl;

          while(row=mysql_fetch_row(res))
          {
         cout<<setw(4)<<row[0]<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(30)<<row[3]<<setw(30)<<row[4]<<setw(28)<<row[5]<<setw(20)<<row[6]<<endl;
           }
       }
         else
        cout<<"Query Not work"<<endl;

        }
        else
            cout<<"Database Not connected"<<endl;

	}
	void student_enrroll()
	{
	    system("cls");
	    MYSQL* conn;
        conn=mysql_init(0);
        conn=mysql_real_connect(conn,"192.168.137.1","admin","admin","ums",0,NULL,0);
        MYSQL_ROW row;//get value from the table
        MYSQL_RES* res;
		if(conn)
        {
         int qstate=mysql_query(conn,"select e.enroll_id,s.fname,s.lname,s.ID,c.title,c.credit,d.dep_name from enrollment e inner join student s on s.ID=e.ID inner join course c on c.courseId=e.courseID inner join department d on d.dep_ID=c.dep_ID");
;
            if(!qstate)
         {
          res=mysql_store_result(conn);
         cout<<setw(4)<<"enroll_ID"<<setw(12)<<"Fname"<<setw(10)<< "LName "<<setw(10)<<" ID "<<setw(25)<<" Title"<<setw(13)<<" credit "<<setw(20)<<" Department "<<endl;

          while(row=mysql_fetch_row(res))
          {
         cout<<setw(4)<<row[0]<<setw(15)<<row[1]<<setw(10)<<row[2]<<setw(10)<<row[3]<<setw(30)<<row[4]<<setw(8)<<row[5]<<setw(25)<<row[6]<<endl;
           }
       }
         else
        cout<<"Query Not work"<<endl;


        }
        else
            cout<<"Not connected"<<endl;

	}

int main()
{
	admin obj;
    int forever=1;
    while(forever==1)
    {
    cout<<endl<<endl<<endl;
    cout<<"Enter 1 for admin panel"<<endl;
    cout<<"Enter 2 for Student Portal \nEnter 3 for exit"<<endl;
    int choise;
    cin>>choise;
    switch(choise)
    {
    case 1:
        obj.admin_x();
        break;
    case 2:
        student_portal();
        break;
    case 3:
        forever=3;
        cout<<"Program terminate"<<endl;
        break;
    default:
        cout<<"invalid enter \nplease reEnter "<<endl;
        cin>>choise;

    }
    }

    return 0;
}
