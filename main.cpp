#include <iostream>
#include<fstream>
#include<vector>
#include<String>
using namespace std;
class Player{
    string name;
    int year_of_birth;
    int height;
    int int_goals;
    string nationality;
public:

    Player(string name="",int year=0,int h=0,int ig=0,string nationality=""){
        this->name=name;
        year_of_birth=year;
        height=h;
        int_goals=ig;
        this->nationality=nationality;
    }
public:
     void set_name(string n){
         name=n;
     }
    void set_yearofbirth(int n){
        year_of_birth=n;
    }
    void set_intgoals(int n){
         int_goals-n;
     }
    void set_height(int n){
        height=n;
    }
    void set_nationality(string n){
        nationality=n;
    }
  string get_name(){
         return name;
     }
    int get_yearofbirth(){
        return year_of_birth;
    }
    int get_intgoals(){
        return int_goals;
    }
    int get_height(){
        return height;
    }
    string get_nationality(){
        return nationality;
    }
};
class NationalTeam{
    static int i;
Player players[18];
bool active[18]={false};
public:
bool addPlayer(const Player&obj){
    if(i>18){
        cout<<"team full";
        return false;
    }
    players[i]=obj;
    active[i]=true;
    cout<<"player number "<<i+1<<" added ";
    i++;
    return true;
}
bool removeplayer(string n){
    bool flag;
    for (int j = 0; j < sizeof (players); ++j) {
        if(players[j].get_name()==n){
            active[j]=false;
            flag=true;
        }
        if(flag)
            return true;
        return false;
    }
}
};
int NationalTeam::i=0;
int main() {

}
