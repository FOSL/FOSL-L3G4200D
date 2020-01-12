// METHDS
inline void base::write(enum REGISTER address, u8 value)
{
	write_8bit(address, value);
}

inline uint8_t base::read(enum REGISTER address)
{
	return read_8bit(address);
}
