/**
 * @file Quaternion.hpp
 *
 * All rotations and axis systems follow the right-hand rule.
 * The Hamilton quaternion convention including its product definition is used.
 *
 * In order to rotate a vector in frame b (v_b) to frame n by a righthand
 * rotation defined by the quaternion q_nb (from frame b to n)
 * one can use the following operation:
 * v_n = q_nb * [0;v_b] * q_nb^(-1)
 *
 * Just like DCM's: v_n = C_nb * v_b (vector rotation)
 * M_n = C_nb * M_b * C_nb^(-1) (matrix rotation)
 *
 * or similarly the reverse operation
 * v_b = q_nb^(-1) * [0;v_n] * q_nb
 *
 * where q_nb^(-1) represents the inverse of the quaternion q_nb^(-1) = q_bn
 *
 * The product z of two quaternions z = q2 * q1 represents an intrinsic rotation
 * in the order of first q1 followed by q2.
 * The first element of the quaternion
 * represents the real part, thus, a quaternion representing a zero-rotation
 * is defined as (1,0,0,0).
 *
 * @author James Goppert <james.goppert@gmail.com>
 */

#pragma once

#include "math.hpp"

namespace matrix
{

template <typename Type>
class Dcm;

template <typename Type>
class Euler;

template <typename Type>
class AxisAngle;


/**
 * Quaternion class
 *
 * The rotation between two coordinate frames is
 * described by this class.
 */
template<typename Type>
class Quaternion : public Vector<Type, 4>
{
public:
    typedef Matrix<Type, 4, 1> Matrix41;
    typedef Matrix<Type, 3, 1> Matrix31;

    /**
     * Constructor from array
     *
     * @param data_ array
     */
    explicit Quaternion(const Type data_[4]) :
        Vector<Type, 4>(data_)
    {
    }

    /**
     * Standard constructor
     */
    Quaternion()
    {
        Quaternion &q = *this;
        q(0) = 1;
        q(1) = 0;
        q(2) = 0;
        q(3) = 0;
    }

    /**
     * Constructor from Matrix41
     *
     * @param other Matrix41 to copy
     */
    Quaternion(const Matrix41 &other) :
        Vector<Type, 4>(other)
    {
    }

    /**
     * Constructor from dcm
     *
     * Instance is initialized from a dcm representing coordinate transformation
     * from frame 2 to frame 1.
     *
     * @param dcm dcm to set quaternion to
     */
    Quaternion(const Dcm<Type> &R)
    {
        Quaternion &q = *this;
        Type t = R.trace();
        if (t > Type(0)) {
            t = sqrt(Type(1) + t);
            q(0) = Type(0.5) * t;
            t = Type(0.5) / t;
            q(1) = (R(2,1) - R(1,2)) * t;
            q(2) = (R(0,2) - R(2,0)) * t;
            q(3) = (R(1,0) - R(0,1)) * t;
        } else if (R(0,0) > R(1,1) && R(0,0) > R(2,2)) {
            t = sqrt(Type(1) + R(0,0) - R(1,1) - R(2,2));
            q(1) = Type(0.5) * t;
            t = Type(0.5) / t;
            q(0) = (R(2,1) - R(1,2)) * t;
            q(2) = (R(1,0) + R(0,1)) * t;
            q(3) = (R(0,2) + R(2,0)) * t;
        } else if (R(1,1) > R(2,2)) {
            t = sqrt(Type(1) - R(0,0) + R(1,1) - R(2,2));
            q(2) = Type(0.5) * t;
            t = Type(0.5) / t;
            q(0) = (R(0,2) - R(2,0)) * t;
            q(1) = (R(1,0) + R(0,1)) * t;
            q(3) = (R(2,1) + R(1,2)) * t;
        } else {
            t = sqrt(Type(1) - R(0,0) - R(1,1) + R(2,2));
            q(3) = Type(0.5) * t;
            t = Type(0.5) / t;
            q(0) = (R(1,0) - R(0,1)) * t;
            q(1) = (R(0,2) + R(2,0)) * t;
            q(2) = (R(2,1) + R(1,2)) * t;
        }
    }

    /**
     * Constructor from euler angles
     *
     * This sets the instance to a quaternion representing coordinate transformation from
     * frame 2 to frame 1 where the rotation from frame 1 to frame 2 is described
     * by a 3-2-1 intrinsic Tait-Bryan rotation sequence.
     *
     * @param euler euler angle instance
     */
    Quaternion(const Euler<Type> &euler)
    {
        Quaternion &q = *this;
        Type cosPhi_2 = Type(cos(euler.phi() / Type(2)));
        Type cosTheta_2 = Type(cos(euler.theta() / Type(2)));
        Type cosPsi_2 = Type(cos(euler.psi() / Type(2)));
        Type sinPhi_2 = Type(sin(euler.phi() / Type(2)));
        Type sinTheta_2 = Type(sin(euler.theta() / Type(2)));
        Type sinPsi_2 = Type(sin(euler.psi() / Type(2)));
        q(0) = cosPhi_2 * cosTheta_2 * cosPsi_2 +
               sinPhi_2 * sinTheta_2 * sinPsi_2;
        q(1) = sinPhi_2 * cosTheta_2 * cosPsi_2 -
               cosPhi_2 * sinTheta_2 * sinPsi_2;
        q(2) = cosPhi_2 * sinTheta_2 * cosPsi_2 +
               sinPhi_2 * cosTheta_2 * sinPsi_2;
        q(3) = cosPhi_2 * cosTheta_2 * sinPsi_2 -
               sinPhi_2 * sinTheta_2 * cosPsi_2;
    }

    /**
     * Quaternion from AxisAngle
     *
     * @param aa axis-angle vector
     */
    Quaternion(const AxisAngle<Type> &aa)
    {
        Quaternion &q = *this;
        Type angle = aa.norm();
        Vector<Type, 3> axis = aa.unit();
        if (angle < Type(1e-10)) {
            q(0) = Type(1);
            q(1) = q(2) = q(3) = 0;
        } else {
            Type magnitude = sin(angle / Type(2));
            q(0) = cos(angle / Type(2));
            q(1) = axis(0) * magnitude;
            q(2) = axis(1) * magnitude;
            q(3) = axis(2) * magnitude;
        }
    }

    /**
     * Quaternion from two vectors
     * Generates shortest rotation from source to destination vector
     *
     * @param dst destination vector (no need to normalize)
     * @param src source vector (no need to normalize)
     * @param eps epsilon threshold which decides if a value is considered zero
     */
    Quaternion(const Vector3<Type> &src, const Vector3<Type> &dst, const Type eps = Type(1e-5))
    {
        Quaternion &q = *this;
        Vector3<Type> cr = src.cross(dst);
        const float dt = src.dot(dst);
        if (cr.norm() < eps && dt < 0) {
            // handle corner cases with 180 degree rotations
            // if the two vectors are parallel, cross product is zero
            // if they point opposite, the dot product is negative
            cr = src.abs();
            if (cr(0) < cr(1)) {
                if (cr(0) < cr(2)) {
                    cr = Vector3<Type>(1, 0, 0);
                } else {
                    cr = Vector3<Type>(0, 0, 1);
                }
            } else {
                if (cr(1) < cr(2)) {
                    cr = Vector3<Type>(0, 1, 0);
                } else {
                    cr = Vector3<Type>(0, 0, 1);
                }
            }
            q(0) = Type(0);
            cr = src.cross(cr);
        } else {
            // normal case, do half-way quaternion solution
            q(0) = dt + sqrt(src.norm_squared() * dst.norm_squared());
        }
        q(1) = cr(0);
        q(2) = cr(1);
        q(3) = cr(2);
        q.normalize();
    }

    /**
     * Constructor from quaternion values
     *
     * Instance is initialized from quaternion values representing coordinate
     * transformation from frame 2 to frame 1.
     * A zero-rotation quaternion is represented by (1,0,0,0).
     *
     * @param a set quaternion value 0
     * @param b set quaternion value 1
     * @param c set quaternion value 2
     * @param d set quaternion value 3
     */
    Quaternion(Type a, Type b, Type c, Type d)
    {
        Quaternion &q = *this;
        q(0) = a;
        q(1) = b;
        q(2) = c;
        q(3) = d;
    }

    /**
     * Quaternion multiplication operator
     *
     * @param q quaternion to multiply with
     * @return product
     */
    Quaternion operator*(const Quaternion &p) const
    {
        const Quaternion &q = *this;
        return {
            q(0) * p(0) - q(1) * p(1) - q(2) * p(2) - q(3) * p(3),
            q(1) * p(0) + q(0) * p(1) - q(3) * p(2) + q(2) * p(3),
            q(2) * p(0) + q(3) * p(1) + q(0) * p(2) - q(1) * p(3),
            q(3) * p(0) - q(2) * p(1) + q(1) * p(2) + q(0) * p(3) };
    }

    /**
     * Self-multiplication operator
     *
     * @param other quaternion to multiply with
     */
    void operator*=(const Quaternion &other)
    {
        Quaternion &self = *this;
        self = self * other;
    }

    /**
     * Scalar multiplication operator
     *
     * @param scalar scalar to multiply with
     * @return product
     */
    Quaternion operator*(Type scalar) const
    {
        const Quaternion &q = *this;
        return scalar * q;
    }

    /**
     * Scalar self-multiplication operator
     *
     * @param scalar scalar to multiply with
     */
    void operator*=(Type scalar)
    {
        Quaternion &q = *this;
        q = q * scalar;
    }

    /**
     * Computes the derivative of q_21 when
     * rotated with angular velocity expressed in frame 1
     * v_2 = q_21 * v_1 * q_21^-1
     * d/dt q_21 = 0.5 * q_21 * omega_2
     *
     * @param w angular rate in frame 1 (typically body frame)
     */
    Matrix41 derivative1(const Matrix31 &w) const
    {
        const Quaternion &q = *this;
        Quaternion<Type> v(0, w(0, 0), w(1, 0), w(2, 0));
        return q * v  * Type(0.5);
    }

    /**
     * Computes the derivative of q_21 when
     * rotated with angular velocity expressed in frame 2
     * v_2 = q_21 * v_1 * q_21^-1
     * d/dt q_21 = 0.5 * omega_1 * q_21
     *
     * @param w angular rate in frame 2 (typically reference frame)
     */
    Matrix41 derivative2(const Matrix31 &w) const
    {
        const Quaternion &q = *this;
        Quaternion<Type> v(0, w(0, 0), w(1, 0), w(2, 0));
        return v * q  * Type(0.5);
    }

    /**
     * Invert quaternion in place
     */
    void invert()
    {
        *this = this->inversed();
    }

    /**
     * Invert quaternion
     *
     * @return inverted quaternion
     */
    Quaternion inversed() const
    {
        const Quaternion &q = *this;
        Type normSq = q.dot(q);
        return Quaternion(
                   q(0)/normSq,
                   -q(1)/normSq,
                   -q(2)/normSq,
                   -q(3)/normSq);
    }

    /**
     * Bring quaternion to canonical form
     */
    void canonicalize()
    {
        *this = this->canonical();
    }

    /**
     * Return canonical form of the quaternion
     *
     * @return quaternion in canonical from
     */
    Quaternion canonical() const
    {
        const Quaternion &q = *this;

        for (size_t i = 0; i < 4; i++) {
            if (fabs(q(i)) > FLT_EPSILON) {
                return q * Type(matrix::sign(q(i)));
            }
        }
        return q;
    }

    /**
     * Rotate quaternion from rotation vector
     *
     * @param vec rotation vector
     */
    void rotate(const AxisAngle<Type> &vec)
    {
        Quaternion res(vec);
        (*this) = res * (*this);
    }

    /**
     * Rotates vector v_1 in frame 1 to vector v_2 in frame 2
     * using the rotation quaternion q_21
     * describing the rotation from frame 1 to 2
     * v_2 = q_21 * v_1 * q_21^-1
     *
     * @param vec vector to rotate in frame 1 (typically body frame)
     * @return rotated vector in frame 2 (typically reference frame)
     */
    Vector3<Type> conjugate(const Vector3<Type> &vec) const {
        const Quaternion& q = *this;
        Quaternion v(Type(0), vec(0), vec(1), vec(2));
        Quaternion res = q*v*q.inversed();
        return Vector3<Type>(res(1), res(2), res(3));
    }

    /**
     * Rotates vector v_2 in frame 2 to vector v_1 in frame 1
     * using the rotation quaternion q_21
     * describing the rotation from frame 1 to 2
     * v_1 = q_21^-1 * v_2 * q_21
     *
     * @param vec vector to rotate in frame 2 (typically reference frame)
     * @return rotated vector in frame 1 (typically body frame)
     */
    Vector3<Type> conjugate_inversed(const Vector3<Type> &vec) const
    {
        const Quaternion& q = *this;
        Quaternion v(Type(0), vec(0), vec(1), vec(2));
        Quaternion res = q.inversed()*v*q;
        return Vector3<Type>(res(1), res(2), res(3));
    }

    /**
     * Imaginary components of quaternion
     */
    Vector3<Type> imag() const
    {
        const Quaternion &q = *this;
        return Vector3<Type>(q(1), q(2), q(3));
    }

    /**
     * Corresponding body z-axis to an attitude quaternion /
     * last orthogonal unit basis vector
     *
     * == last column of the equivalent rotation matrix
     * but calculated more efficiently than a full conversion
     */
    Vector3<Type> dcm_z() const
    {
        const Quaternion &q = *this;
        Vector3<Type> R_z;
        const Type a = q(0);
        const Type b = q(1);
        const Type c = q(2);
        const Type d = q(3);
        R_z(0) = 2 * (a * c + b * d);
        R_z(1) = 2 * (c * d - a * b);
        R_z(2) = a * a - b * b - c * c + d * d;
        return R_z;
    }
};

typedef Quaternion<float> Quatf;
typedef Quaternion<float> Quaternionf;

} // namespace matrix

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
