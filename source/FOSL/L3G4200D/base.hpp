#ifndef _FOSL_L3G4200D_BASE_HPP_
#define _FOSL_L3G4200D_BASE_HPP_

#include <FOSL/utility.hpp>
#include <FOSL/math/vector3.hpp>

#include "FOSL/L3G4200D/REGISTER.hpp"

namespace FOSL
{
	namespace L3G4200D
	{
		enum class SCALE : u8
		{
			DPS250,
			DPS500,
			DPS2000,
		};

		struct specification
		{
			SCALE scale;
		};

		class base
		{
			protected: // CONSTRUCTORS
				base(void) = default;
			protected: // DESTRUCTOR
				virtual ~base(void) = default;

			protected: // STATIC CONSTANTS
				static const u8 WHO_AM_I = 0b11010011;

			public: // VARIABLES
				math::vector3<s16> angular_rate;
			private:
				struct specification specification;

			public: // SETTERS
				void set_scale(enum SCALE scale);

			public: // METHODS
				void initialize(struct specification specification);

				bool is_connected(void);

				math::vector3<s16> &read_angular_rate(void);

				        void write     (enum REGISTER address, u8 value);
				virtual void write_8bit(enum REGISTER address, u8 value) = 0;

				        u8 read     (enum REGISTER address);
				virtual u8 read_8bit(enum REGISTER address) = 0;
		};

		#include "FOSL/L3G4200D/base-impl.hpp"
	}
}

#endif
