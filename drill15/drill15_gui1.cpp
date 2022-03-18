#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	int x = 600;
	int y = 600;
	int axis = 400;
	int notches = 400 / 20;
	int ykozep = y / 2;
	int xkozep = x / 2;
	Point center(300, 300);

	Simple_window win{ Point{100,100}, x, y, "Munkaterület" };

	Axis xaxis(Axis::x, Point(100, ykozep), axis, notches, "x 1== 20 pixel");
	xaxis.set_color(Color::red);
	win.attach(xaxis);
	Axis yaxis(Axis::y, Point(xkozep, axis + 100), axis, notches, "y 1 == 20 pixel");
	yaxis.set_color(Color::red);
	win.attach(yaxis);

	win.wait_for_button();
}
