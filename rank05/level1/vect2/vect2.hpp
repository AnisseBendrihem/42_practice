#include <iostream>

class vect2
{
    private:
        int _x;
        int _y;
    public :
        vect2():_x(0), _y(0){}
        vect2(int x, int y) : _x(x), _y(y){}
        vect2(const vect2& copie) : vect2(copie._x, copie._y){}
        vect2& operator=(const vect2& copie)
        {
            if(this != &copie)
            {
                _x = copie._x;
                _y = copie._y;
            }
            return *this;
        }
        ~vect2(){}
        //-------------------------------------------------------
        int operator[](int index) const
        {
            if (index == 0)
                return (_x);
            return (_y);
        }
        int& operator[](int index)
        {
            if (index == 0)
                return (_x);
            return (_y);
        }
        //-------------------------------------------------------
        vect2& operator++()
        {
            _x += 1;
            _y += 1;
            return *this;
        }
        vect2 operator++(int)
        {
            vect2 tmp = *this;
            ++*this;
            return (tmp);
        }
        vect2& operator--()
        {
            _x -= 1;
            _y -= 1;
            return *this;
        }
        vect2 operator--(int)
        {
            vect2 tmp = *this;
            --*this;
            return (tmp);
        }
        //-----------------------------------------------------------
        vect2& operator +=(const vect2& obj)
        {
            _x += obj._x;
            _y +=obj._y;
            return *this;
        }
        vect2& operator -=(const vect2& obj)
        {
            _x -= obj._x;
            _y -=obj._y;
            return *this;
        }
        vect2& operator *=(const vect2& obj)
        {
            _x *= obj._x;
            _y *=obj._y;
            return *this;
        }
        vect2& operator *=(int num)
        {
            _x *= num;
            _y *= num;
            return *this;
        }
        //-------------------------------------------
        vect2 operator +(const vect2& obj) const 
        {
            vect2 tmp = *this;
            tmp+= obj;
            return (tmp);
        }
        vect2 operator -(const vect2& obj) const 
        {
            vect2 tmp = *this;
            tmp-= obj;
            return (tmp);
        }
        vect2 operator *(const vect2& obj) const 
        {
            vect2 tmp = *this;
            tmp*= obj;
            return (tmp);
        }
        vect2 operator *(int num) const 
        {
            vect2 tmp = *this;
            tmp*= num;
            return (tmp);
        }
        //------------------------------------------------
        vect2 operator-() const
        {
            return vect2(-this->_x, -this->_y);
        }
        //------------------------------------------------
        bool operator ==(const vect2& obj) const 
        {
            return (_x == obj._x && _y == obj._y);
        }
        bool operator !=(const vect2& obj) const 
        {
            return !(*this == obj);
        }
};

inline vect2 operator *(int num, const vect2& obj)
{
    return (obj * num);
}
inline std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
    os << "{" << obj[0] << ", " << obj[1] << "}";
    return os;
}

