// Copyright (c) 2012-2017 The Cryptonote developers
// Copyright (c) 2018-2023 Conceal Network & Conceal Devs
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "gtest/gtest.h"
#include <Common/JsonValue.h>

using common::JsonValue;

namespace {

std::vector<std::string> goodPatterns{
  "{}",
  "   {}   ",
  "   {   }   ",
  "100",
  "[10,20,30]",
  "  [  10  , \n 20  , \n  30  ]  ",
  "{\"prop\": 100}",
  "{\"prop\": 100, \"prop2\": [100, 20, 30] }",
  "{\"prop\": 100, \"prop2\": { \"p\":\"test\" } }",

};


std::vector<std::string> badPatterns{
  "",
  "1..2",
  "\n\n",
  "{",
  "[",
  "[100,",
  "[[]",
  "\"",
  "{\"prop: 100 }",
  "{\"prop\" 100 }",
  "{ prop: 100 }",
};

}

TEST(JsonValue, testGoodPatterns) {
  for (const auto& p : goodPatterns) {
    std::cout << "Pattern: " << p << std::endl;
    ASSERT_NO_THROW(common::JsonValue::fromString(p));
  }
}

TEST(JsonValue, testBadPatterns) {
  for (const auto& p : badPatterns) {
    ASSERT_ANY_THROW(common::JsonValue::fromString(p));
  }
}

