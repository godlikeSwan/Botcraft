#pragma once

#include "protocolCraft/BaseMessage.hpp"

namespace ProtocolCraft
{
    class Spectate : public BaseMessage<Spectate>
    {
    public:
        virtual const int GetId() const override
        {
#if PROTOCOL_VERSION == 340 // 1.12.2
            return 0x1E;
#elif PROTOCOL_VERSION == 393 || PROTOCOL_VERSION == 401 || PROTOCOL_VERSION == 404 // 1.13.X
            return 0x28;
#elif PROTOCOL_VERSION == 477 || PROTOCOL_VERSION == 480 || PROTOCOL_VERSION == 485 || PROTOCOL_VERSION == 490 || PROTOCOL_VERSION == 498 // 1.14.X
            return 0x2B;
#elif PROTOCOL_VERSION == 573 || PROTOCOL_VERSION == 575 || PROTOCOL_VERSION == 578 // 1.15.X
            return 0x2B;
#elif PROTOCOL_VERSION == 735 || PROTOCOL_VERSION == 736  // 1.16.X
            return 0x2C;
#else
#error "Protocol version not implemented"
#endif
        }

        virtual const std::string GetName() const override
        {
            return "Spectate";
        }

        void SetTargetPlayer(const UUID& target_player_)
        {
            target_player = target_player_;
        }


        const UUID& GetTargetPlayer() const
        {
            return target_player;
        }


    protected:
        virtual void ReadImpl(ReadIterator& iter, size_t& length) override
        {
            target_player = ReadUUID(iter, length);
        }

        virtual void WriteImpl(WriteContainer& container) const override
        {
            WriteUUID(target_player, container);
        }

        virtual const picojson::value SerializeImpl() const override
        {
            picojson::value value(picojson::object_type, false);
            picojson::object& object = value.get<picojson::object>();

            object["target_player"] = picojson::value(target_player);

            return value;
        }

    private:
        UUID target_player;

    };
} //ProtocolCraft