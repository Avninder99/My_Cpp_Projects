#include<iostream>
#include<ctime>
using namespace std;

class bank_account {

    private:

        int acc_number,balance,pin;
        string acc_holder_name,acc_type;
        bool uninitialized = true;

    public:

        void initialize(){
            if(this->uninitialized){
                cout << "Add Account Holder Name -> " << endl;
                cin >> acc_holder_name;
                cout << "Add Account number -> " << endl;
                cin >> acc_number;
                cout << "Add Account type ->  Current OR Saving (Enter one only)" << endl;
                cin >> acc_type;
                srand(time(0));
                pin = 1000 + ( std::rand() % ( 9999 - 1000 + 1 ) );
                balance = 0;
                uninitialized = false;
                cout << "##################################################################" << endl;
                cout << "Your account pin is -> " << pin << endl;
                cout << "##################################################################" << endl;
            }else{
                cout << "Same Account can be initialized once only !!!" << endl;
            }
        }

        bool validator(){
            int pincode;
            cout << "Enter 4 digit pin of your account -> ";
            cin >> pincode;
            if(pincode == this->pin){
                return true;
            }else{
                cout << " Invalid Pin Entered !!!" << endl << endl;
                return false;
            }
            cout << endl;
        }

        void depositor(){
            if(this->validator()){
                int amt;
                cout << " Add the amount you wish to Deposit -> ";
                cin >> amt;
                balance += amt;
            }
        }

        void withdrawl(){
            if(this->validator()){
                int amt;
                cout << " Add the amount you wish to withdrawl -> ";
                cin >> amt;
                if(amt <= balance){
                    balance -= amt;
                }else{
                    cout << "  Insufficient Balance !!!" << endl;
                }
                
            }
        }

        void display_info(){
            if(this->validator()){
                cout << endl << "-------------- Account information ------------------" << endl;
                cout << " Account holder name -> " << acc_holder_name << endl;
                cout << " Account number -> " << acc_number << endl;
                cout << " Your balance is -> " << balance << endl;
                cout << "-----------------------------------------------------" << endl << endl;
            }
        }

        void statement(){
            if(this->validator()){
                cout << endl << "-----------------------------------------------------" << endl;
                cout << " Your balance is -> " << balance << endl;
                cout << "-----------------------------------------------------" << endl << endl;
            }
        }

        bool checker(int num){
            if(num == this->acc_number){
                return true;
            }else{
                return false;
            }
        }
};

int main(){

    bank_account acc[5];
    int n1,n2=1,counter1=0,main_num=0,num9=0;

    cout << "##############################################################################" << endl << endl;
    cout << "                             BANKING SYSTEM PROJECT" << endl << endl;
    cout << "##############################################################################" << endl << endl;


    while(n2!=3 && counter1 < 100){
        cout << "***********************************************************************" << endl << endl;
        cout << "  Access on behalf of -> " << endl << "                     BANK           (1)" << endl <<"                     Account holder (2)" << endl;
        cout << "                     For EXIT PRESS (3)" << endl << endl << "  Enter Choice -> ";
        cin >> n2;
        cout << endl;

        if(n2 == 1){
            do{
                //////////////////////////////////////////////////////////////////////////////////////////////
                cout << "***********************************************************************" << endl << endl;
                cout << "              For Creating bank Account        PRESS '1'" << endl;
                //cout << "              For Depositing money in account  PRESS '2'" << endl;
                cout << "              For Knowing account info         PRESS '3'" << endl;
                //cout << "              For Knowing balance in account   PRESS '4'" << endl;
                cout << "              For EXIT                         PRESS '5'" << endl << endl;
                cout << "  what you want to do -> ";
                cin >> n1;
                cout << endl;
                //////////////////////////////////////////////////////////////////////////////////////////////

                if(n1==1){
                    acc[num9].initialize();
                    num9++;
                }else if(n1==2){
                    int num7,num8;
                    cout << "Enter Account Number -> ";
                    cin >> num7;
                    for(int i=0;i<5;i++){
                        if(acc[i].checker(num7)){
                            num8 = i;
                        }
                    }
                    acc[num8].depositor();
                }else if(n1==3){
                    int num7,num8;
                    cout << "Enter Account Number -> ";
                    cin >> num7;
                    for(int i=0;i<3;i++){
                        if(acc[i].checker(num7)){
                            num8 = i;
                        }
                    }
                    acc[num8].display_info();
                }else if(n1==4){
                    int num7,num8;
                    cout << "Enter Account Number -> ";
                    cin >> num7;
                    for(int i=0;i<3;i++){
                        if(acc[i].checker(num7)){
                            num8 = i;
                        }
                    }
                    acc[num8].statement();
                }
                cout << endl;
                counter1++;
            }while(n1!=5 && counter1 < 100);
        }
        
        else if(n2 == 2){
            int num5,num6;
            cout << "Enter Account Number -> ";
            cin >> num5;
            for(int i=0;i<3;i++){
                if(acc[i].checker(num5)){
                    num6 = i;
                }
            }
            do{
                /////////////////////////////////////////////////////////////////////////////////////////////
                cout << "***********************************************************************" << endl << endl;
                cout << "              For Depositing money in account  PRESS '1'" << endl;
                cout << "              For Withdrawing money            PRESS '2'" << endl;
                cout << "              For Knowing account info         PRESS '3'" << endl;
                cout << "              For Knowing balance in account   PRESS '4'" << endl;
                cout << "              For EXIT                         PRESS '5'" << endl;
                cout << "what you want to do -> ";
                cin >> n1;
                cout << endl;
                /////////////////////////////////////////////////////////////////////////////////////////////
                if(n1==1){
                    acc[num6].depositor();
                }else if(n1==2){
                    acc[num6].withdrawl();
                }else if(n1==3){
                    acc[num6].display_info();
                }else if(n1==4){
                    acc[num6].statement();
                }
                cout << endl << endl;
                counter1++;
            }while(n1!=5 && counter1 < 100);
        }
        counter1++;
    }
    return 0;
}