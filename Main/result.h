#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;



typedef struct result
{
 string rId;//for Registration No number
 string classes;//for classNo number
 string kannada;//for kannada
 string english;//for english
 string science;//for science
 string maths;//for maths
 string sStudy;//for sStudy
};



void newResultAdd()
{
    fstream outfile ("resultInfo.txt",ios::app);
    result s1;
    cout<<"Registration Id:";
    cin>>s1.rId;
    cout<<"Class:";
    cin>>s1.classes;
    cout<<"Kannada:";
    cin>>s1.kannada;
    cout<<"English:";
    cin>>s1.english;
    cout<<"Maths:";
    cin>>s1.maths;
    cout<<"science:";
    cin>>s1.science;
    cout<<"s.study:";
    cin>>s1.sStudy;
    outfile<<s1.rId<<" "<<s1.classes<<" "<<s1.kannada<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;

}
void updateResultAdd()
{
    string rId,classes;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Class:\n";
    cin>>classes;

    result s1;
    fstream infile ("resultInfo.txt");
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
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"Kannada:";
            cin>>s1.kannada;
            cout<<"English:";
            cin>>s1.english;
            cout<<"Maths:";
            cin>>s1.maths;
            cout<<"science:";
            cin>>s1.science;
            cout<<"s.study:";
            cin>>s1.sStudy;
            tempfile<<rId<<" "<<classes<<" "<<s1.kannada<<" "<<s1.english<<" "<<s1.maths<<" "<<s1.science<<" "<<s1.sStudy<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {
            tempfile<<line<<endl;

        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");


}
void deleteResult()
{

        string rId,classes;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Class:\n";
    cin>>classes;

    result s1;
    fstream infile ("resultInfo.txt");
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
            if(i==0 && rId==*it)
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
            cout<<"\n\n ** deleted successfully**\n\n";
        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");



}

void overAllClassResult()
{
    string classes;
    cout<<"Enter the class:";
    cin>>classes;

    int failCount=0,passCount=0,totalCount=0;

    ifstream file("resultInfo.txt");
    string line;
    int check_fail=0;
    while(std::getline(file, line))
    {
            check_fail=0;
            istringstream ss(line);
            std::istream_iterator<std::string> begin(ss), end;
            //putting all the tokens in the vector
            std::vector<std::string> arrayTokens(begin, end);
            vector<string>::iterator it;
            int flag=0,i=0;
            for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
            {
                string p=*it;
                stringstream geek(p);
                // The object has the value 12345 and stream
                // it to the integer x
                int x = 0;
                geek >> x;
                if(flag==1)
                {
                    if(x<35)
                    {
                        check_fail=1;
                        failCount++;
                        break;
                    }
                    else
                    {
                        continue;
                    }

                }
                if(classes==(*it) && i==1)
                {
                        flag=1;
                        totalCount++;
                }
                i++;

            }
            if(check_fail==0 && flag==1)
            {
                passCount++;
            }

        }
        cout<<endl<<"\t\t\t\t !** CLASS "<<classes<<" RESULT**!\t\t\n\n\n";
        cout<<"Total No. of Failed Students:"<<failCount<<endl;
        cout<<"Total No. of Passed Students:"<<passCount<<endl;
        cout<<"Total No. of Students:"<<totalCount<<endl;
        cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
        cout<<endl;

}

void schoolResult()
{
    int failCount=0,passCount=0,totalCount=0;
    ifstream file("resultInfo.txt");
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            string p=*it;
            stringstream geek(p);
            // The object has the value 12345 and stream
            // it to the integer x
            int x = 0;
            geek >> x;

            if(x<35 && i>1)
            {
                flag=1;
                failCount++;
                break;
            }
            i++;

        }
        if(flag==0)
        {
            passCount++;

        }


        totalCount++;
    }

    cout<<"Total No. of Failed Students:"<<failCount<<endl;
    cout<<"Total No. of Passed Students:"<<passCount<<endl;
    cout<<"Total No. of Students:"<<totalCount<<endl;
    cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
    cout<<endl;
}

void studentResult()
{
    string rId;
    cout<<"\nEnter student Reg.ID:";
    cin>>rId;
    ifstream file("resultInfo.txt");
    string line;
    int s_result=1;
    string r1;
    int total=0;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
             string p=*it;
             stringstream geek(p);
             // The object has the value 12345 and stream
             // it to the integer x
             int x = 0;
            geek >> x;
            if(flag==1)
            {
                total+=x;
                if(x<35)
                {
                    s_result=0;
                    break;
                }
                else
                {
                    continue;
                }

            }
            if(rId==(*it) && i==0)
            {
                flag=1;
                it++;
                r1=line;
            }
            else
                break;

        }
    }
        cout<<endl<<"\t\t\t\t !** STUDENT RESULT **!\t\t\n\n\n";
        cout<<setw(10)<<"Reg.Id";
        cout<<setw(10)<<"Class";
        cout<<setw(10)<<"Kannada";
        cout<<setw(10)<<"English";
        cout<<setw(10)<<"Maths";
        cout<<setw(10)<<"Science";
        cout<<setw(10)<<"S.study";
        cout<<endl;
        istringstream ss(r1);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            cout<<setw(10)<<*it;
        }

        if(s_result==0)
        {
            cout<<"**Result is Fail**";
        }
        else
        {
            cout<<"\n\n\tTotal Score->"<<total<<endl;
            cout<<"\tTotal Percentage(%)->"<<((double)total/500)*100<<"%"<<endl;
            cout<<"\t**Result is Pass**";
        }
        cout<<endl;
}
