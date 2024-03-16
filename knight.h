bool isL(const std::string &input){
    if(isDiag(input) == true) return false;
  
  int i1 = input[0];
  int i2 = input[1];
  int i3 = input[3];
  int i4 = input[4];

  int i=0;
  int ii=0;
  for (i = 1; i < 3; i++) {
    for (ii = 2; ii > 0; ii--) {
      if((i1 + i == i3) && (i2 + ii == i4)){
        return true;
      }

      if((i1 - i == i3) && (i2 - ii == i4)){
        return true;
      }

      if((i1 + i == i3) && (i2 - ii == i4)){
        return true;
      }

      if((i1 - i == i3) && (i2 + ii == i4)){
        return true;
      }

    }
  }
  return false;
}

bool knightk(std::string &input, std::string b[8][8], bool t=1){
   bool x = isL(input);
   if(x== false) return false;
  if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48])[0] == (b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48])[0]) return false;
if(b[static_cast<int>(input[3]) - 48][static_cast<int>(input[4]) - 48][1] == 'K') return false;
else return true;

}

bool knightv(std::string &input, std::string b[8][8], bool t=1){
  bool x = isL(input);
  if(x== false) return false;
  if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48]) != "  "){
    //    x = knightk(input, b, t);
    return false;
  }
  return x;
}
