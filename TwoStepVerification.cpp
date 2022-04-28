#include "TwoStepVerification.h"
#include<fstream>
#include<iostream>
#include "encrypted.h"
#include "User_module.h"
using namespace std;

std::string TwoStepVerification::correct_pin(){
    std::string pin_number;

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);

        cout<<"Enter pin number : "<<endl;
        cin>>pin_number;

        // We are reading the file
        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            // checking the condition if pin is valid or not
            if(encrypt(pin_number)==pin){
                //cout<<"Successfully "<<endl;
                return "Successful";

            }
        }
        return "False";
};

