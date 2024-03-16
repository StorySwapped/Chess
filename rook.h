bool rookv(std::string &input, std::string b[8][8], bool t=1){


  int i1 = input[0] - '0';
  int i2 = input[1] - '0';
  int i3 = input[3] - '0';
  int i4 = input[4] - '0';

  if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48])[0] == (b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48])[0]) return false;

  if(i1 == i3 && i2<i4){
    for (int i = i2+1; i < i4; i++) {
      if((b[i1][i]) != "  ") return false;
    }
    return true;
  }

  else if(i1 == i3 && i2>i4){
    for (int i = i2-1; i > i4; i--) {
      if((b[i1][i]) != "  ") return false;
    }
    return true;
  }

  else if(i2==i4 && i1<i3){
    for (int i = i1+1; i < i3; i++) {
      if((b[i][i2]) != "  ") return false;
    }
    return true;

  }

  else if(i2==i4 && i1>i3){
    for (int i = i1-1; i > i3; i--) {
      if((b[i][i2]) != "  ") return false;

    }
    return true;

  }

  return false;
}

bool rookk(std::string &input, std::string b[8][8], bool t=1){
  bool z = rookv(input, b, t);
if(b[static_cast<int>(input[3]) - 48][static_cast<int>(input[4]) - 48][1] == 'K') return false;
  if(z==false) return z;
if(b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48] != "  " ){
    if((b[static_cast<int>(input[3]) - 48][ static_cast<int>(input[4]) -48])[0] == (b[static_cast<int>(input[0]) - 48][ static_cast<int>(input[1]) -48])[0]) return false;

else return true;
  }
else return false;
}