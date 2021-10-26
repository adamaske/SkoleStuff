#include "pch.h"
#include "Form1.h"
#include <math.h>
#include <iostream>


System::Void CppCLRWinformsProjekt::Form1::TstDisplay_Click(System::Object^ sender, System::EventArgs^ e)
{
	float fxArray[2][NO_OF_STEPS_TO_STORE]{};
	float fxArray2[2][NO_OF_STEPS_TO_STORE]{};

	bool aOK = sinus(0,2*3.14,fxArray);
	bool bOK = Display2(fxArray, 0);
	bool aOK2 = cosinus(0, 2 * 3.14, fxArray2);
	bool bOK2 = Display2(fxArray2, 1);

	return System::Void();
}

bool CppCLRWinformsProjekt::Form1::sinus(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]) {
	float delta = (tEnd - tStart) / (NO_OF_STEPS_TO_STORE-1);
	float x = tStart;// +delta / 2;
	float fx;
	float R = 12000;
	
	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {
		
		fArr[0][ix] = x;
		fArr[1][ix] = cos(x);

		x = x + delta;
	}
	return true;
}
bool CppCLRWinformsProjekt::Form1::cosinus(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]) {
	float delta = (tEnd - tStart) / (NO_OF_STEPS_TO_STORE - 1);
	float x = tStart;// +delta / 2;
	float fx;
	float R = 0;

	for (int ix = 0; ix < NO_OF_STEPS_TO_STORE; ix++) {

		fArr[0][ix] = x;
		fArr[1][ix] = cos(x);

		x = x + delta;
	}
	return true;
}


bool CppCLRWinformsProjekt::Form1::Display2(float d2dArr[2][NO_OF_STEPS_TO_STORE], int serieNr)
{
	for (int i = 0; i < NO_OF_STEPS_TO_STORE; i++) {
		this->chart1->Series[serieNr]->Points->AddXY(d2dArr[0][i], d2dArr[1][i]);
	}
	return false;
}


