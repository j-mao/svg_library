/**
 * SVG handler
 * Author: Jerry Mao, Caulfield Grammar School
 */

/*
 * Fill rules for polygons and polylines can be added as:
 * fill-rule="nonzero"
 * fill-rule="evenodd"
 * Support for this is yet to exist, so they need to be added manually at completion
 */

#ifndef __SVG_H
#define __SVG_H

#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <assert.h>

using namespace std;

#include "group.h"
#include "element.h"
#include "color.h"

class SVG
{
	private:

		vector<Group> img;
		int w, h;

	public:

		SVG(int W, int H)
		{
			img = vector<Group>();
			w = W;
			h = H;
		}

		SVG()
		{
			img = vector<Group>();
			w = 800;
			h = 500;
		}

		void addGroup()
		{
			img.push_back(Group());
		}

		void addGroup(string filter)
		{
			img.push_back(Group(filter));
		}

		void setFilter(string filter)
		{
			img.back().setFilter(filter);
		}

		void circle(int cx, int cy, int r, Color fill)
		{
			Element me("circle");
			me.setAttr("cx", cx);
			me.setAttr("cy", cy);
			me.setAttr("r", r);
			me.setAttr("fill", fill);
			img.back().addElement(me);
		}

		void circle(int cx, int cy, int r, Color fill, int stroke_width, Color stroke)
		{
			Element me("circle");
			me.setAttr("cx", cx);
			me.setAttr("cy", cy);
			me.setAttr("r", r);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			img.back().addElement(me);
		}

		void rectangle(int x_1, int y_1, int x_2, int y_2, Color fill)
		{
			Element me("rect");
			me.setAttr("x", x_1);
			me.setAttr("y", y_1);
			me.setAttr("width", x_2-x_1);
			me.setAttr("height", y_2-y_1);
			me.setAttr("fill", fill);
			img.back().addElement(me);
		}

		void rectangle(int x_1, int y_1, int x_2, int y_2, Color fill, int stroke_width, Color stroke)
		{
			Element me("rect");
			me.setAttr("x", x_1);
			me.setAttr("y", y_1);
			me.setAttr("width", x_2-x_1);
			me.setAttr("height", y_2-y_1);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			img.back().addElement(me);
		}

		void rectangle(int x_1, int y_1, int x_2, int y_2, Color fill, int rx, int ry)
		{
			Element me("rect");
			me.setAttr("x", x_1);
			me.setAttr("y", y_1);
			me.setAttr("width", x_2-x_1);
			me.setAttr("height", y_2-y_1);
			me.setAttr("fill", fill);
			me.setAttr("rx", rx);
			me.setAttr("ry", ry);
			img.back().addElement(me);
		}

		void rectangle(int x_1, int y_1, int x_2, int y_2, Color fill, int stroke_width, Color stroke, int rx, int ry)
		{
			Element me("rect");
			me.setAttr("x", x_1);
			me.setAttr("y", y_1);
			me.setAttr("width", x_2-x_1);
			me.setAttr("height", y_2-y_1);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			me.setAttr("rx", rx);
			me.setAttr("ry", ry);
			img.back().addElement(me);
		}

		void ellipse(int cx, int cy, int rx, int ry, Color fill)
		{
			Element me("ellipse");
			me.setAttr("cx", cx);
			me.setAttr("cy", cy);
			me.setAttr("rx", rx);
			me.setAttr("ry", ry);
			me.setAttr("fill", fill);
			img.back().addElement(me);
		}

		void ellipse(int cx, int cy, int rx, int ry, Color fill, int stroke_width, Color stroke)
		{
			Element me("ellipse");
			me.setAttr("cx", cx);
			me.setAttr("cy", cy);
			me.setAttr("rx", rx);
			me.setAttr("ry", ry);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			img.back().addElement(me);
		}

		void polygon(vector<int> x, vector<int> y, Color fill)
		{
			assert(x.size() == y.size());
			string points;
			for (unsigned i = 0;i < x.size();i++)
			{
				char buf[10];
				sprintf(buf, "%d,%d", x[i], y[i]);
				if (i)
				{
					points += " ";
				}
				points += buf;
			}
			Element me("polygon");
			me.setAttr("points", points);
			me.setAttr("fill", fill);
			img.back().addElement(me);
		}

		void polygon(vector<int> x, vector<int> y, Color fill, int stroke_width, Color stroke)
		{
			assert(x.size() == y.size());
			string points;
			for (unsigned i = 0;i < x.size();i++)
			{
				char buf[10];
				sprintf(buf, "%d,%d", x[i], y[i]);
				if (i)
				{
					points += " ";
				}
				points += buf;
			}
			Element me("polygon");
			me.setAttr("points", points);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			img.back().addElement(me);
		}

		void polygon(vector<pair<int, int> > points, Color fill)
		{
			vector<int> x, y;
			for (unsigned i = 0;i < points.size();i++)
			{
				x.push_back(points[i].first);
				y.push_back(points[i].second);
			}
			polygon(x, y, fill);
		}

		void polygon(vector<pair<int, int> > points, Color fill, int stroke_width, Color stroke)
		{
			vector<int> x, y;
			for (unsigned i = 0;i < points.size();i++)
			{
				x.push_back(points[i].first);
				y.push_back(points[i].second);
			}
			polygon(x, y, fill, stroke_width, stroke);
		}

		void polyline(vector<int> x, vector<int> y, Color fill)
		{
			assert(x.size() == y.size());
			string points;
			for (unsigned i = 0;i < x.size();i++)
			{
				char buf[10];
				sprintf(buf, "%d,%d", x[i], y[i]);
				if (i)
				{
					points += " ";
				}
				points += buf;
			}
			Element me("polyline");
			me.setAttr("points", points);
			me.setAttr("fill", fill);
			img.back().addElement(me);
		}

		void polyline(vector<int> x, vector<int> y, Color fill, int stroke_width, Color stroke)
		{
			assert(x.size() == y.size());
			string points;
			for (unsigned i = 0;i < x.size();i++)
			{
				char buf[10];
				sprintf(buf, "%d,%d", x[i], y[i]);
				if (i)
				{
					points += " ";
				}
				points += buf;
			}
			Element me("polyline");
			me.setAttr("points", points);
			me.setAttr("fill", fill);
			me.setAttr("stroke-width", stroke_width);
			me.setAttr("stroke", stroke);
			img.back().addElement(me);
		}

		void polyline(vector<pair<int, int> > points, Color fill)
		{
			vector<int> x, y;
			for (unsigned i = 0;i < points.size();i++)
			{
				x.push_back(points[i].first);
				y.push_back(points[i].second);
			}
			polyline(x, y, fill);
		}

		void polyline(vector<pair<int, int> > points, Color fill, int stroke_width, Color stroke)
		{
			vector<int> x, y;
			for (unsigned i = 0;i < points.size();i++)
			{
				x.push_back(points[i].first);
				y.push_back(points[i].second);
			}
			polyline(x, y, fill, stroke_width, stroke);
		}

		void text(int x, int y, Color fill, string value, int font_size=16)
		{
			Element me("text");
			me.setAttr("x", x);
			me.setAttr("y", y);
			me.setAttr("fill", fill);
			me.setAttr("value", value);
			me.setAttr("font-size", font_size);
			me.setAttr("font-family", "sans-serif");
			img.back().addElement(me);
		}

		void addDasharray()
		{
			img.back().addDasharray();
		}

		void print(const char *file, const char *title) const
		{
			ofstream out(file);
			out << "<!DOCTYPE html>\n<html>\n<head>\n<title>" << title << "</title>\n</head>\n<body>\n";
			out << "<svg width=\"" << w << "\" height=\"" << h << "\">\n";
			for (unsigned i = 0;i < img.size();i++)
			{
				out << img[i];
			}
			out << "It looks like this browser does not support SVG.\n";
			out << "</svg>\n";
			out << "</body>\n</html>\n";
			out.close();
		}

		void print(const char *file) const
		{
			print(file, "Image");
		}
};

#endif
