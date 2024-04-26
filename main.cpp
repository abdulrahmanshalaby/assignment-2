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
    string country;
    static int i;
Player players[18];
bool active[18]={false};
public:
    NationalTeam(string country){
        this->country=country;
    }
bool addPlayer(const Player&obj){
    if(i>18){
        cout<<"team full"<<endl;
        return false;
    }
    players[i]=obj;
    active[i]=true;
    cout<<"player number "<<i+1<<" added "<<endl;
    i++;
    return true;
}
bool removeplayer(string n){
    bool flag;
    for (int j = 0; j < 18; ++j) {
        if(players[j].get_name()==n){
            active[j]=false;
            flag=true;
        }

    }
    if(flag){
        cout<<"player(S) with name "<<n<<" where removed from team"<<endl;
        return true;}
    else {
        cout<<"No player with that name"<<endl;
        return false;}
}
int getNumOfPlayers(){
    int i=0;
    for (int j = 0; j < 18; ++j) {
        if(active[j]==true)
            i++;
    }
    return i;
}
int AvgHeight(){
    int i=0;
    int k=0;
    for (int j = 0; j < 18; ++j) {
        if (active[j] == true) {
            i++;
        }
    }
        for (int l = 0; l < 18; ++l) {
            if (i==0)
                return i;
            k=k+(players[l].get_height()/i);
        }


    return k;
}
Player OldestPlayer(){
    int k=0;
    long long oldest=57857824758;
    for (int j = 0; j < 18; ++j) {
        if(active[j]== true){
        if(players[j].get_yearofbirth()<oldest) {
            oldest = players[j].get_yearofbirth();
            k = j;
        }
        }

    }
    return players[k];
}
Player YoungestPlayer(){
        int k=0;
        int oldest=0;
        for (int j = 0; j < 18; ++j) {
            if(active[j]== true){
                if(players[j].get_yearofbirth()>oldest) {
                    oldest = players[j].get_yearofbirth();
                    k = j;
                }
            }

        }
        return players[k];
    }

Player HighestIntGoals(){
    int k=0;
    int Hgoals=0;
    for (int j = 0; j < 18; ++j) {
        if(active[j]== true){
            if(players[j].get_intgoals()>Hgoals) {
                Hgoals = players[j].get_intgoals();
                k = j;
            }
        }

    }
    return players[k];
}
 friend ostream& operator <<(ostream&os,NationalTeam& obj);
    void writeStatistics(ofstream& ofs) {
        ofs << "Team Country: " << country << endl;
        ofs << "Number of players: " << getNumOfPlayers() << endl;
        ofs << "Average height of players: " << AvgHeight() << endl;

        Player oldest = OldestPlayer();
        ofs << "Name and age of oldest player: " << oldest.get_name() << " (" << (2024 - oldest.get_yearofbirth()) << " years old)" << endl;

        Player youngest = YoungestPlayer();
        ofs << "Name and age of youngest player: " << youngest.get_name() << " (" << (2024 - youngest.get_yearofbirth()) << " years old)" << endl;

        ofs << "Average number of international goals of players: " << AvgIntGoals() << endl;

        Player highestGoals =HighestIntGoals() ;
        ofs << "Player with the highest international goals: " << highestGoals.get_name() << " (" << highestGoals.get_intgoals() << " goals)" << endl;
    }

    int AvgIntGoals(){
        int i=0;
        int k=0;
        for (int j = 0; j < 18; ++j) {
            if (active[j] == true) {
                i++;
            }
        }
        for (int l = 0; l < 18; ++l) {
            if (i==0)
                return i;
            k=k+(players[l].get_intgoals()/i);
        }


        return k;
    }

};
int NationalTeam::i=0;
ostream& operator <<(ostream&os,NationalTeam& obj){
    os<<"team country: "<<obj.country<<endl;
    for (int i = 0; i < 18; ++i) {
        if(obj.active[i]== true){
            os<<"player "<<i+1<<" "<<"info:"<<endl;
            os<<obj.players[i].get_name()<<endl;
        }

    }
    return os;
}
int main() {
Player a("ahmed",2004,180,22,"egyptian");
    Player b("ahme",2005,180,22,"egyptian");
    Player c("ramy",2005,180,22,"egyptian");

    NationalTeam ahly("egypt");
    ahly.addPlayer(a);
    ahly.addPlayer(b);
    ahly.addPlayer(c);
ofstream out("out.txt");
ahly.writeStatistics(out);


}
