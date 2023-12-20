#include "ScoreLabel.h"
#include "Camera.h"
namespace scribbleHop
{
    ScoreLabel::ScoreLabel(int x, int y, int w, int h, std::string t):Label(x,y,w,h,t){
    }
    std::shared_ptr<ScoreLabel> ScoreLabel::getInstance(int x, int y, int w, int h, std::string t){
        return std::shared_ptr<ScoreLabel>(new ScoreLabel(x,y,w,h,t));
    }
    void ScoreLabel::tick(){
        setText(std::to_string((int)engine::Camera::getDistanceMoved()));
    }
} // namespace scribbleHop
