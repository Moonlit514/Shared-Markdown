#include "ChassisCtrlMsg.hpp"
#include "CanMsgDispatcher.hpp"
#include "Stream.hpp"

void ChassisCtrlMsg::HandleNewCanRxMsg(CanRxMsg* _msg)
{
    CanMsgHandler::HandleNewCanRxMsg(_msg);

    uint8_t* ptr = lastCanMsg.Data;

    m_fdbmsg = ArrayStreamHelper::ReadUint8(ptr);
    m_isopen = ArrayStreamHelper::ReadUint8(ptr);
}


void ChassisCtrlMsg::Init(CAN_TypeDef* can, uint32_t _stdId)
{
    m_fdbmsg = 0;
    m_isopen = 0;

    m_canId = _stdId;
    m_pCan = can;
    CanMsgDispatcher::Instance()->RegisterHandler(m_pCan, m_canId, this);
}

void ChassisCtrlMsg::SendMsg()
{
    uint8_t buffer = 0;

    uint8_t* ptr = &buffer;

    ArrayStreamHelper::Write(ptr, m_fdbmsg);
    ArrayStreamHelper::Write(ptr, m_isopen);

    CanManager::Instance()->CanTransmit(m_pCan, m_canId, &buffer, sizeof(buffer));
}
void ChassisCtrlMsg::Update()
{
    if(Time::GetTick() % 50 == 5)
    {
        ChassisCtrlMsg::Instance()->SendMsg();
	}
}
