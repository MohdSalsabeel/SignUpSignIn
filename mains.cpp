#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#include "LoginPage.h"
#include "ForgetPassword.h"
#include "TwoStepVerification.h"
#include "ThirdStepVerification.h"
#include "encrypted.h"
using std::ios;
using std::cerr;

using namespace std;

bool specialCharacter(string str_password){
    for(int i=0;i<str_password.size();++i){
        if(str_password[i]=='!' || str_password[i]=='@' || str_password[i]=='#' || str_password[i]=='$' || str_password[i]=='%' || str_password[i]=='^' || str_password[i]=='&' || str_password[i]=='*' || str_password[i]=='(' || str_password[i]==')'){
            return true;
        }
    }
    return false;
};

bool ischeck(string number){
    int c=0;
    for(int i=0;i<number.size();i++){
        if(isdigit(number[i])){
            c++;
        }
    }
    if(c==10){
        return true;
    }
    else{
        return false;
    }
}


int main(){

    User obj;

    string user_name1;
    string mobile_no1;
    string user_id1;
    string email_id1;
    string password1;
    string pin1;
    string imei_no1;
    string location1;
    string time1;

    loop:
    cout<<"**********************************************************"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"                1. Sign Up           "<<endl;
    cout<<"                2. Already Register/Sign In              "<<endl;
    cout<<"                3. Forget Password                      "<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"***********************************************************"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;


    switch(choice){

        case 1:{

            // we are creating file
            // we are opening file in write mode ,read mode and append mode
            fstream database_file;                                                        
            database_file.open("databaseRecordtest.txt",ios::out | ios::app | ios::in); 

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

            // long long int mobile=obj.mobile_no_int;
            // if(!isdigit(mobile)){
            //     goto mobile_loop;
            // }
            

            //bottom_mobile:
            
            // string str;
            str=to_string(obj.mobile_no_int);

            if(str.size()<10){
                cout<<"Mobile number must be ten digit"<<endl;
                goto mobile_loop;
            }

            if(ischeck(str)){
                //break;
                goto bottom_mobile_loop;
            }else{
                cout<<"Mobile must be integer"<<endl;
                //goto loop;
                //goto mobile_loop;
                exit(1);
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
                goto loop;
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

            // Here we are checking unique user id and mobile number and email id
            // If user wrote same id , mobile number and email id then go to registration form again , user must used different id,mobile number and email

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

            cout<<"Successfully Register"<<endl;

            database_file.close();

            //}

            goto loop;
        }
        case 2:{
            //User obj[5];

            

            LoginPage login_page_obj;
            

            if(login_page_obj.login()=="Successful"){
                cout<<endl;
                
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Go to Second Step Verification"<<endl;
                cout<<"----------------------------------------------------------"<<endl;
                cout<<endl;

                loginLoop:

                TwoStepVerification pin_obj;
                //pin_obj.correct_pin(obj);

                if(pin_obj.correct_pin()=="Successful"){
                    cout<<endl;
                    thirdStepLoop:
                    cout<<"----------------------------------------------------------"<<endl;
                    cout<<"Go to Third Step Verification"<<endl;
                    cout<<"**********************************************************"<<endl;
                    cout<<endl;
                    ThirdStepVerification third_step_verification_obj;
                    if(third_step_verification_obj.correct_third_step()=="Successful"){
                        cout<<"**********************************************************"<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                        cout<<" Main Page"<<endl;
                        cout<<"**********************************************************"<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                    }else{
                        cout<<"Please re-write correct input: "<<endl;
                        goto thirdStepLoop;
                    }
                }else{
                    cout<<"Invalid pin number"<<endl;
                    cout<<endl;
                    cout<<"Please re-write correct pin: "<<endl;
                    goto loginLoop;

                }
            }
            else{
                cout<<"Invalid user id and password"<<endl;
                goto loop;
            }

            break;
        }

        case 3:{
            //User obj[5];

            forget_loop:
            ForgetPassword forget_password_obj;
            if(forget_password_obj.forget()=="Successful"){
                cout<<"Reset password Successfully"<<endl;
                break;
            }else{
                cout<<"Please re-write correct pin and time"<<endl;
                goto forget_loop;
            }
            //cout<<obj[0].pin<<endl;
            
        }

        default:
            cout<<"Enter the correct choice"<<endl;

    }


    cout<<endl;
    getch();
    return 0;
}

