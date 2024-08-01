#include "reciever.h"

Calculator::Calculator(int x, int y)
    : m_nX(x),
      m_nY(y)
{

}

void Calculator::setAction(TYPES::ACTION action)
{
    m_currentAction = action;
}

int Calculator::getResult()
{
    int nResult;
    switch (m_currentAction) {
    case TYPES::ACTION::ADD :
        nResult = m_nX + m_nY;
        break;
    case TYPES::ACTION::SUBTRACT :
        nResult = m_nX - m_nY;
        break;
    case TYPES::ACTION::MULTIPLY :
        nResult = m_nX * m_nY;
        break;
    case TYPES::ACTION::DIVIDE :
        nResult = m_nX / m_nY;
        break;
    default:
        break;
    }

    return nResult;
}
