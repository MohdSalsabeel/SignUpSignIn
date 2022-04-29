#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>

#include "Register.h"
#include "LoginPage.h"
#include "ForgetPassword.h"
#include "TwoStepVerification.h"
#include "ThirdStepVerification.h"
#include "encrypted.h"
using std::ios;
using std::cerr;

using namespace std;




int main(){

    

    loop1:
    
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
             Register registerobj;
             if(registerobj.RegisterPage()=="Successful"){
                 cout<<"Successfully Register"<<endl;
                 goto loop1;
             }
             else{
                 cout<<"Please re-write input: "<<endl;
                 goto loop1;
             }

            
        }
        case 2:{

            LoginPage login_page_obj;
            

            if(login_page_obj.login()=="Successful"){
                cout<<endl;
                
                cout<<"----------------------------------------------------------"<<endl;
                cout<<"Go to Second Step Verification"<<endl;
                cout<<"----------------------------------------------------------"<<endl;
                cout<<endl;

                loginLoop:

                TwoStepVerification pin_obj;
        
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
                goto loop1;
            }

            break;
        }

        case 3:{

            forget_loop:
            ForgetPassword forget_password_obj;
            forget_password_obj.forget();
            
        }

        default:
            cout<<"Enter the correct choice"<<endl;
            goto loop1;

    }
    cout<<endl;
    getch();
    return 0;
}

