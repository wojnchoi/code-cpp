#include<iostream>

using namespace std;

class SinivelCap
{
public:
    void Take() const {cout<<"Sinivel cure"<<endl;}
};

class SneezeCap
{
public:
    void Take() const {cout<<"Sneeze cure"<<endl;}
};

class SnuffleCap
{
public:
    void Take() const {cout<<"Snuffle cure "<<endl;}
};

class ColdPatient
{
public:
    void TakeSinivelCap(const SinivelCap &cap) const {cap.Take();}
    void TakeSneezeCap(const SneezeCap &cap) const {cap.Take();}
    void TakeSnuffleCap(const SnuffleCap &cap) const {cap.Take();}

};
int main()
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient patient;
    patient.TakeSinivelCap(scap);
    patient.TakeSneezeCap(zcap);
    patient.TakeSnuffleCap(ncap);

    return 0;
}