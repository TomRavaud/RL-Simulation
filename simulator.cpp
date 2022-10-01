#include <Imagine/Graphics.h>

#include "simulator.h"

simulator::simulator(int w, int h)
{
    width = w;
    height = h;
}

void simulator::display()
{
    Imagine::openWindow(width, height);
}
