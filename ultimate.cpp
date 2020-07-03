#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;
#define null NULL
class student
{
private:
    int ID;        //学号
    string Name;   //姓名
    int Class;     //班级
    int Math;      //数学成绩
    int Foreign;   //外语成绩
    int IT;        //计算机成绩
    int Total;     //总成绩
    int Average; //平均成绩

    student *next; //节点指针
    friend class operate;

public:
  
    student(int id, string name, int clAss, int math, int foreign, int it)
    {
        ID = id;
        Name = name;
        Class = clAss;
        Math = math;
        Foreign = foreign;
        IT = it;
        Total = Math + Foreign + IT;
        Average = Total / 3;
        next = NULL;
    }
    student()
    {
        Name = "null";
        ID = 0;
        Class = 0;
        Math = 0;
        Foreign = 0;
        IT = 0;
        Total = 0;
        Average = 0;
        next = NULL;
    }
    ~student() {}
    void swap(student *);
};

class operate //学生信息操作
{
private:
    int count;
    student *one;

public:
    operate()
    {
        count = 0;
        one = new student;
    }
    ~operate() { delete one; }
    int desktop(void);
    void desktop2(void);
    void Lockscreen(void);
    void input(void);
    void Show(void);
    void Search(void);
    void Change(void);
    void Add(void);
    void Sort(void);
    void Del(void);
    void Save(void);
    int Exit(void);
};

int operate::desktop(void)
{
    int a;
    cout << "1.Input student information." << endl;
    cout << "2.Show student information." << endl;
    cout << "3.Search student information" << endl;
    cout << "4.Change student information." << endl;
    cout << "5.Add student information." << endl;
    cout << "6.Sort student information." << endl;
    cout << "7.Delete student information." << endl;
    cout << "0.Exit the system." << endl;
    cin >> a;
    return a;
}

void operate::Lockscreen(void)
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "                 ******** Student Management System ********" << endl;
    cout<<"                                V5.1 Ultimate Pro+                " <<endl;
    cout<<endl;
    cout << "                                   Log In                   " << endl;
    
    string c, b;
    for(int f=3;f>0;f--)
    {
        cout << "            User name:";
        cin >> b;
       if ((b == "Ryy") || (b == "ryy"))
        {
              cout << "            Password:";
              cin >> c;
              if (c == "000919")
              {
                   operate::desktop2();
                   break;
              }
              else
              {
                   cout<<"Password Wrong,Please check"<<endl;
              }
        }
      else
        {
        cout<<"            User name is Wrong,Please check! You have ";
        cout<<f-1<<" time left!"<<endl;
         if((f-1)==0)
         {
             system("pause");
             exit(0);
         }
        }
    }
}
void operate::desktop2(void)
{
     
            cout << "\n\n\n\n\n\n";
            cout << "                  *******************Welcome***************************\n";
            cout << "                  ********Student Score Management System**************\n";
            cout << "                  *---------------------------------------------------*\n";
            cout << "                  *      1--Input student information                 *\n";
            cout << "                  *      2--Show student information                  *\n";
            cout << "                  *      3--Search student information                *\n";
            cout << "                  *      4--Change student information                *\n";
            cout << "                  *      5--Add student information                   *\n";
            cout << "                  *      6--Sort student information                  *\n";
            cout << "                  *      7--Delete student information                *\n";
            cout << "                  *      0--Exit the system                           *\n";
            cout << "                  *---------------------------------------------------*\n";
            cout << "                  *------------------*Ultimate Pro+*------------------*\n";
            cout << "                  *-----------v5.1.1 Copyright By RoyRao--------------*\n";
            cout << "                  *----------All Rights Reserved @2020----------------*\n";
            cout << "                     Select(0-7):";
          
}

void operate::input(void) //输入学生信息
{
    string name;
    int id, Class, Math, Foreign, It;
    int n;
    cout<<endl;
    cout<<"           [1]Input Now  [2]Input From a 'Test' txt\n";
    cout<<"           ";
    cin>>n;
    if(n==1)
    { 
        ofstream OutFile("Text2.txt");
    cout << "Please input student information,end with two enter keys." << endl;
    cout << "  ID          Name     Class   Math    Foreign   It " << endl;
   
         for(;;){
             if(cin.peek()=='\n')
             {
                 cin.get();
             }
             if(cin.peek()=='\n')
             {
                 break;
             }
        cin >> id >> name >> Class >> Math >> Foreign >> It;
        OutFile<<endl<<id<<"\t"<<name<<"\t"<<Class<<"\t"<<Math<<"\t"<<Foreign<<"\t"<<It<<endl;
        
        student *NEW = new student(id, name, Class, Math, Foreign, It);

        student *q = one;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = NEW;
        NEW->next = null;
        count++;
    }
    }
    else if(n==2)
    {
          ifstream InFile("Test.txt");
         if(! InFile)
         {
             cout<<"Txt break,Please Check!"<<endl;
             exit(0);
         }
         while(InFile.peek()!=EOF){
             
             if(InFile){
         InFile>>id >> name >> Class >> Math >> Foreign >> It;}
             if(!InFile){
                 break;
             }
         student *NEW =new student(id, name, Class, Math, Foreign, It);
          student *q = one;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = NEW;
        NEW->next = null;
        count++;
         }
         InFile.close();
         cout<<endl;
         cout<<"           Read Test Successfully!"<<endl;
    }
}

void operate::Show(void)
{
    if (count == 0)
    {
        cout << endl;
        cout << "Error! No Student Record! Please Check." << endl;
        cout << endl;
    }
    else
    {
        student *q = one->next;
        cout << endl;
        cout << " ID              Name      Class     Math     Foreign      It    ToTal    Average " << endl;
        while (q != null)
        {
            cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
            q = q->next;
        }
    }
}

void operate::Search(void)
{
    int a;
    cout << endl;
    cout << "   Please choose the way you would like to search the student's information " << endl;
    cout << "      [1] Search By ID               [2] Search By Name" << endl;
    cout << "    ";
    cin >> a;
    if (a == 1)
    {
        int _id, count = 0;
        cout << "Please input the student's ID:";
        cin >> _id;
        student *q = one->next;
        while (q != null)
        {
            if (q->ID == _id)
            {
                count = 1;
                cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
            }
            q = q->next;
        }
        if (count == 0)
        {
            cout << "No Record." << endl;
        }
    }
    if (a == 2)
    {
        string _name;
        int count = 0;
        cout << endl;
        cout << "Please input the student's name:";
        cin >> _name;
        student *q = one->next;
        while (q != null)
        {
            if (q->Name == _name)
            {
                count = 1;
                cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "       " << q->Total << "    " << q->Average << endl;
            }
            q = q->next;
        }
        if (count == 0)
        {
            cout << "No Record." << endl;
        }
    }
}
void operate::Change(void)
{
    int _id, _Class, course = 0;
    string _name;
    int flag = 0, temp;
    int n;
    cout << endl;
    cout << "  [1] Change By ID      [2] Change By Name";
    cout << "  ";
    cin >> n;
    if (n == 1)
    {
        cout << "Please input the student's ID:";
        cin >> _id;
        student *q = one->next;
        while (q != null)
        {
            if (q->ID == _id)
            {
                flag = 1;
                cout << "The student information is:" << endl;
                cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
                cout << "   " << endl;
                cout << "[1] Change ID    [2] Change Name   [3] Change Class  [4] Change Score" << endl;
                cin >> temp;
                switch (temp)
                {
                case 1:
                {
                    cout << "Please input new ID:";
                    cin >> _id;
                    q->ID = _id;
                }
                break;
                case 2:
                {
                    cout << "Please input new Name:";
                    cin >> _name;
                    q->Name = _name;
                }
                break;
                case 3:
                {
                    cout << "Please input new Class:";
                    cin >> _Class;
                    q->Class = _Class;
                }
                break;
                case 4:
                {
                    cout << "[1]Change Math  [2]Change Foreign  [3]Change It" << endl;
                    cin >> course;
                    if (course == 1)
                    {
                        cout << "Please input the new Math score:";
                        cin >> q->Math;
                    }
                    else if (course == 2)
                    {
                        cout << "Please input the new Foreign score:";
                        cin >> q->Foreign;
                    }
                    else if (course == 3)
                    {
                        cout << "Please input the new It score:";
                        cin >> q->IT;
                    }                 
                    else
                    {
                        return;
                    }                   
                }
                break;
                default:
                    cout << "Error,Please Check." << endl;
                    cout << endl;
                }
                    q->Total = q->Math + q->Foreign + q->IT;
                    q->Average = q->Total / 3+0.5;
                    cout << "The student information is:" << endl;
                    cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                    cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
                    cout << endl;
                    cout<<"Stored the new data in Test?"<<endl;
                    cout<<"[1]Yes            [2]No"<<endl;
                    int r;
                    cin>>r;
                    if(r==1)
                    {
                        ofstream openfile("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
                        openfile<<endl<<"Change a student information,the new is below:"<<endl;
                        openfile<<" ID                        Name    Class  Math     Foreign  It      ToTal     Average " << endl;
                        openfile<< q->ID <<"       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "        " << q->IT << "        " << q->Total << "     " << q->Average << endl;
                        openfile<<endl;
                        openfile<<"Now student information is:"<<endl;
                        operate::Save();
                        cout<<"\nStored the new data in Test successfully!\n";
                    }
                    else{
                        return;
                    }

            }
            q = q->next;
        }
        if (flag == 0)
        {
            cout << "No Record!Please Check." << endl;
            cout << endl;
        }
    }

    else if (n == 2)
    {
        cout << "Please input the student's Name:";
        cin >> _name;
        student *q = one->next;
        while (q != null)
        {
            if (q->Name == _name)
            {
                flag = 1;
                cout << "The student information is:" << endl;
                cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
                cout << "   " << endl;
                cout << "[1] Change ID    [2] Change Name   [3] Change Class  [4] Change Score" << endl;
                cin >> temp;
                switch (temp)
                {
                case 1:
                {
                    cout << "Please input new ID:";
                    cin >> _id;
                    q->ID = _id;
                }
                break;
                case 2:
                {
                    cout << "Please input new Name:";
                    cin >> _name;
                    q->Name = _name;
                }
                break;
                case 3:
                {
                    cout << "Please input new Class:";
                    cin >> _Class;
                    q->Class = _Class;
                }
                break;
                case 4:
                {
                    cout << "[1]Change Math  [2]Change Foreign  [3]Change It" << endl;
                    cin >> course;
                    if (course == 1)
                    {
                        cout << "Please input the new Math score:";
                        cin >> q->Math;
                    }
                    else if (course == 2)
                    {
                        cout << "Please input the new Foreign score:";
                        cin >> q->Foreign;
                    }
                    else if (course == 3)
                    {
                        cout << "Please input the new It score:";
                        cin >> q->IT;
                    }
                    else
                    {
                        return;
                    }                 
                }
                break;
                default:
                    cout << "Error,Please Check." << endl;
                }
                    q->Total = q->Math + q->Foreign + q->IT;
                    q->Average = q->Total / 3+0.5;
                    cout << "The student information is:" << endl;
                    cout << " ID              Name      Class     Math     Foreign    It    ToTal    Average " << endl;
                    cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "       " << q->IT << "      " << q->Total << "    " << q->Average << endl;
                     cout<<"Stored the new data in Test?"<<endl;
                    cout<<"[1]Yes            [2]No"<<endl;
                    int z;
                    cin>>z;
                    if(z==1)
                    {
                        ofstream openfile("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
                        openfile<<endl<<"Change a student information,the new is below:"<<endl;
                        openfile<<" ID                        Name    Class  Math     Foreign  It      ToTal     Average " << endl;
                        openfile<< q->ID <<"       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "        " << q->IT << "        " << q->Total << "     " << q->Average << endl;
                        openfile<<endl;
                        openfile<<"Now student information is:"<<endl;
                        operate::Save();
                        cout<<"\nStored the new data in Test successfully!\n";
                    }
                    else
                    {
                        return;
                    }
            }
            q = q->next;

        }
        if (flag == 0)
        {
            cout << "No Record!Please Check." << endl;
        }
    }
}
void operate::Add(void)
{
    string name;
    int id, Class, Math, Foreign, It;
    cout << "*****input student information*****" << endl;
    cout << "  ID          Name     Class   Math    Foreign   It " << endl;
    cin >> id >> name >> Class >> Math >> Foreign >> It;
    student *NEW = new student(id, name, Class, Math, Foreign, It);

    student *q = one;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = NEW;
    NEW->next = null;
    count++;
                    cout<<"Stored the new data in Test?"<<endl;
                    cout<<"[1]Yes            [2]No"<<endl;
                    int e;
                    cin>>e;
                    if(e==1)
                    {
                         while (q->next != NULL)
                            {
                               q = q->next;
                              
                             }
                              q->next = NEW;
                              NEW->next = null;
                        ofstream openfile("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
                        openfile<<endl<<"Add a student information,the new one is below:"<<endl;
                        openfile<<" ID                        Name    Class  Math     Foreign  It      ToTal     Average " << endl;
                        openfile<< q->ID <<"       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "        " << q->IT << "        " << q->Total << "     " << q->Average << endl;
                        openfile<<endl;
                        openfile<<"Now student information is:"<<endl;
                        operate::Save();
                        cout<<"\nAdd the new data in Test successfully!\n";
                    }
                    else{
                        return;
                    }
}

void student::swap(student *p)
{
    string _name;
    int _ID, _math, _foreign, _IT, _total, _class, _average;

    _name = Name;
    Name = p->Name;
    p->Name = _name;

    _class = Class;
    Class = p->Class;
    p->Class = _class;

    _ID = ID;
    ID = p->ID;
    p->ID = _ID;

    _math = Math;
    Math = p->Math;
    p->Math = _math;

    _foreign = Foreign;
    Foreign = p->Foreign;
    p->Foreign = _foreign;

    _IT = IT;
    IT = p->IT;
    p->IT = _IT;

    _total = Total;
    Total = p->Total;
    p->Total = _total;

    _average = Average;
    Average = p->Average;
    p->Average = _average;
}
void operate::Sort(void)
{
    cout << endl;
    cout << "[1]Sort by ID      [2]Sort by Average     [3]Sort by Total " << endl;
    cout << "[4]Sort by Math    [5] Sort by Foreign    [6]Sort by It  " << endl;
    string _name;
    int _class, _ID, _math, _foreign, _IT, _total, _average;
    int n;
    cout << "Select one (1-6):";
    cin >> n;
    int a[6];
    if (n == 1)
    {
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[0];
        if(a[0]==1)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->ID > p->ID)
                {
                    
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        cout<<endl;
        }
        else if(a[0]==2)
        {
             student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->ID <p->ID)
                {
                    
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        cout<<endl;
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }
         
    }
    else if (n == 2)
    {
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[1];
        if(a[1]==1){
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Average > p->Average)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else if(a[1]==2)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Average < p->Average)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }
    }
    else if (n == 3)
    {
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[2];
        if(a[2]==1)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Total > p->Total)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else if(a[2]==2)
        {
            student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Total < p->Total)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }
    }
    else if (n == 4)
    {
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[3];
        if(a[3]==1)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Math > p->Math)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else if(a[3]==2)
        {
            student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Math < p->Math)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }
    }
    else if (n == 5)
    { 
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[4];
        if(a[4]==1)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Foreign > p->Foreign)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else if(a[4]==2)
        {
            student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->Foreign < p->Foreign)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }
    }
    else if (n == 6)
    {
        cout<<"Ascending or Dscending?"<<endl;
        cout<<"[1]Ascending [2]Dscending"<<endl;
        cout<<" ";cin>>a[5];
        if(a[5]==1)
        {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->IT > p->IT)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else if(a[5]==2)
        {
            student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->IT < p->IT)
                {
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
        }
        else
        {
            cout<<"Input Wrong."<<endl;
            system("pause");
            return;
        }

    }
    else
    {
        cout<<"Error,Input Wrong!"<<endl;
        return;
    }
    
    student *q = one->next;
    cout<<endl;
    cout << " ID              Name      Class     Math     Foreign      It        ToTal     Average " << endl;
    while (q != null)
    {
        cout << q->ID << "       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "        " << q->IT << "         " << q->Total << "     " << q->Average << endl;
        q = q->next;
    }
   

    ofstream Outfile("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
    if(n==1){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int m;
        cin>>m;
        if(m==1){
        Outfile<<endl<<endl<<"The new order after sort by ID:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(m==2)
           {
               return;
           }
        }
    if(n==2){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int l;
        cin>>l;
        if(l==1){
        Outfile<<endl<<endl<<"The new order after sort by Average:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(l==2)
           {
               return;
           }
        }
    if(n==3){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int i;
        cin>>i;
        if(i==1){
        Outfile<<endl<<endl<<"The new order after sort by ToTal:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(i==2)
           {
               return;
           }
        }
    if(n==4){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int y;
        cin>>y;
        if(y==1){
        Outfile<<endl<<endl<<"The new order after sort by Math:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(y==2)
           {
               return;
           }
        }
    if(n==5){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int q;
        cin>>q;
        if(q==1){
        Outfile<<endl<<endl<<"The new order after sort by Foreign:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(q==2)
           {
               return;
           }
        }
    if(n==6){
        cout<<endl;
        cout<<"Stored the result in Test?"<<endl;
        cout<<"[1]Yes         [2]No"<<endl;
        int s;
        cin>>s;
        if(s==1){
        Outfile<<endl<<endl<<"The new order after sort by IT:"<<endl;
        operate::Save();
        cout<<"\nThe result are stored in Test successfully!\n";
                }
           else if(s==2)
           {
               return;
           }
        }  
    cout << endl;
}
void operate::Del(void)
{
    int a[1000]={0};
    cout << endl;
    cout<<"Please input the number you will delete,Notice!There are ";
    cout<<count<<" students data in the system:";
    int i;
    cin>>i;
    cout << "Please input  student's ID you will delete,space by space:";
    int n;
   for(n=0;n<i;n++)
    {       
       cin>>a[n];
    student *p = one;
    student *q = null;
    while (p)
    {
        if (p->ID == a[n])
            break;
        q = p;
        p = p->next;
    }
    if (!p)
    {
        cout << endl;
        cout << "No Student Record.Please Check." << endl;
        cout << endl;
       
    }
    if (!q)
    {
        cout << endl;
        one = one->next;
        cout << "Delete" << a[n] << "Successfully." << endl;
        ofstream open("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
        open<<"You delele a student's data successuflly.The student id is"<<a[n]<<endl;
        cout << endl;
        delete p;
    }
    else
    {
        cout << endl;
        q->next = p->next;
        cout << "Delete " << a[n] << " Successfully." << endl;
         ofstream open("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
        open<<"You delele a student's data successuflly.The student id is"<<a[n]<<endl;
        cout << endl;
        delete p;
    }
    count--;
    }
       ofstream open("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
       open<<"Now the data is:\n";
       operate::Save();
}

void operate::Save(void)
{
    ofstream outfile("C:\\Users\\Ryy\\Student-Management-System\\Test.txt",ios::app);
     student *q = one->next;
     outfile<<" ID                        Name    Class  Math     Foreign  It      ToTal     Average " << endl;
    while (q != null)
    {   
        outfile<< q->ID <<"       " << q->Name << "     " << q->Class << "        " << q->Math << "           " << q->Foreign << "        " << q->IT << "        " << q->Total << "     " << q->Average << endl;
        q = q->next;
    }
}

int operate::Exit(void)
{
    cout << endl;
    cout << "   Exit the system?    " << endl;
    cout << "   [1]Yes     [2]No    " << endl;
    cout << "  ";
    int n;
    cin >> n;
    if (n == 1)
    {
        exit(0);
    }
    else if (n == 2)
    {
        return n;
    }
    return n;
}

int main()
{
    operate Ryy;
    Ryy.Lockscreen();  
            int m;
            cout<<"";
            cin >> m;
            if (m == 0)
            {
                Ryy.Exit();
            }
            else if (m == 1)
            {
                Ryy.input();
            }
            else if (m == 2)
            {
                Ryy.Show();
            }
            else if (m == 3)
            {
                Ryy.Search();
            }
            else if (m == 4)
            {
                Ryy.Change();
            }
            else if (m == 5)
            {
                Ryy.Add();
            }
            else if (m == 6)
            {
                Ryy.Sort();
            }
            else if (m == 7)
            {
                Ryy.Del();
            }
            else
            {
                cout << "Input Error.Please Check.";
                return 1;
            }

            int a;
            while (a = Ryy.desktop())
            {
                switch (a)
                {
                case 1:
                    Ryy.input();
                    break;
                case 2:
                    Ryy.Show();
                    break;
                case 3:
                    Ryy.Search();
                    break;
                case 4:
                    Ryy.Change();
                    break;
                case 5:
                    Ryy.Add();
                    break;
                case 6:
                    Ryy.Sort();
                    break;
                case 7:
                    Ryy.Del();
                    break;
                case 0:
                    Ryy.Exit();
                    break;
                default:
                    cout << "Error..Please input in rules" << endl;
                }
            }
    system("pause");
    return 0;
}