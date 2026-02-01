// Glarens - GUI Framework.
//
// C#-like property in C++ using operator overloading.
//
// Copyright (c) 2026 Anstro Pleuton.
// This project is licensed under the terms of MIT license.
// See LICENSE.md file in the project root for license text.

#pragma once

#include <cstddef>     // IWYU pragma: keep
#include <type_traits> // IWYU pragma: keep
#include <utility>

template <typename P>
concept HasGet = requires {
    { std::declval<P>().get };
};

template <typename P>
concept HasSet = requires {
    { std::declval<P>().set };
};

template <HasGet P> auto             operator+(const P &a) { return +a.get(); }
template <HasGet P> auto             operator-(const P &a) { return -a.get(); }
template <HasGet P, typename T> auto operator+(const P &a, const P &b) { return a.get() + b.get(); }
template <HasGet P, typename T> auto operator+(const P &a, const T &b) { return a.get() + b; }
template <HasGet P, typename T> auto operator+(const T &a, const P &b) { return a + b.get(); }
template <HasGet P, typename T> auto operator-(const P &a, const P &b) { return a.get() - b.get(); }
template <HasGet P, typename T> auto operator-(const P &a, const T &b) { return a.get() - b; }
template <HasGet P, typename T> auto operator-(const T &a, const P &b) { return a - b.get(); }
template <HasGet P, typename T> auto operator*(const P &a, const P &b) { return a.get() * b.get(); }
template <HasGet P, typename T> auto operator*(const P &a, const T &b) { return a.get() * b; }
template <HasGet P, typename T> auto operator*(const T &a, const P &b) { return a * b.get(); }
template <HasGet P, typename T> auto operator/(const P &a, const P &b) { return a.get() / b.get(); }
template <HasGet P, typename T> auto operator/(const P &a, const T &b) { return a.get() / b; }
template <HasGet P, typename T> auto operator/(const T &a, const P &b) { return a / b.get(); }
template <HasGet P, typename T> auto operator%(const P &a, const P &b) { return a.get() % b.get(); }
template <HasGet P, typename T> auto operator%(const P &a, const T &b) { return a.get() % b; }
template <HasGet P, typename T> auto operator%(const T &a, const P &b) { return a % b.get(); }
template <HasGet P> auto             operator~(const P &a) { return ~a.get(); }
template <HasGet P, typename T> auto operator&(const P &a, const P &b) { return a.get() & b.get(); }
template <HasGet P, typename T> auto operator&(const P &a, const T &b) { return a.get() & b; }
template <HasGet P, typename T> auto operator&(const T &a, const P &b) { return a & b.get(); }
template <HasGet P, typename T> auto operator|(const P &a, const P &b) { return a.get() | b.get(); }
template <HasGet P, typename T> auto operator|(const P &a, const T &b) { return a.get() | b; }
template <HasGet P, typename T> auto operator|(const T &a, const P &b) { return a | b.get(); }
template <HasGet P, typename T> auto operator^(const P &a, const P &b) { return a.get() ^ b.get(); }
template <HasGet P, typename T> auto operator^(const P &a, const T &b) { return a.get() ^ b; }
template <HasGet P, typename T> auto operator^(const T &a, const P &b) { return a ^ b.get(); }
template <HasGet P, typename T> auto operator<<(const P &a, const P &b) { return a.get() << b.get(); }
template <HasGet P, typename T> auto operator<<(const P &a, const T &b) { return a.get() << b; }
template <HasGet P, typename T> auto operator<<(const T &a, const P &b) { return a << b.get(); }
template <HasGet P, typename T> auto operator>>(const P &a, const P &b) { return a.get() >> b.get(); }
template <HasGet P, typename T> auto operator>>(const P &a, const T &b) { return a.get() >> b; }
template <HasGet P, typename T> auto operator>>(const T &a, const P &b) { return a >> b.get(); }
template <HasGet P> auto             operator!(const P &a) { return !a.get(); }
template <HasGet P, typename T> auto operator&&(const P &a, const P &b) { return a.get() && b.get(); }
template <HasGet P, typename T> auto operator&&(const P &a, const T &b) { return a.get() && b; }
template <HasGet P, typename T> auto operator&&(const T &a, const P &b) { return a && b.get(); }
template <HasGet P, typename T> auto operator==(const P &a, const P &b) { return a.get() == b.get(); }
template <HasGet P, typename T> auto operator==(const P &a, const T &b) { return a.get() == b; }
template <HasGet P, typename T> auto operator==(const T &a, const P &b) { return a == b.get(); }
template <HasGet P, typename T> auto operator!=(const P &a, const P &b) { return a.get() != b.get(); }
template <HasGet P, typename T> auto operator!=(const P &a, const T &b) { return a.get() != b; }
template <HasGet P, typename T> auto operator!=(const T &a, const P &b) { return a != b.get(); }
template <HasGet P, typename T> auto operator<(const P &a, const P &b) { return a.get() < b.get(); }
template <HasGet P, typename T> auto operator<(const P &a, const T &b) { return a.get() < b; }
template <HasGet P, typename T> auto operator<(const T &a, const P &b) { return a < b.get(); }
template <HasGet P, typename T> auto operator>(const P &a, const P &b) { return a.get() > b.get(); }
template <HasGet P, typename T> auto operator>(const P &a, const T &b) { return a.get() > b; }
template <HasGet P, typename T> auto operator>(const T &a, const P &b) { return a > b.get(); }
template <HasGet P, typename T> auto operator<=(const P &a, const P &b) { return a.get() <= b.get(); }
template <HasGet P, typename T> auto operator<=(const P &a, const T &b) { return a.get() <= b; }
template <HasGet P, typename T> auto operator<=(const T &a, const P &b) { return a <= b.get(); }
template <HasGet P, typename T> auto operator>=(const P &a, const P &b) { return a.get() >= b.get(); }
template <HasGet P, typename T> auto operator>=(const P &a, const T &b) { return a.get() >= b; }
template <HasGet P, typename T> auto operator>=(const T &a, const P &b) { return a >= b.get(); }

template <HasSet P, typename T> auto &operator+=(P &a, const T &b) { return (set(a.get() + b), a); }
template <HasSet P, HasGet Q> auto   &operator+=(P &a, const Q &b) { return (set(a.get() + b.get()), a); }
template <HasSet P, typename T> auto &operator-=(P &a, const T &b) { return (set(a.get() - b), a); }
template <HasSet P, HasGet Q> auto   &operator-=(P &a, const Q &b) { return (set(a.get() - b.get()), a); }
template <HasSet P, typename T> auto &operator*=(P &a, const T &b) { return (set(a.get() * b), a); }
template <HasSet P, HasGet Q> auto   &operator*=(P &a, const Q &b) { return (set(a.get() * b.get()), a); }
template <HasSet P, typename T> auto &operator/=(P &a, const T &b) { return (set(a.get() / b), a); }
template <HasSet P, HasGet Q> auto   &operator/=(P &a, const Q &b) { return (set(a.get() / b.get()), a); }
template <HasSet P, typename T> auto &operator%=(P &a, const T &b) { return (set(a.get() % b), a); }
template <HasSet P, HasGet Q> auto   &operator%=(P &a, const Q &b) { return (set(a.get() % b.get()), a); }
template <HasSet P, typename T> auto &operator&=(P &a, const T &b) { return (set(a.get() & b), a); }
template <HasSet P, HasGet Q> auto   &operator&=(P &a, const Q &b) { return (set(a.get() & b.get()), a); }
template <HasSet P, typename T> auto &operator|=(P &a, const T &b) { return (set(a.get() | b), a); }
template <HasSet P, HasGet Q> auto   &operator|=(P &a, const Q &b) { return (set(a.get() | b.get()), a); }
template <HasSet P, typename T> auto &operator^=(P &a, const T &b) { return (set(a.get() ^ b), a); }
template <HasSet P, HasGet Q> auto   &operator^=(P &a, const Q &b) { return (set(a.get() ^ b.get()), a); }
template <HasSet P, typename T> auto &operator<<=(P &a, const T &b) { return (set(a.get() << b), a); }
template <HasSet P, HasGet Q> auto   &operator<<=(P &a, const Q &b) { return (set(a.get() << b.get()), a); }
template <HasSet P, typename T> auto &operator>>=(P &a, const T &b) { return (set(a.get() >> b), a); }
template <HasSet P, HasGet Q> auto   &operator>>=(P &a, const Q &b) { return (set(a.get() >> b.get()), a); }

template <HasSet P>
auto &operator++(P &a) {
    set(++a.get());
    return a;
}

template <HasSet P>
auto operator++(P &a, int) {
    auto temp = a.get();
    set(++a.get());
    return temp;
}

template <HasSet P>
auto &operator--(P &a) {
    set(--a.get());
    return a;
}

template <HasSet P>
auto operator--(P &a, int) {
    auto temp = a.get();
    set(--a.get());
    return temp;
}

template <auto G>
struct PropRO {
    using T = decltype(G());

    T get() const { return G(); }

    operator T() const { return get(); }
};

template <auto G, auto S>
struct Prop : PropRO<G> {
    using T = PropRO<G>::T;

    template <typename T> void set(const T &v) const { S(v); }

    Prop() = default;

    template <typename T> Prop(T &&a) { set(std::forward<T>(a)); }
    template <HasGet Q> Prop(const Q &a) { set(a.get()); }

    template <typename T> Prop &operator=(T &&b) { return (set(std::forward<T>(b)), *this); }
    template <HasGet Q> Prop   &operator=(const Q &b) { return (set(b.get()), *this); }
};

// Hot garbage
#define MemPropRO(O, N, T, G)                                             \
    struct MemPropRO_##N {                                                \
        O &self() const { return *(O *)((char *)this - offsetof(O, N)); } \
                                                                          \
        T get() const { return G(self()); }                               \
                                                                          \
        operator T() const { return get(); }                              \
    };                                                                    \
    [[no_unique_address]] MemPropRO_##N N

#define MemProp(O, N, T, G, S)                                                                           \
    struct MemProp_##N {                                                                                 \
        O &self() const { return *(O *)((char *)this - offsetof(O, N)); }                                \
                                                                                                         \
        T get() const { return G(self()); }                                                              \
                                                                                                         \
        operator T() const { return get(); }                                                             \
                                                                                                         \
        template <typename U> void set(const U &v) const { S(this->self(), v); }                         \
                                                                                                         \
        MemProp_##N() = default;                                                                         \
                                                                                                         \
        template <typename U> MemProp_##N(U &&a) { set(std::forward<U>(a)); }                            \
        template <HasGet Q> MemProp_##N(const Q &a) { set(a.get()); }                                    \
                                                                                                         \
        template <typename U> MemProp_##N &operator=(U &&b) { return (set(std::forward<U>(b)), *this); } \
        template <HasGet Q> MemProp_##N   &operator=(const Q &b) { return (set(b.get()), *this); }       \
    };                                                                                                   \
    [[no_unique_address]] MemProp_##N N

#define mem_prop_get(O, N, T, G) \
    static T mem_prop_get_##N(const O &self) { return G; }

#define mem_prop_set(O, N, T, S) \
    static void mem_prop_set_##N(O &self, const T &value) { S; }

#define MemPropROExp(O, N, T, G) mem_prop_get(O, N, T, G) MemPropRO(O, N, T, mem_prop_get_##N)

#define MemPropExp(O, N, T, G, S) mem_prop_get(O, N, T, G) mem_prop_set(O, N, T, S) MemProp(O, N, T, mem_prop_get_##N, mem_prop_set_##N)

#define mem_obs_get(O, N, T, G)               \
    static T mem_obs_get_##N(const O &self) { \
        G;                                    \
        return self.N##__;                    \
    }

#define mem_obs_set(O, N, T, S)                            \
    static void mem_obs_set_##N(O &self, const T &value) { \
        S;                                                 \
        self.N##__ = value;                                \
    }

#define MemObsExp(O, N, T, G, S) \
    T N##__;                     \
    mem_obs_get(O, N, T, G) mem_obs_set(O, N, T, S) MemProp(O, N, T, mem_obs_get_##N, mem_obs_set_##N)

#define MemPropRODecl(O, N, T)                                            \
    struct MemPropRO_##N {                                                \
        O &self() const { return *(O *)((char *)this - offsetof(O, N)); } \
                                                                          \
        inline T get() const;                                             \
                                                                          \
        operator T() const;                                               \
    };                                                                    \
    [[no_unique_address]] MemPropRO_##N N

#define MemPropDecl(O, N, T)                                              \
    struct MemProp_##N {                                                  \
        O &self() const { return *(O *)((char *)this - offsetof(O, N)); } \
                                                                          \
        inline T get() const;                                             \
                                                                          \
        inline operator T() const;                                        \
                                                                          \
        template <typename U> inline void set(const U &v) const;          \
                                                                          \
        MemProp_##N() = default;                                          \
                                                                          \
        template <typename U> inline MemProp_##N(U &&a);                  \
        template <HasGet Q> inline MemProp_##N(const Q &a);               \
                                                                          \
        template <typename U> inline MemProp_##N &operator=(U &&b);       \
        template <HasGet Q> inline MemProp_##N   &operator=(const Q &b);  \
    };                                                                    \
    [[no_unique_address]] MemProp_##N N

#define mem_prop_get_decl(O, N, T) \
    static T mem_prop_get_##N(const O &self);

#define mem_prop_set_decl(O, N, T) \
    static void mem_prop_set_##N(O &self, const T &value);

#define MemPropROExpDecl(O, N, T) mem_prop_get_decl(O, N, T) MemPropRODecl(O, N, T)

#define MemPropExpDecl(O, N, T) mem_prop_get_decl(O, N, T) mem_prop_set_decl(O, N, T, S) MemPropDecl(O, N, T)

#define mem_obs_get_decl(O, N, T) \
    static T mem_obs_get_##N(const O &self);

#define mem_obs_set_decl(O, N, T) \
    static void mem_obs_set_##N(O &self, const T &value);

#define MemObsExpDecl(O, N, T) \
    T N##__;                   \
    mem_obs_get_decl(O, N, T) mem_obs_set_decl(O, N, T) MemPropDecl(O, N, T)

#define MemPropRODef(O, N, T, G)                                                 \
    inline T                 O::MemPropRO_##N::get() const { return G(self()); } \
    inline O::MemPropRO_##N::operator T() const { return get(); }

#define MemPropDef(O, N, T, G, S)                                                                                               \
    inline T O::MemProp_##N::get() const { return G(self()); }                                                                  \
                                                                                                                                \
    inline O::MemProp_##N::operator T() const { return get(); }                                                                 \
                                                                                                                                \
    template <typename U> inline void O::MemProp_##N::set(const U &v) const { S(this->self(), v); }                             \
                                                                                                                                \
    template <typename U> inline O::MemProp_##N::MemProp_##N(U &&a) { set(std::forward<U>(a)); }                                \
    template <HasGet Q> inline O::MemProp_##N::MemProp_##N(const Q &a) { set(a.get()); }                                        \
                                                                                                                                \
    template <typename U> inline O::MemProp_##N &O::MemProp_##N::operator=(U && b) { return (set(std::forward<U>(b)), *this); } \
    template <HasGet Q> inline O::MemProp_##N   &O::MemProp_##N::operator=(const Q & b) { return (set(b.get()), *this); }

#define mem_prop_get_def(O, N, T, G) \
    inline T O::mem_prop_get_##N(const O &self) { return G; }

#define mem_prop_set_def(O, N, T, S) \
    inline void O::mem_prop_set_##N(O &self, const T &value) { S; }

#define MemPropROExpDef(O, N, T, G) mem_prop_get_def(O, N, T, G) MemPropRODef(O, N, T, mem_prop_get_##N)

#define MemPropExpDef(O, N, T, G, S) mem_prop_get_def(O, N, T, G) mem_prop_set_def(O, N, T, S) MemPropDef(O, N, T, mem_prop_get_##N, mem_prop_set_##N)

#define mem_obs_get_def(O, N, T, G)              \
    inline T O::mem_obs_get_##N(const O &self) { \
        G;                                       \
        return self.N##__;                       \
    }

#define mem_obs_set_def(O, N, T, S)                           \
    inline void O::mem_obs_set_##N(O &self, const T &value) { \
        S;                                                    \
        self.N##__ = value;                                   \
    }

#define MemObsExpDef(O, N, T, G, S) \
    T N##__;                        \
    mem_obs_get_def(O, N, T, G) mem_obs_set_def(O, N, T, S) MemPropDef(O, N, T, mem_obs_get_##N, mem_obs_set_##N)