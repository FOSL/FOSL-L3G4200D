#include "FOSL/L3G4200D/base.hpp"

namespace FOSL
{
	namespace L3G4200D
	{
		// SETTERS
		void base::set_scale(enum SCALE scale)
		{
			specification.scale = scale;

			switch(scale)
			{
				case SCALE::DPS250:  write(REGISTER::CTRL_REG4, 0b00000000); break;
				case SCALE::DPS500:  write(REGISTER::CTRL_REG4, 0b00010000); break;
				case SCALE::DPS2000: write(REGISTER::CTRL_REG4, 0b00100000); break;
			}
		}

		// METHODS
		void base::initialize(struct specification specification)
		{
			// REFER TO DATASHEET!

			this->specification = specification;

			write(REGISTER::CTRL_REG1, 0b00001111); // ENABLE XYZ AXIS AND POWER UP

			set_scale(specification.scale);

			write(REGISTER::CTRL_REG2, 0b00000000); // HIGH-PASS FILTER SETTINGS
			write(REGISTER::CTRL_REG5, 0b00010000); // ENABLE HIGH-PASS FILTER
		}

		bool base::is_connected(void)
		{
			return read(REGISTER::WHO_AM_I) == WHO_AM_I;
		}

		math::vector3<s16> &base::read_angular_rate(void)
		{
			angular_rate.x  = read(REGISTER::OUT_X_L) & 0xFF;
			angular_rate.x |= read(REGISTER::OUT_X_H) << 8  ;
			angular_rate.y  = read(REGISTER::OUT_Y_L) & 0xFF;
			angular_rate.y |= read(REGISTER::OUT_Y_H) << 8  ;
			angular_rate.z  = read(REGISTER::OUT_Z_L) & 0xFF;
			angular_rate.z |= read(REGISTER::OUT_Z_H) << 8  ;

			float scaler;
			switch(specification.scale)
			{
				case SCALE::DPS250:  scaler =  8.75 / 1000.0; break;
				case SCALE::DPS500:  scaler = 17.50 / 1000.0; break;
				case SCALE::DPS2000: scaler = 70.00 / 1000.0; break;
			}

			angular_rate.x *= scaler;
			angular_rate.y *= scaler;
			angular_rate.z *= scaler;

			return angular_rate;
		}
	}
}
