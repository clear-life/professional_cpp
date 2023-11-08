export module spreadsheet_cell;

import <string>;
import <string_view>;
import <compare>;
import <iostream>;

export class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(std::string_view initialValue);

	void set(double value);
	void set(std::string_view value);

	inline double getValue() const { return m_value; }
	inline std::string getString() const { return doubleToString(m_value); }

	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
	
	[[nodiscard]] auto operator<=>(const SpreadsheetCell&) const = default;
	
	SpreadsheetCell operator-() const;
	SpreadsheetCell& operator++();   // prefix
	SpreadsheetCell operator++(int); // postfix
	SpreadsheetCell& operator--();   // prefix 
	SpreadsheetCell operator--(int); // postfix

private:
	double m_value{ 0 };
};

export SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export std::ostream& operator<<(std::ostream& ostr, const SpreadsheetCell& cell);
export std::istream& operator>>(std::istream& istr, SpreadsheetCell& cell);
