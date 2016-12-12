#include <gtest\gtest.h>
#include <gmock\gmock.h>
#include "BowlingGame.h"

#include "ImpossibleSpareException.h"
#include "InvalidPinsCharException.h"

using namespace testing;
using namespace std;

class TestFixture : public Test {

public:
	BowlingGame *game;

	void SetUp() override {
		game = new BowlingGame();
	}

	void TearDown() override {
		delete game;
	}
};

TEST_F(TestFixture, Perfect) {

	game->setSequence("XXXXXXXXXXXX");

	ASSERT_THAT(game->getScore(), Eq(300));
}

TEST_F(TestFixture, Zero) {

	game->setSequence("--------------------");

	ASSERT_THAT(game->getScore(), Eq(0));
}

TEST_F(TestFixture, SparesWith5) {

	game->setSequence("5/5/5/5/5/5/5/5/5/5/5");

	ASSERT_THAT(game->getScore(), Eq(150));
}

TEST_F(TestFixture, Game1) {

	game->setSequence("1");

	ASSERT_THAT(game->getScore(), Eq(1));
}

TEST_F(TestFixture, Game2) {

	game->setSequence("1/");

	ASSERT_THAT(game->getScore(), Eq(10));
}

TEST_F(TestFixture, Game3) {

	game->setSequence("1/5");

	ASSERT_THAT(game->getScore(), Eq(20));
}

TEST_F(TestFixture, Game4) {

	game->setSequence("X");

	ASSERT_THAT(game->getScore(), Eq(10));
}

TEST_F(TestFixture, Game5) {

	game->setSequence("XX");

	ASSERT_THAT(game->getScore(), Eq(30));
}

TEST_F(TestFixture, Game6) {

	game->setSequence("XXX");

	ASSERT_THAT(game->getScore(), Eq(60));
}

TEST_F(TestFixture, Game7) {

	game->setSequence("-/-/-/-/-/-/-/-/-/-/-");

	ASSERT_THAT(game->getScore(), Eq(100));
}

TEST_F(TestFixture, DidNotStartYet) {

	game->setSequence("");

	ASSERT_THAT(game->getScore(), Eq(0));
}

TEST_F(TestFixture, ImpossibleSpareExceptionTest) {

	try {
		game->setSequence("/");
		FAIL() << "Expected Impossible Spare Exception.";
	}
	catch (ImpossibleSpareException &e) {
		ASSERT_THAT(e.what(), Eq(string("There is an impossible spare in your scorecard")));
	}
	catch (exception &e) {
		FAIL() << "Expected Impossible Spare Exception.";
	}
}

TEST_F(TestFixture, InvalidPinsCharExceptionTest) {

	try {
		game->setSequence("a");
		FAIL() << "Expected Invalid Pins Char Exception.";
	}
	catch (InvalidPinsCharException &e) {
		ASSERT_THAT(e.what(), Eq(string("There is an invalid character in your scorecard")));
	}
	catch (exception &e) {
		FAIL() << "Expected Invalid Pins Char Exception.";
	}
}