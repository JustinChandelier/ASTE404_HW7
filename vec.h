// vec.h

#ifndef _VEC_H
#define _VEC_H

#include <ostream>
#include <math.h>

template<typename T>

class _vec3 { // generic 3D vector of type T

public:
    _vec3<T>() : d{0,0,0} {} //!< Initialize all values of vector to 0

    /**
     * 
     *  \param a,b,c
     *  \parblock The value you wish to assign to the a, b, or c indices \endparblock
     * 
     *  \return \f$ \overrightarrow{d}=[a,b,c]\f$
     *  \parblock A 3D vector with the values a, b, and c \endparblock
     */
    _vec3<T>(T a, T b, T c) : d{a,b,c} {} 

    T& operator[] (int i) {return d[i];}
    T operator[] (int i) const {return d[i];}

    /**
    *    \param a 
    *   \parblock A 3D vector \endparblock
    *   \param b 
    *   \parblock A 3D vector \endparblock
    *
    *   \return \f$ \overrightarrow{a}+\overrightarrow{b} =  \overrightarrow{a}[i]+\overrightarrow{b}[i]\f$
    *   \parblock Vector addition; \f$i\f$ is the index of each vector (\f$ i\in[0,2] \f$)
    */
    friend _vec3<T> operator+(const _vec3<T>&a, const _vec3<T>&b) {
    return _vec3<T>(a[0]+b[0],a[1]+b[1],a[2]+b[2]);
    }

    /**
    *    \param a 
    *   \parblock A 3D vector \endparblock
    *   \param b 
    *   \parblock A 3D vector \endparblock
    *
    *   \return \f$ \overrightarrow{a}-\overrightarrow{b} =  \overrightarrow{a}[i]-\overrightarrow{b}[i]\f$
    *   \parblock Vector subtraction; \f$i\f$ is the index of each vector (\f$ i\in[0,2] \f$)
    */
    friend _vec3<T> operator-(const _vec3<T>&a, const _vec3<T>&b) {
    return _vec3<T>(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
    }

    /**
    *    \param a 
    *   \parblock A 3D vector \endparblock
    *   \param b 
    *   \parblock A 3D vector \endparblock
    *
    *   \return \f$ \overrightarrow{a}\cdot\overrightarrow{b} =  (\overrightarrow{a}[0]*\overrightarrow{b}[0]) + 
    *   (\overrightarrow{a}[1]*\overrightarrow{b}[1]) + (\overrightarrow{a}[2]*\overrightarrow{b}[2])\f$
    *   \parblock Dot product of two vectors; \f$n\f$ is the final index of each vector \endparblock
    */
    friend T dot(const _vec3<T>&a, const _vec3<T>&b) {
    return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    }


    /**
    *    \param a 
    *   \parblock A 3D vector \endparblock
    *
    *   \return \f$ \sqrt{\overrightarrow{a}\cdot\overrightarrow{a}} =  
    *   \sqrt{(\overrightarrow{a}[0]*\overrightarrow{a}[0]) + (\overrightarrow{a}[1]*\overrightarrow{a}[1]) + 
    *   (\overrightarrow{a}[2]*\overrightarrow{a}[2])}\f$
    *   \parblock Squaring of a vector \endparblock
    */
    friend double mag(const _vec3<T>&a) {return sqrt(dot(a,a));}

    friend std::ostream& operator<<(std::ostream &out, const _vec3<T>&a) {
    out<<a[0]<<" "<<a[1]<<" "<<a[2]; return out;
    }

protected:
T d[3]; //!< Ensures the data stored in d[3] cannot be edited outside of these functions

};
using double3 = _vec3<double>; // assign a nickname

#endif