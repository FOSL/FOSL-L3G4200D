#ifndef _FOSL_L3GD20_SPI_BASE_H_
#define _FOSL_L3GD20_SPI_BASE_H_

#include "fosl/l3gd20/base.h"

namespace fosl
{
	namespace L3gd20
	{
		namespace Spi
		{
			class Base : public L3gd20::Base
			{
				protected: // CONSTRUCTORS
					Base(void) = default;
				protected: // DESTRUCTOR
					~Base(void) = default;

				public: // METHODS
					virtual void write_register_8bit(REGISTER address, uint8_t value) = 0;
					//
					virtual uint8_t read_register_8bit(REGISTER address) = 0;
					//
					virtual void chip_select(bool select) = 0;
			};
		}
	}
}

#endif
