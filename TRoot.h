#pragma once
#include "stack.h"
#include "MyForm.h"
#include <Windows.h>

class TRoot
{
protected:
	bool Visible, Active;
public:
	TRoot() {
		Visible = true;
		Active = false;
	}
	bool IsVisible(){ return Visible; }
	bool IsActive() { return Active; }
	virtual void Show(Graphics^ gr) = 0;
	virtual void Hide(Graphics^ gr) = 0;
};

class TPoint : public TRoot {
protected:
	int x, y;
public:
	TPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int GetX() { return x; }
	int GetY() { return y; }
	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	int* X() { return &x; }
	int* Y() { return &y; }
	virtual void Show(Graphics^ gr) {
		gr->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
		Visible = true;
	}
	virtual void Hide(Graphics^ gr) {
		gr->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
		Visible = false;
	}
};

class TChart :public TRoot {
protected:
	std::stack<TLine> st;
	TRoot* pFirst, * pLast;
public:
	TChart() { pFirst = pLast = NULL; }
	virtual void Show(Graphics^ gr);
	virtual void Hide(Graphics^ gr);
	int GetSize() { return (bool)pFirst + (bool)pLast; }
	void SetFirst(TRoot* p) {
		TPoint* pPoint = dynamic_cast<TPoint*>(p);
		TChart* pChart = dynamic_cast<TChart*>(p);
		if (pPoint || pChart)
			pFirst = p;
	}
	void SetLast(TRoot* p) {
		///
		pLast = p;
	}
};

struct TLine {
	TChart* pChart;
	TPoint* pFp, * pLp; // pFirstPoint, pLastPoint
};


