/**
 * @file Dcm.hpp
 *
 * A direction cosine matrix class.
 * All rotations and axis systems follow the right-hand rule.
 *
 * This library uses the convention that premultiplying a three dimensional
 * vector represented in coordinate system 1 will apply a rotation from coordinate system
 * 1 to coordinate system 2 to the vector.
 * Likewise, a matrix instance of this class also represents a coordinate transformation
 * from frame 2 to frame 1.
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include "math.hpp"

namespace matrix
{

template<typename Type>
class Quaternion;

template<typename Type>
class Euler;

template<typename Type>
class AxisAngle;

/**
 * Direction cosine matrix class
 *
 * The rotation between two coordinate frames is
 * described by this class.
 */
template<typename Type>
class Dcm : public SquareMatrix<Type, 3>
{
public:
    typedef Matrix<Type, 3, 1> Vector3;

    /**
     * Standard constructor
     *
     * Initializes to identity
     */
    Dcm()
    {
        (*this) = eye<Type, 3>();
    }

    /**
     * Constructor from array
     *
     * @param _data pointer to array
     */
    explicit Dcm(const Type data_[3][3]) : SquareMatrix<Type, 3>(data_)
    {
    }

    /**
     * Constructor from array
     *
     * @param _data pointer to array
     */
    explicit Dcm(const Type data_[9]) : SquareMatrix<Type, 3>(data_)
    {
    }

    /**
     * Copy constructor
     *
     * @param other Matrix33 to set dcm to
     */
    Dcm(const Matrix<Type, 3, 3> &other) : SquareMatrix<Type, 3>(other)
    {
    }

    /**
     * Constructor from quaternion
     *
     * Instance is initialized from quaternion representing
     * coordinate transformation from frame 2 to frame 1.
     *
     * @param q quaternion to set dcm to
     */
    Dcm(const Quaternion<Type> &q)
    {
        Dcm &dcm = *this;
        const Type a = q(0);
        const Type b = q(1);
        const Type c = q(2);
        const Type d = q(3);
        const Type aa = a * a;
        const Type ab = a * b;
        const Type ac = a * c;
        const Type ad = a * d;
        const Type bb = b * b;
        const Type bc = b * c;
        const Type bd = b * d;
        const Type cc = c * c;
        const Type cd = c * d;
        const Type dd = d * d;
        dcm(0, 0) = aa + bb - cc - dd;
        dcm(0, 1) = Type(2) * (bc - ad);
        dcm(0, 2) = Type(2) * (ac + bd);
        dcm(1, 0) = Type(2) * (bc + ad);
        dcm(1, 1) = aa - bb + cc - dd;
        dcm(1, 2) = Type(2) * (cd - ab);
        dcm(2, 0) = Type(2) * (bd - ac);
        dcm(2, 1) = Type(2) * (ab + cd);
        dcm(2, 2) = aa - bb - cc + dd;
    }

    /**
     * Constructor from euler angles
     *
     * This sets the transformation matrix from frame 2 to frame 1 where the rotation
     * from frame 1 to frame 2 is described by a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     *
     * @param euler euler angle instance
     */
    Dcm(const Euler<Type> &euler)
    {
        Dcm &dcm = *this;
        Type cosPhi = Type(cos(euler.phi()));
        Type sinPhi = Type(sin(euler.phi()));
        Type cosThe = Type(cos(euler.theta()));
        Type sinThe = Type(sin(euler.theta()));
        Type cosPsi = Type(cos(euler.psi()));
        Type sinPsi = Type(sin(euler.psi()));

        dcm(0, 0) = cosThe * cosPsi;
        dcm(0, 1) = -cosPhi * sinPsi + sinPhi * sinThe * cosPsi;
        dcm(0, 2) = sinPhi * sinPsi + cosPhi * sinThe * cosPsi;

        dcm(1, 0) = cosThe * sinPsi;
        dcm(1, 1) = cosPhi * cosPsi + sinPhi * sinThe * sinPsi;
        dcm(1, 2) = -sinPhi * cosPsi + cosPhi * sinThe * sinPsi;

        dcm(2, 0) = -sinThe;
        dcm(2, 1) = sinPhi * cosThe;
        dcm(2, 2) = cosPhi * cosThe;
    }


    /**
     * Constructor from axis angle
     *
     * This sets the transformation matrix from frame 2 to frame 1 where the rotation
     * from frame 1 to frame 2 is described by a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     *
     * @param euler euler angle instance
     */
    Dcm(const AxisAngle<Type> &aa)
    {
        Dcm &dcm = *this;
        dcm = Quaternion<Type>(aa);
    }

    Vector<Type, 3> vee() const      // inverse to Vector.hat() operation
    {
        const Dcm &A(*this);
        Vector<Type, 3> v;
        v(0) = -A(1, 2);
        v(1) =  A(0, 2);
        v(2) = -A(0, 1);
        return v;
    }

    void renormalize()
    {
        /* renormalize rows */
        for (size_t r = 0; r < 3; r++) {
            matrix::Vector3<Type> rvec(Matrix<Type,1,3>(this->Matrix<Type,3,3>::row(r)).transpose());
            this->Matrix<Type,3,3>::row(r) = rvec.normalized();
        }
    }
};

typedef Dcm<float> Dcmf;

} // namespace matrix

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
