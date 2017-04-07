#ifndef BITMASK_H
#define BITMASK_H

#include "Types.h"

template <typename BASE, uint32 SIZE>
struct Bitmask
{
private:
	BASE m_value;

public:
	Bitmask() : Bitmask(0) {}
	Bitmask(BASE aVal) : m_value(aVal) {}
	Bitmask(const Bitmask<BASE, SIZE>& aOther) : m_value(aOther.m_value) {}

	void SetAll() { m_value = ~static_cast<BASE>(0); }
	void ClearAll() { m_value = 0; }
	void CopyAll(const Bitmask<BASE, SIZE>& aFrom) { m_value = aFrom.m_value; }

	void Set(uint32 aBit) { if (aBit > 0 && aBit <= SIZE) m_value |= 1 << (aBit - 1); }
	void Clear(uint32 aBit) { if (aBit > 0 && aBit <= SIZE) m_value &= ~(1 << (aBit - 1)); }
	void SetOrClear(uint32 aBit, bool aSet) { aSet ? Set(aBit) : Clear(aBit); }
	void Copy(uint32 aBit, const Bitmask<BASE, SIZE>& aFrom) { SetOrClear(aBit, aFrom.IsSet(aBit)); }

	bool IsSet(uint32 aBit) const { if (aBit > 0 && aBit <= SIZE) return ((m_value & (1 << (aBit - 1))) != 0); return false; }
	BASE Intersect(const Bitmask<BASE, SIZE>& aOther) const { return (m_value & aOther.m_value); }

	BASE GetValue() const { return m_value; }
};

typedef Bitmask<byte, 8> Bitmask8;
typedef Bitmask<uint16, 16> Bitmask16;
typedef Bitmask<uint32, 32> Bitmask32;
typedef Bitmask<uint64, 64> Bitmask64;

#endif
