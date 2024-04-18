/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.gtest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:58:28 by mogawa            #+#    #+#             */
/*   Updated: 2023/12/05 21:41:24 by mogawa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <iostream>

class HarlTest : public testing::Test
{
	protected:
		Harl harl;
		std::streambuf		*originalCoutBuf;
		std::ostringstream	capturedCout;

	void SetUp() override
	{
		originalCoutBuf = std::cout.rdbuf();
		std::cout.rdbuf(capturedCout.rdbuf());
	}
	void TearDown() override
	{
		std::cout.rdbuf(originalCoutBuf);
	}
};

TEST_F(HarlTest, testDebug)
{
	harl.complain("DEBUG");
	EXPECT_EQ(capturedCout.str(), DEBUG_STR + "\n\n" + INFO_STR + "\n\n" + WARNING_STR + "\n\n" + ERROR_STR + "\n\n");
}

TEST_F(HarlTest, testInfo)
{
	harl.complain("INFO");
	EXPECT_EQ(capturedCout.str(), INFO_STR + "\n\n" + WARNING_STR + "\n\n" + ERROR_STR + "\n\n");
}

TEST_F(HarlTest, testWarning)
{
	harl.complain("WARNING");
	EXPECT_EQ(capturedCout.str(), WARNING_STR + "\n\n" + ERROR_STR + "\n\n");
}

TEST_F(HarlTest, testError)
{
	harl.complain("ERROR");
	EXPECT_EQ(capturedCout.str(), ERROR_STR + "\n\n");
}

TEST_F(HarlTest, testInvalidInput)
{
	harl.complain("ABC");
	EXPECT_EQ(capturedCout.str(), INVALID_STR + "\n");
}

TEST_F(HarlTest, testEmptyInput)
{
	harl.complain("");
	EXPECT_EQ(capturedCout.str(), INVALID_STR + "\n");
}

TEST_F(HarlTest, testInputWithSpaces)
{
	harl.complain("	          B");
	EXPECT_EQ(capturedCout.str(), INVALID_STR +"\n");
}

TEST_F(HarlTest, testInputWithCapitals)
{
	harl.complain("debug");
	EXPECT_EQ(capturedCout.str(), INVALID_STR + "\n");
}
