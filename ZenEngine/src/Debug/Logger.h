#pragma once

#include <iostream>
#include <format>

#ifdef ZEN_DEBUG
	#define DEBUG_ERROR(cause, message) std::cerr << (cause) << "::" << (message) << std::endl
	#define DEBUG_MESSAGE(source, message) std::cout << (source) << "::" << message << std::endl;
	#define DEBUG_CALL(source, message) source(); std::cout << std::format("{}", ##source) << "::" << message << std::endl;
#else
	#define DEBUG_MESSAGE(source, message)
	#define DEBUG_CALL(source, message)
	#define DEBUG_ERROR(cause, message)
#endif