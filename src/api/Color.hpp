#ifndef SEKAI_ENGINE_API_COLOR_HPP
#define SEKAI_ENGINE_API_COLOR_HPP

#include "./APIConfig.hpp"
#include <stdint.h>

#define uint32_t uint32_t //0xRRGGBBAA

namespace SekaiEngine
{
    namespace API
    {
        class Color
        {
        public:
            explicit Color(const COLOR_API& color);

            /// @brief Init color by int
            /// @param color color in hex 0xRRGGBBAA
            explicit Color(const uint32_t& color);
            
            Color(const Color& color);
            
            Color& operator=(const Color& color);
            
            Color& operator=(const COLOR_API& color);
            
            /// @brief assign constructor by int
            /// @param color color in hex 0xRRGGBBAA
            /// @return Color API
            Color& operator=(const uint32_t& color);

            ~Color();

            const bool operator==(const Color& color);

            uint32_t getCode() const;
            uint32_t getCode();

            const COLOR_API& get() const;
            const COLOR_API& get();

            const unsigned char& r() const;
            unsigned char& r();

            const unsigned char& g() const;
            unsigned char& g();

            const unsigned char& b() const;
            unsigned char& b();

            const unsigned char& a() const;
            unsigned char& a();
        private:
            COLOR_API m_color;
        };

        inline uint32_t Color::getCode() const
        {
            return (m_color.a << 24) | (m_color.g << 16) | (m_color.b << 8) | m_color.a;
        }

        inline uint32_t Color::getCode()
        {
            return static_cast<const Color&>(*this).getCode();
        }

        inline const COLOR_API& Color::get() const
        {
            return m_color;
        }

        inline const COLOR_API& Color::get()
        {
            return static_cast<const Color&>(*this).get();
        }

        inline const unsigned char& Color::r() const
        {
            return m_color.r;
        }

        inline unsigned char& Color::r()
        {
            return const_cast<unsigned char&>(static_cast<const Color&>(*this).r());
        }

        inline const unsigned char& Color::g() const
        {
            return m_color.g;
        }

        inline unsigned char& Color::g()
        {
            return const_cast<unsigned char&>(static_cast<const Color&>(*this).g());
        }

        inline const unsigned char& Color::b() const
        {
            return m_color.b;
        }

        inline unsigned char& Color::b()
        {
            return const_cast<unsigned char&>(static_cast<const Color&>(*this).b());
        }

        inline const unsigned char& Color::a() const
        {
            return m_color.a;
        }

        inline unsigned char& Color::a()
        {
            return const_cast<unsigned char&>(static_cast<const Color&>(*this).a());
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_COLOR_HPP