bool kingvc(std::string &input, std::string b[8][8], bool t){
  bool z = 1;
std::string bb[8][8];
for (int i = 0; i < 8; i++) {
for (int ii = 0; ii < 8; ii++) {
  bb[i][ii] = b[i][ii];
}
}



int i1 = input[0] - '0';
int i2 = input[1] - '0';
int i3 = input[3] - '0';
int i4 = input[4] - '0';

//if((bb[i3][i4])[0] ==  bb[i1][i2][0])  return true;
if(i3 - i1 == 1 && i2 - i4 == 1){
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true) z = false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == 1 && i2 - i4 == 0 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true) z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == 0 && i2 - i4 == 1 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == 1 && i2 - i4 == -1 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == -1 && i2 - i4 == 1 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == -1 && i2 - i4 == 0 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == 0 && i2 - i4 == -1 ){
  //if((bb[i3][i4])[0] ==  bb[i1][i2][0])  x= true;
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}
if(i3 - i1 == -1 && i2 - i4 == -1 ){
  if(bb[i1][i2][0] !=  bb[i3][i4][0])
    s(bb, i1, i2, i3, i4);
  if(check(bb) == true)  z =  false; else z = true;
  if(z==1) return z;

}

return z;

}

bool km(std::string b[8][8], std::string &input){
  int i1 = input[0] - '0';
  int i2 = input[1] - '0';
  int i3 = input[3] - '0';
  int i4 = input[4] - '0';

    std::string bb[8][8];
    for (int i = 0; i < 8; i++) {
      for (int ii = 0; ii < 8; ii++) {
        bb[i][ii] = b[i][ii];
      }
    }
    if(bb[i3][i4][0] == bb[i1][i2][0]) return false;
    else{
//       bb[i3][i4] = bb[i1][i2];
        s(bb[i1][i2] ,bb[i3][i4]);
//        std::cout<< check(bb)<<std::endl;
        bool k;
        k = (check(bb));
       if(k==true) return false; else return true;
    }
}


bool kingselfcheck(std::string b[8][8], std::string input){
    std::string bb[8][8];
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
     bb[i][ii] = b[i][ii];
   }
   }

    s(bb[static_cast<int>(input[0]) - '0'][ static_cast<int>(input[1]) - '0' ], bb[static_cast<int>(input[3]) - '0'][static_cast<int>(input[4]) - '0']);
    return !check(bb);

}


bool whitepawnmate(std::string b[8][8]){

std::string bb[8][8];
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
     bb[i][ii] = b[i][ii];
 }
}

for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
      if(bb[i][ii] == "WP" && i!=0){
          if(b[i-1][ii][0] != 'B' && b[i-1][ii][0] != 'W' && i-1>-1){
          std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i-1) + std::to_string(ii);
          if(checkv(bb, input) == 1) return 1; 
        }
          if(bb[i-1][ii-1][0] == 'B'  && i-1>-1 &&  ii-1>-1){
               std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i-1) + std::to_string(ii-1);
               if(checkv(bb, input) == 1) return 1;
          } 
          if(bb[i-1][ii+1][0] == 'B' &&  i-1>-1 && ii+1<8){
               std::string input = std::to_string(i) + std::to_string(ii) + " " +std::to_string(i-1) + std::to_string(ii+1);
               if(checkv(bb, input) == 1) return 1;
          } 
          if(i==6 && b[i-2][ii][0] != 'B' && b[i-2][ii][0] != 'W' && b[i-1][ii][0] == ' '){
              std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i-2) + std::to_string(ii);
              if(checkv(bb, input) == 1) return 1;  
          }

      }

   } 
}
return 0;
}



bool blackpawnmate(std::string b[8][8]){

std::string bb[8][8];
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
     bb[i][ii] = b[i][ii];
 }
}

for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
      if(bb[i][ii] == "BP" && i!=7){
          if(b[i+1][ii][0] != 'B' && b[i+1][ii][0] != 'W'){
          std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i+1) + std::to_string(ii);
          if(checkv(bb, input) == 1) return 1; 
        }
          if(bb[i+1][ii-1][0] == 'W'){
               std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i+1) + std::to_string(ii-1);
               if(checkv(bb, input) == 1) return 1;
          } 
          if(bb[i+1][ii+1][0] == 'W'){
               std::string input = std::to_string(i) + std::to_string(ii) + " " +std::to_string(i+1) + std::to_string(ii+1);
               if(checkv(bb, input) == 1) return 1;
          } 
          if(i==1 && b[i+2][ii] == "  " && b[i+1][ii][0] == ' '){
              std::string input = std::to_string(i) + std::to_string(ii) + " "+ std::to_string(i+2) + std::to_string(ii);
              if(checkv(bb, input) == 1) return 1;  
          }

      }

   } 
}
return 0;
}



bool whitebishopmate(std::string b[8][8]){
std::string bb[8][8];
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
     bb[i][ii] = b[i][ii];
 }
}

for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
      if(bb[i][ii] == "WB"){
           for (int count = 1; count < 8; count++) {

               if((i-count>(-1)) && (ii+count<(8))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii+count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }
               if((i-count>(-1)) && (ii-count>(-1))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii-count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }

              if((i+count<(8)) && (ii-count>(-1))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii-count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }

             if((i+count<(8)) && (ii+count<(8))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii+count);
               //if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               bool aa=bishopv(input, b, 1);
               bool bb=bishopk(input, b);
               bool cc=checkv(b, input);
               if(aa==1||bb==1){
                if(cc==1) return 1;
               }
               
             }
               
           }
      }
   } 
}
return 0;
}



bool blackbishopmate(std::string b[8][8]){
std::string bb[8][8];
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
     bb[i][ii] = b[i][ii];
 }
}

for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
      if(bb[i][ii] == "BB"){
           for (int count = 1; count < 8; count++) {

               if((i-count>(-1)) && (ii+count<(8))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii+count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }
               if((i-count>(-1)) && (ii-count>(-1))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii-count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }

              if((i+count<(8)) && (ii-count>(-1))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii-count);
               if((bishopv(input, b, 1) == 1 || bishopk(input, b) ==1 ) && checkv(b, input) == 1) return 1;
               
             }

             if((i+count<(8)) && (ii+count<(8))){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii+count);
               bool aa=bishopv(input, b, 1);
               bool bb=bishopk(input, b);
               bool cc=checkv(b, input);
               if(aa==1||bb==1){
                if(cc==1) return 1;
               }
               
             }
               
           }
      }
   } 
}
return 0;
}

bool whiterookmate(std::string b[8][8]){
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
       if(b[i][ii] == "WR"){
         for (int count = 0; count < 8; count++) {

               if(ii+count<8){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i) + std::to_string(ii+count);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }

               if(i+count<8){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }
              
               if(i-count>-1){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }
               
               if(ii-count>-1){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i) + std::to_string(ii-count);
               if((rookv(input, b) == 1 || rookk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
               }
         }
       }
   } 
}
return 0;
}

bool blackrookmate(std::string b[8][8]){
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
       if(b[i][ii] == "BR"){
         for (int count = 0; count < 8; count++) {

               if(ii+count<8){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i) + std::to_string(ii+count);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }

               if(i+count<8){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i+count) + std::to_string(ii);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }
              
               if(i-count>-1){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i-count) + std::to_string(ii);
               if((rookv(input, b) == 1 || rookk(input, b) == 1) && (checkv(b, input) == 1)) return 1;
               }
               
               if(ii-count>-1){
               std::string input = std::to_string(i) + std::to_string(ii) +" "+ std::to_string(i) + std::to_string(ii-count);
               if((rookv(input, b) == 1 || rookk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
               }
         }
       }
   } 
}
return 0;
}

bool whiteknightmate(std::string b [8][8]){
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
       if(b[i][ii] == "WN"){
          for (int count = 1; count < 3; count++) {
             for (int counti = 2; counti > 0; counti--) {

                if(i+count<8 && ii+counti<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+count) + std::to_string(ii+counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+counti<8 && ii+count<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+counti) + std::to_string(ii+count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-counti>-1 && ii+count<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-counti) + std::to_string(ii+count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+counti<8 && ii-count>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+counti) + std::to_string(ii-count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-counti>-1 && ii-count>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-counti) + std::to_string(ii-count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-count>-1 && ii+counti<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-count) + std::to_string(ii+counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+count<8 && ii-counti>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+count) + std::to_string(ii-counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-count>-1 && ii-counti>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-count) + std::to_string(ii-counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
             } 
          }
       }
   }
}
return 0;
}


bool blackknightmate(std::string b [8][8]){
for (int i = 0; i < 8; i++) {
   for (int ii = 0; ii < 8; ii++) {
       if(b[i][ii] == "BN"){
          for (int count = 1; count < 3; count++) {
             for (int counti = 2; counti > 0; counti--) {

                if(i+count<8 && ii+counti<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+count) + std::to_string(ii+counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+counti<8 && ii+count<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+counti) + std::to_string(ii+count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-counti>-1 && ii+count<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-counti) + std::to_string(ii+count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+counti<8 && ii-count>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+counti) + std::to_string(ii-count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-counti>-1 && ii-count>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-counti) + std::to_string(ii-count);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-count>-1 && ii+counti<8){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-count) + std::to_string(ii+counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i+count<8 && ii-counti>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i+count) + std::to_string(ii-counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
                 if(i-count>-1 && ii-counti>-1){
                 std::string input = std::to_string(i) + std::to_string(ii) + std::to_string(i-count) + std::to_string(ii-counti);
                 if((knightv(input, b) == 1 || knightk(input, b)) == 1 && (checkv(b, input) == 1)) return 1;
                 }
             } 
          }
       }
   }
}
return 0;
}

bool whitequeenmate(std::string b[8][8]){
if(whiterookmate(b) || whitebishopmate(b)) return 1;
else return 0;
}

bool blackqueenmate(std::string b[8][8]){
if(blackrookmate(b) || blackbishopmate(b)) return 1;
else return 0;
}


bool wmate(std::string bb[8][8]){ 
  bool p=1;
  int king[4];
  kingl(bb, king);

//white
int u1 = king[0] + 1;
int u2 = king[1] + 1;
int u3 = king[1] - 1;
int u4 = king[0] - 1;
if(u1<8 && u1>-1 && (bb[u1][king[1]][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(u1) + std::to_string(king[1]);
  bool r =  km(bb, s1) ;;

  // std::cout << "\nr is"<< r<<"\n";
  p=!r;
  if(r==1) return false;
}

if(u2<8 && u2>-1 && (bb[king[0]][u2][0] != 'W')){
  std::string  s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(king[0]) + std::to_string(u2);
  bool r =  km(bb, s1) ;
  p=!r;
  if(r==1) return false;
}
if(u3<8 && u3>-1 && (bb[king[0]][u3][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(king[0]) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}
if(u4<8 && u4>-1 && (bb[u4][king[1]][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(u4) + std::to_string(king[1]);
  bool  r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}
if(u1<8 && u1>-1 && u2<8  && u2>-1 && (bb[u1][u2][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(u1) + std::to_string(u2);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u4<8 && u4>-1 && u3<8 && u4>-1  && (bb[u4][u3][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(u4) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u1>-1 && u1<8 && u3>-1 && u3<8  && (bb[u1][u3][0] != 'W')){
  std::string s1 = std::to_string(king[1]) + std::to_string(king[1]) + " " + std::to_string(u1) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u4<8 && u4>-1 && u2<8 && u2>-1  && (bb[u4][u2][0] != 'W')){
  std::string s1 = std::to_string(king[0]) + std::to_string(king[1]) + " " + std::to_string(u4) + std::to_string(u2);
  bool r =  km(bb, s1) ;

p=!r;
if(r==1) return false;
}

if(whitepawnmate(bb) == 1) return 0;
if(whitebishopmate(bb) == 1) return 0;
if(whiteknightmate(bb) == 1) return 0;
if(whiterookmate(bb) == 1) return 0;
if(whitequeenmate(bb) == 1) return 0;
return p;

}



bool bmate(std::string bb[8][8]){
  bool p=1;
  int king[4];
  kingl(bb, king);

//white
int u1 = king[2] + 1;
int u2 = king[3] + 1;
int u3 = king[3] - 1;
int u4 = king[2] - 1;
if(u1>-1 && u1<8 && (bb[u1][king[3]][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u1) + std::to_string(king[3]);
  bool r =  km(bb, s1) ;;

  // std::cout << "\nr is"<< r<<"\n";
  p=!r;
  if(r==1) return false;
}

if(u2>-1 && u2<8 && (bb[king[2]][u2][0] != 'B')){
  std::string  s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(king[2]) + std::to_string(u2);
  bool r =  km(bb, s1) ;
  p=!r;
  if(r==1) return false;
}
if(u3>-1 && u3<8 && (bb[king[2]][u3][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(king[2]) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}
if(u4>-1 && u4<8 && (bb[u4][king[3]][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u4) + std::to_string(king[3]);
  bool  r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}
if(u1>-1 && u1<8 && u2>-1 && u2<8 && (bb[u1][u2][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u1) + std::to_string(u2);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u4>-1 && u4<8 && u3>-1 && u3<8  && (bb[u4][u3][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u4) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u1>-1 && u1<8 && u3>-1 && u3<8  && (bb[u1][u3][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u1) + std::to_string(u3);
  bool r =  km(bb, s1) ;
p=!r;
if(r==1) return false;
}

if(u4>-1 && u4<8 && u2>-1 && u2<8  && (bb[u4][u2][0] != 'B')){
  std::string s1 = std::to_string(king[2]) + std::to_string(king[3]) + " " + std::to_string(u4) + std::to_string(u2);
  bool r =  km(bb, s1) ;

p=!r;
if(r==1) return false;
}


if(blackpawnmate(bb) == 1) return 0;
if(blackbishopmate(bb) == 1) return 0;
if(blackknightmate(bb) == 1) return 0;
if(blackrookmate(bb) == 1) return 0;
if(blackqueenmate(bb) == 1) return 0;
return p;

}

bool stalemate(std::string b[8][8]){
if(!(check(b)) && (wmate(b) == 1 || bmate(b) == 1) ){
return 1;
}
else return 0;
}
