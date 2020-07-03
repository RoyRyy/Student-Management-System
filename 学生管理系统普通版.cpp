
#include <iostream>
#include <windows.h>
#include <string>
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
    float Average; //平均成绩

    student *next; //节点指针
    friend class operate;

public:
    int Get_Class();
    int Get_Math();
    int Get_Foreign();
    int Get_IT();
    int Get_Total();
    student(int id, string name, int clAss, int math, int foreign, int it)
    {
        ID = id;
        Name = name;
        Class = clAss;
        Math = math;
        Foreign = foreign;
        IT = it;
        Total = Math + Foreign + IT;
        Average = Total / 3.0;
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
    void input(void);
    void Show(void);
    void Search(void);
    void Change(void);
    void Add(void);
    void Sort(void);
    void Del(void);
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

void operate::input(void) //输入学生信息
{
    string name;
    int id, Class, Math, Foreign, It;
    int n, i;
    cout << "Please input the number of students:";
    cin >> n;
    cout << "*****input student information*****" << endl;
    cout << "ID          Name     Class   Math    Foreign   It " << endl;
    for (i = 0; i < n; i++)
    {
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
    }
}

void operate::Show(void)
{
    if (count == 0)
    {
        cout << "Error! No Student Record! Please Check." << endl;
        cout << endl;
    }
    else
    {
        student *q = one->next;
        cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average " << endl;
        while (q != null)
        {
            cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
            q = q->next;
        }
    }
}

void operate::Search(void)
{
    int a;
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
                cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
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
        cout << "Please input the student's name:";
        cin >> _name;
        student *q = one->next;
        while (q != null)
        {
            if (q->Name == _name)
            {
                count = 1;
                cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
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
                cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
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

                    q->Total = q->Math + q->Foreign + q->IT;
                    q->Average = q->Total / 3;
                    cout << "The fixed information is below: " << endl;
                    cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                    cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
                }
                break;
                default:
                    cout << "Error,Please Check." << endl;
                }
            }
            q = q->next;
        }
        if (flag == 0)
        {
            cout << "No Record!Please Check." << endl;
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
                cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
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

                    q->Total = q->Math + q->Foreign + q->IT;
                    q->Average = q->Total / 3;
                    cout << "The fixed information is below: " << endl;
                    cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average" << endl;
                    cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
                }
                break;
                default:
                    cout << "Error,Please Check." << endl;
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
    cout << "ID          Name     Class   Math    Foreign   It " << endl;
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
    cout << "[1]Sort by ID      [2]Sort by Average     [3]Sort by Total " << endl;
    cout << "[4]Sort by Math    [5] Sort by Foreign    [6]Sort by It  " << endl;
    string _name;
    int _class, _ID, _math, _foreign, _IT, _total, _average;
    int n;
    cin >> n;
    if (n == 1)
    {
        student *q = one->next;
        while (q->next != null)
        {
            student *p = q->next;
            while (p != null)
            {
                if (q->ID > p->ID)
                {
                    // _ID=q->ID;
                    //q->ID=p->ID;
                    //p->ID=_ID;
                    q->swap(p);
                }
                p = p->next;
            }
            q = q->next;
        }
    }
    else if (n == 2)
    {
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
    else if (n == 3)
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
    else if (n == 4)
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
    else if (n == 5)
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
    else if (n == 6)
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
    student *q = one->next;
    cout << "ID          Name      Class   Math    Foreign   It   ToTal  Average " << endl;
    while (q != null)
    {
        cout << q->ID << "      " << q->Name << "    " << q->Class << "   " << q->Math << "   " << q->Foreign << "   " << q->IT << "   " << q->Total << "   " << q->Average << endl;
        q = q->next;
    }
    cout << endl;
}
void operate::Del(void)
{
    int a;
    cout << endl;
    cout << "Please input the student's ID you will delete:";
    cin >> a;
    student *p = one;
    student *q = null;
    while (p)
    {
        if (p->ID == a)
            break;
        q = p;
        p = p->next;
    }
    if (!p)
    {
        cout << endl;
        cout << "No Student Record.Please Check." << endl;
        return;
    }
    if (!q)
    {
        cout << endl;
        one = one->next;
        cout << "Delete" << a << "Successfully." << endl;
        delete p;
    }
    else
    {
        q->next = p->next;
        cout << "Delete " << a << " Successfully." << endl;
        delete p;
    }
    count--;
}

int operate::Exit(void)
{
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
    int m;
    cout << "\n\n\n\n\n\n";
    cout << "                   *******************Welcome***************************\n";
    cout << "                   ********Student Score Management System**************\n";
    cout << "                   *---------------------------------------------------*\n";
    cout << "                   *     1--Input student information                  *\n";
    cout << "                   *     2--Show student information                   *\n";
    cout << "                   *     3--Search student information                 *\n";
    cout << "                   *     4--Change student information                 *\n";
    cout << "                   *     5--Add student information                    *\n";
    cout << "                   *     6--Sort student information                   *\n";
    cout << "                   *     7--Delete student information                 *\n";
    cout << "                   *     0--Exit the system                            *\n";
    cout << "                   *---------------------------------------------------*\n";
    cout << "                   *---------------Home Edition------------------------*\n";
    cout << "                   *----------v1.2.0 Copyright By RoyRao 2020----------*\n";
    cout << "                   *------------All Rights Reserved--------------------*\n";
    cout << "                      Select(0-7):";
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