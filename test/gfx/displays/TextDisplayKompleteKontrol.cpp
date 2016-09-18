/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include <catch.hpp>
#include <gfx/displays/TextDisplayKompleteKontrol.h>

//--------------------------------------------------------------------------------------------------

namespace sl
{
namespace cabl
{
namespace test
{

//--------------------------------------------------------------------------------------------------

TEST_CASE("TextDisplayKompleteKontrol: constructor", "[gfx][displays][TextDisplayKompleteKontrol]")
{
  TextDisplayKompleteKontrol display;
  CHECK(display.width() == 8);
  CHECK(display.height() == 3);
}

//--------------------------------------------------------------------------------------------------

// clang-format off
TEST_CASE("TextDisplayKompleteKontrol: set text", "[gfx][displays][TextDisplayKompleteKontrol]")
{
  TextDisplayKompleteKontrol display;

  SECTION("Write text to first row")
  {
    display.putText("@A text@+!ˆ&",0,Alignment::Center);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    CHECK( displayData == expected );
  }

  SECTION("Write text to second row")
  {
    display.putText("@A text@+!ˆ&",1,Alignment::Center);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x7F, 0x48, 0xCF, 0x18, 0x00, 0x00, 0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08, 0x7F, 0x48,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    CHECK( displayData == expected );
  }

  SECTION("Write text to third row")
  {
    display.putText("@A text@+!ˆ&",2,Alignment::Center);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x7F, 0x48, 0xCF, 0x18, 0x00, 0x00, 0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08, 0x7F, 0x48,
    };
    CHECK( displayData == expected );
  }

  SECTION("Text alignment - 1")
  {
    display.putText("text",0,Alignment::Center);
    display.putText("text",1,Alignment::Right);
    display.putText("text",2,Alignment::Left);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08,
      0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    CHECK( displayData == expected );
  }

  SECTION("Text alignment - 2")
  {
    display.putText("text",0,Alignment::Left);
    display.putText("text",1,Alignment::Center);
    display.putText("text",2,Alignment::Right);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x08, 0x60, 0x28, 0x00, 0x66, 0xE0, 0x08,
    };
    CHECK( displayData == expected );
  }

  SECTION("Numbers (integers)")
  {
    display.putText(123456789,1,Alignment::Left);
    display.putText(123456,1,Alignment::Center);
    display.putText(67890,2,Alignment::Right);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x0C, 0x04, 0x77, 0x18, 0x3F, 0x18, 0x8C, 0x18, 0xBB, 0x18, 0xFB, 0x18, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFB, 0x18, 0x0F, 0x00, 0xFF, 0x18, 0xBF, 0x18, 0xFF, 0x24,
    };
    CHECK( displayData == expected );
  }

  SECTION("Numbers (double)")
  {
    display.putText(1234.5678,1,Alignment::Left);
    display.putText(123.456,1,Alignment::Center);
    display.putText(67.890,2,Alignment::Right);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x0C, 0x04, 0x77, 0x18, 0x3F, 0x18, 0x8C, 0x18, 0xBB, 0x18, 0xFB, 0x18, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFB, 0x18, 0x0F, 0x00, 0xFF, 0x18, 0xBF, 0x18, 0xFF, 0x24,
    };
    CHECK( displayData == expected );
  }

}
//--------------------------------------------------------------------------------------------------

TEST_CASE("TextDisplayKompleteKontrol: set value", "[gfx][displays][TextDisplayKompleteKontrol]")
{
  TextDisplayKompleteKontrol display;

  {
    display.putValue(0.6f,0,Alignment::Right);
    std::vector<uint8_t> displayData(
      display.displayData(), display.displayData() + display.dataSize());

    std::vector<uint8_t> expected = {
      0x07, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    CHECK( displayData == expected );
  }
}
// clang-format on

//--------------------------------------------------------------------------------------------------

} // namespace test
} // namespace cabl
} // namespace sl