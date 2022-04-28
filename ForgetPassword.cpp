#include "ForgetPassword.h"
#include<iostream>
#include<fstream>
#include "encrypted.h"
#include "User_module.h"
using namespace std;

string ForgetPassword::forget(){
    
        // We have open databaseRecordtest.txt file in read mode
        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        string pins;
        string times;
        cout<<"Enter the pin "<<endl;
        cin>>pins;
        cout<<"Enter the sign up time "<<endl;
        cin>>times;


        // We are reading the file 
        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            // Checking the pins if it is valid or not
            //new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
            if(encrypt(pins)==pin && encrypt(times)==time){
                string new_password;
                cout<<"Enter the new password"<<endl;
                cin>>new_password;
                string n;
                cout<<"Enter the user_id"<<endl;
                cin>>n;
                //password=encrypt(new_password);
                //new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                database_file.close();
                database_file.open("databaseRecordtest.txt",ios::in);
                while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                    // cout<<"Enter the user_id"<<endl;
                    // cin>>n;
                    if(n==user_id){
                        new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< encrypt(new_password) <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                        break;
                    }else{
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    }
                }
                database_file.close();
                new_database_file.close();
                remove("databaseRecordtest.txt");
                rename("newDatabaseRecordtest.txt","databaseRecordtest.txt");
                //cout<<"Reset password successfully "<<endl;
                return "Successful";
                

            }
        }
        return "False";
    
}
