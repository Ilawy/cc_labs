#include <iostream>
#include <graphics.h>

using namespace std;

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Shape{
    protected:
        int color = WHITE;
    public:
        Shape(int color) : color(color) {}
};



class Line : public Shape
{
private:
    Point start;
    Point end;

public:
    Line() : start(), end(), Shape(WHITE) {}
    Line(int x1, int y1, int x2, int y2, int color = WHITE) : start(x1, y1), end(x2, y2), Shape(color) {}

    void draw()
    {
        setcolor(this->color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
        setcolor(WHITE);
    }
};

class Rect : public Shape
{
private:
    Point ul;
    Point lr;
public:
    Rect(int color = WHITE) : ul(), lr(), Shape(color) {}
    Rect(int x1, int y1, int x2, int y2, int color = WHITE) : ul(x1, y1), lr(x2, y2), Shape(color) {}

    void draw()
    {   
        setfillstyle(SOLID_FILL, this->color);
        bar(ul.getX(), ul.getY(), lr.getX(), lr.getY());
        
    }
};

class Text : public Shape
{
private:
    char *value;
    Point position;
    int fontSize;

public:
    Text(char *value, int x, int y, int color = WHITE): Shape(color)
    {
        this->value = value;
        this->fontSize = 12;
        this->position = Point(x, y);
    }
    void draw()
    {
        settextstyle(DEFAULT_FONT, 0, this->fontSize);
        setcolor(this->color);
        outtextxy(this->position.getX(), this->position.getY(), this->value);
        setcolor(WHITE);
    }

    void setFontSize(int fs){
        this->fontSize = fs;
    }
};

class Circle: public Shape
{
private:
    Point center;
    int radius;

public:
    Circle() : center(), radius(0), Shape(WHITE) {}
    Circle(int m, int n, int r, int color = WHITE) : center(m, n), radius(r), Shape(color) {}

    void draw()
    {
        setfillstyle(SOLID_FILL, this->color);
        fillellipse(center.getX(), center.getY(), radius, radius);
        setfillstyle(EMPTY_FILL, WHITE);
    }
};

class Picture
{
private:
    int cNum, rNum, lNum, tNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;
    Text *texts;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect *pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line *pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void setTexts(int tn, Text *pT)
    {
        tNum = tn;
        this->texts = pT;
    }

    void paint()
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }

        for (int i = 0; i < this->tNum; i++)
        {
            texts[i].draw();
        }
    }
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "Hola");
    int x, y;

    Picture myPic;
    Text t0 = Text("press any key to exit", 30, 420, RED);
    t0.setFontSize(3);
    Text t1 = Text("Hello", 30, 120, YELLOW);
    Text t2 = Text("World", 30, 180, CYAN);
    t1.setFontSize(5);
    t2.setFontSize(5);

    Circle cArr[3] = {Circle(50, 50, 50, RED), Circle(200, 100, 100, RED), Circle(420, 50, 30, RED)};
    Rect rArr[2] = {Rect(30, 40, 170, 100, GREEN), Rect(420, 50, 500, 300, GREEN)};
    Line lArr[2] = {Line(420, 50, 300, 300, BLUE), Line(40, 500, 500, 400, BLUE)};
    Text tArr[3] = {t0, t1, t2};


    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);
    myPic.setTexts(3, tArr);

    myPic.paint();
    printf("%c\n", getch());

    return 0;
}