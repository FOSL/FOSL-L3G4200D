#ifndef _FOSL_L3G4200D_BASE_HPP_
#define _FOSL_L3G4200D_BASE_HPP_

#include <FOSL/Utilities.hpp>
#include <FOSL/Math/Vector3.hpp>

#include "FOSL/L3G4200D/REGISTER.hpp"

namespace FOSL
{
	namespace L3G4200D
	{
		enum class SCALE : int8_t
		{
			DPS250,
			DPS500,
			DPS2000,
		};

		struct Specification
		{
			SCALE scale;
		};

		class Base
		{
			protected: // CONSTRUCTORS
				Base(void) = default;
			protected: // DESTRUCTOR
				virtual ~Base(void) = default;

			protected: // STATIC CONSTANTS
				static const uint8_t WHO_AM_I = 0b11010011;

			public: // VARIABLES
				Math::Vector3<int16_t> angular_rate;
			private:
				Specification specification;

			public: // SETTERS
				void set_scale(SCALE scale);

			public: // METHODS
				void initialize(Specification specification);

				bool is_connected(void);

				Math::Vector3<int16_t>& read_angular_rate(void);

				        void write     (REGISTER address, uint8_t value);
				virtual void write_8bit(REGISTER address, uint8_t value) = 0;

				        uint8_t read     (REGISTER address);
				virtual uint8_t read_8bit(REGISTER address) = 0;
		};

		#include "FOSL/L3G4200D/Base-impl.hpp"
	}
}

#endif
