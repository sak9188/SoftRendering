#pragma once
#include "SFRSetting.h"
#include <glm\glm.hpp>
#include <graphics.h>

namespace SFR
{
	class Canvas
	{
		SINGLETON(Canvas)
	public:
		void Init(glm::vec2 size);
		void Init(int width, int height);
		void Init(float width, float height);

		// ������Ⱦ����
		// void SetRenderFunc(func*);
		// void RenderLoop();
		// void RenderOnce(func*=nullptr);

		void SetBrushColor(glm::vec4 color);

		// ���� ����Bresenham 
		void SetDrawLineMode(/* ö�� */);
		void DrawLine(int x, int y);
		void DrawLine(float x, float y);
		// �ѿ�������
		void DrawLineDescartes(int x1, int y1, int x2, int y2);
		void DrawLineDescartes(float x1, float y1, float x2, float y2);
		void DrawLineDescartes(glm::vec2 p1, glm::vec2 p2);
		// DDA����
		void DrawLineDDA(int x1, int y1, int x2, int y2);
		void DrawLineDDA(float x1, float y1, float x2, float y2);
		void DrawLineDDA(glm::vec2 p1, glm::vec2 p2);
		// Bresenham����
		void DrawLineBresenham(int x1, int y1, int x2, int y2);
		void DrawLineBresenham(float x1, float y1, float x2, float y2);
		void DrawLineBresenham(glm::vec2 p1, glm::vec2 p2);

		// ����Բ
		void DrawOrbicular(int r, int x, int y);
		void DrawOrbicular(float r, float x, float y);
		void DrawOrbicular(float r, glm::vec2 p);
		void DrawOrbicular(glm::vec3 com);

	private:
		bool _is_init;
		glm::uint _brush_color;
		glm::vec2 _size;
		// func* _render_fun;

		~Canvas();
	};
}