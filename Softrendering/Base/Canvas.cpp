#include "Assist.h"
#include "Canvas.h"
#include "Log.h"

#include <algorithm>

SET_SINGLETON(SFR::Canvas)

SFR::Canvas::~Canvas()
{
	closegraph();
}

void SFR::Canvas::Init(int width, int height)
{
	Init(float(width), float(height));
}

void SFR::Canvas::Init(float width, float height)
{
	if (_is_init)
		return;
	_size.x = width;
	_size.y = height;
	initgraph(int(width), int(height));
	SetBrushColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	_is_init = true;
}

void SFR::Canvas::SetBrushColor(glm::vec4 color)
{
	_brush_color = SFR::Con_vec4ToColor(color);
}

void SFR::Canvas::DrawLineDescartes(int x1, int y1, int x2, int y2)
{
	DrawLineDescartes(float(x1), float(y1), float(x2), float(y2));
}

void SFR::Canvas::DrawLineDescartes(glm::vec2 p1, glm::vec2 p2)
{
	DrawLineDescartes(p1.x, p1.y, p2.x, p2.y);
}

void Core_LineDescartes(float x1, float y1, float x2, float y2, int color, float step = 0.25)
{
	float slope = (y2 - y1) / (x2 - x1);

	int min_x = std::min(x1, x2);
	int max_x = x1 + x2 - min_x;
	float b_param = y1 - (x1 * slope);

	for (float i_x = min_x; i_x <= max_x; i_x += step)
	{
		float f_y = i_x * slope + b_param;
		putpixel(int(i_x), int(f_y), color);
	}
}

void SFR::Canvas::DrawLineDescartes(float x1, float y1, float x2, float y2)
{
	if (!_is_init)
	{
		WARN_NO_INIT
		return;
	}
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
	{
		WARN_NO_NEG
		return;
	}

	Core_LineDescartes(x1, y1, x2, y2, _brush_color); // x Öá×ø±ê
}

void Core_LineDDA(float x1, float y1, float x2, float y2, int color)
{
	float slope = (y2 - y1) / (x2 - x1);


	if (slope <= 1.0)
	{
		int min_x = std::min(x1, x2);
		int max_x = x1 + x2 - min_x;
		float b_param = y1 - (x1 * slope);

		for (float i_x = min_x; i_x <= max_x; i_x += 1)
		{
			float f_y = i_x * slope + b_param;
			putpixel(int(i_x), int(f_y), color);
		}
	}
	else
	{
		int min_y = std::min(y1, y2);
		int max_y = y1 + y2 - min_y;
		float b_param = x1 - (y1 * slope);

		for (float i_y = min_y; i_y <= max_y; i_y += 1)
		{
			float f_x = i_y / slope + b_param;
			putpixel(int(f_x), int(i_y), color);
		}
	}

}

void SFR::Canvas::DrawLineDDA(int x1, int y1, int x2, int y2)
{
	DrawLineDDA(float(x1), float(y1), float(x2), float(y2));
}

void SFR::Canvas::DrawLineDDA(float x1, float y1, float x2, float y2)
{
	if (!_is_init)
	{
		WARN_NO_INIT
		return;
	}
	Core_LineDDA(x1, y1, x2, y2, _brush_color);
}

void SFR::Canvas::DrawLineDDA(glm::vec2 p1, glm::vec2 p2)
{
	DrawLineDDA(p1.x, p1.y, p2.x, p2.y);
}

void SFR::Canvas::DrawLineBresenham(int x1, int y1, int x2, int y2)
{
	DrawLineBresenham(float(x1), float(y1), float(x2), float(y2));
}

void Core_LineBresenham(float x1, float y1, float x2, float y2, int color)
{
	float slope = (y2 - y1) / (x2 - x1);

	if (slope <= 1.0)
	{
		int min_x = std::min(x1, x2);
		int max_x = x1 + x2 - min_x;
		float b_param = y1 - (x1 * slope);

		for (float i_x = min_x; i_x <= max_x; i_x += 1)
		{
			float f_y = i_x * slope + b_param;
			putpixel(int(i_x), int(ceil(f_y)), color);
		}
	}
	else
	{
		int min_y = std::min(y1, y2);
		int max_y = y1 + y2 - min_y;
		float b_param = x1 - (y1 * slope);

		for (float i_y = min_y; i_y <= max_y; i_y += 1)
		{
			float f_x = i_y / slope + b_param;
			putpixel(int(ceil(f_x)), int(i_y), color);
		}
	}

}

void SFR::Canvas::DrawLineBresenham(float x1, float y1, float x2, float y2)
{
	if (!_is_init)
	{
		WARN_NO_INIT
			return;
	}
	if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0)
	{
		WARN_NO_NEG
			return;
	}

	Core_LineBresenham(x1, y1, x2, y2, _brush_color);
}

void SFR::Canvas::DrawLineBresenham(glm::vec2 p1, glm::vec2 p2)
{
	DrawLineBresenham(p1.x, p1.y, p2.x, p2.y);
}

void SFR::Canvas::DrawOrbicular(int r, int x, int y)
{
	DrawOrbicular(float(r), float(x), float(y));
}

void Core_Orbicular(float r, float x, float y, int color)
{

}

void SFR::Canvas::DrawOrbicular(float r, float x, float y)
{
	if (!_is_init)
	{
		WARN_NO_INIT
			return;
	}
	if (r < 0 || x < 0 || y1 < 0 || y < 0)
	{
		WARN_NO_NEG
			return;
	}
	Core_Orbicular(r, x, y, _brush_color);
}

void SFR::Canvas::DrawOrbicular(float r, glm::vec2 p)
{
	DrawOrbicular(float(r), p.x, p.y);
}

void SFR::Canvas::DrawOrbicular(glm::vec3 com)
{
	DrawOrbicular(com.z, com.x, com.y);
}
