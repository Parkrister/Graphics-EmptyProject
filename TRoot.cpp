#include "TRoot.h"

void TChart::Show(Graphics^ gr) {
	TLine CurrLine;
	TRoot* pr;
	TPoint* pp;
	CurrLine.pChart = this;
	CurrLine.pFp = CurrLine.pLp = NULL;
	st.Clear();
	st.push(CurrLine);
	while (!st.empty()) {
		CurrLine = st.pop();
		while (CurrLine.pFp == NULL) {
			pr = CurrLine.pChart->GetFirst();
			pp = dynamic_cast<TPoint*>(pr);
			if (pp) {
				CurrLine.pFp = pp;
				pp->Show(gr);
			}
			else {
				st.push(CurrLine);
				CurrLine.pChart = dynamic_cast<TChart*>(pr);
			}
		}
		if (CurrLine.pLp == NULL) {
			pr = CurrLine.pChart->GetLast();
			pp = dynamic_cast<TPoint*>(pr);
			if (pp != NULL) {
				CurrLine.pLp = pp;
				pp->Show(gr);
			}
			else {
				st.push(CurrLine);
				CurrLine.pChart = dynamic_cast<TChart*>(pr);
				CurrLine.pFp = NULL;
				st.push(CurrLine);
			}
		}
		if (CurrLine.pFp != NULL && CurrLine.pLp != NULL) {
			gr->DrawLine(/*//*/);
			pp = CurrLine.pLp;
			if (!st.empty()) {
				CurrLine = st.pop();
				if (CurrLine.pFp == NULL)
					CurrLine.pFp = pp;
				else
					CurrLine.pLp = pp;
				st.push(CurrLine);
			}
		}
	}
}