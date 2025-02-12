#ifndef RGB_H
#define RGB_H
#include "defs.h"
#define fullChar 0xff
class RGB{
    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned long colour;
    public:
        //Constuctors
        RGB();
        RGB(CuColour colour);
        RGB(unsigned char r, unsigned char g, unsigned char b);
        //Getters/Setters
        unsigned char getR() const, getG() const, getB() const;
        unsigned long getColour() const;
        void setR(unsigned char r), setG(unsigned char g), setB(unsigned char b), setColour(CuColour colour);
        //Calculates the RGB or colour when a RGB value or colour is set
        void calcRGB();
        void calcColour();
        //Static basic colours RGB clases
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();
        void print() const; 
};
#endif