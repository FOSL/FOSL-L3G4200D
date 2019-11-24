#ifndef _FOSL_L3GD20_BASE_H_
#define _FOSL_L3GD20_BASE_H_

#include <fosl/util.h>

namespace fosl
{
	namespace L3gd20
	{
		class Base
		{
			public: // CONSTRUCTORS
				Base(void) = default;
			public: // DESTRUCTOR
				~Base(void) = default;

			public: // METHODS
				void initialize(void);
		};
	}
}

#endif
