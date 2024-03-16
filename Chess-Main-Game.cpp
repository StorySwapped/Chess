#include <stdio.h>
#include <time.h>
#include <ios>
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include<cstdlib>
#include<thread>
#include "validate.h"
#include "util.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include "check.h"
#include "specialmoves.h"
#include "mate.h"
#include "2.h"


bool sc = 0;
int choice=0;

int enpw=0, enpb=0;

bool s2f=0;
bool rff=0;
bool lwr=0;

bool rsgn=0, whndshk=0, bhndshk=0;

char y=0, y11=0, y2=0;

bool blight=1, wlight=1, lgtn=0, inw=1, inb=1;

std::ofstream of;
std::ifstream iof;

std::string pathout;
std::string pathin;

 int tm = time(0);
 time_t wtime=0, btime=0;

bool inputv(std::string b[8][8]);
void menu();

void foo(){
      while(1){
          char x;
          x =getchar();
          x=' ';
          if(x==' ') {lwr=0;}
      }
}

void bsleep(){
for (int i =0 ; i < 15; i++){
    system("sleep 1");
    if(inb==0) return;
}
if(inb==1) {std::cout << "You ran out of time; White won! ";std::exit(0);}
}

void wsleep() 
{
    for (int i = 0; i < 15; i++) 
    {
        system("sleep 1");
        if (inw == 0) return;
    }
    if (inw == 1) { std::cout << "You ran out of time; Black won! "; std::exit(0); }
}

int main(){
    std::string b [8][8];

    

    if(sc)system("clear");
    menu();
     init(b);
std::thread tl(print, b);
        tl.detach();


        system("sleep 1");
      if(lwr){
          std::thread t1(foo);
          t1.detach();
      }
      if(lgtn){
      bool z=0;
      while(1){
         if(z==0){
             inw=1;
           std::thread t1(wsleep);
           t1.detach();
           if(inputv(b) == 0) break;
           inw=0;
         }

         if(z==1){
             inb=1;
           std::thread t1(bsleep);
           t1.detach();
           if(inputv(b) == 0) break;
           inb=0;
         }
         if(z==0) z=1;
         else z=0;
      }
      }

     while(1){
     if(inputv(b) == 0) break;
     if(rff==0) lwr=0;
 }
}


void menu(){

    int cy=0;
    system("clear");
    do{
        cy=0;
        std::cout << "\n \t\t\t\t\t\t\t1)New Game\n\t\t\t\t\t\t\t2)Load Game\n\t\t\t\t\t\t\t3)Quit\n\t\t\t\t\t\t\t\n\t\t\t\t\t\t\tChoose an Option:";
        std::cin >> cy;
        std::cin.ignore();
        std::cin.clear();
    }while(cy!=1 && cy!=2 && cy!=3);

    if(cy==1){

    do{
        std::string g;
        choice=0;
        system("clear");
        std::cout << "\n \t\t\t\t\t\t\tChoose A Game Mode\n\t\t\t\t\t\t\t1)Classic\n\t\t\t\t\t\t\t2)Rapid\n\t\t\t\t\t\t\t3)Blitz\n\t\t\t\t\t\t\t4)Lightening\n\t\t\t\t\t\t\tChoose an Option:";
        std::cin >> g;
        choice = static_cast<int>(g[0]) - '0';
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);
    if(choice==2){
      wtime=600;
     btime=600;
    }

    else if(choice==3){
      wtime=300;
     btime=300;
    }
    if(choice==4){
        lgtn=1;
    }
}
if(cy==2){

    
        rff=1;
        do{
           std::cout << "\n\t\t\t\t\t\t\tEnter Path of game file: ";
           std::cin >> pathin;
           iof.open(pathin);
        }while(!iof);
        iof >> choice;

    if(choice==2){
      wtime=600;
     btime=600;
    }

    else if(choice==3){
      wtime=300;
     btime=300;
    }
    if(choice==4){
        lgtn=1;
    }

    int tz=0;
do{
    std::string g;
    std::cout << "\n\t\t\t\t\t\t\tLoad with replay feature on? (Enter 1 for Yes, 0 for No): ";
    std::cin >> g;
    tz = static_cast<int>(g[0]) - '0';
    }while (tz !=0 && tz !=1);
if(tz==0) lwr=0;
else if(tz==1) lwr=1;

}

    do{
        std::string g;
        y2=' ';
       std::cout << "\n\t\t\t\t\t\t\tDo you want to save the game to a file? ";
       std::cin >> g;
      y2=g[0];
    }while(y2!='Y' && y2!='N' && y2!='y' && y2!='n');

    if(y2=='Y' || y2 == 'y'){
        s2f=1;
        do{
           std::cout << "\n\t\t\t\t\t\t\tEnter Path of file: ";
           std::cin >> pathout;
           of.open(pathout);
        }while(!of);
    }
of<<choice;
of.close();
}




bool inputv(std::string b[8][8])
{
    static bool t = 0;

    if (lgtn && t == 0) inw = 1;
    if (lgtn && t == 1) inb = 1;
    time_t tmp = time(0);

    static size_t ic = 0;
    /* std::ofstream of; */

    bool n = check(b);
    if (n == true) {
        if (c == 'W') std::cout << "White is in Check!\n";
        else if (c == 'B') std::cout << "Black is in Check!\n";
    }
    if (n == 1) {
        if (c == 'W') {
            bool m = (wmate(b));
            if (m == 1) {
                std::cout << "White is mated\n";
                Blackwon();
                system("sleep 10");
                return 0;
            }
        }
        else if (c == 'B') {
            bool m = bmate(b);
            if (m == 1) {
                std::cout << "Black is mated\n";
                Whitewon();
                system("sleep 10");
                return 0;
            }
        }
    }

    if (stalemate(b) == 1) {
        std::cout << "\nStalemate\n";
        /* Stalemate(); */
        return 0;
    }

    bool vv = false;
    bool v1 = false;
    bool v2 = false;

    std::string input{ " " };
    bool g = false;

    while (vv == false) {
        if (input != "") {
            if (t == false) std::cout << "White's turn (Enter S to save, R to resign, H to offer a draw): ";
            else std::cout << "Black's turn (Enter S to save, R to resign, H to offer a draw):  ";
        }
        if (input == "--") { g = true; break; }
        if (!lgtn) {
            if (input == "R") {
                if (t == 1) {
                    std::cout << "White Won! ";
                    return 0;
                }
                else {
                    std::cout << "Black Won!";
                    return 0;
                }
            }
            if (input == "H") {
                char o = 0;
                std::cout << "\nPress H to accept handshake or D to deny\n";
                do {
                    std::cin >> o;
                } while (o != 'H' && o != 'D');
                if (o == 'H') {
                    std::cout << "\nDraw!\n";
                    return 0;
                }
                else {
                    std::cout << "\nYour opponent refused the draw!\n";
                    input = "     ";
                    continue;
                }
            }
        }

        if (rff && !s2f) {
            std::getline(iof, input);
            if (input[0] == 'w' || input[0] == 'b') {
                if (input[0] == 'w') {
                    input[0] = '0';
                    wtime = std::stoi(input);
                    std::getline(iof, input);
                    if (input[0] == 'b') {
                        input[0] = '0';
                        btime = std::stoi(input);
                    }

                }
            }
            std::getline(iof, input);
            std::cout << input;
            if (iof.eof()) rff = 0;
        }

        else if (rff && s2f) {
            std::getline(iof, input);
            if (input[0] == 'w' || input[0] == 'b') {
                if (input[0] == 'w') {
                    input[0] = '0';
                    wtime = std::stoi(input);
                    of.open(pathout, std::ios::app);
                    of << "w" + std::to_string(wtime);
                    of << '\n';
                    std::getline(iof, input);
                    if (input[0] == 'b') {
                        input[0] = '0';
                        btime = std::stoi(input);
                        of << "b" + std::to_string(btime);
                        of << '\n';
                        of.close();
                    }

                }
            }
            std::getline(iof, input);

            of.open(pathout, std::ios::app);
            of << input;
            of << '\n';
            of.close();
            if (iof.eof())  rff = 0;
        }

        else if (!rff && s2f) {
            std::getline(std::cin, input);
            of.open(pathout, std::ios::app);
            of << input;
            of << '\n';

            of << "w" + std::to_string(wtime);
            of << '\n';
            of << "b" + std::to_string(btime);
            of << '\n';

            of.close();
        }

        else if (!rff && !s2f) {
            std::getline(std::cin, input);
        }
        if (rff) {
            if (input[0] == 'Q') {
                t = !t;
                b[static_cast<int>(input[1]) - '0'][static_cast<int>(input[2]) - '0'][1] = 'Q';
                vv = true;
                g = 1;
                continue;
            }
            else if (input[0] == 'R') {
                t = !t;
                b[static_cast<int>(input[1]) - '0'][static_cast<int>(input[2]) - '0'][1] = 'R';
                vv = 1;
                g = 1;
                continue;
            }

            else if (input[0] == 'N') {
                t = !t;
                b[static_cast<int>(input[1]) - '0'][static_cast<int>(input[2]) - '0'][1] = 'N';
                vv = 1;
                g = 1;
                continue;
            }

            else if (input[0] == 'B') {
                t = !t;
                b[static_cast<int>(input[1]) - '0'][static_cast<int>(input[2]) - '0'][1] = 'B';
                vv = 1;
                g = 1;
                continue;
            }


        }
        if (input == "S") {
            if (of) of.close();
            if (iof) iof.close();
            std::exit(0);
        }

        vv = inc(input); if (vv == false) continue;
        bool u = castling(b, input);
        if (u == 1) {
            g = 1;
            break;
        }
        vv = v(input); if (vv == false) continue;
        vv = general(input, b, t); if (vv == false) continue;

        if ((c == 'W' || c == '0') && t == 0) {
            if (checkv(b, input) == 0) {
                if (c != 'B') { vv = false; continue; }
            }
        }
        if ((c == 'B' || c == '0') && t == 1) {
            if (checkv(b, input) == 0) {
                if (c != 'W') { vv = false; continue; }
            }
        }



        char type = type1(b, input);

        if (type == 'P') {
            int i1 = input[0] - '0';
            int i2 = input[1] - '0';
            int i3 = input[3] - '0';
            int i4 = input[4] - '0';

            if (b[i1][i2] == "WP" && isDiag(input) == true) {
                if (i3 - i1 != -1) { vv = false; continue; }

            }
            if (b[i1][i2] == "BP" && isDiag(input) == true) {
                if (i3 - i1 != 1) { vv = false; continue; }

            }

            v1 = pawnv(input, b, t);
            v2 = pawnk(input, b, t);
            if (v1 == false && v2 == false) { vv = false; continue; }
        }

        else if (type == 'B') {
            v1 = bishopv(input, b, t);
            v2 = bishopk(input, b);
            if (v1 == false && v2 == false) { vv = false; continue; }
        }

        else if (type == 'N') {
            v1 = knightv(input, b, t);
            v2 = knightk(input, b, t);
            if (v1 == false && v2 == false) { vv = false; continue; }
        }

        else if (type == 'R') {
            v1 = rookv(input, b, t);
            v2 = rookk(input, b, t);
            if (v1 == false && v2 == false) { vv = false; continue; }
            if (b[static_cast<int>(input[3]) - 48][static_cast<int>(input[4]) - 48][1] == 'K') { vv = false; continue; }
        }

        else if (type == 'Q') {
            v1 = queenv(input, b, t);
            v2 = queenk(input, b, t);
            if (v1 == false && v2 == false) { vv = false; continue; }
        }

        else if (type == 'K') {
            v1 = kingv(input, b, t);
            v2 = kingk(input, b, t);
            if (v1 == false && v2 == false) { vv = false; continue; }
            /* bool vk = kingselfcheck(b, input); */
            /* if(vk ==0) {vv=false;continue;} */
        }

    }


    if (sc)system("clear");
    if (!g) s(b[static_cast<int>(input[0]) - 48][static_cast<int>(input[1]) - 48], b[static_cast<int>(input[3]) - 48][static_cast<int>(input[4]) - 48]);

    time_t tmp1 = time(0) - tmp;


    if (choice == 1) {
        if (t == 0) wtime += tmp1;
        else btime += tmp1;

        std::cout << "\nWhite time is " << wtime << " seconds";
        std::cout << "\nBlack time is " << btime << " seconds";

        if (wtime > btime) std::cout << "\nBlack has the advantage\n";
        else std::cout << "\nWhite has the advantage\n";
        std::cout << "\n";
    }

    else if (choice == 2) {
        if (t == 0) { wtime -= tmp1; wtime += 10; }
        else { btime -= tmp1; btime += 10; }
        std::cout << t;
        std::cout << "\nWhite time is " << wtime << " seconds";
        std::cout << "\nBlack time is " << btime << " seconds";

        std::cout << "\n";
        if (t == 0 && wtime <= 0) {
            std::cout << "White has run out of time and lost the game!\n";
            return 0;
        }
        else if (t == 1 && btime <= 0) {
            std::cout << "Black has run out of time and lost the game!\n";
            return 0;
        }

    }

    else if (choice == 3) {
        if (t == 0) { wtime -= tmp1; }
        else { btime -= tmp1; }
        std::cout << t;
        std::cout << "\nWhite time is " << wtime << " seconds";
        std::cout << "\nBlack time is " << btime << " seconds";

        std::cout << "\n";
        if (t == 0 && wtime <= 0) {
            std::cout << "White has run out of time and lost the game!\n";
            return 0;
        }
        else if (t == 1 && btime <= 0) {
            std::cout << "Black has run out of time and lost the game!\n";
            return 0;
        }

    }

    if (lgtn && t == 0) inw = 0;
    if (lgtn && t == 1) inb = 0;

    t = !t;

    check(b);
    int l = -1; char c = '\0', np = '\0';
    if (!rff && pawnp(b, l, c, np)) {
        of.open(pathout, std::ios::app);
        std::string p{ "lol" };
        p[0] = np;
        if (c == 'w')p[1] = '0';
        else if (c == 'b')p[1] = '7';
        p[2] = static_cast<char>(l) + '0';
        of << p;
        of.close();
    }
    if (lwr) system("sleep 5");

    return 1;
}
