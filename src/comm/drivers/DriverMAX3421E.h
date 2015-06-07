/*----------------------------------------------------------------------------------------------------------------------

                 %%%%%%%%%%%%%%%%%                
                 %%%%%%%%%%%%%%%%%
                 %%%           %%%
                 %%%           %%%
                 %%%           %%%
%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% www.shaduzlabs.com %%%%%

------------------------------------------------------------------------------------------------------------------------

  Copyright (C) 2014 Vincenzo Pacella

  This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
  License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later
  version.

  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along with this program.  
  If not, see <http://www.gnu.org/licenses/>.

----------------------------------------------------------------------------------------------------------------------*/
#pragma once

#include "comm/DriverImpl.h"

namespace sl
{

class DriverMAX3421E : public DriverImpl
{
public:

  DriverMAX3421E();
  ~DriverMAX3421E() override;
  
  bool connect( Driver::tVendorId vid_, Driver::tProductId pid_ ) override;
  void disconnect() override;

  bool read( Transfer&, uint8_t ) override;
  bool write( const Transfer&, uint8_t ) const override;
  
private:
  
  tRawData           m_inputBuffer;
  
  static uint32_t    s_numPacketR;
  static uint32_t    s_numPacketW;

};
  
//----------------------------------------------------------------------------------------------------------------------

} // sl