#ifndef SCORELABEL_H
#define SCORELABEL_H
#include "Label.h"

namespace scribbleHop
{
    class ScoreLabel : public engine::Label
    {
    private:
        ScoreLabel(int x, int y, int w, int h, std::string t);

    public:
        static std::shared_ptr<ScoreLabel> getInstance(int x, int y, int w, int h, std::string t);
        ~ScoreLabel(){}
        void tick() override;
    };
}

#endif
