/*
        ##########    Copyright (C) 2015 Vincenzo Pacella
        ##      ##    Distributed under MIT license, see file LICENSE
        ##      ##    or <http://opensource.org/licenses/MIT>
        ##      ##
##########      ############################################################# shaduzlabs.com #####*/

#include <catch.hpp>
#include <gfx/displays/LCDDisplayKompleteKontrol.h>

//--------------------------------------------------------------------------------------------------

namespace sl
{
namespace cabl
{
namespace test
{

//--------------------------------------------------------------------------------------------------

TEST_CASE("LCDDisplayKompleteKontrol: constructor", "[gfx][displays][LCDDisplayKompleteKontrol]")
{
  LCDDisplayKompleteKontrol display;
  CHECK(display.width() == 8);
  CHECK(display.height() == 3);
}

//--------------------------------------------------------------------------------------------------

// clang-format off
TEST_CASE("LCDDisplayKompleteKontrol: set text", "[gfx][displays][LCDDisplayKompleteKontrol]")
{
  LCDDisplayKompleteKontrol display;

  SECTION("Write text to first row")
  {
    display.text("@A text@+!ˆ&",0,LCDDisplay::Align::Center);
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
    display.text("@A text@+!ˆ&",1,LCDDisplay::Align::Center);
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
    display.text("@A text@+!ˆ&",2,LCDDisplay::Align::Center);
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
    display.text("text",0,LCDDisplay::Align::Center);
    display.text("text",1,LCDDisplay::Align::Right);
    display.text("text",2,LCDDisplay::Align::Left);
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
    display.text("text",0,LCDDisplay::Align::Left);
    display.text("text",1,LCDDisplay::Align::Center);
    display.text("text",2,LCDDisplay::Align::Right);
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
    display.text(123456789,1,LCDDisplay::Align::Left);
    display.text(123456,1,LCDDisplay::Align::Center);
    display.text(67890,2,LCDDisplay::Align::Right);
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
    display.text(1234.5678,1,LCDDisplay::Align::Left);
    display.text(123.456,1,LCDDisplay::Align::Center);
    display.text(67.890,2,LCDDisplay::Align::Right);
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

TEST_CASE("LCDDisplayKompleteKontrol: set value", "[gfx][displays][LCDDisplayKompleteKontrol]")
{
  LCDDisplayKompleteKontrol display;

  {
    display.value(0.6f,0,LCDDisplay::Align::Right);
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
