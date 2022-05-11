#include <firmament.h>

using namespace rtthread;

class Box {
public:
    double length;
    double breadth;
    double height;

    double get(void);
    void set(double len, double bre, double hei);
};

double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

// extern "C" int test_cpp(void);
extern "C" {
int test_cpp(void)
{
    Box Box1;
    Box* Box2 = new Box;
    double volume = 0.0;

    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    Box2->set(16.0, 8.0, 12.0);

    volume = Box1.height * Box1.length * Box1.breadth;
    printf("Box1 volume %lf\n", volume);

    volume = Box2->get();
    printf("Box2 volume %lf\n", volume);

    delete Box2;

    return 0;
}
}
