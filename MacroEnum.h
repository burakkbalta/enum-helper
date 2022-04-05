#ifndef MACROENUM_H
#define MACROENUM_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

/*
 * Macro implementation for enum class due to print its enum class values.
 * @name : name of the enum class.
 * @...  : enum class values.
 * @EnumToString : function that returns string representation of a given enum class value.  
 */
#define MACRO_ENUM(name, ...) enum class name {__VA_ARGS__}; \
static std::vector<std::string> Init_##name##_Vec(){\
	const std::string content = #__VA_ARGS__;\
	std::vector<std::string> str;\
	size_t len = content.length();\
	std::ostringstream temp;\
	for(size_t i=0; i<len;++i) {\
	if(isspace(content[i])) continue;\
	else if(content[i] == ','){\
		str.push_back(temp.str());\
		temp.str(std::string());}\
	else temp<< content[i];}\
	str.push_back(temp.str());\
	return str;}\
static const std::vector<std::string> Enum_##name##_Str_Vec = Init_##name##_Vec();\
inline std::string EnumToString(name val) noexcept {\
	return Enum_##name##_Str_Vec[static_cast<size_t>(val)];\
}\
static void PrintAll_##name##_Enum() {\
	std::cout << "All Enum Values : " << "\n";\
	for(const auto& elem : Enum_##name##_Str_Vec) {\
		std::cout << elem << std::endl;\
	}\
}

/*
 * Macro implementation for enum class due to print its enum class values.
 * @name : name of the enum class.
 * @valueType : underlying type for enum class 
 * @...  : enum class value with key and value pairs.
 * @EnumToString : function that returns string representation of a given enum class value. 
 * @PrintAll##name##Enum : function that prints all enum variable with values in enum class named ##name##
 * Usage : MACRO_ENUM_WITH_VALUE(LogTypes, int, DEBUG=0, NORMAL=1, ERROR=2)
 */
#define MACRO_ENUM_WITH_VALUE(name, valueType, ...) enum class name : valueType {__VA_ARGS__};\
static std::map<valueType, std::string> Init_##name##_Map(){\
	const std::string content = #__VA_ARGS__;\
	std::map<valueType, std::string> str;\
	size_t len = content.length();\
	std::ostringstream temp;\
	std::stringstream temp2;\
	std::string k;\
	valueType v;\
	for(size_t i=0; i<len;++i) {\
	if(isspace(content[i])) continue;\
	else if(content[i] == ','){\
		temp2 << temp.str();\
		temp2 >> v;\
		temp.str(std::string());\
		temp2.clear();\
		str[v] = k;}\
	else if(content[i] == '='){\
		k = temp.str();\
		temp.str(std::string());}\
	else temp<< content[i];}\
	temp2 << temp.str();\
	temp2 >> v;\
	str[v]= k;\
	return str;}\
static std::map<valueType, std::string> Enum_##name##_Str_Map = Init_##name##_Map();\
static std::string EnumToString(name val) {\
	return Enum_##name##_Str_Map[static_cast<valueType>(val)];\
}\
static void PrintAll_##name##_Enum() {\
	std::cout << "All Enum Values : " << "\n";\
	for(const auto& elem : Enum_##name##_Str_Map) {\
		std::cout << elem.first << " : " << elem.second << std::endl;\
	}\
}

#endif /* MACROENUM_H */