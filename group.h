/**
 * Group handler for SVG files
 * Author: Jerry Mao, Caulfield Grammar School
 */

#ifndef __GROUP_H
#define __GROUP_H

#include <vector>

using namespace std;

#include "element.h"
#include "color.h"

class Group
{
	private:

		vector<Element> img;
		string filter;
	
	public:

		Group()
		{
			img = vector<Element>();
			filter = "";
		}

		Group(string Filter)
		{
			img = vector<Element>();
			filter = Filter;
		}

		void addElement(Element e)
		{
			img.push_back(e);
		}

		void setFilter(const string Filter)
		{
			filter = Filter;
		}

		void addDasharray()
		{
			img.back().setAttr("stroke-dasharray", "5,5");
		}

		friend ostream& operator<< (ostream& out, const Group &g)
		{
			if (g.filter == "")
			{
				out << "\t<g>\n";
			} else
			{
				out << "\t<g filter=\"url(#" << g.filter << ")\">\n";
			}
			for (unsigned i = 0;i < g.img.size();i++)
			{
				out << g.img[i];
			}
			out << "\t</g>\n";
			return out;
		}
};

#endif
