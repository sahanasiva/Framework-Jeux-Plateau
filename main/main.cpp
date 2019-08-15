#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "echecs/Echecs.hpp"

using namespace std;

void lancerJeuDames(){
    cout<<"TEST lancerJeuDames"<<endl;
    cout<<"TEST a implementer"<<endl;
}

void lancerJeuEchecs(){
    cout<<"TEST lancerJeuEchecs"<<endl;
    Echecs p;
    p.lancerPartie();
    // delete p;
}

void lancerJeuFantasy(){
    cout<<"TEST lancerJeuFantasy"<<endl;
    cout<<"TEST a implementer"<<endl;
}

int main(){
    int choix = 0;
    while(choix == 0){
        cout<<endl;
        cout<<"Choix du jeu :"<<endl;
        cout<<"1: Dames francaises"<<endl;
        cout<<"2: Echecs classiques"<<endl;
        cout<<"3: Fantasy"<<endl;
        cout<<"> ";
        cin>>choix;
        if(choix==1 || choix==2 || choix==3) break;
        else choix = 0;
    }
    if(choix==1) lancerJeuDames();
    else if(choix==2)  lancerJeuEchecs();
    else if(choix==3)  lancerJeuFantasy();
    return 0;
}
