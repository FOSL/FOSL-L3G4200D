inline void Base::write_register(REGISTER address, uint8_t value)
{
	write_register_8bit(address, value);
}
//
inline uint8_t Base::read_register(REGISTER address)
{
	return read_register_8bit(address);
}
