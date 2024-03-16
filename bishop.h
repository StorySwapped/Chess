bool td(const std::string &input, std::string b[8][8]){
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
  if(b1 == 1){
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1+ii-48][i2+ii-'0'] != "  "){
        return false;
      }
    }
  }

  if(b2 == 1){
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1-ii-'0'][i2-ii-'0'] != "  "){
        return false;
      }
    }
  }

  if(b3 == 1) {
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1+ii-'0'][i2-ii-'0'] != "  ") {
        return false;
      }
    }
  }

  if(b4 == 1) {
    for (int ii = 1; ii <= i; ii++) {
      if(b[i1-ii-'0'][i2+ii-'0'] != "  ") {
        return false;
      }
    }
  }
  return true;

}


bool bishopv(const std::string &input, std::string b[8][8], bool t){
  bool x=false;
  x=isDiag(input);

  if(x==false) return false;
  x=td(input, b);
  if(x==false) return false;

  return x;
}

bool bishopk(const std::string &input, std::string b[8][8]){
  if(b[static_cast<int>(input[3]) - '0'][static_cast<int>(input[4]) - '0'][1] == 'K') return false;
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