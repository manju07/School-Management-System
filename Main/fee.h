
#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;






typedef struct fee
{
 string classes;//for classNo number
 string year;//for kannada
 float tuitionFee;//for english
 float sportsFee;//for science
 float uniformFee;//for maths
 float total;//for sStudy
};

void addFee()
{
    fee s1;
    fstream outfile ("feeInfo.txt",ios::app);
    cout<<"Class(Standard):";
    cin>>s1.classes;
    cout<<"Year:";
    cin>>s1.year;
    cout<<"SportsFee:";
    cin>>s1.sportsFee;
    cout<<"TuitionFee:";
    cin>>s1.tuitionFee;
    cout<<"UniformFee:";
    cin>>s1.uniformFee;
    s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
    outfile<<s1.classes<<" "<<s1.year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateFee()
{
    string classes,year;
    cout<<"\n Enter class(STANDARD):\n";
    cin>>classes;

    cout<<"\n Enter Year:\n";
    cin>>year;

    fee s1;
    fstream infile ("feeInfo.txt");
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
            if(i==0 && classes==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"SportsFee:";
            cin>>s1.sportsFee;
            cout<<"TuitionFee:";
            cin>>s1.tuitionFee;
            cout<<"UniformFee:";
            cin>>s1.uniformFee;
            s1.total=s1.sportsFee+s1.tuitionFee+s1.uniformFee;
            tempfile<<classes<<" "<<year<<" "<<s1.sportsFee<<" "<<s1.tuitionFee<<" "<<s1.uniformFee<<" "<<s1.total<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {
                tempfile<<line<<endl;
        }

    }
    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");

}

void listAllFees()
{
    ifstream file("feeInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !** FEES LIST **!\t\t\n\n\n";
    cout << setw(15) <<"CLASS" << setw(15) << "YEAR" << setw(15) << "S.FEE" <<setw(15) <<"T.FEE"<<setw(15)<<"U.FEE"<<setw(15)<<"TOTAL"<<endl<<endl;
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
        std::cout << '\n';

    }


}

void deleteFee()
{
    string classes,year;
    cout<<"\n Enter class(STANDARD):\n";
    cin>>classes;

    fee s1;
    fstream infile ("feeInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
    string line;
    int p=0;
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
            if(i==0 && classes==*it)
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
        else{
            cout<<"** successfully Deleted **\n";
        }


    }

    infile.close();
    tempfile.close();
    remove("feeInfo.txt");
    rename("tempInfo.txt","feeInfo.txt");
}
