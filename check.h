char c=0;

void kingl(std::string b [8][8], int kings[4]){
  for (int i = 0; i < 8; i++) {
    for (int ii = 0; ii < 8; ii++) {
      if(b[i][ii] == "WK"){
        kings[0] = i;
        kings[1] = ii;
      }
      else if(b[i][ii] == "BK"){
        kings[2] = i;
        kings[3] = ii;
      }
    }
  }
}

bool pawnc(std::string b [8][8], int kings[4]){
  bool x=false;
for (int i = 0; i < 8; i++) {
  for (int ii = 0; ii < 8; ii++) {
    if(b[i][ii] == "BP" && i!=7){
      if(i+1 == kings[0] && (ii+1 == kings[1] || ii-1 == kings[1])) {x=true;c='W';}
    }
    else if(b[i][ii] == "WP" && i!=0){
      if(i-1 == kings[2] && (ii+1 == kings[3] || ii-1 == kings[3])) {x=true;c='B';}
    }
}
}
return x;
}


bool bishopkc(const std::string &input, std::string b[8][8]){
if(isDiag(input) == false) return false;
int i1 = input[0];
int i2 = input[1];
int i3 = input[3];
int i4 = input[4];

bool b1=0, b2=0, b3=0, b4=0;
int i=0;
for (i = 1; i < 8; i++) {
    if((i1+i == i3) && (i2+i == i4)) {
      b1=1;
      break;
    }

    else if((i1-i == i3) && (i2-i == i4)) {
      b2=1;
      break;
    }

    else if((i1+i == i3) && (i2-i == i4)) {
      b3=1;
      break;
    }

    else if((i1-i == i3) && (i2+i == i4)) {
      b4=1;
      break;
    }
}

if(b[i1-'0'][i2-'0'][0] == b[i3-'0'][i4-'0'][0]) return false;
if(b1 == 1){
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1+ii-48][i2+ii-'0'] != "  "){
        int l1=i1+ii;
        int l2=i2+ii;
        if(l1==i3 && l2==i4) return true;
        else return false;
      }
    }
}

if(b2 == 1){
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1-ii-'0'][i2-ii-'0'] != "  "){
        int l1=i1-ii;
        int l2=i2-ii;
        if(l1==i3 && l2==i4) return true;
        else return false;
      }
    }
}

if(b3 == 1) {
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1+ii-'0'][i2-ii-'0'] != "  ") {
        int l1=i1+ii;
        int l2=i2-ii;
        if(l1==i3 && l2==i4) return true;
        else return false;
      }
    }
}

if(b4 == 1) {
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1-ii-'0'][i2+ii-'0'] != "  ") {
        int l1=i1-ii;
        int l2=i2+ii;
        if(l1==i3 && l2==i4) return true;
        else return false;
      }
    }
}
return true;

}

bool bishopc(int kings[4], std::string b[8][8]){
    bool z=false;
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
       if(b[i][ii] == "BB"){
           std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[0]) + std::to_string(kings[1]);
             if(bishopkc(input, b) == true) {z=true;c='W';}
       }
       else if(b[i][ii] == "WB"){
           std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[2]) + std::to_string(kings[3]);
             if(bishopkc(input, b) == true) {z=true;c='B';}
       }

   }
}
return z;
}

bool rookck(std::string &input, std::string b[8][8], bool t){
bool z = rookv(input, b, t);
if(z==false) return z;
if(b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48] != "  " ){
  if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48])[0] == (b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48])[0]) return false;
  else return true;
}
else return false;
}

bool rookc(int kings[4], std::string b[8][8]){
  bool z=false;
  for (int i = 0; i < 8; i++) {
    for (int ii = 0; ii < 8; ii++) {
      if(b[i][ii] == "BR"){
        std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[0]) + std::to_string(kings[1]);
         if(rookck(input, b, 1) == true) {z=true;c='W';}
      }
      else if(b[i][ii] == "WR"){
        std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[2]) + std::to_string(kings[3]);
         if(rookck(input, b, 1) == true) {z=true;c='B';}
      }

    }
  }
  return z;
}

bool knightkc(std::string &input, std::string b[8][8], bool t){
   bool x = isL(input);
   if(x== false) return false;
  if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48])[0] == (b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48])[0]) return false;
else return true;

}

bool knightc(int kings[4], std::string b[8][8]){
  bool z=false;
  for (int i = 0; i < 8; i++) {
    for (int ii = 0; ii < 8; ii++) {
      if(b[i][ii] == "BN"){
        std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[0]) + std::to_string(kings[1]);
          if(knightkc(input, b, 1) == true) {z=true;c='W';}
      }
      else if(b[i][ii] == "WN"){
        std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[2]) + std::to_string(kings[3]);
          if(knightkc(input, b, 1) == true) {z=true;c='B';}
      }

    }
  }
  return z;
}

bool queenc(int kings[4], std::string b[8][8]){
bool z=false;
for (int i = 0; i < 8; i++) {
for (int ii = 0; ii < 8; ii++) {
  if(b[i][ii] == "BQ"){
    std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[0]) + std::to_string(kings[1]);
    if(rookck(input, b, 1) == true || bishopkc(input, b) == true) {z=true;c='W';}
  }
else if(b[i][ii] == "WQ"){
    std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(kings[2]) + std::to_string(kings[3]);
    if(rookck(input, b, 1) == true || bishopkc(input, b) == true) {z=true;c='B';}
  }

}
}
return z;
}

bool check(std::string b [8][8]){
int kings[4];
kingl(b, kings);

if(pawnc(b, kings) == true ) return true;
if(bishopc(kings, b) == true ) return true;
if(rookc(kings, b) == true ) return true;
if(knightc(kings, b) == true ) return true;
if(queenc(kings, b) == true ) return true;
else {c='0';return false;}

}

bool check(std::string b [8][8], char &cc){
int kings[4];
kingl(b, kings);

if(pawnc(b, kings) == true ) {cc=c;return true;}
if(bishopc(kings, b) == true ) {cc=c;return true;}
if(rookc(kings, b) == true ) {cc=c;return true;}
if(knightc(kings, b) == true ){cc=c;return true;}
if(queenc(kings, b) == true ) {cc=c;return true;}
else {c='0';return false;}

}

bool checkv(std::string b[8][8], std::string &input, char h=0){
    std::string bb[8][8];
    for (int i = 0; i < 8; i++) {
       for (int ii = 0; ii < 8; ii++) {
          bb[i][ii] = b[i][ii];
       } 
    }
    s(bb[static_cast<int>(input[0]) - '0'][static_cast<int>(input[1]) - '0'], bb[static_cast<int>(input[3]) - '0'][static_cast<int>(input[4]) - '0']);
    return !check(bb);

}
