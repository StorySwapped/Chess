#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

void print(std::string s[8][8]){
    int t1=20, t2=20;
sf::RenderWindow window(sf::VideoMode(1360, 768), "Chess Game");
while(window.isOpen()){
window.display();
bool next=0;
sf::Color color(150, 75, 0);
int s1=110, s2=100;
                   sf::Texture texture;
                   /* sf::Texture chsb; */
                   /* /1* chsb.loadFromFile("/home/saad/Downloads/JohnPablok Cburnett Chess set/board squares/sq.png"); *1/ */
                   /* chsb.loadFromFile("/home/saad/Downloads/esma-q-MCC1g6Ziw-unsplash.jpg"); */
                   /* sf::Sprite bg(chsb); */
                   /* window.draw(bg); */
                   sf::RectangleShape rectangle(sf::Vector2f(1360, 768));
                   rectangle.setFillColor(color);
                   window.draw(rectangle);

       for (int i = 0, l=0; i < (75*8); i+=85, l++) {
          for (int ii = 0, ll=0; ii < (75*8); ii+=85, ll++) {
              
               sf::RectangleShape rectangle(sf::Vector2f(75, 75));
               rectangle.setPosition(sf::Vector2f(t1+ii+300, t2+i));

               if(s[l][ll] == "WR") {
                   texture.loadFromFile("/home/saad/Desktop/chs/w_rook_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }
              
               else if(s[l][ll] == "WN") {
                   texture.loadFromFile("/home/saad/Desktop/chs/w_knight_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }

               else if(s[l][ll] == "WB") {
                   texture.loadFromFile("/home/saad/Desktop/chs/w_bishop_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }


               else if(s[l][ll] == "WQ") {
                   texture.loadFromFile("/home/saad/Desktop/chs/w_queen_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }

               else if(s[l][ll] == "WK") {
                   texture.loadFromFile("/home/saad/Desktop/chs/w_king_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }
               else if(s[l][ll] == "WP"){
                   texture.loadFromFile("/home/saad/Desktop/chs/w_pawn_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);

               }

               else if(s[l][ll] == "BR") {
                   texture.loadFromFile("/home/saad/Desktop/chs/b_rook_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }
              
               else if(s[l][ll] == "BN") {
                   texture.loadFromFile("/home/saad/Desktop/chs/b_knight_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }

               else if(s[l][ll] == "BB") {
                   texture.loadFromFile("/home/saad/Desktop/chs/b_bishop_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }

               else if(s[l][ll] == "BQ") {
                   texture.loadFromFile("/home/saad/Desktop/chs/b_queen_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }

               else if(s[l][ll] == "BK") {
                   texture.loadFromFile("/home/saad/Desktop/chs/b_king_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);
               }
               else if(s[l][ll] == "BP"){
                   texture.loadFromFile("/home/saad/Desktop/chs/b_pawn_png_shadow_128px.png");
                 rectangle.setTexture(&texture, 0);

               }
               /* else rectangle.setFillColor(sf::Color::Transparent); */
               else if(!next){
                   texture.loadFromFile("/home/saad/Downloads/JohnPablok Cburnett Chess set/board squares/sqd.png");
                   rectangle.setTexture(&texture, 0);
               }
               else if(next){
                   texture.loadFromFile("/home/saad/Downloads/JohnPablok Cburnett Chess set/board squares/sql.png");
                   rectangle.setTexture(&texture, 0);
               }
               texture.setSmooth(1);
               window.draw(rectangle);
               if(ll!=7) next = !next;
      
          } 
       }
} 
}

void Whitewon() {
    int t1 = 20, t2 = 20;
    sf::RenderWindow window(sf::VideoMode(1360, 768), "Chess Game");
    while (window.isOpen()) {
        window.display();
        bool next = 0;
        sf::Color color(150, 75, 0);
        int s1 = 110, s2 = 100;
        sf::Texture texture;
        texture.loadFromFile("./whitewon");
        sf::RectangleShape rectangle(sf::Vector2f(640, 480));
        rectangle.setTexture(&texture, 0);
        window.draw(rectangle);


    }
}

void Blackwon() {
    int t1 = 20, t2 = 20;
    sf::RenderWindow window(sf::VideoMode(1360, 768), "Chess Game");
    while (window.isOpen()) {
        window.display();
        bool next = 0;
        sf::Color color(150, 75, 0);
        int s1 = 110, s2 = 100;
        sf::Texture texture;
        texture.loadFromFile("./blackwon.png");
        sf::RectangleShape rectangle(sf::Vector2f(640, 480));
        rectangle.setTexture(&texture, 0);
        window.draw(rectangle);


    }
}
