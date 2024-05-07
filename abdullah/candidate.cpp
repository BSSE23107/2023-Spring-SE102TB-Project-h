#include "candidate.h"


Candidate::Candidate(){
        sign="";
        name="";
        party="";
        sector="";
        gender=' ';
        votecount=0;            
    }
Candidate::Candidate(string name,string sign,string party,string sector,int votecount,char gender){
        this->name = name;
        this->sign = sign;
        this->party = party;
        this->sector = sector;
        this->votecount = votecount;
        this->gender = gender;
    }