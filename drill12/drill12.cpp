#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{100,100}, 600, 400, "My Window" };
    Axis xa(Axis::x, Point(20,300), 350, 12, "x axis");
    win.attach(xa);

    Axis ya(Axis::y, Point(20,300), 200, 8, "y axis");
    ya.set_color(Color:: red);
    ya.label.set_color(Color:: yellow);
    win.attach(ya);

    Function sine(cos,20,100,Point(-1000,200),1000,50,50); 
    sine.set_color(Color::green);
    win.attach(sine);

    Polygon poly;                       //ez valami 5 szög
    poly.add(Point(300,200));
    poly.add(Point(350,100));
    poly.add(Point(370,150));
    poly.add(Point(400,200));
    poly.add(Point(320,250));
    poly.set_color(Color:: dark_magenta);
    poly.set_style(Line_style::solid);
    win.attach(poly);

    Rectangle r(Point(400,200), 100, 50);
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(200,50));
    poly_rect.add(Point(300,100));
    poly_rect.add(Point(200,100));
    poly_rect.add(Point(150,75));
    poly_rect.add(Point(200, 90));
    win.attach(poly_rect);

    r.set_fill_color(Color:: dark_red);
    poly.set_style(Line_style(Line_style::dash,4)) ;
    poly_rect.set_style(Line_style(Line_style::dash,2)) ;

    Text t(Point(150,280), "Escape was never an option") ;
    t.set_font(Font::times_bold);
    t.set_font_size(18) ;
    win.attach(t);

    Image ii(Point(200,350),"corleone.jpg");
    win .attach(ii);

    Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image gfather {Point{400,100},"father.jpg"}; 
	gfather.set_mask(Point{40,40},145,82);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(gfather);

	win.wait_for_button();
}
