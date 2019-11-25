// METHDS
inline void Base::write(REGISTER address, uint8_t value)
{
	write_8bit(address, value);
}

inline uint8_t Base::read(REGISTER address)
{
	return read_8bit(address);
}
