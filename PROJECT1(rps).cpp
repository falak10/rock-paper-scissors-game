#include <iostream>
#include <cmath>
#include <string>

using namespace std;

enum engamechoice {stone =1 , paper =2 , scissor =3};

enum enwinner{player =1 , computer =2 , draw=3};

struct stroundinfo{
    short roundnumber =0;
    engamechoice playerchoice;
    engamechoice computerchoice;
    enwinner winner;
    string winnername;
};

struct stgameresults{
    short gamerounds =0;
    short playerwintimes = 0;
    short computerwintimes = 0;
    short drawtimes = 0;
    enwinner gamewinner;
    string winnername ="";

};


int RoundNumber(int from, int to){

    int randnum = rand() % (to - from + 1) +from;

    return randnum;
}

engamechoice getcomputerchoice(){
    return (engamechoice)RoundNumber(1,3);
}

enwinner whowontheround(stroundinfo roundinfo){
    if (roundinfo.playerchoice == roundinfo.computerchoice)
    {
        return enwinner::draw;
    }
    switch (roundinfo.playerchoice)
    {
    case  engamechoice::stone:
        return (roundinfo.computerchoice == engamechoice::paper ? enwinner::computer : enwinner::player);
    case  engamechoice::paper:
        return (roundinfo.computerchoice == engamechoice::scissor ? enwinner::computer : enwinner::player); 
    case  engamechoice::scissor:
        return (roundinfo.computerchoice == engamechoice::stone ? enwinner::computer : enwinner::player);
    }
}

enwinner whowonthegame(short playerwintimes, short computerwintimes){

    if (playerwintimes > computerwintimes) return enwinner::player;
    else if (computerwintimes > playerwintimes) return enwinner::computer;
    else return enwinner::draw;
}

string choicename(engamechoice choice){

    string arrchoicename[3] = {"stone" , "paper" , "scissor"};
    return arrchoicename[choice - 1];
}

string winnername(enwinner winner){
    string arrwinnernames[3] = {"player" , "computer" , "no winner(draw)"};
    return arrwinnernames[winner - 1];
}

engamechoice readplayerchoice(){
    short choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissor? ";
        cin>>choice;
    } while (choice < 1 || choice > 3);
    return (engamechoice)choice;
}

void printroundresult(stroundinfo roundinfo){
    cout<<"\n____________Round ["<<roundinfo.roundnumber<<"]_______\n\n";
    cout<<"Player Choice: "<<choicename(roundinfo.playerchoice)<<endl;
    cout<<"Computer Choice: "<<choicename(roundinfo.computerchoice)<<endl;
    cout<<"Round Winner: ["<<roundinfo.winnername<<"]\n";
    cout<<"___________________________________\n"<<endl;
}

stgameresults playgame(short howmanyrounds){
    stroundinfo roundinfo;
    short playerwintimes =0 , computerwintimes=0 , drawtimes=0;

    for (short gameround = 1; gameround <= howmanyrounds; gameround++)
    {
        cout<<"\nRound ["<<gameround<<"] begins:\n";
        roundinfo.roundnumber =gameround;
        roundinfo.playerchoice = readplayerchoice();
        roundinfo.computerchoice = getcomputerchoice();
        roundinfo.winner = whowontheround(roundinfo);
        roundinfo.winnername = winnername(roundinfo.winner);

        if (roundinfo.winner == enwinner::player)
        {
           playerwintimes++;
        }else if (roundinfo.winner == enwinner::computer)
        {
           computerwintimes++;
        }
        else
        drawtimes++;

        printroundresult(roundinfo);
    }
    return {howmanyrounds, playerwintimes, computerwintimes, drawtimes, whowonthegame(playerwintimes,computerwintimes), winnername(whowonthegame(playerwintimes,computerwintimes))};
}

void startgame(){
    char playagain = 'Y';
    do
    {
       stgameresults gameresults = playgame(3);
       cout<<"\nGmae Over! Winner: "<<gameresults.winnername<<endl;

       cout<<"Do You Want To Play Again? (Y/N): ";
       cin>>playagain;

    } while (playagain == 'Y' || playagain == 'y');
    
}
int main() {
    
srand((unsigned)time(NULL));

startgame();

    return 0;
}