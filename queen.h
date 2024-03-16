bool queenk(std::string &input, std::string b[8][8], bool t){
  bool v1 = bishopk(input, b);
  bool v2 = rookk(input, b, t);
  if(v1==1 || v2==1){
    return true;
  }
else return false;
}

bool queenv(std::string &input, std::string b[8][8], bool t){
bool v1 = bishopv(input, b, t);
bool v2 = rookv(input, b, t);
if(v1==1 || v2==1){
  return true;
}
else return false;
}
