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
#include <cmath>
#include <cstdint>
#include <cstdlib>

struct Vec2;
struct Vec3;
struct Vec4;

struct Vec2 {
    float x;
    float y;

    Vec2() = default;
    Vec2(float x, float y) : x(x), y(y) {}

    Vec2(SDL_FPoint v) : x(v.x), y(v.y) {}

    inline explicit Vec2(Vec3 v);
    inline explicit Vec2(Vec4 v);

    operator SDL_FPoint() const { return {x, y}; }

    Vec2 &operator+=(Vec2 b);
    Vec2 &operator-=(Vec2 b);
    Vec2 &operator*=(Vec2 b);
    Vec2 &operator/=(Vec2 b);
    Vec2 &operator+=(SDL_FPoint b);
    Vec2 &operator-=(SDL_FPoint b);
    Vec2 &operator*=(SDL_FPoint b);
    Vec2 &operator/=(SDL_FPoint b);
    Vec2 &operator+=(float b);
    Vec2 &operator-=(float b);
    Vec2 &operator*=(float b);
    Vec2 &operator/=(float b);

    inline explicit operator Vec3() const;
    inline explicit operator Vec4() const;
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
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3(Vec2 v, float z) : x(v.x), y(v.y), z(z) {}
    Vec3(float x, Vec2 v) : x(x), y(v.x), z(v.y) {}

    inline explicit Vec3(Vec2 v);
    inline explicit Vec3(Vec4 v);

    Vec3 &operator+=(Vec3 b);
    Vec3 &operator-=(Vec3 b);
    Vec3 &operator*=(Vec3 b);
    Vec3 &operator/=(Vec3 b);
    Vec3 &operator+=(float b);
    Vec3 &operator-=(float b);
    Vec3 &operator*=(float b);
    Vec3 &operator/=(float b);

    inline explicit operator Vec2() const;
    inline explicit operator Vec4() const;
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
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vec4(SDL_FRect v) : x(v.x), y(v.y), z(v.w), w(v.h) {}

    Vec4(Vec2 v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {}
    Vec4(Vec2 v, Vec2 u) : x(v.x), y(v.y), z(u.x), w(u.y) {}
    Vec4(float x, Vec2 v, float w) : x(x), y(v.x), z(v.y), w(w) {}
    Vec4(float x, float y, Vec2 v) : x(x), y(y), z(v.x), w(v.y) {}
    Vec4(Vec3 v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}
    Vec4(float x, Vec3 v) : x(x), y(v.x), z(v.y), w(v.z) {}

    inline explicit Vec4(Vec2 v);
    inline explicit Vec4(Vec3 v);

    operator SDL_FRect() const { return {x, y, z, w}; }

    Vec4 &operator+=(Vec4 b);
    Vec4 &operator-=(Vec4 b);
    Vec4 &operator*=(Vec4 b);
    Vec4 &operator/=(Vec4 b);
    Vec4 &operator+=(SDL_FRect b);
    Vec4 &operator-=(SDL_FRect b);
    Vec4 &operator*=(SDL_FRect b);
    Vec4 &operator/=(SDL_FRect b);
    Vec4 &operator+=(float b);
    Vec4 &operator-=(float b);
    Vec4 &operator*=(float b);
    Vec4 &operator/=(float b);

    inline explicit operator Vec2() const;
    inline explicit operator Vec3() const;
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

inline Vec2::operator Vec3() const { return Vec3(x, y, 0.0f); }
inline Vec2::operator Vec4() const { return Vec4(x, y, 0.0f, 0.0f); }
inline Vec3::operator Vec2() const { return Vec2(x, y); }
inline Vec3::operator Vec4() const { return Vec4(x, y, z, 0.0f); }
inline Vec4::operator Vec2() const { return Vec2(x, y); }
inline Vec4::operator Vec3() const { return Vec3(x, y, z); }

inline Vec2 abs(Vec2 v) { return Vec2(fabs(v.x), fabs(v.y)); }
inline Vec3 abs(Vec3 v) { return Vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }
inline Vec4 abs(Vec4 v) { return Vec4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w)); }

inline Vec2 neg(Vec2 v) { return Vec2(-v.x, -v.y); }
inline Vec3 neg(Vec3 v) { return Vec3(-v.x, -v.y, -v.z); }
inline Vec4 neg(Vec4 v) { return Vec4(-v.x, -v.y, -v.z, -v.w); }

inline Vec2 inv(Vec2 v) { return Vec2(1.0f / v.x, 1.0f / v.y); }
inline Vec3 inv(Vec3 v) { return Vec3(1.0f / v.x, 1.0f / v.y, 1.0f / v.z); }
inline Vec4 inv(Vec4 v) { return Vec4(1.0f / v.x, 1.0f / v.y, 1.0f / v.z, 1.0f / v.w); }

inline Vec2 pow(Vec2 a, Vec2 b) { return Vec2(pow(a.x, b.x), pow(a.y, b.y)); }
inline Vec3 pow(Vec3 a, Vec3 b) { return Vec3(pow(a.x, b.x), pow(a.y, b.y), pow(a.z, b.z)); }
inline Vec4 pow(Vec4 a, Vec4 b) { return Vec4(pow(a.x, b.x), pow(a.y, b.y), pow(a.z, b.z), pow(a.w, b.w)); }

inline Vec2 mod(Vec2 a, Vec2 b) { return Vec2(fmod(a.x, b.x), fmod(a.y, b.y)); }
inline Vec3 mod(Vec3 a, Vec3 b) { return Vec3(fmod(a.x, b.x), fmod(a.y, b.y), fmod(a.z, b.z)); }
inline Vec4 mod(Vec4 a, Vec4 b) { return Vec4(fmod(a.x, b.x), fmod(a.y, b.y), fmod(a.z, b.z), fmod(a.w, b.w)); }

inline Vec2 log(Vec2 v, float b) { return Vec2(log(v.x) / log(b), log(v.y) / log(b)); }
inline Vec3 log(Vec3 v, float b) { return Vec3(log(v.x) / log(b), log(v.y) / log(b), log(v.z) / log(b)); }
inline Vec4 log(Vec4 v, float b) { return Vec4(log(v.x) / log(b), log(v.y) / log(b), log(v.z) / log(b), log(v.w) / log(b)); }

inline Vec2 sqrt(Vec2 v) { return Vec2(sqrt(v.x), sqrt(v.y)); }
inline Vec3 sqrt(Vec3 v) { return Vec3(sqrt(v.x), sqrt(v.y), sqrt(v.z)); }
inline Vec4 sqrt(Vec4 v) { return Vec4(sqrt(v.x), sqrt(v.y), sqrt(v.z), sqrt(v.w)); }

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

inline Vec2 min(Vec2 a, Vec2 b) { return Vec2(fmin(a.x, b.x), fmin(a.y, b.y)); }
inline Vec3 min(Vec3 a, Vec3 b) { return Vec3(fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z)); }
inline Vec4 min(Vec4 a, Vec4 b) { return Vec4(fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z), fmin(a.w, b.w)); }

inline Vec2 max(Vec2 a, Vec2 b) { return Vec2(fmax(a.x, b.x), fmax(a.y, b.y)); }
inline Vec3 max(Vec3 a, Vec3 b) { return Vec3(fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z)); }
inline Vec4 max(Vec4 a, Vec4 b) { return Vec4(fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z), fmax(a.w, b.w)); }

inline Vec2 clamp(Vec2 v, Vec2 a, Vec2 b) { return min(max(v, a), b); }
inline Vec3 clamp(Vec3 v, Vec3 a, Vec3 b) { return min(max(v, a), b); }
inline Vec4 clamp(Vec4 v, Vec4 a, Vec4 b) { return min(max(v, a), b); }

inline Vec2 lerp(Vec2 a, Vec2 b, float t) { return a * (1.0f - t) + b * t; }
inline Vec3 lerp(Vec3 a, Vec3 b, float t) { return a * (1.0f - t) + b * t; }
inline Vec4 lerp(Vec4 a, Vec4 b, float t) { return a * (1.0f - t) + b * t; }

inline Vec2 floor(Vec2 v) { return Vec2(floor(v.x), floor(v.y)); }
inline Vec3 floor(Vec3 v) { return Vec3(floor(v.x), floor(v.y), floor(v.z)); }
inline Vec4 floor(Vec4 v) { return Vec4(floor(v.x), floor(v.y), floor(v.z), floor(v.w)); }

inline Vec2 ceil(Vec2 v) { return Vec2(ceil(v.x), ceil(v.y)); }
inline Vec3 ceil(Vec3 v) { return Vec3(ceil(v.x), ceil(v.y), ceil(v.z)); }
inline Vec4 ceil(Vec4 v) { return Vec4(ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w)); }

inline Vec2 round(Vec2 v) { return Vec2(round(v.x), round(v.y)); }
inline Vec3 round(Vec3 v) { return Vec3(round(v.x), round(v.y), round(v.z)); }
inline Vec4 round(Vec4 v) { return Vec4(round(v.x), round(v.y), round(v.z), round(v.w)); }

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

template <typename Fn> Vec2 fore(Vec2 v, Fn fn) { return Vec2(fn(v.x), fn(v.y)); }
template <typename Fn> Vec3 fore(Vec3 v, Fn fn) { return Vec3(fn(v.x), fn(v.y), fn(v.z)); }
template <typename Fn> Vec4 fore(Vec4 v, Fn fn) { return Vec4(fn(v.x), fn(v.y), fn(v.z), fn(v.w)); }

template <typename Fn> Vec2 fore(Vec2 a, Vec2 b, Fn fn) { return Vec2(fn(a.x, b.x), fn(a.y, b.y)); }
template <typename Fn> Vec3 fore(Vec3 a, Vec3 b, Fn fn) { return Vec3(fn(a.x, b.x), fn(a.y, b.y), fn(a.z, b.z)); }
template <typename Fn> Vec4 fore(Vec4 a, Vec4 b, Fn fn) { return Vec4(fn(a.x, b.x), fn(a.y, b.y), fn(a.z, b.z), fn(a.w, b.w)); }

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

struct Color {
    using U8 = std::uint8_t;

    U8 r;
    U8 g;
    U8 b;
    U8 a;

    // clang-format off
    static U8    u8(float v) { return fmin(fmax(v * 255.0f, 0.0f), 255.0f); }
    static U8    u8(int v) { return v < 0 ? 0 : v > 255 ? 255 : v; }
    static float f(U8 v) { return v / 255.0f; }
    // clang-format on

    Color() = default;

    Color(U8 r, U8 g, U8 b, U8 a = 255) : r(r), g(g), b(b), a(a) {}
    Color(U8 v, U8 a = 255) : r(v), g(v), b(v), a(a) {}
    Color(float r, float g, float b, float a = 1.0f) : r(u8(r)), g(u8(g)), b(u8(b)), a(u8(a)) {}
    Color(float v, float a = 1.0f) : r(u8(v)), g(u8(v)), b(u8(v)), a(u8(a)) {}
    Color(Vec4 v) : r(u8(v.x)), g(u8(v.y)), b(u8(v.z)), a(u8(v.w)) {}
    Color(Vec3 v, float a = 1.0f) : r(u8(v.x)), g(u8(v.y)), b(u8(v.z)), a(u8(a)) {}
    Color(std::uint32_t rgba) : r((rgba >> 24) & 0xFF), g((rgba >> 16) & 0xFF), b((rgba >> 8) & 0xFF), a((rgba >> 0) & 0xFF) {}

    static Color from_hsv(Vec4 hsv) {
        float h = hsv.x;
        float s = hsv.y;
        float v = hsv.z;
        float a = hsv.w;

        float c  = v * s;
        float hh = h * 6.0f;
        float x  = c * (1.0f - fabs(fmod(hh, 2.0f) - 1.0f));

        float r = 0, g = 0, b = 0;
        if (hh < 1) {
            r = c;
            g = x;
        } else if (hh < 2) {
            r = x;
            g = c;
        } else if (hh < 3) {
            g = c;
            b = x;
        } else if (hh < 4) {
            g = x;
            b = c;
        } else if (hh < 5) {
            r = x;
            b = c;
        } else {
            r = c;
            b = x;
        }

        float m = v - c;
        return Color(r + m, g + m, b + m, a);
    }

    static Color from_hsv(Vec3 hsv) {
        return from_hsv(Vec4(hsv, 1.0f));
    }

    static Vec4 to_hsv(Color c) {
        float r = f(c.r), g = f(c.g), b = f(c.b);
        float maxv = fmax(r, fmax(g, b));
        float minv = fmin(r, fmin(g, b));
        float d    = maxv - minv;

        float h = 0.0f;
        if (d != 0.0f) {
            if (maxv == r)
                h = fmod((g - b) / d, 6.0f);
            else if (maxv == g)
                h = (b - r) / d + 2.0f;
            else
                h = (r - g) / d + 4.0f;
            h /= 6.0f;
            if (h < 0) h += 1.0f;
        }

        float s = maxv == 0 ? 0 : d / maxv;
        return Vec4(h, s, maxv, f(c.a));
    }

    static Color from_hsl(Vec4 hsl) {
        float h = hsl.x, s = hsl.y, l = hsl.z, a = hsl.w;
        float c  = (1.0f - fabs(2.0f * l - 1.0f)) * s;
        float hh = h * 6.0f;
        float x  = c * (1.0f - fabs(fmod(hh, 2.0f) - 1.0f));

        float r = 0, g = 0, b = 0;
        if (hh < 1) {
            r = c;
            g = x;
        } else if (hh < 2) {
            r = x;
            g = c;
        } else if (hh < 3) {
            g = c;
            b = x;
        } else if (hh < 4) {
            g = x;
            b = c;
        } else if (hh < 5) {
            r = x;
            b = c;
        } else {
            r = c;
            b = x;
        }

        float m = l - c * 0.5f;
        return Color(r + m, g + m, b + m, a);
    }

    static Color from_hsl(Vec3 hsl) {
        return from_hsl(Vec4(hsl, 1.0f));
    }

    static Vec4 to_hsl(Color c) {
        float r = f(c.r), g = f(c.g), b = f(c.b);
        float maxv = fmax(r, fmax(g, b));
        float minv = fmin(r, fmin(g, b));
        float d    = maxv - minv;

        float l = (maxv + minv) * 0.5f;
        float s = d == 0 ? 0 : d / (1.0f - fabs(2.0f * l - 1.0f));

        float h = 0;
        if (d != 0) {
            if (maxv == r)
                h = fmod((g - b) / d, 6.0f);
            else if (maxv == g)
                h = (b - r) / d + 2.0f;
            else
                h = (r - g) / d + 4.0f;
            h /= 6.0f;
            if (h < 0) h += 1.0f;
        }
        return Vec4(h, s, l, f(c.a));
    }

    static Color from_hwb(Vec4 hwb) {
        float h = hwb.x, w = hwb.y, bl = hwb.z, a = hwb.w;
        Color base = from_hsv(Vec4(h, 1, 1, 1));
        float r = f(base.r), g = f(base.g), b = f(base.b);
        float sum = w + bl;
        if (sum > 1.0f) {
            w /= sum;
            bl /= sum;
        }
        return Color(
            r * (1 - w - bl) + w,
            g * (1 - w - bl) + w,
            b * (1 - w - bl) + w,
            a
        );
    }

    static Color from_hwb(Vec3 hwb) {
        return from_hwb(Vec4(hwb, 1.0f));
    }

    static Vec4 to_hwb(Color c) {
        Vec4  hsv = to_hsv(c);
        float r = f(c.r), g = f(c.g), b = f(c.b);
        float w  = fmin(r, fmin(g, b));
        float bl = 1.0f - fmax(r, fmax(g, b));
        return Vec4(hsv.x, w, bl, f(c.a));
    }

    static Vec3 oklab_to_rgb(Vec3 c) {
        float l = c.x + 0.3963377774f * c.y + 0.2158037573f * c.z;
        float m = c.x - 0.1055613458f * c.y - 0.0638541728f * c.z;
        float s = c.x - 0.0894841775f * c.y - 1.2914855480f * c.z;
        l       = pow(l, 3.0f);
        m       = pow(m, 3.0f);
        s       = pow(s, 3.0f);
        return Vec3(
            4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
            -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
            -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s
        );
    }

    static Vec3 oklab_from_rgb(Vec3 c) {
        float l = 0.4122214708f * c.x + 0.5363325363f * c.y + 0.0514459929f * c.z;
        float m = 0.2119034982f * c.x + 0.6806995451f * c.y + 0.1073969566f * c.z;
        float s = 0.0883024619f * c.x + 0.2817188376f * c.y + 0.6299787005f * c.z;
        l       = cbrt(l);
        m       = cbrt(m);
        s       = cbrt(s);
        return Vec3(
            0.2104542553f * l + 0.7936177850f * m - 0.0040720468f * s,
            1.9779984951f * l - 2.4285922050f * m + 0.4505937099f * s,
            0.0259040371f * l + 0.7827717662f * m - 0.8086757660f * s
        );
    }

    static Color from_oklab(Vec4 v) {
        Vec3 rgb = oklab_to_rgb(Vec3(v));
        return Color(rgb.x, rgb.y, rgb.z, v.w);
    }

    static Color from_oklab(Vec3 hwb) {
        return from_oklab(Vec4(hwb, 1.0f));
    }

    static Vec4 to_oklab(Color c) {
        Vec3 v = oklab_from_rgb(Vec3(c));
        return Vec4(v.x, v.y, v.z, f(c.a));
    }

    static Color from_oklch(Vec4 v) {
        float a = v.y * cos(v.z * 2.0f * 3.14159265f);
        float b = v.y * sin(v.z * 2.0f * 3.14159265f);
        return from_oklab(Vec4(v.x, a, b, v.w));
    }

    static Color from_oklch(Vec3 hwb) {
        return from_oklch(Vec4(hwb, 1.0f));
    }

    static Vec4 to_oklch(Color c) {
        Vec4  l = to_oklab(c);
        float s = sqrt(l.y * l.y + l.z * l.z);
        float h = atan2(l.z, l.y) / (2.0f * 3.14159265f);
        if (h < 0) h += 1.0f;
        return Vec4(l.x, s, h, l.w);
    }

    inline Color &operator+=(Color b);
    inline Color &operator-=(Color b);
    inline Color &operator*=(Color b);
    inline Color &operator/=(Color b);
    inline Color &operator+=(Vec4 b);
    inline Color &operator-=(Vec4 b);
    inline Color &operator*=(Vec4 b);
    inline Color &operator/=(Vec4 b);
    inline Color &operator+=(Vec3 b);
    inline Color &operator-=(Vec3 b);
    inline Color &operator*=(Vec3 b);
    inline Color &operator/=(Vec3 b);
    inline Color &operator+=(float b);
    inline Color &operator-=(float b);
    inline Color &operator*=(float b);
    inline Color &operator/=(float b);

    operator Vec4() const { return Vec4(f(r), f(g), f(b), f(a)); }
    operator Vec3() const { return Vec3(f(r), f(g), f(b)); }
    operator std::uint32_t() const { return (r << 24) + (g << 16) + (b << 8) + a; }
};

inline Color operator+(Color a) { return Color(Color::u8(+a.r), Color::u8(+a.g), Color::u8(+a.b), 255); }
inline Color operator-(Color a) { return Color(Color::u8(-a.r), Color::u8(-a.g), Color::u8(-a.b), 255); }

inline Color operator+(Color a, Color b) { return Color(Color::u8(Color::f(a.r) + Color::f(b.r)), Color::u8(Color::f(a.g) + Color::f(b.g)), Color::u8(Color::f(a.b) + Color::f(b.b)), Color::u8(Color::f(a.a) + Color::f(b.a))); }
inline Color operator-(Color a, Color b) { return Color(Color::u8(Color::f(a.r) - Color::f(b.r)), Color::u8(Color::f(a.g) - Color::f(b.g)), Color::u8(Color::f(a.b) - Color::f(b.b)), Color::u8(Color::f(a.a) - Color::f(b.a))); }
inline Color operator*(Color a, Color b) { return Color(Color::u8(Color::f(a.r) * Color::f(b.r)), Color::u8(Color::f(a.g) * Color::f(b.g)), Color::u8(Color::f(a.b) * Color::f(b.b)), Color::u8(Color::f(a.a) * Color::f(b.a))); }
inline Color operator/(Color a, Color b) { return Color(Color::u8(Color::f(a.r) / Color::f(b.r)), Color::u8(Color::f(a.g) / Color::f(b.g)), Color::u8(Color::f(a.b) / Color::f(b.b)), Color::u8(Color::f(a.a) / Color::f(b.a))); }
inline Color operator+(Color a, Vec4 b) { return Color(Color::u8(Color::f(a.r) + Color::f(b.x)), Color::u8(Color::f(a.g) + Color::f(b.y)), Color::u8(Color::f(a.b) + Color::f(b.z)), Color::u8(Color::f(a.a) + Color::f(b.w))); }
inline Color operator-(Color a, Vec4 b) { return Color(Color::u8(Color::f(a.r) - Color::f(b.x)), Color::u8(Color::f(a.g) - Color::f(b.y)), Color::u8(Color::f(a.b) - Color::f(b.z)), Color::u8(Color::f(a.a) - Color::f(b.w))); }
inline Color operator*(Color a, Vec4 b) { return Color(Color::u8(Color::f(a.r) * Color::f(b.x)), Color::u8(Color::f(a.g) * Color::f(b.y)), Color::u8(Color::f(a.b) * Color::f(b.z)), Color::u8(Color::f(a.a) * Color::f(b.w))); }
inline Color operator/(Color a, Vec4 b) { return Color(Color::u8(Color::f(a.r) / Color::f(b.x)), Color::u8(Color::f(a.g) / Color::f(b.y)), Color::u8(Color::f(a.b) / Color::f(b.z)), Color::u8(Color::f(a.a) / Color::f(b.w))); }
inline Color operator+(Vec4 a, Color b) { return Color(Color::u8(Color::f(a.x) + Color::f(b.r)), Color::u8(Color::f(a.y) + Color::f(b.g)), Color::u8(Color::f(a.z) + Color::f(b.b)), Color::u8(Color::f(a.w) + Color::f(b.a))); }
inline Color operator-(Vec4 a, Color b) { return Color(Color::u8(Color::f(a.x) - Color::f(b.r)), Color::u8(Color::f(a.y) - Color::f(b.g)), Color::u8(Color::f(a.z) - Color::f(b.b)), Color::u8(Color::f(a.w) - Color::f(b.a))); }
inline Color operator*(Vec4 a, Color b) { return Color(Color::u8(Color::f(a.x) * Color::f(b.r)), Color::u8(Color::f(a.y) * Color::f(b.g)), Color::u8(Color::f(a.z) * Color::f(b.b)), Color::u8(Color::f(a.w) * Color::f(b.a))); }
inline Color operator/(Vec4 a, Color b) { return Color(Color::u8(Color::f(a.x) / Color::f(b.r)), Color::u8(Color::f(a.y) / Color::f(b.g)), Color::u8(Color::f(a.z) / Color::f(b.b)), Color::u8(Color::f(a.w) / Color::f(b.a))); }
inline Color operator+(Color a, Vec3 b) { return Color(Color::u8(Color::f(a.r) + Color::f(b.x)), Color::u8(Color::f(a.g) + Color::f(b.y)), Color::u8(Color::f(a.b) + Color::f(b.z)), Color::u8(Color::f(a.a))); }
inline Color operator-(Color a, Vec3 b) { return Color(Color::u8(Color::f(a.r) - Color::f(b.x)), Color::u8(Color::f(a.g) - Color::f(b.y)), Color::u8(Color::f(a.b) - Color::f(b.z)), Color::u8(Color::f(a.a))); }
inline Color operator*(Color a, Vec3 b) { return Color(Color::u8(Color::f(a.r) * Color::f(b.x)), Color::u8(Color::f(a.g) * Color::f(b.y)), Color::u8(Color::f(a.b) * Color::f(b.z)), Color::u8(Color::f(a.a))); }
inline Color operator/(Color a, Vec3 b) { return Color(Color::u8(Color::f(a.r) / Color::f(b.x)), Color::u8(Color::f(a.g) / Color::f(b.y)), Color::u8(Color::f(a.b) / Color::f(b.z)), Color::u8(Color::f(a.a))); }
inline Color operator+(Vec3 a, Color b) { return Color(Color::u8(Color::f(a.x) + Color::f(b.r)), Color::u8(Color::f(a.y) + Color::f(b.g)), Color::u8(Color::f(a.z) + Color::f(b.b)), Color::u8(Color::f(b.a))); }
inline Color operator-(Vec3 a, Color b) { return Color(Color::u8(Color::f(a.x) - Color::f(b.r)), Color::u8(Color::f(a.y) - Color::f(b.g)), Color::u8(Color::f(a.z) - Color::f(b.b)), Color::u8(Color::f(b.a))); }
inline Color operator*(Vec3 a, Color b) { return Color(Color::u8(Color::f(a.x) * Color::f(b.r)), Color::u8(Color::f(a.y) * Color::f(b.g)), Color::u8(Color::f(a.z) * Color::f(b.b)), Color::u8(Color::f(b.a))); }
inline Color operator/(Vec3 a, Color b) { return Color(Color::u8(Color::f(a.x) / Color::f(b.r)), Color::u8(Color::f(a.y) / Color::f(b.g)), Color::u8(Color::f(a.z) / Color::f(b.b)), Color::u8(Color::f(b.a))); }
inline Color operator+(Color a, float b) { return Color(Color::u8(Color::f(a.r) + Color::f(b)), Color::u8(Color::f(a.r) + Color::f(b)), Color::u8(Color::f(a.r) + Color::f(b)), Color::u8(Color::f(a.a) + Color::f(b))); }
inline Color operator-(Color a, float b) { return Color(Color::u8(Color::f(a.r) - Color::f(b)), Color::u8(Color::f(a.r) - Color::f(b)), Color::u8(Color::f(a.r) - Color::f(b)), Color::u8(Color::f(a.a) - Color::f(b))); }
inline Color operator*(Color a, float b) { return Color(Color::u8(Color::f(a.r) * Color::f(b)), Color::u8(Color::f(a.r) * Color::f(b)), Color::u8(Color::f(a.r) * Color::f(b)), Color::u8(Color::f(a.a) * Color::f(b))); }
inline Color operator/(Color a, float b) { return Color(Color::u8(Color::f(a.r) / Color::f(b)), Color::u8(Color::f(a.r) / Color::f(b)), Color::u8(Color::f(a.r) / Color::f(b)), Color::u8(Color::f(a.a) / Color::f(b))); }
inline Color operator+(float a, Color b) { return Color(Color::u8(Color::f(a) + Color::f(b.r)), Color::u8(Color::f(a) + Color::f(b.r)), Color::u8(Color::f(a) + Color::f(b.r)), Color::u8(Color::f(a) + Color::f(b.a))); }
inline Color operator-(float a, Color b) { return Color(Color::u8(Color::f(a) - Color::f(b.r)), Color::u8(Color::f(a) - Color::f(b.r)), Color::u8(Color::f(a) - Color::f(b.r)), Color::u8(Color::f(a) - Color::f(b.a))); }
inline Color operator*(float a, Color b) { return Color(Color::u8(Color::f(a) * Color::f(b.r)), Color::u8(Color::f(a) * Color::f(b.r)), Color::u8(Color::f(a) * Color::f(b.r)), Color::u8(Color::f(a) * Color::f(b.a))); }
inline Color operator/(float a, Color b) { return Color(Color::u8(Color::f(a) / Color::f(b.r)), Color::u8(Color::f(a) / Color::f(b.r)), Color::u8(Color::f(a) / Color::f(b.r)), Color::u8(Color::f(a) / Color::f(b.a))); }

inline Color &Color::operator+=(Color b) { return *this = *this + b; }
inline Color &Color::operator-=(Color b) { return *this = *this - b; }
inline Color &Color::operator*=(Color b) { return *this = *this * b; }
inline Color &Color::operator/=(Color b) { return *this = *this / b; }
inline Color &Color::operator+=(Vec4 b) { return *this = *this + b; }
inline Color &Color::operator-=(Vec4 b) { return *this = *this - b; }
inline Color &Color::operator*=(Vec4 b) { return *this = *this * b; }
inline Color &Color::operator/=(Vec4 b) { return *this = *this / b; }
inline Color &Color::operator+=(Vec3 b) { return *this = *this + b; }
inline Color &Color::operator-=(Vec3 b) { return *this = *this - b; }
inline Color &Color::operator*=(Vec3 b) { return *this = *this * b; }
inline Color &Color::operator/=(Vec3 b) { return *this = *this / b; }
inline Color &Color::operator+=(float b) { return *this = *this + b; }
inline Color &Color::operator-=(float b) { return *this = *this - b; }
inline Color &Color::operator*=(float b) { return *this = *this * b; }
inline Color &Color::operator/=(float b) { return *this = *this / b; }

inline Color rand_color() { return Color(Color::u8(rand() % 256), Color::u8(rand() % 256), Color::u8(rand() % 256), Color::u8(rand() % 256)); }

inline Color lerp(Color a, Color b, float t) { return a * (1.0f - t) + b * t; }

inline Color add_a(Color a, Color b, float alpha) { return Color(Vec3(a + b), alpha); }
inline Color sub_a(Color a, Color b, float alpha) { return Color(Vec3(a - b), alpha); }
inline Color mul_a(Color a, Color b, float alpha) { return Color(Vec3(a * b), alpha); }
inline Color div_a(Color a, Color b, float alpha) { return Color(Vec3(a / b), alpha); }

template <typename Fn>
inline Color blend(Color a, Color b, Fn fn) {
    float srcA = Color::f(a.a);
    float dstA = Color::f(b.a);
    float outA = srcA + dstA * (1.0f - srcA);
    if (outA <= 0.0f) return Color();

    Vec3 aVec = a;
    Vec3 bVec = b;

    Vec3 fVec = fore(aVec, bVec, fn);
    Vec3 cVec = (fVec * srcA + bVec * dstA * (1.0f - srcA)) / outA;

    return Color(cVec, outA);
}

// clang-format off
inline Color blend_add(Color a, Color b) { return blend(a, b, [](float a, float b) { return a + b; }); }
inline Color blend_sub(Color a, Color b) { return blend(a, b, [](float a, float b) { return a - b; }); }
inline Color blend_mul(Color a, Color b) { return blend(a, b, [](float a, float b) { return a * b; }); }
inline Color blend_div(Color a, Color b) { return blend(a, b, [](float a, float b) { return a / b; }); }
inline Color blend_screen(Color a, Color b) { return blend(a, b, [](float a, float b) { return a + b - a * b; }); }
inline Color blend_overlay(Color a, Color b) { return blend(a, b, [](float a, float b) { return b <= 0.5f ? (2.0f * a * b) : (1.0f - 2.0f * (1.0f - a) * (1.0f - b)); }); }
inline Color blend_diff(Color a, Color b) { return blend(a, b, [](float a, float b) { return fabs(b - a); }); }
inline Color blend_exc(Color a, Color b) { return blend(a, b, [](float a, float b) { return a + b - 2.0f * a * b; }); }
// clang-format on
