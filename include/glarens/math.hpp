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

    inline Vec3 &operator+=(Vec3 b);
    inline Vec3 &operator-=(Vec3 b);
    inline Vec3 &operator*=(Vec3 b);
    inline Vec3 &operator/=(Vec3 b);
    inline Vec3 &operator+=(float b);
    inline Vec3 &operator-=(float b);
    inline Vec3 &operator*=(float b);
    inline Vec3 &operator/=(float b);
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

inline Vec2 abs(Vec2 v) { return Vec2(fabs(v.x), fabs(v.y)); }
inline Vec3 abs(Vec3 v) { return Vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }
inline Vec4 abs(Vec4 v) { return Vec4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w)); }

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

inline Mat2 abs(Mat2 m) { return Mat2(fabs(m.m[0]), fabs(m.m[1]), fabs(m.m[2]), fabs(m.m[3])); }
inline Mat3 abs(Mat3 m) { return Mat3(fabs(m.m[0]), fabs(m.m[1]), fabs(m.m[2]), fabs(m.m[3]), fabs(m.m[4]), fabs(m.m[5]), fabs(m.m[6]), fabs(m.m[7]), fabs(m.m[8])); }
inline Mat4 abs(Mat4 m) { return Mat4(fabs(m.m[0]), fabs(m.m[1]), fabs(m.m[2]), fabs(m.m[3]), fabs(m.m[4]), fabs(m.m[5]), fabs(m.m[6]), fabs(m.m[7]), fabs(m.m[8]), fabs(m.m[9]), fabs(m.m[10]), fabs(m.m[11]), fabs(m.m[12]), fabs(m.m[13]), fabs(m.m[14]), fabs(m.m[15])); }

inline Mat2 pow(Mat2 a, Mat2 b) { return Mat2(pow(a.m[0], b.m[0]), pow(a.m[1], b.m[1]), pow(a.m[2], b.m[2]), pow(a.m[3], b.m[3])); }
inline Mat3 pow(Mat3 a, Mat3 b) { return Mat3(pow(a.m[0], b.m[0]), pow(a.m[1], b.m[1]), pow(a.m[2], b.m[2]), pow(a.m[3], b.m[3]), pow(a.m[4], b.m[4]), pow(a.m[5], b.m[5]), pow(a.m[6], b.m[6]), pow(a.m[7], b.m[7]), pow(a.m[8], b.m[8])); }
inline Mat4 pow(Mat4 a, Mat4 b) { return Mat4(pow(a.m[0], b.m[0]), pow(a.m[1], b.m[1]), pow(a.m[2], b.m[2]), pow(a.m[3], b.m[3]), pow(a.m[4], b.m[4]), pow(a.m[5], b.m[5]), pow(a.m[6], b.m[6]), pow(a.m[7], b.m[7]), pow(a.m[8], b.m[8]), pow(a.m[9], b.m[9]), pow(a.m[10], b.m[10]), pow(a.m[11], b.m[11]), pow(a.m[12], b.m[12]), pow(a.m[13], b.m[13]), pow(a.m[14], b.m[14]), pow(a.m[15], b.m[15])); }

inline Mat2 mod(Mat2 a, Mat2 b) { return Mat2(fmod(a.m[0], b.m[0]), fmod(a.m[1], b.m[1]), fmod(a.m[2], b.m[2]), fmod(a.m[3], b.m[3])); }
inline Mat3 mod(Mat3 a, Mat3 b) { return Mat3(fmod(a.m[0], b.m[0]), fmod(a.m[1], b.m[1]), fmod(a.m[2], b.m[2]), fmod(a.m[3], b.m[3]), fmod(a.m[4], b.m[4]), fmod(a.m[5], b.m[5]), fmod(a.m[6], b.m[6]), fmod(a.m[7], b.m[7]), fmod(a.m[8], b.m[8])); }
inline Mat4 mod(Mat4 a, Mat4 b) { return Mat4(fmod(a.m[0], b.m[0]), fmod(a.m[1], b.m[1]), fmod(a.m[2], b.m[2]), fmod(a.m[3], b.m[3]), fmod(a.m[4], b.m[4]), fmod(a.m[5], b.m[5]), fmod(a.m[6], b.m[6]), fmod(a.m[7], b.m[7]), fmod(a.m[8], b.m[8]), fmod(a.m[9], b.m[9]), fmod(a.m[10], b.m[10]), fmod(a.m[11], b.m[11]), fmod(a.m[12], b.m[12]), fmod(a.m[13], b.m[13]), fmod(a.m[14], b.m[14]), fmod(a.m[15], b.m[15])); }

inline Mat2 log(Mat2 a, float b) { return Mat2(log(a.m[0]) / log(b), log(a.m[1]) / log(b), log(a.m[2]) / log(b), log(a.m[3]) / log(b)); }
inline Mat3 log(Mat3 a, float b) { return Mat3(log(a.m[0]) / log(b), log(a.m[1]) / log(b), log(a.m[2]) / log(b), log(a.m[3]) / log(b), log(a.m[4]) / log(b), log(a.m[5]) / log(b), log(a.m[6]) / log(b), log(a.m[7]) / log(b), log(a.m[8]) / log(b)); }
inline Mat4 log(Mat4 a, float b) { return Mat4(log(a.m[0]) / log(b), log(a.m[1]) / log(b), log(a.m[2]) / log(b), log(a.m[3]) / log(b), log(a.m[4]) / log(b), log(a.m[5]) / log(b), log(a.m[6]) / log(b), log(a.m[7]) / log(b), log(a.m[8]) / log(b), log(a.m[9]) / log(b), log(a.m[10]) / log(b), log(a.m[11]) / log(b), log(a.m[12]) / log(b), log(a.m[13]) / log(b), log(a.m[14]) / log(b), log(a.m[15]) / log(b)); }

inline Mat2 sqrt(Mat2 m) { return Mat2(sqrt(m.m[0]), sqrt(m.m[1]), sqrt(m.m[2]), sqrt(m.m[3])); }
inline Mat3 sqrt(Mat3 m) { return Mat3(sqrt(m.m[0]), sqrt(m.m[1]), sqrt(m.m[2]), sqrt(m.m[3]), sqrt(m.m[4]), sqrt(m.m[5]), sqrt(m.m[6]), sqrt(m.m[7]), sqrt(m.m[8])); }
inline Mat4 sqrt(Mat4 m) { return Mat4(sqrt(m.m[0]), sqrt(m.m[1]), sqrt(m.m[2]), sqrt(m.m[3]), sqrt(m.m[4]), sqrt(m.m[5]), sqrt(m.m[6]), sqrt(m.m[7]), sqrt(m.m[8]), sqrt(m.m[9]), sqrt(m.m[10]), sqrt(m.m[11]), sqrt(m.m[12]), sqrt(m.m[13]), sqrt(m.m[14]), sqrt(m.m[15])); }

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
