#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

#include "svg.h"

int main()
{
	SVG image;
	image.addGroup();
	image.polyline({{100,10}, {40,198}, {190,78}, {10,78}, {160,198}}, Color::NONE, 5, Color::SALMON);
	image.addDasharray();
	image.text(500, 500, Color::BLUE, "TEXT");
	image.print("pic.html");
	return 0;
}
