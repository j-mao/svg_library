/**
 * Element handler for SVG files
 * Author: Jerry Mao, Caulfield Grammar School
 */

#ifndef __ELEMENT_H
#define __ELEMENT_H

#include <map>
#include <string>
#include <fstream>

using namespace std;

#include "color.h"

class Element
{
	private:

		string type;
		map<string, string> attr;

	public:

		Element()
		{
			type = "";
			attr = map<string, string>();
		}

		Element(string Type)
		{
			type = Type;
			attr = map<string, string>();
		}

		void setType(string Type)
		{
			type = Type;
		}

		void setAttr(string attr_type, string attr_val)
		{
			attr[attr_type] = attr_val;
		}

		void setAttr(string attr_type, int attr_val)
		{
			char buf[10];
			sprintf(buf, "%d", attr_val);
			setAttr(attr_type, buf);
		}

		friend ostream& operator<< (ostream& out, const Element &e)
		{
			out << "\t\t<" << e.type;
			string myValue = "";
			bool hasValue = false;
			for (map<string, string>::const_iterator it = e.attr.begin();it != e.attr.end();it++)
			{
				if (it->first != "value")
				{
					out << " " << it->first << "=\"" << it->second << "\"";
				} else
				{
					myValue = it->second;
					hasValue = true;
				}
			}
			if (hasValue)
			{
				out << ">" << myValue << "</" << e.type << ">\n";
			} else
			{
				out << " />\n";
			}
			return out;
		}
};

#endif
