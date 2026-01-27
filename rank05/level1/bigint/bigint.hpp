#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
	private:
		std::string str;

		static std::string reverse(const std::string& s)
		{
			std::string revStr;
			for(size_t i = s.length(); i > 0; i--)
			{
				revStr.push_back(s[i - 1]);
			}
			return(revStr);
		}

		static std::string addition(const bigint& obj1, const bigint& obj2)
		{
			std::string str1 = reverse(obj1.getStr());
			std::string str2 = reverse(obj2.getStr());
			std::string result;
			size_t len1 = str1.length();
			size_t len2 = str2.length();

			if(len1 > len2)
			{
				int diff = len1 - len2;
				while(diff > 0)
				{
					str2.push_back('0');
					diff--;
				}
			}
			else if(len2 > len1)
			{
				int diff = len2 - len1;
				while(diff > 0)
				{
					str1.push_back('0');
					diff--;
				}
			}

			int carry = 0;
			int digit1;
			int digit2;
			size_t len = str1.length();
			for(size_t i = 0; i < len; i++)
			{
				digit1 = str1[i] - '0';
				digit2 = str2[i] - '0';
				int res = digit1 + digit2 + carry;
				if(res > 9)
				{
					carry = res / 10;
					result.push_back((res % 10) + '0');
				}
				else
				{
					carry = 0;
					result.push_back(res + '0');
				}
			}
			if(carry != 0)
				result.push_back(carry + '0');
			return(reverse(result));
		}

		static unsigned int stringToUINT(std::string s)
		{
			std::stringstream ss(s);
			unsigned int res;
			ss >> res;
			return (res);
		}

	public:
		bigint()
		{
			this->str = "0";
		}

		bigint(unsigned int num)
		{
			std::stringstream ss;
			ss << num;
			this->str = ss.str();
		}

		bigint(const bigint& source)
		{
			(*this) = source;
		}

		std::string getStr() const
		{
			return(this->str);
		}

		bigint& operator=(const bigint& source)
		{
			if(this == &source)
				return(*this);
			this->str = source.str;
			return(*this);
		}

		bigint operator+(const bigint& other) const
		{
			bigint temp(other);
			temp.str.clear();
			std::string result = addition(*this, other);
			temp.str = result;
			return(temp);
		}

		bigint& operator+=(const bigint& other)
		{
			(*this) = (*this) + other;
			return(*this);
		}

		bigint& operator++()
		{
			*(this) = *(this) + bigint(1);
			return(*this);
		}

		bigint operator++(int)
		{
			bigint temp = (*this);
			*(this) = *(this) + bigint(1);
			return(temp);
		}

		bigint operator<<(unsigned int n) const
		{
			bigint temp = *this;
			temp.str.insert(temp.str.end(), n, '0');
			return(temp);
		}

		bigint operator>>(unsigned int n) const
		{
			bigint temp = *this;
			size_t len = temp.str.length();
			if(n >= len)
				temp.str = "0";
			else
			{
				temp.str.erase(temp.str.length() - n, n);
			}
			return(temp);
		}

		bigint& operator<<=(unsigned int n)
		{
			(*this) = (*this) << n;
			return(*this);
		}

		bigint& operator>>=(unsigned int n)
		{
			(*this) = (*this) >> n;
			return(*this);
		}

		bigint operator<<(const bigint& other) const
		{
			bigint temp;
			temp = (*this) << stringToUINT(other.str);
			return(temp);
		}

		bigint operator>>(const bigint& other) const
		{
			bigint temp;
			temp = (*this) >> stringToUINT(other.str);
			return(temp);
		}

		bigint& operator<<=(const bigint& other)
		{
			(*this) = (*this) << stringToUINT(other.str);
			return(*this);
		}

		bigint& operator>>=(const bigint& other)
		{
			(*this) = (*this) >> stringToUINT(other.str);
			return(*this);
		}

		bool operator==(const bigint& other) const
		{
			if(this->getStr() == other.getStr())
				return(true);
			return(false);
		}

		bool operator!=(const bigint& other) const
		{
			return(!((*this) == (other)));
		}

		bool operator<(const bigint& other) const
		{
			std::string str1 = this->str;
			std::string str2 = other.getStr();
			size_t len1 = str1.length();
			size_t len2 = str2.length();

			if(len1 != len2)
				return(len1 < len2);
			return(str1 < str2);
		}

		bool operator>(const bigint& other) const
		{
			return(!(((*this) < other)));
		}

		bool operator<=(const bigint& other) const
		{
			return((((*this) < other) || ((*this) == other)));
		}

		bool operator>=(const bigint& other) const
		{
			return((((*this) > other) || ((*this) == other)));
		}
};

inline std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}

