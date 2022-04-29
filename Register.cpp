#include "Register.h"
#include<iostream>
#include<regex>
#include<fstream>
#include "encrypted.h"
//#include "User_module.h"
using namespace std;

bool specialCharacter(string str){
    for(int i=0;i<str.length();i++)
    {
        if ((str[i]>=48 && str[i]<=57)||
            (str[i]>=65 && str[i]<=90)||
            (str[i]>=97 && str[i]<=122))
            {
            continue;
            }
        else
        {
        //cout<<"String contains special character.\n";
        return true;
        //flag=1;
        //break;
        }
    }
    return false;
}

// bool ischeck(string number){
//     int c=0;
//     for(int i=0;i<number.size();i++){
//         if(isdigit(number[i])){
//             c++;
//         }
//     }
//     if(c==10){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool isValid(string s)
{
    const regex pattern("(0|91)?[7-9][0-9]{9}");
    if(regex_match(s, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Register::RegisterPage(){

    User obj;

    loop:
    
            fstream database_file;                                                        
            database_file.open("databaseRecordtest.txt",ios::out | ios::app | ios::in); 

            if(database_file.is_open())
            {

            cout<<"Enter the user name:"<<endl;
            cin>>obj.user_name;
            
            // Here we are extracting three word from user name
            string three_user_word;                                                  
            for(int i=0;i<3;i++){
                three_user_word+=obj.user_name[i];
            }

            
            mobile_loop:
            string str;
            cout<<"Enter the mobile number"<<endl;
            
            cin>>obj.mobile_no_int;

            

            //bottom_mobile:
            
            // string str;
            str=to_string(obj.mobile_no_int);

            

            //string s=to_string(number);
            char YesNo;
            bool value=false;
            if(isValid(str))
            {
                goto bottom_mobile_loop;
            }
            else
            {
                cout<<"Please write correct mobile number"<<endl;
                goto mobile_loop;
            }
            

            bottom_mobile_loop:
            // Here we are extracting three word from mobile number
            string three_mobile_word;                                                 
            for(int i=0;i<3;i++){
                three_mobile_word+=str[i];
            }

            // We are generating unique user id
            string unique_user_id=three_user_word+three_mobile_word;                   
            cout<<"User id is generated: "<<endl;
            cout<<unique_user_id<<endl;

            cout<<"Enter the email id:"<<endl;
            cin>>obj.email_id;

            specialLoop:

            cout<<"Enter the password:"<<endl;
            cin>>obj.password;

            // Password must be greater than 8 digit
            if(obj.password.size()>=8 ){                                                 
                goto specialCharaterBottom;
            }
            else{
                cout<<"Password must be greater than 8 character"<<endl;
                goto specialLoop;
            }

            specialCharaterBottom:

            if(specialCharacter(obj.password)){
                goto bottom1;
            }
            else{
                cout<<"Please write strong password"<<endl;
                goto specialLoop;    
            }

            

            bottom1:

            cout<<"Enter the pin:"<<endl;
            cin>>obj.pin;

            // Pin must be four digit
            if(obj.pin.size()==4){                                                           
                goto bottom2;
            }
            else{
                cout<<"Pin must be in 4 digit"<<endl;
                goto bottom1;
            }

            bottom2:

            cout<<"Enter the imei number"<<endl;
            cin>>obj.imei_no;

            cout<<"Enter the location"<<endl;
            cin>>obj.location;

            cout<<"Enter the time"<<endl;
            cin>>obj.time;

            
            database_file.close();

            //Here we are checking unique user id and mobile number and email id
            //If user wrote same id , mobile number and email id then go to registration form again , user must used different id,mobile number and email

            database_file.open("databaseRecordtest.txt",ios::in);            
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                // if user id present in database then it will goto sign up page
                if(encrypt(unique_user_id)==user_id1){
                    cout<<"Please write different name and mobile no"<<endl;
                    goto loop;  // It will goto sign up page
                    break;
                }
                // if same mobile present in database then it will goto sign up page , print message 
                if(encrypt(str)==mobile_no1){
                    cout<<"Mobile number must be different"<<endl;
                    goto loop;  // It will goto sign up page
                    break;
                }
                if(encrypt(obj.email_id)==email_id1){
                    cout<<"Email id must be different"<<endl;
                    goto loop;   // It will goto sign up page
                    break;
                }
                if(encrypt(obj.imei_no)==imei_no1){
                    cout<<"imei must be different"<<endl;
                    goto loop;   // It will goto sign up page
                    break;
                }
                
            }
            database_file.close();

            // We put all input into database in encrypted form 
            
            database_file.open("databaseRecordtest.txt",ios::out | ios::app);
            database_file<<encrypt(obj.user_name)<<" ";
            database_file<<encrypt(str)<<" ";
            database_file<<encrypt(three_user_word+three_mobile_word)<<" ";


            database_file<<encrypt(obj.email_id)<<" ";
            database_file<<encrypt(obj.password)<<" ";
            database_file<<encrypt(obj.pin)<<" ";
            database_file<<encrypt(obj.imei_no)<<" ";
            database_file<<encrypt(obj.location)<<" ";
            database_file<<encrypt(obj.time)<<" ";
            database_file<<endl;

            // cout<<"Successfully Register"<<endl;

            database_file.close();

            return "Successful";
            }

    
        return "False";
            //}

}
