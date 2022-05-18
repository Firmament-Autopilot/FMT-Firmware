#include <firmament.h>
#include "module/task_manager/task_manager.h"

using namespace rtthread;

class Box {
public:
    double length;
    double breadth;
    double height;

    double get(void);
    void set(double len, double bre, double hei);
};

double Box::get(void) { return length * breadth * height; }

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

extern "C" int test_cpp(void);
fmt_err_t test_cpp_init(void)
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

    return FMT_EOK;
}

void test_cpp_entry(void* parameter)
{

    while (1) {
        Box Box1;
        Box* Box2 = new Box;
        double volume = 0.0;

        Box1.height = 5.0;
        Box1.length = 6.0;
        Box1.breadth = 7.0;

        Box2->set(16.0, 8.0, 12.0);

        sys_msleep(1000);

        volume = Box1.height * Box1.length * Box1.breadth;
        printf("Box1 volume %lf\n", volume);

        volume = Box2->get();
        printf("Box2 volume %lf\n", volume);

        delete Box2;
    }

}

// TASK_EXPORT __fmt_task_desc = {
//     .name = "cpp",
//     .init = test_cpp_init,
//     .entry = test_cpp_entry,
//     .priority = 25,
//     .stack_size = 1024,
//     .param = NULL,
//     .dependency = NULL
// };