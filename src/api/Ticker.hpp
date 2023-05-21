#ifndef SEKAI_ENGINE_API_TICKER_HPP
#define SEKAI_ENGINE_API_TICKER_HPP

#include "./APIConfig.hpp"

namespace SekaiEngine
{
    namespace API
    {
        class Ticker
        {
        public:
            Ticker(const int& targetFPS = 60);
            ~Ticker();

            void start();
            void nextFrame();
            void wait();

            const float frameTime() const;
            const float frameTime();

            const double elapsedTime() const;
            const double elapsedTime();

            const int& targetFPS() const;
            const int& targetFPS();
        private:
            int m_targetFPS;
        };

        inline const float Ticker::frameTime() const
        {
#ifdef RAYLIB_API
            return GetFrameTime();
#else

#endif
        }

        inline const float Ticker::frameTime()
        {
            return static_cast<const Ticker&>(*this).frameTime();
        }

        inline const double Ticker::elapsedTime() const
        {
#ifdef RAYLIB_API
            return GetTime();
#else

#endif
        }

        inline const double Ticker::elapsedTime()
        {
            return static_cast<const Ticker&>(*this).elapsedTime();
        }

        inline const int& Ticker::targetFPS() const
        {
            return m_targetFPS;
        }

        inline const int& Ticker::targetFPS()
        {
            return static_cast<const Ticker&>(*this).targetFPS();
        }
    } // namespace API
    
} // namespace SekaiEngine


#endif //!SEKAI_ENGINE_API_TICKER_HPP