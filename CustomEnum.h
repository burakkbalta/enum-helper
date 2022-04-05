#ifndef CUSTOM_ENUM_H
#define CUSTOM_ENUM_H

#include <type_traits> 

template<class TValue>
class CustomEnum final {
	typedef CustomEnum<TValue> ThisType;
public:
	static_assert(std::is_integral<TValue>::value, "Value type must be integral.");

	typedef TValue ValueType;

	constexpr CustomEnum(TValue value, const char* name) : m_value{value}, m_name{name}
	{
	}

	constexpr CustomEnum(const ThisType& orig) : m_value{orig.m_value}, m_name{orig.m_name}
	{
	}

	constexpr CustomEnum() {
	}

	constexpr operator TValue() const {
		return m_value;
	}

	constexpr bool operator==(const CustomEnum& rhs) const {
		return this->m_value == rhs.m_value;
	}

	constexpr TValue GetValue() const {
		return m_value;
	}

	constexpr const char* GetName() const {
		return m_name;
	}

private:
	TValue m_value{};
	const char* m_name{};

};

#endif /* CUSTOM_ENUM_H */