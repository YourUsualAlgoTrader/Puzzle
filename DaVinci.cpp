#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

//The nine squares and their 4 edge
bool *SetOfSquare[9][4];

//List of edge is red if his value is false, else it is green 
bool edge[24]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};

//List of pointer of each edges
bool *Edge[24];
int i;
int j;


string binaryCode;

void initialization(){
    for (int i=0;i<24;i++){
        Edge[i]=&edge[i];
    }

    //first square initialization
    for (int i = 0; i < 4; i++) {
        SetOfSquare[0][i]=&edge[i];
    }

    //Edge in common square1/square2
    SetOfSquare[1][0]=SetOfSquare[0][2];
    //Square 2 initialization
    for (int i = 4; i < 7; i++) {
        SetOfSquare[1][i-3]=&edge[i];
    }


    //Edge in common square2/square3
    SetOfSquare[2][0]=SetOfSquare[1][2];
    //Square 3 initialization
    for (int i = 7; i < 10; i++) {
        SetOfSquare[2][i-6]=&edge[i];
    }


    //Edge in common square1/square4
    SetOfSquare[3][1]=SetOfSquare[0][3];
    //Square 4 initialization
    SetOfSquare[3][0]=&edge[10];
    for (int i = 11; i < 13; i++) {
        SetOfSquare[3][i-9]=&edge[i];
    }


    //Edge in common square4/square5
    SetOfSquare[4][0]=SetOfSquare[3][2];
    //Edge in common square2/square5
    SetOfSquare[4][1]=SetOfSquare[1][3];
    //Square 5 initialization
    for (int i = 13; i < 15; i++) {
        SetOfSquare[4][i-11]=&edge[i];
    }



    //Edge in common square5/square6
    SetOfSquare[5][0]=SetOfSquare[4][2];
    //Edge in common square3/square6
    SetOfSquare[5][1]=SetOfSquare[2][3];
    //Square 6 initialization
    for (int i = 15; i < 17; i++) {
        SetOfSquare[5][i-13]=&edge[i];
    }



    //Edge in common square4/square7
    SetOfSquare[6][1]=SetOfSquare[3][3];
    //Square 7 initialization
    SetOfSquare[6][0]=&edge[17];
    for (int i = 18; i < 20; i++) {
        SetOfSquare[6][i-16]=&edge[i];
    }
    
    //Edge in common square7/square8
    SetOfSquare[7][0]=SetOfSquare[6][2];
    //Edge in common square5/square8
    SetOfSquare[7][1]=SetOfSquare[4][3];
    //Square 8 initialization
    for (int i = 20; i < 22; i++) {
        SetOfSquare[7][i-18]=&edge[i];
    }

    //Edge in common square8/square9
    SetOfSquare[8][0]=SetOfSquare[7][2];
    //Edge in common square6/square8
    SetOfSquare[8][1]=SetOfSquare[5][3];
    //Square 8 initialization
    for (int i = 22; i < 24; i++) {
        SetOfSquare[8][i-20]=&edge[i];
    }
}

bool testSquareColor(bool* Square[4]){
    return ((*Square[0]==*Square[1]) & (*Square[1]==*Square[2]) & (*Square[2]==*Square[3]));

}

bool testSetOfSquareColor(bool* SetOfSquare[9][4]){
    bool SquareMonochrome=false;
    for (int i=0; i<9;i++){
        if (testSquareColor(SetOfSquare[i])){
            SquareMonochrome=true;
            break;
        }
    }
    return(SquareMonochrome);
}
int main(){
    int count=0;
    initialization();

    for (int i=0;i<pow(2,24);i++){
        // Utiliser la bijection de la transformation binaire pour obtenir la couleur de chaque arête, 0 pour rouge et 1 pour vert
        string binaryCode = bitset<24>(i).to_string();
        for (int j = 0; j < binaryCode.length(); j++) {

            *Edge[j]=(binaryCode[j]=='1');

        }
        count= count+testSetOfSquareColor(SetOfSquare);
    }

    std::cout <<"The probability that none of the nine unit squres have four trading candles of the same colour is : "<< 1-count/pow(2,24) << std::endl;
    return 0;
}