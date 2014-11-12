/*
 * Copyright (C) 2014 MediaSift Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SERVED_RESPONSE_HPP
#define SERVED_RESPONSE_HPP

#include <sstream>
#include <iostream>
#include <map>

#include <served/status.hpp>

namespace served {

/*
 * Represents a HTTP response.
 *
 * This class represents a HTTP response, and provides an appropriate interface
 * for setting properties, and then generating a response string. The class is
 * composed of a status code, headers, and the body of the response.
 *
 * The response to a given HTTP request is built by method handlers in response
 * to a request. This class is used to simplify the method of composing an
 * appropriate response to a request.
 */
class response
{
	typedef std::tuple<std::string, std::string> header_pair;
	typedef std::map<std::string, header_pair>   header_list;

	int               d_status;
	header_list       d_headers;
	std::stringstream d_body;
	std::string       d_buffer;

public:
	//  -----  constructors  -----

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * List each parameter, what is the purpose? What is considered valid /
	 * invalid?
	 */
	response();

	//  -----  response mutators  -----

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @param header ...
	 * @param value ...
	 */
	void set_header(std::string const& header, std::string const& value);

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @param status_code ...
	 */
	void set_status(int status_code);

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @param body ...
	 */
	void set_body(const std::string & body);

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @param rhs ...
	 */
	response& operator<<(std::string const& rhs);

	//  -----  accessors  -----

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @return ...
	 */
	const int status();

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @return ...
	 */
	const int body_size();

	//  -----  serializer  -----

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @return ...
	 */
	const std::string to_buffer();

	//  -----  stock reply  -----

	/*
	 * Describe the method in a single line.
	 *
	 * Describe the work this method does, what does it do? Is there anything
	 * the developer should be aware of?
	 *
	 * @param method ...
	 * @param handler ...
	 */
	static void stock_reply(int status_code, response & res);
};

} // served

#endif // SERVED_RESPONSE_HPP
