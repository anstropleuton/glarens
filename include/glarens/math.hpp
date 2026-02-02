// Glarens - GUI Framework.
//
// SDL-compatible math types.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "SDL3/SDL_rect.h"
#include "glarens/property.hpp"
#include <array>
#include <cmath>
#include <concepts>
#include <cstdint>
#include <cstdlib>

struct Vec2;
struct Vec3;
struct Vec4;

struct Vec2 {
    float x;
    float y;

    Vec2() = default;
    Vec2(float xy) : x(xy), y(xy) {}
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2(SDL_FPoint v) : x(v.x), y(v.y) {}

    inline explicit Vec2(Vec3 v);
    inline explicit Vec2(Vec4 v);

    operator SDL_FPoint() const { return {x, y}; }

    inline Vec2 &operator+=(Vec2 b);
    inline Vec2 &operator-=(Vec2 b);
    inline Vec2 &operator*=(Vec2 b);
    inline Vec2 &operator/=(Vec2 b);
    inline Vec2 &operator+=(SDL_FPoint b);
    inline Vec2 &operator-=(SDL_FPoint b);
    inline Vec2 &operator*=(SDL_FPoint b);
    inline Vec2 &operator/=(SDL_FPoint b);
    inline Vec2 &operator+=(float b);
    inline Vec2 &operator-=(float b);
    inline Vec2 &operator*=(float b);
    inline Vec2 &operator/=(float b);

    MemPropROExpDecl(Vec2, xx, Vec2);
    MemPropROExpDecl(Vec2, xy, Vec2);
    MemPropROExpDecl(Vec2, yx, Vec2);
    MemPropROExpDecl(Vec2, yy, Vec2);

    MemPropROExpDecl(Vec2, xxx, Vec3);
    MemPropROExpDecl(Vec2, xxy, Vec3);
    MemPropROExpDecl(Vec2, xyx, Vec3);
    MemPropROExpDecl(Vec2, xyy, Vec3);
    MemPropROExpDecl(Vec2, yxx, Vec3);
    MemPropROExpDecl(Vec2, yxy, Vec3);
    MemPropROExpDecl(Vec2, yyx, Vec3);
    MemPropROExpDecl(Vec2, yyy, Vec3);

    MemPropROExpDecl(Vec2, xxxx, Vec4);
    MemPropROExpDecl(Vec2, xxxy, Vec4);
    MemPropROExpDecl(Vec2, xxyx, Vec4);
    MemPropROExpDecl(Vec2, xxyy, Vec4);
    MemPropROExpDecl(Vec2, xyxx, Vec4);
    MemPropROExpDecl(Vec2, xyxy, Vec4);
    MemPropROExpDecl(Vec2, xyyx, Vec4);
    MemPropROExpDecl(Vec2, xyyy, Vec4);
    MemPropROExpDecl(Vec2, yxxx, Vec4);
    MemPropROExpDecl(Vec2, yxxy, Vec4);
    MemPropROExpDecl(Vec2, yxyx, Vec4);
    MemPropROExpDecl(Vec2, yxyy, Vec4);
    MemPropROExpDecl(Vec2, yyxx, Vec4);
    MemPropROExpDecl(Vec2, yyxy, Vec4);
    MemPropROExpDecl(Vec2, yyyx, Vec4);
    MemPropROExpDecl(Vec2, yyyy, Vec4);
};

inline Vec2 operator+(Vec2 a) { return Vec2(+a.x, +a.y); }
inline Vec2 operator-(Vec2 a) { return Vec2(-a.x, -a.y); }

inline Vec2 operator+(Vec2 a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
inline Vec2 operator-(Vec2 a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }
inline Vec2 operator*(Vec2 a, Vec2 b) { return {a.x * b.x, a.y * b.y}; }
inline Vec2 operator/(Vec2 a, Vec2 b) { return {a.x / b.x, a.y / b.y}; }
inline Vec2 operator+(Vec2 a, SDL_FPoint b) { return {a.x + b.x, a.y + b.y}; }
inline Vec2 operator-(Vec2 a, SDL_FPoint b) { return {a.x - b.x, a.y - b.y}; }
inline Vec2 operator*(Vec2 a, SDL_FPoint b) { return {a.x * b.x, a.y * b.y}; }
inline Vec2 operator/(Vec2 a, SDL_FPoint b) { return {a.x / b.x, a.y / b.y}; }
inline Vec2 operator+(SDL_FPoint a, Vec2 b) { return {a.x + b.x, a.y + b.y}; }
inline Vec2 operator-(SDL_FPoint a, Vec2 b) { return {a.x - b.x, a.y - b.y}; }
inline Vec2 operator*(SDL_FPoint a, Vec2 b) { return {a.x * b.x, a.y * b.y}; }
inline Vec2 operator/(SDL_FPoint a, Vec2 b) { return {a.x / b.x, a.y / b.y}; }
inline Vec2 operator+(Vec2 a, float b) { return {a.x + b, a.y + b}; }
inline Vec2 operator-(Vec2 a, float b) { return {a.x - b, a.y - b}; }
inline Vec2 operator*(Vec2 a, float b) { return {a.x * b, a.y * b}; }
inline Vec2 operator/(Vec2 a, float b) { return {a.x / b, a.y / b}; }
inline Vec2 operator+(float a, Vec2 b) { return {a + b.x, a + b.y}; }
inline Vec2 operator-(float a, Vec2 b) { return {a - b.x, a - b.y}; }
inline Vec2 operator*(float a, Vec2 b) { return {a * b.x, a * b.y}; }
inline Vec2 operator/(float a, Vec2 b) { return {a / b.x, a / b.y}; }

inline Vec2 &Vec2::operator+=(Vec2 b) { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(Vec2 b) { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(Vec2 b) { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(Vec2 b) { return *this = *this / b; }
inline Vec2 &Vec2::operator+=(SDL_FPoint b) { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(SDL_FPoint b) { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(SDL_FPoint b) { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(SDL_FPoint b) { return *this = *this / b; }
inline Vec2 &Vec2::operator+=(float b) { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(float b) { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(float b) { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(float b) { return *this = *this / b; }

struct Vec3 {
    float x;
    float y;
    float z;

    Vec3() = default;
    Vec3(float xyz) : x(xyz), y(xyz), z(xyz) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3(Vec2 v, float z) : x(v.x), y(v.y), z(z) {}
    Vec3(float x, Vec2 v) : x(x), y(v.x), z(v.y) {}

    inline explicit Vec3(Vec2 v);
    inline explicit Vec3(Vec4 v);

    inline Vec3 &operator+=(Vec3 b);
    inline Vec3 &operator-=(Vec3 b);
    inline Vec3 &operator*=(Vec3 b);
    inline Vec3 &operator/=(Vec3 b);
    inline Vec3 &operator+=(float b);
    inline Vec3 &operator-=(float b);
    inline Vec3 &operator*=(float b);
    inline Vec3 &operator/=(float b);

    MemPropROExpDecl(Vec3, xx, Vec2);
    MemPropROExpDecl(Vec3, xy, Vec2);
    MemPropROExpDecl(Vec3, xz, Vec2);
    MemPropROExpDecl(Vec3, yx, Vec2);
    MemPropROExpDecl(Vec3, yy, Vec2);
    MemPropROExpDecl(Vec3, yz, Vec2);
    MemPropROExpDecl(Vec3, zx, Vec2);
    MemPropROExpDecl(Vec3, zy, Vec2);
    MemPropROExpDecl(Vec3, zz, Vec2);

    MemPropROExpDecl(Vec3, xxx, Vec3);
    MemPropROExpDecl(Vec3, xxy, Vec3);
    MemPropROExpDecl(Vec3, xxz, Vec3);
    MemPropROExpDecl(Vec3, xyx, Vec3);
    MemPropROExpDecl(Vec3, xyy, Vec3);
    MemPropROExpDecl(Vec3, xyz, Vec3);
    MemPropROExpDecl(Vec3, xzx, Vec3);
    MemPropROExpDecl(Vec3, xzy, Vec3);
    MemPropROExpDecl(Vec3, xzz, Vec3);
    MemPropROExpDecl(Vec3, yxx, Vec3);
    MemPropROExpDecl(Vec3, yxy, Vec3);
    MemPropROExpDecl(Vec3, yxz, Vec3);
    MemPropROExpDecl(Vec3, yyx, Vec3);
    MemPropROExpDecl(Vec3, yyy, Vec3);
    MemPropROExpDecl(Vec3, yyz, Vec3);
    MemPropROExpDecl(Vec3, yzx, Vec3);
    MemPropROExpDecl(Vec3, yzy, Vec3);
    MemPropROExpDecl(Vec3, yzz, Vec3);
    MemPropROExpDecl(Vec3, zxx, Vec3);
    MemPropROExpDecl(Vec3, zxy, Vec3);
    MemPropROExpDecl(Vec3, zxz, Vec3);
    MemPropROExpDecl(Vec3, zyx, Vec3);
    MemPropROExpDecl(Vec3, zyy, Vec3);
    MemPropROExpDecl(Vec3, zyz, Vec3);
    MemPropROExpDecl(Vec3, zzx, Vec3);
    MemPropROExpDecl(Vec3, zzy, Vec3);
    MemPropROExpDecl(Vec3, zzz, Vec3);

    MemPropROExpDecl(Vec3, xxxx, Vec4);
    MemPropROExpDecl(Vec3, xxxy, Vec4);
    MemPropROExpDecl(Vec3, xxxz, Vec4);
    MemPropROExpDecl(Vec3, xxyx, Vec4);
    MemPropROExpDecl(Vec3, xxyy, Vec4);
    MemPropROExpDecl(Vec3, xxyz, Vec4);
    MemPropROExpDecl(Vec3, xxzx, Vec4);
    MemPropROExpDecl(Vec3, xxzy, Vec4);
    MemPropROExpDecl(Vec3, xxzz, Vec4);
    MemPropROExpDecl(Vec3, xyxx, Vec4);
    MemPropROExpDecl(Vec3, xyxy, Vec4);
    MemPropROExpDecl(Vec3, xyxz, Vec4);
    MemPropROExpDecl(Vec3, xyyx, Vec4);
    MemPropROExpDecl(Vec3, xyyy, Vec4);
    MemPropROExpDecl(Vec3, xyyz, Vec4);
    MemPropROExpDecl(Vec3, xyzx, Vec4);
    MemPropROExpDecl(Vec3, xyzy, Vec4);
    MemPropROExpDecl(Vec3, xyzz, Vec4);
    MemPropROExpDecl(Vec3, xzxx, Vec4);
    MemPropROExpDecl(Vec3, xzxy, Vec4);
    MemPropROExpDecl(Vec3, xzxz, Vec4);
    MemPropROExpDecl(Vec3, xzyx, Vec4);
    MemPropROExpDecl(Vec3, xzyy, Vec4);
    MemPropROExpDecl(Vec3, xzyz, Vec4);
    MemPropROExpDecl(Vec3, xzzx, Vec4);
    MemPropROExpDecl(Vec3, xzzy, Vec4);
    MemPropROExpDecl(Vec3, xzzz, Vec4);
    MemPropROExpDecl(Vec3, yxxx, Vec4);
    MemPropROExpDecl(Vec3, yxxy, Vec4);
    MemPropROExpDecl(Vec3, yxxz, Vec4);
    MemPropROExpDecl(Vec3, yxyx, Vec4);
    MemPropROExpDecl(Vec3, yxyy, Vec4);
    MemPropROExpDecl(Vec3, yxyz, Vec4);
    MemPropROExpDecl(Vec3, yxzx, Vec4);
    MemPropROExpDecl(Vec3, yxzy, Vec4);
    MemPropROExpDecl(Vec3, yxzz, Vec4);
    MemPropROExpDecl(Vec3, yyxx, Vec4);
    MemPropROExpDecl(Vec3, yyxy, Vec4);
    MemPropROExpDecl(Vec3, yyxz, Vec4);
    MemPropROExpDecl(Vec3, yyyx, Vec4);
    MemPropROExpDecl(Vec3, yyyy, Vec4);
    MemPropROExpDecl(Vec3, yyyz, Vec4);
    MemPropROExpDecl(Vec3, yyzx, Vec4);
    MemPropROExpDecl(Vec3, yyzy, Vec4);
    MemPropROExpDecl(Vec3, yyzz, Vec4);
    MemPropROExpDecl(Vec3, yzxx, Vec4);
    MemPropROExpDecl(Vec3, yzxy, Vec4);
    MemPropROExpDecl(Vec3, yzxz, Vec4);
    MemPropROExpDecl(Vec3, yzyx, Vec4);
    MemPropROExpDecl(Vec3, yzyy, Vec4);
    MemPropROExpDecl(Vec3, yzyz, Vec4);
    MemPropROExpDecl(Vec3, yzzx, Vec4);
    MemPropROExpDecl(Vec3, yzzy, Vec4);
    MemPropROExpDecl(Vec3, yzzz, Vec4);
    MemPropROExpDecl(Vec3, zxxx, Vec4);
    MemPropROExpDecl(Vec3, zxxy, Vec4);
    MemPropROExpDecl(Vec3, zxxz, Vec4);
    MemPropROExpDecl(Vec3, zxyx, Vec4);
    MemPropROExpDecl(Vec3, zxyy, Vec4);
    MemPropROExpDecl(Vec3, zxyz, Vec4);
    MemPropROExpDecl(Vec3, zxzx, Vec4);
    MemPropROExpDecl(Vec3, zxzy, Vec4);
    MemPropROExpDecl(Vec3, zxzz, Vec4);
    MemPropROExpDecl(Vec3, zyxx, Vec4);
    MemPropROExpDecl(Vec3, zyxy, Vec4);
    MemPropROExpDecl(Vec3, zyxz, Vec4);
    MemPropROExpDecl(Vec3, zyyx, Vec4);
    MemPropROExpDecl(Vec3, zyyy, Vec4);
    MemPropROExpDecl(Vec3, zyyz, Vec4);
    MemPropROExpDecl(Vec3, zyzx, Vec4);
    MemPropROExpDecl(Vec3, zyzy, Vec4);
    MemPropROExpDecl(Vec3, zyzz, Vec4);
    MemPropROExpDecl(Vec3, zzxx, Vec4);
    MemPropROExpDecl(Vec3, zzxy, Vec4);
    MemPropROExpDecl(Vec3, zzxz, Vec4);
    MemPropROExpDecl(Vec3, zzyx, Vec4);
    MemPropROExpDecl(Vec3, zzyy, Vec4);
    MemPropROExpDecl(Vec3, zzyz, Vec4);
    MemPropROExpDecl(Vec3, zzzx, Vec4);
    MemPropROExpDecl(Vec3, zzzy, Vec4);
    MemPropROExpDecl(Vec3, zzzz, Vec4);
};

inline Vec3 operator+(Vec3 a) { return Vec3(+a.x, +a.y, +a.z); }
inline Vec3 operator-(Vec3 a) { return Vec3(-a.x, -a.y, -a.z); }

inline Vec3 operator+(Vec3 a, Vec3 b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
inline Vec3 operator-(Vec3 a, Vec3 b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
inline Vec3 operator*(Vec3 a, Vec3 b) { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
inline Vec3 operator/(Vec3 a, Vec3 b) { return {a.x / b.x, a.y / b.y, a.z / b.z}; }
inline Vec3 operator+(Vec3 a, float b) { return {a.x + b, a.y + b, a.z + b}; }
inline Vec3 operator-(Vec3 a, float b) { return {a.x - b, a.y - b, a.z - b}; }
inline Vec3 operator*(Vec3 a, float b) { return {a.x * b, a.y * b, a.z * b}; }
inline Vec3 operator/(Vec3 a, float b) { return {a.x / b, a.y / b, a.z / b}; }
inline Vec3 operator+(float a, Vec3 b) { return {a + b.x, a + b.y, a + b.z}; }
inline Vec3 operator-(float a, Vec3 b) { return {a - b.x, a - b.y, a - b.z}; }
inline Vec3 operator*(float a, Vec3 b) { return {a * b.x, a * b.y, a * b.z}; }
inline Vec3 operator/(float a, Vec3 b) { return {a / b.x, a / b.y, a / b.z}; }

inline Vec3 &Vec3::operator+=(Vec3 b) { return *this = *this + b; }
inline Vec3 &Vec3::operator-=(Vec3 b) { return *this = *this - b; }
inline Vec3 &Vec3::operator*=(Vec3 b) { return *this = *this * b; }
inline Vec3 &Vec3::operator/=(Vec3 b) { return *this = *this / b; }
inline Vec3 &Vec3::operator+=(float b) { return *this = *this + b; }
inline Vec3 &Vec3::operator-=(float b) { return *this = *this - b; }
inline Vec3 &Vec3::operator*=(float b) { return *this = *this * b; }
inline Vec3 &Vec3::operator/=(float b) { return *this = *this / b; }

struct Vec4 {
    float x;
    float y;
    float z;
    float w;

    Vec4() = default;
    Vec4(float xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vec4(SDL_FRect v) : x(v.x), y(v.y), z(v.w), w(v.h) {}

    Vec4(Vec2 v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {}
    Vec4(float x, Vec2 v, float w) : x(x), y(v.x), z(v.y), w(w) {}
    Vec4(float x, float y, Vec2 v) : x(x), y(y), z(v.x), w(v.y) {}
    Vec4(Vec2 v, Vec2 u) : x(v.x), y(v.y), z(u.x), w(u.y) {}
    Vec4(Vec3 v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}
    Vec4(float x, Vec3 v) : x(x), y(v.x), z(v.y), w(v.z) {}

    inline explicit Vec4(Vec2 v);
    inline explicit Vec4(Vec3 v);

    operator SDL_FRect() const { return {x, y, z, w}; }

    inline Vec4 &operator+=(Vec4 b);
    inline Vec4 &operator-=(Vec4 b);
    inline Vec4 &operator*=(Vec4 b);
    inline Vec4 &operator/=(Vec4 b);
    inline Vec4 &operator+=(SDL_FRect b);
    inline Vec4 &operator-=(SDL_FRect b);
    inline Vec4 &operator*=(SDL_FRect b);
    inline Vec4 &operator/=(SDL_FRect b);
    inline Vec4 &operator+=(float b);
    inline Vec4 &operator-=(float b);
    inline Vec4 &operator*=(float b);
    inline Vec4 &operator/=(float b);

    MemPropROExpDecl(Vec4, xx, Vec2);
    MemPropROExpDecl(Vec4, xy, Vec2);
    MemPropROExpDecl(Vec4, xz, Vec2);
    MemPropROExpDecl(Vec4, xw, Vec2);
    MemPropROExpDecl(Vec4, yx, Vec2);
    MemPropROExpDecl(Vec4, yy, Vec2);
    MemPropROExpDecl(Vec4, yz, Vec2);
    MemPropROExpDecl(Vec4, yw, Vec2);
    MemPropROExpDecl(Vec4, zx, Vec2);
    MemPropROExpDecl(Vec4, zy, Vec2);
    MemPropROExpDecl(Vec4, zz, Vec2);
    MemPropROExpDecl(Vec4, zw, Vec2);
    MemPropROExpDecl(Vec4, wx, Vec2);
    MemPropROExpDecl(Vec4, wy, Vec2);
    MemPropROExpDecl(Vec4, wz, Vec2);
    MemPropROExpDecl(Vec4, ww, Vec2);

    MemPropROExpDecl(Vec4, xxx, Vec3);
    MemPropROExpDecl(Vec4, xxy, Vec3);
    MemPropROExpDecl(Vec4, xxz, Vec3);
    MemPropROExpDecl(Vec4, xxw, Vec3);
    MemPropROExpDecl(Vec4, xyx, Vec3);
    MemPropROExpDecl(Vec4, xyy, Vec3);
    MemPropROExpDecl(Vec4, xyz, Vec3);
    MemPropROExpDecl(Vec4, xyw, Vec3);
    MemPropROExpDecl(Vec4, xzx, Vec3);
    MemPropROExpDecl(Vec4, xzy, Vec3);
    MemPropROExpDecl(Vec4, xzz, Vec3);
    MemPropROExpDecl(Vec4, xzw, Vec3);
    MemPropROExpDecl(Vec4, xwx, Vec3);
    MemPropROExpDecl(Vec4, xwy, Vec3);
    MemPropROExpDecl(Vec4, xwz, Vec3);
    MemPropROExpDecl(Vec4, xww, Vec3);
    MemPropROExpDecl(Vec4, yxx, Vec3);
    MemPropROExpDecl(Vec4, yxy, Vec3);
    MemPropROExpDecl(Vec4, yxz, Vec3);
    MemPropROExpDecl(Vec4, yxw, Vec3);
    MemPropROExpDecl(Vec4, yyx, Vec3);
    MemPropROExpDecl(Vec4, yyy, Vec3);
    MemPropROExpDecl(Vec4, yyz, Vec3);
    MemPropROExpDecl(Vec4, yyw, Vec3);
    MemPropROExpDecl(Vec4, yzx, Vec3);
    MemPropROExpDecl(Vec4, yzy, Vec3);
    MemPropROExpDecl(Vec4, yzz, Vec3);
    MemPropROExpDecl(Vec4, yzw, Vec3);
    MemPropROExpDecl(Vec4, ywx, Vec3);
    MemPropROExpDecl(Vec4, ywy, Vec3);
    MemPropROExpDecl(Vec4, ywz, Vec3);
    MemPropROExpDecl(Vec4, yww, Vec3);
    MemPropROExpDecl(Vec4, zxx, Vec3);
    MemPropROExpDecl(Vec4, zxy, Vec3);
    MemPropROExpDecl(Vec4, zxz, Vec3);
    MemPropROExpDecl(Vec4, zxw, Vec3);
    MemPropROExpDecl(Vec4, zyx, Vec3);
    MemPropROExpDecl(Vec4, zyy, Vec3);
    MemPropROExpDecl(Vec4, zyz, Vec3);
    MemPropROExpDecl(Vec4, zyw, Vec3);
    MemPropROExpDecl(Vec4, zzx, Vec3);
    MemPropROExpDecl(Vec4, zzy, Vec3);
    MemPropROExpDecl(Vec4, zzz, Vec3);
    MemPropROExpDecl(Vec4, zzw, Vec3);
    MemPropROExpDecl(Vec4, zwx, Vec3);
    MemPropROExpDecl(Vec4, zwy, Vec3);
    MemPropROExpDecl(Vec4, zwz, Vec3);
    MemPropROExpDecl(Vec4, zww, Vec3);
    MemPropROExpDecl(Vec4, wxx, Vec3);
    MemPropROExpDecl(Vec4, wxy, Vec3);
    MemPropROExpDecl(Vec4, wxz, Vec3);
    MemPropROExpDecl(Vec4, wxw, Vec3);
    MemPropROExpDecl(Vec4, wyx, Vec3);
    MemPropROExpDecl(Vec4, wyy, Vec3);
    MemPropROExpDecl(Vec4, wyz, Vec3);
    MemPropROExpDecl(Vec4, wyw, Vec3);
    MemPropROExpDecl(Vec4, wzx, Vec3);
    MemPropROExpDecl(Vec4, wzy, Vec3);
    MemPropROExpDecl(Vec4, wzz, Vec3);
    MemPropROExpDecl(Vec4, wzw, Vec3);
    MemPropROExpDecl(Vec4, wwx, Vec3);
    MemPropROExpDecl(Vec4, wwy, Vec3);
    MemPropROExpDecl(Vec4, wwz, Vec3);
    MemPropROExpDecl(Vec4, www, Vec3);

    MemPropROExpDecl(Vec4, xxxx, Vec4);
    MemPropROExpDecl(Vec4, xxxy, Vec4);
    MemPropROExpDecl(Vec4, xxxz, Vec4);
    MemPropROExpDecl(Vec4, xxxw, Vec4);
    MemPropROExpDecl(Vec4, xxyx, Vec4);
    MemPropROExpDecl(Vec4, xxyy, Vec4);
    MemPropROExpDecl(Vec4, xxyz, Vec4);
    MemPropROExpDecl(Vec4, xxyw, Vec4);
    MemPropROExpDecl(Vec4, xxzx, Vec4);
    MemPropROExpDecl(Vec4, xxzy, Vec4);
    MemPropROExpDecl(Vec4, xxzz, Vec4);
    MemPropROExpDecl(Vec4, xxzw, Vec4);
    MemPropROExpDecl(Vec4, xxwx, Vec4);
    MemPropROExpDecl(Vec4, xxwy, Vec4);
    MemPropROExpDecl(Vec4, xxwz, Vec4);
    MemPropROExpDecl(Vec4, xxww, Vec4);
    MemPropROExpDecl(Vec4, xyxx, Vec4);
    MemPropROExpDecl(Vec4, xyxy, Vec4);
    MemPropROExpDecl(Vec4, xyxz, Vec4);
    MemPropROExpDecl(Vec4, xyxw, Vec4);
    MemPropROExpDecl(Vec4, xyyx, Vec4);
    MemPropROExpDecl(Vec4, xyyy, Vec4);
    MemPropROExpDecl(Vec4, xyyz, Vec4);
    MemPropROExpDecl(Vec4, xyyw, Vec4);
    MemPropROExpDecl(Vec4, xyzx, Vec4);
    MemPropROExpDecl(Vec4, xyzy, Vec4);
    MemPropROExpDecl(Vec4, xyzz, Vec4);
    MemPropROExpDecl(Vec4, xyzw, Vec4);
    MemPropROExpDecl(Vec4, xywx, Vec4);
    MemPropROExpDecl(Vec4, xywy, Vec4);
    MemPropROExpDecl(Vec4, xywz, Vec4);
    MemPropROExpDecl(Vec4, xyww, Vec4);
    MemPropROExpDecl(Vec4, xzxx, Vec4);
    MemPropROExpDecl(Vec4, xzxy, Vec4);
    MemPropROExpDecl(Vec4, xzxz, Vec4);
    MemPropROExpDecl(Vec4, xzxw, Vec4);
    MemPropROExpDecl(Vec4, xzyx, Vec4);
    MemPropROExpDecl(Vec4, xzyy, Vec4);
    MemPropROExpDecl(Vec4, xzyz, Vec4);
    MemPropROExpDecl(Vec4, xzyw, Vec4);
    MemPropROExpDecl(Vec4, xzzx, Vec4);
    MemPropROExpDecl(Vec4, xzzy, Vec4);
    MemPropROExpDecl(Vec4, xzzz, Vec4);
    MemPropROExpDecl(Vec4, xzzw, Vec4);
    MemPropROExpDecl(Vec4, xzwx, Vec4);
    MemPropROExpDecl(Vec4, xzwy, Vec4);
    MemPropROExpDecl(Vec4, xzwz, Vec4);
    MemPropROExpDecl(Vec4, xzww, Vec4);
    MemPropROExpDecl(Vec4, xwxx, Vec4);
    MemPropROExpDecl(Vec4, xwxy, Vec4);
    MemPropROExpDecl(Vec4, xwxz, Vec4);
    MemPropROExpDecl(Vec4, xwxw, Vec4);
    MemPropROExpDecl(Vec4, xwyx, Vec4);
    MemPropROExpDecl(Vec4, xwyy, Vec4);
    MemPropROExpDecl(Vec4, xwyz, Vec4);
    MemPropROExpDecl(Vec4, xwyw, Vec4);
    MemPropROExpDecl(Vec4, xwzx, Vec4);
    MemPropROExpDecl(Vec4, xwzy, Vec4);
    MemPropROExpDecl(Vec4, xwzz, Vec4);
    MemPropROExpDecl(Vec4, xwzw, Vec4);
    MemPropROExpDecl(Vec4, xwwx, Vec4);
    MemPropROExpDecl(Vec4, xwwy, Vec4);
    MemPropROExpDecl(Vec4, xwwz, Vec4);
    MemPropROExpDecl(Vec4, xwww, Vec4);
    MemPropROExpDecl(Vec4, yxxx, Vec4);
    MemPropROExpDecl(Vec4, yxxy, Vec4);
    MemPropROExpDecl(Vec4, yxxz, Vec4);
    MemPropROExpDecl(Vec4, yxxw, Vec4);
    MemPropROExpDecl(Vec4, yxyx, Vec4);
    MemPropROExpDecl(Vec4, yxyy, Vec4);
    MemPropROExpDecl(Vec4, yxyz, Vec4);
    MemPropROExpDecl(Vec4, yxyw, Vec4);
    MemPropROExpDecl(Vec4, yxzx, Vec4);
    MemPropROExpDecl(Vec4, yxzy, Vec4);
    MemPropROExpDecl(Vec4, yxzz, Vec4);
    MemPropROExpDecl(Vec4, yxzw, Vec4);
    MemPropROExpDecl(Vec4, yxwx, Vec4);
    MemPropROExpDecl(Vec4, yxwy, Vec4);
    MemPropROExpDecl(Vec4, yxwz, Vec4);
    MemPropROExpDecl(Vec4, yxww, Vec4);
    MemPropROExpDecl(Vec4, yyxx, Vec4);
    MemPropROExpDecl(Vec4, yyxy, Vec4);
    MemPropROExpDecl(Vec4, yyxz, Vec4);
    MemPropROExpDecl(Vec4, yyxw, Vec4);
    MemPropROExpDecl(Vec4, yyyx, Vec4);
    MemPropROExpDecl(Vec4, yyyy, Vec4);
    MemPropROExpDecl(Vec4, yyyz, Vec4);
    MemPropROExpDecl(Vec4, yyyw, Vec4);
    MemPropROExpDecl(Vec4, yyzx, Vec4);
    MemPropROExpDecl(Vec4, yyzy, Vec4);
    MemPropROExpDecl(Vec4, yyzz, Vec4);
    MemPropROExpDecl(Vec4, yyzw, Vec4);
    MemPropROExpDecl(Vec4, yywx, Vec4);
    MemPropROExpDecl(Vec4, yywy, Vec4);
    MemPropROExpDecl(Vec4, yywz, Vec4);
    MemPropROExpDecl(Vec4, yyww, Vec4);
    MemPropROExpDecl(Vec4, yzxx, Vec4);
    MemPropROExpDecl(Vec4, yzxy, Vec4);
    MemPropROExpDecl(Vec4, yzxz, Vec4);
    MemPropROExpDecl(Vec4, yzxw, Vec4);
    MemPropROExpDecl(Vec4, yzyx, Vec4);
    MemPropROExpDecl(Vec4, yzyy, Vec4);
    MemPropROExpDecl(Vec4, yzyz, Vec4);
    MemPropROExpDecl(Vec4, yzyw, Vec4);
    MemPropROExpDecl(Vec4, yzzx, Vec4);
    MemPropROExpDecl(Vec4, yzzy, Vec4);
    MemPropROExpDecl(Vec4, yzzz, Vec4);
    MemPropROExpDecl(Vec4, yzzw, Vec4);
    MemPropROExpDecl(Vec4, yzwx, Vec4);
    MemPropROExpDecl(Vec4, yzwy, Vec4);
    MemPropROExpDecl(Vec4, yzwz, Vec4);
    MemPropROExpDecl(Vec4, yzww, Vec4);
    MemPropROExpDecl(Vec4, ywxx, Vec4);
    MemPropROExpDecl(Vec4, ywxy, Vec4);
    MemPropROExpDecl(Vec4, ywxz, Vec4);
    MemPropROExpDecl(Vec4, ywxw, Vec4);
    MemPropROExpDecl(Vec4, ywyx, Vec4);
    MemPropROExpDecl(Vec4, ywyy, Vec4);
    MemPropROExpDecl(Vec4, ywyz, Vec4);
    MemPropROExpDecl(Vec4, ywyw, Vec4);
    MemPropROExpDecl(Vec4, ywzx, Vec4);
    MemPropROExpDecl(Vec4, ywzy, Vec4);
    MemPropROExpDecl(Vec4, ywzz, Vec4);
    MemPropROExpDecl(Vec4, ywzw, Vec4);
    MemPropROExpDecl(Vec4, ywwx, Vec4);
    MemPropROExpDecl(Vec4, ywwy, Vec4);
    MemPropROExpDecl(Vec4, ywwz, Vec4);
    MemPropROExpDecl(Vec4, ywww, Vec4);
    MemPropROExpDecl(Vec4, zxxx, Vec4);
    MemPropROExpDecl(Vec4, zxxy, Vec4);
    MemPropROExpDecl(Vec4, zxxz, Vec4);
    MemPropROExpDecl(Vec4, zxxw, Vec4);
    MemPropROExpDecl(Vec4, zxyx, Vec4);
    MemPropROExpDecl(Vec4, zxyy, Vec4);
    MemPropROExpDecl(Vec4, zxyz, Vec4);
    MemPropROExpDecl(Vec4, zxyw, Vec4);
    MemPropROExpDecl(Vec4, zxzx, Vec4);
    MemPropROExpDecl(Vec4, zxzy, Vec4);
    MemPropROExpDecl(Vec4, zxzz, Vec4);
    MemPropROExpDecl(Vec4, zxzw, Vec4);
    MemPropROExpDecl(Vec4, zxwx, Vec4);
    MemPropROExpDecl(Vec4, zxwy, Vec4);
    MemPropROExpDecl(Vec4, zxwz, Vec4);
    MemPropROExpDecl(Vec4, zxww, Vec4);
    MemPropROExpDecl(Vec4, zyxx, Vec4);
    MemPropROExpDecl(Vec4, zyxy, Vec4);
    MemPropROExpDecl(Vec4, zyxz, Vec4);
    MemPropROExpDecl(Vec4, zyxw, Vec4);
    MemPropROExpDecl(Vec4, zyyx, Vec4);
    MemPropROExpDecl(Vec4, zyyy, Vec4);
    MemPropROExpDecl(Vec4, zyyz, Vec4);
    MemPropROExpDecl(Vec4, zyyw, Vec4);
    MemPropROExpDecl(Vec4, zyzx, Vec4);
    MemPropROExpDecl(Vec4, zyzy, Vec4);
    MemPropROExpDecl(Vec4, zyzz, Vec4);
    MemPropROExpDecl(Vec4, zyzw, Vec4);
    MemPropROExpDecl(Vec4, zywx, Vec4);
    MemPropROExpDecl(Vec4, zywy, Vec4);
    MemPropROExpDecl(Vec4, zywz, Vec4);
    MemPropROExpDecl(Vec4, zyww, Vec4);
    MemPropROExpDecl(Vec4, zzxx, Vec4);
    MemPropROExpDecl(Vec4, zzxy, Vec4);
    MemPropROExpDecl(Vec4, zzxz, Vec4);
    MemPropROExpDecl(Vec4, zzxw, Vec4);
    MemPropROExpDecl(Vec4, zzyx, Vec4);
    MemPropROExpDecl(Vec4, zzyy, Vec4);
    MemPropROExpDecl(Vec4, zzyz, Vec4);
    MemPropROExpDecl(Vec4, zzyw, Vec4);
    MemPropROExpDecl(Vec4, zzzx, Vec4);
    MemPropROExpDecl(Vec4, zzzy, Vec4);
    MemPropROExpDecl(Vec4, zzzz, Vec4);
    MemPropROExpDecl(Vec4, zzzw, Vec4);
    MemPropROExpDecl(Vec4, zzwx, Vec4);
    MemPropROExpDecl(Vec4, zzwy, Vec4);
    MemPropROExpDecl(Vec4, zzwz, Vec4);
    MemPropROExpDecl(Vec4, zzww, Vec4);
    MemPropROExpDecl(Vec4, zwxx, Vec4);
    MemPropROExpDecl(Vec4, zwxy, Vec4);
    MemPropROExpDecl(Vec4, zwxz, Vec4);
    MemPropROExpDecl(Vec4, zwxw, Vec4);
    MemPropROExpDecl(Vec4, zwyx, Vec4);
    MemPropROExpDecl(Vec4, zwyy, Vec4);
    MemPropROExpDecl(Vec4, zwyz, Vec4);
    MemPropROExpDecl(Vec4, zwyw, Vec4);
    MemPropROExpDecl(Vec4, zwzx, Vec4);
    MemPropROExpDecl(Vec4, zwzy, Vec4);
    MemPropROExpDecl(Vec4, zwzz, Vec4);
    MemPropROExpDecl(Vec4, zwzw, Vec4);
    MemPropROExpDecl(Vec4, zwwx, Vec4);
    MemPropROExpDecl(Vec4, zwwy, Vec4);
    MemPropROExpDecl(Vec4, zwwz, Vec4);
    MemPropROExpDecl(Vec4, zwww, Vec4);
    MemPropROExpDecl(Vec4, wxxx, Vec4);
    MemPropROExpDecl(Vec4, wxxy, Vec4);
    MemPropROExpDecl(Vec4, wxxz, Vec4);
    MemPropROExpDecl(Vec4, wxxw, Vec4);
    MemPropROExpDecl(Vec4, wxyx, Vec4);
    MemPropROExpDecl(Vec4, wxyy, Vec4);
    MemPropROExpDecl(Vec4, wxyz, Vec4);
    MemPropROExpDecl(Vec4, wxyw, Vec4);
    MemPropROExpDecl(Vec4, wxzx, Vec4);
    MemPropROExpDecl(Vec4, wxzy, Vec4);
    MemPropROExpDecl(Vec4, wxzz, Vec4);
    MemPropROExpDecl(Vec4, wxzw, Vec4);
    MemPropROExpDecl(Vec4, wxwx, Vec4);
    MemPropROExpDecl(Vec4, wxwy, Vec4);
    MemPropROExpDecl(Vec4, wxwz, Vec4);
    MemPropROExpDecl(Vec4, wxww, Vec4);
    MemPropROExpDecl(Vec4, wyxx, Vec4);
    MemPropROExpDecl(Vec4, wyxy, Vec4);
    MemPropROExpDecl(Vec4, wyxz, Vec4);
    MemPropROExpDecl(Vec4, wyxw, Vec4);
    MemPropROExpDecl(Vec4, wyyx, Vec4);
    MemPropROExpDecl(Vec4, wyyy, Vec4);
    MemPropROExpDecl(Vec4, wyyz, Vec4);
    MemPropROExpDecl(Vec4, wyyw, Vec4);
    MemPropROExpDecl(Vec4, wyzx, Vec4);
    MemPropROExpDecl(Vec4, wyzy, Vec4);
    MemPropROExpDecl(Vec4, wyzz, Vec4);
    MemPropROExpDecl(Vec4, wyzw, Vec4);
    MemPropROExpDecl(Vec4, wywx, Vec4);
    MemPropROExpDecl(Vec4, wywy, Vec4);
    MemPropROExpDecl(Vec4, wywz, Vec4);
    MemPropROExpDecl(Vec4, wyww, Vec4);
    MemPropROExpDecl(Vec4, wzxx, Vec4);
    MemPropROExpDecl(Vec4, wzxy, Vec4);
    MemPropROExpDecl(Vec4, wzxz, Vec4);
    MemPropROExpDecl(Vec4, wzxw, Vec4);
    MemPropROExpDecl(Vec4, wzyx, Vec4);
    MemPropROExpDecl(Vec4, wzyy, Vec4);
    MemPropROExpDecl(Vec4, wzyz, Vec4);
    MemPropROExpDecl(Vec4, wzyw, Vec4);
    MemPropROExpDecl(Vec4, wzzx, Vec4);
    MemPropROExpDecl(Vec4, wzzy, Vec4);
    MemPropROExpDecl(Vec4, wzzz, Vec4);
    MemPropROExpDecl(Vec4, wzzw, Vec4);
    MemPropROExpDecl(Vec4, wzwx, Vec4);
    MemPropROExpDecl(Vec4, wzwy, Vec4);
    MemPropROExpDecl(Vec4, wzwz, Vec4);
    MemPropROExpDecl(Vec4, wzww, Vec4);
    MemPropROExpDecl(Vec4, wwxx, Vec4);
    MemPropROExpDecl(Vec4, wwxy, Vec4);
    MemPropROExpDecl(Vec4, wwxz, Vec4);
    MemPropROExpDecl(Vec4, wwxw, Vec4);
    MemPropROExpDecl(Vec4, wwyx, Vec4);
    MemPropROExpDecl(Vec4, wwyy, Vec4);
    MemPropROExpDecl(Vec4, wwyz, Vec4);
    MemPropROExpDecl(Vec4, wwyw, Vec4);
    MemPropROExpDecl(Vec4, wwzx, Vec4);
    MemPropROExpDecl(Vec4, wwzy, Vec4);
    MemPropROExpDecl(Vec4, wwzz, Vec4);
    MemPropROExpDecl(Vec4, wwzw, Vec4);
    MemPropROExpDecl(Vec4, wwwx, Vec4);
    MemPropROExpDecl(Vec4, wwwy, Vec4);
    MemPropROExpDecl(Vec4, wwwz, Vec4);
    MemPropROExpDecl(Vec4, wwww, Vec4);
};

inline Vec4 operator+(Vec4 a) { return Vec4(+a.x, +a.y, +a.z, +a.w); }
inline Vec4 operator-(Vec4 a) { return Vec4(-a.x, -a.y, -a.z, -a.w); }

inline Vec4 operator+(Vec4 a, Vec4 b) { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
inline Vec4 operator-(Vec4 a, Vec4 b) { return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
inline Vec4 operator*(Vec4 a, Vec4 b) { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
inline Vec4 operator/(Vec4 a, Vec4 b) { return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }
inline Vec4 operator+(Vec4 a, SDL_FRect b) { return {a.x + b.x, a.y + b.y, a.z + b.w, a.w + b.h}; }
inline Vec4 operator-(Vec4 a, SDL_FRect b) { return {a.x - b.x, a.y - b.y, a.z - b.w, a.w - b.h}; }
inline Vec4 operator*(Vec4 a, SDL_FRect b) { return {a.x * b.x, a.y * b.y, a.z * b.w, a.w * b.h}; }
inline Vec4 operator/(Vec4 a, SDL_FRect b) { return {a.x / b.x, a.y / b.y, a.z / b.w, a.w / b.h}; }
inline Vec4 operator+(SDL_FRect a, Vec4 b) { return {a.x + b.x, a.y + b.y, a.w + b.z, a.h + b.w}; }
inline Vec4 operator-(SDL_FRect a, Vec4 b) { return {a.x - b.x, a.y - b.y, a.w - b.z, a.h - b.w}; }
inline Vec4 operator*(SDL_FRect a, Vec4 b) { return {a.x * b.x, a.y * b.y, a.w * b.z, a.h * b.w}; }
inline Vec4 operator/(SDL_FRect a, Vec4 b) { return {a.x / b.x, a.y / b.y, a.w / b.z, a.h / b.w}; }
inline Vec4 operator+(Vec4 a, float b) { return {a.x + b, a.y + b, a.z + b, a.w + b}; }
inline Vec4 operator-(Vec4 a, float b) { return {a.x - b, a.y - b, a.z - b, a.w - b}; }
inline Vec4 operator*(Vec4 a, float b) { return {a.x * b, a.y * b, a.z * b, a.w * b}; }
inline Vec4 operator/(Vec4 a, float b) { return {a.x / b, a.y / b, a.z / b, a.w / b}; }
inline Vec4 operator+(float a, Vec4 b) { return {a + b.x, a + b.y, a + b.z, a + b.w}; }
inline Vec4 operator-(float a, Vec4 b) { return {a - b.x, a - b.y, a - b.z, a - b.w}; }
inline Vec4 operator*(float a, Vec4 b) { return {a * b.x, a * b.y, a * b.z, a * b.w}; }
inline Vec4 operator/(float a, Vec4 b) { return {a / b.x, a / b.y, a / b.z, a / b.w}; }

inline Vec4 &Vec4::operator+=(Vec4 b) { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(Vec4 b) { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(Vec4 b) { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(Vec4 b) { return *this = *this / b; }
inline Vec4 &Vec4::operator+=(SDL_FRect b) { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(SDL_FRect b) { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(SDL_FRect b) { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(SDL_FRect b) { return *this = *this / b; }
inline Vec4 &Vec4::operator+=(float b) { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(float b) { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(float b) { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(float b) { return *this = *this / b; }

inline Vec2::Vec2(Vec3 v) : x(v.x), y(v.y) {}
inline Vec2::Vec2(Vec4 v) : x(v.x), y(v.y) {}
inline Vec3::Vec3(Vec2 v) : x(v.x), y(v.y), z(0.0f) {}
inline Vec3::Vec3(Vec4 v) : x(v.x), y(v.y), z(v.z) {}
inline Vec4::Vec4(Vec2 v) : x(v.x), y(v.y), z(0.0f), w(0.0f) {}
inline Vec4::Vec4(Vec3 v) : x(v.x), y(v.y), z(v.z), w(0.0f) {}

MemPropROExpDef(Vec2, xx, Vec2, Vec2(self.x, self.x));
MemPropROExpDef(Vec2, xy, Vec2, Vec2(self.x, self.y));
MemPropROExpDef(Vec2, yx, Vec2, Vec2(self.y, self.x));
MemPropROExpDef(Vec2, yy, Vec2, Vec2(self.y, self.y));

MemPropROExpDef(Vec2, xxx, Vec3, Vec3(self.x, self.x, self.x));
MemPropROExpDef(Vec2, xxy, Vec3, Vec3(self.x, self.x, self.y));
MemPropROExpDef(Vec2, xyx, Vec3, Vec3(self.x, self.y, self.x));
MemPropROExpDef(Vec2, xyy, Vec3, Vec3(self.x, self.y, self.y));
MemPropROExpDef(Vec2, yxx, Vec3, Vec3(self.y, self.x, self.x));
MemPropROExpDef(Vec2, yxy, Vec3, Vec3(self.y, self.x, self.y));
MemPropROExpDef(Vec2, yyx, Vec3, Vec3(self.y, self.y, self.x));
MemPropROExpDef(Vec2, yyy, Vec3, Vec3(self.y, self.y, self.y));

MemPropROExpDef(Vec2, xxxx, Vec4, Vec4(self.x, self.x, self.x, self.x));
MemPropROExpDef(Vec2, xxxy, Vec4, Vec4(self.x, self.x, self.x, self.y));
MemPropROExpDef(Vec2, xxyx, Vec4, Vec4(self.x, self.x, self.y, self.x));
MemPropROExpDef(Vec2, xxyy, Vec4, Vec4(self.x, self.x, self.y, self.y));
MemPropROExpDef(Vec2, xyxx, Vec4, Vec4(self.x, self.y, self.x, self.x));
MemPropROExpDef(Vec2, xyxy, Vec4, Vec4(self.x, self.y, self.x, self.y));
MemPropROExpDef(Vec2, xyyx, Vec4, Vec4(self.x, self.y, self.y, self.x));
MemPropROExpDef(Vec2, xyyy, Vec4, Vec4(self.x, self.y, self.y, self.y));
MemPropROExpDef(Vec2, yxxx, Vec4, Vec4(self.y, self.x, self.x, self.x));
MemPropROExpDef(Vec2, yxxy, Vec4, Vec4(self.y, self.x, self.x, self.y));
MemPropROExpDef(Vec2, yxyx, Vec4, Vec4(self.y, self.x, self.y, self.x));
MemPropROExpDef(Vec2, yxyy, Vec4, Vec4(self.y, self.x, self.y, self.y));
MemPropROExpDef(Vec2, yyxx, Vec4, Vec4(self.y, self.y, self.x, self.x));
MemPropROExpDef(Vec2, yyxy, Vec4, Vec4(self.y, self.y, self.x, self.y));
MemPropROExpDef(Vec2, yyyx, Vec4, Vec4(self.y, self.y, self.y, self.x));
MemPropROExpDef(Vec2, yyyy, Vec4, Vec4(self.y, self.y, self.y, self.y));

MemPropROExpDef(Vec3, xx, Vec2, Vec2(self.x, self.x));
MemPropROExpDef(Vec3, xy, Vec2, Vec2(self.x, self.y));
MemPropROExpDef(Vec3, xz, Vec2, Vec2(self.x, self.z));
MemPropROExpDef(Vec3, yx, Vec2, Vec2(self.y, self.x));
MemPropROExpDef(Vec3, yy, Vec2, Vec2(self.y, self.y));
MemPropROExpDef(Vec3, yz, Vec2, Vec2(self.y, self.z));
MemPropROExpDef(Vec3, zx, Vec2, Vec2(self.z, self.x));
MemPropROExpDef(Vec3, zy, Vec2, Vec2(self.z, self.y));
MemPropROExpDef(Vec3, zz, Vec2, Vec2(self.z, self.z));

MemPropROExpDef(Vec3, xxx, Vec3, Vec3(self.x, self.x, self.x));
MemPropROExpDef(Vec3, xxy, Vec3, Vec3(self.x, self.x, self.y));
MemPropROExpDef(Vec3, xxz, Vec3, Vec3(self.x, self.x, self.z));
MemPropROExpDef(Vec3, xyx, Vec3, Vec3(self.x, self.y, self.x));
MemPropROExpDef(Vec3, xyy, Vec3, Vec3(self.x, self.y, self.y));
MemPropROExpDef(Vec3, xyz, Vec3, Vec3(self.x, self.y, self.z));
MemPropROExpDef(Vec3, xzx, Vec3, Vec3(self.x, self.z, self.x));
MemPropROExpDef(Vec3, xzy, Vec3, Vec3(self.x, self.z, self.y));
MemPropROExpDef(Vec3, xzz, Vec3, Vec3(self.x, self.z, self.z));
MemPropROExpDef(Vec3, yxx, Vec3, Vec3(self.y, self.x, self.x));
MemPropROExpDef(Vec3, yxy, Vec3, Vec3(self.y, self.x, self.y));
MemPropROExpDef(Vec3, yxz, Vec3, Vec3(self.y, self.x, self.z));
MemPropROExpDef(Vec3, yyx, Vec3, Vec3(self.y, self.y, self.x));
MemPropROExpDef(Vec3, yyy, Vec3, Vec3(self.y, self.y, self.y));
MemPropROExpDef(Vec3, yyz, Vec3, Vec3(self.y, self.y, self.z));
MemPropROExpDef(Vec3, yzx, Vec3, Vec3(self.y, self.z, self.x));
MemPropROExpDef(Vec3, yzy, Vec3, Vec3(self.y, self.z, self.y));
MemPropROExpDef(Vec3, yzz, Vec3, Vec3(self.y, self.z, self.z));
MemPropROExpDef(Vec3, zxx, Vec3, Vec3(self.z, self.x, self.x));
MemPropROExpDef(Vec3, zxy, Vec3, Vec3(self.z, self.x, self.y));
MemPropROExpDef(Vec3, zxz, Vec3, Vec3(self.z, self.x, self.z));
MemPropROExpDef(Vec3, zyx, Vec3, Vec3(self.z, self.y, self.x));
MemPropROExpDef(Vec3, zyy, Vec3, Vec3(self.z, self.y, self.y));
MemPropROExpDef(Vec3, zyz, Vec3, Vec3(self.z, self.y, self.z));
MemPropROExpDef(Vec3, zzx, Vec3, Vec3(self.z, self.z, self.x));
MemPropROExpDef(Vec3, zzy, Vec3, Vec3(self.z, self.z, self.y));
MemPropROExpDef(Vec3, zzz, Vec3, Vec3(self.z, self.z, self.z));

MemPropROExpDef(Vec3, xxxx, Vec4, Vec4(self.x, self.x, self.x, self.x));
MemPropROExpDef(Vec3, xxxy, Vec4, Vec4(self.x, self.x, self.x, self.y));
MemPropROExpDef(Vec3, xxxz, Vec4, Vec4(self.x, self.x, self.x, self.z));
MemPropROExpDef(Vec3, xxyx, Vec4, Vec4(self.x, self.x, self.y, self.x));
MemPropROExpDef(Vec3, xxyy, Vec4, Vec4(self.x, self.x, self.y, self.y));
MemPropROExpDef(Vec3, xxyz, Vec4, Vec4(self.x, self.x, self.y, self.z));
MemPropROExpDef(Vec3, xxzx, Vec4, Vec4(self.x, self.x, self.z, self.x));
MemPropROExpDef(Vec3, xxzy, Vec4, Vec4(self.x, self.x, self.z, self.y));
MemPropROExpDef(Vec3, xxzz, Vec4, Vec4(self.x, self.x, self.z, self.z));
MemPropROExpDef(Vec3, xyxx, Vec4, Vec4(self.x, self.y, self.x, self.x));
MemPropROExpDef(Vec3, xyxy, Vec4, Vec4(self.x, self.y, self.x, self.y));
MemPropROExpDef(Vec3, xyxz, Vec4, Vec4(self.x, self.y, self.x, self.z));
MemPropROExpDef(Vec3, xyyx, Vec4, Vec4(self.x, self.y, self.y, self.x));
MemPropROExpDef(Vec3, xyyy, Vec4, Vec4(self.x, self.y, self.y, self.y));
MemPropROExpDef(Vec3, xyyz, Vec4, Vec4(self.x, self.y, self.y, self.z));
MemPropROExpDef(Vec3, xyzx, Vec4, Vec4(self.x, self.y, self.z, self.x));
MemPropROExpDef(Vec3, xyzy, Vec4, Vec4(self.x, self.y, self.z, self.y));
MemPropROExpDef(Vec3, xyzz, Vec4, Vec4(self.x, self.y, self.z, self.z));
MemPropROExpDef(Vec3, xzxx, Vec4, Vec4(self.x, self.z, self.x, self.x));
MemPropROExpDef(Vec3, xzxy, Vec4, Vec4(self.x, self.z, self.x, self.y));
MemPropROExpDef(Vec3, xzxz, Vec4, Vec4(self.x, self.z, self.x, self.z));
MemPropROExpDef(Vec3, xzyx, Vec4, Vec4(self.x, self.z, self.y, self.x));
MemPropROExpDef(Vec3, xzyy, Vec4, Vec4(self.x, self.z, self.y, self.y));
MemPropROExpDef(Vec3, xzyz, Vec4, Vec4(self.x, self.z, self.y, self.z));
MemPropROExpDef(Vec3, xzzx, Vec4, Vec4(self.x, self.z, self.z, self.x));
MemPropROExpDef(Vec3, xzzy, Vec4, Vec4(self.x, self.z, self.z, self.y));
MemPropROExpDef(Vec3, xzzz, Vec4, Vec4(self.x, self.z, self.z, self.z));
MemPropROExpDef(Vec3, yxxx, Vec4, Vec4(self.y, self.x, self.x, self.x));
MemPropROExpDef(Vec3, yxxy, Vec4, Vec4(self.y, self.x, self.x, self.y));
MemPropROExpDef(Vec3, yxxz, Vec4, Vec4(self.y, self.x, self.x, self.z));
MemPropROExpDef(Vec3, yxyx, Vec4, Vec4(self.y, self.x, self.y, self.x));
MemPropROExpDef(Vec3, yxyy, Vec4, Vec4(self.y, self.x, self.y, self.y));
MemPropROExpDef(Vec3, yxyz, Vec4, Vec4(self.y, self.x, self.y, self.z));
MemPropROExpDef(Vec3, yxzx, Vec4, Vec4(self.y, self.x, self.z, self.x));
MemPropROExpDef(Vec3, yxzy, Vec4, Vec4(self.y, self.x, self.z, self.y));
MemPropROExpDef(Vec3, yxzz, Vec4, Vec4(self.y, self.x, self.z, self.z));
MemPropROExpDef(Vec3, yyxx, Vec4, Vec4(self.y, self.y, self.x, self.x));
MemPropROExpDef(Vec3, yyxy, Vec4, Vec4(self.y, self.y, self.x, self.y));
MemPropROExpDef(Vec3, yyxz, Vec4, Vec4(self.y, self.y, self.x, self.z));
MemPropROExpDef(Vec3, yyyx, Vec4, Vec4(self.y, self.y, self.y, self.x));
MemPropROExpDef(Vec3, yyyy, Vec4, Vec4(self.y, self.y, self.y, self.y));
MemPropROExpDef(Vec3, yyyz, Vec4, Vec4(self.y, self.y, self.y, self.z));
MemPropROExpDef(Vec3, yyzx, Vec4, Vec4(self.y, self.y, self.z, self.x));
MemPropROExpDef(Vec3, yyzy, Vec4, Vec4(self.y, self.y, self.z, self.y));
MemPropROExpDef(Vec3, yyzz, Vec4, Vec4(self.y, self.y, self.z, self.z));
MemPropROExpDef(Vec3, yzxx, Vec4, Vec4(self.y, self.z, self.x, self.x));
MemPropROExpDef(Vec3, yzxy, Vec4, Vec4(self.y, self.z, self.x, self.y));
MemPropROExpDef(Vec3, yzxz, Vec4, Vec4(self.y, self.z, self.x, self.z));
MemPropROExpDef(Vec3, yzyx, Vec4, Vec4(self.y, self.z, self.y, self.x));
MemPropROExpDef(Vec3, yzyy, Vec4, Vec4(self.y, self.z, self.y, self.y));
MemPropROExpDef(Vec3, yzyz, Vec4, Vec4(self.y, self.z, self.y, self.z));
MemPropROExpDef(Vec3, yzzx, Vec4, Vec4(self.y, self.z, self.z, self.x));
MemPropROExpDef(Vec3, yzzy, Vec4, Vec4(self.y, self.z, self.z, self.y));
MemPropROExpDef(Vec3, yzzz, Vec4, Vec4(self.y, self.z, self.z, self.z));
MemPropROExpDef(Vec3, zxxx, Vec4, Vec4(self.z, self.x, self.x, self.x));
MemPropROExpDef(Vec3, zxxy, Vec4, Vec4(self.z, self.x, self.x, self.y));
MemPropROExpDef(Vec3, zxxz, Vec4, Vec4(self.z, self.x, self.x, self.z));
MemPropROExpDef(Vec3, zxyx, Vec4, Vec4(self.z, self.x, self.y, self.x));
MemPropROExpDef(Vec3, zxyy, Vec4, Vec4(self.z, self.x, self.y, self.y));
MemPropROExpDef(Vec3, zxyz, Vec4, Vec4(self.z, self.x, self.y, self.z));
MemPropROExpDef(Vec3, zxzx, Vec4, Vec4(self.z, self.x, self.z, self.x));
MemPropROExpDef(Vec3, zxzy, Vec4, Vec4(self.z, self.x, self.z, self.y));
MemPropROExpDef(Vec3, zxzz, Vec4, Vec4(self.z, self.x, self.z, self.z));
MemPropROExpDef(Vec3, zyxx, Vec4, Vec4(self.z, self.y, self.x, self.x));
MemPropROExpDef(Vec3, zyxy, Vec4, Vec4(self.z, self.y, self.x, self.y));
MemPropROExpDef(Vec3, zyxz, Vec4, Vec4(self.z, self.y, self.x, self.z));
MemPropROExpDef(Vec3, zyyx, Vec4, Vec4(self.z, self.y, self.y, self.x));
MemPropROExpDef(Vec3, zyyy, Vec4, Vec4(self.z, self.y, self.y, self.y));
MemPropROExpDef(Vec3, zyyz, Vec4, Vec4(self.z, self.y, self.y, self.z));
MemPropROExpDef(Vec3, zyzx, Vec4, Vec4(self.z, self.y, self.z, self.x));
MemPropROExpDef(Vec3, zyzy, Vec4, Vec4(self.z, self.y, self.z, self.y));
MemPropROExpDef(Vec3, zyzz, Vec4, Vec4(self.z, self.y, self.z, self.z));
MemPropROExpDef(Vec3, zzxx, Vec4, Vec4(self.z, self.z, self.x, self.x));
MemPropROExpDef(Vec3, zzxy, Vec4, Vec4(self.z, self.z, self.x, self.y));
MemPropROExpDef(Vec3, zzxz, Vec4, Vec4(self.z, self.z, self.x, self.z));
MemPropROExpDef(Vec3, zzyx, Vec4, Vec4(self.z, self.z, self.y, self.x));
MemPropROExpDef(Vec3, zzyy, Vec4, Vec4(self.z, self.z, self.y, self.y));
MemPropROExpDef(Vec3, zzyz, Vec4, Vec4(self.z, self.z, self.y, self.z));
MemPropROExpDef(Vec3, zzzx, Vec4, Vec4(self.z, self.z, self.z, self.x));
MemPropROExpDef(Vec3, zzzy, Vec4, Vec4(self.z, self.z, self.z, self.y));
MemPropROExpDef(Vec3, zzzz, Vec4, Vec4(self.z, self.z, self.z, self.z));

MemPropROExpDef(Vec4, xx, Vec2, Vec2(self.x, self.x));
MemPropROExpDef(Vec4, xy, Vec2, Vec2(self.x, self.y));
MemPropROExpDef(Vec4, xz, Vec2, Vec2(self.x, self.z));
MemPropROExpDef(Vec4, xw, Vec2, Vec2(self.x, self.w));
MemPropROExpDef(Vec4, yx, Vec2, Vec2(self.y, self.x));
MemPropROExpDef(Vec4, yy, Vec2, Vec2(self.y, self.y));
MemPropROExpDef(Vec4, yz, Vec2, Vec2(self.y, self.z));
MemPropROExpDef(Vec4, yw, Vec2, Vec2(self.y, self.w));
MemPropROExpDef(Vec4, zx, Vec2, Vec2(self.z, self.x));
MemPropROExpDef(Vec4, zy, Vec2, Vec2(self.z, self.y));
MemPropROExpDef(Vec4, zz, Vec2, Vec2(self.z, self.z));
MemPropROExpDef(Vec4, zw, Vec2, Vec2(self.z, self.w));
MemPropROExpDef(Vec4, wx, Vec2, Vec2(self.w, self.x));
MemPropROExpDef(Vec4, wy, Vec2, Vec2(self.w, self.y));
MemPropROExpDef(Vec4, wz, Vec2, Vec2(self.w, self.z));
MemPropROExpDef(Vec4, ww, Vec2, Vec2(self.w, self.w));

MemPropROExpDef(Vec4, xxx, Vec3, Vec3(self.x, self.x, self.x));
MemPropROExpDef(Vec4, xxy, Vec3, Vec3(self.x, self.x, self.y));
MemPropROExpDef(Vec4, xxz, Vec3, Vec3(self.x, self.x, self.z));
MemPropROExpDef(Vec4, xxw, Vec3, Vec3(self.x, self.x, self.w));
MemPropROExpDef(Vec4, xyx, Vec3, Vec3(self.x, self.y, self.x));
MemPropROExpDef(Vec4, xyy, Vec3, Vec3(self.x, self.y, self.y));
MemPropROExpDef(Vec4, xyz, Vec3, Vec3(self.x, self.y, self.z));
MemPropROExpDef(Vec4, xyw, Vec3, Vec3(self.x, self.y, self.w));
MemPropROExpDef(Vec4, xzx, Vec3, Vec3(self.x, self.z, self.x));
MemPropROExpDef(Vec4, xzy, Vec3, Vec3(self.x, self.z, self.y));
MemPropROExpDef(Vec4, xzz, Vec3, Vec3(self.x, self.z, self.z));
MemPropROExpDef(Vec4, xzw, Vec3, Vec3(self.x, self.z, self.w));
MemPropROExpDef(Vec4, xwx, Vec3, Vec3(self.x, self.w, self.x));
MemPropROExpDef(Vec4, xwy, Vec3, Vec3(self.x, self.w, self.y));
MemPropROExpDef(Vec4, xwz, Vec3, Vec3(self.x, self.w, self.z));
MemPropROExpDef(Vec4, xww, Vec3, Vec3(self.x, self.w, self.w));
MemPropROExpDef(Vec4, yxx, Vec3, Vec3(self.y, self.x, self.x));
MemPropROExpDef(Vec4, yxy, Vec3, Vec3(self.y, self.x, self.y));
MemPropROExpDef(Vec4, yxz, Vec3, Vec3(self.y, self.x, self.z));
MemPropROExpDef(Vec4, yxw, Vec3, Vec3(self.y, self.x, self.w));
MemPropROExpDef(Vec4, yyx, Vec3, Vec3(self.y, self.y, self.x));
MemPropROExpDef(Vec4, yyy, Vec3, Vec3(self.y, self.y, self.y));
MemPropROExpDef(Vec4, yyz, Vec3, Vec3(self.y, self.y, self.z));
MemPropROExpDef(Vec4, yyw, Vec3, Vec3(self.y, self.y, self.w));
MemPropROExpDef(Vec4, yzx, Vec3, Vec3(self.y, self.z, self.x));
MemPropROExpDef(Vec4, yzy, Vec3, Vec3(self.y, self.z, self.y));
MemPropROExpDef(Vec4, yzz, Vec3, Vec3(self.y, self.z, self.z));
MemPropROExpDef(Vec4, yzw, Vec3, Vec3(self.y, self.z, self.w));
MemPropROExpDef(Vec4, ywx, Vec3, Vec3(self.y, self.w, self.x));
MemPropROExpDef(Vec4, ywy, Vec3, Vec3(self.y, self.w, self.y));
MemPropROExpDef(Vec4, ywz, Vec3, Vec3(self.y, self.w, self.z));
MemPropROExpDef(Vec4, yww, Vec3, Vec3(self.y, self.w, self.w));
MemPropROExpDef(Vec4, zxx, Vec3, Vec3(self.z, self.x, self.x));
MemPropROExpDef(Vec4, zxy, Vec3, Vec3(self.z, self.x, self.y));
MemPropROExpDef(Vec4, zxz, Vec3, Vec3(self.z, self.x, self.z));
MemPropROExpDef(Vec4, zxw, Vec3, Vec3(self.z, self.x, self.w));
MemPropROExpDef(Vec4, zyx, Vec3, Vec3(self.z, self.y, self.x));
MemPropROExpDef(Vec4, zyy, Vec3, Vec3(self.z, self.y, self.y));
MemPropROExpDef(Vec4, zyz, Vec3, Vec3(self.z, self.y, self.z));
MemPropROExpDef(Vec4, zyw, Vec3, Vec3(self.z, self.y, self.w));
MemPropROExpDef(Vec4, zzx, Vec3, Vec3(self.z, self.z, self.x));
MemPropROExpDef(Vec4, zzy, Vec3, Vec3(self.z, self.z, self.y));
MemPropROExpDef(Vec4, zzz, Vec3, Vec3(self.z, self.z, self.z));
MemPropROExpDef(Vec4, zzw, Vec3, Vec3(self.z, self.z, self.w));
MemPropROExpDef(Vec4, zwx, Vec3, Vec3(self.z, self.w, self.x));
MemPropROExpDef(Vec4, zwy, Vec3, Vec3(self.z, self.w, self.y));
MemPropROExpDef(Vec4, zwz, Vec3, Vec3(self.z, self.w, self.z));
MemPropROExpDef(Vec4, zww, Vec3, Vec3(self.z, self.w, self.w));
MemPropROExpDef(Vec4, wxx, Vec3, Vec3(self.w, self.x, self.x));
MemPropROExpDef(Vec4, wxy, Vec3, Vec3(self.w, self.x, self.y));
MemPropROExpDef(Vec4, wxz, Vec3, Vec3(self.w, self.x, self.z));
MemPropROExpDef(Vec4, wxw, Vec3, Vec3(self.w, self.x, self.w));
MemPropROExpDef(Vec4, wyx, Vec3, Vec3(self.w, self.y, self.x));
MemPropROExpDef(Vec4, wyy, Vec3, Vec3(self.w, self.y, self.y));
MemPropROExpDef(Vec4, wyz, Vec3, Vec3(self.w, self.y, self.z));
MemPropROExpDef(Vec4, wyw, Vec3, Vec3(self.w, self.y, self.w));
MemPropROExpDef(Vec4, wzx, Vec3, Vec3(self.w, self.z, self.x));
MemPropROExpDef(Vec4, wzy, Vec3, Vec3(self.w, self.z, self.y));
MemPropROExpDef(Vec4, wzz, Vec3, Vec3(self.w, self.z, self.z));
MemPropROExpDef(Vec4, wzw, Vec3, Vec3(self.w, self.z, self.w));
MemPropROExpDef(Vec4, wwx, Vec3, Vec3(self.w, self.w, self.x));
MemPropROExpDef(Vec4, wwy, Vec3, Vec3(self.w, self.w, self.y));
MemPropROExpDef(Vec4, wwz, Vec3, Vec3(self.w, self.w, self.z));
MemPropROExpDef(Vec4, www, Vec3, Vec3(self.w, self.w, self.w));

MemPropROExpDef(Vec4, xxxx, Vec4, Vec4(self.x, self.x, self.x, self.x));
MemPropROExpDef(Vec4, xxxy, Vec4, Vec4(self.x, self.x, self.x, self.y));
MemPropROExpDef(Vec4, xxxz, Vec4, Vec4(self.x, self.x, self.x, self.z));
MemPropROExpDef(Vec4, xxxw, Vec4, Vec4(self.x, self.x, self.x, self.w));
MemPropROExpDef(Vec4, xxyx, Vec4, Vec4(self.x, self.x, self.y, self.x));
MemPropROExpDef(Vec4, xxyy, Vec4, Vec4(self.x, self.x, self.y, self.y));
MemPropROExpDef(Vec4, xxyz, Vec4, Vec4(self.x, self.x, self.y, self.z));
MemPropROExpDef(Vec4, xxyw, Vec4, Vec4(self.x, self.x, self.y, self.w));
MemPropROExpDef(Vec4, xxzx, Vec4, Vec4(self.x, self.x, self.z, self.x));
MemPropROExpDef(Vec4, xxzy, Vec4, Vec4(self.x, self.x, self.z, self.y));
MemPropROExpDef(Vec4, xxzz, Vec4, Vec4(self.x, self.x, self.z, self.z));
MemPropROExpDef(Vec4, xxzw, Vec4, Vec4(self.x, self.x, self.z, self.w));
MemPropROExpDef(Vec4, xxwx, Vec4, Vec4(self.x, self.x, self.w, self.x));
MemPropROExpDef(Vec4, xxwy, Vec4, Vec4(self.x, self.x, self.w, self.y));
MemPropROExpDef(Vec4, xxwz, Vec4, Vec4(self.x, self.x, self.w, self.z));
MemPropROExpDef(Vec4, xxww, Vec4, Vec4(self.x, self.x, self.w, self.w));
MemPropROExpDef(Vec4, xyxx, Vec4, Vec4(self.x, self.y, self.x, self.x));
MemPropROExpDef(Vec4, xyxy, Vec4, Vec4(self.x, self.y, self.x, self.y));
MemPropROExpDef(Vec4, xyxz, Vec4, Vec4(self.x, self.y, self.x, self.z));
MemPropROExpDef(Vec4, xyxw, Vec4, Vec4(self.x, self.y, self.x, self.w));
MemPropROExpDef(Vec4, xyyx, Vec4, Vec4(self.x, self.y, self.y, self.x));
MemPropROExpDef(Vec4, xyyy, Vec4, Vec4(self.x, self.y, self.y, self.y));
MemPropROExpDef(Vec4, xyyz, Vec4, Vec4(self.x, self.y, self.y, self.z));
MemPropROExpDef(Vec4, xyyw, Vec4, Vec4(self.x, self.y, self.y, self.w));
MemPropROExpDef(Vec4, xyzx, Vec4, Vec4(self.x, self.y, self.z, self.x));
MemPropROExpDef(Vec4, xyzy, Vec4, Vec4(self.x, self.y, self.z, self.y));
MemPropROExpDef(Vec4, xyzz, Vec4, Vec4(self.x, self.y, self.z, self.z));
MemPropROExpDef(Vec4, xyzw, Vec4, Vec4(self.x, self.y, self.z, self.w));
MemPropROExpDef(Vec4, xywx, Vec4, Vec4(self.x, self.y, self.w, self.x));
MemPropROExpDef(Vec4, xywy, Vec4, Vec4(self.x, self.y, self.w, self.y));
MemPropROExpDef(Vec4, xywz, Vec4, Vec4(self.x, self.y, self.w, self.z));
MemPropROExpDef(Vec4, xyww, Vec4, Vec4(self.x, self.y, self.w, self.w));
MemPropROExpDef(Vec4, xzxx, Vec4, Vec4(self.x, self.z, self.x, self.x));
MemPropROExpDef(Vec4, xzxy, Vec4, Vec4(self.x, self.z, self.x, self.y));
MemPropROExpDef(Vec4, xzxz, Vec4, Vec4(self.x, self.z, self.x, self.z));
MemPropROExpDef(Vec4, xzxw, Vec4, Vec4(self.x, self.z, self.x, self.w));
MemPropROExpDef(Vec4, xzyx, Vec4, Vec4(self.x, self.z, self.y, self.x));
MemPropROExpDef(Vec4, xzyy, Vec4, Vec4(self.x, self.z, self.y, self.y));
MemPropROExpDef(Vec4, xzyz, Vec4, Vec4(self.x, self.z, self.y, self.z));
MemPropROExpDef(Vec4, xzyw, Vec4, Vec4(self.x, self.z, self.y, self.w));
MemPropROExpDef(Vec4, xzzx, Vec4, Vec4(self.x, self.z, self.z, self.x));
MemPropROExpDef(Vec4, xzzy, Vec4, Vec4(self.x, self.z, self.z, self.y));
MemPropROExpDef(Vec4, xzzz, Vec4, Vec4(self.x, self.z, self.z, self.z));
MemPropROExpDef(Vec4, xzzw, Vec4, Vec4(self.x, self.z, self.z, self.w));
MemPropROExpDef(Vec4, xzwx, Vec4, Vec4(self.x, self.z, self.w, self.x));
MemPropROExpDef(Vec4, xzwy, Vec4, Vec4(self.x, self.z, self.w, self.y));
MemPropROExpDef(Vec4, xzwz, Vec4, Vec4(self.x, self.z, self.w, self.z));
MemPropROExpDef(Vec4, xzww, Vec4, Vec4(self.x, self.z, self.w, self.w));
MemPropROExpDef(Vec4, xwxx, Vec4, Vec4(self.x, self.w, self.x, self.x));
MemPropROExpDef(Vec4, xwxy, Vec4, Vec4(self.x, self.w, self.x, self.y));
MemPropROExpDef(Vec4, xwxz, Vec4, Vec4(self.x, self.w, self.x, self.z));
MemPropROExpDef(Vec4, xwxw, Vec4, Vec4(self.x, self.w, self.x, self.w));
MemPropROExpDef(Vec4, xwyx, Vec4, Vec4(self.x, self.w, self.y, self.x));
MemPropROExpDef(Vec4, xwyy, Vec4, Vec4(self.x, self.w, self.y, self.y));
MemPropROExpDef(Vec4, xwyz, Vec4, Vec4(self.x, self.w, self.y, self.z));
MemPropROExpDef(Vec4, xwyw, Vec4, Vec4(self.x, self.w, self.y, self.w));
MemPropROExpDef(Vec4, xwzx, Vec4, Vec4(self.x, self.w, self.z, self.x));
MemPropROExpDef(Vec4, xwzy, Vec4, Vec4(self.x, self.w, self.z, self.y));
MemPropROExpDef(Vec4, xwzz, Vec4, Vec4(self.x, self.w, self.z, self.z));
MemPropROExpDef(Vec4, xwzw, Vec4, Vec4(self.x, self.w, self.z, self.w));
MemPropROExpDef(Vec4, xwwx, Vec4, Vec4(self.x, self.w, self.w, self.x));
MemPropROExpDef(Vec4, xwwy, Vec4, Vec4(self.x, self.w, self.w, self.y));
MemPropROExpDef(Vec4, xwwz, Vec4, Vec4(self.x, self.w, self.w, self.z));
MemPropROExpDef(Vec4, xwww, Vec4, Vec4(self.x, self.w, self.w, self.w));
MemPropROExpDef(Vec4, yxxx, Vec4, Vec4(self.y, self.x, self.x, self.x));
MemPropROExpDef(Vec4, yxxy, Vec4, Vec4(self.y, self.x, self.x, self.y));
MemPropROExpDef(Vec4, yxxz, Vec4, Vec4(self.y, self.x, self.x, self.z));
MemPropROExpDef(Vec4, yxxw, Vec4, Vec4(self.y, self.x, self.x, self.w));
MemPropROExpDef(Vec4, yxyx, Vec4, Vec4(self.y, self.x, self.y, self.x));
MemPropROExpDef(Vec4, yxyy, Vec4, Vec4(self.y, self.x, self.y, self.y));
MemPropROExpDef(Vec4, yxyz, Vec4, Vec4(self.y, self.x, self.y, self.z));
MemPropROExpDef(Vec4, yxyw, Vec4, Vec4(self.y, self.x, self.y, self.w));
MemPropROExpDef(Vec4, yxzx, Vec4, Vec4(self.y, self.x, self.z, self.x));
MemPropROExpDef(Vec4, yxzy, Vec4, Vec4(self.y, self.x, self.z, self.y));
MemPropROExpDef(Vec4, yxzz, Vec4, Vec4(self.y, self.x, self.z, self.z));
MemPropROExpDef(Vec4, yxzw, Vec4, Vec4(self.y, self.x, self.z, self.w));
MemPropROExpDef(Vec4, yxwx, Vec4, Vec4(self.y, self.x, self.w, self.x));
MemPropROExpDef(Vec4, yxwy, Vec4, Vec4(self.y, self.x, self.w, self.y));
MemPropROExpDef(Vec4, yxwz, Vec4, Vec4(self.y, self.x, self.w, self.z));
MemPropROExpDef(Vec4, yxww, Vec4, Vec4(self.y, self.x, self.w, self.w));
MemPropROExpDef(Vec4, yyxx, Vec4, Vec4(self.y, self.y, self.x, self.x));
MemPropROExpDef(Vec4, yyxy, Vec4, Vec4(self.y, self.y, self.x, self.y));
MemPropROExpDef(Vec4, yyxz, Vec4, Vec4(self.y, self.y, self.x, self.z));
MemPropROExpDef(Vec4, yyxw, Vec4, Vec4(self.y, self.y, self.x, self.w));
MemPropROExpDef(Vec4, yyyx, Vec4, Vec4(self.y, self.y, self.y, self.x));
MemPropROExpDef(Vec4, yyyy, Vec4, Vec4(self.y, self.y, self.y, self.y));
MemPropROExpDef(Vec4, yyyz, Vec4, Vec4(self.y, self.y, self.y, self.z));
MemPropROExpDef(Vec4, yyyw, Vec4, Vec4(self.y, self.y, self.y, self.w));
MemPropROExpDef(Vec4, yyzx, Vec4, Vec4(self.y, self.y, self.z, self.x));
MemPropROExpDef(Vec4, yyzy, Vec4, Vec4(self.y, self.y, self.z, self.y));
MemPropROExpDef(Vec4, yyzz, Vec4, Vec4(self.y, self.y, self.z, self.z));
MemPropROExpDef(Vec4, yyzw, Vec4, Vec4(self.y, self.y, self.z, self.w));
MemPropROExpDef(Vec4, yywx, Vec4, Vec4(self.y, self.y, self.w, self.x));
MemPropROExpDef(Vec4, yywy, Vec4, Vec4(self.y, self.y, self.w, self.y));
MemPropROExpDef(Vec4, yywz, Vec4, Vec4(self.y, self.y, self.w, self.z));
MemPropROExpDef(Vec4, yyww, Vec4, Vec4(self.y, self.y, self.w, self.w));
MemPropROExpDef(Vec4, yzxx, Vec4, Vec4(self.y, self.z, self.x, self.x));
MemPropROExpDef(Vec4, yzxy, Vec4, Vec4(self.y, self.z, self.x, self.y));
MemPropROExpDef(Vec4, yzxz, Vec4, Vec4(self.y, self.z, self.x, self.z));
MemPropROExpDef(Vec4, yzxw, Vec4, Vec4(self.y, self.z, self.x, self.w));
MemPropROExpDef(Vec4, yzyx, Vec4, Vec4(self.y, self.z, self.y, self.x));
MemPropROExpDef(Vec4, yzyy, Vec4, Vec4(self.y, self.z, self.y, self.y));
MemPropROExpDef(Vec4, yzyz, Vec4, Vec4(self.y, self.z, self.y, self.z));
MemPropROExpDef(Vec4, yzyw, Vec4, Vec4(self.y, self.z, self.y, self.w));
MemPropROExpDef(Vec4, yzzx, Vec4, Vec4(self.y, self.z, self.z, self.x));
MemPropROExpDef(Vec4, yzzy, Vec4, Vec4(self.y, self.z, self.z, self.y));
MemPropROExpDef(Vec4, yzzz, Vec4, Vec4(self.y, self.z, self.z, self.z));
MemPropROExpDef(Vec4, yzzw, Vec4, Vec4(self.y, self.z, self.z, self.w));
MemPropROExpDef(Vec4, yzwx, Vec4, Vec4(self.y, self.z, self.w, self.x));
MemPropROExpDef(Vec4, yzwy, Vec4, Vec4(self.y, self.z, self.w, self.y));
MemPropROExpDef(Vec4, yzwz, Vec4, Vec4(self.y, self.z, self.w, self.z));
MemPropROExpDef(Vec4, yzww, Vec4, Vec4(self.y, self.z, self.w, self.w));
MemPropROExpDef(Vec4, ywxx, Vec4, Vec4(self.y, self.w, self.x, self.x));
MemPropROExpDef(Vec4, ywxy, Vec4, Vec4(self.y, self.w, self.x, self.y));
MemPropROExpDef(Vec4, ywxz, Vec4, Vec4(self.y, self.w, self.x, self.z));
MemPropROExpDef(Vec4, ywxw, Vec4, Vec4(self.y, self.w, self.x, self.w));
MemPropROExpDef(Vec4, ywyx, Vec4, Vec4(self.y, self.w, self.y, self.x));
MemPropROExpDef(Vec4, ywyy, Vec4, Vec4(self.y, self.w, self.y, self.y));
MemPropROExpDef(Vec4, ywyz, Vec4, Vec4(self.y, self.w, self.y, self.z));
MemPropROExpDef(Vec4, ywyw, Vec4, Vec4(self.y, self.w, self.y, self.w));
MemPropROExpDef(Vec4, ywzx, Vec4, Vec4(self.y, self.w, self.z, self.x));
MemPropROExpDef(Vec4, ywzy, Vec4, Vec4(self.y, self.w, self.z, self.y));
MemPropROExpDef(Vec4, ywzz, Vec4, Vec4(self.y, self.w, self.z, self.z));
MemPropROExpDef(Vec4, ywzw, Vec4, Vec4(self.y, self.w, self.z, self.w));
MemPropROExpDef(Vec4, ywwx, Vec4, Vec4(self.y, self.w, self.w, self.x));
MemPropROExpDef(Vec4, ywwy, Vec4, Vec4(self.y, self.w, self.w, self.y));
MemPropROExpDef(Vec4, ywwz, Vec4, Vec4(self.y, self.w, self.w, self.z));
MemPropROExpDef(Vec4, ywww, Vec4, Vec4(self.y, self.w, self.w, self.w));
MemPropROExpDef(Vec4, zxxx, Vec4, Vec4(self.z, self.x, self.x, self.x));
MemPropROExpDef(Vec4, zxxy, Vec4, Vec4(self.z, self.x, self.x, self.y));
MemPropROExpDef(Vec4, zxxz, Vec4, Vec4(self.z, self.x, self.x, self.z));
MemPropROExpDef(Vec4, zxxw, Vec4, Vec4(self.z, self.x, self.x, self.w));
MemPropROExpDef(Vec4, zxyx, Vec4, Vec4(self.z, self.x, self.y, self.x));
MemPropROExpDef(Vec4, zxyy, Vec4, Vec4(self.z, self.x, self.y, self.y));
MemPropROExpDef(Vec4, zxyz, Vec4, Vec4(self.z, self.x, self.y, self.z));
MemPropROExpDef(Vec4, zxyw, Vec4, Vec4(self.z, self.x, self.y, self.w));
MemPropROExpDef(Vec4, zxzx, Vec4, Vec4(self.z, self.x, self.z, self.x));
MemPropROExpDef(Vec4, zxzy, Vec4, Vec4(self.z, self.x, self.z, self.y));
MemPropROExpDef(Vec4, zxzz, Vec4, Vec4(self.z, self.x, self.z, self.z));
MemPropROExpDef(Vec4, zxzw, Vec4, Vec4(self.z, self.x, self.z, self.w));
MemPropROExpDef(Vec4, zxwx, Vec4, Vec4(self.z, self.x, self.w, self.x));
MemPropROExpDef(Vec4, zxwy, Vec4, Vec4(self.z, self.x, self.w, self.y));
MemPropROExpDef(Vec4, zxwz, Vec4, Vec4(self.z, self.x, self.w, self.z));
MemPropROExpDef(Vec4, zxww, Vec4, Vec4(self.z, self.x, self.w, self.w));
MemPropROExpDef(Vec4, zyxx, Vec4, Vec4(self.z, self.y, self.x, self.x));
MemPropROExpDef(Vec4, zyxy, Vec4, Vec4(self.z, self.y, self.x, self.y));
MemPropROExpDef(Vec4, zyxz, Vec4, Vec4(self.z, self.y, self.x, self.z));
MemPropROExpDef(Vec4, zyxw, Vec4, Vec4(self.z, self.y, self.x, self.w));
MemPropROExpDef(Vec4, zyyx, Vec4, Vec4(self.z, self.y, self.y, self.x));
MemPropROExpDef(Vec4, zyyy, Vec4, Vec4(self.z, self.y, self.y, self.y));
MemPropROExpDef(Vec4, zyyz, Vec4, Vec4(self.z, self.y, self.y, self.z));
MemPropROExpDef(Vec4, zyyw, Vec4, Vec4(self.z, self.y, self.y, self.w));
MemPropROExpDef(Vec4, zyzx, Vec4, Vec4(self.z, self.y, self.z, self.x));
MemPropROExpDef(Vec4, zyzy, Vec4, Vec4(self.z, self.y, self.z, self.y));
MemPropROExpDef(Vec4, zyzz, Vec4, Vec4(self.z, self.y, self.z, self.z));
MemPropROExpDef(Vec4, zyzw, Vec4, Vec4(self.z, self.y, self.z, self.w));
MemPropROExpDef(Vec4, zywx, Vec4, Vec4(self.z, self.y, self.w, self.x));
MemPropROExpDef(Vec4, zywy, Vec4, Vec4(self.z, self.y, self.w, self.y));
MemPropROExpDef(Vec4, zywz, Vec4, Vec4(self.z, self.y, self.w, self.z));
MemPropROExpDef(Vec4, zyww, Vec4, Vec4(self.z, self.y, self.w, self.w));
MemPropROExpDef(Vec4, zzxx, Vec4, Vec4(self.z, self.z, self.x, self.x));
MemPropROExpDef(Vec4, zzxy, Vec4, Vec4(self.z, self.z, self.x, self.y));
MemPropROExpDef(Vec4, zzxz, Vec4, Vec4(self.z, self.z, self.x, self.z));
MemPropROExpDef(Vec4, zzxw, Vec4, Vec4(self.z, self.z, self.x, self.w));
MemPropROExpDef(Vec4, zzyx, Vec4, Vec4(self.z, self.z, self.y, self.x));
MemPropROExpDef(Vec4, zzyy, Vec4, Vec4(self.z, self.z, self.y, self.y));
MemPropROExpDef(Vec4, zzyz, Vec4, Vec4(self.z, self.z, self.y, self.z));
MemPropROExpDef(Vec4, zzyw, Vec4, Vec4(self.z, self.z, self.y, self.w));
MemPropROExpDef(Vec4, zzzx, Vec4, Vec4(self.z, self.z, self.z, self.x));
MemPropROExpDef(Vec4, zzzy, Vec4, Vec4(self.z, self.z, self.z, self.y));
MemPropROExpDef(Vec4, zzzz, Vec4, Vec4(self.z, self.z, self.z, self.z));
MemPropROExpDef(Vec4, zzzw, Vec4, Vec4(self.z, self.z, self.z, self.w));
MemPropROExpDef(Vec4, zzwx, Vec4, Vec4(self.z, self.z, self.w, self.x));
MemPropROExpDef(Vec4, zzwy, Vec4, Vec4(self.z, self.z, self.w, self.y));
MemPropROExpDef(Vec4, zzwz, Vec4, Vec4(self.z, self.z, self.w, self.z));
MemPropROExpDef(Vec4, zzww, Vec4, Vec4(self.z, self.z, self.w, self.w));
MemPropROExpDef(Vec4, zwxx, Vec4, Vec4(self.z, self.w, self.x, self.x));
MemPropROExpDef(Vec4, zwxy, Vec4, Vec4(self.z, self.w, self.x, self.y));
MemPropROExpDef(Vec4, zwxz, Vec4, Vec4(self.z, self.w, self.x, self.z));
MemPropROExpDef(Vec4, zwxw, Vec4, Vec4(self.z, self.w, self.x, self.w));
MemPropROExpDef(Vec4, zwyx, Vec4, Vec4(self.z, self.w, self.y, self.x));
MemPropROExpDef(Vec4, zwyy, Vec4, Vec4(self.z, self.w, self.y, self.y));
MemPropROExpDef(Vec4, zwyz, Vec4, Vec4(self.z, self.w, self.y, self.z));
MemPropROExpDef(Vec4, zwyw, Vec4, Vec4(self.z, self.w, self.y, self.w));
MemPropROExpDef(Vec4, zwzx, Vec4, Vec4(self.z, self.w, self.z, self.x));
MemPropROExpDef(Vec4, zwzy, Vec4, Vec4(self.z, self.w, self.z, self.y));
MemPropROExpDef(Vec4, zwzz, Vec4, Vec4(self.z, self.w, self.z, self.z));
MemPropROExpDef(Vec4, zwzw, Vec4, Vec4(self.z, self.w, self.z, self.w));
MemPropROExpDef(Vec4, zwwx, Vec4, Vec4(self.z, self.w, self.w, self.x));
MemPropROExpDef(Vec4, zwwy, Vec4, Vec4(self.z, self.w, self.w, self.y));
MemPropROExpDef(Vec4, zwwz, Vec4, Vec4(self.z, self.w, self.w, self.z));
MemPropROExpDef(Vec4, zwww, Vec4, Vec4(self.z, self.w, self.w, self.w));
MemPropROExpDef(Vec4, wxxx, Vec4, Vec4(self.w, self.x, self.x, self.x));
MemPropROExpDef(Vec4, wxxy, Vec4, Vec4(self.w, self.x, self.x, self.y));
MemPropROExpDef(Vec4, wxxz, Vec4, Vec4(self.w, self.x, self.x, self.z));
MemPropROExpDef(Vec4, wxxw, Vec4, Vec4(self.w, self.x, self.x, self.w));
MemPropROExpDef(Vec4, wxyx, Vec4, Vec4(self.w, self.x, self.y, self.x));
MemPropROExpDef(Vec4, wxyy, Vec4, Vec4(self.w, self.x, self.y, self.y));
MemPropROExpDef(Vec4, wxyz, Vec4, Vec4(self.w, self.x, self.y, self.z));
MemPropROExpDef(Vec4, wxyw, Vec4, Vec4(self.w, self.x, self.y, self.w));
MemPropROExpDef(Vec4, wxzx, Vec4, Vec4(self.w, self.x, self.z, self.x));
MemPropROExpDef(Vec4, wxzy, Vec4, Vec4(self.w, self.x, self.z, self.y));
MemPropROExpDef(Vec4, wxzz, Vec4, Vec4(self.w, self.x, self.z, self.z));
MemPropROExpDef(Vec4, wxzw, Vec4, Vec4(self.w, self.x, self.z, self.w));
MemPropROExpDef(Vec4, wxwx, Vec4, Vec4(self.w, self.x, self.w, self.x));
MemPropROExpDef(Vec4, wxwy, Vec4, Vec4(self.w, self.x, self.w, self.y));
MemPropROExpDef(Vec4, wxwz, Vec4, Vec4(self.w, self.x, self.w, self.z));
MemPropROExpDef(Vec4, wxww, Vec4, Vec4(self.w, self.x, self.w, self.w));
MemPropROExpDef(Vec4, wyxx, Vec4, Vec4(self.w, self.y, self.x, self.x));
MemPropROExpDef(Vec4, wyxy, Vec4, Vec4(self.w, self.y, self.x, self.y));
MemPropROExpDef(Vec4, wyxz, Vec4, Vec4(self.w, self.y, self.x, self.z));
MemPropROExpDef(Vec4, wyxw, Vec4, Vec4(self.w, self.y, self.x, self.w));
MemPropROExpDef(Vec4, wyyx, Vec4, Vec4(self.w, self.y, self.y, self.x));
MemPropROExpDef(Vec4, wyyy, Vec4, Vec4(self.w, self.y, self.y, self.y));
MemPropROExpDef(Vec4, wyyz, Vec4, Vec4(self.w, self.y, self.y, self.z));
MemPropROExpDef(Vec4, wyyw, Vec4, Vec4(self.w, self.y, self.y, self.w));
MemPropROExpDef(Vec4, wyzx, Vec4, Vec4(self.w, self.y, self.z, self.x));
MemPropROExpDef(Vec4, wyzy, Vec4, Vec4(self.w, self.y, self.z, self.y));
MemPropROExpDef(Vec4, wyzz, Vec4, Vec4(self.w, self.y, self.z, self.z));
MemPropROExpDef(Vec4, wyzw, Vec4, Vec4(self.w, self.y, self.z, self.w));
MemPropROExpDef(Vec4, wywx, Vec4, Vec4(self.w, self.y, self.w, self.x));
MemPropROExpDef(Vec4, wywy, Vec4, Vec4(self.w, self.y, self.w, self.y));
MemPropROExpDef(Vec4, wywz, Vec4, Vec4(self.w, self.y, self.w, self.z));
MemPropROExpDef(Vec4, wyww, Vec4, Vec4(self.w, self.y, self.w, self.w));
MemPropROExpDef(Vec4, wzxx, Vec4, Vec4(self.w, self.z, self.x, self.x));
MemPropROExpDef(Vec4, wzxy, Vec4, Vec4(self.w, self.z, self.x, self.y));
MemPropROExpDef(Vec4, wzxz, Vec4, Vec4(self.w, self.z, self.x, self.z));
MemPropROExpDef(Vec4, wzxw, Vec4, Vec4(self.w, self.z, self.x, self.w));
MemPropROExpDef(Vec4, wzyx, Vec4, Vec4(self.w, self.z, self.y, self.x));
MemPropROExpDef(Vec4, wzyy, Vec4, Vec4(self.w, self.z, self.y, self.y));
MemPropROExpDef(Vec4, wzyz, Vec4, Vec4(self.w, self.z, self.y, self.z));
MemPropROExpDef(Vec4, wzyw, Vec4, Vec4(self.w, self.z, self.y, self.w));
MemPropROExpDef(Vec4, wzzx, Vec4, Vec4(self.w, self.z, self.z, self.x));
MemPropROExpDef(Vec4, wzzy, Vec4, Vec4(self.w, self.z, self.z, self.y));
MemPropROExpDef(Vec4, wzzz, Vec4, Vec4(self.w, self.z, self.z, self.z));
MemPropROExpDef(Vec4, wzzw, Vec4, Vec4(self.w, self.z, self.z, self.w));
MemPropROExpDef(Vec4, wzwx, Vec4, Vec4(self.w, self.z, self.w, self.x));
MemPropROExpDef(Vec4, wzwy, Vec4, Vec4(self.w, self.z, self.w, self.y));
MemPropROExpDef(Vec4, wzwz, Vec4, Vec4(self.w, self.z, self.w, self.z));
MemPropROExpDef(Vec4, wzww, Vec4, Vec4(self.w, self.z, self.w, self.w));
MemPropROExpDef(Vec4, wwxx, Vec4, Vec4(self.w, self.w, self.x, self.x));
MemPropROExpDef(Vec4, wwxy, Vec4, Vec4(self.w, self.w, self.x, self.y));
MemPropROExpDef(Vec4, wwxz, Vec4, Vec4(self.w, self.w, self.x, self.z));
MemPropROExpDef(Vec4, wwxw, Vec4, Vec4(self.w, self.w, self.x, self.w));
MemPropROExpDef(Vec4, wwyx, Vec4, Vec4(self.w, self.w, self.y, self.x));
MemPropROExpDef(Vec4, wwyy, Vec4, Vec4(self.w, self.w, self.y, self.y));
MemPropROExpDef(Vec4, wwyz, Vec4, Vec4(self.w, self.w, self.y, self.z));
MemPropROExpDef(Vec4, wwyw, Vec4, Vec4(self.w, self.w, self.y, self.w));
MemPropROExpDef(Vec4, wwzx, Vec4, Vec4(self.w, self.w, self.z, self.x));
MemPropROExpDef(Vec4, wwzy, Vec4, Vec4(self.w, self.w, self.z, self.y));
MemPropROExpDef(Vec4, wwzz, Vec4, Vec4(self.w, self.w, self.z, self.z));
MemPropROExpDef(Vec4, wwzw, Vec4, Vec4(self.w, self.w, self.z, self.w));
MemPropROExpDef(Vec4, wwwx, Vec4, Vec4(self.w, self.w, self.w, self.x));
MemPropROExpDef(Vec4, wwwy, Vec4, Vec4(self.w, self.w, self.w, self.y));
MemPropROExpDef(Vec4, wwwz, Vec4, Vec4(self.w, self.w, self.w, self.z));
MemPropROExpDef(Vec4, wwww, Vec4, Vec4(self.w, self.w, self.w, self.w));

template <typename Fn> Vec2 fore(Vec2 v, Fn fn) { return Vec2(fn(v.x), fn(v.y)); }
template <typename Fn> Vec3 fore(Vec3 v, Fn fn) { return Vec3(fn(v.x), fn(v.y), fn(v.z)); }
template <typename Fn> Vec4 fore(Vec4 v, Fn fn) { return Vec4(fn(v.x), fn(v.y), fn(v.z), fn(v.w)); }

template <typename Fn> Vec2 fore(Vec2 a, Vec2 b, Fn fn) { return Vec2(fn(a.x, b.x), fn(a.y, b.y)); }
template <typename Fn> Vec3 fore(Vec3 a, Vec3 b, Fn fn) { return Vec3(fn(a.x, b.x), fn(a.y, b.y), fn(a.z, b.z)); }
template <typename Fn> Vec4 fore(Vec4 a, Vec4 b, Fn fn) { return Vec4(fn(a.x, b.x), fn(a.y, b.y), fn(a.z, b.z), fn(a.w, b.w)); }

template <typename Fn> Vec2 fore(Vec2 a, float b, Fn fn) { return Vec2(fn(a.x, b), fn(a.y, b)); }
template <typename Fn> Vec3 fore(Vec3 a, float b, Fn fn) { return Vec3(fn(a.x, b), fn(a.y, b), fn(a.z, b)); }
template <typename Fn> Vec4 fore(Vec4 a, float b, Fn fn) { return Vec4(fn(a.x, b), fn(a.y, b), fn(a.z, b), fn(a.w, b)); }

template <typename Fn> Vec2 fore(float a, Vec2 b, Fn fn) { return Vec2(fn(a, b.x), fn(a, b.y)); }
template <typename Fn> Vec3 fore(float a, Vec3 b, Fn fn) { return Vec3(fn(a, b.x), fn(a, b.y), fn(a, b.z)); }
template <typename Fn> Vec4 fore(float a, Vec4 b, Fn fn) { return Vec4(fn(a, b.x), fn(a, b.y), fn(a, b.z), fn(a, b.w)); }

inline float add_v(Vec2 v) { return v.x + v.y; }
inline float add_v(Vec3 v) { return v.x + v.y + v.z; }
inline float add_v(Vec4 v) { return v.x + v.y + v.z + v.w; }

inline float sub_v(Vec2 v) { return 0.0f - v.x - v.y; }
inline float sub_v(Vec3 v) { return 0.0f - v.x - v.y - v.z; }
inline float sub_v(Vec4 v) { return 0.0f - v.x - v.y - v.z - v.w; }

inline float mul_v(Vec2 v) { return v.x * v.y; }
inline float mul_v(Vec3 v) { return v.x * v.y * v.z; }
inline float mul_v(Vec4 v) { return v.x * v.y * v.z * v.w; }

inline float div_v(Vec2 v) { return 1.0f / v.x / v.y; }
inline float div_v(Vec3 v) { return 1.0f / v.x / v.y / v.z; }
inline float div_v(Vec4 v) { return 1.0f / v.x / v.y / v.z / v.w; }

inline float dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }
inline float dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline float dot(Vec4 a, Vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

inline float cross(Vec2 a, Vec2 b) {
    return a.x * b.y - a.y * b.x;
}

inline Vec3 cross(Vec3 a, Vec3 b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

inline float len_sqr(Vec2 v) { return dot(v, v); }
inline float len_sqr(Vec3 v) { return dot(v, v); }
inline float len_sqr(Vec4 v) { return dot(v, v); }

inline float len(Vec2 v) { return sqrt(len_sqr(v)); }
inline float len(Vec3 v) { return sqrt(len_sqr(v)); }
inline float len(Vec4 v) { return sqrt(len_sqr(v)); }

inline Vec2 norm(Vec2 v) {
    float l = len(v);
    return Vec2(v.x / l, v.y / l);
}

inline Vec3 norm(Vec3 v) {
    float l = len(v);
    return Vec3(v.x / l, v.y / l, v.z / l);
}

inline Vec4 norm(Vec4 v) {
    float l = len(v);
    return Vec4(v.x / l, v.y / l, v.z / l, v.w / l);
}

inline float dist_sqr(Vec2 a, Vec2 b) { return len_sqr(a - b); }
inline float dist_sqr(Vec3 a, Vec3 b) { return len_sqr(a - b); }
inline float dist_sqr(Vec4 a, Vec4 b) { return len_sqr(a - b); }

inline float dist(Vec2 a, Vec2 b) { return len(a - b); }
inline float dist(Vec3 a, Vec3 b) { return len(a - b); }
inline float dist(Vec4 a, Vec4 b) { return len(a - b); }

inline Vec2 proj(Vec2 a, Vec2 b) { return b * dot(a, b); }
inline Vec3 proj(Vec3 a, Vec3 b) { return b * dot(a, b); }
inline Vec4 proj(Vec4 a, Vec4 b) { return b * dot(a, b); }

inline Vec2 proj_norm(Vec2 a, Vec2 b) { return proj(a, norm(b)); }
inline Vec3 proj_norm(Vec3 a, Vec3 b) { return proj(a, norm(b)); }
inline Vec4 proj_norm(Vec4 a, Vec4 b) { return proj(a, norm(b)); }

inline Vec2 refl(Vec2 a, Vec2 b) { return a - b * 2.0f * dot(a, b); }
inline Vec3 refl(Vec3 a, Vec3 b) { return a - b * 2.0f * dot(a, b); }
inline Vec4 refl(Vec4 a, Vec4 b) { return a - b * 2.0f * dot(a, b); }

inline Vec2 refl_norm(Vec2 a, Vec2 b) { return refl(a, norm(b)); }
inline Vec3 refl_norm(Vec3 a, Vec3 b) { return refl(a, norm(b)); }
inline Vec4 refl_norm(Vec4 a, Vec4 b) { return refl(a, norm(b)); }

inline float angle(Vec2 v) {
    return atan2(v.y, v.x);
}

inline float angle(Vec2 a, Vec2 b) {
    return atan2(cross(a, b), dot(a, b));
}

inline float angle(Vec3 a, Vec3 b) {
    return acos(dot(a, b) / (len(a) * len(b)));
}

inline Vec2 rotate(Vec2 v, float a) {
    float c = cos(a);
    float s = sin(a);
    return Vec2(v.x * c - v.y * s, v.x * s + v.y * c);
}

inline Vec3 rotate(Vec3 v, Vec3 axis, float a) {
    float c = cos(a);
    float s = sin(a);
    return v * c + cross(axis, v) * s + axis * dot(axis, v) * (1.0f - c);
}

inline Vec3 add_vw(Vec4 v) { return Vec3(v.x + v.w, v.y + v.w, v.z + v.w); }
inline Vec3 sub_vw(Vec4 v) { return Vec3(v.x - v.w, v.y - v.w, v.z - v.w); }
inline Vec3 mul_vw(Vec4 v) { return Vec3(v.x * v.w, v.y * v.w, v.z * v.w); }
inline Vec3 div_vw(Vec4 v) { return Vec3(v.x / v.w, v.y / v.w, v.z / v.w); }

inline Vec3 add_wv(Vec4 v) { return Vec3(v.w + v.x, v.w + v.y, v.w + v.z); }
inline Vec3 sub_wv(Vec4 v) { return Vec3(v.w - v.x, v.w - v.y, v.w - v.z); }
inline Vec3 mul_wv(Vec4 v) { return Vec3(v.w * v.x, v.w * v.y, v.w * v.z); }
inline Vec3 div_wv(Vec4 v) { return Vec3(v.w / v.x, v.w / v.y, v.w / v.z); }

// Note: matrix multiplication is mm(m1, m2), not m1 * m2
// The latter is element-wise multiplication

struct Mat2;
struct Mat3;
struct Mat4;

struct Mat2 {
    using M = std::array<float, 4>;
    using V = std::array<Vec2, 2>;

    // Row-major
    // [0, 1
    //  2, 3]
    M m;

    MemPropExp(Mat2, rows, V, V({Vec2(self.m[0], self.m[1]), Vec2(self.m[2], self.m[3])}), (self.m = M{value[0].x, value[0].y, value[1].x, value[1].y}));

    MemPropExp(Mat2, cols, V, V({Vec2(self.m[0], self.m[2]), Vec2(self.m[1], self.m[3])}), (self.m = M{value[0].x, value[1].x, value[0].y, value[1].y}));

    MemPropExp(Mat2, diag, Vec2, Vec2(self.m[0], self.m[3]), (self.m = {value.x, self.m[1], self.m[2], value.y}));

    Mat2() = default;
    Mat2(M m) : m({m[0], m[1], m[2], m[3]}) {}
    Mat2(float m0, float m1, float m2, float m3) : m({m0, m1, m2, m3}) {}
    Mat2(Vec2 v1, Vec2 v2) : m({v1.x, v1.y, v2.x, v2.y}) {}

    inline explicit Mat2(Mat3 m);
    inline explicit Mat2(Mat4 m);

    static Mat2 from_rows(Vec4 m) { return Mat2(m.x, m.y, m.z, m.w); }

    static Mat2 from_cols(Vec4 m) { return Mat2(m.x, m.z, m.y, m.w); }

    Vec4 to_rows() const { return Vec4(m[0], m[1], m[2], m[3]); }

    Vec4 to_cols() const { return Vec4(m[0], m[2], m[1], m[3]); }

    inline Mat2 &operator+=(Mat2 b);
    inline Mat2 &operator-=(Mat2 b);
    inline Mat2 &operator*=(Mat2 b);
    inline Mat2 &operator/=(Mat2 b);
    inline Mat2 &operator+=(float b);
    inline Mat2 &operator-=(float b);
    inline Mat2 &operator*=(float b);
    inline Mat2 &operator/=(float b);
};

inline Mat2 operator+(Mat2 a) { return Mat2(+a.m[0], +a.m[1], +a.m[2], +a.m[3]); }
inline Mat2 operator-(Mat2 a) { return Mat2(-a.m[0], -a.m[1], -a.m[2], -a.m[3]); }

inline Mat2 operator+(Mat2 a, Mat2 b) { return Mat2(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3]); }
inline Mat2 operator-(Mat2 a, Mat2 b) { return Mat2(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3]); }
inline Mat2 operator*(Mat2 a, Mat2 b) { return Mat2(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3]); }
inline Mat2 operator/(Mat2 a, Mat2 b) { return Mat2(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3]); }
inline Mat2 operator+(Mat2 a, float b) { return Mat2(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b); }
inline Mat2 operator-(Mat2 a, float b) { return Mat2(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b); }
inline Mat2 operator*(Mat2 a, float b) { return Mat2(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b); }
inline Mat2 operator/(Mat2 a, float b) { return Mat2(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b); }
inline Mat2 operator+(float a, Mat2 b) { return Mat2(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3]); }
inline Mat2 operator-(float a, Mat2 b) { return Mat2(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3]); }
inline Mat2 operator*(float a, Mat2 b) { return Mat2(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3]); }
inline Mat2 operator/(float a, Mat2 b) { return Mat2(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3]); }

inline Mat2 &Mat2::operator+=(Mat2 b) { return *this = *this + b; }
inline Mat2 &Mat2::operator-=(Mat2 b) { return *this = *this - b; }
inline Mat2 &Mat2::operator*=(Mat2 b) { return *this = *this * b; }
inline Mat2 &Mat2::operator/=(Mat2 b) { return *this = *this / b; }
inline Mat2 &Mat2::operator+=(float b) { return *this = *this + b; }
inline Mat2 &Mat2::operator-=(float b) { return *this = *this - b; }
inline Mat2 &Mat2::operator*=(float b) { return *this = *this * b; }
inline Mat2 &Mat2::operator/=(float b) { return *this = *this / b; }

struct Mat3 {
    using M = std::array<float, 9>;
    using V = std::array<Vec3, 3>;

    // Row-major
    // [0, 1, 2
    //  3, 4, 5
    //  6, 7, 8]
    M m;

    MemPropExp(Mat3, rows, V, V({Vec3(self.m[0], self.m[1], self.m[2]), Vec3(self.m[3], self.m[4], self.m[5]), Vec3(self.m[6], self.m[7], self.m[8])}), (self.m = M{value[0].x, value[0].y, value[0].z, value[1].x, value[1].y, value[1].z, value[2].x, value[2].y, value[2].z}));

    MemPropExp(Mat3, cols, V, V({Vec3(self.m[0], self.m[3], self.m[6]), Vec3(self.m[1], self.m[4], self.m[7]), Vec3(self.m[2], self.m[5], self.m[8])}), (self.m = M{value[0].x, value[1].x, value[2].x, value[0].y, value[1].y, value[2].y, value[0].z, value[1].z, value[2].z}));

    MemPropExp(Mat3, diag, Vec3, Vec3(self.m[0], self.m[3], self.m[6]), (self.m = {value.x, self.m[1], self.m[2], self.m[3], value.y, self.m[5], self.m[6], self.m[7], value.z}));

    Mat3() = default;
    Mat3(M m) : m({m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]}) {}
    Mat3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) : m({m0, m1, m2, m3, m4, m5, m6, m7, m8}) {}
    Mat3(Vec3 v1, Vec3 v2, Vec3 v3) : m({v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z}) {}

    inline explicit Mat3(Mat2 m);
    inline explicit Mat3(Mat4 m);

    inline Mat3 &operator+=(Mat3 b);
    inline Mat3 &operator-=(Mat3 b);
    inline Mat3 &operator*=(Mat3 b);
    inline Mat3 &operator/=(Mat3 b);
    inline Mat3 &operator+=(float b);
    inline Mat3 &operator-=(float b);
    inline Mat3 &operator*=(float b);
    inline Mat3 &operator/=(float b);
};

inline Mat3 operator+(Mat3 a) { return Mat3(+a.m[0], +a.m[1], +a.m[2], +a.m[3], +a.m[4], +a.m[5], +a.m[6], +a.m[7], +a.m[8]); }
inline Mat3 operator-(Mat3 a) { return Mat3(-a.m[0], -a.m[1], -a.m[2], -a.m[3], -a.m[4], -a.m[5], -a.m[6], -a.m[7], -a.m[8]); }

inline Mat3 operator+(Mat3 a, Mat3 b) { return Mat3(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3], a.m[4] + b.m[4], a.m[5] + b.m[5], a.m[6] + b.m[6], a.m[7] + b.m[7], a.m[8] + b.m[8]); }
inline Mat3 operator-(Mat3 a, Mat3 b) { return Mat3(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3], a.m[4] - b.m[4], a.m[5] - b.m[5], a.m[6] - b.m[6], a.m[7] - b.m[7], a.m[8] - b.m[8]); }
inline Mat3 operator*(Mat3 a, Mat3 b) { return Mat3(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3], a.m[4] * b.m[4], a.m[5] * b.m[5], a.m[6] * b.m[6], a.m[7] * b.m[7], a.m[8] * b.m[8]); }
inline Mat3 operator/(Mat3 a, Mat3 b) { return Mat3(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3], a.m[4] / b.m[4], a.m[5] / b.m[5], a.m[6] / b.m[6], a.m[7] / b.m[7], a.m[8] / b.m[8]); }
inline Mat3 operator+(Mat3 a, float b) { return Mat3(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b, a.m[4] + b, a.m[5] + b, a.m[6] + b, a.m[7] + b, a.m[8] + b); }
inline Mat3 operator-(Mat3 a, float b) { return Mat3(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b, a.m[4] - b, a.m[5] - b, a.m[6] - b, a.m[7] - b, a.m[8] - b); }
inline Mat3 operator*(Mat3 a, float b) { return Mat3(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b, a.m[4] * b, a.m[5] * b, a.m[6] * b, a.m[7] * b, a.m[8] * b); }
inline Mat3 operator/(Mat3 a, float b) { return Mat3(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b, a.m[4] / b, a.m[5] / b, a.m[6] / b, a.m[7] / b, a.m[8] / b); }
inline Mat3 operator+(float a, Mat3 b) { return Mat3(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3], a + b.m[4], a + b.m[5], a + b.m[6], a + b.m[7], a + b.m[8]); }
inline Mat3 operator-(float a, Mat3 b) { return Mat3(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3], a - b.m[4], a - b.m[5], a - b.m[6], a - b.m[7], a - b.m[8]); }
inline Mat3 operator*(float a, Mat3 b) { return Mat3(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3], a * b.m[4], a * b.m[5], a * b.m[6], a * b.m[7], a * b.m[8]); }
inline Mat3 operator/(float a, Mat3 b) { return Mat3(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3], a / b.m[4], a / b.m[5], a / b.m[6], a / b.m[7], a / b.m[8]); }

inline Mat3 &Mat3::operator+=(Mat3 b) { return *this = *this + b; }
inline Mat3 &Mat3::operator-=(Mat3 b) { return *this = *this - b; }
inline Mat3 &Mat3::operator*=(Mat3 b) { return *this = *this * b; }
inline Mat3 &Mat3::operator/=(Mat3 b) { return *this = *this / b; }
inline Mat3 &Mat3::operator+=(float b) { return *this = *this + b; }
inline Mat3 &Mat3::operator-=(float b) { return *this = *this - b; }
inline Mat3 &Mat3::operator*=(float b) { return *this = *this * b; }
inline Mat3 &Mat3::operator/=(float b) { return *this = *this / b; }

struct Mat4 {
    using M = std::array<float, 16>;
    using V = std::array<Vec4, 4>;

    // Row-major
    // [ 0,  1,  2,  3
    //   4,  5,  6,  7
    //   8,  9, 10, 11
    //  12, 13, 14, 15]
    M m;

    MemPropExp(Mat4, rows, V, V({Vec4(self.m[0], self.m[1], self.m[2], self.m[3]), Vec4(self.m[4], self.m[5], self.m[6], self.m[7]), Vec4(self.m[8], self.m[9], self.m[10], self.m[11]), Vec4(self.m[12], self.m[13], self.m[14], self.m[15])}), (self.m = M{value[0].x, value[0].y, value[0].z, value[0].w, value[1].x, value[1].y, value[1].z, value[1].w, value[2].x, value[2].y, value[2].z, value[2].w, value[3].x, value[3].y, value[3].z, value[3].w}));

    MemPropExp(Mat4, cols, V, V({Vec4(self.m[0], self.m[4], self.m[8], self.m[12]), Vec4(self.m[1], self.m[5], self.m[9], self.m[13]), Vec4(self.m[2], self.m[6], self.m[10], self.m[14]), Vec4(self.m[3], self.m[7], self.m[11], self.m[15])}), (self.m = M{value[0].x, value[1].x, value[2].x, value[3].x, value[0].y, value[1].y, value[2].y, value[3].y, value[0].z, value[1].z, value[2].z, value[3].z, value[0].w, value[1].w, value[2].w, value[3].w}));

    MemPropExp(Mat4, diag, Vec4, Vec4(self.m[0], self.m[5], self.m[10], self.m[15]), (self.m = {value.x, self.m[1], self.m[2], self.m[3], self.m[4], value.y, self.m[6], self.m[7], self.m[8], self.m[9], value.z, self.m[11], self.m[12], self.m[13], self.m[14], value.w}));

    Mat4() = default;
    Mat4(M m) : m({m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]}) {}
    Mat4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15) : m({m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15}) {}

    inline explicit Mat4(Mat2 m);
    inline explicit Mat4(Mat3 m);

    inline Mat4 &operator+=(Mat4 b);
    inline Mat4 &operator-=(Mat4 b);
    inline Mat4 &operator*=(Mat4 b);
    inline Mat4 &operator/=(Mat4 b);
    inline Mat4 &operator+=(float b);
    inline Mat4 &operator-=(float b);
    inline Mat4 &operator*=(float b);
    inline Mat4 &operator/=(float b);
};

inline Mat4 operator+(Mat4 a) { return Mat4(+a.m[0], +a.m[1], +a.m[2], +a.m[3], +a.m[4], +a.m[5], +a.m[6], +a.m[7], +a.m[8], +a.m[9], +a.m[10], +a.m[11], +a.m[12], +a.m[13], +a.m[14], +a.m[15]); }
inline Mat4 operator-(Mat4 a) { return Mat4(-a.m[0], -a.m[1], -a.m[2], -a.m[3], -a.m[4], -a.m[5], -a.m[6], -a.m[7], -a.m[8], -a.m[9], -a.m[10], -a.m[11], -a.m[12], -a.m[13], -a.m[14], -a.m[15]); }

inline Mat4 operator+(Mat4 a, Mat4 b) { return Mat4(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3], a.m[4] + b.m[4], a.m[5] + b.m[5], a.m[6] + b.m[6], a.m[7] + b.m[7], a.m[8] + b.m[8], a.m[9] + b.m[9], a.m[10] + b.m[10], a.m[11] + b.m[11], a.m[12] + b.m[12], a.m[13] + b.m[13], a.m[14] + b.m[14], a.m[15] + b.m[15]); }
inline Mat4 operator-(Mat4 a, Mat4 b) { return Mat4(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3], a.m[4] - b.m[4], a.m[5] - b.m[5], a.m[6] - b.m[6], a.m[7] - b.m[7], a.m[8] - b.m[8], a.m[9] - b.m[9], a.m[10] - b.m[10], a.m[11] - b.m[11], a.m[12] - b.m[12], a.m[13] - b.m[13], a.m[14] - b.m[14], a.m[15] - b.m[15]); }
inline Mat4 operator*(Mat4 a, Mat4 b) { return Mat4(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3], a.m[4] * b.m[4], a.m[5] * b.m[5], a.m[6] * b.m[6], a.m[7] * b.m[7], a.m[8] * b.m[8], a.m[9] * b.m[9], a.m[10] * b.m[10], a.m[11] * b.m[11], a.m[12] * b.m[12], a.m[13] * b.m[13], a.m[14] * b.m[14], a.m[15] * b.m[15]); }
inline Mat4 operator/(Mat4 a, Mat4 b) { return Mat4(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3], a.m[4] / b.m[4], a.m[5] / b.m[5], a.m[6] / b.m[6], a.m[7] / b.m[7], a.m[8] / b.m[8], a.m[9] / b.m[9], a.m[10] / b.m[10], a.m[11] / b.m[11], a.m[12] / b.m[12], a.m[13] / b.m[13], a.m[14] / b.m[14], a.m[15] / b.m[15]); }
inline Mat4 operator+(Mat4 a, float b) { return Mat4(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b, a.m[4] + b, a.m[5] + b, a.m[6] + b, a.m[7] + b, a.m[8] + b, a.m[9] + b, a.m[10] + b, a.m[11] + b, a.m[12] + b, a.m[13] + b, a.m[14] + b, a.m[15] + b); }
inline Mat4 operator-(Mat4 a, float b) { return Mat4(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b, a.m[4] - b, a.m[5] - b, a.m[6] - b, a.m[7] - b, a.m[8] - b, a.m[9] - b, a.m[10] - b, a.m[11] - b, a.m[12] - b, a.m[13] - b, a.m[14] - b, a.m[15] - b); }
inline Mat4 operator*(Mat4 a, float b) { return Mat4(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b, a.m[4] * b, a.m[5] * b, a.m[6] * b, a.m[7] * b, a.m[8] * b, a.m[9] * b, a.m[10] * b, a.m[11] * b, a.m[12] * b, a.m[13] * b, a.m[14] * b, a.m[15] * b); }
inline Mat4 operator/(Mat4 a, float b) { return Mat4(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b, a.m[4] / b, a.m[5] / b, a.m[6] / b, a.m[7] / b, a.m[8] / b, a.m[9] / b, a.m[10] / b, a.m[11] / b, a.m[12] / b, a.m[13] / b, a.m[14] / b, a.m[15] / b); }
inline Mat4 operator+(float a, Mat4 b) { return Mat4(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3], a + b.m[4], a + b.m[5], a + b.m[6], a + b.m[7], a + b.m[8], a + b.m[9], a + b.m[10], a + b.m[11], a + b.m[12], a + b.m[13], a + b.m[14], a + b.m[15]); }
inline Mat4 operator-(float a, Mat4 b) { return Mat4(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3], a - b.m[4], a - b.m[5], a - b.m[6], a - b.m[7], a - b.m[8], a - b.m[9], a - b.m[10], a - b.m[11], a - b.m[12], a - b.m[13], a - b.m[14], a - b.m[15]); }
inline Mat4 operator*(float a, Mat4 b) { return Mat4(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3], a * b.m[4], a * b.m[5], a * b.m[6], a * b.m[7], a * b.m[8], a * b.m[9], a * b.m[10], a * b.m[11], a * b.m[12], a * b.m[13], a * b.m[14], a * b.m[15]); }
inline Mat4 operator/(float a, Mat4 b) { return Mat4(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3], a / b.m[4], a / b.m[5], a / b.m[6], a / b.m[7], a / b.m[8], a / b.m[9], a / b.m[10], a / b.m[11], a / b.m[12], a / b.m[13], a / b.m[14], a / b.m[15]); }

inline Mat4 &Mat4::operator+=(Mat4 b) { return *this = *this + b; }
inline Mat4 &Mat4::operator-=(Mat4 b) { return *this = *this - b; }
inline Mat4 &Mat4::operator*=(Mat4 b) { return *this = *this * b; }
inline Mat4 &Mat4::operator/=(Mat4 b) { return *this = *this / b; }
inline Mat4 &Mat4::operator+=(float b) { return *this = *this + b; }
inline Mat4 &Mat4::operator-=(float b) { return *this = *this - b; }
inline Mat4 &Mat4::operator*=(float b) { return *this = *this * b; }
inline Mat4 &Mat4::operator/=(float b) { return *this = *this / b; }

inline Mat2::Mat2(Mat3 m) : m({m.m[0], m.m[1], m.m[3], m.m[4]}) {}
inline Mat2::Mat2(Mat4 m) : m({m.m[0], m.m[1], m.m[4], m.m[5]}) {}
inline Mat3::Mat3(Mat2 m) : m({m.m[0], m.m[1], 0.0f, m.m[2], m.m[3], 0.0f, 0.0f, 0.0f, 0.0f}) {}
inline Mat3::Mat3(Mat4 m) : m({m.m[0], m.m[1], m.m[2], m.m[4], m.m[5], m.m[6], m.m[8], m.m[9], m.m[10]}) {}
inline Mat4::Mat4(Mat2 m) : m({m.m[0], m.m[1], 0.0f, 0.0f, m.m[2], m.m[3], 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}) {}
inline Mat4::Mat4(Mat3 m) : m({m.m[0], m.m[1], m.m[2], 0.0f, m.m[3], m.m[4], m.m[5], 0.0f, m.m[6], m.m[7], m.m[8], 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}) {}

template <typename Fn> Mat2 fore(Mat2 m, Fn fn) { return Mat2(fn(m.m[0]), fn(m.m[1]), fn(m.m[2]), fn(m.m[3])); }
template <typename Fn> Mat3 fore(Mat3 m, Fn fn) { return Mat3(fn(m.m[0]), fn(m.m[1]), fn(m.m[2]), fn(m.m[3]), fn(m.m[4]), fn(m.m[5]), fn(m.m[6]), fn(m.m[7]), fn(m.m[8])); }
template <typename Fn> Mat4 fore(Mat4 m, Fn fn) { return Mat4(fn(m.m[0]), fn(m.m[1]), fn(m.m[2]), fn(m.m[3]), fn(m.m[4]), fn(m.m[5]), fn(m.m[6]), fn(m.m[7]), fn(m.m[8]), fn(m.m[9]), fn(m.m[10]), fn(m.m[11]), fn(m.m[12]), fn(m.m[13]), fn(m.m[14]), fn(m.m[15])); }

template <typename Fn> Mat2 fore(Mat2 a, Mat2 b, Fn fn) { return Mat2(fn(a.m[0], b.m[0]), fn(a.m[1], b.m[1]), fn(a.m[2], b.m[2]), fn(a.m[3], b.m[3])); }
template <typename Fn> Mat3 fore(Mat3 a, Mat3 b, Fn fn) { return Mat3(fn(a.m[0], b.m[0]), fn(a.m[1], b.m[1]), fn(a.m[2], b.m[2]), fn(a.m[3], b.m[3]), fn(a.m[4], b.m[4]), fn(a.m[5], b.m[5]), fn(a.m[6], b.m[6]), fn(a.m[7], b.m[7]), fn(a.m[8], b.m[8])); }
template <typename Fn> Mat4 fore(Mat4 a, Mat4 b, Fn fn) { return Mat4(fn(a.m[0], b.m[0]), fn(a.m[1], b.m[1]), fn(a.m[2], b.m[2]), fn(a.m[3], b.m[3]), fn(a.m[4], b.m[4]), fn(a.m[5], b.m[5]), fn(a.m[6], b.m[6]), fn(a.m[7], b.m[7]), fn(a.m[8], b.m[8]), fn(a.m[9], b.m[9]), fn(a.m[10], b.m[10]), fn(a.m[11], b.m[11]), fn(a.m[12], b.m[12]), fn(a.m[13], b.m[13]), fn(a.m[14], b.m[14]), fn(a.m[15], b.m[15])); }

template <typename Fn> Mat2 fore(Mat2 a, float b, Fn fn) { return Mat2(fn(a.m[0], b), fn(a.m[1], b), fn(a.m[2], b), fn(a.m[3], b)); }
template <typename Fn> Mat3 fore(Mat3 a, float b, Fn fn) { return Mat3(fn(a.m[0], b), fn(a.m[1], b), fn(a.m[2], b), fn(a.m[3], b), fn(a.m[4], b), fn(a.m[5], b), fn(a.m[6], b), fn(a.m[7], b), fn(a.m[8], b)); }
template <typename Fn> Mat4 fore(Mat4 a, float b, Fn fn) { return Mat4(fn(a.m[0], b), fn(a.m[1], b), fn(a.m[2], b), fn(a.m[3], b), fn(a.m[4], b), fn(a.m[5], b), fn(a.m[6], b), fn(a.m[7], b), fn(a.m[8], b), fn(a.m[9], b), fn(a.m[10], b), fn(a.m[11], b), fn(a.m[12], b), fn(a.m[13], b), fn(a.m[14], b), fn(a.m[15], b)); }

template <typename Fn> Mat2 fore(float a, Mat2 b, Fn fn) { return Mat2(fn(a, b.m[0]), fn(a, b.m[1]), fn(a, b.m[2]), fn(a, b.m[3])); }
template <typename Fn> Mat3 fore(float a, Mat3 b, Fn fn) { return Mat3(fn(a, b.m[0]), fn(a, b.m[1]), fn(a, b.m[2]), fn(a, b.m[3]), fn(a, b.m[4]), fn(a, b.m[5]), fn(a, b.m[6]), fn(a, b.m[7]), fn(a, b.m[8])); }
template <typename Fn> Mat4 fore(float a, Mat4 b, Fn fn) { return Mat4(fn(a, b.m[0]), fn(a, b.m[1]), fn(a, b.m[2]), fn(a, b.m[3]), fn(a, b.m[4]), fn(a, b.m[5]), fn(a, b.m[6]), fn(a, b.m[7]), fn(a, b.m[8]), fn(a, b.m[9]), fn(a, b.m[10]), fn(a, b.m[11]), fn(a, b.m[12]), fn(a, b.m[13]), fn(a, b.m[14]), fn(a, b.m[15])); }

inline float add_m(Mat2 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result += m;
    }
    return result;
}

inline float add_m(Mat3 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result += m;
    }
    return result;
}

inline float add_m(Mat4 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result += m;
    }
    return result;
}

inline float sub_m(Mat2 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result -= m;
    }
    return result;
}

inline float sub_m(Mat3 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result -= m;
    }
    return result;
}

inline float sub_m(Mat4 m) {
    float result = 0.0f;
    for (float m : m.m) {
        result -= m;
    }
    return result;
}

inline float mul_m(Mat2 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result *= m;
    }
    return result;
}

inline float mul_m(Mat3 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result *= m;
    }
    return result;
}

inline float mul_m(Mat4 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result *= m;
    }
    return result;
}

inline float div_m(Mat2 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result /= m;
    }
    return result;
}

inline float div_m(Mat3 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result /= m;
    }
    return result;
}

inline float div_m(Mat4 m) {
    float result = 1.0f;
    for (float m : m.m) {
        result /= m;
    }
    return result;
}

inline float det(Mat2 m) {
    return m.m[0] * m.m[3] - m.m[1] * m.m[2];
}

inline float det(Mat3 m) {
    return m.m[0] * (m.m[4] * m.m[8] - m.m[5] * m.m[7]) -
           m.m[1] * (m.m[3] * m.m[8] - m.m[5] * m.m[6]) +
           m.m[2] * (m.m[3] * m.m[7] - m.m[4] * m.m[6]);
}

inline float det(Mat4 m) {
    return m.m[0] * m.m[5] * m.m[10] * m.m[15] +
           m.m[0] * m.m[6] * m.m[11] * m.m[13] +
           m.m[0] * m.m[7] * m.m[9] * m.m[14] +

           m.m[1] * m.m[4] * m.m[11] * m.m[14] +
           m.m[1] * m.m[6] * m.m[8] * m.m[15] +
           m.m[1] * m.m[7] * m.m[10] * m.m[12] +

           m.m[2] * m.m[4] * m.m[9] * m.m[15] +
           m.m[2] * m.m[5] * m.m[11] * m.m[12] +
           m.m[2] * m.m[7] * m.m[8] * m.m[13] +

           m.m[3] * m.m[4] * m.m[10] * m.m[13] +
           m.m[3] * m.m[5] * m.m[8] * m.m[14] +
           m.m[3] * m.m[6] * m.m[9] * m.m[12] -

           m.m[0] * m.m[5] * m.m[11] * m.m[14] -
           m.m[0] * m.m[6] * m.m[9] * m.m[15] -
           m.m[0] * m.m[7] * m.m[10] * m.m[13] -

           m.m[1] * m.m[4] * m.m[10] * m.m[15] -
           m.m[1] * m.m[6] * m.m[11] * m.m[12] -
           m.m[1] * m.m[7] * m.m[8] * m.m[14] -

           m.m[2] * m.m[4] * m.m[11] * m.m[13] -
           m.m[2] * m.m[5] * m.m[8] * m.m[15] -
           m.m[2] * m.m[7] * m.m[9] * m.m[12] -

           m.m[3] * m.m[4] * m.m[9] * m.m[14] -
           m.m[3] * m.m[5] * m.m[10] * m.m[12] -
           m.m[3] * m.m[6] * m.m[8] * m.m[13];
}

inline Mat2 inv(Mat2 m) {
    float d = det(m);
    Mat2  r;

    r.m[0] = m.m[3] / d;
    r.m[1] = -m.m[1] / d;
    r.m[2] = -m.m[2] / d;
    r.m[3] = m.m[0] / d;

    return r;
}

inline Mat3 inv(Mat3 m) {
    float d = det(m);
    Mat3  r;

    r.m[0] = (m.m[4] * m.m[8] - m.m[5] * m.m[7]) / d;
    r.m[1] = -(m.m[1] * m.m[8] - m.m[2] * m.m[7]) / d;
    r.m[2] = (m.m[1] * m.m[5] - m.m[2] * m.m[4]) / d;
    r.m[3] = -(m.m[3] * m.m[8] - m.m[5] * m.m[6]) / d;
    r.m[4] = (m.m[0] * m.m[8] - m.m[2] * m.m[6]) / d;
    r.m[5] = -(m.m[0] * m.m[5] - m.m[2] * m.m[3]) / d;
    r.m[6] = (m.m[3] * m.m[7] - m.m[4] * m.m[6]) / d;
    r.m[7] = -(m.m[0] * m.m[7] - m.m[1] * m.m[6]) / d;
    r.m[8] = (m.m[0] * m.m[4] - m.m[1] * m.m[3]) / d;

    return r;
}

inline Mat4 inv(Mat4 m) {
    float d = det(m);
    Mat4  r;

    r.m[0]  = (m.m[5] * (m.m[10] * m.m[15] - m.m[11] * m.m[14]) - m.m[6] * (m.m[9] * m.m[15] - m.m[11] * m.m[13]) + m.m[7] * (m.m[9] * m.m[14] - m.m[10] * m.m[13])) / d;
    r.m[1]  = (-m.m[1] * (m.m[10] * m.m[15] - m.m[11] * m.m[14]) + m.m[2] * (m.m[9] * m.m[15] - m.m[11] * m.m[13]) - m.m[3] * (m.m[9] * m.m[14] - m.m[10] * m.m[13])) / d;
    r.m[2]  = (m.m[1] * (m.m[6] * m.m[15] - m.m[7] * m.m[14]) - m.m[2] * (m.m[5] * m.m[15] - m.m[7] * m.m[13]) + m.m[3] * (m.m[5] * m.m[14] - m.m[6] * m.m[13])) / d;
    r.m[3]  = (-m.m[1] * (m.m[6] * m.m[11] - m.m[7] * m.m[10]) + m.m[2] * (m.m[5] * m.m[11] - m.m[7] * m.m[9]) - m.m[3] * (m.m[5] * m.m[10] - m.m[6] * m.m[9])) / d;
    r.m[4]  = (-m.m[4] * (m.m[10] * m.m[15] - m.m[11] * m.m[14]) + m.m[6] * (m.m[8] * m.m[15] - m.m[11] * m.m[12]) - m.m[7] * (m.m[8] * m.m[14] - m.m[10] * m.m[12])) / d;
    r.m[5]  = (m.m[0] * (m.m[10] * m.m[15] - m.m[11] * m.m[14]) - m.m[2] * (m.m[8] * m.m[15] - m.m[11] * m.m[12]) + m.m[3] * (m.m[8] * m.m[14] - m.m[10] * m.m[12])) / d;
    r.m[6]  = (-m.m[0] * (m.m[6] * m.m[15] - m.m[7] * m.m[14]) + m.m[2] * (m.m[4] * m.m[15] - m.m[7] * m.m[12]) - m.m[3] * (m.m[4] * m.m[14] - m.m[6] * m.m[12])) / d;
    r.m[7]  = (m.m[0] * (m.m[6] * m.m[11] - m.m[7] * m.m[10]) - m.m[2] * (m.m[4] * m.m[11] - m.m[7] * m.m[8]) + m.m[3] * (m.m[4] * m.m[10] - m.m[6] * m.m[8])) / d;
    r.m[8]  = (m.m[4] * (m.m[9] * m.m[15] - m.m[11] * m.m[13]) - m.m[5] * (m.m[8] * m.m[15] - m.m[11] * m.m[12]) + m.m[7] * (m.m[8] * m.m[13] - m.m[9] * m.m[12])) / d;
    r.m[9]  = (-m.m[0] * (m.m[9] * m.m[15] - m.m[11] * m.m[13]) + m.m[1] * (m.m[8] * m.m[15] - m.m[11] * m.m[12]) - m.m[3] * (m.m[8] * m.m[13] - m.m[9] * m.m[12])) / d;
    r.m[10] = (m.m[0] * (m.m[5] * m.m[15] - m.m[7] * m.m[13]) - m.m[1] * (m.m[4] * m.m[15] - m.m[7] * m.m[12]) + m.m[3] * (m.m[4] * m.m[13] - m.m[5] * m.m[12])) / d;
    r.m[11] = (-m.m[0] * (m.m[5] * m.m[11] - m.m[7] * m.m[9]) + m.m[1] * (m.m[4] * m.m[11] - m.m[7] * m.m[8]) - m.m[3] * (m.m[4] * m.m[9] - m.m[5] * m.m[8])) / d;
    r.m[12] = (-m.m[4] * (m.m[9] * m.m[14] - m.m[10] * m.m[13]) + m.m[5] * (m.m[8] * m.m[14] - m.m[10] * m.m[12]) - m.m[6] * (m.m[8] * m.m[13] - m.m[9] * m.m[12])) / d;
    r.m[13] = (m.m[0] * (m.m[9] * m.m[14] - m.m[10] * m.m[13]) - m.m[1] * (m.m[8] * m.m[14] - m.m[10] * m.m[12]) + m.m[2] * (m.m[8] * m.m[13] - m.m[9] * m.m[12])) / d;
    r.m[14] = (-m.m[0] * (m.m[5] * m.m[14] - m.m[6] * m.m[13]) + m.m[1] * (m.m[4] * m.m[14] - m.m[6] * m.m[12]) - m.m[2] * (m.m[4] * m.m[13] - m.m[5] * m.m[12])) / d;
    r.m[15] = (m.m[0] * (m.m[5] * m.m[10] - m.m[6] * m.m[9]) - m.m[1] * (m.m[4] * m.m[10] - m.m[6] * m.m[8]) + m.m[2] * (m.m[4] * m.m[9] - m.m[5] * m.m[8])) / d;

    return r;
}

inline Mat2 mm(Mat2 a, Mat2 b) {
    return Mat2(
        a.m[0] * b.m[0] + a.m[1] * b.m[2],
        a.m[0] * b.m[1] + a.m[1] * b.m[3],

        a.m[2] * b.m[0] + a.m[3] * b.m[2],
        a.m[2] * b.m[1] + a.m[3] * b.m[3]
    );
}

inline Mat3 mm(Mat3 a, Mat3 b) {
    return Mat3(
        a.m[0] * b.m[0] + a.m[1] * b.m[3] + a.m[2] * b.m[6],
        a.m[0] * b.m[1] + a.m[1] * b.m[4] + a.m[2] * b.m[7],
        a.m[0] * b.m[2] + a.m[1] * b.m[5] + a.m[2] * b.m[8],

        a.m[3] * b.m[0] + a.m[4] * b.m[3] + a.m[5] * b.m[6],
        a.m[3] * b.m[1] + a.m[4] * b.m[4] + a.m[5] * b.m[7],
        a.m[3] * b.m[2] + a.m[4] * b.m[5] + a.m[5] * b.m[8],

        a.m[6] * b.m[0] + a.m[7] * b.m[3] + a.m[8] * b.m[6],
        a.m[6] * b.m[1] + a.m[7] * b.m[4] + a.m[8] * b.m[7],
        a.m[6] * b.m[2] + a.m[7] * b.m[5] + a.m[8] * b.m[8]
    );
}

inline Mat4 mm(Mat4 a, Mat4 b) {
    return Mat4(
        a.m[0] * b.m[0] + a.m[1] * b.m[4] + a.m[2] * b.m[8] + a.m[3] * b.m[12],
        a.m[0] * b.m[1] + a.m[1] * b.m[5] + a.m[2] * b.m[9] + a.m[3] * b.m[13],
        a.m[0] * b.m[2] + a.m[1] * b.m[6] + a.m[2] * b.m[10] + a.m[3] * b.m[14],
        a.m[0] * b.m[3] + a.m[1] * b.m[7] + a.m[2] * b.m[11] + a.m[3] * b.m[15],

        a.m[4] * b.m[0] + a.m[5] * b.m[4] + a.m[6] * b.m[8] + a.m[7] * b.m[12],
        a.m[4] * b.m[1] + a.m[5] * b.m[5] + a.m[6] * b.m[9] + a.m[7] * b.m[13],
        a.m[4] * b.m[2] + a.m[5] * b.m[6] + a.m[6] * b.m[10] + a.m[7] * b.m[14],
        a.m[4] * b.m[3] + a.m[5] * b.m[7] + a.m[6] * b.m[11] + a.m[7] * b.m[15],

        a.m[8] * b.m[0] + a.m[9] * b.m[4] + a.m[10] * b.m[8] + a.m[11] * b.m[12],
        a.m[8] * b.m[1] + a.m[9] * b.m[5] + a.m[10] * b.m[9] + a.m[11] * b.m[13],
        a.m[8] * b.m[2] + a.m[9] * b.m[6] + a.m[10] * b.m[10] + a.m[11] * b.m[14],
        a.m[8] * b.m[3] + a.m[9] * b.m[7] + a.m[10] * b.m[11] + a.m[11] * b.m[15],

        a.m[12] * b.m[0] + a.m[13] * b.m[4] + a.m[14] * b.m[8] + a.m[15] * b.m[12],
        a.m[12] * b.m[1] + a.m[13] * b.m[5] + a.m[14] * b.m[9] + a.m[15] * b.m[13],
        a.m[12] * b.m[2] + a.m[13] * b.m[6] + a.m[14] * b.m[10] + a.m[15] * b.m[14],
        a.m[12] * b.m[3] + a.m[13] * b.m[7] + a.m[14] * b.m[11] + a.m[15] * b.m[15]
    );
}

inline Vec2 mr(Mat2 m, Vec2 v) {
    return Vec2(
        m.m[0] * v.x + m.m[1] * v.y,
        m.m[2] * v.x + m.m[3] * v.y
    );
}

inline Vec2 mc(Mat2 m, Vec2 v) {
    return Vec2(
        m.m[0] * v.x + m.m[2] * v.y,
        m.m[1] * v.x + m.m[3] * v.y
    );
}

inline Vec3 mr(Mat3 m, Vec3 v) {
    return Vec3(
        m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z,
        m.m[3] * v.x + m.m[4] * v.y + m.m[5] * v.z,
        m.m[6] * v.x + m.m[7] * v.y + m.m[8] * v.z
    );
}

inline Vec3 mc(Mat3 m, Vec3 v) {
    return Vec3(
        m.m[0] * v.x + m.m[3] * v.y + m.m[6] * v.z,
        m.m[1] * v.x + m.m[4] * v.y + m.m[7] * v.z,
        m.m[2] * v.x + m.m[5] * v.y + m.m[8] * v.z
    );
}

inline Vec4 mr(Mat4 m, Vec4 v) {
    return Vec4(
        m.m[0] * v.x + m.m[1] * v.y + m.m[2] * v.z + m.m[3] * v.w,
        m.m[4] * v.x + m.m[5] * v.y + m.m[6] * v.z + m.m[7] * v.w,
        m.m[8] * v.x + m.m[9] * v.y + m.m[10] * v.z + m.m[11] * v.w,
        m.m[12] * v.x + m.m[13] * v.y + m.m[14] * v.z + m.m[15] * v.w
    );
}

inline Vec4 mc(Mat4 m, Vec4 v) {
    return Vec4(
        m.m[0] * v.x + m.m[4] * v.y + m.m[8] * v.z + m.m[12] * v.w,
        m.m[1] * v.x + m.m[5] * v.y + m.m[9] * v.z + m.m[13] * v.w,
        m.m[2] * v.x + m.m[6] * v.y + m.m[10] * v.z + m.m[14] * v.w,
        m.m[3] * v.x + m.m[7] * v.y + m.m[11] * v.z + m.m[15] * v.w
    );
}

inline Mat2 tp(Mat2 m) {
    return Mat2(
        m.m[0], m.m[2],
        m.m[1], m.m[3]
    );
}

inline Mat3 tp(Mat3 m) {
    return Mat3(
        m.m[0], m.m[3], m.m[6],
        m.m[1], m.m[4], m.m[7],
        m.m[2], m.m[5], m.m[8]
    );
}

inline Mat4 tp(Mat4 m) {
    return Mat4(
        m.m[0], m.m[4], m.m[8], m.m[12],
        m.m[1], m.m[5], m.m[9], m.m[13],
        m.m[2], m.m[6], m.m[10], m.m[14],
        m.m[3], m.m[7], m.m[11], m.m[15]
    );
}

inline Mat2 sym(Mat2 m) { return 0.5f * (m + tp(m)); }
inline Mat3 sym(Mat3 m) { return 0.5f * (m + tp(m)); }
inline Mat4 sym(Mat4 m) { return 0.5f * (m + tp(m)); }

inline Mat2 skew(Mat2 m) { return 0.5f * (m - tp(m)); }
inline Mat3 skew(Mat3 m) { return 0.5f * (m - tp(m)); }
inline Mat4 skew(Mat4 m) { return 0.5f * (m - tp(m)); }

struct Rect {
    Vec2 center;
    Vec2 extent;

    MemPropExp(Rect, halfExtent, Vec2, self.extent / 2.0f, self.extent = value * 2.0f);

    MemPropExp(Rect, top, float, self.center.y - self.extent.y / 2.0f, {
        float bottom  = self.bottom;
        self.extent.y = value - bottom;
        self.center.y = (value + bottom) / 2.0f;
    });

    MemPropExp(Rect, bottom, float, self.center.y + self.extent.y / 2.0f, {
        float top     = self.top;
        self.extent.y = top - value;
        self.center.y = (top + value) / 2.0f;
    });

    MemPropExp(Rect, left, float, self.center.x - self.extent.x / 2.0f, {
        float right   = self.right;
        self.extent.x = value - right;
        self.center.x = (value + right) / 2.0f;
    });

    MemPropExp(Rect, right, float, self.center.x + self.extent.x / 2.0f, {
        float left    = self.left;
        self.extent.x = left - value;
        self.center.x = (left + value) / 2.0f;
    });

    MemPropExp(Rect, topLeft, Vec2, Vec2(self.left, self.top), {
        self.left = value.x;
        self.top  = value.y;
    });

    MemPropExp(Rect, topRight, Vec2, Vec2(self.right, self.top), {
        self.right = value.x;
        self.top   = value.y;
    });

    MemPropExp(Rect, bottomLeft, Vec2, Vec2(self.left, self.bottom), {
        self.left   = value.x;
        self.bottom = value.y;
    });

    MemPropExp(Rect, bottomRight, Vec2, Vec2(self.right, self.bottom), {
        self.right  = value.x;
        self.bottom = value.y;
    });

    Rect() = default;
    Rect(float cx, float cy, float ex, float ey) : center(cx, cy), extent(ex, ey) {}
    Rect(Vec2 center, Vec2 extent) : center(center), extent(extent) {}
    Rect(SDL_FPoint center, SDL_FPoint extent) : center(center), extent(extent) {}
    Rect(Vec4 rect) : center(rect.x, rect.y), extent(rect.z, rect.w) {}
    Rect(SDL_FRect rect) : center(rect.x + rect.w / 2.0f, rect.y + rect.h / 2.0f), extent(rect.w, rect.h) {}

    static Rect from_xywh(float x, float y, float w, float h) { return Rect(x + w / 2.0f, y + h / 2.0f, w, h); }

    static Rect from_xywh(Vec2 xy, Vec2 wh) { return from_xywh(xy.x, xy.y, wh.x, wh.y); }

    static Rect from_xywh(Vec4 xywh) { return from_xywh(xywh.x, xywh.y, xywh.z, xywh.w); }

    Vec4 to_xywh() const { return Vec4(center.x - extent.x / 2.0f, center.y - extent.y / 2.0f, extent.x, extent.y); }

    operator Vec4() const { return Vec4(center.x, center.y, extent.x, extent.y); }

    operator SDL_FRect() const { return SDL_FRect{center.x - extent.x / 2.0f, center.y - extent.y / 2.0f, extent.x, extent.y}; }
};

inline bool contains(Rect r, Vec2 p) {
    Vec2 tl = r.topLeft;
    Vec2 br = r.bottomRight;
    return tl.x >= p.x && tl.y >= p.y && br.x <= p.x && br.y <= p.y;
}

inline bool contains(Rect r, Rect s) {
    return contains(r, s.topLeft) && contains(r, s.bottomRight);
}

inline Rect in(Rect a, Rect b) {
    Rect r;
    r.top    = fmax(a.top, b.top);
    r.bottom = fmin(a.bottom, b.bottom);
    r.left   = fmax(a.left, b.left);
    r.right  = fmin(a.right, b.right);
    return r;
}

inline Rect un(Rect a, Rect b) {
    Rect r;
    r.top    = fmin(a.top, b.top);
    r.bottom = fmax(a.bottom, b.bottom);
    r.left   = fmin(a.left, b.left);
    r.right  = fmax(a.right, b.right);
    return r;
}

struct Color {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a;

    Color() = default;
    Color(std::uint8_t R, std::uint8_t G, std::uint8_t B, std::uint8_t A = 255) : r(R), g(G), b(B), a(A) {}
    Color(std::uint8_t V, std::uint8_t A = 255) : r(V), g(V), b(V), a(A) {}
    Color(std::uint8_t R, std::uint8_t G, std::uint8_t B, float A) : r(R), g(G), b(B), a(quant(A)) {}
    Color(std::uint8_t V, float A) : r(V), g(V), b(V), a(quant(A)) {}
    Color(std::uint32_t rgba) : r((rgba >> 24) & 0xFF), g((rgba >> 16) & 0xFF), b((rgba >> 8) & 0xFF), a((rgba >> 0) & 0xFF) {}

    static float norm(std::uint8_t v) { return v / 255.0f; }

    static std::uint8_t quant(float v) { return v * 255.0f + 0.5f; }

    static std::uint8_t encode(float v) {
        float s = v <= 0.0031308f ? 12.92f * v : 1.055f * pow(v, 1.0f / 2.4f) - 0.055f;
        return quant(s);
    }

    static float decode(std::uint8_t v) {
        float s = norm(v);
        return s <= 0.04045f ? s / 12.92f : pow((s + 0.055f) / 1.055f, 2.4f);
    }

    static Color from_linear(Vec4 c);

    static Color from_linear(Vec3 c);

    Vec4 to_linear() const;

    static Color from_norm(Vec4 c);

    static Color from_norm(Vec3 c);

    Vec4 to_norm() const;

    static Color from_hsv(Vec4 h);
    static Color from_hsv(Vec3 h);

    Vec4 to_hsv() const;

    static Color from_hsl(Vec4 h);

    static Color from_hsl(Vec3 h);

    Vec4 to_hsl() const;

    static Color from_hwb(Vec4 h);

    static Color from_hwb(Vec3 h);

    Vec4 to_hwb() const;

    static Color from_oklab(Vec4 v);

    static Color from_oklab(Vec3 v);

    Vec4 to_oklab() const;

    static Color from_oklch(Vec4 v);

    static Color from_oklch(Vec3 v);

    Vec4 to_oklch() const;

    operator std::uint32_t() const { return (r << 24) + (g << 16) + (b << 8) + a; }
};

inline Color operator+(Color a) { return Color::from_linear(Vec4(+a.to_linear().xyz, a.to_linear().w)); }
inline Color operator-(Color a) { return Color::from_linear(Vec4(-a.to_linear().xyz, a.to_linear().w)); }

inline Color operator+(Color a, Color b) { return Color::from_linear(a.to_linear() + b.to_linear()); }
inline Color operator-(Color a, Color b) { return Color::from_linear(a.to_linear() - b.to_linear()); }
inline Color operator*(Color a, Color b) { return Color::from_linear(a.to_linear() * b.to_linear()); }
inline Color operator/(Color a, Color b) { return Color::from_linear(a.to_linear() / b.to_linear()); }
inline Color operator+(Color a, Vec4 b) { return Color::from_linear(a.to_linear() + b); }
inline Color operator-(Color a, Vec4 b) { return Color::from_linear(a.to_linear() - b); }
inline Color operator*(Color a, Vec4 b) { return Color::from_linear(a.to_linear() * b); }
inline Color operator/(Color a, Vec4 b) { return Color::from_linear(a.to_linear() / b); }
inline Color operator+(Vec4 a, Color b) { return Color::from_linear(a + b.to_linear()); }
inline Color operator-(Vec4 a, Color b) { return Color::from_linear(a - b.to_linear()); }
inline Color operator*(Vec4 a, Color b) { return Color::from_linear(a * b.to_linear()); }
inline Color operator/(Vec4 a, Color b) { return Color::from_linear(a / b.to_linear()); }
inline Color operator+(Color a, Vec3 b) { return Color::from_linear(a.to_linear() + Vec4(b, 0.0f)); }
inline Color operator-(Color a, Vec3 b) { return Color::from_linear(a.to_linear() - Vec4(b, 0.0f)); }
inline Color operator*(Color a, Vec3 b) { return Color::from_linear(a.to_linear() * Vec4(b, 1.0f)); }
inline Color operator/(Color a, Vec3 b) { return Color::from_linear(a.to_linear() / Vec4(b, 1.0f)); }
inline Color operator+(Vec3 a, Color b) { return Color::from_linear(Vec4(a, 0.0f) + b.to_linear()); }
inline Color operator-(Vec3 a, Color b) { return Color::from_linear(Vec4(a, 0.0f) - b.to_linear()); }
inline Color operator*(Vec3 a, Color b) { return Color::from_linear(Vec4(a, 1.0f) * b.to_linear()); }
inline Color operator/(Vec3 a, Color b) { return Color::from_linear(Vec4(a, 1.0f) / b.to_linear()); }
inline Color operator+(Color a, float b) { return Color::from_linear(a.to_linear() + Vec4(b, b, b, 0.0f)); }
inline Color operator-(Color a, float b) { return Color::from_linear(a.to_linear() - Vec4(b, b, b, 0.0f)); }
inline Color operator*(Color a, float b) { return Color::from_linear(a.to_linear() * Vec4(b, b, b, 1.0f)); }
inline Color operator/(Color a, float b) { return Color::from_linear(a.to_linear() / Vec4(b, b, b, 1.0f)); }
inline Color operator+(float a, Color b) { return Color::from_linear(Vec4(a, a, a, 0.0f) + b.to_linear()); }
inline Color operator-(float a, Color b) { return Color::from_linear(Vec4(a, a, a, 0.0f) - b.to_linear()); }
inline Color operator*(float a, Color b) { return Color::from_linear(Vec4(a, a, a, 1.0f) * b.to_linear()); }
inline Color operator/(float a, Color b) { return Color::from_linear(Vec4(a, a, a, 1.0f) / b.to_linear()); }

template <typename Fn> Color fore(Color c, Fn fn) { return Color(Color::encode(fn(Color::decode(c.r))), Color::encode(fn(Color::decode(c.g))), Color::encode(fn(Color::decode(c.b))), Color::encode(fn(Color::decode(c.a)))); }

template <typename Fn> Color fore(Color a, Color b, Fn fn) { return Color(Color::encode(fn(Color::decode(a.r), Color::decode(b.r))), Color::encode(fn(Color::decode(a.g), Color::decode(b.g))), Color::encode(fn(Color::decode(a.b), Color::decode(b.b))), Color::encode(fn(Color::decode(a.a), Color::decode(b.a)))); }
template <typename Fn> Color fore(Color a, Vec4 b, Fn fn) { return Color(Color::encode(fn(Color::decode(a.r), b.x)), Color::encode(fn(Color::decode(a.g), b.y)), Color::encode(fn(Color::decode(a.b), b.z)), Color::encode(fn(Color::decode(a.a), b.w))); }
template <typename Fn> Color fore(Vec4 a, Color b, Fn fn) { return Color(Color::encode(fn(a.x, Color::decode(b.r))), Color::encode(fn(a.y, Color::decode(b.g))), Color::encode(fn(a.z, Color::decode(b.b))), Color::encode(fn(a.w, Color::decode(b.a)))); }
template <typename Fn> Color fore(Color a, float b, Fn fn) { return Color(Color::encode(fn(Color::decode(a.r), b)), Color::encode(fn(Color::decode(a.g), b)), Color::encode(fn(Color::decode(a.b), b)), Color::encode(fn(Color::decode(a.a), b))); }
template <typename Fn> Color fore(float a, Color b, Fn fn) { return Color(Color::encode(fn(a, Color::decode(b.r))), Color::encode(fn(a, Color::decode(b.g))), Color::encode(fn(a, Color::decode(b.b))), Color::encode(fn(a, Color::decode(b.a)))); }
template <typename Fn> Color fore(Color a, Vec3 b, Fn fn) { return Color(Color::encode(fn(Color::decode(a.r), b.x)), Color::encode(fn(Color::decode(a.g), b.y)), Color::encode(fn(Color::decode(a.b), b.z)), a.a); }
template <typename Fn> Color fore(Vec3 a, Color b, Fn fn) { return Color(Color::encode(fn(a.x, Color::decode(b.r))), Color::encode(fn(a.y, Color::decode(b.g))), Color::encode(fn(a.z, Color::decode(b.b))), b.a); }

template <typename T>
concept Fore = std::same_as<T, Vec2> ||
               std::same_as<T, Vec3> ||
               std::same_as<T, Vec4> ||
               std::same_as<T, Mat2> ||
               std::same_as<T, Mat3> ||
               std::same_as<T, Mat4> ||
               std::same_as<T, Color>;

// clang-format off
template <Fore T> T abs(T t) { return fore(t, [](float x) { return fabsf(x); }); }

template <Fore T> T sqrt(T t) { return fore(t, [](float x) { return sqrtf(x); }); }

template <Fore T> T cbrt(T t) { return fore(t, [](float x) { return cbrtf(x); }); }

template <Fore T> T exp(T t) { return fore(t, [](float x) { return expf(x); }); }

template <Fore T> T exp2(T t) { return fore(t, [](float x) { return exp2f(x); }); }

template <Fore T> T ln(T t) { return fore(t, [](float x) { return logf(x); }); }

template <Fore T> T log10(T t) { return fore(t, [](float x) { return log10f(x); }); }

template <Fore T> T log2(T t) { return fore(t, [](float x) { return log2f(x); }); }

template <Fore T> T sin(T t) { return fore(t, [](float x) { return sinf(x); }); }

template <Fore T> T cos(T t) { return fore(t, [](float x) { return cosf(x); }); }

template <Fore T> T tan(T t) { return fore(t, [](float x) { return tanf(x); }); }

template <Fore T> T asin(T t) { return fore(t, [](float x) { return asinf(x); }); }

template <Fore T> T acos(T t) { return fore(t, [](float x) { return acosf(x); }); }

template <Fore T> T atan(T t) { return fore(t, [](float x) { return atanf(x); }); }

template <Fore T> T sinh(T t) { return fore(t, [](float x) { return sinhf(x); }); }

template <Fore T> T cosh(T t) { return fore(t, [](float x) { return coshf(x); }); }

template <Fore T> T tanh(T t) { return fore(t, [](float x) { return tanhf(x); }); }

template <Fore T> T asinh(T t) { return fore(t, [](float x) { return asinhf(x); }); }

template <Fore T> T acosh(T t) { return fore(t, [](float x) { return acoshf(x); }); }

template <Fore T> T atanh(T t) { return fore(t, [](float x) { return atanhf(x); }); }

template <Fore T> T ceil(T t) { return fore(t, [](float x) { return ceilf(x); }); }

template <Fore T> T floor(T t) { return fore(t, [](float x) { return floorf(x); }); }

template <Fore T> T trunc(T t) { return fore(t, [](float x) { return truncf(x); }); }

template <Fore T> T round(T t) { return fore(t, [](float x) { return roundf(x); }); }

template <Fore T> T mod(T a, T b) { return fore(a, b, [](float x, float y) { return fmodf(x, y); }); }
template <Fore T> T mod(T a, float b) { return fore(a, b, [](float x, float y) { return fmodf(x, y); }); }
template <Fore T> T mod(float a, T b) { return fore(a, b, [](float x, float y) { return fmodf(x, y); }); }

template <Fore T> T min(T a, T b) { return fore(a, b, [](float x, float y) { return fminf(x, y); }); }
template <Fore T> T min(T a, float b) { return fore(a, b, [](float x, float y) { return fminf(x, y); }); }
template <Fore T> T min(float a, T b) { return fore(a, b, [](float x, float y) { return fminf(x, y); }); }

template <Fore T> T max(T a, T b) { return fore(a, b, [](float x, float y) { return fmaxf(x, y); }); }
template <Fore T> T max(T a, float b) { return fore(a, b, [](float x, float y) { return fmaxf(x, y); }); }
template <Fore T> T max(float a, T b) { return fore(a, b, [](float x, float y) { return fmaxf(x, y); }); }

template <Fore T> T pow(T a, T b) { return fore(a, b, [](float x, float y) { return powf(x, y); }); }
template <Fore T> T pow(T a, float b) { return fore(a, b, [](float x, float y) { return powf(x, y); }); }
template <Fore T> T pow(float a, T b) { return fore(a, b, [](float x, float y) { return powf(x, y); }); }

template <Fore T> T log(T a, T b) { return fore(a, b, [](float x, float y) { return logf(x) / logf(y); }); }
template <Fore T> T log(T a, float b) { return fore(a, b, [](float x, float y) { return logf(x) / logf(y); }); }
template <Fore T> T log(float a, T b) { return fore(a, b, [](float x, float y) { return logf(x) / logf(y); }); }

template <Fore T> T atan2(T a, T b) { return fore(a, b, [](float x, float y) { return atan2f(x, y); }); }
template <Fore T> T atan2(T a, float b) { return fore(a, b, [](float x, float y) { return atan2f(x, y); }); }
template <Fore T> T atan2(float a, T b) { return fore(a, b, [](float x, float y) { return atan2f(x, y); }); }

template <Fore T> T clamp(T a, T l, T u) { return min(max(a, l), u); }
template <Fore T> T clamp(T a, T l, float u) { return min(max(a, l), u); }
template <Fore T> T clamp(T a, float l, T u) { return min(max(a, l), u); }
template <Fore T> T clamp(T a, float l, float u) { return min(max(a, l), u); }
template <Fore T> T clamp(float a, T l, T u) { return min(max(a, l), u); }
template <Fore T> T clamp(float a, T l, float u) { return min(max(a, l), u); }
template <Fore T> T clamp(float a, float l, T u) { return min(fmax(a, l), u); }
template <Fore T> T clamp01(T a) { return min(max(a, 0.0f), 1.0f); }

template <Fore T> T lerp(T a, T b, float t) { return a * (1.0f - t) + b * t; }
template <Fore T> T lerp(T a, float b, float t) { return a * (1.0f - t) + b * t; }
template <Fore T> T lerp(float a, T b, float t) { return a * (1.0f - t) + b * t; }
// clang-format on

inline Color Color::from_linear(Vec4 c) { return Color(encode(c.x), encode(c.y), encode(c.z), quant(c.w)); }

inline Color Color::from_linear(Vec3 c) { return from_linear(Vec4(c, 1.0f)); }

inline Vec4 Color::to_linear() const { return Vec4(decode(r), decode(g), decode(b), norm(a)); }

inline Color Color::from_norm(Vec4 c) { return Color(quant(c.x), quant(c.y), quant(c.z), quant(c.w)); }

inline Color Color::from_norm(Vec3 c) { return from_norm(Vec4(c, 1.0f)); }

inline Vec4 Color::to_norm() const { return Vec4(norm(r), norm(g), norm(b), norm(a)); }

inline Color Color::from_hsv(Vec4 h) {
    Vec3 k   = mod(h.x * 6.0f + Vec3(0.0f, 4.0f, 2.0f), 6.0f);
    Vec3 f   = clamp(min(k, 4.0f - k), 0.0f, 1.0f);
    Vec3 rgb = h.z * lerp(Vec3(1.0f), f, h.y);
    return Color(quant(rgb.x), quant(rgb.y), quant(rgb.z), quant(h.w));
}

inline Color Color::from_hsv(Vec3 h) { return from_hsv(Vec4(h.x, h.y, h.z, 1.0f)); }

inline Vec4 Color::to_hsv() const {
    Vec4  c  = to_norm();
    float mx = fmax(c.x, fmax(c.y, c.z));
    float mn = fmin(c.x, fmin(c.y, c.z));
    float d  = mx - mn;
    float h  = d == 0.0f ? 0.0f : (mx == c.x ? fmod((c.y - c.z) / d, 6.0f) : (mx == c.y ? (c.z - c.x) / d + 2.0f : (c.x - c.y) / d + 4.0f)) / 6.0f;
    h += h < 0.0f ? 1.0f : 0.0f;
    float s = mx == 0.0f ? 0.0f : d / mx;
    return Vec4(h, s, mx, c.w);
}

inline Color Color::from_hsl(Vec4 h) {
    float l = h.z, s = h.y;
    float v  = l + s * fmin(l, 1.0f - l);
    float sv = v == 0.0f ? 0.0f : 2.0f * (1.0f - l / v);
    return from_hsv(Vec4(h.x, sv, v, h.w));
}

inline Color Color::from_hsl(Vec3 h) { return from_hsl(Vec4(h.x, h.y, h.z, 1.0f)); }

inline Vec4 Color::to_hsl() const {
    Vec4  c  = to_norm();
    float mx = fmax(c.x, fmax(c.y, c.z));
    float mn = fmin(c.x, fmin(c.y, c.z));
    float d  = mx - mn;
    float l  = (mx + mn) * 0.5f;
    float h  = 0.0f;
    h        = d == 0.0f ? 0.0f : (mx == c.x ? (c.y - c.z) / d + (c.y < c.z ? 6.0f : 0.0f) : (mx == c.y ? (c.z - c.x) / d + 2.0f : (c.x - c.y) / d + 4.0f)) / 6.0f;
    h += h < 0.0f ? 1.0f : 0.0f;
    float s = d == 0.0f ? 0.0f : (l > 0.5f ? d / (2.0f - mx - mn) : d / (mx + mn));
    return Vec4(h, s, l, c.w);
}

inline Color Color::from_hwb(Vec4 h) {
    Vec3  k   = mod(h.x * 6.0f + Vec3(0.0f, 4.0f, 2.0f), 6.0f);
    Vec3  f   = clamp(min(k, 4.0f - k), 0.0f, 1.0f);
    Vec3  rgb = lerp(Vec3(1.0f), f, 1.0f); // base hue at v=1,s=1
    float w = h.y, bl = h.z;
    float q = quant(w / (w + bl));
    Vec3  r = rgb * (1.0f - w - bl) + Vec3(w);
    return (w + bl >= 1.0f) ? Color(q, q, q, quant(h.w))
                            : Color(quant(r.x), quant(r.y), quant(r.z), quant(h.w));
}

inline Color Color::from_hwb(Vec3 h) { return from_hwb(Vec4(h.x, h.y, h.z, 1.0f)); }

inline Vec4 Color::to_hwb() const {
    Vec4  c  = to_norm();
    float mx = fmax(c.x, fmax(c.y, c.z));
    float mn = fmin(c.x, fmin(c.y, c.z));
    return Vec4(to_hsv().x, mn, 1.0f - mx, c.w);
}

inline Color Color::from_oklab(Vec4 v) {
    Vec3 lab = Vec3(v.x, v.y, v.z);
    Vec3 t   = Vec3(lab.x, lab.x, lab.x) + Vec3(0.3963377774f, -0.1055613458f, -0.0894841775f) * lab.y + Vec3(0.2158037573f, -0.0638541728f, -1.2914855480f) * lab.z;
    Vec3 c   = t * t * t;
    Vec3 rgb = Vec3(4.0767416621f, -1.2684380046f, -0.0041960863f) * c.x + Vec3(-3.3077115913f, 2.6097574011f, -0.7034186147f) * c.y + Vec3(0.2309699292f, -0.3413193965f, 1.7076147010f) * c.z;
    return Color(encode(rgb.x), encode(rgb.y), encode(rgb.z), quant(v.w));
}

inline Color Color::from_oklab(Vec3 v) { return from_oklab(Vec4(v.x, v.y, v.z, 1.0f)); }

inline Vec4 Color::to_oklab() const {
    Vec4  L   = to_linear();
    Vec3  lms = Vec3(0.4122214708f, 0.2119034982f, 0.0883024619f) * L.x + Vec3(0.5363325363f, 0.6806995451f, 0.2817188376f) * L.y + Vec3(0.0514459929f, 0.1073969566f, 0.6299787005f) * L.z;
    Vec3  c   = cbrt(lms);
    float L_  = 0.2104542553f * c.x + 0.7936177850f * c.y - 0.0040720468f * c.z;
    float a_  = 1.9779984951f * c.x - 2.4285922050f * c.y + 0.4505937099f * c.z;
    float b_  = 0.0259040371f * c.x + 0.7827717662f * c.y - 0.8086757660f * c.z;
    return Vec4(L_, a_, b_, L.w);
}

inline Color Color::from_oklch(Vec4 v) {
    float h = v.z * 2.0f * M_PI;
    return from_oklab(Vec4(v.x, v.y * cos(h), v.y * sin(h), v.w));
}

inline Color Color::from_oklch(Vec3 v) { return from_oklch(Vec4(v.x, v.y, v.z, 1.0f)); }

inline Vec4 Color::to_oklch() const {
    Vec4  lab = to_oklab();
    float C   = sqrt(lab.y * lab.y + lab.z * lab.z);
    float h   = atan2(lab.z, lab.y);
    h += h < 0.0f ? 2.0f * M_PI : 0.0f;
    return Vec4(lab.x, C, h / (2.0f * M_PI), lab.w);
}

inline Vec4 premul(Color c) {
    Vec4 lin = c.to_linear();
    return Vec4(lin.x * lin.w, lin.y * lin.w, lin.z * lin.w, lin.w);
}

inline Color prediv(Vec4 c) { return Color::from_linear(Vec4(c.w == 0.0f ? 0.0f : c.x / c.w, c.w == 0.0f ? 0.0f : c.y / c.w, c.w == 0.0f ? 0.0f : c.z / c.w, c.w)); }

inline float luminance(Color c) {
    Vec4 lin = c.to_linear();
    return 0.2126f * lin.x + 0.7152f * lin.y + 0.0722f * lin.z;
}

inline float brightness(Color c) { return fmax(Color::norm(c.r), fmax(Color::norm(c.g), Color::norm(c.b))); }

inline Color brightness(Color c, float v) {
    Vec4  n = c.to_norm();
    float b = fmax(n.x, fmax(n.y, n.z));
    return b == 0.0f ? Color(Color::quant(v), Color::quant(v), Color::quant(v), Color::quant(n.w)) : Color::from_norm(Vec4(n.x * (v / b), n.y * (v / b), n.z * (v / b), n.w));
}

inline Color saturation(Color c, float v) {
    Vec4 h = c.to_hsv();
    return Color::from_hsv(Vec4(h.x, v, h.z, h.w));
}

inline Color hue(Color c, float v) {
    Vec4  h    = c.to_hsv();
    float newH = fmodf(h.x + v, 1.0f);
    newH += newH < 0.0f ? 1.0f : 0.0f;
    return Color::from_hsv(Vec4(newH, h.y, h.z, h.w));
}

inline Color contrast(Color c, float v) {
    Vec4 n = c.to_norm();
    return Color::from_norm(Vec4((n.x - 0.5f) * v + 0.5f, (n.y - 0.5f) * v + 0.5f, (n.z - 0.5f) * v + 0.5f, n.w));
}

// Linear blending

inline Color lb_screen(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return 1.0f - (1.0f - x) * (1.0f - y); });
}

inline Color lb_multiply(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return x * y; });
}

inline Color lb_overlay(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return x < 0.5f ? 2.0f * x * y : 1.0f - 2.0f * (1.0f - x) * (1.0f - y); });
}

inline Color lb_soft_light(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return (1.0f - 2.0f * y) * x * x + 2.0f * y * x; });
}

inline Color lb_hard_light(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return y < 0.5f ? 2.0f * x * y : 1.0f - 2.0f * (1.0f - x) * (1.0f - y); });
}

inline Color lb_difference(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return fabsf(x - y); });
}

inline Color lb_exclusion(Color a, Color b) {
    return fore(a, b, [](float x, float y) { return x + y - 2.0f * x * y; });
}

// Gamma blending

inline Color gb_screen(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(1.0f - (1.0f - A.x) * (1.0f - B.x), 1.0f - (1.0f - A.y) * (1.0f - B.y), 1.0f - (1.0f - A.z) * (1.0f - B.z), A.w + B.w * (1.0f - A.w)));
}

inline Color gb_multiply(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(A.x * B.x, A.y * B.y, A.z * B.z, A.w + B.w * (1.0f - A.w)));
}

inline Color gb_overlay(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(A.x < 0.5f ? 2.0f * A.x * B.x : 1.0f - 2.0f * (1.0f - A.x) * (1.0f - B.x), A.y < 0.5f ? 2.0f * A.y * B.y : 1.0f - 2.0f * (1.0f - A.y) * (1.0f - B.y), A.z < 0.5f ? 2.0f * A.z * B.z : 1.0f - 2.0f * (1.0f - A.z) * (1.0f - B.z), A.w + B.w * (1.0f - A.w)));
}

inline Color gb_soft_light(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4((1.0f - 2.0f * B.x) * A.x * A.x + 2.0f * B.x * A.x, (1.0f - 2.0f * B.y) * A.y * A.y + 2.0f * B.y * A.y, (1.0f - 2.0f * B.z) * A.z * A.z + 2.0f * B.z * A.z, A.w + B.w * (1.0f - A.w)));
}

inline Color gb_hard_light(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(B.x < 0.5f ? 2.0f * A.x * B.x : 1.0f - 2.0f * (1.0f - A.x) * (1.0f - B.x), B.y < 0.5f ? 2.0f * A.y * B.y : 1.0f - 2.0f * (1.0f - A.y) * (1.0f - B.y), B.z < 0.5f ? 2.0f * A.z * B.z : 1.0f - 2.0f * (1.0f - A.z) * (1.0f - B.z), A.w + B.w * (1.0f - A.w)));
}

inline Color gb_difference(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(fabsf(A.x - B.x), fabsf(A.y - B.y), fabsf(A.z - B.z), A.w + B.w * (1.0f - A.w)));
}

inline Color gb_exclusion(Color a, Color b) {
    Vec4 A = a.to_norm();
    Vec4 B = b.to_norm();
    return Color::from_norm(Vec4(A.x + B.x - 2.0f * A.x * B.x, A.y + B.y - 2.0f * A.y * B.y, A.z + B.z - 2.0f * A.z * B.z, A.w + B.w * (1.0f - A.w)));
}
