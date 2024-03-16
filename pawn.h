int wenp[2];
int benp[2];
bool pawnv(std::string &input, std::string b[8][8], bool t){
  bool z1=true;
  if((b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48]) == "WP"){
    if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48]) != "  "){
      return false;
    }
    bool wt=0;

    if(input[1] != input[4]) return false;
    if(input[0] != '6'){
      int i1= input[3]  - input[0];

      //Only col
      if(i1 != -1){ 
        if(i1 == 0) z1 =true;
        else z1 =false;
      }
     
      if(z1 == true) return true;
      else return false;

    }
else{
      int i1= input[3]  - input[0];
      if(i1 != -2 && i1 != -1){
        if(i1 == 0) z1 =true;
        else z1 =false;
      }
      wenp[0] = (static_cast<int>(input[3]) - 48) + 1;
      wenp[1] = (static_cast<int>(input[4]) - 48);
      wt= t;
      if(z1 == true) return true;
      else return false;


    }
  }



  if((b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48]) == "BP"){
    if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48]) != "  " ){
      return false;
    }
    if(input[1] != input[4]) return false;

    if(input[0] != '1'){
      int i1= input[3]  - input[0];
      if(i1 != 1){
        if(i1 == 0) z1 =true;
        else z1 =false;
      }

      if(z1 == true) return true;
      else return false;

    }
else{
      int i1= input[3]  - input[0];
      if(i1 != 2 && i1 != 1){
        if(i1 == 0) z1 =true;
        else z1 =false;
      }
      if(i1 == 2)int be = input[3]  +1 -'0';
       // if(enpb == 0) enpb=1; else enpb=0;
       // std::cout<<enp<<" is enp \n";
      benp[0] = (static_cast<int>(input[3]) - 48) - 1;
      benp[1] = (static_cast<int>(input[4]) - 48);

      if(z1 == true) return true;
      else return false;


    }
  }

  return true;
}

bool pawnk(std::string &input, std::string b[8][8], bool t=false){
int i1 = input[0] -'0';
int i2 = input[1] -'0';
int i3 = input[3] -'0';
int i4 = input[4] -'0';



if(b[i1][i2][0] == b[i3][i4][0]) return false;
if(b[static_cast<int>(input[3]) - 48][static_cast<int>(input[4]) - 48][1] == 'K') return false;

if(isDiag(input) == true){
    if(b[i3][i4] != "  "){
      return true;
    }
else return false;
}
else return false;

}

bool pawnp(std::string b[8][8], int &l, char &pc, char &np){
    for (int i = 0; i < 8; i++) {
        std::string s =b[0][i];

        if(s=="WP"){
              system("clear");
              std::cout << "What do you want to promote the pawn to? \n";
              std::cout << "1) Queen\n";
              std::cout << "2) Rook\n";
              std::cout << "3) Bishop\n";
              std::cout << "4) Knight\n-> ";
              int ii{0};
              while(ii<1 || ii>4){
                  std::cin >> ii;
              }
              if(ii==1) {b[0][i] = "WQ"; np='Q';}
              else if(ii==2) {b[0][i] = "WR";  np='R';}
              else if(ii==3) {b[0][i] = "WB";  np='B';}
              else if(ii==4) {b[0][i] = "WN";  np='N';}
              system("clear");
              p(b);
              l=i; 
              pc='w';
              return 1;
        }


    }

    for (int i = 0; i < 8; i++) {
      std::string s =b[7][i];

      if(s=="BP"){
        system("clear");
        std::cout << "What do you want to promote the pawn to? \n";
        std::cout << "1) Queen\n";
        std::cout << "2) Rook\n";
        std::cout << "3) Bishop\n";
        std::cout << "4) Knight\n-> ";
        int ii{0};
        while(ii<1 || ii>4){
          std::cin >> ii;
        }
        if(ii==1) {b[7][i] = "BQ"; np='Q';}
        else if(ii==2) {b[7][i] = "BR"; np='R';}
        else if(ii==3) {b[7][i] = "BB"; np='B';}
        else if(ii==4) {b[7][i] = "BN";  np='N';}
        system("clear");
        p(b);
        l=i; 
        pc='b';

        return 1;
      }


    }
    return 0;
}
