#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

/*!
 * Used to modulus zip code by 10 along with divisor to split digit up.
*/
const int mod_by = 10;

/*!
 * Divide by 10 after using modulus to split digit up.
*/
const int divisor = 10;

/*!
 * Number subtracted from to get the check digit.
*/
const int check_multiple = 10;

/*!
 * Number of spaces between city and state.
*/
const int spacer = 10;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_zero = 0;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_one = 1;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_two = 2;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_three = 3;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_four = 4;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_five = 5;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_six = 6;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_seven = 7;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_eight = 8;

/*!
 * Bar value which will be displayed based on the value of the digit being compared.
*/
const int bar_nine = 9;

/*!
 *\brief prompts the user with the given string and returns the integer entered.
 * Prompts the user for string value storing the integer for future use.
 *\param prompt part of zip code being asked for.
 *\return the int value for the prompted string.
*/
int get_int(std::string prompt);

/*!
 *\brief prompts the user with the given string and returns the value entered.
 * Prompts the user for string value storing the string for future use.
 *\param prompt part of address being asked for.
 *\return the value for the prompted string.
*/
std::string get_string(std::string prompt);

/*!
 *\brief takes zip entered from user and finds check digit.
 * Takes 5 digit zip code and computes the check digit.
 *\param zip is the zip code inputed by user.
 *\return the check digit for zip code input.
*/
int check_digit(int zip);

/*!
 *\brief converts the given digit to its bar code representation.
 * Takes zip check digit and converts the digit into its equivalent bar code representation.
 *\param digit is the zip check digit computed by the check_digit function.
 *\return the string bar code value for the zip code's check digit.
*/
std::string encode_digit(int digit);

/*!
 *\brief converts the given zip code to its bar code representation.
 * Takes zip code entered by user and converts the zip into its equivalent bar code representation.
 *\param zip_code is the zip code entered by the user.
 *\return the string bar code value for the entire zip code.
*/
std::string encode_zip_code(int zip_code);

int main()
{
	std::string name = get_string("Enter your name > ");
	getline(std::cin, name);

	std::string street = get_string("Enter your street with number > ");
	getline(std::cin, street);

	std::string city = get_string("Enter your city > ");
	getline(std::cin, city);

	std::string state = get_string("Enter your state > ");
	getline(std::cin, state);

	auto zip = get_int("Enter 5 digit zip code > ");
	std::cin >> zip;

	auto zip_extension = get_string("Enter 4 digit zip extension > ");
	std::cin >> zip_extension;

	auto zip_check_digit = check_digit(zip);

	auto check_digit_barcode = encode_digit(zip_check_digit);

	auto bar_code_value = encode_zip_code(zip);

	std::ofstream fout;
	fout.open("address.txt");

	fout << name << std::endl;
	fout << street << std::endl;
	fout << city << std::setw(spacer) << state << ' ' << zip << '-' << zip_extension << std::endl;
	fout << std::endl;
	fout << bar_code_value << std::endl;

	fout.close();

	return 0;
}

/*!
 *\brief prompts the user with the given string and returns the integer entered.
 * Prompts the user for string value storing the integer for future use.
 *\param Part of address being asked for.
 *\return the int value for the prompted string.
*/
int get_int(std::string prompt)
{
	std::cout << prompt;
	auto value = 0;

	return value;
}

/*!
 *\brief prompts the user with the given string and returns the value entered.
 * Prompts the user for string value storing the string for future use.
 *\param prompt part of address being asked for.
 *\return the value for the prompted string.
*/
std::string get_string(std::string prompt)
{
	std::cout << prompt;
	std::string address;

	return address;
}

/*!
 *\brief takes zip entered from user and finds check digit.
 * Takes 5 digit zip code and computes the check digit.
 *\param zip is the zip code inputed by user.
 *\return the check digit for zip code input.
*/
int check_digit(int zip)
{
	int sum_of_digits = 0;
	int check_digit = 0;
	while (zip)
	{
		sum_of_digits = sum_of_digits + zip % mod_by;
		zip % mod_by;
		zip = zip / divisor;
	}
	check_digit = check_multiple - (sum_of_digits % mod_by);

	return check_digit;
}

/*!
 *\brief Converts the given digit to its bar code representation.
 * Takes zip check digit and converts the digit into its equivalent bar code representation.
 *\param digit is the zip check digit computed by the check_digit function.
 *\return the string bar code value for the zip code's check digit.
*/
std::string encode_digit(int digit)
{
	if (digit == bar_zero) return "||:::";
	else if (digit == bar_one) return ":::||";
	else if (digit == bar_two) return "::|:|";
	else if (digit == bar_three) return "::||:";
	else if (digit == bar_four) return ":|::|";
	else if (digit == bar_five) return ":|:|:";
	else if (digit == bar_six) return ":||::";
	else if (digit == bar_seven) return "|:::|";
	else if (digit == bar_eight) return "|::|:";
	else if (digit == bar_nine) return "|:|::";
	else return "Invalid";
}

/*!
 *\brief converts the given zip code to its bar code representation.
 * Takes zip code entered by user and converts the zip into its equivalent bar code representation.
 *\param zip_code is the zip code entered by the user.
 *\return the string bar code value for the entire zip code.
*/
std::string encode_zip_code(int zip)
{
	auto zip_check_digit = check_digit(zip);
	auto digit_one = zip % mod_by;
	zip = zip / divisor;
	auto digit_two = zip % mod_by;
	zip = zip / divisor;
	auto digit_three = zip % mod_by;
	zip = zip / divisor;
	auto digit_four = zip % mod_by;
	zip = zip / divisor;
	auto digit_five = zip % mod_by;
	zip = zip / divisor;

	std::string first = "|" + encode_digit(digit_five) + encode_digit(digit_four)
		+ encode_digit(digit_three) + encode_digit(digit_two) + encode_digit(digit_one);
	std::string last = encode_digit(zip_check_digit) + "|";
	return (first + last);
}
