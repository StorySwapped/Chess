
bool kingv(std::string &input, std::string b[8][8], bool t){

int i1 = input[0] - '0';
int i2 = input[1] - '0';
int i3 = input[3] - '0';
int i4 = input[4] - '0';

if((b[i3][i4]) != "  " ) return false;

if(i3 - i1 == 1 && i2 - i4 == 1) return true;
else if(i3 - i1 == 1 && i2 - i4 == 0) return true;
else if(i3 - i1 == 0 && i2 - i4 == 1) return true;
else if(i3 - i1 == 1 && i2 - i4 == -1) return true;
else if(i3 - i1 == -1 && i2 - i4 == 1) return true;
else if(i3 - i1 == -1 && i2 - i4 == 0) return true;
else if(i3 - i1 == 0 && i2 - i4 == -1) return true;
else if(i3 - i1 == -1 && i2 - i4 == -1) return true;
else return false;

}

bool kingk(std::string &input, std::string b[8][8], bool t){

  int i1 = input[0] - '0';
  int i2 = input[1] - '0';
  int i3 = input[3] - '0';
  int i4 = input[4] - '0';

  if((b[i3][i4]) != "  " ){
    if((b[i3][i4])[0] == (b[i1][i2])[0]) return false;
    //if((b[i3][i4])[1] == 'K') return false;
    else return true;
  }

  if(i3 - i1 == 1 && i2 - i4 == 1) return true;
  else if(i3 - i1 == 1 && i2 - i4 == 0) return true;
  else if(i3 - i1 == 0 && i2 - i4 == 1) return true;
  else if(i3 - i1 == 1 && i2 - i4 == -1) return true;
  else if(i3 - i1 == -1 && i2 - i4 == 1) return true;
  else if(i3 - i1 == -1 && i2 - i4 == 0) return true;
  else if(i3 - i1 == 0 && i2 - i4 == -1) return true;
  else if(i3 - i1 == -1 && i2 - i4 == -1) return true;
  else return false;

}
