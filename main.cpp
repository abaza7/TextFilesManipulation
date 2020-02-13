/*************************************************
Aufgabe Nr./Task No.: H3
Nachname/Last,Family Name: Abaza
Vorname/First,Given Name: Ahmed
Matrikelnummer/Matriculation number: 3035482
Uni-Email: ahmed.abaza@stud.uni-due.de
Studiengang/Course of Studies: ISE CE
*************************************************/
#include<cstring>
#include<fstream>
#include <iostream>

using namespace std;

struct Diseases
{
	string code;
	string name;
	Diseases *next;
};

Diseases *head = nullptr;
int foundf;
int foundh;
int foundt;
int foundc;
int foundup;
int foundcup;

void readCSVfileWithDiseaseData(string fileName, char separator)
{
   char c;
   int counter=0;
   string name;
   string code;
   string n;
   char f;
   ifstream inFile;
   inFile.open(fileName);
   if (!inFile.is_open())
      cerr << "error opening file \"" << fileName << '\"' << endl;
   else
   {
      cout << "input file \"" << fileName << "\" opened..." << endl;
      while ((c = inFile.get()) != EOF)
      {
         code = "";
         while (c != separator)
         {
            code = code + c;
            c = inFile.get();
         }
         c= inFile.get();
         name = "";
         while ((c != EOF) &&(c != '\n'))// && (c != separator))
         {
            name = name + c;
            c = inFile.get();
         }
         //if (name.size () > 0)  name.resize (name.size () - 1);
         //name.pop_back();
         //insertDisease(name, code);
        if(counter!=0)
        {


                Diseases *newDisease = new Diseases;
                newDisease->code = code;
                //int x=name.find(";");
                //string y=name.substr(0,x)
                int lengthName = 0;
                while (name[lengthName] != '\0')
                {
                    ++lengthName;
                }
                n = "";
                for(int i = 0; i < lengthName - 1; i++)
                {
                    f = name[i];
                    n = n + f;
                }
                newDisease->name = n;
                newDisease->next = head;
                head = newDisease;
        }
        counter++;
      }
      inFile.close();
      cout << "input file closed" << endl;
      cout << endl;
   }
}

/*bool searchName(Diseases *p, string key)
{
    foundf = 0;
    while (p != nullptr)
    {
        if(p->name == key)
        {
            cout << "" << p->code << "\t" << p->name <<endl;
            foundf++;
            return true;
        }
        else
        {
            p = p->next;
        }
    }
    return false;
}*/

bool searchHname(Diseases *p, string key)
{
    foundh = 0;
    int len = 0;
    while (key[len] != '\0')
    {
        ++len;
    }
    int k, m;
    int count;
    while (p != nullptr)
    {
        string nam = p->name;
        int lenNam = 0;
        while (nam[lenNam] != '\0')
        {
            ++lenNam;
        }

        for(m = 0; m < lenNam; m++)
        {
            k = 0;
            count = 0;
            if(nam[m] == key[k])
            {
                do
                {
                    m++;
                    k++;
                    count++;
                }
                while((nam[m] == key[k]) && (k < len) && (m < lenNam));
                if (count == len)
                {
                    cout << "" << p->code << "\t" << p->name <<endl;
                    foundh++;
                }
            }
       }

    p = p->next;
    }
    return true;
}

bool searchNameToupper(Diseases *p, string key)
{
    foundup = 0;
    int len = 0;
    key[0] = toupper(key[0]);
    while (key[len] != '\0')
    {
        ++len;
    }
    int k, m;
    int count;
    while (p != nullptr)
    {
        string nam = p->name;
        int lenNam = 0;
        while (nam[lenNam] != '\0')
        {
            ++lenNam;
        }

        for(m = 0; m < lenNam; m++)
        {
            k = 0;
            count = 0;
            if(nam[m] == key[k])
            {
                do
                {
                    m++;
                    k++;
                    count++;
                }
                while((nam[m] == key[k]) && (k < len) && (m < lenNam));
                if (count == len)
                {
                    cout << "" << p->code << "\t" << p->name <<endl;
                    foundup++;
                }
            }
       }
            p = p->next;
    }
    return true;
}

bool searchNameTolower(Diseases *p, string key)
{
    foundup = 0;
    int len = 0;
    key[0] = tolower(key[0]);
    while (key[len] != '\0')
    {
        ++len;
    }
    int k, m;
    int count;
    while (p != nullptr)
    {
        string nam = p->name;
        int lenNam = 0;
        while (nam[lenNam] != '\0')
        {
            ++lenNam;
        }

        for(m = 0; m < lenNam; m++)
        {
            k = 0;
            count = 0;
            if(nam[m] == key[k])
            {
                do
                {
                    m++;
                    k++;
                    count++;
                }
                while((nam[m] == key[k]) && (k < len) && (m < lenNam));
                if (count == len)
                {
                    cout << "" << p->code << "\t" << p->name <<endl;
                    foundup++;
                }
            }
       }
            p = p->next;
    }
    return true;
}
/*bool searchCode(Diseases *p, string key)
{
    foundc = 0;
    int len = 0;
    while (key[len] != '\0')
    {
        ++len;
    }
    int k, m;
    int count;
    while (p != nullptr)
    {
        string cod = p->code;
        int lenCod = 0;
        while (cod[lenCod] != '\0')
        {
            ++lenCod;
        }

        for(m = 0; m < lenCod; m++)
        {
            k = 0;
            count = 0;
            if(cod[m] == key[k])
            {
                do
                {
                    m++;
                    k++;
                    count++;
                }
                while((cod[m] == key[k]) && (k < len) && (m < lenCod));
                if (count == len)
                {
                    cout << "" << p->code << "\t" << p->name <<endl;
                    foundc++;
                }
            }
       }
            p = p->next;
    }
    return true;
}*/

bool searchCodeToupper(Diseases *p, string key)
{
    foundcup = 0;
    int len = 0;
    key[0] = toupper(key[0]);
    while (key[len] != '\0')
    {
        ++len;
    }
    int k, m;
    int count;
    while (p != nullptr)
    {
        string cod = p->code;
        int lenCod = 0;
        while (cod[lenCod] != '\0')
        {
            ++lenCod;
        }

        for(m = 0; m < lenCod; m++)
        {
            k = 0;
            count = 0;
            if(cod[m] == key[k])
            {
                do
                {
                    m++;
                    k++;
                    count++;
                }
                while((cod[m] == key[k]) && (k < len) && (m < lenCod));
                if (count == len)
                {
                    cout << "" << p->code << "\t" << p->name <<endl;
                    foundcup++;
                }
            }
       }
            p = p->next;
    }
    return true;
}

int main()
{
    char choice;
	string name;
	string code;
    string d;
	string filename = "Section111ValidICD10-2018.csv";
	char separator = ';';
	readCSVfileWithDiseaseData(filename, separator);
   do
   {
      cout << "0 End" << endl
           << "1 search by code" << endl
           << "2 search by disease" << endl
           << ">> ";
      cin >> choice;
      switch (choice)
      {
      case '0': break;
      case '1': cout << "Please enter Code to search for: ";
                cin.sync();
                getline(cin, d);
//                searchCode(head,d);
                searchCodeToupper(head, d);
                foundt = foundc + foundcup;
                if(foundt != 0)
                {
                    cout << foundt << " entries found." << endl;
                }
                else
                {
                    cout << "'"<< d << "' was not found." << endl;
                }
                break;
      case '2': cout << "Please enter diagnosis to search for: ";
                cin.sync();
                getline(cin, d);
                //searchName(head,d);
                if(isupper(d[0]))       //if it is forbidden to use isupper: if(d[0] == 'A' || d[0] == 'B' || d[0] == 'C' ||...etc)
                {
                    searchHname(head,d);
                    searchNameTolower(head,d);
                }
                else
                {
                    searchHname(head,d);
                    searchNameToupper(head,d);
                }
                foundt = foundup + foundh;
                if(foundt != 0)
                {
                    cout << foundt << " entries found." << endl;
                }
                else
                {
                    cout << "'"<< d << "' was not found." << endl;
                }
                break;
      default:  cout << "sorry wrong choice" << endl;
      }
   } while(choice != '0');
   return 0;
}
