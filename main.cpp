#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool login();
void main_menu();
void MainMenu();
void case1();
void case2();
void case3();
class Car {
    protected:
       string carName;
       int model;
       int carID;
       int r_p_h;
       int driverID;
       int car_choice;
    public:
        Car()
        {
            cout<<"\n\n\n\t\t___________________CAR MANAGEMENT SCREEN!!!___________________";
            cout<<"\n\n\t\t1) Add Car";
            cout<<"\n\n\t\t2) ALL Cars";
            cout<<"\n\n\t\t3) Modify Car";
            cout<<"\n\n\t\t4) Delete Car";
            cout<<"\n\n\t\t5) Main Menu";

            cout<<"\n\n\t\tEnter Choice:";
            cin>>car_choice;
        }
        void carMenu(){
            cout<<"\n\n\n\t\t___________________CAR MANAGEMENT SCREEN!!!___________________";
            cout<<"\n\n\t\t1) Add Car";
            cout<<"\n\n\t\t2) ALL Cars";
            cout<<"\n\n\t\t3) Modify Car";
            cout<<"\n\n\t\t4) Delete Car";
            cout<<"\n\n\t\t5) Main Menu";

            cout<<"\n\n\t\tEnter Choice:";
            cin>>car_choice;
        }
        int carChoice()
        {
            return car_choice;
        }
        void addCar()
        {
            int count = 0;
            int dID,dExp,searchedID,searchedexp;
            bool IsAvailable;
            string name;

            m:
                carID = (rand()/80)+(rand()/120);
                //cout<<carID;
                cout<<"\n\n\t\tEnter Car Name:";
                cin>>carName;
                cout<<"\n\n\t\tEnter Model:";
                cin>>model;
                //cout<<"\n\n\t\tEnter Car ID:";
                //cin>>carID;
                cout<<"\n\n\t\tEnter Car Rate Per Hour:";
                cin>>r_p_h;
                if(r_p_h<=0){
                    cout<<"\n\n\t\tRate Can Not Be Zero OR Negative!!!!";
                    case1();
                }

                cout<<"\n\n\t\tEnter Driver ID:";
                cin>>driverID;

                fstream file;

                    file.open("Driver.txt",ios::in);
                    file>>dID>>name>>dExp>>IsAvailable;

                    while(!file.eof())
                    {
                        if(driverID == dID)
                        {
                            searchedID = dID;
                            searchedexp = dExp;
                            count++;
                        }
                        file>>dID>>name>>dExp>>IsAvailable;
                    }
                    file.close();


                if(count == 0)
                {
                    system("color C");
                    cout<<"\n\n\t\tNo Driver Found with this "<<driverID<<" ID!!!!";
                    Sleep(3000);
                    system("CLS");
                    system("color B");
                    case1();
                }
                else {
                    fstream file1;
                    file1.open("Car.txt", ios::out | ios::app);
                    file1<<" "<<carName<<" "<<model<<" "<<carID<<" "<<r_p_h<<" "<<searchedID<<" "<<searchedexp<<"\n";
                    file1.close();
                    cout<<"\n\n\t\tRecord Inserted successfully!";
                    Sleep(2000);
                    system("CLS");
                    case1();
                }

        }
        void allCars()
{
            cout<<"\n\n\n\t\t___________________All Cars___________________";
            fstream file;
            if(!file)
            {
                cout<<"\n\n\t\tFile Does not Exist!!!";
                Sleep(2000);
                system("CLS");
                file.close();
                case1();
            }
            else
            {

                int DExp;
                file.open("Car.txt", ios::in);
                file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
                while(!file.eof())
                {


                    cout<<"\n\n\n\tCar Name:"<<carName<<"||"<<"Model:"<<model<<"||"<<"Car ID:"<<carID<<"||"<<"Rate Per Hour:"<<r_p_h<<"||"<<"Driver ID:"<<driverID<<"||"<<"Driver Experience:"<<DExp<<"\n";


                    file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
                }
                file.close();
                cout<<"\n";
                system("pause");
                system("CLS");
                case1();
            }

}

/*void allCars()
        {
            cout<<"\n\n\n\t\t___________________All Cars___________________";
            fstream file;
            int DExp;
            file.open("Car.txt", ios::in);
              file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
            while(!file.eof())
            {
                cout<<"\n\n\n\tCar Name:"<<carName<<"||"<<"Model:"<<model<<"||"<<"Car ID:"<<carID<<"||"<<"Rate Per Hour:"<<r_p_h<<"||"<<"Driver ID:"<<driverID<<"||"<<"Driver Experience:"<<DExp<<"\n";
                file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
            }
            file.close();
            system("pause");
            system("CLS");
            case1();
        }
        */
void modifyCar()
{
    fstream file,file1;
    int searchCarID;
    string CN;
    int CID;
    int DID;
    int RPH;
    int DExp;
    int mod;
    int token = 0;
    int countD = 0;
    cout<<"\n\n\n\t\t___________________Modify Car___________________";
    cout<<"\n\n\t\tEnter Search Car ID:";
    cin>>searchCarID;
    file.open("Car.txt",ios::in);
    if(!file)
    {

        cout<<"\n\n\t\tFile Does not Exist!!!";
        Sleep(2000);
        system("CLS");
        case1();
    }
    else
    {
        file1.open("Car2.txt",ios::out|ios::app);
        file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
        while(!file.eof())
        {
            start:
                if(searchCarID == carID)
                {
                    CID = rand()/80;
                    cout<<"\n\n\t\tEnter New Car Name:";
                    cin>>CN;
                    cout<<"\n\n\t\tEnter New Model:";
                    cin>>mod;
                    //cout<<"\n\n\t\tEnter New Car ID:";
                    //cin>>CID;
                    cout<<"\n\n\t\tEnter New Rate Per Hour:";
                    cin>>RPH;
                    if(RPH<=0)
                    {
                        cout<<"\n\n\t\tRate Can Not Be Negative!!!!";
                        Sleep(2000);
                        system("CLS");
                        case1();
                    }
                    cout<<"\n\n\t\tEnter New Driver ID:";
                    cin>>DID;

                    fstream file3;
                    int DRIVERID,DRIVEREXP,MATCHEDID,MATCHEDEXP;
                    string DRIVERNAME;
                    bool ISAVAIL;
                    file3.open("Driver.txt",ios::in);
                    file3>>DRIVERID>>DRIVERNAME>>DRIVEREXP>>ISAVAIL;

                    while(!file3.eof())
                    {
                        if(DID == DRIVERID)
                        {
                            MATCHEDID = DRIVERID;
                            MATCHEDEXP = DRIVEREXP;
                            countD++;
                            break;
                        }
                        file3>>DRIVERID>>DRIVERNAME>>DRIVEREXP>>ISAVAIL;
                    } //END OF WHILE LOOP
                    file3.close();
                    if(countD == 0)
                    {
                        cout<<"\n\n\t\tNO DRIVER FOUND!!!";
                        Sleep(2000);
                        system("CLS");
                        goto start;
                    }
                    else {
                        file1<<" "<<CN<<" "<<mod<<" "<<CID<<" "<<RPH<<" "<<DID<<" "<<MATCHEDEXP<<"\n";
                        cout<<"\n\n\t\tRecord Edited!!!";
                        token++;
                    }
                }
                else
                {
                    cout<<"\n\n\t\tNo Car Found!!!";
                    file1<<" "<<carName<<" "<<model<<" "<<carID<<" "<<r_p_h<<" "<<driverID<<" "<<DExp<<"\n";
                }
                file>>carName>>model>>carID>>r_p_h>>driverID>>DExp;
        }
        file.close();
        file1.close();
        remove("Car.txt");
        rename("Car2.txt","Car.txt");
        Sleep(2000);

        if(token == 0)
        {
            cout<<"\n\n\t\tRecord Not Found!!!";
            Sleep(2000);
        }
        system("CLS");
        case1();
    }
} // END OF MODIFYCAR FUNCTION

void deleteCar()
{
    fstream file,file1;
    int CID;
    int token = 0;
    int driverExp;
    cout<<"\n\n\n\t\t___________________Delete Car___________________";
    cout<<"\n\n\t\tEnter Car ID:";
    cin>>CID;
    file.open("Car.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tFile Does Not Exist!!!";
        Sleep(2000);
        file.close();
        system("CLS");
        case1();
    }
    else
    {
        file1.open("Car1.txt",ios::out|ios::app);

        file>>carName>>model>>carID>>r_p_h>>driverID>>driverExp;
        while(!file.eof())
        {

            if(CID == carID)
            {
                cout<<"\n\n\t\tCar Deleted!!!";
                token++;
                Sleep(2000);
                system("CLS");
            }
            else
            {
                file1<<" "<<carName<<" "<<model<<" "<<carID<<" "<<r_p_h<<" "<<driverID<<" "<<driverExp<<"\n";
            }
            file>>carName>>model>>carID>>r_p_h>>driverID>>driverExp;
        } //END OF WHILE LOOPs
        if(token == 0)
        {
            cout<<"\n\n\t\tRecord Not Found!!!";
            Sleep(2000);
        }
        file.close();
        file1.close();
        remove("Car.txt");
        rename("Car1.txt","Car.txt");
        system("CLS");
        case1();
    }
}


};

class Driver{
    protected:
        string driverName;
        int driverID;
        int driverExp;
        bool isAvail = true;
        int driver_choice;
    public:
        Driver()
        {

            cout<<"\n\n\n\t\t___________________Driver MANAGEMENT SCREEN!!!___________________";
            cout<<"\n\n\t\t1) Add Driver";
            cout<<"\n\n\t\t2) ALL Driver";
            cout<<"\n\n\t\t3) Modify Driver";
            cout<<"\n\n\t\t4) Delete Driver";
            cout<<"\n\n\t\t5) Main Menu";

            cout<<"\n\n\t\tEnter Choice:";
            cin>>driver_choice;
        }
        int driverChoice()
        {
            return driver_choice;
        }

        void addDriver()
        {
            int count = 0;
            int dID,dExp,matchedID;
            bool IsAvailable;
            string name;
            int tempID = (rand()/43);
            m:
                driverID = (rand()/80)+(rand()/200);
                /*
                fstream file5;
                file5.open("Driver.txt",ios::in);
                if(!file5)
                {

                    cout<<"File Does not Exist";
                    file5.close();
                }
                else{
                        cout<<"ELSE PART!!!";
                        bool tempAvail;
                    file5.open("Driver.txt",ios::in);
                    file5>>dID>>name>>dExp>>IsAvailable;
                    while(!file5.eof())
                    {
                        tempID = dID;
                        file5>>dID>>name>>dExp>>IsAvailable;
                    }
                file5.close();
                }

            test:
            */
                //cout<<"Goto";


                //srand(tempID);
                //driverID = (rand() + tempID);
                cout<<driverID;
                //cout<<"\n\n\t\tEnter Driver ID:";
                //cin>>driverID;
                cout<<"\n\n\t\tEnter Name:";
                //cin.get();
                //getline(cin,driverName);
                cin>>driverName;
                cout<<"\n\n\t\tEnter Driver Experience:";
                cin>>driverExp;
                //strcat(id,driverName);
                cout<<driverID;
                fstream file;
                /*
                file.open("Driver.txt",ios::in);
                file>>dID>>name>>dExp>>IsAvailable;

                while(!file.eof())
                {
                    if(driverID == dID)
                    {
                        matchedID = dID;
                        count++;
                    }
                    file>>dID>>name>>dExp>>IsAvailable;
                }
                file.close();
                if(count >= 1)
                {
                    cout<<"\n\n\t\tDriver Already exist with this ID!!!!";
                    Sleep(3000);
                    system("CLS");
                    goto m;
                }
                */

                    //fstream file1;
                    file.open("Driver.txt", ios::out | ios::app);
                    file<<" "<<driverID<<" "<<driverName<<" "<<driverExp<<" "<<isAvail<<"\n";
                    file.close();
                    cout<<"\n\n\t\tRecord Inserted successfully!";
                    Sleep(2000);
                    system("CLS");
                    //goto m;
                    case2();


        }
void allDrivers()
{
            cout<<"\n\n\n\t\t___________________All Drivers___________________";
            fstream file;
            if(!file)
            {
                cout<<"\n\n\t\tFile Does Not Exist!!!";
                Sleep(2000);
                system("CLS");
                file.close();
                case2();
            }
            else
            {
              //int DExp;
            file.open("Driver.txt");
            file>>driverID>>driverName>>driverExp>>isAvail;

            while(!file.eof())
            {
                cout<<"\n\n\n\tDriver ID:"<<driverID<<"||"<<"Name:"<<driverName<<"||"<<"Experience:"<<driverExp<<"\n";
                /*
                file>>driverID;
                file>>isAvail;
                file>>driverExp;
                file.ignore();
                getline(file,driverName);
                */
                file>>driverID>>driverName>>driverExp>>isAvail;
            }
            file.close();
            cout<<"\n";
            system("pause");
            system("CLS");
            case2();
            }


}

void modifyDriver()
{
    fstream file,file1,file3,file4;
    int searchDriverID;
    string dName;
    string CN;
    int CID;
    int DID;
    int dID;
    int RPH;
    int DExp;
    int dExp;
    int mod;
    int token = 0;
    int countD = 0;
    cout<<"\n\n\n\t\t___________________Modify Driver___________________";
    cout<<"\n\n\t\tEnter Search Driver ID:";
    cin>>searchDriverID;
    file.open("Driver.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tFile Does not Exist!!!";
        Sleep(2000);
        system("CLS");
        case2();
    }
    else
    {
        file1.open("Driver2.txt",ios::out|ios::app);
        file>>driverID>>driverName>>driverExp>>isAvail;
        while(!file.eof())
        {
            start:
                if(searchDriverID == driverID)
                {
                    DID = driverID;
                    //CID = rand()/80;
                    cout<<"\n\n\t\tEnter New Driver Name:";
                    cin>>dName;
                    //cin.get();
                    //getline(cin,dName);
                    cout<<"\n\n\t\tEnter New Driver Experience:";
                    cin>>DExp;
                    //cout<<"\n\n\t\tEnter New Car ID:";
                    //cin>>CID;


                    //fstream file3,file4;
                    file3.open("Car.txt",ios::in);
                    if(!file3)
                    {
                        cout<<"\n\n\t\tFile Does not Exist!!!";
                        Sleep(2000);
                        file3.close();
                        file3.close();
                    }
                    else
                    {
                        file4.open("Car2.txt",ios::out | ios::app);
                        file3>>CN>>mod>>CID>>RPH>>dID>>dExp;
                        while(!file3.eof())
                        {
                            if(DID == dID)
                            {
                                file4<<" "<<CN<<" "<<mod<<" "<<CID<<" "<<RPH<<" "<<dID<<" "<<DExp<<"\n";
                            }
                            else
                            {
                                file4<<" "<<CN<<" "<<mod<<" "<<CID<<" "<<RPH<<" "<<dID<<" "<<dExp<<"\n";
                            }
                            file3>>CN>>mod>>CID>>RPH>>dID>>dExp;
                        } //END OF WHILE LOOP

                    }
                    file1<<" "<<DID<<" "<<dName<<" "<<DExp<<" "<<isAvail<<"\n";
                    token++;

                }
                else
                {
                    //int tempDEXP;
                    //cout<<"TEMPDEXP="<<tempDEXP;
                    //cout<<"\n\n\t\tNo Driver Found!!!";
                    file1<<" "<<driverID<<" "<<driverName<<" "<<driverExp<<" "<<isAvail<<"\n";
                }
                file>>driverID>>driverName>>driverExp>>isAvail;
        } // END OF MAIN WHILE LOOP
        file3.close();
        file4.close();
        remove("Car.txt");
        rename("Car2.txt","Car.txt");
        file.close();
        file1.close();
        remove("Driver.txt");
        rename("Driver2.txt","Driver.txt");
        Sleep(2000);

        if(token == 0)
        {
            cout<<"\n\n\t\tRecord Not Found!!!";
        }
         system("CLS");
        case2();
    }
} // END OF MODIFYDRIVER FUNCTION

void deleteDriver()
{
    fstream file,file1;
    int DID;
    int token = 0;
    cout<<"\n\n\n\t\t___________________Delete Driver___________________";
    cout<<"\n\n\t\tEnter Driver ID:";
    cin>>DID;
    file.open("Driver.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tFile Does Not Exist!!!";
        Sleep(2000);
        file.close();
        system("CLS");
        case2();
        file.close();
    }

    else
    {
        file1.open("Driver1.txt",ios::out|ios::app);

        file>>driverID>>driverName>>driverExp>>isAvail;
        while(!file.eof())
        {

            if(DID == driverID)
            {

                cout<<"\n\n\t\tDriver Deleted!!!";
                cout<<"\n\n\t\tYou Have to Edit/Modify Cars with this "<<driverID<<" Driver ID!!!";
                token++;
                Sleep(2000);

            }
            else
            {
                file1<<" "<<driverID<<" "<<driverName<<" "<<driverExp<<" "<<isAvail<<"\n";
            }
            file>>driverID>>driverName>>driverExp>>isAvail;
        } //END OF WHILE LOOP
        if(token == 0)
        {
            Sleep(2000);
            cout<<"\n\n\t\tRecord Can Not Found!!!";
        }
        file.close();
        file1.close();
        remove("Driver.txt");
        rename("Driver1.txt","Driver.txt");
        system("CLS");
        char ch;
        cout<<"\n\n\t\tDo You want to Modify Car? (Y/N)";
                cin>>ch;
                switch(ch)
                {
                    case 'Y':
                    case1();
                    break;

                    case 'N':
                    system("CLS");
                    case2();
                    break;
                    default:
                    cout<<ch<<" Enter Valid Keyword!!!";
                    break;
                }

    }

}

};

class Customer{
    protected:
        string customerName;
        int customerID;
        string email;
        string address;
        int driverID;
        string driverName;
        int carID;
        int discount;
        string carName;
        int bill;
        int no_of_hours;
        int customer_choice;
    public:
        Customer()
        {

            cout<<"\n\n\n\t\t___________________Customer MANAGEMENT SCREEN!!!___________________";
            cout<<"\n\n\t\t1) Add Customer";
            cout<<"\n\n\t\t2) ALL Customers";
            cout<<"\n\n\t\t3) Modify Customer";
            cout<<"\n\n\t\t4) Delete Customer";
            cout<<"\n\n\t\t5) Main Menu";

            cout<<"\n\n\t\tEnter Choice:";
            cin>>customer_choice;
        }
        int customerChoice()
        {
            return customer_choice;
        }

void addCustomer()
{

            int countCar = 0;
            int dID,dExp,searchedDriverID,searchedDriverExp,searchedCarID,RPH,cID,mod,ratePerHour;
            string dName,cName;
            bool IsAvailable;

            //string name;
            m:
                customerID = (rand()/80)+(rand()/120)*(rand()/70);
                cout<<"\n\n\t\tEnter Customer Name:";
                cin>>customerName;
                //cin.get();
                //getline(cin,customerName);
                cout<<"\n\n\t\tEnter Customer Email Address:";
                cin>>email;
                cout<<"\n\n\t\tEnter Customer Address:";
                cin>>address;
                //cin.get();
                //getline(cin,address);
                cout<<"\n\n\t\tEnter No of Hours:";
                cin>>no_of_hours;
                if(no_of_hours<=0)
                {
                    cout<<"\n\n\t\tNo of Hours Should be Greater than 1!!!";
                    Sleep(2000);
                    system("CLS");
                    case3();
                }
                //cout<<"\n\n\t\tEnter Driver ID:";
                //cin>>driverID;
                cout<<"\n\n\t\tEnter Car ID:";
                cin>>carID;
                    fstream file1,file2;


                    file1.open("Car.txt",ios::in);
                    file1>>cName>>mod>>cID>>RPH>>dID>>dExp;

                    while(!file1.eof())
                    {
                        if(carID == cID)
                        {
                            searchedDriverID = dID;
                            searchedDriverExp = dExp;
                            ratePerHour = RPH;
                            carName = cName;
                            searchedCarID = cID;

                            file2.open("Driver.txt",ios::in);
                            file2>>dID>>dName>>dExp>>IsAvailable;
                            while(!file2.eof())
                            {
                                if(searchedDriverID == dID)
                                {
                                    driverName = dName;
                                }
                                file2>>dID>>dName>>dExp>>IsAvailable;
                            }

                            countCar++;
                        }
                        /*
                        else
                        {
                            cout<<"\n\n\t\tNo Driver OR Car Found with this ID!!!!";
                            Sleep(2000);
                            countCar = 0;
                            countDriver = 0;

                        }
                        */
                        /*
                        else
                        {
                            cout<<"\n\n\t\tNor Car Found with this ID!!!";
                            Sleep(2000);
                            case3();
                        }
                        */
                        file1>>cName>>mod>>cID>>RPH>>dID>>dExp;
                    }
                    file1.close();
                    file2.close();

                    if(countCar == 0)
                    {
                        system("color C");
                        cout<<"\n\n\t\tNo Driver OR Car Found with this ID!!!!   if part";
                        Sleep(3000);
                        system("CLS");
                        system("color B");
                        case3();
                    }

                    else
                    {
                        fstream file3;
                        file3.open("Customer.txt", ios::out | ios::app);
                        file3<<" "<<customerID<<" "<<customerName<<" "<<email<<" "<<address<<" "<<searchedCarID<<" "<<carName<<" "<<ratePerHour<<" "<<ratePerHour*no_of_hours<<" "<<searchedDriverID<<" "<<driverName<<" "<<searchedDriverExp<<"\n";
                        //file3<<" "<<customerID<<" "<<email<<" "<<searchedCarID<<" "<<carName<<" "<<ratePerHour<<" "<<ratePerHour*no_of_hours<<" "<<searchedDriverID<<" "<<driverName<<" "<<searchedDriverExp<<" "<<address<<" "<<customerName<<"\n";
                        file3.close();
                        cout<<"\n\n\t\tRecord Inserted successfully!";
                        Sleep(2000);
                        system("CLS");
                        case3();
                    }
}


void allCustomers()

{

            cout<<"\n\n\n\t\t___________________All Customers___________________";
            fstream file;
            int searchedCarID,searchDriverID,ratePerHour,searchDriverExp;
            if(!file)
            {
                cout<<"\n\n\t\tFile Does Not Exist!!!";
                Sleep(2000);
                system("CLS");
                file.close();
                case3();
            }
            else
            {
              //int DExp;
            file.open("Customer.txt", ios::in);
            file>>customerID>>customerName>>email>>address>>searchedCarID>>carName>>ratePerHour>>bill>>searchDriverID>>driverName>>searchDriverExp;
            //file>>customerID>>customerName>>email>>address>>searchedCarID>>carName>>ratePerHour>>bill>>searchDriverID>>driverName>>searchDriverExp;




            while(!file.eof())
            {
                cout<<"\n\n\n\tCustomer ID:"<<customerID<<"||"<<"Name:"<<customerName<<"||"<<"Email:"<<email<<"||"<<"Address:"<<address<<"||"<<"Car ID:"<<searchedCarID<<"||"<<"Car Name:"<<carName<<"||"<<"RPH:"<<ratePerHour<<"||"<<"Bill:"<<bill<<"||"<<"Driver ID:"<<searchDriverID<<"||"<<"Driver Name:"<<driverName<<"||"<<"Driver Exp:"<<searchDriverExp<<"\n";
                file>>customerID>>customerName>>email>>address>>searchedCarID>>carName>>ratePerHour>>bill>>searchDriverID>>driverName>>searchDriverExp;
            }
            file.close();
            cout<<"\n";
            system("pause");
            system("CLS");
            case3();
            }


}

void deleteCustomer()
{
    fstream file,file1;
    int searchedCarID,searchDriverID,ratePerHour,searchDriverExp;
    int CusID;
    int token = 0;
    //int driverExp;
    cout<<"\n\n\n\t\t___________________Delete Customer___________________";
    cout<<"\n\n\t\tEnter Customer ID:";
    cin>>CusID;
    file.open("Customer.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tFile Does Not Exist!!!";
        Sleep(2000);
        file.close();
        system("CLS");
        case3();
    }
    else
    {
        file1.open("Customer1.txt",ios::out|ios::app);

        file>>customerID>>customerName>>email>>address>>searchedCarID>>carName>>ratePerHour>>bill>>searchDriverID>>driverName>>searchDriverExp;
        while(!file.eof())
        {

            if(CusID == customerID)
            {
                cout<<"\n\n\t\tCustomer Deleted!!!";
                token++;
                Sleep(2000);
                system("CLS");
            }
            else
            {
                file1<<" "<<customerID<<" "<<customerName<<" "<<email<<" "<<address<<" "<<searchedCarID<<" "<<carName<<" "<<ratePerHour<<" "<<bill<<" "<<searchDriverID<<" "<<driverName<<" "<<searchDriverExp<<"\n";
            }
            file>>customerID>>customerName>>email>>address>>searchedCarID>>carName>>ratePerHour>>bill>>searchDriverID>>driverName>>searchDriverExp;
        } //END OF WHILE LOOP
        if(token == 0)
        {
            cout<<"\n\n\t\tRecord Can Not Found!!!";
        }
        file.close();
        file1.close();
        remove("Customer.txt");
        rename("Customer1.txt","Customer.txt");
        system("CLS");
        case3();
    }
}


};

void case1(){
    int inner_choice;
    Car c1;
            inner_choice = c1.carChoice();
            if(inner_choice == 1)
            {
                c1.addCar();
            }
            else if(inner_choice == 2)
            {
                c1.allCars();
                //cout<<"c1.allCars()";
            }
            else if(inner_choice == 3)
            {
                c1.modifyCar();
                cout<<"c1.modifyCars()";
            }
            else if(inner_choice == 4)
            {
                c1.deleteCar();
                //cout<<"c1.deleteCar()";
            }
            else if(inner_choice == 5)
            {
                cout<<"\n\n\t\tInvalid Choice!!!!";
                system("CLS");
                MainMenu();
            }
            else
            {
                cout<<"\n\n\t\tInvalid Choice!!!!";
                Sleep(2000);
                system("CLS");
                case1();
            }
}
void case2(){
    int inner_choice;
    Driver d1;
            inner_choice = d1.driverChoice();
            if(inner_choice == 1)
            {
                d1.addDriver();
            }
            else if(inner_choice == 2)
            {
                d1.allDrivers();
                //cout<<"d1.allDrivers()";
            }
            else if(inner_choice == 3)
            {
                d1.modifyDriver();
                //cout<<"c1.modifyCars()";
            }
            else if(inner_choice == 4)
            {
                d1.deleteDriver();
                cout<<"d1.deleteDriver()";
            }
            else
            {
                cout<<"\n\n\t\tInvalid Choice!!!!";
                system("CLS");
                MainMenu();
            }
}

void case3(){
    int inner_choice;
    Customer C1;
            inner_choice = C1.customerChoice();
            if(inner_choice == 1)
            {
                //cout<<"C1.addCustomer()";
                C1.addCustomer();
            }
            else if(inner_choice == 2)
            {
                C1.allCustomers();
                //cout<<"c1.allCars()";
            }
            else if(inner_choice == 3)
            {
                C1.modifyCustomers();
                //cout<<"c1.modifyCars()";
            }
            else if(inner_choice == 4)
            {
                C1.deleteCustomer();
                //cout<<"c1.deleteCar()";
            }
            else if(inner_choice == 5)
            {
                system("CLS");
                MainMenu();
            }
            else
            {
                cout<<"\n\n\t\tInvalid Choice!!!!";
                Sleep(2000);
                system("CLS");
                case3();
            }
}

void MainMenu()
{
    int main_choice,inner_choice;
        system("CLS");
        cout<<"\n\n\n\t\t*********************************************************************";
        cout<<"\n\n\n\t\t___________________CAR RENTAL MANAGEMENT SCREEN!!!___________________";
        cout<<"\n\n\n\t\t*********************************************************************";
        cout<<"\n\n\t\t1) Car Management";
        cout<<"\n\n\t\t2) Driver Management";
        cout<<"\n\n\t\t3) Customer Management";
        cout<<"\n\n\t\t4) Exit";

        cout<<"\n\n\t\tEnter Choice:";
        cin>>main_choice;

        switch(main_choice)
        {
        case 1:
            {
                system("CLS");
                case1();
            break;
            }

        case 2:
            {
                system("CLS");
                case2();
                break;
                //case2Start:
            }
        case 3:
            {
                system("CLS");
                case3();
                break;
            }
        case 5:
            {
                system("CLS");
                main_menu();
                break;
            }

        }
}

void main_menu() {
    if(login()) {
        int main_choice,inner_choice;
        system("CLS");
        cout<<"\n\n\n\t\t*********************************************************************";
        cout<<"\n\n\n\t\t___________________CAR RENTAL MANAGEMENT SCREEN!!!___________________";
        cout<<"\n\n\n\t\t*********************************************************************";
        cout<<"\n\n\t\t1) Car Management";
        cout<<"\n\n\t\t2) Driver Management";
        cout<<"\n\n\t\t3) Customer Management";
        cout<<"\n\n\t\t4) Exit";

        cout<<"\n\n\t\tEnter Choice:";
        cin>>main_choice;

        switch(main_choice)
        {
            //case1Start:
        case 1:
            {
                system("CLS");
                case1();

            break;
            }

        case 2:
            {
                system("CLS");
                case2();
                break;
            }
        case 3:
            {
                system("CLS");
                case3();
                break;
            }
            case 4:
            {
                system("CLS");
                main_menu();
                break;
                //case2Start:
            }



        }
    }
}

bool login(){
    string uname;
    string pass;
    bool isLoggedin = false;
    cout<<"\n\n\n\t\t___________________Car Rental Login Screen!!!___________________";
    cout<<"\n\n\t\tEnter User Name:";
    cin>>uname;
    cout<<"\n\n\t\tEnter Password:";
    cin>>pass;
    //cout<<uname<<pass;
    //strcmp(uname,"zaid") == 0&& strcmp(pass,"123456") == 0
    //cout<<uname.length()<<pass.length();
    if(uname == "zaid" && pass == "123456"){
        isLoggedin = true;

        cout<<"\n\n\t\tYou are Logged In successfully.........";
        cout<<"\n\n\t\tLoading";
        char loading = 219;
        for(int i = 0;i<=20; i++){
            cout<<loading;
            Sleep(50);
        }
        system("CLS");
        return isLoggedin;
    } else{
        system("color 4");
        cout<<"\n\n\t\tLogIn Failed!!!!!";
        Sleep(2000);
        system("CLS");
        system("color B");
        login();
    }
}
int main()
{
    system("color B");
    main_menu();
    //if(login()) {

      //  cout<<"Hello Main!";
    //} else { cout<<"Else Main part!!!"; }
    return 0;
}
