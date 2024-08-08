// concrete_state.cpp
#include "concrete_state.h"
#include "context.h"
#include <iostream>

// 红灯
RedLight::RedLight(TrafficLights* context) : m_pContext(context) {}

void RedLight::Handle()
{
    std::cout << "Red Light" << std::endl;
    m_pContext->SetState(new GreenLight(m_pContext));//设置红灯的下一个状态是绿灯
    delete this;
}

// 绿灯
GreenLight::GreenLight(TrafficLights* context) : m_pContext(context) {}

void GreenLight::Handle()
{
    std::cout << "Green Light" << std::endl;
    m_pContext->SetState(new YellowLight(m_pContext));
    delete this;
}

// 黄灯
YellowLight::YellowLight(TrafficLights* context) : m_pContext(context) {}

void YellowLight::Handle()
{
    std::cout << "Yellow Light" << std::endl;
    m_pContext->SetState(new RedLight(m_pContext));
    delete this;
}
