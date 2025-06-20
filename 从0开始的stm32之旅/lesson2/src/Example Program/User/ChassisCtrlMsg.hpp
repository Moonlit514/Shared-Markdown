#ifndef CHASSIS_CTRL_MSG_HPP
#define CHASSIS_CTRL_MSG_HPP

#include "CanMsgHandler.hpp"



class ChassisCtrlMsg : public CanMsgHandler
{
private:
    uint8_t m_fdbmsg;
    uint8_t m_isopen;

    CAN_TypeDef* m_pCan;
    uint32_t m_canId;

public:

    uint8_t Getfdbmsg() const { return m_fdbmsg; }
    uint8_t GetIsOpen() const { return m_isopen; }

    void Setfdbmsg(uint8_t msg) { m_fdbmsg = msg; }
    void SetIsOpen(bool isOpen) {m_isopen = isOpen; }

    void Update();
    void Init(CAN_TypeDef* can, uint32_t _stdId);
    void SendMsg();

    virtual void HandleNewCanRxMsg(CanRxMsg* _msg);
    static ChassisCtrlMsg *Instance()
    {
        static ChassisCtrlMsg instance;
        return &instance;
    }
};

#endif
