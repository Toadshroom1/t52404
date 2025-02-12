#include "RGB.h"
RGB::RGB(){
    r = 0;
    g = 0;
    b = 0;
}
RGB::RGB(unsigned char r, unsigned char g, unsigned char b){
    this->r = r;
    this->g = g;
    this->b = b;
    calcColour();
}
RGB::RGB(CuColour colour){
    this->colour = colour;
    calcRGB();
}
unsigned char RGB::getR() const{
    return r;
}
unsigned char RGB::getG() const{
    return g;
}
unsigned char RGB::getB() const{
    return b;
}
CuColour RGB::getColour() const{
    return colour;
}
void RGB::setR(unsigned char r){
    this->r = r;
    calcColour();
}
void RGB::setB(unsigned char b){
    this->b = b;
    calcColour();
}
void RGB::setG(unsigned char g){
    this->g = g;
    calcColour();
}
void RGB::setColour(CuColour colour){
    this->colour = colour;
    calcRGB();
}
void RGB::calcRGB(){
    r = (colour >> 16) & fullChar;
    g = (colour >> 8) & fullChar;
    b = colour & fullChar;
}
void RGB::calcColour(){
    colour = r;
    colour = colour << 8;
    colour += g;
    colour = colour << 8;
    colour += b;
}
RGB RGB::WHITE(){
    return RGB(0xFFFFFF);
}
RGB RGB::BLACK(){
    return RGB(0x000000);
}
RGB RGB::RED(){
    return RGB(0xFF0000);
}
RGB RGB::GREEN(){
    return RGB(0x00FF00);
}
RGB RGB::BLUE(){
    return RGB(0x0000FF);
}
void RGB::print() const{
    cout << "The RGB values R: " << int(r) << ", G: " << int(g) << ", B: " << int(b) << " and hex value: " << hex << colour << endl;
}