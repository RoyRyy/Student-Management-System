#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<fstream>
#include<iomanip>
using namespace std;
int order;
class Student
{
    private:
    string Name;
    string Id;
    int Classnum;
    long long Idnum;
    double Math;
    double English;
    double computer;
    double Sum;
    double Average;
    Student *nxt;
    public:
void ShowMenu()
{
    puts("*********************************Welcome to************************************\n");
    puts("***********************Student achievement management system*******************\n");
    puts("--------------------------------------------------------------------------\n");
    puts("*                      1.Input student information                       *\n");
    puts("*                      2.Display student information                     *\n");
    puts("*                      3.Query student information                       *\n");
    puts("*                      4.Modify student information                      *\n");
    puts("*                      5.Add student information                         *\n");
    puts("*                      6.Sort student information                        *\n");
    puts("*                      7.Delete student information                      *\n");
    puts("*                      0.Exit the system                                 *\n");
    puts("*------------------------------------------------------------------------*\n");
    puts("The command you are going to execute is（0—7）：");
}

void ExitSystem()
{
    puts("\n\n\n           *****************************************");
    puts("                               Thank you for your use！          ");
    puts("                 **************************************\n\n\n");
    exit(0);
}

void InputError()
{
    puts("\n               ******************************************************************");
    puts("                      The command you entered is incorrect. Please re-enter it。   ");
    puts("                 ******************************************************************\n");
}
void Add()
{
    puts("                 ***************************************************");
    puts("                                Input student information           ");
    puts("                 --------------------------------------");
    puts("                               Please input student information          ");
    puts("                 ***************************************************\n");
    char x = 'Y';
    ofstream fout("data.txt", ios::app);
    if (!fout)
    {
        puts("File open failed！");
        exit(0);
    }
    Student *nw;
    nw =  new Student;
    while (x == 'Y' || x == 'y')
    {
        printf("Please input student number：");
        cin >> nw->Id;
        printf("Please input student name：");
        cin >> nw->Name;
        printf("Please input class：");
        cin >> nw->Classnum;
        printf("Please input math score：");
        cin >> nw->Math;
        while (nw->Math < 0 || nw->Math > 100)
        {
            puts("The data you entered is illegal, please re-enter");
            cin >> nw->Math;
        }
        printf("Please enter your English score：");
        cin >> nw->English;
        while (nw->English < 0 || nw->English > 100)
        {
            puts("The data you entered is illegal, please re-enter");
            cin >> nw->English;
        }
        printf("Please input computer grade：");
        cin >> nw->computer;
        while (nw->computer < 0 || nw->computer > 100)
        {
            puts("The data you entered is illegal, please re-enter");
            cin >> nw->computer;
        }
        nw->Sum = (nw->Math) + (nw->English) + (nw->computer);
        nw->Average = (nw->Sum) / 3;
        fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
             << nw->Sum << " " << nw->Average << endl;
        printf("Student information added successfully！\n");
        puts("Do you want to continue adding？(Y/N)");
        cin >> x;
    }
    fout.close();
}

void Display()
{
    ifstream fin("data.txt");
    if (!fin)
    {
        puts("File open failed！");
        exit(0);
    }
    puts("*******************************************************");
    puts("                    All student information           ");
    puts("*******************************************************\n");
    cout << "Serial number\tStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
    Student *nw;
    nw =  new Student;
    int cnt = 0;
    while (fin >> nw->Id >> nw->Name >> nw->Classnum >> nw->Math >> nw->English >> nw->computer >> nw->Sum >> nw->Average)
    {
        cnt++;
        cout << left << setw(16) << cnt
             << left << setw(16) << nw->Id
             << left << setw(10) << nw->Name
             << left << setw(8) << nw->Classnum
             << left << setw(16) << nw->Math
             << left << setw(16) << nw->English
             << left << setw(16) << nw->computer
             << left << setw(16) << nw->Sum
             << setw(2) << nw->Average
             << endl;
    }
    fin.close();
}
void Mend()
{
    char x = 'Y';
    string tmp;
    puts("*******************************************************");
    puts("                    Modify student information           ");
    puts("*******************************************************\n");

    while (x == 'Y' || x == 'y')
    {
        ifstream fin("data.txt", ios::app);
        ofstream fout("data2.txt", ios::app);
        if (!fin)
        {
            puts("File open failed！");
            exit(0);
        }
        if (!fout)
        {
            puts("File open failed！");
            exit(0);
        }

        puts("         Please search for students according to the following keywords：");
        puts("-----------------------------------------------------------------------------");
        puts("            1.Name\n");
        puts("            2.Student number\n");
        puts("            0.Return to the previous menu");
        printf("Command：");
        scanf("%d", &order);
        while ((order < 0) || (order > 2))
        {
            puts("");
            InputError();
            puts("       Please search for students according to the following keywords：");
            puts("-------------------------------------------------------------------------");
            puts("            1.Name\n");
            puts("            2.Student number\n");
            puts("            0.Return to the previous menu");
            printf("Command：");
            scanf("%d", &order);
        }
        if (order == 0)
            return;

        if (order == 1)
        {
            printf("Please enter Name：");
            cin >> tmp;
        }
        else if (order == 2)
        {
            printf("Please enter Student number：");
            cin >> tmp;
        }

        Student *nw;
        nw =  new Student;
        bool isFind = false;
        while (fin >> nw->Id >> nw->Name >> nw->Classnum >> nw->Math >> nw->English >> nw->computer >> nw->Sum >> nw->Average)
        {
            if ((tmp.compare(nw->Name)) && (tmp.compare(nw->Id)))
            {
                fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                     << nw->Sum << " " << nw->Average << endl;
                continue;
            }
            isFind = true;

            cout << "\nStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
            cout << left << setw(16) << nw->Id
                 << left << setw(10) << nw->Name
                 << left << setw(8) << nw->Classnum
                 << left << setw(16) << nw->Math
                 << left << setw(16) << nw->English
                 << left << setw(16) << nw->computer
                 << left << setw(16) << nw->Sum
                 << setw(2) << nw->Average
                 << endl;
            puts("\n         Please select to modify student information style：");
            puts("----------------------------------------------------------------");
            puts("            1.Name\n");
            puts("            2.Student number\n");
            puts("            3.Math score\n");
            puts("            4.English score\n");
            puts("            5.Computer score\n");
            puts("            6.Class\n");
            puts("            0.Return to the previous menu");
            printf("Command：");
            scanf("%d", &order);
            while ((order < 0) || (order > 6))
            {
                InputError();
                puts("\n         Please select to Modify student information style：");
                puts("---------------------------------------------------------------");
                puts("            1.Name\n");
                puts("            2.Student number\n");
                puts("            3.Math score\n");
                puts("            4.English score\n");
                puts("            5.Computer score\n");
                puts("            6.Class\n");
                puts("            0.Return to the previous menu");
                printf("Command：");
                scanf("%d", &order);
            }

            if (order == 0)
                return;

            if (order == 1)
            {
                string NewName;
                printf("Please enter new Name：");
                cin >> NewName;
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    fout << nw->Id << " " << NewName << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
            else if (order == 2)
            {
                string NewId;
                printf("Please enter new Student number：");
                cin >> NewId;
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    fout << NewId << " " << nw->Name << " " << nw->Classnum<<" " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
            else if (order == 3)
            {
                double NewMath;
                printf("Please enter new Math score：");
                cin >> NewMath;
                while (NewMath < 0 || NewMath > 100)
                {
                    puts("The data you entered is illegal. Please re-enter it");
                    cin >> NewMath;
                }
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    nw->Sum = NewMath + nw->English + nw->computer;
                    nw->Average = (nw->Sum) / 3;
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << NewMath << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
            else if (order == 4)
            {
                double NewEng;
                printf("Please enter new English score：");
                cin >> NewEng;
                while (NewEng < 0 || NewEng > 100)
                {
                    puts("The data you entered is illegal. Please re-enter it");
                    cin >> NewEng;
                }
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    nw->Sum = nw->Math + NewEng + nw->computer;
                    nw->Average = (nw->Sum) / 3;
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << NewEng << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
            else if (order == 5)
            {
                double NewComputer;
                printf("Please enter new Computer score：");
                cin >> NewComputer;
                while (NewComputer < 0 || NewComputer > 100)
                {
                    puts("The data you entered is illegal. Please re-enter it");
                    cin >> NewComputer;
                }
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    nw->Sum = nw->Math + nw->English + NewComputer;
                    nw->Average = (nw->Sum) / 3;
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << NewComputer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
            else if (order == 6)
            {
                double NewCla;
                printf("Please enter new Class：");
                cin >> NewCla;
                while (NewCla < 0)
                {
                    puts("The data you entered is illegal. Please re-enter it");
                    cin >> NewCla;
                }
                printf("\nConfirm modification？(Y/N) ");
                cin >> x;
                if (x == 'N' || x == 'n')
                {
                    puts("\nModification cancelled successfully!");
                    fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                }
                else
                {
                    nw->Sum = nw->Math + NewCla + nw->computer;
                    nw->Average = (nw->Sum) / 3;
                    fout << nw->Id << " " << nw->Name << " " << NewCla << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                         << nw->Sum << " " << nw->Average << endl;
                    puts("\nData modified successfully!");
                }
            }
        }

        if (!isFind)
            puts("\nThe information was not found！");

        fin.close();
        fout.close();
        remove("data.txt");
        rename("data2.txt", "data.txt");
        puts("\nContinue to modify？(Y/N)");
        cin >> x;
    }
}
void Delete()
{
    char x = 'Y';
    string tmp;
    puts("*******************************************************");
    puts("                    Delete student information           ");
    puts("*******************************************************\n");

    while (x == 'Y' || x == 'y')
    {
        ifstream fin("data.txt", ios::app);
        ofstream fout("data2.txt", ios::app);
        if (!fin)
        {
            puts("File open failed！");
            exit(0);
        }
        puts("         Please select to Delete student information according to the keywords：");
        puts("------------------------------------------------------------------------------------");
        puts("            1.Name\n");
        puts("            2.Student number\n");
        puts("            0.Return to the previous menu");
        printf("Command：");
        scanf("%d", &order);
        while ((order < 0) || (order > 2))
        {
            puts("");
            InputError();
            puts("         Please select to Delete student information according to the keywords：");
            puts("----------------------------------------------------------------------------------");
            puts("            1.Name\n");
            puts("            2.Student number\n");
            puts("            0.Return to the previous menu");
            printf("Command：");
            scanf("%d", &order);
        }

        if (order == 0)
            return;

        if (order == 1)
        {
            printf("Please enter Name：");
            cin >> tmp;
        }
        else if (order == 2)
        {
            printf("Please enter Student number：");
            cin >> tmp;
        }

        Student *nw;
        nw =  new Student;
        bool isFind = false;
        while (fin >> nw->Id >> nw->Name >> nw->Classnum >> nw->Math >> nw->English >> nw->computer >> nw->Sum >> nw->Average)
        {
            if ((tmp.compare(nw->Name)) && (tmp.compare(nw->Id)))
            {
                fout << nw->Id << " " << nw->Name << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                     << nw->Sum << " " << nw->Average << endl;
                continue;
            }
            isFind = true;

            cout << "\nStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
            cout << left << setw(16) << nw->Id
                 << left << setw(16) << nw->Name
                 << left << setw(10) << nw->Classnum
                 << left << setw(8) << nw->Math
                 << left << setw(16) << nw->English
                 << left << setw(16) << nw->computer
                 << left << setw(6) << nw->Sum
                 << setw(2) << nw->Average
                 << endl;

            printf("\nConfirm deletion？(Y/N) ");
            cin >> x;
            if (x == 'N' || x == 'n')
            {
                puts("\nComfirm deletion succeeded!");
                fout << nw->Name << " " << nw->Id << " " << nw->Classnum << " " << nw->Math << " " << nw->English << " " << nw->computer << " "
                     << nw->Sum << " " << nw->Average << endl;
                continue;
            }
            puts("\nData deleted successfully!");
        }

        if (!isFind)
            puts("\nThe information was not found！");

        fin.close();
        fout.close();

        remove("data.txt");
        rename("data2.txt", "data.txt");

        puts("\nDo you want to continue deleting？(Y/N)");
        cin >> x;
    }
}

void Search()
{
    char x = 'Y';
    string tmp;
    puts("*******************************************************");
    puts("                    Query student information           ");
    puts("*******************************************************\n");

    while (x == 'Y' || x == 'y')
    {
        ifstream fin("data.txt");
        if (!fin)
        {
            puts("File open failed！");
            exit(0);
        }

        puts("                  Please select query  method：");
        puts("-------------------------------------------------");
        puts("                  1.Name\n");
        puts("                  2.Student number\n");
        puts("                  3.Return to the previous menu");
        printf("Command：");
        scanf("%d", &order);
        while ((order < 1) || (order > 2))
        {
            InputError();
            puts("                  Please select query  method：");
            puts("--------------------------------------------------");
            puts("                  1.Name\n");
            puts("                  2.Student number\n");
            puts("                  0.Return to the previous menu");
            printf("Command：");
            scanf("%d", &order);
        }

        if (order == 0)
            return;

        if (order == 1)
        {
            printf("Please enter to query Name：");
            cin >> tmp;
        }
        else if (order == 2)
        {
            printf("Please enter to query Student number：");
            cin >> tmp;
        }
        Student *nw;
        nw =  new Student;
        bool isFind = 0;
        int cnt = 0;
        while (fin >> nw->Id >> nw->Name >> nw->Classnum >> nw->Math >> nw->English >> nw->computer >> nw->Sum >> nw->Average)
        {
            if (order == 1)
            {
                if (!nw->Name.compare(tmp))
                {
                    if (!isFind)
                        cout << "\nSerial number\tStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
                    isFind = 1;
                    cnt++;
                    cout << left << setw(16) << cnt
                         << left << setw(16) << nw->Id
                         << left << setw(10) << nw->Name
                         << left << setw(8) << nw->Classnum
                         << left << setw(16) << nw->Math
                         << left << setw(16) << nw->English
                         << left << setw(16) << nw->computer
                         << left << setw(16) << nw->Sum
                         << setw(2) << nw->Average
                         << endl;
                }
            }
            else if (order == 2)
            {
                if (!nw->Id.compare(tmp))
                {
                    if (!isFind)
                        cout << "\nSerial number\tStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
                    isFind = 1;
                    cnt++;
                    cout << left << setw(16) << cnt
                         << left << setw(16) << nw->Id
                         << left << setw(10) << nw->Name
                         << left << setw(8) << nw->Classnum
                         << left << setw(16) << nw->Math
                         << left << setw(16) << nw->English
                         << left << setw(16) << nw->computer
                         << left << setw(16) << nw->Sum
                         << setw(2) << nw->Average
                         << endl;
                }
            }
        }
        if (!isFind)
            puts("\nThe information was not found！");
        fin.close();
        puts("\nDo you want to continue the query？(Y/N)");
        cin >> x;
    }
}
void Sort()
{

    char x = 'Y';
    string tmp;
    puts("*******************************************************");
    puts("                          Sort                          ");
    puts("*******************************************************\n");

    while (x == 'Y' || x == 'y')
    {
        ifstream fin("data.txt");
        if (!fin)
        {
            puts("File open failed！");
            system("pause");
            exit(0);
        }
        puts("                  Please select Sort method：");
        puts("-----------------------------------------------");
        puts("                  1.Student number from small to large\n");
        puts("                  2.Math score from large to small\n");
        puts("                  3.English score from large to small\n");
        puts("                  4.Computer score from large to small\n");
        puts("                  5.Total score from large to small\n");
        puts("                  6.Average score from large to small\n");
        puts("                  0.Return to the previous menu");
        printf("Command：");
        scanf("%d", &order);
        while ((order < 0) || (order > 6))
        {
            InputError();
            puts("                  Please select Sort method：");
        puts("---------------------------------------------------");
        puts("                  1.Student number from small to large\n");
        puts("                  2.Math score from large to small\n");
        puts("                  3.English score from large to small\n");
        puts("                  4.Computer score from large to small\n");
        puts("                  5.Total score from large to small\n");
        puts("                  6.Average score from large to small\n");
        puts("                  0.Return to the previous menu");
            printf("Command：");
            scanf("%d", &order);
        }
        if (order == 0)
        {
            return;
        }

        Student *Head ,*pend,*pnew = NULL;
        Head = pend =  new Student;
        pnew =  new Student;
        while (fin >> pnew->Id >> pnew->Name >>pnew -> Classnum>> pnew->Math >> pnew->English >> pnew->computer >> pnew->Sum >> pnew->Average)
        {
            pnew -> nxt =NULL;
            pend -> nxt = pnew;
            pend = pnew;
            pnew =  new Student;
        }
        Student *p,*q;
                if (order == 1)
                {
                    for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                        {
                            if(p -> Id .size() < q -> Id.size())
                                continue;
                    if(p -> Id > q-> Id)
                    {
                        string t1 = p -> Id;
                        p -> Id = q -> Id;
                        q -> Id = t1;
                        cout<<t1<<endl;
                    }
                }
                       }
                else if (order == 2)
                {
                     for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                    if(p ->Math < q-> Math)
                    {
                        int t1 = p -> Math;
                        p -> Math = q -> Math;
                        q -> Math = t1;
                    }
                }
                else if (order == 3)
                {
                     for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                    if(p ->English < q-> English)
                    {
                        int t1 = p -> English;
                        p -> English = q -> English;
                        q -> English = t1;
                    }
                }
                else if (order == 4)
                {
                     for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                    if(p ->computer < q-> computer)
                    {
                        int t1 = p -> computer;
                        p -> computer = q -> computer;
                        q -> computer = t1;
                    }
                }
                else if (order == 5)
                {
                     for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                    if(p ->Sum < q-> Sum)
                    {
                        int t1 = p -> Sum;
                        p -> Sum = q ->Sum;
                        q -> Sum = t1;
                    }
                }
                else if (order == 6)
                {
                     for(p = Head -> nxt; p != NULL ; p = p-> nxt)
                        for(q = p -> nxt ; q != NULL ; q = q->nxt)
                    if(p ->Average < q-> Average)
                    {
                        int t1 = p -> Average;
                        p -> Average= q ->Average;
                        q -> Average = t1;
                    }
                }
        Student *r = Head -> nxt;
        puts("*******************************************************");
        if (order == 1)
            puts("              Student number from small to large       ");
        else if (order == 2)
            puts("              Math score from large to small    ");
        else if (order == 3)
            puts("              English score from large to small    ");
        else if (order == 4)
            puts("              Computer score from large to small ");
        else if (order == 5)
            puts("              Total score from large to small ");
        else if (order == 6)
            puts("              Average score from large to small ");
        puts("*******************************************************\n");
        cout << "\nSerial number\tStudent number\tName\tClass\tMath score\tEnglish score\tComputer score\tTotal score\tAverage score\n";
        int cnt = 0;
        while (r != NULL)
        {
            cnt++;
            cout << left << setw(16) << cnt
                 << left << setw(16) << r->Id
                 << left << setw(10) << r->Name
                 << left << setw(8) << r->Classnum
                 << left << setw(16) << r->Math
                 << left << setw(16) << r->English
                 << left << setw(16) << r->computer
                 << left << setw(16) << r->Sum
                 << left << setw(2) << r->Average
                 << endl;
            r = r->nxt;
        }
        fin.close();
        puts("\nDo you want to continue viewing？(Y/N)");
        cin >> x;
    }
}

void MenuOrderAction()
{
    if (order == 1)
    {
        Add();
    }
    else if (order == 2)
    {
        Display();
    }
    else if (order == 3)
    {
        Search();
    }
    else if (order == 4)
    {
        Mend();
    }
    else if (order == 5)
    {
        Add();
    }
    else if (order == 6)
    {
        Sort();
    }
    else if (order == 7)
    {
        Delete();
    }
    else if (order == 0)
    {
        ExitSystem();
    }
}
};
int main()
{
    while (1)
    {
        Student A;
        A.ShowMenu();
        printf("Command：");
        scanf("%d", &order);
        while ((order < 0) || (order > 7))
        {
            A.ShowMenu();
            A.InputError();
            printf("Command：");
            scanf("%d", &order);
        }
        A.MenuOrderAction();
    }
    return 0;
}
