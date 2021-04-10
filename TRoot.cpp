#include "TRoot.h"

void TChart::Show(Graphics^ gr) {
	TLine CurrLine;
	TRoot* pr;
	TPoint* pp;
	CurrLine.pChart = this;
	CurrLine.pFp = CurrLine.pLp = NULL;
	st.clear();
}