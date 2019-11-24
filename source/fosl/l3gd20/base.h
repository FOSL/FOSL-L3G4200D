#ifndef _FOSL_L3GD20_BASE_H_
#define _FOSL_L3GD20_BASE_H_

#include <fosl/util.h>

#include "fosl/l3gd20/register.h"

namespace fosl
{
	namespace L3gd20
	{
		class Base
		{
			protected: // CONSTRUCTORS
				Base(void) = default;
			protected: // DESTRUCTOR
				~Base(void) = default;

			public: // METHODS
				void initialize(void);
				//
				        void write_register     (REGISTER address, uint8_t value);
				virtual void write_register_8bit(REGISTER address, uint8_t value) = 0;
				//
				        uint8_t read_register     (REGISTER address);
				virtual uint8_t read_register_8bit(REGISTER address) = 0;
		};

		#include "fosl/l3gd20/base-impl.h"
	}
}

#endif
