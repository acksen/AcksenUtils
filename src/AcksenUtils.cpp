/***********************************************************/
/*!

@file AcksenUtils.cpp

@mainpage Arduino utility library with miscellaneous functions

@section intro_sec Introduction

This is the documentation for Acksen Ltd's AcksenUtils library for the
Arduino platform.

Arduino utility library with miscellaneous functions, including Debug 
helpers for flexible serial port mapping, statistics and sorting functions 
designed for 8-bit AVR platforms, and temperature conversion.

@section dependencies Dependencies

There are no external dependencies for this library.

Arduino Library rev.2.2 - requires Arduino IDE v1.8.10 or greater.

@section author Author

Written by Richard Phillips for Acksen Ltd.

@section license License

This source file is licenced using the 3-Clause BSD License.

Copyright (c) 2022 Acksen Ltd, All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/***********************************************************/

// Acksen Utilities Library v1.4.0

#include "Arduino.h"
#include "AcksenUtils.h"

AcksenUtils::AcksenUtils(void)
{
	
	// No initialisation required.

}

void AcksenUtils::CalculateFloatArrayStatistics(float &fMin, float &fMax, float &fAvg, float &fRange, float fValueArray[], uint8_t uiArraySize)
{

	// Work out the Statistics from the values recorded in buffer
	fMin = 0;
	fMax = 0;
	fAvg = 0;
	fRange = 0;

	for (int x = 0; x <= uiArraySize - 1; x++)
	{
		if (x == 0)
		{
			// Initialise Values
			fMin = fValueArray[x];
			fMax = fValueArray[x];
		}
		else
		{
			// Update Min/Max values if necessary
			if (fValueArray[x] < fMin)
			{
				fMin = fValueArray[x];
			}
			if (fValueArray[x] > fMax)
			{
				fMax = fValueArray[x];
			}
		}

		fAvg = fAvg + fValueArray[x];
	}

	// Calculate the Average
	fAvg = fAvg / (float)uiArraySize;

	// Calculate the Range
	fRange = fMax - fMin;

	//DebugPort->print(F("Boil Min:"));
	//DebugPort->println(fBoilArrayMinValue);
	//DebugPort->print(F("Boil Max:"));
	//DebugPort->println(fBoilArrayMaxValue);
	//DebugPort->print(F("Boil Range:"));
	//DebugPort->println(fBoilArrayRange);

}

void AcksenUtils::CalculateIntArrayStatistics(int &iMin, int &iMax, float &fAvg, int &iRange, int iValueArray[], uint8_t uiArraySize)
{

	// Work out the Statistics from the values recorded in buffer
	iMin = 0;
	iMax = 0;
	fAvg = 0;
	iRange = 0;

	for (int x = 0; x <= uiArraySize - 1; x++)
	{
		if (x == 0)
		{
			// Initialise Values
			iMin = iValueArray[x];
			iMax = iValueArray[x];
		}
		else
		{
			// Update Min/Max values if necessary
			if (iValueArray[x] < iMin)
			{
				iMin = iValueArray[x];
			}
			if (iValueArray[x] > iMax)
			{
				iMax = iValueArray[x];
			}
		}

		fAvg = (float)fAvg + (float)iValueArray[x];
	}

	// Calculate the Average
	fAvg = fAvg / (float)uiArraySize;

	// Calculate the Range
	iRange = iMax - iMin;

	//DebugPort->print(F("Boil Min:"));
	//DebugPort->println(fBoilArrayMinValue);
	//DebugPort->print(F("Boil Max:"));
	//DebugPort->println(fBoilArrayMaxValue);
	//DebugPort->print(F("Boil Range:"));
	//DebugPort->println(fBoilArrayRange);

}

void AcksenUtils::CalculateUnsignedLongArrayStatistics(unsigned long &ulMin, unsigned long& ulMax, float &fAvg, unsigned long &ulRange, unsigned long ulValueArray[], uint8_t uiArraySize)
{

	// Work out the Statistics from the values recorded in buffer
	ulMin = 0;
	ulMin = 0;
	fAvg = 0;
	ulRange = 0;

	for (int x = 0; x <= uiArraySize - 1; x++)
	{
		if (x == 0)
		{
			// Initialise Values
			ulMin = ulValueArray[x];
			ulMax = ulValueArray[x];
		}
		else
		{
			// Update Min/Max values if necessary
			if (ulValueArray[x] < ulMin)
			{
				ulMin = ulValueArray[x];
			}
			if (ulValueArray[x] > ulMax)
			{
				ulMax = ulValueArray[x];
			}
		}

		fAvg = (float)fAvg + (float)ulValueArray[x];
	}

	// Calculate the Average
	fAvg = fAvg / (float)uiArraySize;

	// Calculate the Range
	ulRange = ulMax - ulMin;

	//DebugPort->print(F("Boil Min:"));
	//DebugPort->println(fBoilArrayMinValue);
	//DebugPort->print(F("Boil Max:"));
	//DebugPort->println(fBoilArrayMaxValue);
	//DebugPort->print(F("Boil Range:"));
	//DebugPort->println(fBoilArrayRange);

}

void AcksenUtils::sortIntArray(int a[], unsigned int uiSize)
{
	for (unsigned int i = 0; i<(uiSize - 1); i++)
	{
		for (unsigned int o = 0; o<(uiSize - (i + 1)); o++)
		{
			if (a[o] > a[o + 1])
			{
				int t = a[o];
				a[o] = a[o + 1];
				a[o + 1] = t;
			}
		}
	}
}

void AcksenUtils::sortUIntArray(unsigned int a[], unsigned int uiSize)
{
	for (unsigned int i = 0; i<(uiSize - 1); i++)
	{
		for (unsigned int o = 0; o<(uiSize - (i + 1)); o++)
		{
			if (a[o] > a[o + 1])
			{
				unsigned int t = a[o];
				a[o] = a[o + 1];
				a[o + 1] = t;
			}
		}
	}
}

void AcksenUtils::sortLongArray(long a[], unsigned int uiSize)
{
	for (unsigned int i = 0; i<(uiSize - 1); i++)
	{
		for (unsigned int o = 0; o<(uiSize - (i + 1)); o++)
		{
			if (a[o] > a[o + 1])
			{
				long t = a[o];
				a[o] = a[o + 1];
				a[o + 1] = t;
			}
		}
	}	
}

void AcksenUtils::sortUnsignedLongArray(unsigned long a[], unsigned int uiSize)
{
	for (unsigned int i = 0; i<(uiSize - 1); i++)
	{
		for (unsigned int o = 0; o<(uiSize - (i + 1)); o++)
		{
			if (a[o] > a[o + 1])
			{
				unsigned long t = a[o];
				a[o] = a[o + 1];
				a[o + 1] = t;
			}
		}
	}	
}


int AcksenUtils::freeRam()
{
	extern int __heap_start;
	extern char *__brkval;
	//extern int __heap_start, *__brkval;

	int v;
	return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

void AcksenUtils::ShiftAndAddToFloatArrayStart(float fValueArray[], uint8_t uiArraySize, float fNewValue)
{

	// Shift all existing array values up by 1 position
	for (int x = uiArraySize - 1; x > 0; x--)
	{
		fValueArray[x] = fValueArray[x - 1];
	}

	// Save new value at position 0 in array
	fValueArray[0] = fNewValue;

}

void AcksenUtils::ShiftAndAddToFloatArrayEnd(float fValueArray[], uint8_t uiArraySize, float fNewValue)
{

	// Shift all existing array values down by 1 position (remove oldest value!)
	for (int x = 0; x < (uiArraySize - 1); x++)
	{
		fValueArray[x] = fValueArray[x+1];
	}

	// Save new value at last position in array
	fValueArray[uiArraySize - 1] = fNewValue;

}

void AcksenUtils::ShiftAndAddToIntArrayStart(int iValueArray[], uint8_t uiArraySize, int iNewValue)
{

	// Shift all existing array values up by 1 position
	for (int x = uiArraySize - 1; x > 0; x--)
	{
		iValueArray[x] = iValueArray[x - 1];
	}

	// Save new value at position 0 in array
	iValueArray[0] = iNewValue;

}

void AcksenUtils::ShiftAndAddToIntArrayEnd(int iValueArray[], uint8_t uiArraySize, int iNewValue)
{

	// Shift all existing array values down by 1 position (remove oldest value!)
	for (int x = 0; x < (uiArraySize - 1); x++)
	{
		iValueArray[x] = iValueArray[x+1];
	}

	// Save new value at last position in array
	iValueArray[uiArraySize - 1] = iNewValue;

}

float AcksenUtils::ConvertCelsiusToFahrenheit(float fTemperature, float fMinTempRange, float fMaxTempRange)
{

	fTemperature = (float)(fTemperature * 1.8) + 32;
	
	if (fTemperature < fMinTempRange)
	{
		fTemperature = fMinTempRange;
	}
	else if (fTemperature > fMaxTempRange)
	{
		fTemperature = fMaxTempRange;
	}

	return fTemperature;

}

float AcksenUtils::ConvertFahrenheitToCelsius(float fTemperature, float fMinTempRange, float fMaxTempRange)
{

	fTemperature = (float)(fTemperature - 32) / 1.8;
	
	if (fTemperature < fMinTempRange)
	{
		fTemperature = fMinTempRange;
	}
	else if (fTemperature > fMaxTempRange)
	{
		fTemperature = fMaxTempRange;
	}

	return fTemperature;

}