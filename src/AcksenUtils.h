/*!
@file AcksenUtils.h
 
*/
 
/***********************************************************
This source file is licenced using the 3-Clause BSD License.

Copyright (c) 2022 Acksen Ltd, All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************/

// Acksen Utilities Library v1.4.0

// v1.4.0	25 Jul 2022
// - Add licence, other cosmetic/comments changes for preparation for open source release
//
// v1.3.0	22 Jan 2020
// - Add functions for working with unsigned long arrays
//
// v1.2.0	15 Apr 2019
// - Add sortLongArray function
//
// v1.1.0	15 Mar 2018
// - Add support for Float and Int array functions
// - Add support for SERIAL_DEBUG calls
//
// v1.0.0	26 Oct 2017
// - Initial Version
//

#ifndef AcksenUtils_h
#define AcksenUtils_h

#define AcksenUtils_ver		140						///< Constant used to set the present library version. Can be used to ensure any code using this library, is correctly updated with necessary changes in subsequent versions, before compilation.

// Constants
#define TEMP_UNITS_CELSIUS						0	///< Set temperature units to Celsius.  Used as a constant within code that includes this library.
#define TEMP_UNITS_FAHRENHEIT					1	///< Set temperature units to Fahrenheit.  Used as a constant within code that includes this library.
#define TEMP_UNITS_COUNT						1	///< Total number of supported temperature units (zero indexed)

#define TEMP_UNITS_DEFAULT						TEMP_UNITS_CELSIUS	///< Default temperature units.  Used as a constant within code that includes this library.

/* 
@code

Conditional Debugging Helpers:

Define SERIAL_DEBUG in calling code to allow use of debug helper functions.
beginDebug()  do { DebugSerial.begin(DEBUG_BAUD_RATE); } while (0)	// Serial port agnostic version of Serial.begin()

// Serial port agnostic version of Serial.print()
Trace(x)      DebugSerial.print(x)	

// Serial port agnostic version of Serial.println()
Traceln(x)    DebugSerial.println(x)	

// Serial port agnostic version of Serial.print(), with inclusion of name of function it is being called in
TraceFunc()   do { DebugSerial.print ("In function: "); DebugSerial.println (__PRETTY_FUNCTION__); } while (0)	

// Serial port agnostic version of Serial.flush()
TraceFlush()  DebugSerial.flush()	

@endcode
*/


// conditional debugging
#if SERIAL_DEBUG 

#define beginDebug()  do { DebugSerial.begin (DEBUG_BAUD_RATE); } while (0)	///< Serial port agnostic version of Serial.begin()
#define Trace(x)      DebugSerial.print   (x)	///< Serial port agnostic version of Serial.print()
#define Traceln(x)    DebugSerial.println (x)	///< Serial port agnostic version of Serial.println()
#define TraceFunc()   do { DebugSerial.print (F("In function: ")); DebugSerial.println (__PRETTY_FUNCTION__); } while (0)	///< Serial port agnostic version of Serial.print(), with inclusion of name of function it is being called in
#define TraceFlush()  DebugSerial.flush()	///< Serial port agnostic version of Serial.flush()

#else

#define beginDebug()  ((void) 0)
#define Trace(x)      ((void) 0)
#define Traceln(x)    ((void) 0)
#define TraceFunc()   ((void) 0)
#define TraceFlush()  ((void) 0)

#endif // SERIAL_DEBUG

/**************************************************************************/
/*! 
    @brief  Class that defines the AcksenUtils functions
*/
/**************************************************************************/

class AcksenUtils
{

public:
	
/**************************************************************************/
/*!
    @brief  Class initialisation.
            Sets up the AcksenUtils library.
    @return No return value.
*/
/**************************************************************************/		
	AcksenUtils(void);
	
/**************************************************************************/
/*!
    @brief  Find the Minimum, Maximum, Mean Average and Range for a given array of floats.
    @param  &fMin
            Pointer to a float that will return the Minimum value in the float array.
    @param  &fMax
            Pointer to a float that will return the Maximum value in the float array.
    @param  &fAvg
            Pointer to a float that will return the Mean Average value in the float array.
    @param  &fRange
            TPointer to a float that will return the Range of the float array.
    @param  fValueArray[]
            Array of floats to calculate Statistics using.
    @param  uiArraySize
            Size of float array being passed through.
    @return No return value.
*/
/**************************************************************************/
	void CalculateFloatArrayStatistics(float &fMin, float &fMax, float &fAvg, float &fRange, float fValueArray[], uint8_t uiArraySize);

/**************************************************************************/
/*!
    @brief  Insert a float value at the start of a float array, moving existing values forward in position.
			Last value in array will be discarded.
			Designed for using a FILO float array buffer for measurements.
    @param  fValueArray[]
            Array of floats to insert new value into.
    @param  uiArraySize
            Size of float array being passed through.
    @param  fNewValue
            New float value to insert at start of array.
    @return No return value.
*/
/**************************************************************************/
	void ShiftAndAddToFloatArrayStart(float fValueArray[], uint8_t uiArraySize, float fNewValue);

/**************************************************************************/
/*!
    @brief  Insert a float value at the end of a float array, moving existing values backwards in position.
			First value in array will be discarded.
			Designed for using a FILO float array buffer for measurements.
    @param  fValueArray[]
            Array of floats to insert new value into.
    @param  uiArraySize
            Size of float array being passed through.
    @param  fNewValue
            New float value to insert at end of array.
    @return No return value.
*/
/**************************************************************************/
	void ShiftAndAddToFloatArrayEnd(float fValueArray[], uint8_t uiArraySize, float fNewValue);
	
/**************************************************************************/
/*!
    @brief  Find the Minimum, Maximum, Mean Average and Range for a given array of ints.
    @param  &iMin
            Pointer to an int that will return the Minimum value in the int array.
    @param  &iMax
            Pointer to an int that will return the Maximum value in the int array.
    @param  &fAvg
            Pointer to an float that will return the Mean Average value in the int array.
    @param  &iRange
            TPointer to an int that will return the Range of the int array.
    @param  iValueArray[]
            Array of floats to calculate Statistics using.
    @param  uiArraySize
            Size of int array being passed through.
    @return No return value.
*/
/**************************************************************************/
	void CalculateIntArrayStatistics(int &iMin, int &iMax, float &fAvg, int &iRange, int iValueArray[], uint8_t uiArraySize);

/**************************************************************************/
/*!
    @brief  Insert a float value at the start of an int array, moving existing values forward in position.
			Last value in array will be discarded.
			Designed for using a FILO int array buffer for measurements.
    @param  iValueArray[]
            Array of ints to insert new value into.
    @param  uiArraySize
            Size of int array being passed through.
    @param  iNewValue
            New int value to insert at start of array.
    @return No return value.
*/
/**************************************************************************/
	void ShiftAndAddToIntArrayStart(int iValueArray[], uint8_t uiArraySize, int iNewValue);

/**************************************************************************/
/*!
    @brief  Insert a int value at the end of a int array, moving existing values backwards in position.
			First value in array will be discarded.
			Designed for using a FILO int array buffer for measurements.
    @param  iValueArray[]
            Array of ints to insert new value into.
    @param  uiArraySize
            Size of int array being passed through.
    @param  iNewValue
            New int value to insert at end of array.
    @return No return value.
*/
/**************************************************************************/
	void ShiftAndAddToIntArrayEnd(int iValueArray[], uint8_t uiArraySize, int iNewValue);
/**************************************************************************/
/*!
    @brief  Sort int array into ascending order.
    @param  a[]
            Array of ints to sort.
    @param  uiSize
            Size of int array being passed in.
    @return No return value.
*/
/**************************************************************************/
	void sortIntArray(int a[], unsigned int uiSize);
	
/**************************************************************************/
/*!
    @brief  Sort unsigned int array into ascending order.
    @param  a[]
            Array of unsigned ints to sort.
    @param  uiSize
            Size of unsigned int array being passed in.
    @return No return value.
*/
/**************************************************************************/
	void sortUIntArray(unsigned int a[], unsigned int uiSize);

/**************************************************************************/
/*!
    @brief  Sort long array into ascending order.
    @param  a[]
            Array of longs to sort.
    @param  uiSize
            Size of long array being passed in.
    @return No return value.
*/
/**************************************************************************/
	void sortLongArray(long a[], unsigned int uiSize);
	
/**************************************************************************/
/*!
    @brief  Sort unsigned long array into ascending order.
    @param  a[]
            Array of unsigned longs to sort.
    @param  uiSize
            Size of unsigned long array being passed in.
    @return No return value.
*/
/**************************************************************************/
	void sortUnsignedLongArray(unsigned long a[], unsigned int uiSize);
	
/**************************************************************************/
/*!
    @brief  Find the Minimum, Maximum, Mean Average and Range for a given array of unsigned longs.
    @param  &ulMin
            Pointer to a unsigned long that will return the Minimum value in the unsigned long array.
    @param  &ulMax
            Pointer to a unsigned long that will return the Maximum value in the unsigned long array.
    @param  &ulAvg
            Pointer to a unsigned long that will return the Mean Average value in the unsigned long array.
    @param  &ulRange
            TPointer to a unsigned long that will return the Range of the unsigned long array.
    @param  ulValueArray
            Array of unsigned longs to calculate Statistics using.
    @param  uiArraySize
            Size of unsigned long array being passed through.
    @return No return value.
*/
/**************************************************************************/
	void CalculateUnsignedLongArrayStatistics(unsigned long &ulMin, unsigned long &ulMax, float &fAvg, unsigned long &ulRange, unsigned long ulValueArray[], uint8_t uiArraySize);

/**************************************************************************/
/*!
    @brief  Calculate the free RAM available on the Arduino MCU.  Designed to work with 8-bit AVR platforms.
    @return Free RAM in bytes.
*/
/**************************************************************************/
	int freeRam();
	
/**************************************************************************/
/*!
    @brief  Converts a Celsius float temperature value to a Fahrenheit float temperature value.
			Value returned will be clamped to within supplied min/max range values.
    @param  fTemperature
            Celsius temperature value to be converted
    @param  fMinTempRange
            Minimum Fahrenheit value acceptable after conversion..
    @param  fMaxTempRange
	        Maximum Fahrenheit value acceptable after conversion.
    @return Temperature float value in Fahrenheit.
*/
/**************************************************************************/
	float ConvertCelsiusToFahrenheit(float fTemperature, float fMinTempRange, float fMaxTempRange);
	
/**************************************************************************/
/*!
    @brief  Converts a Fahrenheit float temperature value to a Celsius float temperature value.
			Value returned will be clamped to within supplied min/max range values.
    @param  fTemperature
            Fahrenheit temperature value to be converted
    @param  fMinTempRange
            Minimum Celsius value acceptable after conversion..
    @param  fMaxTempRange
	        Maximum Celsius value acceptable after conversion.
    @return Temperature float value in Celsius.
*/
/**************************************************************************/	
	float ConvertFahrenheitToCelsius(float fTemperature, float fMinTempRange, float fMaxTempRange);
	
protected: 
  
};

#endif


