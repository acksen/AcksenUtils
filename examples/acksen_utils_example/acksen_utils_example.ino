/***********************************************************
This source file is licenced using the 3-Clause BSD License.

Copyright (c) 2022 Acksen Ltd, All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************/

/*
Example: 		acksen_utils_example.ino
Library:		AcksenUtils
Author: 		Richard Phillips for Acksen Ltd

Created:		25 Jul 2022
Last Modified:		25 Jul 2022

Description:
Demonstrate via debug serial port, the usage of helper functions in the AcksenUtils library.

*/

#include <AcksenUtils.h>

// ***********************************

// Note - Ports are initialised using Serial identifier in Setup() section:
// modify this manually if any changes made here to ports in use
#define DebugSerial			Serial
#define DEBUG_BAUD_RATE			115200

// ***********************************
// I/O  
// ***********************************

// ***********************************
// Constants
// ***********************************
#define SERIAL_DEBUG	true	// This enables the serial debug system.  If this is set to False, no serial debug output will occur.
				// This allows debug output to be toggled on/off for the entire project easily.
				
#define TEMP_CEL_VALUE_MIN		0	// Minimum allowable Celsius value
#define TEMP_CEL_VALUE_MAX		110	// Maximum allowable Celsius value

#define TEMP_FAH_VALUE_MIN		32	// Minimum allowable Fahrenheit value
#define TEMP_FAH_VALUE_MAX		230	// Minimum allowable Fahrenheit value

// ***********************************
// Variables
// ***********************************
AcksenUtils Utilities;	// Initialise the AcksenUtils class object

// ************************************************
// Setup 
// ************************************************
void setup()
{
	// Debug Serial Port Setup, using the DebugSerial port defined above
	beginDebug();

	
	Traceln("Startup Complete!");	// Use the Traceln() helper function instead of Serial.println()
	Traceln("");
	
	Trace(F("Startup FreeRAM:"));
	Traceln(Utilities.freeRam());	// Return the amount of free RAM, in Bytes.
	Traceln("");
	
}

// ************************************************
// Main Control Loop
// ************************************************
void loop()
{

	// *************************************************
	// Demonstration of Temperature Conversion functions
	int iCelsiusValue;
	int iFahrenheitValue;
	
	// Convert a value from Celsius to Fahrenheit
	iCelsiusValue = 50;
	iFahrenheitValue = TEMP_FAH_VALUE_MIN;
	iFahrenheitValue = Utilities.ConvertCelsiusToFahrenheit(iCelsiusValue, TEMP_FAH_VALUE_MIN, TEMP_FAH_VALUE_MAX)

	Traceln("Celsius to Fahrenheit Conversion:");
	Traceln("");
	
	Trace("Celsius Value = ");
	Trace(iCelsiusValue);
	Traceln("C");
	
	Trace("Converted Fahrenheit Value = ");
	Trace(iFahrenheitValue);
	Traceln("F");
	Traceln("");
	
	
	// Convert a value from Fahrenheit to Celsius
	iCelsiusValue = TEMP_CEL_VALUE_MIN;
	iFahrenheitValue = 91;
	iCelsiusValue = Utilities.ConvertFahrenheitToCelsius(iFahrenheitValue, TEMP_CEL_VALUE_MIN, TEMP_CEL_VALUE_MAX)

	Traceln("Fahrenheit to Celsius Conversion:");
	Traceln("");
	
	Trace("Fahrenheit Value = ");
	Trace(iFahrenheitValue);
	Traceln("F");
	
	Trace("Converted Celsius Value = ");
	Trace(iCelsiusValue);
	Traceln("C");
	Traceln("");


	// *************************************************
	// Demonstration of Array Sorting and Statistics functions
	
	int iArrayMinValue, iArrayMaxValue, iArrayRange;
	float fArrayAvgValue;
	int iTestArray[5] = {5, 1, 3, 2, 4}
	unsigned int uiArraySize = sizeof(iTestArray);

	// Calculate Statistics for int array
	Utilities.CalculateIntArrayStatistics(iArrayMinValue, iArrayMaxValue, fArrayAvgValue, iArrayRange, iTestArray, uiArraySize);
		
	Traceln("Unsorted Int Array:");		
	for (byte i = 0; i < uiArraySize; i = i + 1) 
	{
		Trace("Array Element");
		Trace(byte);
		Trace(" = ");
	  	Traceln(iTestArray[i]);
	}
	
	Trace("Min Value = ");
	Traceln(iArrayMinValue);
	
	Trace("Max Value = ");
	Traceln(iArrayMaxValue);

	Trace("Mean Average = ");
	Traceln(fArrayAvgValue);
	
	Trace("Range = ");
	Traceln(iArrayRange);
	
	Traceln(");
	
	// Sort Int Array
	Utilities.sortIntArray(iTestArray, uiArraySize);
	
	Traceln("Sorted Int Array:");		
	for (byte i = 0; i < uiArraySize; i = i + 1) 
	{
		Trace("Array Element");
		Trace(byte);
		Trace(" = ");
	  	Traceln(iTestArray[i]);
	}
	
	
}