#ifndef CANDIDATE_H
#define CANDIDATE_H

#include<iostream>
using namespace std;
class  Candidate {
    private:
        string sign;
        string name;
        string party;
        string sector;
        int votecount;
        char gender;
    public:
    Candidate();
    Candidate(string name,string sign,string party,string sector,int votecount,char gender);
    void setVotecount(int vc) { this->votecount=vc;}
    int getVotecount() const{return votecount;}
    string getSign()const{return sign;}
    string getName()const{return name;}
    string getSector()const{return sector;}
    char getGender()const{return gender;}
    
   virtual void display()const {
        cout << "Candidate Name : " << name << endl ;
        cout << "Sign : " << sign << endl ;
        cout << "Party : " << party << endl ;
        cout << "Sector : " << sector << endl<<endl<<endl ;
        
    }
    void displayre()const {
        cout << "Candidate Name : " << name << endl ;
        cout << "Sign : " << sign << endl ;
        cout << "Party : " << party << endl ;
        cout << "Sector : " << sector << endl<<endl<<endl ;
        cout << "VoteCount : " << votecount << endl<<endl<<endl ;
    }
	bool operator>(const Candidate& other) const {
        return votecount > other.votecount;
    }


};






#endif
