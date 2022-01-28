#include <iostream>

#define clear system("cls");
#define setbuf setbuf(stdin, NULL);
using namespace std;

class HospitalMain {

public:
    void hall();
private:
    void option();
    void patient();
    void consult();

};

void HospitalMain::hall(){
    int ans;

    while(true){
    cout << "\n\n\tWelcome To GREYLAKE register center.\n";
    cout << "\tTake the necessary steps to fill your registration.\n";
    cout<< "\n\n\tPress 1 to continue.\n\n";
    cin >> ans;
    clear;

    if(ans==1)
        option();
    }
}


void HospitalMain::option() {
    int ans;
    bool checkp;

    while(true){
    cout<< "\n\n\t1.Register a patient.\n\t2. Set a consult with a doctor.";
    cin >> ans;
    setbuf;

    if(ans==1)
        patient();
    else if(ans==2){
        // checkp = checkPatient_exist();
        if(checkp==false)
            patient();

        consult();
    }
    else
        cout << "\n\n\tChoose an existing option." << endl;
    }
}

void HospitalMain::patient() {
    cout << "go";
}

void HospitalMain::consult() {
    cout <<"yes";
}






class HospitalLog {
public:
    
    void checkPatient_exist_db(string name, string birthday);
    bool checkPatient_exist();

};

bool HospitalLog::checkPatient_exist() {
    bool toreturn;

    toreturn = false;
    return toreturn;
} 



int main() {

    HospitalMain *show = new HospitalMain();

    show->hall();

    return 0;
}
