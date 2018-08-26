#include <iostream>
using namespace std;

class person{
    public:
    void set_person_data (string person_name, string person_address){
        name    = person_name;
        address = person_address;
    }
    protected:
      string name;
      string address;
};

class money{
    public:
    int basic_fee=1000;
    
    void set_basic_fee(int fee){
        basic_fee = fee;
    }
    
};


class patient: public person, public money{
    public:
    patient(int p_id, string p_name, string p_address, string h_name, int j_year){
        patient_id = p_id;
        name = p_name;
        address = p_address;
        hospital_name = h_name;
        joining_year = j_year;

    }
    
    void set_hospital_data(int j_year, string h_name){
        joining_year = j_year;
        hospital_name = h_name;
    }
    
    void get_hospital_data(){
        cout << "Patient address                = " << address <<"\n";
        cout << "Hospital name                  = " << hospital_name <<"\n";
        cout << "Year of joining the hospital   = " << joining_year <<"\n";

    }
    
    int total_fee(int fee_charge){
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        int total_fee = fee_charge + basic_fee;
        cout << "Patient total charged fee      = " << total_fee <<"\n";
        return total_fee ;
    }
    protected:
        int patient_id;
        string hospital_name;
        int joining_year;
};


int  main(){
    int patient_id;
    int joining_year;
    string patient_name;
    string hospital_name;
    string address;
    cin<<"Enter patient_id"<<patient_id<<endl;
    cin<<"Enter name"<<patient_name<<endl;
    cin<<"Enter joining year"<<joining_year<<endl;
    cin<<"Enter hospital name"<<hospital_name<<endl;
    cin<<"Enter patient address"<<patient_address<<endl;
    
    patient p(patient_id, patient_name, address, hospital_name, joining_year );
    p.get_hospital_data();
    p.set_hospital_data(2016, "RML Hospital");
    p.get_hospital_data();
    p.total_fee(500);
    
    
}
