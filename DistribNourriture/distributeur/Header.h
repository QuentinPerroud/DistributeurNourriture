#ifndef HEADER_H
#define HEADER_H

#include "tinyxml.h"
#ifndef TESTWINDOWS
#include "wiringPi.h"
#else
#include <Windows.h>
#define delay Sleep

#endif
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#endif
