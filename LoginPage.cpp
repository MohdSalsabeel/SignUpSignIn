#include "LoginPage.h"
#include<iostream>
#include<fstream>
#include "encrypted.h"
using namespace std;


string LoginPage::login(){

        // Read the databaseRecordtest file
        std::ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        std::string word;

        // Creating the new database file
        std::ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        // We are taking input from user
        string login_user_id;
        string login_password;
        string login_time;
        
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        cout<<"Enter login password: "<<endl;
        cin>>login_password;
        cout<<"Enter current login time: "<<endl;
        cin>>login_time;

        // Here we are reading the file (databaseRecordtest)
        if(database_file.is_open()){
            while(database_file>> user_name>> mobile_no>> user_id>> email_id>> password>> pin>> imei_no>> location>> time){
                
                if(encrypt(login_user_id)==user_id && encrypt(login_password)==password){
                    
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                        new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                    }
                    return "Successful";
                }


            }
        }
        return "False";

};
