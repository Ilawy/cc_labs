#include <iostream>
#include <graphics.h>
#include "../lib/flex_stack.hh"
#include "../lab_3/str.hh"
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

class Shape
{
protected:
    int color = WHITE;

public:
    Shape(int color) : color(color) {}
    virtual void draw() = 0;
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
    String *value;
    Point position;
    int fontSize;

public:
    Text(String *value, int x, int y, int color = WHITE) : Shape(color)
    {
        this->value = value;
        this->fontSize = 12;
        this->position = Point(x, y);
    }
    void draw()
    {
        settextstyle(DEFAULT_FONT, 0, this->fontSize);
        setcolor(this->color);
        outtextxy(this->position.getX(), this->position.getY(), this->value->str());
        setcolor(WHITE);
    }
    Point& getXY(){
        return this->position;
    }
    void setXY(int x, int y){
        this->position = Point(x, y);
    }

    void setFontSize(int fs)
    {
        this->fontSize = fs;
    }
};

class Circle : public Shape
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
    FlexStack<Shape *> shapes;

public:
    Picture() : shapes(24) {}

    void addShape(Shape *s)
    {
        this->shapes.push(s);
    }

    void paint()
    {
        Shape **items = this->shapes.getItems();
        for (int i = 0; i < shapes.getSize(); i++)
        {
            items[i]->draw();
        }
    }
};

void click_handler(int x, int y)
{
    cout << x << ", " << y << endl;
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x, y;

    Picture myPic;
    // Text t0 = Text("press any key to exit", 30, 420, RED);
    // t0.setFontSize(3);
    // Text *t1 = new Text("Hello", 30, 120, YELLOW);
    // Text *t2 = new Text("World", 30, 180, CYAN);
    // t1->setFontSize(5);
    // t2->setFontSize(5);

    Circle *c1 = new Circle(30, 30, 10);
    Circle *c2 = new Circle(getmaxx() - 60, 30, 10);
    String* s1 = new String("Press any key to write a very long line of text");
    Text *t1 = new Text(s1, 40, 60, RED);
    t1->setFontSize(3);

    myPic.addShape(c1);
    myPic.addShape(c2);
    myPic.addShape(t1);
    int count = 0;
    myPic.paint();
    while (1)
    {
        
        char keypress = getch();
        if (keypress == '\0' || keypress == 27)
        {
            break;
        }
            char r[24];
            sprintf(r, "%c", keypress);
            *s1 = String("KEY :: ") + r + " ";
            count++;
            Point xy = t1->getXY();
            t1->setXY(xy.getX(), xy.getY());
            cleardevice();
            myPic.paint();
            printf("%d\n", keypress);
    }

    return 0;
}