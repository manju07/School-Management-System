#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;



typedef struct staff
{
 string id;// for staff id
 string fName;//for student first name
 string lName;//for student last name
 string qualification;//for Registration No number
 string mNumber;//for class info
 string pay;//Pay of the Teacher
};


void newStaffRegistration()
{
    fstream outfile ("staffInfo.txt",ios::app);
    staff s1;
    cout<<"StaffId:";
    cin>>s1.id;
    cout<<"FirstName:";
    cin>>s1.fName;
    cout<<"LastName:";
    cin>>s1.lName;
    cout<<"Pay:";
    cin>>s1.pay;
    cout<<"Qualification:";
    cin>>s1.qualification;
    cout<<"Mobile Number:";
    cin>>s1.mNumber;
    outfile<<s1.id<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}
void updateStaffInform()
{
    string sId;
    cout<<"\n Enter staff Id:\n";
    cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && sId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName:";
            cin>>s1.fName;
            cout<<"LastName:";
            cin>>s1.lName;
            cout<<"Pay:";
            cin>>s1.pay;
            cout<<"Qualification:";
            cin>>s1.qualification;
            cout<<"Mobile Number:";
            cin>>s1.mNumber;
            tempfile<<sId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.pay<<" "<<s1.qualification<<" "<<s1.mNumber<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {

            tempfile<<line<<endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}
void deleteStaffInform()
{
        string sId;
    cout<<"\n Enter staff Id:\n";
    cin>>sId;

    staff s1;
    fstream infile ("staffInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {

        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && sId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n\n ** deleted successfully**\n";

        }
    }
    infile.close();
    tempfile.close();
    remove("staffInfo.txt");
    rename("tempInfo.txt","staffInfo.txt");

}

void listOfStaffs()
{

    fstream file ("staffInfo.txt");
    staff s1;
cout<<endl<<"\t\t\t\t !** STAFF LIST **!\t\t\n\n\n";
    cout<<setw(15)<<"S.ID"<<setw(15)<<"F.NAME:"<<setw(15)<<"L.NAME"<<setw(15)<<"PAY"<<setw(15)<<"QUALIFICATION"<<setw(15)<<"M.NUMBER"<<endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        cout<<endl;
    }
        cout<<endl;

}
