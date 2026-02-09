// Glarens - GUI Framework.
//
// SDL-compatible math types.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include "SDL3/SDL_rect.h"
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

    Vec2() noexcept = default;
    Vec2(float xy) noexcept : x(xy), y(xy) {}
    Vec2(float x, float y) noexcept : x(x), y(y) {}

    Vec2(SDL_FPoint v) noexcept : x(v.x), y(v.y) {}

    inline explicit Vec2(Vec3 v) noexcept;
    inline explicit Vec2(Vec4 v) noexcept;

    [[nodiscard]] operator SDL_FPoint() const noexcept { return {x, y}; }

    inline Vec2 &operator+=(Vec2 b) noexcept;
    inline Vec2 &operator-=(Vec2 b) noexcept;
    inline Vec2 &operator*=(Vec2 b) noexcept;
    inline Vec2 &operator/=(Vec2 b) noexcept;
    inline Vec2 &operator+=(SDL_FPoint b) noexcept;
    inline Vec2 &operator-=(SDL_FPoint b) noexcept;
    inline Vec2 &operator*=(SDL_FPoint b) noexcept;
    inline Vec2 &operator/=(SDL_FPoint b) noexcept;
    inline Vec2 &operator+=(float b) noexcept;
    inline Vec2 &operator-=(float b) noexcept;
    inline Vec2 &operator*=(float b) noexcept;
    inline Vec2 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Vec2 operator+(Vec2 a) noexcept { return Vec2(+a.x, +a.y); }
[[nodiscard]] inline Vec2 operator-(Vec2 a) noexcept { return Vec2(-a.x, -a.y); }

[[nodiscard]] inline Vec2 operator+(Vec2 a, Vec2 b) noexcept { return {a.x + b.x, a.y + b.y}; }
[[nodiscard]] inline Vec2 operator-(Vec2 a, Vec2 b) noexcept { return {a.x - b.x, a.y - b.y}; }
[[nodiscard]] inline Vec2 operator*(Vec2 a, Vec2 b) noexcept { return {a.x * b.x, a.y * b.y}; }
[[nodiscard]] inline Vec2 operator/(Vec2 a, Vec2 b) noexcept { return {a.x / b.x, a.y / b.y}; }
[[nodiscard]] inline Vec2 operator+(Vec2 a, SDL_FPoint b) noexcept { return {a.x + b.x, a.y + b.y}; }
[[nodiscard]] inline Vec2 operator-(Vec2 a, SDL_FPoint b) noexcept { return {a.x - b.x, a.y - b.y}; }
[[nodiscard]] inline Vec2 operator*(Vec2 a, SDL_FPoint b) noexcept { return {a.x * b.x, a.y * b.y}; }
[[nodiscard]] inline Vec2 operator/(Vec2 a, SDL_FPoint b) noexcept { return {a.x / b.x, a.y / b.y}; }
[[nodiscard]] inline Vec2 operator+(SDL_FPoint a, Vec2 b) noexcept { return {a.x + b.x, a.y + b.y}; }
[[nodiscard]] inline Vec2 operator-(SDL_FPoint a, Vec2 b) noexcept { return {a.x - b.x, a.y - b.y}; }
[[nodiscard]] inline Vec2 operator*(SDL_FPoint a, Vec2 b) noexcept { return {a.x * b.x, a.y * b.y}; }
[[nodiscard]] inline Vec2 operator/(SDL_FPoint a, Vec2 b) noexcept { return {a.x / b.x, a.y / b.y}; }
[[nodiscard]] inline Vec2 operator+(Vec2 a, float b) noexcept { return {a.x + b, a.y + b}; }
[[nodiscard]] inline Vec2 operator-(Vec2 a, float b) noexcept { return {a.x - b, a.y - b}; }
[[nodiscard]] inline Vec2 operator*(Vec2 a, float b) noexcept { return {a.x * b, a.y * b}; }
[[nodiscard]] inline Vec2 operator/(Vec2 a, float b) noexcept { return {a.x / b, a.y / b}; }
[[nodiscard]] inline Vec2 operator+(float a, Vec2 b) noexcept { return {a + b.x, a + b.y}; }
[[nodiscard]] inline Vec2 operator-(float a, Vec2 b) noexcept { return {a - b.x, a - b.y}; }
[[nodiscard]] inline Vec2 operator*(float a, Vec2 b) noexcept { return {a * b.x, a * b.y}; }
[[nodiscard]] inline Vec2 operator/(float a, Vec2 b) noexcept { return {a / b.x, a / b.y}; }

inline Vec2 &Vec2::operator+=(Vec2 b) noexcept { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(Vec2 b) noexcept { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(Vec2 b) noexcept { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(Vec2 b) noexcept { return *this = *this / b; }
inline Vec2 &Vec2::operator+=(SDL_FPoint b) noexcept { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(SDL_FPoint b) noexcept { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(SDL_FPoint b) noexcept { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(SDL_FPoint b) noexcept { return *this = *this / b; }
inline Vec2 &Vec2::operator+=(float b) noexcept { return *this = *this + b; }
inline Vec2 &Vec2::operator-=(float b) noexcept { return *this = *this - b; }
inline Vec2 &Vec2::operator*=(float b) noexcept { return *this = *this * b; }
inline Vec2 &Vec2::operator/=(float b) noexcept { return *this = *this / b; }

struct Vec3 {
    float x;
    float y;
    float z;

    Vec3() noexcept = default;
    Vec3(float xyz) noexcept : x(xyz), y(xyz), z(xyz) {}
    Vec3(float x, float y, float z) noexcept : x(x), y(y), z(z) {}

    Vec3(Vec2 v, float z) noexcept : x(v.x), y(v.y), z(z) {}
    Vec3(float x, Vec2 v) noexcept : x(x), y(v.x), z(v.y) {}

    inline explicit Vec3(Vec2 v) noexcept;
    inline explicit Vec3(Vec4 v) noexcept;

    inline Vec3 &operator+=(Vec3 b) noexcept;
    inline Vec3 &operator-=(Vec3 b) noexcept;
    inline Vec3 &operator*=(Vec3 b) noexcept;
    inline Vec3 &operator/=(Vec3 b) noexcept;
    inline Vec3 &operator+=(float b) noexcept;
    inline Vec3 &operator-=(float b) noexcept;
    inline Vec3 &operator*=(float b) noexcept;
    inline Vec3 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Vec3 operator+(Vec3 a) noexcept { return Vec3(+a.x, +a.y, +a.z); }
[[nodiscard]] inline Vec3 operator-(Vec3 a) noexcept { return Vec3(-a.x, -a.y, -a.z); }

[[nodiscard]] inline Vec3 operator+(Vec3 a, Vec3 b) noexcept { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
[[nodiscard]] inline Vec3 operator-(Vec3 a, Vec3 b) noexcept { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
[[nodiscard]] inline Vec3 operator*(Vec3 a, Vec3 b) noexcept { return {a.x * b.x, a.y * b.y, a.z * b.z}; }
[[nodiscard]] inline Vec3 operator/(Vec3 a, Vec3 b) noexcept { return {a.x / b.x, a.y / b.y, a.z / b.z}; }
[[nodiscard]] inline Vec3 operator+(Vec3 a, float b) noexcept { return {a.x + b, a.y + b, a.z + b}; }
[[nodiscard]] inline Vec3 operator-(Vec3 a, float b) noexcept { return {a.x - b, a.y - b, a.z - b}; }
[[nodiscard]] inline Vec3 operator*(Vec3 a, float b) noexcept { return {a.x * b, a.y * b, a.z * b}; }
[[nodiscard]] inline Vec3 operator/(Vec3 a, float b) noexcept { return {a.x / b, a.y / b, a.z / b}; }
[[nodiscard]] inline Vec3 operator+(float a, Vec3 b) noexcept { return {a + b.x, a + b.y, a + b.z}; }
[[nodiscard]] inline Vec3 operator-(float a, Vec3 b) noexcept { return {a - b.x, a - b.y, a - b.z}; }
[[nodiscard]] inline Vec3 operator*(float a, Vec3 b) noexcept { return {a * b.x, a * b.y, a * b.z}; }
[[nodiscard]] inline Vec3 operator/(float a, Vec3 b) noexcept { return {a / b.x, a / b.y, a / b.z}; }

inline Vec3 &Vec3::operator+=(Vec3 b) noexcept { return *this = *this + b; }
inline Vec3 &Vec3::operator-=(Vec3 b) noexcept { return *this = *this - b; }
inline Vec3 &Vec3::operator*=(Vec3 b) noexcept { return *this = *this * b; }
inline Vec3 &Vec3::operator/=(Vec3 b) noexcept { return *this = *this / b; }
inline Vec3 &Vec3::operator+=(float b) noexcept { return *this = *this + b; }
inline Vec3 &Vec3::operator-=(float b) noexcept { return *this = *this - b; }
inline Vec3 &Vec3::operator*=(float b) noexcept { return *this = *this * b; }
inline Vec3 &Vec3::operator/=(float b) noexcept { return *this = *this / b; }

struct Vec4 {
    float x;
    float y;
    float z;
    float w;

    Vec4() noexcept = default;
    Vec4(float xyzw) noexcept : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
    Vec4(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) {}

    Vec4(SDL_FRect v) noexcept : x(v.x), y(v.y), z(v.w), w(v.h) {}

    Vec4(Vec2 v, float z, float w) noexcept : x(v.x), y(v.y), z(z), w(w) {}
    Vec4(float x, Vec2 v, float w) noexcept : x(x), y(v.x), z(v.y), w(w) {}
    Vec4(float x, float y, Vec2 v) noexcept : x(x), y(y), z(v.x), w(v.y) {}
    Vec4(Vec2 v, Vec2 u) noexcept : x(v.x), y(v.y), z(u.x), w(u.y) {}
    Vec4(Vec3 v, float w) noexcept : x(v.x), y(v.y), z(v.z), w(w) {}
    Vec4(float x, Vec3 v) noexcept : x(x), y(v.x), z(v.y), w(v.z) {}

    inline explicit Vec4(Vec2 v) noexcept;
    inline explicit Vec4(Vec3 v) noexcept;

    [[nodiscard]] operator SDL_FRect() const noexcept { return {x, y, z, w}; }

    inline Vec4 &operator+=(Vec4 b) noexcept;
    inline Vec4 &operator-=(Vec4 b) noexcept;
    inline Vec4 &operator*=(Vec4 b) noexcept;
    inline Vec4 &operator/=(Vec4 b) noexcept;
    inline Vec4 &operator+=(SDL_FRect b) noexcept;
    inline Vec4 &operator-=(SDL_FRect b) noexcept;
    inline Vec4 &operator*=(SDL_FRect b) noexcept;
    inline Vec4 &operator/=(SDL_FRect b) noexcept;
    inline Vec4 &operator+=(float b) noexcept;
    inline Vec4 &operator-=(float b) noexcept;
    inline Vec4 &operator*=(float b) noexcept;
    inline Vec4 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Vec4 operator+(Vec4 a) noexcept { return Vec4(+a.x, +a.y, +a.z, +a.w); }
[[nodiscard]] inline Vec4 operator-(Vec4 a) noexcept { return Vec4(-a.x, -a.y, -a.z, -a.w); }

[[nodiscard]] inline Vec4 operator+(Vec4 a, Vec4 b) noexcept { return {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
[[nodiscard]] inline Vec4 operator-(Vec4 a, Vec4 b) noexcept { return {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
[[nodiscard]] inline Vec4 operator*(Vec4 a, Vec4 b) noexcept { return {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
[[nodiscard]] inline Vec4 operator/(Vec4 a, Vec4 b) noexcept { return {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }
[[nodiscard]] inline Vec4 operator+(Vec4 a, SDL_FRect b) noexcept { return {a.x + b.x, a.y + b.y, a.z + b.w, a.w + b.h}; }
[[nodiscard]] inline Vec4 operator-(Vec4 a, SDL_FRect b) noexcept { return {a.x - b.x, a.y - b.y, a.z - b.w, a.w - b.h}; }
[[nodiscard]] inline Vec4 operator*(Vec4 a, SDL_FRect b) noexcept { return {a.x * b.x, a.y * b.y, a.z * b.w, a.w * b.h}; }
[[nodiscard]] inline Vec4 operator/(Vec4 a, SDL_FRect b) noexcept { return {a.x / b.x, a.y / b.y, a.z / b.w, a.w / b.h}; }
[[nodiscard]] inline Vec4 operator+(SDL_FRect a, Vec4 b) noexcept { return {a.x + b.x, a.y + b.y, a.w + b.z, a.h + b.w}; }
[[nodiscard]] inline Vec4 operator-(SDL_FRect a, Vec4 b) noexcept { return {a.x - b.x, a.y - b.y, a.w - b.z, a.h - b.w}; }
[[nodiscard]] inline Vec4 operator*(SDL_FRect a, Vec4 b) noexcept { return {a.x * b.x, a.y * b.y, a.w * b.z, a.h * b.w}; }
[[nodiscard]] inline Vec4 operator/(SDL_FRect a, Vec4 b) noexcept { return {a.x / b.x, a.y / b.y, a.w / b.z, a.h / b.w}; }
[[nodiscard]] inline Vec4 operator+(Vec4 a, float b) noexcept { return {a.x + b, a.y + b, a.z + b, a.w + b}; }
[[nodiscard]] inline Vec4 operator-(Vec4 a, float b) noexcept { return {a.x - b, a.y - b, a.z - b, a.w - b}; }
[[nodiscard]] inline Vec4 operator*(Vec4 a, float b) noexcept { return {a.x * b, a.y * b, a.z * b, a.w * b}; }
[[nodiscard]] inline Vec4 operator/(Vec4 a, float b) noexcept { return {a.x / b, a.y / b, a.z / b, a.w / b}; }
[[nodiscard]] inline Vec4 operator+(float a, Vec4 b) noexcept { return {a + b.x, a + b.y, a + b.z, a + b.w}; }
[[nodiscard]] inline Vec4 operator-(float a, Vec4 b) noexcept { return {a - b.x, a - b.y, a - b.z, a - b.w}; }
[[nodiscard]] inline Vec4 operator*(float a, Vec4 b) noexcept { return {a * b.x, a * b.y, a * b.z, a * b.w}; }
[[nodiscard]] inline Vec4 operator/(float a, Vec4 b) noexcept { return {a / b.x, a / b.y, a / b.z, a / b.w}; }

inline Vec4 &Vec4::operator+=(Vec4 b) noexcept { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(Vec4 b) noexcept { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(Vec4 b) noexcept { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(Vec4 b) noexcept { return *this = *this / b; }
inline Vec4 &Vec4::operator+=(SDL_FRect b) noexcept { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(SDL_FRect b) noexcept { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(SDL_FRect b) noexcept { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(SDL_FRect b) noexcept { return *this = *this / b; }
inline Vec4 &Vec4::operator+=(float b) noexcept { return *this = *this + b; }
inline Vec4 &Vec4::operator-=(float b) noexcept { return *this = *this - b; }
inline Vec4 &Vec4::operator*=(float b) noexcept { return *this = *this * b; }
inline Vec4 &Vec4::operator/=(float b) noexcept { return *this = *this / b; }

inline Vec2::Vec2(Vec3 v) noexcept : x(v.x), y(v.y) {}
inline Vec2::Vec2(Vec4 v) noexcept : x(v.x), y(v.y) {}
inline Vec3::Vec3(Vec2 v) noexcept : x(v.x), y(v.y), z(0.0f) {}
inline Vec3::Vec3(Vec4 v) noexcept : x(v.x), y(v.y), z(v.z) {}
inline Vec4::Vec4(Vec2 v) noexcept : x(v.x), y(v.y), z(0.0f), w(0.0f) {}
inline Vec4::Vec4(Vec3 v) noexcept : x(v.x), y(v.y), z(v.z), w(0.0f) {}

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

inline Vec2 rotate_around(Vec2 v, Vec2 o, float a) {
    return rotate(v - o, a) + o;
}

inline Vec3 rotate(Vec3 v, Vec3 axis, float a) {
    float c = cos(a);
    float s = sin(a);
    return v * c + cross(axis, v) * s + axis * dot(axis, v) * (1.0f - c);
}

inline Vec3 rotate_around(Vec3 v, Vec3 o, Vec3 axis, float a) {
    return rotate(v - o, axis, a) + o;
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

    Mat2() noexcept = default;
    Mat2(M m) noexcept : m({m[0], m[1], m[2], m[3]}) {}
    Mat2(float m0, float m1, float m2, float m3) noexcept : m({m0, m1, m2, m3}) {}
    Mat2(Vec2 v1, Vec2 v2) noexcept : m({v1.x, v1.y, v2.x, v2.y}) {}

    inline explicit Mat2(Mat3 m) noexcept;
    inline explicit Mat2(Mat4 m) noexcept;

    static Mat2 from_rows_vec(Vec4 m) { return Mat2(m.x, m.y, m.z, m.w); }

    static Mat2 from_cols_vec(Vec4 m) { return Mat2(m.x, m.z, m.y, m.w); }

    Vec4 to_rows_vec() const { return Vec4(m[0], m[1], m[2], m[3]); }

    Vec4 to_cols_vec() const { return Vec4(m[0], m[2], m[1], m[3]); }

    std::array<Vec2, 2> get_rows() const { return {Vec2(m[0], m[1]), Vec2(m[2], m[3])}; }

    void set_rows(std::array<Vec2, 2> rows) { m = {rows[0].x, rows[0].y, rows[1].x, rows[1].y}; }

    std::array<Vec2, 2> get_cols() const { return {Vec2(m[0], m[2]), Vec2(m[1], m[3])}; }

    void set_cols(std::array<Vec2, 2> cols) { m = {cols[0].x, cols[1].x, cols[0].y, cols[1].y}; }

    Vec2 get_diag() const { return Vec2(m[0], m[3]); }

    void set_diag(Vec2 diag) { m = {m[0], diag.x, diag.y, m[3]}; }

    inline Mat2 &operator+=(Mat2 b) noexcept;
    inline Mat2 &operator-=(Mat2 b) noexcept;
    inline Mat2 &operator*=(Mat2 b) noexcept;
    inline Mat2 &operator/=(Mat2 b) noexcept;
    inline Mat2 &operator+=(float b) noexcept;
    inline Mat2 &operator-=(float b) noexcept;
    inline Mat2 &operator*=(float b) noexcept;
    inline Mat2 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Mat2 operator+(Mat2 a) noexcept { return Mat2(+a.m[0], +a.m[1], +a.m[2], +a.m[3]); }
[[nodiscard]] inline Mat2 operator-(Mat2 a) noexcept { return Mat2(-a.m[0], -a.m[1], -a.m[2], -a.m[3]); }

[[nodiscard]] inline Mat2 operator+(Mat2 a, Mat2 b) noexcept { return Mat2(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3]); }
[[nodiscard]] inline Mat2 operator-(Mat2 a, Mat2 b) noexcept { return Mat2(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3]); }
[[nodiscard]] inline Mat2 operator*(Mat2 a, Mat2 b) noexcept { return Mat2(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3]); }
[[nodiscard]] inline Mat2 operator/(Mat2 a, Mat2 b) noexcept { return Mat2(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3]); }
[[nodiscard]] inline Mat2 operator+(Mat2 a, float b) noexcept { return Mat2(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b); }
[[nodiscard]] inline Mat2 operator-(Mat2 a, float b) noexcept { return Mat2(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b); }
[[nodiscard]] inline Mat2 operator*(Mat2 a, float b) noexcept { return Mat2(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b); }
[[nodiscard]] inline Mat2 operator/(Mat2 a, float b) noexcept { return Mat2(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b); }
[[nodiscard]] inline Mat2 operator+(float a, Mat2 b) noexcept { return Mat2(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3]); }
[[nodiscard]] inline Mat2 operator-(float a, Mat2 b) noexcept { return Mat2(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3]); }
[[nodiscard]] inline Mat2 operator*(float a, Mat2 b) noexcept { return Mat2(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3]); }
[[nodiscard]] inline Mat2 operator/(float a, Mat2 b) noexcept { return Mat2(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3]); }

inline Mat2 &Mat2::operator+=(Mat2 b) noexcept { return *this = *this + b; }
inline Mat2 &Mat2::operator-=(Mat2 b) noexcept { return *this = *this - b; }
inline Mat2 &Mat2::operator*=(Mat2 b) noexcept { return *this = *this * b; }
inline Mat2 &Mat2::operator/=(Mat2 b) noexcept { return *this = *this / b; }
inline Mat2 &Mat2::operator+=(float b) noexcept { return *this = *this + b; }
inline Mat2 &Mat2::operator-=(float b) noexcept { return *this = *this - b; }
inline Mat2 &Mat2::operator*=(float b) noexcept { return *this = *this * b; }
inline Mat2 &Mat2::operator/=(float b) noexcept { return *this = *this / b; }

struct Mat3 {
    using M = std::array<float, 9>;
    using V = std::array<Vec3, 3>;

    // Row-major
    // [0, 1, 2
    //  3, 4, 5
    //  6, 7, 8]
    M m;

    Mat3() noexcept = default;
    Mat3(M m) noexcept : m({m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]}) {}
    Mat3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) noexcept : m({m0, m1, m2, m3, m4, m5, m6, m7, m8}) {}
    Mat3(Vec3 v1, Vec3 v2, Vec3 v3) noexcept : m({v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z}) {}

    inline explicit Mat3(Mat2 m) noexcept;
    inline explicit Mat3(Mat4 m) noexcept;

    std::array<Vec3, 3> get_rows() const { return {Vec3(m[0], m[1], m[2]), Vec3(m[3], m[4], m[5]), Vec3(m[6], m[7], m[8])}; }

    void set_rows(std::array<Vec3, 3> rows) { m = {rows[0].x, rows[0].y, rows[0].z, rows[1].x, rows[1].y, rows[1].z, rows[2].x, rows[2].y, rows[2].z}; }

    std::array<Vec3, 3> get_cols() const { return {Vec3(m[0], m[3], m[6]), Vec3(m[1], m[4], m[7]), Vec3(m[2], m[5], m[8])}; }

    void set_cols(std::array<Vec3, 3> cols) { m = {cols[0].x, cols[1].x, cols[2].x, cols[0].y, cols[1].y, cols[2].y, cols[0].z, cols[1].z, cols[2].z}; }

    Vec3 get_diag() const { return Vec3(m[0], m[4], m[8]); }

    void set_diag(Vec3 diag) { m = {diag.x, m[1], m[2], m[3], diag.y, m[5], m[6], m[7], diag.z}; }

    inline Mat3 &operator+=(Mat3 b) noexcept;
    inline Mat3 &operator-=(Mat3 b) noexcept;
    inline Mat3 &operator*=(Mat3 b) noexcept;
    inline Mat3 &operator/=(Mat3 b) noexcept;
    inline Mat3 &operator+=(float b) noexcept;
    inline Mat3 &operator-=(float b) noexcept;
    inline Mat3 &operator*=(float b) noexcept;
    inline Mat3 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Mat3 operator+(Mat3 a) noexcept { return Mat3(+a.m[0], +a.m[1], +a.m[2], +a.m[3], +a.m[4], +a.m[5], +a.m[6], +a.m[7], +a.m[8]); }
[[nodiscard]] inline Mat3 operator-(Mat3 a) noexcept { return Mat3(-a.m[0], -a.m[1], -a.m[2], -a.m[3], -a.m[4], -a.m[5], -a.m[6], -a.m[7], -a.m[8]); }

[[nodiscard]] inline Mat3 operator+(Mat3 a, Mat3 b) noexcept { return Mat3(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3], a.m[4] + b.m[4], a.m[5] + b.m[5], a.m[6] + b.m[6], a.m[7] + b.m[7], a.m[8] + b.m[8]); }
[[nodiscard]] inline Mat3 operator-(Mat3 a, Mat3 b) noexcept { return Mat3(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3], a.m[4] - b.m[4], a.m[5] - b.m[5], a.m[6] - b.m[6], a.m[7] - b.m[7], a.m[8] - b.m[8]); }
[[nodiscard]] inline Mat3 operator*(Mat3 a, Mat3 b) noexcept { return Mat3(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3], a.m[4] * b.m[4], a.m[5] * b.m[5], a.m[6] * b.m[6], a.m[7] * b.m[7], a.m[8] * b.m[8]); }
[[nodiscard]] inline Mat3 operator/(Mat3 a, Mat3 b) noexcept { return Mat3(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3], a.m[4] / b.m[4], a.m[5] / b.m[5], a.m[6] / b.m[6], a.m[7] / b.m[7], a.m[8] / b.m[8]); }
[[nodiscard]] inline Mat3 operator+(Mat3 a, float b) noexcept { return Mat3(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b, a.m[4] + b, a.m[5] + b, a.m[6] + b, a.m[7] + b, a.m[8] + b); }
[[nodiscard]] inline Mat3 operator-(Mat3 a, float b) noexcept { return Mat3(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b, a.m[4] - b, a.m[5] - b, a.m[6] - b, a.m[7] - b, a.m[8] - b); }
[[nodiscard]] inline Mat3 operator*(Mat3 a, float b) noexcept { return Mat3(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b, a.m[4] * b, a.m[5] * b, a.m[6] * b, a.m[7] * b, a.m[8] * b); }
[[nodiscard]] inline Mat3 operator/(Mat3 a, float b) noexcept { return Mat3(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b, a.m[4] / b, a.m[5] / b, a.m[6] / b, a.m[7] / b, a.m[8] / b); }
[[nodiscard]] inline Mat3 operator+(float a, Mat3 b) noexcept { return Mat3(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3], a + b.m[4], a + b.m[5], a + b.m[6], a + b.m[7], a + b.m[8]); }
[[nodiscard]] inline Mat3 operator-(float a, Mat3 b) noexcept { return Mat3(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3], a - b.m[4], a - b.m[5], a - b.m[6], a - b.m[7], a - b.m[8]); }
[[nodiscard]] inline Mat3 operator*(float a, Mat3 b) noexcept { return Mat3(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3], a * b.m[4], a * b.m[5], a * b.m[6], a * b.m[7], a * b.m[8]); }
[[nodiscard]] inline Mat3 operator/(float a, Mat3 b) noexcept { return Mat3(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3], a / b.m[4], a / b.m[5], a / b.m[6], a / b.m[7], a / b.m[8]); }

inline Mat3 &Mat3::operator+=(Mat3 b) noexcept { return *this = *this + b; }
inline Mat3 &Mat3::operator-=(Mat3 b) noexcept { return *this = *this - b; }
inline Mat3 &Mat3::operator*=(Mat3 b) noexcept { return *this = *this * b; }
inline Mat3 &Mat3::operator/=(Mat3 b) noexcept { return *this = *this / b; }
inline Mat3 &Mat3::operator+=(float b) noexcept { return *this = *this + b; }
inline Mat3 &Mat3::operator-=(float b) noexcept { return *this = *this - b; }
inline Mat3 &Mat3::operator*=(float b) noexcept { return *this = *this * b; }
inline Mat3 &Mat3::operator/=(float b) noexcept { return *this = *this / b; }

struct Mat4 {
    using M = std::array<float, 16>;
    using V = std::array<Vec4, 4>;

    // Row-major
    // [ 0,  1,  2,  3
    //   4,  5,  6,  7
    //   8,  9, 10, 11
    //  12, 13, 14, 15]
    M m;

    Mat4() noexcept = default;
    Mat4(M m) noexcept : m({m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8]}) {}
    Mat4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15) noexcept : m({m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15}) {}

    inline explicit Mat4(Mat2 m) noexcept;
    inline explicit Mat4(Mat3 m) noexcept;

    std::array<Vec4, 4> get_rows() const { return {Vec4(m[0], m[1], m[2], m[3]), Vec4(m[4], m[5], m[6], m[7]), Vec4(m[8], m[9], m[10], m[11]), Vec4(m[12], m[13], m[14], m[15])}; }

    void set_rows(std::array<Vec4, 4> rows) { m = {rows[0].x, rows[0].y, rows[0].z, rows[0].w, rows[1].x, rows[1].y, rows[1].z, rows[1].w, rows[2].x, rows[2].y, rows[2].z, rows[2].w, rows[3].x, rows[3].y, rows[3].z, rows[3].w}; }

    std::array<Vec4, 4> get_cols() const { return {Vec4(m[0], m[4], m[8], m[12]), Vec4(m[1], m[5], m[9], m[13]), Vec4(m[2], m[6], m[10], m[14]), Vec4(m[3], m[7], m[11], m[15])}; }

    void set_cols(std::array<Vec4, 4> cols) { m = {cols[0].x, cols[1].x, cols[2].x, cols[3].x, cols[0].y, cols[1].y, cols[2].y, cols[3].y, cols[0].z, cols[1].z, cols[2].z, cols[3].z, cols[0].w, cols[1].w, cols[2].w, cols[3].w}; }

    Vec4 get_diag() const { return Vec4(m[0], m[5], m[10], m[15]); }

    void set_diag(Vec4 diag) { m = {diag.x, m[1], m[2], m[3], m[4], diag.y, m[6], m[7], m[8], m[9], diag.z, m[11], m[12], m[13], m[14], diag.w}; }

    inline Mat4 &operator+=(Mat4 b) noexcept;
    inline Mat4 &operator-=(Mat4 b) noexcept;
    inline Mat4 &operator*=(Mat4 b) noexcept;
    inline Mat4 &operator/=(Mat4 b) noexcept;
    inline Mat4 &operator+=(float b) noexcept;
    inline Mat4 &operator-=(float b) noexcept;
    inline Mat4 &operator*=(float b) noexcept;
    inline Mat4 &operator/=(float b) noexcept;
};

[[nodiscard]] inline Mat4 operator+(Mat4 a) noexcept { return Mat4(+a.m[0], +a.m[1], +a.m[2], +a.m[3], +a.m[4], +a.m[5], +a.m[6], +a.m[7], +a.m[8], +a.m[9], +a.m[10], +a.m[11], +a.m[12], +a.m[13], +a.m[14], +a.m[15]); }
[[nodiscard]] inline Mat4 operator-(Mat4 a) noexcept { return Mat4(-a.m[0], -a.m[1], -a.m[2], -a.m[3], -a.m[4], -a.m[5], -a.m[6], -a.m[7], -a.m[8], -a.m[9], -a.m[10], -a.m[11], -a.m[12], -a.m[13], -a.m[14], -a.m[15]); }

[[nodiscard]] inline Mat4 operator+(Mat4 a, Mat4 b) noexcept { return Mat4(a.m[0] + b.m[0], a.m[1] + b.m[1], a.m[2] + b.m[2], a.m[3] + b.m[3], a.m[4] + b.m[4], a.m[5] + b.m[5], a.m[6] + b.m[6], a.m[7] + b.m[7], a.m[8] + b.m[8], a.m[9] + b.m[9], a.m[10] + b.m[10], a.m[11] + b.m[11], a.m[12] + b.m[12], a.m[13] + b.m[13], a.m[14] + b.m[14], a.m[15] + b.m[15]); }
[[nodiscard]] inline Mat4 operator-(Mat4 a, Mat4 b) noexcept { return Mat4(a.m[0] - b.m[0], a.m[1] - b.m[1], a.m[2] - b.m[2], a.m[3] - b.m[3], a.m[4] - b.m[4], a.m[5] - b.m[5], a.m[6] - b.m[6], a.m[7] - b.m[7], a.m[8] - b.m[8], a.m[9] - b.m[9], a.m[10] - b.m[10], a.m[11] - b.m[11], a.m[12] - b.m[12], a.m[13] - b.m[13], a.m[14] - b.m[14], a.m[15] - b.m[15]); }
[[nodiscard]] inline Mat4 operator*(Mat4 a, Mat4 b) noexcept { return Mat4(a.m[0] * b.m[0], a.m[1] * b.m[1], a.m[2] * b.m[2], a.m[3] * b.m[3], a.m[4] * b.m[4], a.m[5] * b.m[5], a.m[6] * b.m[6], a.m[7] * b.m[7], a.m[8] * b.m[8], a.m[9] * b.m[9], a.m[10] * b.m[10], a.m[11] * b.m[11], a.m[12] * b.m[12], a.m[13] * b.m[13], a.m[14] * b.m[14], a.m[15] * b.m[15]); }
[[nodiscard]] inline Mat4 operator/(Mat4 a, Mat4 b) noexcept { return Mat4(a.m[0] / b.m[0], a.m[1] / b.m[1], a.m[2] / b.m[2], a.m[3] / b.m[3], a.m[4] / b.m[4], a.m[5] / b.m[5], a.m[6] / b.m[6], a.m[7] / b.m[7], a.m[8] / b.m[8], a.m[9] / b.m[9], a.m[10] / b.m[10], a.m[11] / b.m[11], a.m[12] / b.m[12], a.m[13] / b.m[13], a.m[14] / b.m[14], a.m[15] / b.m[15]); }
[[nodiscard]] inline Mat4 operator+(Mat4 a, float b) noexcept { return Mat4(a.m[0] + b, a.m[1] + b, a.m[2] + b, a.m[3] + b, a.m[4] + b, a.m[5] + b, a.m[6] + b, a.m[7] + b, a.m[8] + b, a.m[9] + b, a.m[10] + b, a.m[11] + b, a.m[12] + b, a.m[13] + b, a.m[14] + b, a.m[15] + b); }
[[nodiscard]] inline Mat4 operator-(Mat4 a, float b) noexcept { return Mat4(a.m[0] - b, a.m[1] - b, a.m[2] - b, a.m[3] - b, a.m[4] - b, a.m[5] - b, a.m[6] - b, a.m[7] - b, a.m[8] - b, a.m[9] - b, a.m[10] - b, a.m[11] - b, a.m[12] - b, a.m[13] - b, a.m[14] - b, a.m[15] - b); }
[[nodiscard]] inline Mat4 operator*(Mat4 a, float b) noexcept { return Mat4(a.m[0] * b, a.m[1] * b, a.m[2] * b, a.m[3] * b, a.m[4] * b, a.m[5] * b, a.m[6] * b, a.m[7] * b, a.m[8] * b, a.m[9] * b, a.m[10] * b, a.m[11] * b, a.m[12] * b, a.m[13] * b, a.m[14] * b, a.m[15] * b); }
[[nodiscard]] inline Mat4 operator/(Mat4 a, float b) noexcept { return Mat4(a.m[0] / b, a.m[1] / b, a.m[2] / b, a.m[3] / b, a.m[4] / b, a.m[5] / b, a.m[6] / b, a.m[7] / b, a.m[8] / b, a.m[9] / b, a.m[10] / b, a.m[11] / b, a.m[12] / b, a.m[13] / b, a.m[14] / b, a.m[15] / b); }
[[nodiscard]] inline Mat4 operator+(float a, Mat4 b) noexcept { return Mat4(a + b.m[0], a + b.m[1], a + b.m[2], a + b.m[3], a + b.m[4], a + b.m[5], a + b.m[6], a + b.m[7], a + b.m[8], a + b.m[9], a + b.m[10], a + b.m[11], a + b.m[12], a + b.m[13], a + b.m[14], a + b.m[15]); }
[[nodiscard]] inline Mat4 operator-(float a, Mat4 b) noexcept { return Mat4(a - b.m[0], a - b.m[1], a - b.m[2], a - b.m[3], a - b.m[4], a - b.m[5], a - b.m[6], a - b.m[7], a - b.m[8], a - b.m[9], a - b.m[10], a - b.m[11], a - b.m[12], a - b.m[13], a - b.m[14], a - b.m[15]); }
[[nodiscard]] inline Mat4 operator*(float a, Mat4 b) noexcept { return Mat4(a * b.m[0], a * b.m[1], a * b.m[2], a * b.m[3], a * b.m[4], a * b.m[5], a * b.m[6], a * b.m[7], a * b.m[8], a * b.m[9], a * b.m[10], a * b.m[11], a * b.m[12], a * b.m[13], a * b.m[14], a * b.m[15]); }
[[nodiscard]] inline Mat4 operator/(float a, Mat4 b) noexcept { return Mat4(a / b.m[0], a / b.m[1], a / b.m[2], a / b.m[3], a / b.m[4], a / b.m[5], a / b.m[6], a / b.m[7], a / b.m[8], a / b.m[9], a / b.m[10], a / b.m[11], a / b.m[12], a / b.m[13], a / b.m[14], a / b.m[15]); }

inline Mat4 &Mat4::operator+=(Mat4 b) noexcept { return *this = *this + b; }
inline Mat4 &Mat4::operator-=(Mat4 b) noexcept { return *this = *this - b; }
inline Mat4 &Mat4::operator*=(Mat4 b) noexcept { return *this = *this * b; }
inline Mat4 &Mat4::operator/=(Mat4 b) noexcept { return *this = *this / b; }
inline Mat4 &Mat4::operator+=(float b) noexcept { return *this = *this + b; }
inline Mat4 &Mat4::operator-=(float b) noexcept { return *this = *this - b; }
inline Mat4 &Mat4::operator*=(float b) noexcept { return *this = *this * b; }
inline Mat4 &Mat4::operator/=(float b) noexcept { return *this = *this / b; }

inline Mat2::Mat2(Mat3 m) noexcept : m({m.m[0], m.m[1], m.m[3], m.m[4]}) {}
inline Mat2::Mat2(Mat4 m) noexcept : m({m.m[0], m.m[1], m.m[4], m.m[5]}) {}
inline Mat3::Mat3(Mat2 m) noexcept : m({m.m[0], m.m[1], 0.0f, m.m[2], m.m[3], 0.0f, 0.0f, 0.0f, 0.0f}) {}
inline Mat3::Mat3(Mat4 m) noexcept : m({m.m[0], m.m[1], m.m[2], m.m[4], m.m[5], m.m[6], m.m[8], m.m[9], m.m[10]}) {}
inline Mat4::Mat4(Mat2 m) noexcept : m({m.m[0], m.m[1], 0.0f, 0.0f, m.m[2], m.m[3], 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}) {}
inline Mat4::Mat4(Mat3 m) noexcept : m({m.m[0], m.m[1], m.m[2], 0.0f, m.m[3], m.m[4], m.m[5], 0.0f, m.m[6], m.m[7], m.m[8], 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}) {}

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

    Vec2 get_top_left() const {
        return center - extent * 0.5f * Vec2(1, -1);
    }

    void set_top_left(Vec2 tl) {
        Vec2 br = center + extent * 0.5f * Vec2(1, -1);
        center  = (tl + br) * 0.5f;
        extent  = br - tl;
    }

    Vec2 get_top_right() const {
        return center + extent * 0.5f * Vec2(1, 1);
    }

    void set_top_right(Vec2 tr) {
        Vec2 bl = center - extent * 0.5f * Vec2(1, 1);
        center  = (tr + bl) * 0.5f;
        extent  = tr - bl;
    }

    Vec2 get_bottom_left() const {
        return center - extent * 0.5f * Vec2(1, 1);
    }

    void set_bottom_left(Vec2 bl) {
        Vec2 tr = center + extent * 0.5f * Vec2(1, 1);
        center  = (bl + tr) * 0.5f;
        extent  = tr - bl;
    }

    Vec2 get_bottom_right() const {
        return center + extent * 0.5f * Vec2(1, -1);
    }

    void set_bottom_right(Vec2 br) {
        Vec2 tl = center - extent * 0.5f * Vec2(1, -1);
        center  = (tl + br) * 0.5f;
        extent  = br - tl;
    }

    float get_top() const {
        return center.y + extent.y * 0.5f;
    }

    void set_top(float t) {
        float b  = center.y - extent.y * 0.5f;
        center.y = (b + t) * 0.5f;
        extent.y = t - b;
    }

    float get_bottom() const {
        return center.y - extent.y * 0.5f;
    }

    void set_bottom(float b) {
        float t  = center.y + extent.y * 0.5f;
        center.y = (b + t) * 0.5f;
        extent.y = t - b;
    }

    float get_left() const {
        return center.x - extent.x * 0.5f;
    }

    void set_left(float l) {
        float r  = center.x + extent.x * 0.5f;
        center.x = (l + r) * 0.5f;
        extent.x = r - l;
    }

    float get_right() const {
        return center.x + extent.x * 0.5f;
    }

    void set_right(float r) {
        float l  = center.x - extent.x * 0.5f;
        center.x = (l + r) * 0.5f;
        extent.x = r - l;
    }

    Vec2 get_top_center() const { return Vec2(center.x, center.y + extent.y * 0.5f); }

    Vec2 get_bottom_center() const { return Vec2(center.x, center.y - extent.y * 0.5f); }

    Vec2 get_left_center() const { return Vec2(center.x - extent.x * 0.5f, center.y); }

    Vec2 get_right_center() const { return Vec2(center.x + extent.x * 0.5f, center.y); }

    [[nodiscard]] operator Vec4() const noexcept { return Vec4(center.x, center.y, extent.x, extent.y); }

    [[nodiscard]] operator SDL_FRect() const noexcept { return SDL_FRect{center.x - extent.x / 2.0f, center.y - extent.y / 2.0f, extent.x, extent.y}; }
};

inline bool contains(Rect r, Vec2 p) {
    Vec2 tl = r.get_top_left();
    Vec2 br = r.get_bottom_right();
    return tl.x >= p.x && tl.y >= p.y && br.x <= p.x && br.y <= p.y;
}

inline bool contains(Rect r, Rect s) {
    return contains(r, s.get_top_left()) && contains(r, s.get_bottom_right());
}

inline Rect in(Rect a, Rect b) {
    Rect r;
    r.set_top(fmax(a.get_top(), b.get_top()));
    r.set_bottom(fmin(a.get_bottom(), b.get_bottom()));
    r.set_left(fmax(a.get_left(), b.get_left()));
    r.set_right(fmin(a.get_right(), b.get_right()));
    return r;
}

inline Rect un(Rect a, Rect b) {
    Rect r;
    r.set_top(fmin(a.get_top(), b.get_top()));
    r.set_bottom(fmax(a.get_bottom(), b.get_bottom()));
    r.set_left(fmin(a.get_left(), b.get_left()));
    r.set_right(fmax(a.get_right(), b.get_right()));
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

    static Color from_linear(Vec3 c) { return from_linear(Vec4(c, 1.0f)); }

    static Color from_linear(float r, float g, float b, float a = 1.0f) { return from_linear(Vec4(r, g, b, a)); }

    Vec4 to_linear() const;

    static Color from_norm(Vec4 c);

    static Color from_norm(Vec3 c) { return from_norm(Vec4(c, 1.0f)); }

    static Color from_norm(float r, float g, float b, float a = 1.0f) { return from_norm(Vec4(r, g, b, a)); }

    Vec4 to_norm() const;

    static Color from_hsv(Vec4 c);

    static Color from_hsv(Vec3 c) { return from_hsv(Vec4(c, 1.0f)); }

    static Color from_hsv(float h, float s, float v, float a = 1.0f) { return from_hsv(Vec4(h, s, v, a)); }

    Vec4 to_hsv() const;

    static Color from_hsl(Vec4 c);

    static Color from_hsl(Vec3 c) { return from_hsl(Vec4(c, 1.0f)); }

    static Color from_hsl(float h, float s, float l, float a = 1.0f) { return from_hsl(Vec4(h, s, l, a)); }

    Vec4 to_hsl() const;

    static Color from_hwb(Vec4 c);

    static Color from_hwb(Vec3 c) { return from_hwb(Vec4(c, 1.0f)); }

    static Color from_hwb(float h, float w, float b, float a = 1.0f) { return from_hwb(Vec4(h, w, b, a)); }

    Vec4 to_hwb() const;

    static Color from_oklab(Vec4 c);

    static Color from_oklab(Vec3 c) { return from_oklab(Vec4(c, 1.0f)); }

    static Color from_oklab(float l, float a, float b, float a_ = 1.0f) { return from_oklab(Vec4(l, a, b, a_)); }

    Vec4 to_oklab() const;

    static Color from_oklch(Vec4 c);

    static Color from_oklch(Vec3 c) { return from_oklch(Vec4(c, 1.0f)); }

    static Color from_oklch(float l, float c, float h, float a = 1.0f) { return from_oklch(Vec4(l, c, h, a)); }

    Vec4 to_oklch() const;

    [[nodiscard]] operator std::uint32_t() const noexcept { return (r << 24) + (g << 16) + (b << 8) + a; }
};

[[nodiscard]] inline Color operator+(Color a) noexcept { return Color::from_linear(Vec4(Vec3(+a.to_linear()), a.to_linear().w)); }
[[nodiscard]] inline Color operator-(Color a) noexcept { return Color::from_linear(Vec4(Vec3(-a.to_linear()), a.to_linear().w)); }

[[nodiscard]] inline Color operator+(Color a, Color b) noexcept { return Color::from_linear(a.to_linear() + b.to_linear()); }
[[nodiscard]] inline Color operator-(Color a, Color b) noexcept { return Color::from_linear(a.to_linear() - b.to_linear()); }
[[nodiscard]] inline Color operator*(Color a, Color b) noexcept { return Color::from_linear(a.to_linear() * b.to_linear()); }
[[nodiscard]] inline Color operator/(Color a, Color b) noexcept { return Color::from_linear(a.to_linear() / b.to_linear()); }
[[nodiscard]] inline Color operator+(Color a, Vec4 b) noexcept { return Color::from_linear(a.to_linear() + b); }
[[nodiscard]] inline Color operator-(Color a, Vec4 b) noexcept { return Color::from_linear(a.to_linear() - b); }
[[nodiscard]] inline Color operator*(Color a, Vec4 b) noexcept { return Color::from_linear(a.to_linear() * b); }
[[nodiscard]] inline Color operator/(Color a, Vec4 b) noexcept { return Color::from_linear(a.to_linear() / b); }
[[nodiscard]] inline Color operator+(Vec4 a, Color b) noexcept { return Color::from_linear(a + b.to_linear()); }
[[nodiscard]] inline Color operator-(Vec4 a, Color b) noexcept { return Color::from_linear(a - b.to_linear()); }
[[nodiscard]] inline Color operator*(Vec4 a, Color b) noexcept { return Color::from_linear(a * b.to_linear()); }
[[nodiscard]] inline Color operator/(Vec4 a, Color b) noexcept { return Color::from_linear(a / b.to_linear()); }
[[nodiscard]] inline Color operator+(Color a, Vec3 b) noexcept { return Color::from_linear(a.to_linear() + Vec4(b, 0.0f)); }
[[nodiscard]] inline Color operator-(Color a, Vec3 b) noexcept { return Color::from_linear(a.to_linear() - Vec4(b, 0.0f)); }
[[nodiscard]] inline Color operator*(Color a, Vec3 b) noexcept { return Color::from_linear(a.to_linear() * Vec4(b, 1.0f)); }
[[nodiscard]] inline Color operator/(Color a, Vec3 b) noexcept { return Color::from_linear(a.to_linear() / Vec4(b, 1.0f)); }
[[nodiscard]] inline Color operator+(Vec3 a, Color b) noexcept { return Color::from_linear(Vec4(a, 0.0f) + b.to_linear()); }
[[nodiscard]] inline Color operator-(Vec3 a, Color b) noexcept { return Color::from_linear(Vec4(a, 0.0f) - b.to_linear()); }
[[nodiscard]] inline Color operator*(Vec3 a, Color b) noexcept { return Color::from_linear(Vec4(a, 1.0f) * b.to_linear()); }
[[nodiscard]] inline Color operator/(Vec3 a, Color b) noexcept { return Color::from_linear(Vec4(a, 1.0f) / b.to_linear()); }
[[nodiscard]] inline Color operator+(Color a, float b) noexcept { return Color::from_linear(a.to_linear() + Vec4(b, b, b, 0.0f)); }
[[nodiscard]] inline Color operator-(Color a, float b) noexcept { return Color::from_linear(a.to_linear() - Vec4(b, b, b, 0.0f)); }
[[nodiscard]] inline Color operator*(Color a, float b) noexcept { return Color::from_linear(a.to_linear() * Vec4(b, b, b, 1.0f)); }
[[nodiscard]] inline Color operator/(Color a, float b) noexcept { return Color::from_linear(a.to_linear() / Vec4(b, b, b, 1.0f)); }
[[nodiscard]] inline Color operator+(float a, Color b) noexcept { return Color::from_linear(Vec4(a, a, a, 0.0f) + b.to_linear()); }
[[nodiscard]] inline Color operator-(float a, Color b) noexcept { return Color::from_linear(Vec4(a, a, a, 0.0f) - b.to_linear()); }
[[nodiscard]] inline Color operator*(float a, Color b) noexcept { return Color::from_linear(Vec4(a, a, a, 1.0f) * b.to_linear()); }
[[nodiscard]] inline Color operator/(float a, Color b) noexcept { return Color::from_linear(Vec4(a, a, a, 1.0f) / b.to_linear()); }

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

inline Vec4 Color::to_linear() const { return Vec4(decode(r), decode(g), decode(b), norm(a)); }

inline Color Color::from_norm(Vec4 c) { return Color(quant(c.x), quant(c.y), quant(c.z), quant(c.w)); }

inline Vec4 Color::to_norm() const { return Vec4(norm(r), norm(g), norm(b), norm(a)); }

inline Color Color::from_hsv(Vec4 c) {
    Vec3 k   = mod(c.x * 6.0f + Vec3(0.0f, 4.0f, 2.0f), 6.0f);
    Vec3 f   = clamp(min(k, 4.0f - k), 0.0f, 1.0f);
    Vec3 rgb = c.z * lerp(Vec3(1.0f), f, c.y);
    return Color(quant(rgb.x), quant(rgb.y), quant(rgb.z), quant(c.w));
}

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

inline Color Color::from_hsl(Vec4 c) {
    float l = c.z, s = c.y;
    float v  = l + s * fmin(l, 1.0f - l);
    float sv = v == 0.0f ? 0.0f : 2.0f * (1.0f - l / v);
    return from_hsv(Vec4(c.x, sv, v, c.w));
}

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

inline Color Color::from_hwb(Vec4 c) {
    Vec3  k   = mod(c.x * 6.0f + Vec3(0.0f, 4.0f, 2.0f), 6.0f);
    Vec3  f   = clamp(min(k, 4.0f - k), 0.0f, 1.0f);
    Vec3  rgb = lerp(Vec3(1.0f), f, 1.0f); // base hue at v=1,s=1
    float w = c.y, bl = c.z;
    float q = quant(w / (w + bl));
    Vec3  r = rgb * (1.0f - w - bl) + Vec3(w);
    return (w + bl >= 1.0f) ? Color(q, q, q, quant(c.w))
                            : Color(quant(r.x), quant(r.y), quant(r.z), quant(c.w));
}

inline Vec4 Color::to_hwb() const {
    Vec4  c  = to_norm();
    float mx = fmax(c.x, fmax(c.y, c.z));
    float mn = fmin(c.x, fmin(c.y, c.z));
    return Vec4(to_hsv().x, mn, 1.0f - mx, c.w);
}

inline Color Color::from_oklab(Vec4 c) {
    Vec3 lab = Vec3(c.x, c.y, c.z);
    Vec3 t   = Vec3(lab.x, lab.x, lab.x) + Vec3(0.3963377774f, -0.1055613458f, -0.0894841775f) * lab.y + Vec3(0.2158037573f, -0.0638541728f, -1.2914855480f) * lab.z;
    t        = pow(t, 3);
    Vec3 rgb = Vec3(4.0767416621f, -1.2684380046f, -0.0041960863f) * t.x + Vec3(-3.3077115913f, 2.6097574011f, -0.7034186147f) * t.y + Vec3(0.2309699292f, -0.3413193965f, 1.7076147010f) * t.z;
    return Color(encode(rgb.x), encode(rgb.y), encode(rgb.z), quant(c.w));
}

inline Vec4 Color::to_oklab() const {
    Vec4  L   = to_linear();
    Vec3  lms = Vec3(0.4122214708f, 0.2119034982f, 0.0883024619f) * L.x + Vec3(0.5363325363f, 0.6806995451f, 0.2817188376f) * L.y + Vec3(0.0514459929f, 0.1073969566f, 0.6299787005f) * L.z;
    Vec3  c   = cbrt(lms);
    float L_  = 0.2104542553f * c.x + 0.7936177850f * c.y - 0.0040720468f * c.z;
    float a_  = 1.9779984951f * c.x - 2.4285922050f * c.y + 0.4505937099f * c.z;
    float b_  = 0.0259040371f * c.x + 0.7827717662f * c.y - 0.8086757660f * c.z;
    return Vec4(L_, a_, b_, L.w);
}

inline Color Color::from_oklch(Vec4 c) {
    float h = c.z * 2.0f * M_PI;
    return from_oklab(Vec4(c.x, c.y * cos(h), c.y * sin(h), c.w));
}

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
